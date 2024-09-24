void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14;

   Registry_SetValueInt(L[0].v812, 2);
   var2 = mcRaceArray_Create();
   mcRaceArray_Fill(var2, L[0].v810, 16, 64);
   L[0].v802 = RAND_INT_RANGE(0, mcRaceArray_GetCount(var2) - 1);
   var3 = LookupCity(GetCurrentCity());
   var4 = CityDescription_LookupRaceByIndex(var3, mcRaceArray_GetRaceIndex(var2, L[0].v802));
   PRINTSTRING("DELIVERY START INFO:\n");
   PRINTSTRING("Car Config name ");
   PRINTSTRING(RaceDescription_GetCarConfigName(var4));
   PRINTSTRING("\n");
   PRINTSTRING("nCurrentIdx - ");
   PRINTINT(L[0].v802);
   PRINTSTRING("\n");
   L[0].v835 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v835, RaceDescription_GetCarConfigName(var4), &(L[0].v836), L[0].v839);
   OpponentManager_AddOpponentToWorld(L[0].v835);
   var5 = Opponent_GetRacer(L[0].v835);
   Racer_SetUID(var5, L[0].v809);
   Racer_SetVehicleDriverEnable(var5, 0);
   Racer_SetHeadlights(var5, 0);
   Racer_SetExhaust(var5, 0);
   mcHudMapServer_SetRacerElement(L[0].v815, var5);
   mcHudMapServer_AddElement(L[0].v815);
   mcTargetManager_RegisterRacer(L[0].v809, var5);
   mcTargetManager_HideTarget(L[0].v809, 0);
   mcTargetManager_ToggleMapVisibiliy(L[0].v809, 0);
   Racer_SetIconType(var5, 11);
   Racer_HideIcon(var5, 0);
   Racer_InitializeResetPosition(var5, &(L[0].v836), L[0].v839);
   Racer_ResetWithDamageIntact(var5);
   var6 = sub_1fe(0);
   var7 = UIManager_GetState("Cruising_Offline");
   var8 = null;
   var9 = 0.0f;
   var10 = 0;
   var11 = 3;
   var12 = 0;
   var13 = 0;
   var14 = 0;
   while (!var14)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var10);
       if (var10 == 1)
       {
           PRINTSTRING("Delivery ");
           PRINTSTRING(L[0].v808);
           PRINTSTRING(" was nSuspended (Script_SuspendAllOpponents was set)\n");
           SetExceptionMask(0);
           mcHudMapServer_RemoveElement(L[0].v815);
           Racer_SetStreamingLockedOut(var5);
           while (var10 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var10);
               WAITUNWARPED(100);
           }
           PRINTSTRING("Delivery ");
           PRINTSTRING(L[0].v808);
           PRINTSTRING(" was un-nSuspended ( Script_SuspendAllOpponents was reset )\n");
           Racer_SetStreamingUnlocked(var5);
           mcHudMapServer_AddElement(L[0].v815);
           SetExceptionMask(2);
       }
       if (((vhsmState_IsListener(var7) && (!Game_IsPaused())) && (!Net_IsConnecting())) && (!Net_IsNetworked()))
       {
           if ((var12 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
           {
               var12 = var12 - 1;
           }
           var9 = Racer_DistanceToPoint(var6, &(L[0].v819));
           if (var9 < 12.0f)
           {
               if (PoliceManager_CheckPoliceActivity(1) > 1)
               {
                   if (var12 == 0)
                   {
                       SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                       var12 = 100;
                   }
                   WAITUNWARPED(100);
               }
               else
               {
                   PoliceManager_SetAllPoliceUnderground(1, 1);
                   sub_4c2(0.0f, 0.25f, 67);
                   PRINTSTRING("DELIVERY TRIGGERED\n");
                   mcGame_ThrowEvent("deliveryHangout");
                   Racer_Deactivate(var6);
                   Registry_SetValueInt(L[0].v812, 3);
                   mcHudMapServer_RemoveElement(L[0].v815);
                   Racer_HideIcon(var5, 1);
                   mcEvent_PostEventStr("LOCATION_EVENT", L[0].v808);
                   mcEvent_PostEventStr("MISSION_EVENT", L[0].v813);
                   Registry_GetValueInt(L[0].v812, &var13);
                   while (var13 == 3)
                   {
                       Registry_GetValueInt(L[0].v812, &var13);
                       WAITUNWARPED(100);
                   }
                   if (var13 == 4)
                   {
                       if ((!GetNoTutorialCommandLine()) && (StatsManager_GetIntValue("tTDE", 0) == 0))
                       {
                           StatsManager_UpdateStatInt("tTDE", 0, 3, 1);
                           sub_4c2(0, 0x3f000000, 108);
                           sub_67c(-1, 100, "TUTORIAL_DELIVERY_INGAME", "drv_mb_04_set", "PLAYER");
                           sub_729(108, 0x3f000000);
                       }
                       var11 = sub_7b6(&L[0], var5, var4, var2);
                       if (var11 == 0)
                       {
                           PRINTSTRING("Player decided to return to garage\n");
                       }
                       else if (var11 == 3)
                       {
                           PRINTSTRING("Player opted to ignore exit event\n");
                       }
                       else
                       {
                           Registry_SetValueInt(L[0].v812, 3);
                           mcEvent_PostEventStr("MISSION_EVENT", L[0].v814);
                           Registry_GetValueInt(L[0].v812, &var13);
                           while (var13 == 3)
                           {
                               Registry_GetValueInt(L[0].v812, &var13);
                               WAITUNWARPED(100);
                           }
                       }
                   }
                   mcGame_ThrowEvent("cruising");
                   PRINTSTRING("Delivery car change from  ");
                   PRINTINT(L[0].v802);
                   L[0].v802 = RAND_INT_RANGE(0, mcRaceArray_GetCount(var2) - 1);
                   var4 = CityDescription_LookupRaceByIndex(var3, mcRaceArray_GetRaceIndex(var2, L[0].v802));
                   PRINTSTRING(" to ");
                   PRINTINT(L[0].v802);
                   PRINTSTRING("\n");
                   Racer_InitializeResetPosition(var5, &(L[0].v836), L[0].v839);
                   Racer_ChangeCar(var5, RaceDescription_GetCarConfigName(var4));
                   mcHudMapServer_AddElement(L[0].v815);
                   Racer_HideIcon(var5, 0);
                   Registry_SetValueInt(L[0].v812, 2);
                   PoliceManager_SetAllPoliceUnderground(0, 1);
                   sub_db5();
               }
           }
       }
       WAITUNWARPED(100);
   }
   mcTargetManager_HideTarget(L[0].v809, 1);
   mcTargetManager_UnRegisterTarget(L[0].v809);
   mcHudMapServer_DeleteElement(L[0].v815);
   OpponentManager_RemoveOpponentFromWorld(L[0].v835);
   OpponentManager_DeleteOpponent(L[0].v835);
   mcRaceArray_Destroy(var2);
   Registry_SetValueInt(L[0].v812, 0);
}

