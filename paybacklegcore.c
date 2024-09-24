void main()
{
   auto var2, var3, var4;

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
   var2 = HUD_GetHUDCtrl(10);
   PropertyCtrl_SetPropertyInt(var2, 5, 1);
   Ctrl_SetVisible(var2, 1);
   var3 = LookupCity(GetCurrentCity());
   var4 = CityDescription_LookupRaceByIndex(var3, L[37].v4.v0);
   L[37].v4.v1[0 * 48].v8 = 0x7fffffff;
   CheckpointManager_ClearActiveCheckpointList();
   sub_353(&L[37], var4, var2);
   CheckpointManager_ClearActiveCheckpointList();
   mcHudMapServer_RemoveElement(L[37].v4.v1[1 * 48].v4);
   Racer_HideIcon(L[37].v4.v1[1 * 48].v0, 1);
   PropertyCtrl_SetPropertyInt(var2, 5, 0);
   UILogic_RemoveGPSDestination(0);
   Ctrl_SetVisible(var2, 0);
}

void sub_353(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49;

   PRINTSTRING("PAYBACK: RUN\n");
   var5 = 12.0f;
   var6 = (float)0;
   var7 = 0.0f;
   var8 = 0.0f;
   var9 = 0.0f;
   var10 = 0;
   var12 = UIManager_GetState("Payback_RESULTS");
   var13 = 0;
   var14 = 0.0f;
   var18 = 0;
   var19 = 0;
   var20 = (float)0;
   var21 = RaceDescription_GetTargetTime(var1, *((var0 + 16) + 3100));
   var22 = 0;
   var23 = LookupCity(GetCurrentCity());
   var24 = CityDescription_GetRaceNameByIndex(var23, *((var0 + 16) + 0));
   var41 = 0;
   sub_414(var0);
   WAITUNWARPED(1000);
   while (Warper_IsWarping())
   {
       WAITUNWARPED(100);
   }
   Registry_GetValueInt("Script_PayBackSuccess", &var41);
   if (var41 == 1)
   {
       while (SpeechSystem_IsInUse())
       {
           WAITUNWARPED(100);
       }
       Sidekick_Delay(0);
       var42 = Sidekick_AppendData(0, "SIDEKICK_PAYBACK_NEXT", 1, 0, 5.0f, L[31], "Incoming Call!", "SIDEKICK_PAYBACK_NEXT", "", 1, 0, "SIDEKICK_PAYBACK_NEXT", "KAROL", "PLAYER");
       while (!Sidekick_HasDataBeenAnnounced(var42))
       {
           WAITUNWARPED(100);
       }
       Sidekick_Delay(1);
   }
   while (!Race_IsFinished(*(var0 + 12)))
   {
       if (var13 == 0)
       {
           Racer_GetPosition((*((var0 + 16) + 4))[1 * 48].v0, &var15);
           UILogic_SetGPSDestination(0, &var15);
           if (Racer_DistanceBetween((*((var0 + 16) + 4))[0 * 48].v0, (*((var0 + 16) + 4))[1 * 48].v0) < ((float)50))
           {
               PRINTSTRING("Payback: CHASE ACTIVATED!\n");
               Racer_SetDamageInflictedFactor((*((var0 + 16) + 4))[0 * 48].v0, 3.0f);
               Racer_SetDamageMultiplierFlag((*((var0 + 16) + 4))[0 * 48].v0, 32);
               mcHudMapServer_SetMutExSubtype((*((var0 + 16) + 4))[1 * 48].v4, 6);
               mcHudMapServer_SetSelected((*((var0 + 16) + 4))[1 * 48].v4, 0);
               CheckpointManager_SetActiveCheckpointList(Race_GetCheckpointList(*(var0 + 12)));
               Registry_SetValueInt("Script_DoNotAddBarrier", 0);
               PropertyCtrl_SetPropertyInt(var2, 5, 1);
               SplashManager_Splash(0, 4, "PB_GetHim", 0x40000000, 1, 0);
               var13 = 1;
               sub_986(var0, var21);
           }
       }
       else if (var13 == 1)
       {
           Racer_GetPosition((*((var0 + 16) + 4))[1 * 48].v0, &var15);
           UILogic_SetGPSDestination(0, &var15);
           var6 = Racer_GetDamageValue((*((var0 + 16) + 4))[1 * 48].v0);
           var8 = Racer_GetMaxDamageValue((*((var0 + 16) + 4))[1 * 48].v0);
           if (*((var0 + 16) + 3100) == 0)
           {
               var9 = GetOpponentDamageCommandLine() * 0.5f;
           }
           else if (*((var0 + 16) + 3100) == 1)
           {
               var9 = GetOpponentDamageCommandLine() * 0.75f;
           }
           else if (*((var0 + 16) + 3100) == 2)
           {
               var9 = GetOpponentDamageCommandLine() * 0.87f;
           }
           else if (*((var0 + 16) + 3100) == 3)
           {
               var9 = GetOpponentDamageCommandLine() * 1.0f;
           }
           var6 = (100.0f * var6) / var8;
           var19 = Race_GetTimer(*(var0 + 12));
           if ((!*((var0 + 16) + 3128)) && (var19 > Race_GetTargetTime(*(var0 + 12))))
           {
               PRINTSTRING("Payback: TIMER UP!\n");
               PropertyCtrl_SetPropertyInt(var2, 5, 2);
               SplashManager_Splash(0, 4, "PB_Failed", 0x40000000, 1, 0);
               mcHudMapServer_RemoveElement((*((var0 + 16) + 4))[1 * 48].v4);
               Racer_HideIcon((*((var0 + 16) + 4))[1 * 48].v0, 1);
               UILogic_RemoveGPSDestination(0);
               WAITUNWARPED(1000);
               var13 = 2;
               sub_e1e(var0);
           }
           else if (var6 >= var9)
           {
               PRINTSTRING("Payback: AI CAR DESTROYED!\n");
               Registry_SetValueInt("Script_PayBackSuccess", 1);
               var43 = mcExperienceManager_CalculateRaceMoney(0, *((var0 + 16) + 3100), 20);
               PRINTSTRING("Payback Race Money: ");
               PRINTFLOAT(var43);
               var18 = vhsmState_GetDataInt(var12, "nPaybackCurrentWins");
               if (var18 == 0)
               {
                   var20 = 0.1f;
               }
               else if (var18 == 1)
               {
                   var20 = 0.15f;
               }
               else if (var18 == 2)
               {
                   var20 = 0.2f;
               }
               else if (var18 == 3)
               {
                   var20 = 0.25f;
               }
               else if (var18 == 4)
               {
                   var20 = 0.3f;
               }
               var44 = ROUND(var20 * var43);
               PRINTSTRING("Money Awarded for this lap: ");
               PRINTINT(var44);
               StatsManager_UpdateStatInt("kPDS", 0, 0, 1);
               AudioManager_PlayFrontendSound("PAYBACK_SUCCESS_MASTER");
               SplashManager_SplashDynamicInt(0, 4, "PB_Amount", "PB_Payment", var44, 0x40000000, 0);
               WAIT(1000);
               mcExperienceManager_AddMoney(var44);
               (*((var0 + 16) + 4))[0 * 48].v8 = 1;
               mcEvent_PostEventRaceResults("PAYBACK_LEG_COMPLETE", var0 + 16);
               Race_Finish(*(var0 + 12));
           }
       }
       else
       {
           var45 = PoliceManager_GetTacticResult();
           if ((PoliceManager_CheckPoliceActivity(0) == 3) && (var10 < Race_GetTimer(*(var0 + 12))))
           {
               var11 = L[13];
               if (RAND_INT_RANGE(0, 1) == 1)
               {
                   var11 = L[7];
               }
               var10 = RAND_INT_RANGE(15000 + Race_GetTimer(*(var0 + 12)), 30000 + Race_GetTimer(*(var0 + 12)));
               mcCareerSpeech_PlayNamedScenario("TAUNT_GOON_SEARCH", var11, L[0]);
               PRINTSTRING("Goons are Searching for you");
               WAITUNWARPED(1000);
           }
           if (var45 == 2)
           {
               PRINTSTRING("Payback: CARS AVOIDED!\n");
               SplashManager_Splash(0, 4, "PB_Lost", 0x40000000, 1, 0);
               var11 = L[13];
               if (RAND_INT_RANGE(0, 1) == 1)
               {
                   var11 = L[7];
               }
               while (SpeechSystem_IsInUse())
               {
                   WAITUNWARPED(100);
               }
               mcCareerSpeech_PlayNamedScenario("TAUNT_GOON_END", var11, L[0]);
               PRINTSTRING("Goons have given up and can't find you");
               Race_Finish(*(var0 + 12));
               Registry_SetValueInt("Script_PayBackSuccess", 1);
           }
           else if (var45 == 1)
           {
               PRINTSTRING("Payback: CAUGHT!\n");
               SplashManager_Splash(0, 4, "PB_Caught", 0x40000000, 1, 0);
               WAITUNWARPED(2000);
               Registry_SetValueInt("nPlayerCaught", 1);
               var46 = 0;
               while (!var46)
               {
                   var46 = CineScript_IsScenePlaying();
                   WAITUNWARPED(100);
               }
               while (var46)
               {
                   var46 = CineScript_IsScenePlaying();
                   WAITUNWARPED(100);
               }
               Race_Finish(*(var0 + 12));
           }
       }
       if (Race_IsDamagedOut(*(var0 + 12)))
       {
           PRINTSTRING("Player has damaged out");
           while (!Race_IsFinished(*(var0 + 12)))
           {
               PRINTSTRING("NOT Race_IsFinished");
               if (var6 != ((float)0))
               {
                   WAITUNWARPED(100);
               }
               WAITUNWARPED(100);
           }
           while (CineScript_IsScenePlaying())
           {
               WAITUNWARPED(100);
           }
           Registry_SetValueInt("Shutdown_PaybackOpponents", 1);
           Registry_SetValueInt("nPlayerCaught", 1);
           PRINTSTRING("Race_IsFinished");
           Race_Finish(*(var0 + 12));
           while (!PoliceManager_IsAllStreamedOut())
           {
               WAITUNWARPED(100);
           }
           sub_15e4(1, 1, 0x3f800000, 0);
       }
       Registry_GetValueInt("raceOverTrigger", &var22);
       if (!(var22 == 0))
       {
           Race_Finish(*(var0 + 12));
       }
       WAITUNWARPED(30);
   }
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   Registry_SetValueInt("Shutdown_PaybackOpponents", 1);
}

