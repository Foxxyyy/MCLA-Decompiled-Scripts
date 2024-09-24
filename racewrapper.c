void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45;

   while (!LoadingScreen_IsDoneLoading())
   {
       PRINTSTRING("waiting for loading screen to finish\n");
       WAITUNWARPED(100);
   }
   while (Race_GetCurrentRace() != null)
   {
       PRINTSTRING("waiting for current race to shut down\n");
       WAITUNWARPED(100);
   }
   var2 = LookupCity(GetCurrentCity());
   L[0].v4.v1[0 * 48].v0 = Player_FindRacerObject(0);
   L[0].v4.v1[0 * 48].v2 = 0;
   L[0].v4.v1[0 * 48].v5 = 1;
   L[0].v4.v770 = 1 + L[0].v4.v771;
   var3.v0 = 0.0f;
   var3.v1 = 0.0f;
   var3.v2 = 0.0f;
   OpponentManager_ClearUsedCharacters();
   var6 = mcCarArray_Create();
   mcCarArray_Fill(var6, L[0].v4.v1[0 * 48].v0, L[0].v4.v775, 31, 255, -1);
   var7 = null;
   var8 = null;
   var9 = null;
   var10 = null;
   var11 = null;
   var12 = 0;
   strcpy(&var13, 64, "");
   var29 = GetOpponentModValueCommandLine();
   var30 = 0;
   var31 = null;
   var32 = mcCareerSpeech_FindScenario("GREETING_MEET_ME_THERE_EVENT");
   var33 = 0;
   var34 = 1;
   var35 = 0;
   var36 = 0;
   PRINTSTRING("Num Opponents = ");
   PRINTINT(L[0].v4.v771);
   PRINTSTRING("\n");
   var35 = 0;
   while (var35 < L[0].v4.v771)
   {
       var36 = var35 + (L[0].v4.v770 - L[0].v4.v771);
       PRINTSTRING("Racer index = ");
       PRINTINT(var36);
       PRINTSTRING("\n");
       L[0].v4.v1[var36 * 48].v1 = OpponentManager_CreateOpponent();
       L[0].v4.v1[var36 * 48].v0 = Opponent_GetRacer(L[0].v4.v1[var36 * 48].v1);
       L[0].v4.v1[var36 * 48].v2 = 2;
       L[0].v4.v1[var36 * 48].v5 = 0;
       var31 = GetOpponentCarCommandLine(&var30, var35);
       if (var30 == 0)
       {
           var31 = "";
       }
       var37 = OpponentManager_GetCharacterNameParams(var35);
       if (StringCompare(var37, ""))
       {
           var7 = mcCarArray_GetRandomCarArrayData(var6);
           var8 = mcCarArrayData_GetName(var7);
           var9 = OpponentManager_FindRandomAvailableCharacterByVehicleName(var8);
           var10 = mcCharacterConfigData_GetCarConfigDataByVehicleName(var9, var8, Racer_GetCarConfig(L[0].v4.v1[0 * 48].v0), L[0].v4.v775, 255, 1);
       }
       else
       {
           var9 = OpponentManager_FindCharacterConfigData(var37);
           var10 = mcCharacterConfigData_GetCarConfigData(var9, Racer_GetCarConfig(L[0].v4.v1[0 * 48].v0), L[0].v4.v775, 255, 1);
       }
       if (var9 != null)
       {
           var37 = mcCharacterConfigData_GetName(var9);
           OpponentManager_MarkCharacterAsUsed(var37);
           var37 = mcCareer_GetHookmanCharacterSet(var37);
       }
       if (StringCompare(var31, ""))
       {
           var11 = mcCarConfigData_GetRandomConfigData(var10);
           OpponentManager_LoadOpponent(L[0].v4.v1[var36 * 48].v1, mcConfigData_GetName(var11), &var3, 0);
           if (var29 == -1)
           {
               Racer_SetModValue(L[0].v4.v1[var36 * 48].v0, mcCarConfigData_GetModValue(var10));
           }
           else
           {
               Racer_SetModValue(L[0].v4.v1[var36 * 48].v0, var29);
           }
       }
       else
       {
           OpponentManager_LoadOpponent(L[0].v4.v1[var36 * 48].v1, var31, &var3, 0);
       }
       OpponentManager_AddOpponentToWorld(L[0].v4.v1[var36 * 48].v1);
       Racer_SetCharacterName(L[0].v4.v1[var36 * 48].v0, var37);
       Racer_SetStreamingLockedIn(L[0].v4.v1[var36 * 48].v0);
       L[0].v4.v1[var36 * 48].v4 = mcHudMapServer_CreateElement();
       mcHudMapServer_SetVehicleElement(L[0].v4.v1[var36 * 48].v4, 6, L[0].v4.v1[var36 * 48].v0);
       mcHudMapServer_AddElement(L[0].v4.v1[var36 * 48].v4);
       var35 = var35 + 1;
   }
   L[0].v3 = Race_Create();
   Race_SetRaceData(L[0].v3, &(L[0].v4));
   Race_SetCurrentRace(L[0].v3);
   var38 = CityDescription_LookupRaceByIndex(var2, L[0].v4.v0);
   L[0].v4.v772 = RaceDescription_GetRaceType(var38);
   L[0].v4.v773 = RaceDescription_GetRaceSubType(var38);
   sub_5b4(&L[0]);
   L[0].v799 = sub_667(var38, L[0].v4.v770, var34);
   if (StringCompare(L[0].v799, ""))
   {
       L[0].v799 = "Game/RaceTypes/generic_countdown";
   }
   if ((L[0].v4.v788 || L[0].v4.v789) || (L[0].v4.v770 > mcRacerManager_GetNumRacersAllowedForPolice()))
   {
       sub_7c4(var38, 0.0f, 0, 0, 1, 1, 1);
   }
   else
   {
       sub_7c4(var38, 0.25f, 0, 0, 1, 1, 1);
   }
   while (L[0].v4.v772 == 1)
   {
       PropertyCtrl_SetPropertyBool(var39, 0, 0);
       L[0].v4.v774 = 1;
       Race_ToggleStarterCinematic(L[0].v3, 1);
       mcGame_ThrowEvent("localRace");
       Ctrl_SetVisible(var39, 1);
       Ctrl_SetVisible(var40, 1);
   }
   sub_1056(&L[0]);
   Race_GetRaceData(L[0].v3, &(L[0].v4));
   UIManager_SendEvent("calculateResults");
   Registry_GetValueInt("raceOverTrigger", &var12);
   if (var12 == 0)
   {
       if ((!L[0].v4.v786) && (!Race_IsDamagedOut(L[0].v3)))
       {
           mcEvent_PostEventRaceResults("GENERIC_RACE_COMPLETE", &(L[0].v4));
           mcEvent_PostEventRaceResults("RACE_EVENT", &(L[0].v4));
       }
       var33 = 1;
       sub_137d(&L[0], 0, 1, 1);
       UIManager_SendEvent("raceEnd");
       while (var12 == 0)
       {
           Registry_GetValueInt("raceOverTrigger", &var12);
           WAITUNWARPED(20);
       }
       AudioManager_SetActiveEndRace(0, 0);
   }
   else
   {
       PRINTSTRING("Racer Over Trig already 1");
       mcEvent_PostEventRaceResults("RACE_QUIT", &(L[0].v4));
   }
   Registry_GetValueString("raceOverCommand", &var13);
   PRINTSTRING("RaceWrapper decision made :");
   PRINTSTRING(&var13);
   PRINTSTRING("\n");
   if (StringCaseCompare(&var13, "restart"))
   {
       PRINTSTRING("RaceWrapper restart\n");
       RaceDescription_GetGridPosition(var38, 0, &var42, &var45);
       Warper_TransitionTo("DEFAULT_WITH_CUT", -1, &var42, &var42, &var42, "");
       PRINTSTRING("Start Waiting\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       sub_223a();
       if (CineScript_Next())
       {
       }
       else if (var33)
       {
       }
       else
       {
       }
   }
   else if (StringCaseCompare(&var13, "replay"))
   {
       PRINTSTRING("RaceWrapper replay\n");
       RaceDescription_GetGridPosition(var38, 0, &var42, &var45);
       sub_234e(1, 1, 0x3f800000, 0);
       Warper_TransitionTo("REPLAY", -1, &var42, &var42, &var42, "");
       PRINTSTRING("Setting up replay\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       sub_26f5(1, 1, 0x3f800000, 0);
       Warper_TransitionTo("EXIT_TO_CUT", -1, &var42, &var42, &var42, "");
       PRINTSTRING("Transitioning to replay start\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       Registry_SetValueInt("replaying", 1);
   }
   else if (StringCaseCompare(&var13, "nextRace"))
   {
       if (var32 != null)
       {
           mcCareerSpeech_PlayScenario(var32, Racer_GetVehicleDriverName(L[0].v4.v1[1 * 48].v0), "PLAYER");
       }
       L[0].v4.v0 = CityDescription_GetRaceIndexByName(var2, UILogic_GetNextArcadeRace());
       var38 = CityDescription_LookupRaceByIndex(var2, L[0].v4.v0);
       Warper_Warp("DEFAULT_WITH_CUT");
       PRINTSTRING("Start Waiting\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       while (SpeechSystem_IsPlaying())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting for speech to finish\n");
       }
       if (EventOptions_IsLastManOut(L[0].v4.v790))
       {
           L[0].v4.v779 = L[0].v4.v770 - 1;
       }
       else if ((!L[0].v4.v788) && (RaceDescription_GetRaceSubType(var38) == 2))
       {
           Registry_GetValueInt("nNumLaps", &(L[0].v4.v779));
       }
       else
       {
           L[0].v4.v779 = 0;
       }
       var34 = 0;
   }
   var35 = 0;
   while (var35 < L[0].v4.v771)
   {
       var36 = var35 + (L[0].v4.v770 - L[0].v4.v771);
       sub_2cd1(L[0].v4.v1[0 * 48].v0, L[0].v4.v1[var36 * 48].v1, L[0].v4.v1[var36 * 48].v0, var36, Race_HasBeenArrested(L[0].v3));
       Racer_HideIcon(L[0].v4.v1[var36 * 48].v0, 1);
       mcHudMapServer_DeleteElement(L[0].v4.v1[var36 * 48].v4);
       var35 = var35 + 1;
   }
   PRINTSTRING("DESTROY WRAPPER RACE\n");
   Race_ResetCurrentRace();
   EventOptions_DestroyOptions(L[0].v4.v790);
   Race_Destroy(L[0].v3);
   mcCarArray_Destroy(var6);
   sub_b5f();
   OpponentManager_ClearUsedCharacters();
}

void sub_5b4(var0)
{
   auto var3, var4, var5;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var4 = Racer_GetUID((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var4 == 0)
       {
           var4 = 5000 + var3;
           while (Racer_FindFromUID(var4) != null)
           {
               var4 = var4 + 1;
               WAITUNWARPED(10);
           }
           Racer_SetUID((*((var0 + 16) + 4))[var3 * 48].v0, var4);
       }
       CineScript_Cars_AssignIdToSlot(var4, var3);
       var3 = var3 + 1;
   }
}

function sub_667(var0, var1, var2)
{
   auto var5, var6, var7;

   if (RaceDescription_UseSafetyCam(var0))
   {
       return CineScript_PickRacestartSafetyCutscene();
   }
   else
   {
       return sub_6a5(RaceDescription_GetRaceGridType(var0), var1, var2, !RaceDescription_AllowRaceStarter(var0), 0);
   }
}

function sub_6a5(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11;

   if (var1 == 0)
   {
       PRINTSTRING("PickRacestartCutsceneOrTauntEnum:  0 opponents, forcing grid-type ");
       PRINTINT(var0);
       PRINTSTRING(" to 0 (1x1)\n");
       var0 = 0;
   }
   return CineScript_PickRacestartCutsceneOrTauntFromGridEnum(var0, var2, var3, var4);
}

void sub_7c4(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   PRINTSTRING("EvaluatePolice() - police probability: ");
   PRINTFLOAT(var1);
   PRINTSTRING("\n");
   var9 = 0;
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var1 > 0.0f) && (var9 >= 4))
   {
       PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races >= 4, setting police probability to 1.0\n");
       var1 = 1.0f;
   }
   var10 = 0;
   if (GetRaceCopChaseCommandLine(&var10))
   {
       if (var10 == 1)
       {
           if (var1 > 0.0f)
           {
               PRINTSTRING("EvaluatePolice() - racecopchase=1, setting police probability to 1.0\n");
               var1 = 1.0f;
           }
       }
       else
       {
           PRINTSTRING("EvaluatePolice() - racecopchase=0, setting police probability to 0.0\n");
           var1 = 0.0f;
       }
   }
   if (GetDemoCommandLine())
   {
       PRINTSTRING("EvaluatePolice() - demo, setting police probability to 0.0\n");
       var1 = 0.0f;
   }
   var11 = RAND_FLOAT_RANGE(0.0f, 1.0f);
   PRINTSTRING("EvaluatePolice() - random probability: ");
   PRINTFLOAT(var11);
   PRINTSTRING("\n");
   var12 = RaceDescription_GetNumCopZones(var0);
   PRINTSTRING("EvaluatePolice() - number of cop zones: ");
   PRINTINT(var12);
   PRINTSTRING("\n");
   if ((var12 == 0) || (var11 > var1))
   {
       PoliceManager_DestroyAllPolice();
       PRINTSTRING("EvaluatePolice() - police destroyed, not available in race\n");
       if (var1 > 0.0f)
       {
           var9 = var9 + 1;
       }
   }
   else
   {
       sub_b5f();
       var9 = 0;
   }
   PoliceManager_SetChaseProperties(var4, var5, var6);
   PoliceManager_SetRaceChaseTarget(var2, var3);
   Registry_SetValueInt("nNumNoCopRaces", var9);
   PRINTSTRING("EvaluatePolice() - new number of consecutive no-cop races: ");
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTINT(var9);
   PRINTSTRING("\n");
}

