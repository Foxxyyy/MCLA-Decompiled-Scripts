void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54;

   var2 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   var3.v0 = 12.892f;
   var3.v1 = 30.144f;
   var3.v2 = -886.856f;
   mcTargetManager_RegisterLocation(605, &var3);
   mcTargetManager_HideTarget(605, 0);
   var6 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetElement(var6, 9, 605, &var3, (float)0);
   mcHudMapServer_AddElement(var6);
   var7.v0 = 13.28f;
   var7.v1 = 26.38f;
   var7.v2 = -905.93f;
   var10 = 178.54f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var7, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var11 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var11, var2, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var11, mcHookman_GetModValue(L[0].v0.v97.v0));
   Racer_SetVehicleDriverEnable(var11, 0);
   Racer_SetHeadlights(var11, 0);
   Racer_SetExhaust(var11, 0);
   Racer_InitializeResetPosition(var11, &var7, var10);
   Racer_Reset(var11);
   Racer_Deactivate(var11);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, mcCareer_GetDifficultyPlayerVsRacer(var11));
   Racer_HideIcon(var11, 1);
   var12 = UIManager_GetState("Cruising_Offline");
   var13 = sub_1be(0);
   var14 = 0.0f;
   var15 = 0;
   var16 = 0;
   var17 = 0;
   var18 = 0;
   var19 = 0;
   var20 = Form_GetForm(71);
   var21 = Form_GetForm(5);
   var22 = null;
   var23.v2.v0.v0 = 0.0f;
   var23.v2.v0.v1 = 0.0f;
   var23.v2.v0.v2 = 0.0f;
   var23.v2.v3 = 0.0f;
   var29.v0 = -26.695f;
   var29.v1 = 37.142f;
   var29.v2 = -893.581f;
   var32.v0 = -28.311f;
   var32.v1 = 40.664f;
   var32.v2 = -891.53f;
   var35.v0 = -23.467f;
   var35.v1 = 41.384f;
   var35.v2 = -898.323f;
   var38 = 3;
   var42 = 3;
   var46 = 3;
   var50 = 3;
   var38[0] = "character/ped_ma_005_set";
   var42[0] = "ped_ma_005_set";
   var46[0] = "cutscene/hangout/cut_story_find_sh_02c_peds";
   var50[0] = "m_ped00_loop";
   var38[1] = "character/ped_ma_002_set";
   var42[1] = "ped_ma_002_set";
   var46[1] = "cutscene/hangout/cut_story_find_sh_02c_peds";
   var50[1] = "m_ped01_loop";
   var38[2] = "character/ped_mc_009_set";
   var42[2] = "ped_mc_009_set";
   var46[2] = "cutscene/hangout/cut_story_find_sh_02c_peds";
   var50[2] = "m_ped03_loop";
   var54 = 0;
   while (!var54)
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
                       mcHudMapServer_RemoveElement(var6);
                       if (mcExperienceManager_CanSpendMoney(1000000))
                       {
                           var19 = sub_676(var20, "FIND_SH_02C_SPEND_MONEY_DESC", "FIND_SH_02C_SPEND_MONEY_TITLE", 3, 1);
                           if (var19 == 3)
                           {
                               mcExperienceManager_SpendMoney(1000000);
                               StatsManager_UpdateStatInt("tPAR", 0, 3, 1);
                               Warper_SetIsWarpingToCutscene(1);
                               mcHookman_SetState(L[0].v0.v97.v0, 1);
                               UILogic_RemoveGPSDestination(0);
                               sub_7f2(3, &var38, &var42, &var46, &var50);
                               CineScript_SetGameCoordSysBinding(&var23);
                               sub_a5d(var13, 0);
                               sub_a5d(var11, 1);
                               Racer_Deactivate(var13);
                               Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", 605, &var29, &var32, &var35, "WarpFromCarToWaitPosition_CarneySign");
                               while (!Warper_IsReadyToLoadStuff())
                               {
                                   WAITUNWARPED(100);
                                   PRINTSTRING("Waiting For Camera To Get To Safe Spot\n");
                               }
                               PostProcessing_SetCutsceneDof();
                               CineScript_Prop_LoadSetDressing("cut_hk2_24_set_items", 0);
                               Warper_SetPauseAtEndOfCut(1);
                               var22 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_find_sh_02c_generated", &null, 0, 1500);
                               while (!IsChildFinished(var22))
                               {
                                   WAITUNWARPED(100);
                               }
                               PostProcessing_SetGameDof();
                               sub_c3c(&var46);
                               while (Form_GetFormVisible(var21))
                               {
                                   WAITUNWARPED(100);
                               }
                               sub_c98(1, 1, 0x3f800000, 0);
                               CineScript_Prop_UnloadSetDressing("cut_hk2_24_set_items");
                               UILogic_UnPauseCamera();
                               sub_ffb(1, 1, 0x3f800000, 0);
                               Racer_PlayIgnition(var13);
                               Racer_Activate(var13);
                               mcEvent_PostEventStr("MISSION_EVENT", "FIND_SH_02C_OBJ_01_COMPLETE");
                               mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                           }
                           else
                           {
                               while (var14 < 30.0f)
                               {
                                   var14 = Racer_DistanceToPoint(var13, &var7);
                                   WAITUNWARPED(200);
                               }
                               mcHudMapServer_AddElement(var6);
                           }
                       }
                       else
                       {
                           sub_676(var20, "FIND_SH_02C_MONEY_RESTRICTION_DESC", "FIND_SH_02C_MONEY_RESTRICTION_TITLE", 1, 1);
                           while (var14 < 30.0f)
                           {
                               var14 = Racer_DistanceToPoint(var13, &var7);
                               WAITUNWARPED(200);
                           }
                           mcHudMapServer_AddElement(var6);
                       }
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
   mcTargetManager_HideTarget(605, 1);
   mcHudMapServer_DeleteElement(var6);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_1be(var0)
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

