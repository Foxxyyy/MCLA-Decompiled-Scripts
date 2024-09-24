void main()
{
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
   L[87] = 0;
   L[88] = -1;
   L[89] = 1;
   if (!(L[122].v0 == 3))
   {
       L[122].v0 = 2;
       PRINTSTRING("Script: Play Logo here?\n");
       PRINTSTRING("Script: Play Intro movie here?\n");
       strcpy(&L[90], 64, "SC");
       strcpy(&L[106], 64, "vp_mit_3000gt_99");
       Registry_SetValueString("raceOverCommand", "");
       L[69] = 2;
       while (!(L[69] == 0))
       {
           L[86] = L[69];
           L[69] = 0;
           switch (L[86])
           {
               case 1:
               {
                   PRINTSTRING("Script: Going into a Movie!\n");
                   sub_40a(L[70].v0, L[70].v1, L[70].v2, L[70].v3, L[70].v4, L[70].v5, L[70].v6, L[70].v7, L[70].v8, L[70].v9, L[70].v10, L[70].v11, L[70].v12, L[70].v13, L[70].v14, L[70].v15);
                   break;
               }
               case 2:
               {
                   PRINTSTRING("Script: Going into a Game!\n");
                   sub_5a9();
                   break;
               }
           }
       }
   }
   WAIT(1000);
   PRINTSTRING("Script: Play splash?\n");
   while (1)
   {
       WAIT(100);
   }
}

void sub_40a(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15)
{
   auto var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35;

   var18 = UIManager_LoadMovie("Menu", &var0, 500, 100, 10000, 0);
   strcpy(&L[37], 64, "C_SWITCHMODULE_TRIG");
   var19 = 0;
   while (var19 == 0)
   {
       FlashHelper_GetGlobalInt(var18, &L[37], &var19);
       WAIT(100);
   }
   strcpy(&L[37], 64, "C_NEXTMODULE_NAME");
   FlashHelper_GetGlobalString(var18, &L[37], &L[53]);
   L[69] = sub_4ac(L[53].v0, L[53].v1, L[53].v2, L[53].v3, L[53].v4, L[53].v5, L[53].v6, L[53].v7, L[53].v8, L[53].v9, L[53].v10, L[53].v11, L[53].v12, L[53].v13, L[53].v14, L[53].v15);
   strcpy(&L[37], 64, "C_NEXTMODULE_DESC");
   FlashHelper_GetGlobalString(var18, &L[37], &L[70]);
   if (L[69] == 2)
   {
       strcpy(&L[90], 64, "SC");
       FlashHelper_GetGlobalInt(var18, "d_careermode_id", &L[89]);
   }
   UIManager_UnloadMovie("Menu");
}

