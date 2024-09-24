void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35;

   var2 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   var3.v0 = -3129.594f;
   var3.v1 = -17.735f;
   var3.v2 = 521.781f;
   mcTargetManager_RegisterLocation(603, &var3);
   mcTargetManager_HideTarget(603, 0);
   var6 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetElement(var6, 9, 603, &var3, (float)0);
   mcHudMapServer_AddElement(var6);
   var7.v0 = -3132.6f;
   var7.v1 = -19.73f;
   var7.v2 = 537.87f;
   var10 = 358.61f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var7, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var11 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var11, var2, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var11, mcHookman_GetModValue(L[0].v0.v97.v0));
   Racer_SetVehicleDriverEnable(var11, 0);
   Racer_InitializeResetPosition(var11, &var7, var10);
   Racer_Reset(var11);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, mcCareer_GetDifficultyPlayerVsRacer(var11));
   Racer_HideIcon(var11, 1);
   var12 = UIManager_GetState("Cruising_Offline");
   var13 = sub_1a0(0);
   var14 = 0.0f;
   var15 = 0;
   var16 = 0;
   var17 = 0;
   var18 = 0;
   var19 = null;
   var20.v2.v0.v0 = 0.0f;
   var20.v2.v0.v1 = 0.0f;
   var20.v2.v0.v2 = 0.0f;
   var20.v2.v3 = 0.0f;
   var26.v0 = -3121.483f;
   var26.v1 = 10.008f;
   var26.v2 = 514.29f;
   var29.v0 = -3121.753f;
   var29.v1 = 12.406f;
   var29.v2 = 514.232f;
   var32.v0 = -3155.511f;
   var32.v1 = 6.522f;
   var32.v2 = 528.823f;
   var35 = 0;
   while (!var35)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var17);
       if (var17 == 1)
       {
           mcHudMapServer_RemoveElement(var6);
           Racer_SetStreamingLockedOut(var11);
           while (var17 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var17);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var11);
           mcHudMapServer_AddElement(var6);
       }
       var15 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var15 == 1)
       {
           while (var15 == 1)
           {
               var15 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var15 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           if (vhsmState_IsListener(var12) && (!Game_IsPaused()))
           {
               if ((var16 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
               {
                   var16 = var16 - 1;
               }
               var14 = Racer_DistanceToPoint(var13, &var3);
               if ((!Game_IsPaused()) && (var14 < 20.0f))
               {
                   Warper_SetIsWarpingToCutscene(1);
                   if (PoliceManager_CheckPoliceActivity(1) > 1)
                   {
                       if (var16 == 0)
                       {
                           SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                           var16 = 100;
                       }
                       WAITUNWARPED(100);
                   }
                   else
                   {
                       UILogic_RemoveGPSDestination(0);
                       mcHudMapServer_RemoveElement(var6);
                       mcHookman_SetState(L[0].v0.v97.v0, 1);
                       CineScript_SetGameCoordSysBinding(&var20);
                       sub_45b(var13, 0);
                       sub_45b(var11, 1);
                       Racer_Deactivate(var13);
                       Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", 603, &var26, &var29, &var32, "WarpFromCarToWaitPosition_CarneySign");
                       while (!Warper_IsReadyToLoadStuff())
                       {
                           WAITUNWARPED(100);
                           PRINTSTRING("Waiting For Camera To Get To Safe Spot\n");
                       }
                       PostProcessing_SetCutsceneDof();
                       var19 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_hangout_pinkslip_hills_generated", &null, 0, 1500);
                       while (!IsChildFinished(var19))
                       {
                           WAITUNWARPED(100);
                       }
                       PostProcessing_SetGameDof();
                       Racer_Activate(var13);
                       mcEvent_PostEventStr("MISSION_EVENT", "FIND_SH_02_OBJ_01_COMPLETE");
                       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                   }
               }
           }
           WAITUNWARPED(30);
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING("\n");
   Racer_HideIcon(var11, 1);
   mcTargetManager_HideTarget(603, 1);
   mcHudMapServer_DeleteElement(var6);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_1a0(var0)
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

void sub_45b(var0, var1)
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