function sub_676(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12;

   var7 = 1;
   MessageBox_ShowMessageBox(var0, var1, var2, var3, var4);
   while (var7)
   {
       var7 = MessageBox_GetMessageBoxVisible();
       WAITUNWARPED(100);
   }
   return MessageBox_GetMessageBoxResult();
}

void sub_7f2(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;

   var8 = 0;
   while (!var8)
   {
       var8 = 1;
       var7 = 0;
       while (var7 < var0)
       {
           var8 = var8 && CineScript_Characters_LoadType((*var1)[var7], (*var2)[var7]);
           var7 = var7 + 1;
       }
       WAITUNWARPED(100);
       PRINTSTRING("LoadHangoutCharacters : Streaming characters\n");
   }
   PRINTSTRING("LoadHangoutCharacters : Streaming characters load complete.\n");
   var9 = CineScript_DoesAnimPackExist((*var3)[0]);
   if (var9)
   {
       var10 = (*var3)[0];
       PRINTSTRING("Using Hangout Animpack:  ");
       PRINTSTRING(var10);
       PRINTNL();
       CineScript_StartLoadHangoutAnimPack(var10);
       while (!CineScript_IsLoadedHangoutAnimPack())
       {
           WAITUNWARPED(100);
           PRINTSTRING("LoadHangoutCharacters : Streaming animpack\n");
       }
       PRINTSTRING("LoadHangoutCharacters : Streaming animpack load complete.\n");
       var8 = var8 && 1;
   }
   else
   {
       var7 = 0;
       while (var7 < var0)
       {
           CineScript_Characters_LoadAnimation((*var3)[var7], (*var4)[var7]);
           var7 = var7 + 1;
       }
   }
   var7 = 0;
   while (var7 < var0)
   {
       var15 = CineScript_Characters_LaunchAnimAt((*var1)[var7], (*var2)[var7], (*var3)[var7], (*var4)[var7], &var11, -1);
       CineScript_PushKillBuffer(var15, 0);
       var7 = var7 + 1;
   }
}

void sub_a5d(var0, var1)
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

void sub_c3c(var0)
{
   auto var3, var4;

   CineScript_PopKillBuffer(0);
   var3 = CineScript_DoesAnimPackExist((*var0)[0]);
   if (var3)
   {
       CineScript_ReleaseHangoutAnimPack();
   }
}

void sub_c98(var0, var1, var2, var3)
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

void sub_ffb(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE UP REPORT\n");
   PRINTSTRING("==============\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var7 == 0) && ((var8 != 0) || (var9 != 0)))
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
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", 0.01f);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", var2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 1);
       if (var0)
       {
           var7 = 1;
           while (var7 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
               if (var7 == 1)
               {
                   PRINTSTRING("SCRIPT: waiting for transition movie transition up...\n");
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

