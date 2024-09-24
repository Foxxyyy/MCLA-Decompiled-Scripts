void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139;

   var2.v0 = L[0].v0;
   var3 = "CSCamera";
   var4 = 20;
   var25 = 20;
   PRINTSTRING("Start cutscene load\n");
   AmbientMgr_SetCutscene(1);
   var46 = 0;
   while (var46 < L[0].v4)
   {
       var47 = L[0].v5[var46 * 6].v5;
       if ((var47 < 0) || (!CineScript_Characters_GetSlotToUseUnscaledCharacter(var46)))
       {
           PRINTSTRING("Remapping the character ");
           PRINTSTRING(L[0].v5[var46 * 6].v1);
           var48 = 0;
           var4[var46] = CineScript_Characters_LookupDriverToCutscenePath(L[0].v5[var46 * 6].v1, var48);
           var25[var46] = CineScript_Characters_LookupDriverToCutsceneName(L[0].v5[var46 * 6].v1, var48);
           PRINTSTRING("to ");
           PRINTSTRING(var25[var46]);
           PRINTSTRING(var4[var46]);
           PRINTSTRING("\n");
       }
       else
       {
           PRINTSTRING("NOT remapping character\n");
       }
       if (StringCompare(var4[var46], "") || StringCompare(var25[var46], ""))
       {
           var4[var46] = L[0].v5[var46 * 6].v0;
           var25[var46] = L[0].v5[var46 * 6].v1;
       }
       var46 = var46 + 1;
   }
   if ((Weather_GetCurrentWeather() == 2) && (!StringCaseContains(CineScript_GetSceneName(), "racestart")))
   {
       Weather_SetCurrentWeather(1, 0);
   }
   var49 = Weather_GetAndSetAutoWeatherChange(0);
   var50 = Graphics_GetAndSetAutoUpdateTimeOfDay(0);
   var51 = 1;
   var52 = 1;
   var53 = 1;
   var54 = 0;
   var55 = CineScript_DoesCutsceneAnimPackExist();
   if (var55)
   {
       CineScript_StartLoadCutsceneAnimPack();
   }
   else
   {
       var46 = 0;
       while (var46 < L[0].v4)
       {
           var54 = CineScript_Characters_LoadAnimationWithFace(L[0].v5[var46 * 6].v2, L[0].v5[var46 * 6].v3, L[0].v5[var46 * 6].v4);
           var51 = var51 && var54;
           if (!var54)
           {
               PRINTSTRING("Trying to load ");
               PRINTSTRING(L[0].v5[var46 * 6].v3);
               PRINTSTRING("\n");
           }
           var46 = var46 + 1;
       }
       var46 = 0;
       while (var46 < L[0].v126)
       {
           if (L[0].v127[var46 * 5].v2 && (!L[0].v322))
           {
               var54 = CineScript_Cars_LoadMoverAnimation(L[0].v127[var46 * 5].v3, L[0].v127[var46 * 5].v4);
               var51 = var51 && var54;
           }
           if (!var54)
           {
               PRINTSTRING("Trying to load ");
               PRINTSTRING(L[0].v127[var46 * 5].v4);
               PRINTSTRING("\n");
           }
           var46 = var46 + 1;
       }
       var51 = var51 && CineScript_Camera_LoadAnimation(L[0].v1, var3);
   }
   if (!StringCompare(L[0].v2, ""))
   {
       var54 = CineScript_Audio_PrepareStream(L[0].v2);
       if (!var54)
       {
           PRINTSTRING("Failed to load audio stream ");
           PRINTSTRING(L[0].v2);
           L[0].v2 = "";
           PRINTNL();
       }
   }
   if (!var51)
   {
       PRINTSTRING("/\\/\\/\\/ SKIPPING CUTSCENE: Script '");
       PRINTSTRING(CineScript_GetSceneName());
       PRINTSTRING("_generated.sc' failed to load.  mis-sync between assets & cutscene script.\n");
       CineScript_SKIPPING_CUTSCENE();
   }
   var56 = 10;
   var117 = 10;
   var128 = 0;
   var129 = 0;
   var130 = 0;
   var131 = 0;
   SETTIMERA(0);
   SetExceptionMask(3);
   var132 = ;
   switch (var132)
   {
       case -1:
       {
           break;
       }
       case 1:
       {
           break;
       }
       case 2:
       {
           break;
       }
       case 3:
       {
           break;
       }
       default:
       {
           PRINTSTRING("Unhandled exception: ");
           PRINTINT(var132);
           PRINTSTRING("\n");
           while ((!var128) && var51)
           {
               var128 = 1;
               var52 = 1;
               var53 = 1;
               var130 = 0;
               if (var55)
               {
                   var54 = CineScript_IsLoadedCutsceneAnimPack();
                   var53 = var53 && var54;
                   var128 = var128 && var54;
                   if (!var54)
                   {
                       PRINTSTRING("Trying to load Cutscene animpack ");
                       PRINTSTRING("\n");
                   }
               }
               var46 = 0;
               while (var46 < L[0].v4)
               {
                   var54 = CineScript_Characters_LoadType(var4[var46], var25[var46]);
                   var53 = var53 && var54;
                   var128 = var128 && var54;
                   if (!var54)
                   {
                       PRINTSTRING("Trying to load ");
                       PRINTSTRING(var25[var46]);
                       PRINTSTRING("\n");
                   }
                   var46 = var46 + 1;
               }
               var46 = 0;
               while (var46 < L[0].v126)
               {
                   var54 = CineScript_Cars_RegisterRacer(L[0].v127[var46 * 5].v1, L[0].v127[var46 * 5].v0);
                   var53 = var53 && var54;
                   var128 = var128 && var54;
                   if (!var54)
                   {
                       PRINTSTRING("Trying to load ");
                       PRINTSTRING(L[0].v127[var46 * 5].v0);
                       PRINTSTRING("\n");
                   }
                   var46 = var46 + 1;
               }
               if (!StringCompare(L[0].v2, ""))
               {
                   var54 = CineScript_Audio_IsStreamPrepared();
                   var52 = var52 && var54;
                   var128 = var128 && (var54 || var129);
                   if (!var54)
                   {
                       PRINTSTRING("Trying to load audio\n");
                   }
               }
               if (CineScript_IsSpeechScenarioPending())
               {
                   var54 = CineScript_IsSpeechScenarioPrepared();
                   var52 = var52 && var54;
                   var128 = var128 && (var54 || var129);
                   if (!var54)
                   {
                       PRINTSTRING("CineScript_IsSpeechScenarioPrepared() is not done\n");
                   }
               }
               if (!StringCompare(L[0].v3, ""))
               {
                   var54 = CineScript_Prop_LoadSetDressing(L[0].v3, 1);
                   var53 = var53 && var54;
                   var128 = var128 && var54;
                   if (!var54)
                   {
                       PRINTSTRING("CineScript_Prop_LoadSetDressing() is not done\n");
                   }
               }
               if (CineScript_Prop_IsSetDressingLoading(L[0].v3))
               {
                   PRINTSTRING("CineScript_Prop_IsSetDressingLoading is true\n");
                   var128 = 0;
               }
               if (!mcRacerManager_AreStreamStatesResolved())
               {
                   var128 = 0;
                   PRINTSTRING("mcRacerManager_AreStreamStatesResolved() is not done\n");
               }
               if (var128)
               {
                   CineScript_SetSceneReadyForGame();
                   var46 = 0;
                   while (var46 < L[0].v126)
                   {
                       CineScript_Cars_GetCoordSysBinding(&(var56[var46 * 6]), L[0].v127[var46 * 5].v0);
                       var46 = var46 + 1;
                   }
                   var131 = 0;
                   if ((!L[0].v321) && (L[0].v4 >= 1))
                   {
                       if (L[0].v5[0 * 6].v5 >= 0)
                       {
                           CineScript_SetSceneCoordSysBinding(&(var56[0 * 6]));
                           var131 = 1;
                       }
                   }
                   if (!var131)
                   {
                       CineScript_GetGameCoordSysBinding(&var133);
                       CineScript_SetSceneCoordSysBinding(&var133);
                   }
                   var128 = CineScript_IsGameReadyForReplay();
                   if (!var128)
                   {
                       PRINTSTRING("[CUTSCENE:] Waiting on GPS transition to release replay interlock.\n");
                   }
               }
               if (var128)
               {
                   var130 = 1;
                   if (Race_HasCurrentRace())
                   {
                       Race_EnableRaceTimer(Race_GetCurrentRace(), 1);
                       Race_SetTimer(Race_GetCurrentRace(), -60000);
                   }
                   DebugReplay(1000);
                   var128 = CineScript_IsGameReadyForScene();
                   if (!var128)
                   {
                       PRINTSTRING("[CUTSCENE:] Waiting on GPS transition to release interlock.\n");
                   }
               }
               if (var128)
               {
                   DebugReplay(1100);
                   var46 = 0;
                   while (var46 < L[0].v126)
                   {
                       if (L[0].v127[var46 * 5].v2 && (!L[0].v322))
                       {
                           BrainFactory_CreateBrainAnimated(L[0].v127[var46 * 5].v1);
                       }
                       var46 = var46 + 1;
                   }
                   CineScript_BeginDescription();
                   var46 = 0;
                   while (var46 < L[0].v4)
                   {
                       var47 = L[0].v5[var46 * 6].v5;
                       if (var47 >= 0)
                       {
                           var139 = CineScript_Characters_LaunchAnimEventWithFaceLCS(var4[var46], var25[var46], L[0].v5[var46 * 6].v2, L[0].v5[var46 * 6].v3, L[0].v5[var46 * 6].v4, 0.0f, 1, &(var56[var47 * 6]));
                       }
                       else
                       {
                           var139 = CineScript_Characters_LaunchAnimEventWithFace(var4[var46], var25[var46], L[0].v5[var46 * 6].v2, L[0].v5[var46 * 6].v3, L[0].v5[var46 * 6].v4, 0.0f, 1);
                       }
                       CineScript_PushKillBuffer(var139, 1);
                       var46 = var46 + 1;
                   }
                   var46 = 0;
                   while (var46 < L[0].v126)
                   {
                       if (L[0].v127[var46 * 5].v2 && (!L[0].v322))
                       {
                           var117[var46] = !Racer_IsActive(L[0].v127[var46 * 5].v1);
                           if (var117[var46])
                           {
                               Racer_Activate(L[0].v127[var46 * 5].v1);
                           }
                           var139 = CineScript_Cars_LaunchEvent(L[0].v127[var46 * 5].v0, L[0].v127[var46 * 5].v3, L[0].v127[var46 * 5].v4, 0.0f);
                       }
                       else
                       {
                           var139 = CineScript_Cars_LaunchGameDriven(L[0].v127[var46 * 5].v0);
                       }
                       CineScript_PushKillBuffer(var139, 1);
                       var46 = var46 + 1;
                   }
                   var46 = 0;
                   while (var46 < L[0].v178)
                   {
                       if (L[0].v179[var46 * 7].v1 == 1)
                       {
                           CineScript_Events_LaunchEventOnRacerName(L[0].v179[var46 * 7].v0, L[0].v179[var46 * 7].v2, L[0].v179[var46 * 7].v4, L[0].v179[var46 * 7].v5, L[0].v179[var46 * 7].v6);
                       }
                       else if (L[0].v179[var46 * 7].v1 == 2)
                       {
                           CineScript_Events_LaunchEventOnRacerSlot(L[0].v179[var46 * 7].v0, L[0].v179[var46 * 7].v3, L[0].v179[var46 * 7].v4, L[0].v179[var46 * 7].v5, L[0].v179[var46 * 7].v6);
                       }
                       else
                       {
                           CineScript_Events_LaunchEvent(L[0].v179[var46 * 7].v0, L[0].v179[var46 * 7].v4, L[0].v179[var46 * 7].v5, L[0].v179[var46 * 7].v6);
                       }
                       var46 = var46 + 1;
                   }
                   CineScript_Camera_LaunchEvent(L[0].v1, var3, 0.0f);
                   if (L[0].v323)
                   {
                       CineScript_Camera_BypassCutsceneCameraToGameCamera();
                   }
                   CineScript_EndDescriptionAndStartClock();
                   if (var52 && (!StringCompare(L[0].v2, "")))
                   {
                       CineScript_Audio_PlayStream();
                   }
                   WAITUNWARPED(10);
                   if (Race_HasCurrentRace() && (CineScript_GetTimeToRacestart() >= ((float)0)))
                   {
                       Race_SetTimerSeconds(Race_GetCurrentRace(), -CineScript_GetTimeToRacestart());
                   }
                   sub_101f(0, 1, 0x3f800000, 0);
               }
               if (!var128)
               {
                   WAITUNWARPED(10);
                   if ((TIMERA() > 10000) && (!Game_IsPaused()))
                   {
                       PRINTSTRING("[CORE_ROLLING_PROTOTYPE] The cutscene load has exceeded 10 seconds, at ");
                       PRINTFLOAT(TO_FLOAT(TIMERA()));
                       PRINTSTRING(" seconds.");
                   }
                   if (TIMERA() > 30000)
                   {
                       if (Game_IsPaused())
                       {
                           SETTIMERA(0);
                       }
                       else if (!var130)
                       {
                           if (!var52)
                           {
                               CineScript_Audio_StopStreamPrimary();
                               CineScript_Audio_StopStreamPrimary();
                               PRINTSTRING("Cutscene audio timed out.  Stopping audio");
                               PRINTSTRING("/\\/\\/\\/ SKIPPING CUTSCENE AUDIO.");
                               var129 = 1;
                           }
                           if (!var53)
                           {
                               var51 = 0;
                               PRINTSTRING("/\\/\\/\\/ SKIPPING CUTSCENE: Script '");
                               PRINTSTRING(CineScript_GetSceneName());
                               PRINTSTRING("_generated.sc' waited 10 seconds to load.  trouble streaming in entity.\n");
                               CineScript_SKIPPING_CUTSCENE();
                               sub_101f(1, 1, 0x3f800000, 0);
                           }
                       }
                   }
               }
           }
           while (CineScript_IsScenePlaying() && var51)
           {
               if (L[0].v320)
               {
                   if (CineScript_Camera_GetTimeRemaining() < 0.8f)
                   {
                       sub_158c(1, 1, 0x3f800000, 0);
                   }
               }
               WAITUNWARPED(10);
           }
           break;
       }
   }
   AmbientMgr_SetCutscene(0);
   Weather_GetAndSetAutoWeatherChange(var49);
   Graphics_GetAndSetAutoUpdateTimeOfDay(var50);
   CineScript_Camera_Kill();
   CineScript_PopKillBuffer(1);
   CineScript_FinishScene();
   sub_1908(var2);
   var46 = 0;
   while (var46 < L[0].v126)
   {
       if (L[0].v127[var46 * 5].v2 && (!L[0].v322))
       {
           BrainFactory_DeleteBrain(L[0].v127[var46 * 5].v1);
       }
       if (var117[var46])
       {
           Racer_Deactivate(L[0].v127[var46 * 5].v1);
       }
       var46 = var46 + 1;
   }
}

void sub_101f(var0, var1, var2, var3)
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

void sub_158c(var0, var1, var2, var3)
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

void sub_1908(var0)
{
   auto var3;

   var0.v0 = 3;
}

