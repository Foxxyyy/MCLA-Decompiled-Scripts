void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28;

   var2 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 2);
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &(L[0].v0.v0[0 * 3]), 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var3 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var3, var2, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var3, mcHookman_GetModValue(L[0].v0.v97.v0));
   mcTargetManager_RegisterRacer(var2, var3);
   mcTargetManager_HideTarget(var2, 0);
   Racer_InitializeResetPosition(var3, &(L[0].v0.v0[0 * 3]), L[0].v0.v95);
   Racer_Reset(var3);
   var4 = sub_10f(0);
   L[0].v0.v97.v2 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 2, var3);
   Racer_SetIconType(var3, 4);
   var5 = mcCareer_GetDifficultyPlayerVsRacer(var3);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, var5);
   Racer_SetIconColorByDifficulty(var3, var5);
   mcHudMapServer_AddElement(L[0].v0.v97.v2);
   Racer_HideIcon(var3, 0);
   var6 = mcMissionManager_GetMission("FIND_SH_01");
   var7 = 0;
   var8 = 0;
   var9 = 0;
   var10 = null;
   var11 = null;
   var12.v2.v0.v0 = 0.0f;
   var12.v2.v0.v1 = 0.0f;
   var12.v2.v0.v2 = 0.0f;
   var12.v2.v3 = 0.0f;
   var18.v0 = (float)1772;
   var18.v1 = (float)-3;
   var18.v2 = (float)90;
   var21 = 0;
   var22 = 0;
   if (!var22)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var9);
       if (var9 == 1)
       {
           Racer_HideIcon(var3, 1);
           mcHudMapServer_RemoveElement(L[0].v0.v97.v2);
           Racer_SetStreamingLockedOut(var3);
           while (var9 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var9);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var3);
           Racer_HideIcon(var3, 0);
           mcHudMapServer_AddElement(L[0].v0.v97.v2);
       }
       var7 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var7 == 1)
       {
           while (var7 == 1)
           {
               var7 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var7 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           var5 = mcCareer_GetDifficultyPlayerVsRacer(var3);
           mcHookman_SetDifficulty(L[0].v0.v97.v0, var5);
           Racer_SetIconColorByDifficulty(var3, var5);
           var10 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/CruisingHookmanCore", &(L[0].v0), 103, 1500);
           while (!IsChildFinished(var10))
           {
               WAITUNWARPED(100);
           }
           var7 = mcHookman_GetState(L[0].v0.v97.v0);
           if ((var7 == 4) || IsExitFlagSet())
           {
           }
           else
           {
               L[0].v0.v101 = 1;
               UILogic_RemoveGPSDestination(0);
               sub_42a(1, 1, 0x3f800000, 0);
               CineScript_SetGameCoordSysBinding(&var12);
               sub_76b(var4, 0);
               sub_76b(var3, 1);
               AmbientMgr_Reset();
               AmbientMgr_SetRoadDensity(&var18, var21);
               PostProcessing_SetCutsceneDof();
               Racer_GetPosition(var3, &var23);
               Racer_InitializeResetPosition(var3, &var23, Racer_GetAngleY(var3));
               Racer_Reset(var3);
               Racer_GetPosition(var4, &var26);
               Racer_InitializeResetPosition(var4, &var26, Racer_GetAngleY(var4));
               Racer_Reset(var4);
               WAIT(0);
               while (!City_DoneStreaming(0x42c80000))
               {
                   PRINTSTRING("Waiting for city\n");
                   WAIT(10);
               }
               var11 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_find_sh_04_generated", &null, 0, 1500);
               while (!IsChildFinished(var11))
               {
                   WAITUNWARPED(100);
               }
               PostProcessing_SetGameDof();
               AmbientMgr_SetRoadDensity(&var18, -1);
               Racer_Activate(var4);
               mcEvent_PostEventStr("MISSION_EVENT", "FIND_SH_01_OBJ_01_COMPLETE");
               Racer_HideIcon(var3, 1);
               WAITUNWARPED(1000);
               mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
           }
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING("\n");
   Racer_HideIcon(var3, 1);
   mcTargetManager_UnRegisterTarget(var2);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   OpponentManager_RemoveOpponentFromWorld(L[0].v0.v97.v1);
   OpponentManager_DeleteOpponent(L[0].v0.v97.v1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_10f(var0)
{
   auto var3, var4;

   var3 = Player_FindRacerObject(var0);
   while (var3 == null)
   {
       var3 = Player_FindRacerObject(var0);
       WAITUNWARPED(10);
   }
   return var3;
}

void sub_42a(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           PRINTSTRING("SCRIPT: waiting for transition movie to stream in...\n");
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE DOWN REPORT\n");
   PRINTSTRING("================\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var8 == 0) && ((var9 == 0) || ((var7 == 1) && (var9 == 2))))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", var2);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", 0.01f);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 0);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 1);
       if (var0)
       {
           var8 = 1;
           while (var8 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
               if (var8 == 1)
               {
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

void sub_76b(var0, var1)
{
   auto var4, var5, var6, var7;

   var4 = Racer_GetUID(var0);
   if (var4 == 0)
   {
       var4 = 5000 + var1;
       while (Racer_FindFromUID(var4) != null)
       {
           var4 = var4 + 1;
           WAITUNWARPED(10);
       }
       Racer_SetUID(var0, var4);
   }
   CineScript_Cars_AssignIdToSlot(var4, var1);
   var5 = Racer_GetVehicleDriverName(var0);
   CineScript_Characters_AssignNameToSlot(var5, var1);
}