void sub_414(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13;

   var3 = HUD_GetHUDCtrl(6);
   Ctrl_SetVisible(var3, 0);
   Registry_SetValueInt("Shutdown_PaybackOpponents", 1);
   Race_EnableRaceTimer(*(var0 + 12), 0);
   Racer_Deactivate((*((var0 + 16) + 4))[1 * 48].v0);
   BrainFactory_DeleteBrain((*((var0 + 16) + 4))[1 * 48].v0);
   BrainFactory_DeleteBrain((*((var0 + 16) + 4))[2 * 48].v0);
   Racer_HideIcon((*((var0 + 16) + 4))[2 * 48].v0, 1);
   var4 = BrainFactory_CreateBrainCruising((*((var0 + 16) + 4))[1 * 48].v0);
   var5 = Race_GetCheckpointList(*(var0 + 12));
   var6 = CheckpointList_GetListCount(var5);
   PRINTSTRING("NUMBER OF CHECKPOINTS ");
   PRINTINT(var6);
   PRINTSTRING("\n");
   var10 = CheckpointList_GetCheckpoint(var5, 0);
   Checkpoint_GetPosition(var10, &var7);
   Racer_InitializeResetPosition((*((var0 + 16) + 4))[1 * 48].v0, &var7, 0.0f);
   Racer_Reset((*((var0 + 16) + 4))[1 * 48].v0);
   Registry_GetValueInt("revertDamage", &var11);
   if (var11 == 1)
   {
       UILogic_RevertCarDamage();
       Registry_SetValueInt("revertDamage", 0);
   }
   var12 = 0;
   var12 = 0;
   while (var12 < var6)
   {
       var10 = CheckpointList_GetCheckpoint(var5, var12);
       Checkpoint_GetPosition(var10, &var7);
       PRINTSTRING("Cruise Checkpoint ");
       PRINTINT(var12);
       PRINTSTRING(" - Position: ");
       PRINTVECTOR(var7.v0, var7.v1, var7.v2);
       PRINTSTRING("\n");
       BrainCruising_AppendDest(var4, &var7);
       var12 = var12 + 1;
   }
   BrainCruising_SetLooping(var4, 1);
   BrainCruising_TeleportToNearestRail(var4);
   Racer_Activate((*((var0 + 16) + 4))[1 * 48].v0);
   mcHudMapServer_AddElement((*((var0 + 16) + 4))[1 * 48].v4);
   mcHudMapServer_SetSelected((*((var0 + 16) + 4))[1 * 48].v4, 1);
   mcHudMapServer_SetMutExSubtype((*((var0 + 16) + 4))[1 * 48].v4, 8);
   Racer_SetFatalBlow((*((var0 + 16) + 4))[1 * 48].v0, Racer_GetImpactThreshold((*((var0 + 16) + 4))[1 * 48].v0));
   Racer_SetIconType((*((var0 + 16) + 4))[1 * 48].v0, 10);
   Racer_HideIcon((*((var0 + 16) + 4))[1 * 48].v0, 0);
   Race_SetRaceData(*(var0 + 12), var0 + 16);
}

