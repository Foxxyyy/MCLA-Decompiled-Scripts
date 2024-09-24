void main()
{
   auto var2, var3, var4, var5, var6, var7;

   var2 = Graphics_GetAndSetAutoUpdateTimeOfDay(0);
   var3 = -1;
   if (GetDemoCommandLine())
   {
       var3 = 0;
   }
   else
   {
       var3 = sub_2a();
   }
   SetPlayerPadIndex(0, var3);
   PRINTSTRING("Startpad ");
   PRINTINT(var3);
   PRINTSTRING("\n");
   sub_9fd();
   MoviePlayer_StopMovie();
   Game_FadeLoadscreenLogo(1);
   Game_LoadScreenShutdown();
   Graphics_SetMovieRenderingMode(0);
   Graphics_GetAndSetAutoUpdateTimeOfDay(var2);
   AmbientMgr_SetFrontEnd(0, (float)0, (float)0, (float)0, (float)0, 0);
   Warper_SetUseCinematicWarp(0);
   Warper_SetPauseCameraAtEndOfWarp();
   Warper_Warp("MAXHEIGHT");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(10);
       PRINTSTRING("Waiting for gps transition to finish\n");
   }
   CityDescription_GetDefaultStartPosition(LookupCity(GetCurrentCity()), &var4, &var7);
   UILogic_LockStreamingPosHeading(&var4, var7);
   mcEvent_PostEventStr("EVENT_START_SCREEN_EXIT", "");
}