void sub_b5f()
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

void sub_1056(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9;

   var3 = -1;
   var3 = StatsManager_GetIntValue("xLRW", 0);
   if (var3 != 1)
   {
       PRINTSTRING("StatTracking: Previous race was not won... reset consecutive wins stat");
       StatsManager_UpdateStatInt("gCWN", 0, 3, 0);
       StatsManager_UpdateStatInt("kCWN", 0, 3, 0);
   }
   StatsManager_UpdateStatInt("xLRW", 0, 3, 0);
   OpponentManager_CleanupOpponentArray();
   while (!mcRacerManager_AreStreamStatesResolved())
   {
       PRINTSTRING("Waiting for racer stream state resolution.\n");
       if ((Net_IsConnecting() || Net_IsNetworked()) && (!*((var0 + 16) + 3120)))
       {
           return;
       }
       else
       {
           WAITUNWARPED(200);
       }
   }
   Race_Reset(*(var0 + 12));
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   var4 = 1;
   while (var4 == 1)
   {
       mcCareer_AddRaceToHistory(*((var0 + 16) + 0));
       var5 = LookupCity(GetCurrentCity());
       var6 = null;
       if (*((var0 + 16) + 3112) == 0)
       {
           var7 = CityDescription_LookupRaceByIndex(var5, *((var0 + 16) + 0));
           var6 = RaceDescription_GetEasyRaceName(var7);
           if (StringCompare(var6, ""))
           {
               var6 = CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0));
           }
       }
       else
       {
           var6 = CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0));
       }
       PRINTSTRING("Race Name ");
       PRINTSTRING(var6);
       PRINTSTRING("\n");
       var8 = START_NEW_SCRIPT_WITH_ARGS(var6, var0, 802, 3800);
       while (!IsChildFinished(var8))
       {
           WAIT(10);
       }
       Registry_GetValueInt("Script_ReloadRace", &var4);
       Registry_SetValueInt("Script_ReloadRace", 0);
   }
}

