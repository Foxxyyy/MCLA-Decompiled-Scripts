void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14;

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
   var2 = LookupCity(GetCurrentCity());
   var7 = mcMissionManager_GetMission("RACE_GH_06");
   var8 = ((mcMission_GetState(var7) > 2) || GetDemoCommandLine()) || GetNoTutorialCommandLine();
   if (var8)
   {
       PRINTSTRING("WE ARE STARTING AT THE GARAGE\n");
   }
   else
   {
       PRINTSTRING("WE ARE NOT STARTING AT THE GARAGE\n");
   }
   if (var8)
   {
       CityDescription_GetDefaultStartPosition(var2, &var3, &var6);
   }
   else
   {
       var3.v0 = -199.5f;
       var3.v1 = 18.85f;
       var3.v2 = -752.03f;
       var6 = 167.75f;
   }
   UILogic_LockStreamingPosHeading(&var3, var6);
   var9 = LocalOptions_GetCurrentVehicleProfileIndex();
   var10 = 0;
   var11 = null;
   if (GetDemoCommandLine())
   {
       if (LocalOptions_LookupVehicleProfile("DEMO_vp_mit_3000gt_99") == -1)
       {
           var9 = LocalOptions_AddVehicleToPlayer("DEMO_vp_mit_3000gt_99");
       }
       if (LocalOptions_LookupVehicleProfile("DEMO_vp_sln_s281_06") == -1)
       {
           LocalOptions_AddVehicleToPlayer("DEMO_vp_sln_s281_06");
       }
   }
   else
   {
       var11 = GetCarCommandLine(&var10);
   }
   if (var10 != 0)
   {
       var9 = LocalOptions_LookupVehicleProfile(var11);
       if (var9 == -1)
       {
           var9 = LocalOptions_AddVehicleToPlayer(var11);
       }
   }
   var12 = LocalOptions_GetVehicleProfile(var9);
   LayerPlayer_LoadPlayer(0, var12, &var3, var6);
   while (FlashNavigator_IsTransitioning())
   {
       WAITUNWARPED(100);
   }
   var13 = sub_4eb(0);
   Racer_SetStreamLockState(var13, 1);
   Racer_InitializeResetPosition(var13, &var3, var6);
   Racer_SetUIDAndCharacterName(var13, 50, L[0]);
   Racer_Reset(var13);
   while (!Racer_IsSimStreamed(var13))
   {
       WAITUNWARPED(30);
   }
   if (var8)
   {
       Racer_Deactivate(var13);
   }
   mcTargetManager_RegisterPlayer(50, Player_FindObject(0));
   var14 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(var14, 0, var13);
   mcHudMapServer_AddElement(var14);
   while (!Racer_IsVinylStreamed(var13))
   {
       WAITUNWARPED(30);
   }
   sub_5e0();
   AudioManager_StopLoadingMusic();
   if (var8)
   {
       Warper_Warp("USER_WAIT_NO_CUT_DOWN");
       while (Warper_IsWarping())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Finished waiting\n");
       mcGame_ThrowEvent("cruising");
       Racer_Activate(var13);
       mcMusicManager_Play(0);
   }
   else
   {
       City_SetHighLodEnable(1);
       UILogic_SetIsGPSJumping(0);
       UILogic_UnPauseCamera();
   }
   WAITUNWARPED(1000);
   while (FlashNavigator_IsTransitioning())
   {
       WAITUNWARPED(100);
   }
   mcGame_ThrowEvent("loadSuccess");
   if (mcMissionManager_GetNumMissions(1) > 0)
   {
       mcMissionManager_SetReminderCountdown(5.0f);
   }
   PrestreamManager_UnlockAll();
   while (1)
   {
       WAITUNWARPED(100000);
   }
}

function sub_4eb(var0)
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

void sub_5e0()
{
   mcSlotSystem_ClearAllDistricts();
   while (!mcSlotSystem_AreDistrictsClean())
   {
       PRINTSTRING("Waiting for districts to be purged\n");
       WAITUNWARPED(100);
   }
   WAITUNWARPED(300);
   mcSlotSystem_EvaluateAllDistricts();
}