function sub_1fe(var0)
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

void sub_4c2(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_67c(var0, var1, var2, var3, var4)
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

void sub_729(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

function sub_7b6(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17;

   var6.v0 = 819.61f;
   var6.v1 = 17.58f;
   var6.v2 = -808.41f;
   var9 = 151.72f;
   var10 = 1;
   var11 = Form_GetForm(67);
   Form_SetText(var11, *(var0 + 3232));
   Registry_SetValueString("szEventName", *(var0 + 3232));
   sub_4c2(0, 0x3f000000, 108);
   var12 = sub_67c(-1, 67, 0, 0, 0);
   sub_729(108, 0x3f000000);
   if (var12 == 3)
   {
       var13 = SimpleListForm_GetItem(var11, 0);
       *(((var0 + 0) + 16) + 3100) = ComboBoxItem_GetSelectedIndex(var13);
       Form_CloseForm(var11);
       var10 = sub_882(var0, var2, var3, var1);
   }
   return var10;
}

function sub_882(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49;

   StatsManager_UpdateStatInt("xGAD", 0, 0, 1);
   Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", *(var0 + 3236), var0 + 3288, var0 + 3300, var0 + 3312, "WarpFromCarToWaitPosition_CarneySign");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(30);
       PRINTSTRING("Waiting for cutscene to load\n");
   }
   PRINTSTRING("Warper is in place\n");
   var6 = LookupCity(GetCurrentCity());
   var7 = mcRaceArray_GetCount(var2);
   var8 = var7;
   (*(((var0 + 0) + 16) + 4))[0 * 48].v0 = sub_1fe(0);
   (*(((var0 + 0) + 16) + 4))[0 * 48].v2 = 0;
   (*(((var0 + 0) + 16) + 4))[0 * 48].v5 = 1;
   *(((var0 + 0) + 16) + 3080) = 1;
   *(((var0 + 0) + 16) + 3084) = 0;
   *(((var0 + 0) + 16) + 3088) = 4;
   *(((var0 + 0) + 16) + 3092) = 6;
   *(((var0 + 0) + 16) + 3096) = 6;
   *((var0 + 0) + 12) = Race_Create();
   Race_SetCurrentRace(*((var0 + 0) + 12));
   sub_a1a(var1, 0.0f, 0, 0, 1, 1, 1);
   var9 = UIManager_GetState("Delivery_RESULTS");
   var10 = 0;
   var11 = 0;
   var12 = mcCarConfig_Create("");
   var13 = 0;
   var14 = 0;
   var15 = null;
   var16 = 3;
   var17 = 0;
   strcpy(&var18, 64, "");
   var34 = HUD_GetHUDCtrl(9);
   var35 = null;
   var36 = 0;
   var37 = HUD_GetHUDCtrl(6);
   var38 = Opponent_GetRacer(*(var0 + 3340));
   Racer_ResetWithDamageIntact(var38);
   var39.v2.v0.v0 = 0.0f;
   var39.v2.v0.v1 = 0.0f;
   var39.v2.v0.v2 = 0.0f;
   var39.v2.v3 = 0.0f;
   CineScript_SetGameCoordSysBinding(&var39);
   sub_10ae(var3, 0);
   Warper_SetIsWarpingToCutscene(1);
   Warper_SetDestinationMatrix(var0 + 3288, var0 + 3300, var0 + 3312);
   mcMusicManager_SuspendUserState(1000);
   var45 = START_NEW_SCRIPT(*(var0 + 3244), 1500);
   while (!IsChildFinished(var45))
   {
       WAITUNWARPED(30);
   }
   var14 = LocalOptions_GetCurrentVehicleProfileIndex();
   PRINTSTRING("Player Current idx ");
   PRINTINT(var14);
   PRINTSTRING("\n");
   PRINTSTRING("Start Waiting\n");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Finished waiting\n");
   Racer_SetStreamingLockedOut(var3);
   PRINTSTRING("DELIVERY: SETUP RACE\n");
   mcRaceArray_SetUsed(var2, *(var0 + 3208), 1);
   *(((var0 + 0) + 16) + 0) = mcRaceArray_GetRaceIndex(var2, *(var0 + 3208));
   var1 = CityDescription_LookupRaceByIndex(var6, *(((var0 + 0) + 16) + 0));
   sub_142f(var0 + 0);
   var10 = RAND_INT_RANGE(0, 2);
   if (var10 == 0)
   {
       *((var0 + 0) + 3196) = "Game/CineScripts/generated/RaceStart/gen_prerace_delivery_1x1_01_generated";
   }
   else if (var10 == 1)
   {
       *((var0 + 0) + 3196) = "Game/CineScripts/generated/RaceStart/gen_prerace_delivery_1x1_02_generated";
   }
   else
   {
       *((var0 + 0) + 3196) = "Game/CineScripts/generated/RaceStart/gen_prerace_delivery_1x1_03_generated";
   }
   var13 = mcCarConfig_Load(var12, RaceDescription_GetCarConfigName(var1));
   if (var13)
   {
       Racer_ChangeCarByConfig((*(((var0 + 0) + 16) + 4))[0 * 48].v0, var12);
   }
   while (!Racer_IsCarStreamed((*(((var0 + 0) + 16) + 4))[0 * 48].v0))
   {
       WAITUNWARPED(100);
   }
   PRINTSTRING("DELIVERY: RESTART RACE\n");
   mcGame_ThrowEvent("deliveryRace");
   PRINTSTRING("\nDELIVERY: RACE INFO\n");
   PRINTSTRING("=======================\n");
   var11 = 0;
   while (var11 < var7)
   {
       PRINTSTRING("Race Idx ");
       PRINTINT(var11);
       PRINTSTRING(" = ");
       if (*(var0 + 3208) == var11)
       {
           PRINTSTRING(" CURRENT\n");
       }
       else if (mcRaceArray_IsUsed(var2, var11))
       {
           PRINTSTRING(" TRUE\n");
       }
       else
       {
           PRINTSTRING(" FALSE\n");
       }
       var11 = var11 + 1;
   }
   var35 = CityDescription_GetRaceNameByIndex(var6, *(((var0 + 0) + 16) + 0));
   Race_Reset(*((var0 + 0) + 12));
   Race_EnableRaceTimer(*((var0 + 0) + 12), 0);
   Race_SetTargetTime(*((var0 + 0) + 12), RaceDescription_GetTargetTime(var1, *(((var0 + 0) + 16) + 3100)));
   PropertyCtrl_SetPropertyBool(var37, 0, 1);
   Race_SetTargetDamage(*((var0 + 0) + 12), 100);
   PropertyCtrl_SetPropertyBool(var34, 2, 0);
   PropertyCtrl_SetPropertyFloat(var34, 1, 1.0f * (*(var0 + 3212))[*(((var0 + 0) + 16) + 3100)]);
   PropertyCtrl_SetPropertyFloat(var34, 3, (*(var0 + 3212))[*(((var0 + 0) + 16) + 3100)]);
   Race_SetRaceData(*((var0 + 0) + 12), (var0 + 0) + 16);
   var15 = START_NEW_SCRIPT_WITH_ARGS(var35, var0 + 0, 802, 1500);
   while (!IsChildFinished(var15))
   {
       WAITUNWARPED(100);
   }
   Race_GetRaceData(*((var0 + 0) + 12), (var0 + 0) + 16);
   UIManager_SendEvent("calculateResults");
   Registry_SetValueBool("hudVisible", 0);
   Registry_GetValueInt("raceOverTrigger", &var17);
   if (var17 == 0)
   {
       if ((!*(((var0 + 0) + 16) + 3144)) && (!Race_IsDamagedOut(*((var0 + 0) + 12))))
       {
           if (Registry_GetValueBool("bComplete"))
           {
               mcEvent_PostEventRaceResults("RACE_EVENT", (var0 + 0) + 16);
               mcEvent_PostEventRaceResults("DELIVERY_RACE_COMPLETE", (var0 + 0) + 16);
               StatsManager_UpdateStatInt("xCDL", *(var0 + 3236), 0, 1);
               StatsManager_UpdateStatInt("kDLT", 0, 0, 1);
           }
       }
       sub_19a5(var0 + 0, 0, 1, 1);
       Registry_GetValueInt("NET_UNLOADCAREER", &var36);
       if (((var36 < 1) && (!Net_IsConnecting())) && (!Net_IsNetworked()))
       {
           UIManager_SendEvent("raceEnd");
       }
       while (var17 == 0)
       {
           Registry_GetValueInt("raceOverTrigger", &var17);
           WAITUNWARPED(100);
       }
       AudioManager_SetActiveEndRace(0, 0);
   }
   Registry_GetValueString("raceOverCommand", &var18);
   PRINTSTRING("Delivery Race command: ");
   PRINTSTRING(&var18);
   PRINTSTRING("\n");
   if (StringCompare(&var18, "nextRace"))
   {
       Warper_Warp("DEFAULT_WITH_CUT");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Finished waiting\n");
       Registry_SetValueBool("hudVisible", 1);
       var8 = var8 - 1;
       if (var8 == 0)
       {
       }
       PRINTSTRING("DELIVERY: NEXT RACE\n");
       var10 = RAND_INT_RANGE(0, var8 - 1);
       PRINTSTRING("RANDOM COUNT ");
       PRINTINT(var10);
       PRINTSTRING("\n");
       var11 = 0;
       while (var11 < var7)
       {
           PRINTSTRING("Index ");
           PRINTINT(var11);
           PRINTSTRING("\n");
           if (!mcRaceArray_IsUsed(var2, var11))
           {
               if (var10 == 0)
               {
                   *(var0 + 3208) = var11;
                   PRINTSTRING("DELIVERY: AVAILABLE RACE FOUND\n");
               }
               else
               {
                   var10 = var10 - 1;
               }
           }
           var11 = var11 + 1;
       }
       PRINTSTRING("DELIVERY: COULDN'T FIND UNUSED RACE INDEX. RESTARTING MODE\n");
   }
   else if (StringCompare(&var18, "restart"))
   {
       Warper_Warp("DEFAULT_WITH_CUT");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Finished waiting\n");
       sub_28b8();
       UILogic_FullFix();
       Registry_SetValueBool("hudVisible", 1);
   }
   else if (StringCompare(&var18, "replay"))
   {
       sub_298c(1, 1, 0x3f800000, 0);
       Warper_Warp("REPLAY");
       PRINTSTRING("Setting up replay\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       sub_2d23(1, 1, 0x3f800000, 0);
       Warper_Warp("EXIT_TO_CUT");
       PRINTSTRING("Transitioning to replay start\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Finished waiting\n");
       Registry_SetValueInt("replaying", 1);
       Registry_SetValueBool("hudVisible", 1);
   }
   else
   {
       if (StringCompare(&var18, "returnToGarage"))
       {
           var16 = 0;
       }
       Warper_Warp("USER_WAIT_NO_CUT_UP");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Finished waiting\n");
       while (UIManager_IsSaving())
       {
           WAITUNWARPED(100);
       }
       MessageBox_ShowLoadingBox("Career_Loading");
       Registry_SetValueBool("hudVisible", 1);
       if (var13)
       {
           Racer_InitializeResetPosition((*(((var0 + 0) + 16) + 4))[0 * 48].v0, var0 + 3324, *(var0 + 3336));
           Racer_ChangeCarByConfig((*(((var0 + 0) + 16) + 4))[0 * 48].v0, LocalOptions_GetVehicleProfile(var14));
       }
       Racer_SetStreamingUnlocked(var3);
       while (!Racer_IsVinylStreamed((*(((var0 + 0) + 16) + 4))[0 * 48].v0))
       {
           WAITUNWARPED(100);
       }
       MessageBox_HideLoadingBox("Career_Loading");
       mcCarConfig_Destroy(var12);
       Race_ResetCurrentRace();
       Race_Destroy(*((var0 + 0) + 12));
       Warper_Warp("USER_WAIT_NO_CUT_DOWN");
       while (Warper_IsWarping())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting for warp to return\n");
       }
       PRINTSTRING("Finished waiting\n");
       Racer_Activate((*(((var0 + 0) + 16) + 4))[0 * 48].v0);
       sub_db5();
       PropertyCtrl_SetPropertyBool(var37, 0, 0);
       return var16;
   }
}

void sub_a1a(var0, var1, var2, var3, var4, var5, var6)
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
       sub_db5();
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

void sub_db5()
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

void sub_10ae(var0, var1)
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

void sub_142f(var0)
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

void sub_19a5(var0, var1, var2, var3)
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
                   sub_25e1(var28[0], var68);
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

void sub_25e1(var0, var1)
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

void sub_28b8()
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

void sub_298c(var0, var1, var2, var3)
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

void sub_2d23(var0, var1, var2, var3)
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