void sub_137d(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72;

   while (FlashNavigator_IsTransitioning())
   {
       PRINTSTRING("RaceOver.sch: WAITING TO END TRANSITION\n");
       WAITUNWARPED(200);
   }
   SplashManager_Cleanup();
   var6 = *((var0 + 16) + 3096);
   var7 = UIManager_FindMovie("PAUSEMOVIE");
   var8 = (17 == var6) || (16 == var6);
   var9 = 0;
   if (var6 == 11)
   {
       var9 = 0;
   }
   else
   {
       var9 = Race_IsTeamGame(var0 + 16);
   }
   var10 = Race_IsDamagedOut(*(var0 + 12));
   var11 = 1;
   var12 = Race_HasBeenArrested(*(var0 + 12));
   var13 = 0;
   var14 = Registry_GetValueBool("bComplete");
   var15 = Registry_GetValueBool("bFailure");
   var16 = Registry_GetValueBool("nPlayerCaught");
   var17 = var6 == 6;
   var18 = var6 == 2;
   var19 = var6 == 7;
   var20 = (var6 == 13) || (var6 == 14);
   var21 = var6 == 9;
   var22 = var6 == 10;
   var23 = var6 == 4;
   var24 = var6 == 3;
   PRINTSTRING("SCRIPT: Starting EndOfRaceSequence() for race type ");
   PRINTINT(*((var0 + 16) + 3096));
   if (var9)
   {
       PRINTSTRING(" (TEAM GAME) ");
   }
   else
   {
       PRINTSTRING(" (FFA GAME) ");
   }
   if (var10)
   {
       PRINTSTRING(" (DAMAGED OUT)\n");
   }
   else
   {
       PRINTSTRING(" (RACE SAFE)\n");
   }
   if (var15)
   {
       PRINTSTRING(" (FAILURE)\n");
   }
   else
   {
       PRINTSTRING(" (SUCCESS)\n");
   }
   if (((*((var0 + 16) + 4))[var1 * 48].v8 == 0x7fffffff) && (!var8))
   {
       if (!((var24 || var23) && (var14 || var15)))
       {
           PRINTSTRING("SCRIPT: skipping sequence because did not finish\n");
           var11 = 0;
       }
   }
   if (var12 && (!var16))
   {
       PRINTSTRING("SCRIPT: skipping sequence because damaged out or arrested\n");
       var11 = 0;
   }
   Notify(2);
   if (var11)
   {
       var25 = (*((var0 + 16) + 4))[var1 * 48].v41;
       var26 = (*((var0 + 16) + 4))[var1 * 48].v8;
       PRINTSTRING("nFinishTime = ");
       PRINTINT(var26);
       if (var3)
       {
           if ((var18 || var17) || var19)
           {
               if (var15)
               {
                   mcPlayerAudioEntity_PlayEndRaceSpeechLose();
               }
               else
               {
                   mcPlayerAudioEntity_PlayEndRaceSpeechWin();
               }
           }
           else if (var25 == 1)
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechWin();
           }
           else if ((var25 == 2) && ((var26 - Race_GetWinningTime(*(var0 + 12))) <= 300))
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechClose();
           }
           else
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechLose();
           }
           WAITUNWARPED(200);
       }
       var27 = !*((var0 + 16) + 3120);
       var28 = 16;
       var45 = Form_GetForm(-1);
       var28[9] = Form_GetForm(51);
       var28[0] = Form_GetForm(60);
       var28[1] = Form_GetForm(54);
       var28[2] = Form_GetForm(57);
       var28[3] = Form_GetForm(58);
       var28[5] = Form_GetForm(42);
       var28[6] = Form_GetForm(53);
       var28[7] = Form_GetForm(49);
       var28[8] = Form_GetForm(50);
       var28[10] = Form_GetForm(46);
       var28[11] = Form_GetForm(47);
       var28[12] = Form_GetForm(56);
       var28[13] = Form_GetForm(49);
       var28[14] = Form_GetForm(50);
       var28[15] = Form_GetForm(52);
       UIManager_SendEvent("raceEnding");
       PRINTSTRING("SCRIPT : I start the race over sequence for raceType: ");
       PRINTINT(*((var0 + 16) + 3092));
       PRINTSTRING("\n");
       PerspectiveForm_SetCameraIndex(var28[0], 0);
       Form_ShowForm(var45, var28[0]);
       if (var27)
       {
           var46 = 0.5f;
           PerspectiveForm_SetSlowMotion(var28[0], 0.0f, 1.0f / var46, 0, 1, 0.4f);
       }
       else
       {
           WAITUNWARPED(100);
       }
       var47 = 5;
       var53 = 5;
       var59 = 0;
       var60 = 0;
       var61 = 0;
       var62 = 0;
       if (!var20)
       {
           if (Form_GetFormResult(var28[2]) == 3)
           {
               var61 = 1;
               PropertyCtrl_SetPropertyInt(Form_ToCtrl(var28[2]), 0, 0);
           }
           if (Form_GetFormResult(var28[6]) == 3)
           {
               var62 = 1;
           }
       }
       if (var12 || var13)
       {
           var61 = 0;
           var62 = 0;
           var23 = 0;
           var24 = 0;
           var18 = 0;
           var9 = 0;
       }
       var47[0] = 0;
       var47[1] = 0;
       var47[2] = 0;
       var47[3] = 0;
       var47[4] = 0;
       if (var9)
       {
           var47[0] = 3;
           var60 = var60 + 1;
       }
       else if (var12 && (!var16))
       {
           var47[0] = 10;
           var60 = var60 + 1;
       }
       else if (var13 && (!var16))
       {
           var47[0] = 11;
           var60 = var60 + 1;
       }
       else if (!var10)
       {
           if ((((!var18) && (!var19)) && (!var17)) && ((*((var0 + 16) + 4))[var1 * 48].v8 != 0x7fffffff))
           {
               strcpy(&var63, 16, "");
               strcati(&var63, 16, (*((var0 + 16) + 4))[var1 * 48].v41);
               Form_SetText(var28[1], &var63);
               PRINTSTRING("POSITION=");
               PRINTSTRING(&var63);
               PRINTSTRING("\n");
               var47[0] = 1;
               var60 = var60 + 1;
           }
       }
       if (var17 && (!var10))
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 9;
           var60 = var60 + 1;
       }
       else if (var18 && (!var10))
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 5;
           var60 = var60 + 1;
       }
       else if (var19)
       {
           if (((var14 || var15) || var16) || var10)
           {
               PRINTSTRING("PAYBACK  eP_EventResultsPanel \n A: ");
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       else if (var23)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 13;
           var60 = var60 + 1;
       }
       else if (var24)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 14;
           var60 = var60 + 1;
       }
       else if (var21)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       else if (var22)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       if (var61)
       {
           var47[var60] = 2;
           var60 = var60 + 1;
       }
       if (var62)
       {
           var47[var60] = 6;
           var60 = var60 + 1;
       }
       var67 = 0;
       while (var67 <= (var60 - 1))
       {
           if (var47[var67] == 3)
           {
               var53[var67] = 4400;
           }
           else if (var47[var67] == 9)
           {
               var53[var67] = 5000;
           }
           else if (var47[var67] == 12)
           {
               var53[var67] = 3500;
           }
           else
           {
               var53[var67] = 2200;
           }
           var67 = var67 + 1;
       }
       AudioManager_SetActiveEndRace(1, var20);
       var68 = null;
       var67 = 0;
       while (var67 <= (var60 - 1))
       {
           Registry_GetValueInt("NET_UNLOADCAREER", &var59);
           if ((var59 > 0) || Net_IsConnecting())
           {
           }
           else
           {
               PRINTSTRING("SHOWING FORM AT INDEX: ");
               PRINTINT(var67);
               PRINTSTRING(", FORM: ");
               PRINTINT(var47[var67]);
               PRINTSTRING(", WAIT:");
               PRINTINT(var53[var67]);
               PRINTSTRING("\n");
               var68 = var28[var47[var67]];
               if (var47[var67] == 1)
               {
                   Form_ShowForm(var45, var68);
                   WAITUNWARPED(var53[var67]);
               }
               else if ((var47[var67] == 3) || (var47[var67] == 12))
               {
                   Form_ShowForm(var28[0], var68);
                   WAITUNWARPED(var53[var67]);
               }
               else
               {
                   sub_1fb9(var28[0], var68);
               }
               if (!(var47[var67] == 0))
               {
                   Form_CloseForm(var68);
                   PRINTSTRING("CLOSEFORM\n");
               }
               var67 = var67 + 1;
           }
       }
       Form_CloseForm(var28[0]);
   }
   if (var2)
   {
       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
   }
   PRINTSTRING("SCRIPT: End EndOfRaceSequence()\n");
}

