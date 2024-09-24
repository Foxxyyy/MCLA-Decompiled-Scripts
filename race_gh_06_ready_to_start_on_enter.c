void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25;

   L[0] = "drv_mp_01_set";
   L[1] = "drv_mp_01_lod02_set";
   L[2] = "drv_ma_03_set";
   L[3] = "drv_ma_02_set";
   L[4] = "drv_ma_001_set";
   L[5] = "drv_fa_001_set";
   L[6] = "drv_mb_02_set";
   L[7] = "drv_mb_03_set";
   L[8] = "drv_mb_04_set";
   L[9] = "drv_mb_05_set";
   L[10] = "drv_mb_007_set";
   L[11] = "drv_mb_008_set";
   L[12] = "drv_mb_010_set";
   L[13] = "drv_mb_001_set";
   L[14] = "drv_mb_009_set";
   L[15] = "drv_mb_06_set";
   L[16] = "drv_fb_01_set";
   L[17] = "drv_mc_02_set";
   L[18] = "drv_mc_06_set";
   L[19] = "drv_mc_07_set";
   L[20] = "drv_mc_003_set";
   L[21] = "drv_mc_05_set";
   L[22] = "drv_mc_001_set";
   L[23] = "drv_fc_002_set";
   L[24] = "drv_mh_01_set";
   L[25] = "drv_mh_02_set";
   L[26] = "drv_mh_003_set";
   L[27] = "drv_mh_005_set";
   L[28] = "drv_mh_04_set";
   L[29] = "drv_mh_006_set";
   L[30] = "drv_fh_001_set";
   L[31] = "mec_mc_01_set";
   L[32] = "ped_ma_001_set";
   L[33] = "ped_mb_001_set";
   L[34] = "ped_mc_001_set";
   L[35] = "ped_mh_001_set";
   L[36] = "pol_mc_01_set";
   var2 = mcMissionManager_GetMission("RACE_GH_06");
   if (!GetDemoCommandLine())
   {
       mcMainState_EnableGpsButton(0);
       sub_31d(1, 1, 0x3f800000, 0);
       var3 = sub_653(0);
       var4.v0 = 0.0f;
       var4.v1 = 0.0f;
       var4.v2 = 0.0f;
       var7 = 0.0f;
       var8 = OpponentManager_CreateOpponent();
       var9 = Opponent_GetRacer(var8);
       Racer_SetStreamingLockedIn(var9);
       OpponentManager_LoadOpponent(var8, "GH_06_0_vp_dsn_280z_75", &var4, 0);
       OpponentManager_AddOpponentToWorld(var8);
       Racer_InitializeResetPosition(var9, &var4, var7);
       Racer_Reset(var9);
       Racer_SetUIDAndCharacterName(var9, 5000, L[6]);
       Racer_HideIcon(var9, 1);
       WAITUNWARPED(500);
       MessageBox_ShowLoadingBox("Career_Loading");
       while (!Racer_IsSimStreamed(var3))
       {
           WAITUNWARPED(10);
       }
       Racer_Deactivate(var3);
       sub_779(var3);
       sub_779(var9);
       MessageBox_HideLoadingBox("Career_Loading");
       PRINTSTRING("FINISHED STREAMING\n");
       sub_811(var3, 0);
       sub_811(var9, 1);
       var10.v2.v0.v0 = 0.0f;
       var10.v2.v0.v1 = 0.0f;
       var10.v2.v0.v2 = 0.0f;
       var10.v2.v3 = 0.0f;
       CineScript_SetGameCoordSysBinding(&var10);
       var16.v0 = -234.0f;
       var16.v1 = 21.0f;
       var16.v2 = -733.0f;
       var19 = 0;
       AmbientMgr_SetRoadDensity(&var16, var19);
       while (Warper_IsWarping())
       {
           WAITUNWARPED(10);
       }
       var20 = OpponentManager_FindFromUID(208);
       PostProcessing_SetCutsceneDof();
       DYNAMICMIXER_TriggerState("DYNAMIC_MIXER_MUTE_SHENANIGANS");
       DYNAMICMIXER_TriggerState("DYNAMIC_MIXER_HENRY_DRIVEBY");
       mcMusicManager_GotoAllGenreSong("HIPHOP_MAINO_HIHATER");
       mcMusicManager_SetStartOffset(19940);
       var21 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_race_gh_06_generated", &null, 0, 1500);
       mcGame_ThrowEvent("intro");
       while (!IsChildFinished(var21))
       {
           WAITUNWARPED(10);
           DYNAMICMIXER_DeTriggerState("DYNAMIC_MIXER_HENRY_DRIVEBY");
           DYNAMICMIXER_DeTriggerState("DYNAMIC_MIXER_MUTE_SHENANIGANS");
           mcMusicManager_SetAllowBackgroundPlay(0);
           if ((var20 != null) && (CineScript_Camera_GetTimeElapsed() > 60.0f))
           {
               OpponentManager_RemoveOpponentFromWorld(var20);
               OpponentManager_DeleteOpponent(var20);
               var20 = null;
           }
       }
       Racer_SetStreamingLockedOut(var9);
       OpponentManager_RemoveOpponentFromWorld(var8);
       OpponentManager_DeleteOpponent(var8);
       PostProcessing_SetGameDof();
       AmbientMgr_SetRoadDensity(&var16, -1);
       Racer_Activate(var3);
   }
   if ((!Net_IsConnecting()) && (!Net_IsNetworked()))
   {
       mcMission_ChangeState(var2, 3, 0);
       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
       mcGame_ThrowEvent("cruising");
       var22 = UIManager_GetState("Cruising_Offline");
       while ((!vhsmState_IsListener(var22)) || FlashNavigator_IsTransitioning())
       {
           WAITUNWARPED(100);
       }
       UIManager_ReplaceDelayedEvent("sidekickResume", 2.0f);
       var23 = null;
       var23 = Sidekick_AppendData(0, "RACE_GH_06", mcCareer_GetHookmanFlashId("SH_01"), 0, 10.0f, "drv_mb_04_set", "Incoming Call!", "REMINDER_RACE_GH_06", "", 2, 1, "REMINDER_RACE_GH_06", "drv_mb_04_set", "PLAYER");
       var24 = HUD_GetHUDCtrl(12);
       while (!mcCtrl_IsVisible(var24))
       {
           WAITUNWARPED(10);
       }
       var25 = Form_GetForm(105);
       if ((var25 != null) && (!GetNoTutorialCommandLine()))
       {
           Form_ShowForm(Form_GetForm(-1), var25);
       }
       while (!Sidekick_HasDataBeenAnnounced(var23))
       {
           WAITUNWARPED(100);
       }
       if ((var25 != null) && Form_GetFormVisible(var25))
       {
           Form_CloseForm(var25);
       }
   }
}

void sub_31d(var0, var1, var2, var3)
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

function sub_653(var0)
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

void sub_779(var0)
{
   auto var3;

   while (!Racer_IsCarStreamed(var0))
   {
       PRINTSTRING("Waiting for racer to be streamed\n");
       WAITUNWARPED(10);
   }
}

void sub_811(var0, var1)
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

