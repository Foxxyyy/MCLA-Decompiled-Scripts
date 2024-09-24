void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103;

   var2 = Graphics_GetAndSetAutoUpdateTimeOfDay(0);
   AmbientMgr_SetParkedCarsEnable(0);
   AmbientMgr_Reset();
   var3 = 3;
   var3[0] = "starter_vp_vw_scirocco_88";
   var3[1] = "starter_vp_nsn_240sx_98";
   var3[2] = "starter_vp_vw_golf_83";
   var7 = 3;
   var7[0] = "vp_vw_scirocco_88";
   var7[1] = "vp_nsn_240sx_98";
   var7[2] = "vp_vw_golf_83";
   var11 = 3;
   var11[0 * 3].v0 = -173.088f;
   var11[0 * 3].v1 = 18.169f;
   var11[0 * 3].v2 = -762.769f;
   var11[1 * 3].v0 = -176.355f;
   var11[1 * 3].v1 = 18.199f;
   var11[1 * 3].v2 = -761.178f;
   var11[2 * 3].v0 = -179.104f;
   var11[2 * 3].v1 = 18.203f;
   var11[2 * 3].v2 = -759.119f;
   var21 = 3;
   var21[0] = 34.025f;
   var21[1] = 35.091f;
   var21[2] = 36.12f;
   var25 = 3;
   var35 = 3;
   var25[0 * 3].v0 = -174.154f;
   var25[0 * 3].v1 = 19.609f;
   var25[0 * 3].v2 = -769.263f;
   var35[0 * 3].v0 = -172.353f;
   var35[0 * 3].v1 = 16.673f;
   var35[0 * 3].v2 = -751.904f;
   var25[1 * 3].v0 = -181.709f;
   var25[1 * 3].v1 = 19.577f;
   var25[1 * 3].v2 = -764.572f;
   var35[1 * 3].v0 = -165.489f;
   var35[1 * 3].v1 = 16.825f;
   var35[1 * 3].v2 = -755.183f;
   var25[2 * 3].v0 = -179.077f;
   var25[2 * 3].v1 = 19.065f;
   var25[2 * 3].v2 = -765.562f;
   var35[2 * 3].v0 = -179.634f;
   var35[2 * 3].v1 = 18.415f;
   var35[2 * 3].v2 = -749.725f;
   var45.v0 = -174.542f;
   var45.v1 = 20.308f;
   var45.v2 = -773.402f;
   var48.v0 = -176.885f;
   var48.v1 = 17.332f;
   var48.v2 = -746.174f;
   City_SetFixedStreamingCamLookat(&var45, &var48, 1, 0);
   var51 = 3;
   var55 = 3;
   var59 = 0;
   while (var59 < 3)
   {
       var51[var59] = OpponentManager_CreateOpponent();
       var55[var59] = Opponent_GetRacer(var51[var59]);
       Racer_SetForceHiresTextures(var55[var59], 1);
       OpponentManager_LoadOpponent(var51[var59], var3[var59], &(var11[var59 * 3]), var21[var59]);
       OpponentManager_AddOpponentToWorld(var51[var59]);
       Racer_SetStreamingLockedIn(var55[var59]);
       Racer_SetUID(var55[var59], 205 + var59);
       Racer_SetVehicleDriverEnable(var55[var59], 0);
       if (var59 < 3)
       {
           Racer_Deactivate(var55[var59]);
           Racer_SetHeadlights(var55[var59], 0);
           Racer_SetExhaust(var55[var59], 0);
       }
       Racer_HideIcon(var55[var59], 1);
       var59 = var59 + 1;
   }
   WAITUNWARPED(500);
   MessageBox_ShowLoadingBox("Career_Loading");
   PRINTSTRING("Waiting for selectable vehicles to stream in\n");
   var59 = 0;
   while (var59 < 3)
   {
       while (!Racer_IsCarStreamed(var55[var59]))
       {
           WAIT(20);
       }
       var59 = var59 + 1;
   }
   PRINTSTRING("Selectable vehicles streamed in\n");
   MessageBox_HideLoadingBox("Career_Loading");
   sub_463(1, 1, 0x3f800000, 0);
   var59 = 0;
   while (var59 < 3)
   {
       Racer_SetDefaultSteerDirection(var55[var59], 0.5f);
       var59 = var59 + 1;
   }
   City_SetCrossFadeEnabled(0);
   City_SetHighLodEnable(0);
   var60 = 4;
   var65 = 4;
   var78 = 4;
   var65[0 * 3].v0 = -192.151f;
   var65[0 * 3].v1 = 18.765f;
   var65[0 * 3].v2 = -766.679f;
   var78[0] = 28.189f;
   var65[1 * 3].v0 = -188.556f;
   var65[1 * 3].v1 = 18.733f;
   var65[1 * 3].v2 = -768.174f;
   var78[1] = 28.189f;
   var65[2 * 3].v0 = -185.183f;
   var65[2 * 3].v1 = 18.583f;
   var65[2 * 3].v2 = -769.892f;
   var78[2] = 28.189f;
   var65[3 * 3].v0 = -181.238f;
   var65[3 * 3].v1 = 18.494f;
   var65[3 * 3].v2 = -771.324f;
   var78[3] = 28.189f;
   mcGame_ThrowEvent("loadSuccess");
   AudioManager_StopLoadingMusic();
   var83 = MoviePlayer_StartMovie("game:/intro720.bik", 0);
   if (var83)
   {
       Graphics_SetMovieRenderingMode(1);
   }
   WAIT(2000);
   var83 = MoviePlayer_IsMoviePlaying();
   Graphics_WarpToTimeOfDay(17.0f, 100.0f);
   City_SetFixedStreamingCamLookat(&var45, &var48, 0, 0);
   UILogic_UnPauseCamera();
   Game_SetCamera(&var45, &var48, 25.5f, 0, 0, 0);
   PrestreamManager_UnlockAll();
   SETTIMERA(0);
   if (var83)
   {
       PRINTSTRING("Running intro movie\n");
   }
   else
   {
       PRINTSTRING("NOT Running intro movie\n");
   }
   while (var83)
   {
       WAIT(10);
       var83 = MoviePlayer_IsMoviePlaying();
       Game_SetCamera(&var45, &var48, 25.5f, 0, 0, 0);
       if (((float)TIMERA()) > 1.0f)
       {
           if ((IS_BUTTON_DOWN(0, 11) || IS_BUTTON_DOWN(0, 6)) || IS_BUTTON_DOWN(0, 4))
           {
               sub_a02();
               MoviePlayer_StopMovie();
               Graphics_SetMovieRenderingMode(0);
               PRINTSTRING("Skip Intro Movie\n");
           }
       }
   }
   PRINTSTRING("Ended Intro Movie\n");
   Graphics_SetMovieRenderingMode(0);
   var84 = 0;
   while (var84 < 4)
   {
       var60[var84] = AmbientMgr_AddRandomCarToLayout(0, &(var65[var84 * 3]), var78[var84]);
       var84 = var84 + 1;
   }
   City_SetHighLodEnable(1);
   WAITUNWARPED(10);
   City_SetCrossFadeEnabled(1);
   UILogic_SetIsGPSJumping(0);
   var84 = 0;
   while (var84 < 4)
   {
       AmbientMgr_RemoveAmbientFromLayout(var60[var84]);
       var84 = var84 + 1;
   }
   WAIT(0);
   WAIT(0);
   WAIT(0);
   while (!City_DoneStreaming(0x42c80000))
   {
       PRINTSTRING("Waiting for city\n");
       WAIT(10);
   }
   City_SetSnapLODFade();
   sub_bb7(0, 1, 0x3f800000, 0);
   mcMusicManager_PlayCustomMusic("MUSIC_CARSELECT_MASTER");
   var85 = 0;
   var86 = 0;
   var87 = 9;
   var94.v0 = var45.v0;
   var94.v1 = var45.v1;
   var94.v2 = var45.v2;
   var91.v0 = var48.v0;
   var91.v1 = var48.v1;
   var91.v2 = var48.v2;
   StringTable_SetString("VE_select_vehicle", StringTable_GetString(var7[var85]));
   var100 = UIManager_FindMovie("PROMPTMOVIE");
   if (var100 != null)
   {
       FlashHelper_SetGlobalInt(var100, "vehicle_select", 1);
   }
   var101 = 0.0f;
   var102 = 0.0f;
   var103 = 0;
   while (!var86)
   {
       if (!var103)
       {
           var103 = sub_fca();
           if (var103)
           {
           }
       }
       UILogic_SetPrompt(23 + var85);
       var88.v0 = var35[var85 * 3].v0;
       var88.v1 = var35[var85 * 3].v1;
       var88.v2 = var35[var85 * 3].v2;
       var97.v0 = var25[var85 * 3].v0;
       var97.v1 = var25[var85 * 3].v1;
       var97.v2 = var25[var85 * 3].v2;
       sub_1069(&var94, &var97, &var91, &var88, &var101, &var102);
       Game_SetCamera(&var94, &var91, 25.5f, 0, 0, 0);
       WAITUNWARPED(30);
       if ((IS_BUTTON_DOWN(0, 13) || IS_BUTTON_DOWN(0, 3)) || (GET_CONTROLLER_LEFTX(0) > 0.5f))
       {
           if (var87 != 13)
           {
               var85 = var85 + 1;
               AudioManager_PlayFrontendSound("UI_CAR_SELECT_NAV_MASTER");
               if (var85 >= 3)
               {
                   var85 = 0;
               }
               StringTable_SetString("VE_select_vehicle", StringTable_GetString(var7[var85]));
           }
           var87 = 13;
       }
       else if ((IS_BUTTON_DOWN(0, 15) || IS_BUTTON_DOWN(0, 2)) || (GET_CONTROLLER_LEFTX(0) < (-0.5f)))
       {
           if (var87 != 15)
           {
               var85 = var85 - 1;
               AudioManager_PlayFrontendSound("UI_CAR_SELECT_NAV_MASTER");
               if (var85 < 0)
               {
                   var85 = 2;
               }
               StringTable_SetString("VE_select_vehicle", StringTable_GetString(var7[var85]));
           }
           var87 = 15;
       }
       else if (IS_BUTTON_DOWN(0, 6))
       {
           var86 = 1;
           AudioManager_PlayFrontendSound("UI_CAR_SELECT_ENTER_MASTER");
       }
       else
       {
           var87 = 9;
       }
   }
   UILogic_SetPrompt(0);
   if (var100 != null)
   {
       FlashHelper_SetGlobalInt(var100, "vehicle_select", 0);
   }
   sub_463(1, 1, 0x3f800000, 0);
   var59 = 0;
   while (var59 < 3)
   {
       if (var59 != var85)
       {
           Racer_SetStreamingUnlocked(var55[var59]);
           Opponent_ToggleDeleteOnEviction(var51[var59], 1);
       }
       var59 = var59 + 1;
   }
   LocalOptions_AddVehicleToPlayer(var3[var85]);
   Racer_SetUID(var55[var85], 208);
   Graphics_GetAndSetAutoUpdateTimeOfDay(1);
   AmbientMgr_SetParkedCarsEnable(1);
   AmbientMgr_Reset();
   mcMusicManager_StopCustomMusic();
}