void sub_986(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   PRINTSTRING("PAYBACK: START CHASE AI\n");
   Registry_SetValueInt("nPaybackState", 1);
   Racer_Deactivate((*((var0 + 16) + 4))[1 * 48].v0);
   var4 = BrainCruising_GetCurrentDestinationIndex(BrainFactory_GetBrainCruising((*((var0 + 16) + 4))[1 * 48].v0));
   BrainFactory_DeleteBrain((*((var0 + 16) + 4))[1 * 48].v0);
   Registry_SetValueInt("Shutdown_PaybackOpponents", 1);
   var5 = BrainFactory_CreateBrainRacing((*((var0 + 16) + 4))[1 * 48].v0);
   Racer_SetDamageInflictedFactor((*((var0 + 16) + 4))[1 * 48].v0, 0.55f);
   BrainRacing_SetAllowNitro(var5, 0);
   var6 = Race_GetCheckpointList(*(var0 + 12));
   var7 = CheckpointList_GetListCount(var6);
   PRINTSTRING("NUMBER OF CHECKPOINTS ");
   PRINTINT(var7);
   PRINTSTRING("\n");
   var12 = null;
   var11 = 0;
   while (var11 <= (var7 - 1))
   {
       if (var4 == var7)
       {
           var4 = 0;
       }
       var12 = CheckpointList_GetCheckpoint(var6, var4);
       Checkpoint_GetPosition(var12, &var8);
       PRINTSTRING("Race Checkpoint ");
       PRINTINT(var4);
       PRINTSTRING(" - Position: ");
       PRINTVECTOR(var8.v0, var8.v1, var8.v2);
       PRINTSTRING("\n");
       BrainRacing_AppendGoal(var5, &var8, 25.0f);
       var4 = var4 + 1;
       var11 = var11 + 1;
   }
   BrainRacing_SetLooping(var5, 1);
   BrainRacing_SetMaxSpeed(var5, 32.0f);
   Racer_Activate((*((var0 + 16) + 4))[1 * 48].v0);
   var13 = UIManager_FindMovie("HUDMOVIE");
   sub_bb2(var13);
   if (!*((var0 + 16) + 3128))
   {
       var14 = HUD_GetHUDCtrl(6);
       PropertyCtrl_SetPropertyBool(var14, 0, 1);
       Race_SetTargetTime(*(var0 + 12), var1);
       Race_SetTimer(*(var0 + 12), 0);
       Race_EnableRaceTimer(*(var0 + 12), 1);
       Ctrl_SetVisible(var14, 1);
   }
   Racer_SetIconType((*((var0 + 16) + 4))[1 * 48].v0, 18);
   Racer_HideIcon((*((var0 + 16) + 4))[1 * 48].v0, 0);
}