function sub_4ac(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15)
{
   auto var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33;

   if (StringCaseCompare(&var0, "INGAME"))
   {
       return 2;
   }
   else if (StringCaseCompare(&var0, "PUSHMOVIE"))
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

void sub_5a9()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30;

   var2 = !GetNoCareerCommandLine();
   PRINTSTRING("Playing Game\n");
   var3 = 0;
   var4 = GetCityCommandLine(&var3);
   if (!(var3 == 0))
   {
       strcpy(&L[90], 64, var4);
   }
   var5 = LookupCity(&L[90]);
   LayerCity_LoadCity(&L[90]);
   LayerAmbients_LoadAmbients(&L[90]);
   var6 = 0;
   var7 = GetCarCommandLine(&var6);
   if (var2 || (var6 != 0))
   {
       var8 = UIManager_LoadMovie("HUDMAPMOVIE", "hudmap/hudmap.swf", 150, 200, 10000, 0);
       var9 = UIManager_LoadMovie("SIDEKICKMOVIE", "sidekick/sidekick.swf", 50, 50, 10000, 0);
       var10 = UIManager_LoadMovie("PHOTOALBUMMOVIE", "photoalbum/photoalbum.swf", 300, 500, 10000, 0);
       var11 = UIManager_LoadMovie("NAVSYS2DMOVIE", "navsys2d/navsys2d.swf", 400, 200, 10000, 0);
       UIManager_LoadHUD();
       UILogic_PreLoad();
       var12 = UIManager_LoadMovie("PAUSEMOVIE", "pause/pause.swf", 2400, 1500, 10000, 1);
       var13 = UIManager_LoadMovie("NAVSYSMOVIE", "navsys/navsys.swf", 3100, 1600, 10000, 0);
       var14 = UIManager_LoadMovie("NAVSYSTARGETICONMOVIE", "navsys_target/navsys_target.swf", 20, 20, 10000, 0);
       var15 = UIManager_LoadMovie("PROMPTMOVIE", "prompt/prompt.swf", 300, 100, 10000, 1);
       var16 = UIManager_LoadMovie("TRANSITIONMOVIE", "transition/transition.swf", 50, 50, 10000, 0);
       var17 = UIManager_LoadMovie("POPUPMOVIE", "popup/popup.swf", 1700, 1500, 10000, 1);
       UILogic_PostLoad();
       UIManager_LoadStates();
       sub_898();
   }
   if (var2)
   {
       var18 = START_NEW_SCRIPT("Game/Flow/PressStart", 1500);
       while (!IsChildFinished(var18))
       {
           WAITUNWARPED(30);
       }
   }
   else
   {
       Game_SetLoadingDone();
       AudioManager_StopLoadingMusic();
       WAIT(1500);
       Game_FadeLoadscreenLogo(1);
       Game_LoadScreenShutdown();
       mcEvent_PostEventStr("EVENT_START_SCREEN_EXIT", "");
   }
   var19 = null;
   var20 = null;
   if ((!var2) && (var6 != 0))
   {
       CityDescription_GetDefaultStartPosition(var5, &var21, &var24);
       if (GetDemoCommandLine())
       {
           LocalOptions_AddVehicleToPlayer("vp_nsn_240sx_98");
           LocalOptions_AddVehicleToPlayer("vp_nsn_350z_06");
           LocalOptions_AddVehicleToPlayer("vp_nsn_skyline_99");
           var25 = RAND_INT_RANGE(0, 2);
           mcMusicManager_Play(0);
       }
       else
       {
           var25 = LocalOptions_AddVehicleToPlayer(var7);
           if (var25 == -1)
           {
               PRINTSTRING("BOOT - Attempt to load a default car config\n");
               var26 = mcCarConfig_Create(var7);
               var25 = LocalOptions_AddConfigToPlayer(var26);
               mcCarConfig_Destroy(var26);
           }
       }
       LocalOptions_SetCurrentVehicleProfileIndex(var25);
       var27 = LocalOptions_GetVehicleProfile(var25);
       LayerPlayer_LoadPlayer(0, var27, &var21, var24);
       var19 = Player_FindObject(0);
       var20 = Player_GetRacer(var19);
       Racer_SetStreamLockState(var20, 1);
       Racer_InitializeResetPosition(var20, &var21, var24);
       Racer_SetUIDAndCharacterName(var20, 50, L[0]);
       Racer_Reset(var20);
       mcTargetManager_RegisterPlayer(50, var19);
       var28 = mcHudMapServer_CreateElement();
       mcHudMapServer_SetVehicleElement(var28, 0, var20);
       mcHudMapServer_AddElement(var28);
       mcEvent_PostEventStr("EVENT_PRE_PLAYER_LOAD", "");
       while (!Racer_IsCarStreamed(var20))
       {
           WAITUNWARPED(100);
       }
       if (!(L[88] == -1))
       {
           Racer_SetModValue(var20, L[88]);
       }
       PRINTSTRING("PLAYER HAS BEEN LOADED\n");
       START_NEW_SCRIPT_WITH_ARGS("Game/Flow/BootDebug", &null, 0, 1500);
       mcEvent_PostEventStr("EVENT_POST_PLAYER_LOAD", "");
       mcGame_ThrowEvent("cruising");
       mcCareer_StartNewScript("Game/MiscTasks/SoundTriggers", 1500);
   }
   else if (var2)
   {
       WAIT(30);
       while (var19 == null)
       {
           var19 = Player_FindObject(0);
           WAITUNWARPED(30);
       }
       var20 = Player_GetRacer(var19);
       while (!Racer_IsCarStreamed(var20))
       {
           WAITUNWARPED(30);
       }
       mcEvent_PostEventStr("EVENT_POST_PLAYER_LOAD", "");
   }
   var29 = 0;
   var30 = GetExtraCarCommandLine(&var29);
   if (var29 != 0)
   {
       if (LocalOptions_LookupVehicleProfile(var30) == -1)
       {
           LocalOptions_AddVehicleToPlayer(var30);
       }
   }
   sub_480c();
   WAIT(10000);
}