void sub_463(var0, var1, var2, var3)
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

void sub_a02()
{
   auto var2;

   var2 = 1.0f;
   while (var2 > 0.0f)
   {
       var2 = var2 - 0.1f;
       MoviePlayer_SetTintColor((float)1, (float)1, (float)1, var2);
       WAIT(30);
   }
   MoviePlayer_SetTintColor((float)1, (float)1, (float)1, (float)0);
}

void sub_bb7(var0, var1, var2, var3)
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

function sub_fca()
{
   START_NEW_SCRIPT("Game/Career/cut_story_race_gh_06_preload", 0);
   return 1;
}

void sub_1069(var0, var1, var2, var3, var4, var5)
{
   auto var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   var8 = VDIST(*var0.v0, *var0.v1, *var0.v2, *var1.v0, *var1.v1, *var1.v2);
   var9 = VDIST(*var2.v0, *var2.v1, *var2.v2, *var3.v0, *var3.v1, *var3.v2);
   if (var8 >= var9)
   {
       if (var8 > (*(var4) * 4.0f))
       {
           *var4 = *(var4) + 0.1f;
           if (*(var4) > 1.4f)
           {
               *var4 = 1.4f;
           }
       }
       else
       {
           *var4 = *(var4) * 0.7f;
           if (*(var4) > var8)
           {
               *var4 = var8;
           }
       }
       var10 = *(var4) * (var9 / var8);
       *var5 = ((var10 - *(var5)) * 1.0f) + *(var5);
       if (*(var5) > var9)
       {
           *var5 = var9;
       }
   }
   else
   {
       if (var9 > (*(var5) * 4.0f))
       {
           *var5 = *(var5) + 0.1f;
           if (*(var5) > 1.4f)
           {
               *var5 = 1.4f;
           }
       }
       else
       {
           *var5 = *(var5) * 0.7f;
           if (*(var5) > var9)
           {
               *var5 = var9;
           }
       }
       var10 = *(var5) * (var8 / var9);
       *var4 = ((var10 - *(var4)) * 1.0f) + *(var4);
       if (*(var4) > var8)
       {
           *var4 = var8;
       }
   }
   var11.v0 = *(var4) * (var8 / (*var0.v0 - *var1.v0));
   var11.v1 = *(var4) * (var8 / (*var0.v1 - *var1.v1));
   var11.v2 = *(var4) * (var8 / (*var0.v2 - *var1.v2));
   *var0.v0 = var11.v0 + *var0.v0;
   *var0.v1 = var11.v1 + *var0.v1;
   *var0.v2 = var11.v2 + *var0.v2;
   var11.v0 = *(var5) * (var9 / (*var2.v0 - *var3.v0));
   var11.v1 = *(var5) * (var9 / (*var2.v1 - *var3.v1));
   var11.v2 = *(var5) * (var9 / (*var2.v2 - *var3.v2));
   *var2.v0 = var11.v0 + *var2.v0;
   *var2.v1 = var11.v1 + *var2.v1;
   *var2.v2 = var11.v2 + *var2.v2;
}