void sub_1fb9(var0, var1)
{
   auto var4, var5, var6;

   var4 = 1;
   Form_ShowForm(var0, var1);
   while (var4)
   {
       var4 = Form_GetFormVisible(var1);
       WAITUNWARPED(100);
   }
}

void sub_223a()
{
   auto var2, var3, var4;

   StatsManager_UpdateStatInt("kTRS", 0, 0, 1);
   StatsManager_UpdateStatInt("xRRT", 0, 0, 1);
   var2 = StatsManager_GetIntValue("kTRS", 0);
   var3 = StatsManager_GetIntValue("kRCP", 0);
   var4 = 0.0f;
   if (var3 > 0)
   {
       var4 = TO_FLOAT(var2) / TO_FLOAT(var3);
   }
   StatsManager_UpdateStatFloat("kARS", 0, 3, var4);
}

void sub_234e(var0, var1, var2, var3)
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

void sub_26f5(var0, var1, var2, var3)
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

void sub_2cd1(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13;

   var7 = Racer_DistanceBetween(var0, var2);
   PRINTSTRING("Opponent Distance = ");
   PRINTFLOAT(var7);
   PRINTSTRING("\n");
   if ((var7 < 500.0f) && (!var4))
   {
       Racer_SetStreamingUnlocked(var2);
       Opponent_ToggleDeleteOnEviction(var1, 1);
       var8 = BrainFactory_CreateBrainCruising(var2);
       sub_2d4e(var3, var8);
       BrainCruising_SetLooping(var8, 1);
       BrainCruising_DriveToNearestRail(var8);
   }
   else
   {
       OpponentManager_RemoveOpponentFromWorld(var1);
       OpponentManager_DeleteOpponent(var1);
   }
}