void sub_898()
{
   CineScript_Characters_RegisterDriverMappings("drv_mp_01_set", "drv_mp_01_set_h", "character/drv_mp_01_set_h/", "drv_mp_01_mot_set_h", "character/drv_mp_01_mot_set_h/", "drv_mp_01_set_HackedScale", "character/drv_mp_01_set_HackedScale/", "drv_mp_jacket_01_set_hackedscale", "character/drv_mp_jacket_01_set_hackedscale/", "drv_mp_01_lod02_set", "character/drv_mp_01_lod02_set/", "drv_mp_01_mot_lod02_set", "character/drv_mp_01_mot_lod02_set/");
   CineScript_Characters_RegisterDriverMappings("drv_ma_03_set", "drv_ma_03_set_h", "character/drv_ma_03_set_h", "drv_ma_03_mot_set_h", "character/drv_ma_03_mot_set_h", "drv_ma_03_set_HackedScale", "character/drv_ma_03_set_HackedScale", "drv_ma_03_set_HackedScale", "character/drv_ma_03_set_HackedScale", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_mot_lod02_set", "character/drv_ma_03_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_001_set", "drv_mb_001_set_h", "character/drv_mb_001_set_h", "drv_mb_001_mot_set_h", "character/drv_mb_001_mot_set_h", "drv_mb_001_set_HackedScale", "character/drv_mb_001_set_HackedScale", "drv_mb_001_set_HackedScale", "character/drv_mb_001_set_HackedScale", "drv_mb_001_lod02_set", "character/drv_mb_001_lod02_set", "drv_mb_001_mot_lod02_set", "character/drv_mb_001_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_009_set", "drv_mb_009_set_h", "character/drv_mb_009_set_h", "drv_mb_009_mot_set_h", "character/drv_mb_009_mot_set_h", "drv_mb_009_set", "character/drv_mb_009_set", "drv_mb_009_set", "character/drv_mb_009_set", "drv_mb_009_lod02_set", "character/drv_mb_009_lod02_set", "drv_mb_009_mot_lod02_set", "character/drv_mb_009_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_001_set", "drv_mc_001_set_h", "character/drv_mc_001_set_h", "drv_mc_001_mot_set_h", "character/drv_mc_001_mot_set_h", "drv_mc_001_set_HackedScale", "character/drv_mc_001_set_HackedScale", "drv_mc_001_set_HackedScale", "character/drv_mc_001_set_HackedScale", "drv_mc_001_lod02_set", "character/drv_mc_001_lod02_set", "drv_mc_001_mot_lod02_set", "character/drv_mc_001_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_07_set", "drv_mc_07_set_h", "character/drv_mc_07_set_h", "drv_mc_07_mot_set_h", "character/drv_mc_07_mot_set_h", "drv_mc_07_set", "character/drv_mc_07_set", "drv_mc_07_set", "character/drv_mc_07_set", "drv_mc_07_lod02_set", "character/drv_mc_07_lod02_set", "drv_mc_07_mot_lod02_set", "character/drv_mc_07_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_005_set", "drv_mh_005_set_h", "character/drv_mh_005_set_h", "drv_mh_005_mot_set_h", "character/drv_mh_005_mot_set_h", "drv_mh_005_set", "character/drv_mh_005_set", "drv_mh_005_set", "character/drv_mh_005_set", "drv_mh_005_lod02_set", "character/drv_mh_005_lod02_set", "drv_mh_005_mot_lod2_set", "character/drv_mh_005_mot_lod2_set");
   CineScript_Characters_RegisterDriverMappings("drv_fh_001_set", "drv_fh_001_set_h", "character/drv_fh_001_set_h", "drv_fh_001_mot_set_h", "character/drv_fh_001_mot_set_h", "drv_fh_001_set", "character/drv_fh_001_set", "drv_fh_001_set", "character/drv_fh_001_set", "drv_fh_001_lod02_set", "character/drv_fh_001_lod02_set", "drv_fh_001_mot_lod02_set", "character/drv_fh_001_mot_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_fb_002_set", "drv_sc_fb_002_set_h", "character/drv_sc_fb_002_set_h", "drv_sc_fb_002_set_h", "character/drv_sc_fb_002_set_h", "drv_sc_fb_002_set", "character/drv_sc_fb_002_set", "drv_sc_fb_002_set", "character/drv_sc_fb_002_set", "drv_sc_fb_002_set", "character/drv_sc_fb_002_set", "drv_sc_fb_002_set", "character/drv_sc_fb_002_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_fh_004_set", "drv_sc_fh_004_set_h", "character/drv_sc_fh_004_set_h", "drv_sc_fh_004_mot_set_h", "character/drv_sc_fh_004_mot_set_h", "drv_sc_fh_004_set", "character/drv_sc_fh_004_set", "drv_sc_fh_004_set", "character/drv_sc_fh_004_set", "drv_sc_fh_004_set", "character/drv_sc_fh_004_set", "drv_sc_fh_004_set", "character/drv_sc_fh_004_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_fh_005_set", "drv_sc_fh_005_set_h", "character/drv_sc_fh_005_set_h", "drv_sc_fh_005_set_h", "character/drv_sc_fh_005_set_h", "drv_sc_fh_005_set", "character/drv_sc_fh_005_set", "drv_sc_fh_005_set", "character/drv_sc_fh_005_set", "drv_sc_fh_005_set", "character/drv_sc_fh_005_set", "drv_sc_fh_005_set", "character/drv_sc_fh_005_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_ma_004_set", "drv_sc_ma_004_set_h", "character/drv_sc_ma_004_set_h", "drv_sc_ma_004_set_h", "character/drv_sc_ma_004_set_h", "drv_sc_ma_004_set", "character/drv_sc_ma_004_set", "drv_sc_ma_004_set", "character/drv_sc_ma_004_set", "drv_sc_ma_004_set", "character/drv_sc_ma_004_set", "drv_sc_ma_004_set", "character/drv_sc_ma_004_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_002_set", "drv_sc_mb_002_set_h", "character/drv_sc_mb_002_set_h", "drv_sc_mb_002_set_h", "character/drv_sc_mb_002_set_h", "drv_sc_mb_002_set", "character/drv_sc_mb_002_set", "drv_sc_mb_002_set", "character/drv_sc_mb_002_set", "drv_sc_mb_002_set", "character/drv_sc_mb_002_set", "drv_sc_mb_002_set", "character/drv_sc_mb_002_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_011_set", "drv_sc_mb_011_set_h", "character/drv_sc_mb_011_set_h", "drv_sc_mb_011_set_h", "character/drv_sc_mb_011_set_h", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_012_set", "drv_sc_mb_012_set_h", "character/drv_sc_mb_012_set_h", "drv_sc_mb_012_set_h", "character/drv_sc_mb_012_set_h", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_013_set", "drv_sc_mb_013_set_h", "character/drv_sc_mb_013_set_h", "drv_sc_mb_013_set_h", "character/drv_sc_mb_013_set_h", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_014_set", "drv_sc_mb_014_set_h", "character/drv_sc_mb_014_set_h", "drv_sc_mb_014_set_h", "character/drv_sc_mb_014_set_h", "drv_sc_mb_014_set", "character/drv_sc_mb_014_set", "drv_sc_mb_014_set", "character/drv_sc_mb_014_set", "drv_sc_mb_014_set", "character/drv_sc_mb_014_set", "drv_sc_mb_014_set", "character/drv_sc_mb_014_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mh_007_set", "drv_sc_mh_007_set_h", "character/drv_sc_mh_007_set_h", "drv_sc_mh_007_set_h", "character/drv_sc_mh_007_set_h", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mh_008_set", "drv_sc_mh_008_set_h", "character/drv_sc_mh_008_set_h", "drv_sc_mh_008_set_h", "character/drv_sc_mh_008_set_h", "drv_sc_mh_008_set", "character/drv_sc_mh_008_set", "drv_sc_mh_008_set", "character/drv_sc_mh_008_set", "drv_sc_mh_008_set", "character/drv_sc_mh_008_set", "drv_sc_mh_008_set", "character/drv_sc_mh_008_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mh_009_set", "drv_sc_mh_009_set_h", "character/drv_sc_mh_009_set_h", "drv_sc_mh_009_set_h", "character/drv_sc_mh_009_set_h", "drv_sc_mh_009_set", "character/drv_sc_mh_009_set", "drv_sc_mh_009_set", "character/drv_sc_mh_009_set", "drv_sc_mh_009_set", "character/drv_sc_mh_009_set", "drv_sc_mh_009_set", "character/drv_sc_mh_009_set");
   CineScript_Characters_RegisterDriverMappings("mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set", "mec_sc_mb_001_set", "character/mec_sc_mb_001_set");
   CineScript_Characters_RegisterDriverMappings("drv_ma_001_set", "drv_ma_001_set_h", "character/drv_ma_001_set_h", "drv_ma_001_mot_set_h", "character/drv_ma_001_mot_set_h", "drv_ma_001_set_HackedScale", "character/drv_ma_001_set_HackedScale", "drv_ma_001_set_HackedScale", "character/drv_ma_001_set_HackedScale", "drv_ma_001_lod02_set", "character/drv_ma_001_lod02_set", "drv_ma_001_lod02_set", "character/drv_ma_001_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_ma_02_set", "drv_ma_02_set_h", "character/drv_ma_02_set_h", "drv_ma_02_mot_set_h", "character/drv_ma_02_mot_set_h", "drv_ma_02_set", "character/drv_ma_02_set", "drv_ma_02_set", "character/drv_ma_02_set", "drv_ma_02_lod02_set", "character/drv_ma_02_lod02_set", "drv_ma_02_lod02_set", "character/drv_ma_02_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_02_set", "drv_mb_02_set_h", "character/drv_mb_02_set_h", "drv_mb_02_set_h", "character/drv_mb_02_set_h", "drv_mb_02_set", "character/drv_mb_02_set", "drv_mb_02_set", "character/drv_mb_02_set", "drv_mb_02_lod02_set", "character/drv_mb_02_lod02_set", "drv_mb_02_lod02_set", "character/drv_mb_02_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_03_set", "drv_mb_03_set_h", "character/drv_mb_03_set_h", "drv_mb_03_set_h", "character/drv_mb_03_set_h", "drv_mb_03_set", "character/drv_mb_03_set", "drv_mb_03_set", "character/drv_mb_03_set", "drv_mb_03_lod02_set", "character/drv_mb_03_lod02_set", "drv_mb_03_lod02_set", "character/drv_mb_03_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_04_set", "drv_mb_04_set_h", "character/drv_mb_04_set_h", "drv_mb_04_set_h", "character/drv_mb_04_set_h", "drv_mb_04_set_HackedScale", "character/drv_mb_04_set_HackedScale", "drv_mb_04_set_HackedScale", "character/drv_mb_04_set_HackedScale", "drv_mb_04_lod02_set", "character/drv_mb_04_lod02_set", "drv_mb_04_lod02_set", "character/drv_mb_04_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_05_set", "drv_mb_05_set_h", "character/drv_mb_05_set_h", "drv_mb_05_set_h", "character/drv_mb_05_set_h", "drv_mb_05_set", "character/drv_mb_05_set", "drv_mb_05_set", "character/drv_mb_05_set", "drv_mb_05_lod02_set", "character/drv_mb_05_lod02_set", "drv_mb_05_lod02_set", "character/drv_mb_05_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_06_set", "drv_mb_06_set_h", "character/drv_mb_06_set_h", "drv_mb_06_set_h", "character/drv_mb_06_set_h", "drv_mb_06_set", "character/drv_mb_06_set", "drv_mb_06_set", "character/drv_mb_06_set", "drv_mb_06_lod02_set", "character/drv_mb_06_lod02_set", "drv_mb_06_lod02_set", "character/drv_mb_06_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_007_set", "drv_mb_007_set_h", "character/drv_mb_007_set_h", "drv_mb_007_set_h", "character/drv_mb_007_set_h", "drv_mb_007_set", "character/drv_mb_007_set", "drv_mb_007_set", "character/drv_mb_007_set", "drv_mb_007_lod02_set", "character/drv_mb_007_lod02_set", "drv_mb_007_lod02_set", "character/drv_mb_007_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_008_set", "drv_mb_008_set_h", "character/drv_mb_008_set_h", "drv_mb_008_set_h", "character/drv_mb_008_set_h", "drv_mb_008_set_HackedScale", "character/drv_mb_008_set_HackedScale", "drv_mb_008_set_HackedScale", "character/drv_mb_008_set_HackedScale", "drv_mb_008_lod02_set", "character/drv_mb_008_lod02_set", "drv_mb_008_lod02_set", "character/drv_mb_008_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mb_010_set", "drv_mb_010_set_h", "character/drv_mb_010_set_h", "drv_mb_010_set_h", "character/drv_mb_010_set_h", "drv_mb_010_set", "character/drv_mb_010_set", "drv_mb_010_set", "character/drv_mb_010_set", "drv_mb_010_lod02_set", "character/drv_mb_010_lod02_set", "drv_mb_010_lod02_set", "character/drv_mb_010_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_02_set", "drv_mc_02_set_h", "character/drv_mc_02_set_h", "drv_mc_02_set_h", "character/drv_mc_02_set_h", "drv_mc_02_set_HackedScale", "character/drv_mc_02_set_HackedScale", "drv_mc_02_set_HackedScale", "character/drv_mc_02_set_HackedScale", "drv_mc_02_lod02_set", "character/drv_mc_02_lod02_set", "drv_mc_02_lod02_set", "character/drv_mc_02_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_003_set", "drv_mc_003_set_h", "character/drv_mc_003_set_h", "drv_mc_003_set_h", "character/drv_mc_003_set_h", "drv_mc_003_set_HackedScale", "character/drv_mc_003_set_HackedScale", "drv_mc_003_set_HackedScale", "character/drv_mc_003_set_HackedScale", "drv_mc_003_lod02_set", "character/drv_mc_003_lod02_set", "drv_mc_003_lod02_set", "character/drv_mc_003_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_05_set", "drv_mc_05_set_h", "character/drv_mc_05_set_h", "drv_mc_05_set_h", "character/drv_mc_05_set_h", "drv_mc_05_set", "character/drv_mc_05_set", "drv_mc_05_set", "character/drv_mc_05_set", "drv_mc_05_lod02_set", "character/drv_mc_05_lod02_set", "drv_mc_05_lod02_set", "character/drv_mc_05_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mc_06_set", "drv_mc_06_set_h", "character/drv_mc_06_set_h", "drv_mc_06_set_h", "character/drv_mc_06_set_h", "drv_mc_06_set", "character/drv_mc_06_set", "drv_mc_06_set", "character/drv_mc_06_set", "drv_mc_06_lod02_set", "character/drv_mc_06_lod02_set", "drv_mc_06_lod02_set", "character/drv_mc_06_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_01_set", "drv_mh_01_set_h", "character/drv_mh_01_set_h", "drv_mh_01_set_h", "character/drv_mh_01_set_h", "drv_mh_01_set", "character/drv_mh_01_set", "drv_mh_01_set", "character/drv_mh_01_set", "drv_mh_01_lod02_set", "character/drv_mh_01_lod02_set", "drv_mh_01_lod02_set", "character/drv_mh_01_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_02_set", "drv_mh_02_set_h", "character/drv_mh_02_set_h", "drv_mh_02_set_h", "character/drv_mh_02_set_h", "drv_mh_02_set_HackedScale", "character/drv_mh_02_set_HackedScale", "drv_mh_02_set_HackedScale", "character/drv_mh_02_set_HackedScale", "drv_mh_02_lod02_set", "character/drv_mh_02_lod02_set", "drv_mh_02_lod02_set", "character/drv_mh_02_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_003_set", "drv_mh_003_set_h", "character/drv_mh_003_set_h", "drv_mh_003_set_h", "character/drv_mh_003_set_h", "drv_mh_003_set", "character/drv_mh_003_set", "drv_mh_003_set", "character/drv_mh_003_set", "drv_mh_003_lod02_set", "character/drv_mh_003_lod02_set", "drv_mh_003_lod02_set", "character/drv_mh_003_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_04_set", "drv_mh_04_set_h", "character/drv_mh_04_set_h", "drv_mh_04_mot_set_h", "character/drv_mh_04_mot_set_h", "drv_mh_04_set", "character/drv_mh_04_set", "drv_mh_04_set", "character/drv_mh_04_set", "drv_mh_04_lod02_set", "character/drv_mh_04_lod02_set", "drv_mh_04_lod02_set", "character/drv_mh_04_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_mh_006_set", "drv_mh_006_set_h", "character/drv_mh_006_set_h", "drv_mh_006_set_h", "character/drv_mh_006_set_h", "drv_mh_006_set_HackedScale", "character/drv_mh_006_set_HackedScale", "drv_mh_006_set_HackedScale", "character/drv_mh_006_set_HackedScale", "drv_mh_006_lod02_set", "character/drv_mh_006_lod02_set", "drv_mh_006_lod02_set", "character/drv_mh_006_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_fb_01_set", "drv_fb_01_set_h", "character/drv_fb_01_set_h", "drv_fb_01_set_h", "character/drv_fb_01_set_h", "drv_fb_01_set", "character/drv_fb_01_set", "drv_fb_01_set", "character/drv_fb_01_set", "drv_fb_01_lod02_set", "character/drv_fb_01_lod02_set", "drv_fb_01_lod02_set", "character/drv_fb_01_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_fc_002_set", "drv_fc_002_set_h", "character/drv_fc_002_set_h", "drv_fc_002_set_h", "character/drv_fc_002_set_h", "drv_fc_002_set_HackedScale", "character/drv_fc_002_set_HackedScale", "drv_fc_002_set_HackedScale", "character/drv_fc_002_set_HackedScale", "drv_fc_002_lod02_set", "character/drv_fc_002_lod02_set", "drv_fc_002_lod02_set", "character/drv_fc_002_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_fa_001_set", "drv_fa_001_set_h", "character/drv_fa_001_set_h", "drv_fa_001_set_h", "character/drv_fa_001_set_h", "drv_fa_001_set", "character/drv_fa_001_set", "drv_fa_001_set", "character/drv_fa_001_set", "drv_fa_001_lod02_set", "character/drv_fa_001_lod02_set", "drv_fa_001_lod02_set", "character/drv_fa_001_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_fc_003_set", "drv_fc_003_set_h", "character/drv_fc_003_set_h", "drv_fc_003_set_h", "character/drv_fc_003_set_h", "drv_fc_003_set_HackedScale", "character/drv_fc_003_set_HackedScale", "drv_fc_003_set_HackedScale", "character/drv_fc_003_set_HackedScale", "drv_fc_003_lod02_set", "character/drv_fc_003_lod02_set", "drv_fc_003_lod02_set", "character/drv_fc_003_lod02_set");
   CineScript_Characters_RegisterDriverMappings("mec_mc_01_set", "mec_mc_01_set", "character/mec_mc_01_set", "mec_mc_01_set", "character/mec_mc_01_set", "mec_mc_01_set_HackedScale", "character/mec_mc_01_set_HackedScale", "mec_mc_01_set_HackedScale", "character/mec_mc_01_set_HackedScale", "mec_mc_01_lod02_set", "character/mec_mc_01_lod02_set", "mec_mc_01_lod02_set", "character/mec_mc_01_lod02_set");
}

void sub_480c()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34;

   var2 = 3;
   var6 = 3;
   var16 = 3;
   var20 = 3;
   var2[0] = "vp_chv_police_96";
   var6[0 * 3].v0 = 2030.1f;
   var6[0 * 3].v1 = 6.8f;
   var6[0 * 3].v2 = -813.7f;
   var16[0] = (float)90;
   var20[0 * 3].v0 = -510.0f;
   var20[0 * 3].v1 = 9.5f;
   var20[0 * 3].v2 = -400.0f;
   var2[1] = "vp_chv_police_96";
   var6[1 * 3].v0 = -646.8f;
   var6[1 * 3].v1 = 18.5f;
   var6[1 * 3].v2 = -643.8f;
   var16[1] = (float)90;
   var20[1 * 3].v0 = -500.0f;
   var20[1 * 3].v1 = 9.5f;
   var20[1 * 3].v2 = -400.0f;
   var2[2] = "vp_chv_police_96";
   var6[2 * 3].v0 = -2434.4f;
   var6[2 * 3].v1 = 1.9f;
   var6[2 * 3].v2 = -577.9f;
   var16[2] = 84.9f;
   var20[2 * 3].v0 = -490.0f;
   var20[2 * 3].v1 = 9.5f;
   var20[2 * 3].v2 = -400.0f;
   var30 = 3;
   var34 = 0;
   while (var34 < 3)
   {
       var30[var34] = PoliceManager_CreatePolice(var2[var34], 1, &(var6[var34 * 3]), var16[var34], &(var20[var34 * 3]), 400 + var34);
       var34 = var34 + 1;
   }
}

