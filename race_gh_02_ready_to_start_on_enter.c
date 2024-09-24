void main()
{
   auto var2, var3, var4, var5, var6, var7, var8;

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
   var2 = UIManager_GetState("Cruising_Offline");
   while ((!vhsmState_IsListener(var2)) && (!FlashNavigator_IsTransitioning()))
   {
       WAITUNWARPED(100);
   }
   Registry_SetValueInt("nInTutorial", 1);
   UIManager_ReplaceDelayedEvent("sidekickResume", 2.0f);
   var3 = Sidekick_AppendData(0, "RACE_GH_02", 0, 1, 10.0f, L[8], "Incoming Call!", "SIDEKICK_RACE_GH_02", "", 1, 0, "SIDEKICK_RACE_GH_02", L[8], "PLAYER");
   var4 = 0;
   var5 = 60;
   var6 = 0;
   if (!GetNoTutorialCommandLine())
   {
       var7 = HUD_GetHUDCtrl(12);
       while (!mcCtrl_IsVisible(var7))
       {
           WAITUNWARPED(10);
       }
       while (!var6)
       {
           WAITUNPAUSED(10);
           if (((!Warper_IsWarping()) && vhsmState_IsListener(var2)) && (!UIManager_IsDisplayingMenu()))
           {
               var5 = var5 - 1;
               if (var5 < 0)
               {
                   var6 = 1;
               }
           }
       }
       AudioManager_SetActiveTimeSlow(1);
       sub_465(0, 0x3f000000, 108);
       sub_4cb(-1, 76, "", 0, 0);
       AudioManager_SetActiveTimeSlow(0);
       Sidekick_RemoveData(var3);
       Ctrl_SetVisible(var7, 0);
   }
   while (!Sidekick_HasDataBeenAnnounced(var3))
   {
       WAITUNWARPED(100);
   }
   var8 = mcMissionManager_GetMission("RACE_GH_02");
   mcMission_ChangeState(var8, 3, 0);
   Registry_GetValueInt("NET_UNLOADCAREER", &var4);
   PRINTSTRING("UNLOAD CAREER = ");
   PRINTINT(var4);
   PRINTSTRING("\n");
   else if ((((!GetNoTutorialCommandLine()) && (var4 < 1)) && (!Net_IsConnecting())) && (!Net_IsNetworked()))
   {
       mcEvent_PostEventStr("GOTO_MISSIONLOG_TUTORIAL", "");
       var2 = UIManager_GetState("MissionLogTutorialScene");
       if (!vhsmState_IsActive(var2))
       {
           while (!vhsmState_IsActive(var2))
           {
               Registry_GetValueInt("NET_UNLOADCAREER", &var4);
               if (((var4 > 0) || Net_IsConnecting()) || Net_IsNetworked())
               {
                   PRINTSTRING("TUTORIAL SHUTTING DOWN\n");
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
       }
       mcCareerSpeech_PlayNamedScenario("TUTORIAL_MISSION_LOG_GPS", "drv_mb_04_set", "PLAYER");
       while (vhsmState_IsActive(var2) || UIManager_IsDisplayingMenu())
       {
           Registry_GetValueInt("NET_UNLOADCAREER", &var4);
           if (((var4 > 0) || Net_IsConnecting()) || Net_IsNetworked())
           {
               PRINTSTRING("TUTORIAL SHUTTING DOWN B\n");
           }
           else
           {
               WAITUNWARPED(10);
           }
       }
       AudioManager_SetActiveTimeSlow(1);
       sub_4cb(-1, 77, "TUTORIAL_TARGET_INGAME", "drv_mb_04_set", "PLAYER");
       AudioManager_SetActiveTimeSlow(0);
   }
   sub_81c(108, 0x3f000000);
   mcMainState_EnableGpsButton(1);
   Registry_SetValueInt("nInTutorial", 0);
}

void sub_465(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_4cb(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15;

   var7 = 1;
   var8 = Form_GetForm(var0);
   var9 = Form_GetForm(var1);
   Form_ShowForm(var8, var9);
   if (!StringCompare(var2, ""))
   {
       var10 = mcCareerSpeech_FindScenario(var2);
       if (var10 != null)
       {
           mcCareerSpeech_Stop();
           mcCareerSpeech_PlayScenario(var10, var3, var4);
       }
   }
   while (var7)
   {
       var7 = Form_GetFormVisible(var9);
       WAITUNWARPED(100);
   }
   return Form_GetFormResult(var9);
}

void sub_81c(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