function sub_2d4e(var0, var1)
{
   auto var4, var5, var6, var7, var8;

   switch (var0)
   {
       case 0:
       {
           var4.v0 = -2171.86f;
           var4.v1 = -3.73355f;
           var4.v2 = 38.2942f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2082.38f;
           var4.v1 = -0.150024f;
           var4.v2 = -103.202f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1848.6f;
           var4.v1 = -5.57857f;
           var4.v2 = 181.021f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1889.23f;
           var4.v1 = -4.57721f;
           var4.v2 = 322.555f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2098.78f;
           var4.v1 = 0.623314f;
           var4.v2 = 382.108f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 1:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 2:
       {
           var4.v0 = -529.196f;
           var4.v1 = -8.41289f;
           var4.v2 = 203.315f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -241.864f;
           var4.v1 = -13.1316f;
           var4.v2 = 306.687f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -24.9188f;
           var4.v1 = -8.92001f;
           var4.v2 = 127.65f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -134.135f;
           var4.v1 = 18.2821f;
           var4.v2 = -9.99714f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -502.507f;
           var4.v1 = -1.23221f;
           var4.v2 = -3.32185f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -593.266f;
           var4.v1 = -5.1629f;
           var4.v2 = 79.92f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 3:
       {
           var4.v0 = 364.965f;
           var4.v1 = -4.43402f;
           var4.v2 = 120.526f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 366.118f;
           var4.v1 = -11.8294f;
           var4.v2 = 326.516f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 568.537f;
           var4.v1 = -13.1919f;
           var4.v2 = 359.886f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 778.476f;
           var4.v1 = -10.1129f;
           var4.v2 = 213.564f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 772.173f;
           var4.v1 = -4.87628f;
           var4.v2 = 26.1546f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 697.668f;
           var4.v1 = 1.48578f;
           var4.v2 = -89.3486f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 492.799f;
           var4.v1 = 2.23468f;
           var4.v2 = -31.1908f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 4:
       {
           var4.v0 = 1132.48f;
           var4.v1 = 19.5945f;
           var4.v2 = -995.254f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1181.5f;
           var4.v1 = 14.85f;
           var4.v2 = -668.24f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.25f;
           var4.v1 = 14.85f;
           var4.v2 = -587.388f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 886.057f;
           var4.v1 = 14.8471f;
           var4.v2 = -666.398f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.84f;
           var4.v1 = 19.0699f;
           var4.v2 = -984.565f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 5:
       {
           var4.v0 = 1930.96f;
           var4.v1 = -7.88059f;
           var4.v2 = 519.85f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1974.67f;
           var4.v1 = -5.14804f;
           var4.v2 = 317.939f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2161.5f;
           var4.v1 = -3.14887f;
           var4.v2 = -3.44634f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2279.15f;
           var4.v1 = -5.8414f;
           var4.v2 = -37.9429f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2287.03f;
           var4.v1 = -10.1456f;
           var4.v2 = 150.248f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2089.7f;
           var4.v1 = -10.1458f;
           var4.v2 = 494.101f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 6:
       {
           var4.v0 = 2337.39f;
           var4.v1 = -0.149963f;
           var4.v2 = -661.406f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2278.43f;
           var4.v1 = 1.57553f;
           var4.v2 = -911.264f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2154.28f;
           var4.v1 = 5.34701f;
           var4.v2 = -921.462f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2065.79f;
           var4.v1 = 6.84834f;
           var4.v2 = -679.637f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2196.87f;
           var4.v1 = 4.55591f;
           var4.v2 = -512.556f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       default:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
   }
}