function sub_2a()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143, var144, var145, var146, var147, var148, var149, var150, var151, var152;

   var2 = -1;
   var3 = -1;
   var4 = -1;
   var5 = 0;
   var6 = 7;
   var28 = 7;
   var50 = 7;
   var58 = 7;
   var66 = 7;
   var74 = 7;
   var82 = 7;
   var90 = 7;
   var98 = 7;
   var106 = 7;
   var114 = 7;
   var122 = 7;
   var130 = 7;
   var138 = 7;
   var6[0 * 3].v0 = 2903.0f;
   var6[0 * 3].v1 = 83.0f;
   var6[0 * 3].v2 = 22.6f;
   var28[0 * 3].v0 = -0.993f;
   var28[0 * 3].v1 = -0.106f;
   var28[0 * 3].v2 = 0.044f;
   var50[0] = 39.2f;
   var58[0] = 5.776f;
   var66[0] = 1;
   var74[0] = (float)2000;
   var82[0] = (float)3000;
   var106[0] = 0.06f;
   var114[0] = (float)0;
   var122[0] = 0.1f;
   var130[0] = (float)425;
   var138[0] = 4;
   var6[1 * 3].v0 = -2932.9f;
   var6[1 * 3].v1 = -14.3f;
   var6[1 * 3].v2 = 368.4f;
   var28[1 * 3].v0 = -0.854f;
   var28[1 * 3].v1 = 0.165f;
   var28[1 * 3].v2 = 0.494f;
   var50[1] = 40.4f;
   var58[1] = 17.819f;
   var106[1] = (float)0;
   var114[1] = (float)0;
   var122[1] = 0.1f;
   var130[1] = (float)200;
   var138[1] = 4;
   var6[2 * 3].v0 = -339.0f;
   var6[2 * 3].v1 = 44.1f;
   var6[2 * 3].v2 = -753.2f;
   var28[2 * 3].v0 = 0.963f;
   var28[2 * 3].v1 = -0.15f;
   var28[2 * 3].v2 = 0.225f;
   var50[2] = 34.8f;
   var58[2] = 6.498f;
   var106[2] = (float)0;
   var114[2] = 0.05f;
   var122[2] = 0.1f;
   var130[2] = (float)162;
   var138[2] = 4;
   var6[3 * 3].v0 = 2531.0f;
   var6[3 * 3].v1 = 9.0f;
   var6[3 * 3].v2 = 141.8f;
   var28[3 * 3].v0 = -0.996f;
   var28[3 * 3].v1 = 0.088f;
   var28[3 * 3].v2 = 0.01f;
   var50[3] = 41.0f;
   var58[3] = 16.752f;
   var74[3] = (float)800;
   var82[3] = (float)3000;
   var90[3] = (float)100;
   var98[3] = (float)1500;
   var106[3] = (float)0;
   var114[3] = 0.165f;
   var122[3] = 0.1f;
   var130[3] = (float)131;
   var138[3] = 5;
   var6[4 * 3].v0 = 864.9f;
   var6[4 * 3].v1 = 39.8f;
   var6[4 * 3].v2 = -1415.1f;
   var28[4 * 3].v0 = 0.633f;
   var28[4 * 3].v1 = 0.135f;
   var28[4 * 3].v2 = -0.762f;
   var50[4] = 32.9f;
   var58[4] = 14.81f;
   var74[4] = (float)800;
   var82[4] = (float)3000;
   var90[4] = (float)100;
   var98[4] = (float)1500;
   var106[4] = 0.0f;
   var114[4] = 0.037f;
   var122[4] = 0.1f;
   var130[4] = (float)265;
   var138[4] = 4;
   var6[5 * 3].v0 = -2603.6f;
   var6[5 * 3].v1 = 2.8f;
   var6[5 * 3].v2 = 239.3f;
   var28[5 * 3].v0 = -0.371f;
   var28[5 * 3].v1 = -0.004f;
   var28[5 * 3].v2 = -0.929f;
   var50[5] = 33.3f;
   var58[5] = 10.4f;
   var74[5] = (float)900;
   var82[5] = (float)3000;
   var106[5] = (float)0;
   var114[5] = (float)0;
   var122[5] = 0.1f;
   var130[5] = (float)226;
   var138[5] = 4;
   var6[6 * 3].v0 = 939.2f;
   var6[6 * 3].v1 = 59.6f;
   var6[6 * 3].v2 = 739.7f;
   var28[6 * 3].v0 = 0.508f;
   var28[6 * 3].v1 = -0.21f;
   var28[6 * 3].v2 = -0.835f;
   var50[6] = 50.5f;
   var58[6] = 18.0f;
   var66[6] = 1;
   var74[6] = (float)3500;
   var82[6] = (float)4000;
   var106[6] = 0.055f;
   var114[6] = (float)0;
   var122[6] = 0.1f;
   var130[6] = (float)270;
   var138[6] = 4;
   RAND_RESET();
   RAND_RESET();
   var146 = RAND_INT_RANGE(0, 6);
   UILogic_SetPrompt(0);
   AmbientMgr_SetFrontEnd(1, var106[var146], var114[var146], var122[var146], var130[var146], var138[var146]);
   sub_5a8(var6[var146 * 3].v0, var6[var146 * 3].v1, var6[var146 * 3].v2, var28[var146 * 3].v0, var28[var146 * 3].v1, var28[var146 * 3].v2, var50[var146], var58[var146], var66[var146], var74[var146], var82[var146], var90[var146], var98[var146], 1);
   var147 = Net_GetAchievementSetupStatus();
   if (var147 == 4)
   {
       UIManager_TransitionTo("AchievementDataCorrupt");
   }
   else if (var147 == 5)
   {
       UIManager_TransitionTo("AchievementRequiresUpdate");
   }
   else if (var147 == 2)
   {
       UIManager_TransitionTo("AchievementInitFailed");
   }
   var148 = UILogic_IsShowingDialog();
   if (!var148)
   {
       UILogic_SetPrompt(27);
   }
   SETTIMERA(0);
   var149 = 0;
   var150 = 0;
   if (var5)
   {
       MoviePlayer_StopMovie();
       var149 = MoviePlayer_StartMovie("game:/attract", 0);
       if (var149)
       {
           AudioManager_StopLoadingMusic();
       }
   }
   else
   {
       MoviePlayer_StopMovie();
       var149 = 0;
   }
   while (var2 == -1)
   {
       var148 = UILogic_IsShowingDialog();
       if (var148)
       {
           Game_FadeLoadscreenLogo(1);
           var151 = 0;
           while (var151 < 4)
           {
               if (IS_PAD_BUTTON_DOWN(var151, 6))
               {
                   UILogic_FireButtonPressedEvent(52);
                   UILogic_SetPrompt(27);
               }
               var151 = var151 + 1;
           }
       }
       else
       {
           Game_FadeLoadscreenLogo(var149);
           var151 = 0;
           while (var151 < 4)
           {
               if (IS_PAD_BUTTON_DOWN(var151, 11))
               {
                   var2 = var151;
                   AudioManager_PlayFrontendSound("UI_MENU_SELECT");
               }
               if (IS_PAD_BUTTON_DOWN(var151, 6))
               {
                   var4 = var151;
               }
               var151 = var151 + 1;
           }
       }
       if (var2 == -1)
       {
           var2 = Net_GetJoinWishPad();
       }
       var152 = 0;
       if ((var2 == -1) && (UIManager_GetRebootReason(&var152) == 4))
       {
           var2 = var152;
           PRINTSTRING("Rebooted for Content controller=");
           PRINTINT(var2);
           PRINTSTRING("\n");
       }
       if (!var149)
       {
           if (var3 == var2)
           {
               var2 = -1;
           }
           else
           {
               var3 = -1;
           }
           if (var148 && (!var150))
           {
               sub_9fd();
               var150 = 1;
           }
           else if ((!var148) && var150)
           {
               sub_a75();
               var150 = 0;
           }
           if ((TIMERA() > 110000) && (!var148))
           {
               sub_af8(1, 1, 0x3f800000, 0);
               sub_9fd();
               MoviePlayer_StopMovie();
               WAIT(0);
               WAIT(0);
               WAIT(0);
               var149 = MoviePlayer_StartMovie("game:/attract", 0);
               if (var149)
               {
                   AudioManager_StopLoadingMusic();
                   Graphics_SetMovieRenderingMode(1);
                   WAIT(0);
               }
               SETTIMERA(0);
           }
           else
           {
               UILogic_SetPrompt(27);
           }
       }
       else
       {
           UILogic_SetPrompt(0);
           if (!MoviePlayer_IsMoviePlaying())
           {
               MoviePlayer_StopMovie();
               var149 = 0;
               WAIT(0);
               WAIT(0);
               WAIT(0);
               Graphics_SetMovieRenderingMode(0);
               var146 = var146 + 1;
               if (var146 >= 7)
               {
                   var146 = 0;
               }
               AmbientMgr_SetFrontEnd(1, var106[var146], var114[var146], var122[var146], var130[var146], var138[var146]);
               sub_5a8(var6[var146 * 3].v0, var6[var146 * 3].v1, var6[var146 * 3].v2, var28[var146 * 3].v0, var28[var146 * 3].v1, var28[var146 * 3].v2, var50[var146], var58[var146], var66[var146], var74[var146], var82[var146], var90[var146], var98[var146], 0);
               sub_fc4(1, 1, 0x3f800000, 0);
               UILogic_SetPrompt(27);
               if (var148)
               {
                   var150 = 1;
               }
               else
               {
                   sub_a75();
               }
               SETTIMERA(0);
               AudioManager_StartLoadingMusic();
           }
           else if ((var2 != -1) || (var4 != -1))
           {
               Graphics_SetMovieRenderingMode(0);
               sub_9fd();
               MoviePlayer_StopMovie();
               WAIT(0);
               WAIT(0);
               WAIT(0);
               sub_fc4(1, 1, 0x3f800000, 0);
               sub_a75();
               var149 = 0;
               if (var2 != -1)
               {
                   if (IS_PAD_BUTTON_DOWN(var2, 11))
                   {
                       var3 = var2;
                   }
               }
               var2 = -1;
               UILogic_SetPrompt(27);
               AudioManager_StartLoadingMusic();
               SETTIMERA(0);
           }
       }
       var4 = -1;
       WAIT(20);
   }
   UILogic_SetPrompt(0);
   MoviePlayer_StopMovie();
   sub_a75();
   return var2;
}