void sub_bb2(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 2);
}

void sub_e1e(var0)
{
   auto var3, var4, var5, var6;

   var3 = HUD_GetHUDCtrl(6);
   Ctrl_SetVisible(var3, 0);
   Race_SetTimer(*(var0 + 12), 0);
   Race_EnableRaceTimer(*(var0 + 12), 1);
   var4 = Sidekick_AppendData(0, "SIDEKICK_PAYBACK_WARNING", 1, 0, 5.0f, L[31], "Incoming Call!", "SIDEKICK_PAYBACK_WARNING", "", 1, 0, "PAYBACK_WARNING", "KAROL", "PLAYER");
   UIManager_ReplaceDelayedEvent("sidekickResume", 0.1f);
   while (!Sidekick_HasDataBeenAnnounced(var4))
   {
       WAITUNWARPED(100);
   }
   Registry_SetValueInt("nPaybackState", 2);
   START_NEW_SCRIPT("Game/SeptemberMilestone/Payback_opponent_test", 0);
   WAITUNWARPED(1000);
   var5 = L[13];
   if (RAND_INT_RANGE(0, 1) == 1)
   {
       var5 = L[7];
   }
   PoliceManager_StartPursuit((*((var0 + 16) + 4))[0 * 48].v0, 3, 0, 0, 0);
   SplashManager_Splash(0, 4, "PB_LoseTheseGuys", 0x40000000, 1, 0);
   mcCareerSpeech_PlayNamedScenario("TAUNT_GOON_CHASE", var5, L[0]);
   PRINTSTRING("Goons are going to come after you");
}

void sub_15e4(var0, var1, var2, var3)
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