void sub_5a8(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13)
{
   auto var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32;

   Graphics_WarpToTimeOfDay(var7, 100.0f);
   Weather_SetCurrentWeather(var8, 1);
   if (var9 > 0.1f)
   {
       PostProcessing_SetCutsceneDofNear(var9);
   }
   if (var10 > 0.1f)
   {
       PostProcessing_SetCutsceneDofFar(var10);
       PostProcessing_SetCutsceneDof();
   }
   else
   {
       PostProcessing_SetGameDof();
   }
   if (var11 > 0.1f)
   {
   }
   if (var12 > 0.1f)
   {
   }
   var16.v0 = var3.v0 + var0.v0;
   var16.v1 = var3.v1 + var0.v1;
   var16.v2 = var3.v2 + var0.v2;
   sub_63d(var0.v0, var0.v1, var0.v2, var16.v0, var16.v1, var16.v2, var6);
   if (var13)
   {
       sub_6d4(var0.v0, var0.v1, var0.v2, var16.v0, var16.v1, var16.v2, var6);
   }
   Game_SetCamera(&var0, &var16, var6, 0, 5.0f, 10000.0f);
}

void sub_63d(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15;

   Game_SetCamera(&var0, &var3, var6, 0, 5.0f, 10000.0f);
   WAIT(0);
   WAIT(0);
   WAIT(0);
   PRINTSTRING("About to wait for city\n");
   while (!City_DoneStreaming((float)250))
   {
       WAIT(10);
   }
   City_SetSnapLODFade();
}

void sub_6d4(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15;

   Game_SetCamera(&var0, &var3, var6, 0, 5.0f, 10000.0f);
   Game_SetLoadingDone();
   while (!Game_GetLoadingDone())
   {
       WAIT(10);
   }
   if (UILogic_IsShowingDialog())
   {
       Game_FadeLoadscreenLogo(1);
   }
}

void sub_9fd()
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

void sub_a75()
{
   auto var2;

   var2 = 0.0f;
   while (var2 < 1.0f)
   {
       var2 = var2 + 0.1f;
       MoviePlayer_SetTintColor((float)1, (float)1, (float)1, var2);
       WAIT(30);
   }
   MoviePlayer_SetTintColor((float)1, (float)1, (float)1, (float)1);
}

void sub_af8(var0, var1, var2, var3)
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

void sub_fc4(var0, var1, var2, var3)
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

