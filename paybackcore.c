void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39;

   var2 = mcCarConfig_Create("");
   var3 = 0;
   var4 = Player_FindRacerObject(0);
   var5 = LocalOptions_GetCurrentVehicleProfileIndex();
   var6 = mcCarConfig_Load(var2, L[0].v803);
   Racer_ChangeCarByConfig(var4, var2);
   Racer_Deactivate(var4);
   while (!Racer_IsCarStreamed(var4))
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting for car to stream in");
       Racer_Deactivate(var4);
   }
   CineScript_Cars_AssignIdToSlot(Racer_GetUID(var4), 0);
   Warper_SetIsEnterOnly(1);
   Racer_Deactivate(var4);
   var7 = START_NEW_SCRIPT("Game/CineScripts/generated/RaceStart/cut_payback_get_keys_generated", 1500);
   while (!IsChildFinished(var7))
   {
       WAITUNWARPED(30);
   }
   Racer_Activate(var4);
   PRINTSTRING("Finished Keys");
   var8 = mcRaceArray_Create();
   mcRaceArray_Fill(var8, 6, 32, 128);
   var9 = OpponentManager_CreateOpponent();
   var10 = OpponentManager_CreateOpponent();
   var11 = null;
   var12 = null;
   var13 = 1;
   var14 = mcMissionManager_GetMission("PAYBACK_GH_18");
   if (mcMission_GetState(var14) == 3)
   {
       var11 = OpponentManager_FindCharacterConfigData("GH_18");
       var12 = mcCharacterConfigData_GetCarConfigDataByVehicleName(var11, "vp_mzd_rx7_95", Racer_GetCarConfig(L[0].v0.v4.v1[0 * 48].v0), L[0].v0.v4.v775, 255, 1);
       var13 = 0;
   }
   else
   {
       var11 = OpponentManager_FindRandomAvailableCharacter();
       var12 = mcCharacterConfigData_GetCarConfigData(var11, Racer_GetCarConfig(L[0].v0.v4.v1[0 * 48].v0), L[0].v0.v4.v775, 255, 1);
   }
   var15 = mcCarConfigData_GetRandomConfigData(var12);
   var16.v0 = (float)0;
   var16.v1 = (float)0;
   var16.v2 = (float)0;
   OpponentManager_LoadOpponent(var9, mcConfigData_GetName(var15), &var16, 0);
   OpponentManager_AddOpponentToWorld(var9);
   OpponentManager_LoadOpponent(var10, mcConfigData_GetName(var15), &var16, 0);
   OpponentManager_AddOpponentToWorld(var10);
   var19 = Opponent_GetRacer(var9);
   var20 = Opponent_GetRacer(var10);
   L[0].v0.v4.v1[1 * 48].v0 = var19;
   L[0].v0.v4.v1[1 * 48].v2 = 2;
   L[0].v0.v4.v1[1 * 48].v5 = 0;
   L[0].v0.v4.v1[2 * 48].v0 = var20;
   L[0].v0.v4.v1[2 * 48].v2 = 2;
   L[0].v0.v4.v1[2 * 48].v5 = 0;
   L[0].v0.v4.v1[1 * 48].v4 = mcHudMapServer_CreateElement();
   L[0].v0.v4.v1[2 * 48].v4 = mcHudMapServer_CreateElement();
   Racer_SetCharacterName(var19, mcCareer_GetHookmanCharacterSet(mcCharacterConfigData_GetName(var11)));
   Racer_SetModValue(var19, mcCarConfigData_GetModValue(var12));
   Racer_SetStreamingLockedIn(var19);
   Racer_SetStreamingLockedIn(var20);
   Racer_SetIconType(var19, 10);
   Racer_HideIcon(var19, 0);
   Racer_SetIconType(var20, 10);
   Racer_HideIcon(var20, 0);
   Racer_SetIconColorByDifficulty(var19, L[0].v0.v4.v775);
   Racer_SetIconColorByDifficulty(var20, L[0].v0.v4.v775);
   Racer_SetUIDAndCharacterName(var19, 460, mcCareer_GetHookmanCharacterSet(mcCharacterConfigData_GetName(var11)));
   Racer_SetUIDAndCharacterName(var20, 461, mcCareer_GetHookmanCharacterSet(mcCharacterConfigData_GetName(var11)));
   mcHudMapServer_SetVehicleElement(L[0].v0.v4.v1[1 * 48].v4, 8, var19);
   mcHudMapServer_SetColorByDifficulty(L[0].v0.v4.v1[1 * 48].v4, L[0].v0.v4.v775);
   mcHudMapServer_SetVehicleElement(L[0].v0.v4.v1[2 * 48].v4, 8, var20);
   mcHudMapServer_SetColorByDifficulty(L[0].v0.v4.v1[2 * 48].v4, L[0].v0.v4.v775);
   WAITUNWARPED(2000);
   strcpy(&var21, 64, "");
   var37 = 0;
   var38 = UIManager_GetState("Payback_RESULTS");
   SetExceptionMask(3);
   var39 = ;
   switch (var39)
   {
       case -1:
       {
           break;
       }
       case 1:
       {
           PRINTSTRING("Shutdown exception\n");
           break;
       }
       case 2:
       {
           PRINTSTRING("restart exception\n");
           break;
       }
       case 3:
       {
           PRINTSTRING("network session termination exception\n");
           break;
       }
       default:
       {
           PRINTSTRING("Unhandled exception: ");
           PRINTINT(var39);
           PRINTSTRING("\n");
           while (var3)
           {
               while (!Warper_IsReadyToLoadStuff())
               {
                   WAITUNWARPED(100);
                   PRINTSTRING("Waiting\n");
               }
               Warper_Warp("USER_WAIT_NO_CUT_DOWN");
               var3 = 0;
           }
           sub_6d5(&L[0], var8, var38, var13);
           PRINTSTRING("Outside of RunPayBack");
           Registry_GetValueInt("raceOverTrigger", &var37);
           while (var37 == 0)
           {
               Registry_GetValueInt("raceOverTrigger", &var37);
               WAITUNWARPED(100);
           }
           AudioManager_SetActiveEndRace(0, 0);
           Registry_GetValueString("raceOverCommand", &var21);
           if (StringCompare(&var21, "restart"))
           {
               Warper_Warp("USER_WAIT_NO_CUT_UP");
               while (!Warper_IsReadyToLoadStuff())
               {
                   WAITUNWARPED(100);
                   PRINTSTRING("Waiting Restart Race\n");
               }
               sub_1f11();
               var3 = 1;
               Racer_InitializeResetPosition(var4, &(L[0].v805), L[0].v808);
               Racer_Reset(var4);
               Racer_Activate(var4);
           }
           break;
       }
   }
   PRINTSTRING("Outside of SHUTDOWN");
   Racer_InitializeResetPosition(var4, &(L[0].v805), L[0].v808);
   Warper_Warp("USER_WAIT_NO_CUT_UP");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting Shutdown Race\n");
   }
   while (UIManager_IsSaving())
   {
       WAITUNWARPED(100);
   }
   MessageBox_ShowLoadingBox("Career_Loading");
   Racer_Reset(var4);
   Racer_InitializeResetPosition(var4, &(L[0].v805), L[0].v808);
   if (var6)
   {
       PRINTSTRING("|Changeing back to old car|");
       UILogic_ResumeGame();
       Racer_ChangeCarByConfig(var4, LocalOptions_GetVehicleProfile(var5));
       WAITUNWARPED(2000);
       while (!Racer_IsVinylStreamed(var4))
       {
           WAITUNWARPED(100);
       }
   }
   MessageBox_HideLoadingBox("Career_Loading");
   Warper_Warp("USER_WAIT_NO_CUT_DOWN");
   mcHudMapServer_DeleteElement(L[0].v0.v4.v1[1 * 48].v4);
   OpponentManager_RemoveOpponentFromWorld(var9);
   OpponentManager_DeleteOpponent(var9);
   OpponentManager_RemoveOpponentFromWorld(var10);
   OpponentManager_DeleteOpponent(var10);
   mcCarConfig_Destroy(var2);
   mcRaceArray_Destroy(var8);
}

void sub_6d5(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92;

   var6 = LookupCity(GetCurrentCity());
   var7 = mcMissionManager_GetMission("PAYBACK_GH_18");
   var8 = -1;
   var9 = 0;
   var10 = 0;
   var11 = HUD_GetHUDCtrl(10);
   var12 = 0;
   var13 = 0;
   var14 = 0;
   var15 = 0;
   var16 = 12;
   var29 = 5;
   var35 = 0;
   var36 = 1;
   Racer_SetDamageInflictedFactor((*(((var0 + 0) + 16) + 4))[0 * 48].v0, (*(var0 + 3388))[*(((var0 + 0) + 16) + 3100)]);
   Racer_SetDamageMultiplierFlag((*(((var0 + 0) + 16) + 4))[0 * 48].v0, 32);
   Racer_SetDamageInflictedFactor((*(((var0 + 0) + 16) + 4))[1 * 48].v0, 0.65f);
   Racer_Activate((*(((var0 + 0) + 16) + 4))[0 * 48].v0);
   Registry_SetValueInt("nPlayerCaught", 0);
   var37 = vhsmState_GetDataInt(var2, "nPaybackNeededWins");
   PropertyCtrl_SetPropertyInt(var11, 1, 0);
   PropertyCtrl_SetPropertyInt(var11, 2, var37);
   PropertyCtrl_SetPropertyFloat(var11, 4, (*(var0 + 3368))[*(((var0 + 0) + 16) + 3100)]);
   while (!var10)
   {
       if (var3)
       {
           var14 = sub_848(&var16, 12, var12);
           var15 = sub_848(&var29, 5, var13);
           var16[var14] = 1;
           var29[var15] = 1;
           var12 = var12 + 1;
           var13 = var13 + 1;
           if (var12 >= 12)
           {
               sub_8e4(&var16, 12);
               var12 = 1;
               var16[var14] = 1;
           }
           if (var12 >= 5)
           {
               sub_8e4(&var29, 5);
               var13 = 1;
               var29[var15] = 1;
           }
           sub_944(&var16, 12);
           if (var35)
           {
               mcHudMapServer_RemoveElement((*(((var0 + 0) + 16) + 4))[1 * 48].v4);
               PRINTSTRING("saveing off the damaged racer to the 2nd index");
               var38.v0 = (*(((var0 + 0) + 16) + 4))[1 * 48].v0;
               var38.v1 = (*(((var0 + 0) + 16) + 4))[1 * 48].v1;
               var38.v2 = (*(((var0 + 0) + 16) + 4))[1 * 48].v2;
               var38.v3 = (*(((var0 + 0) + 16) + 4))[1 * 48].v3;
               var38.v4 = (*(((var0 + 0) + 16) + 4))[1 * 48].v4;
               var38.v5 = (*(((var0 + 0) + 16) + 4))[1 * 48].v5;
               var38.v6 = (*(((var0 + 0) + 16) + 4))[1 * 48].v6;
               var38.v7 = (*(((var0 + 0) + 16) + 4))[1 * 48].v7;
               var38.v8 = (*(((var0 + 0) + 16) + 4))[1 * 48].v8;
               var38.v9 = (*(((var0 + 0) + 16) + 4))[1 * 48].v9;
               var38.v10 = (*(((var0 + 0) + 16) + 4))[1 * 48].v10;
               var38.v11 = (*(((var0 + 0) + 16) + 4))[1 * 48].v11;
               var38.v12 = (*(((var0 + 0) + 16) + 4))[1 * 48].v12;
               var38.v13 = (*(((var0 + 0) + 16) + 4))[1 * 48].v13;
               var38.v14 = (*(((var0 + 0) + 16) + 4))[1 * 48].v14;
               var38.v15 = (*(((var0 + 0) + 16) + 4))[1 * 48].v15;
               var38.v16 = (*(((var0 + 0) + 16) + 4))[1 * 48].v16;
               var38.v17 = (*(((var0 + 0) + 16) + 4))[1 * 48].v17;
               var38.v18 = (*(((var0 + 0) + 16) + 4))[1 * 48].v18;
               var38.v19 = (*(((var0 + 0) + 16) + 4))[1 * 48].v19;
               var38.v20 = (*(((var0 + 0) + 16) + 4))[1 * 48].v20;
               var38.v21 = (*(((var0 + 0) + 16) + 4))[1 * 48].v21;
               var38.v22 = (*(((var0 + 0) + 16) + 4))[1 * 48].v22;
               var38.v23 = (*(((var0 + 0) + 16) + 4))[1 * 48].v23;
               var38.v24 = (*(((var0 + 0) + 16) + 4))[1 * 48].v24;
               var38.v25 = (*(((var0 + 0) + 16) + 4))[1 * 48].v25;
               var38.v26 = (*(((var0 + 0) + 16) + 4))[1 * 48].v26;
               var38.v27 = (*(((var0 + 0) + 16) + 4))[1 * 48].v27;
               var38.v28 = (*(((var0 + 0) + 16) + 4))[1 * 48].v28;
               var38.v29 = (*(((var0 + 0) + 16) + 4))[1 * 48].v29;
               var38.v30 = (*(((var0 + 0) + 16) + 4))[1 * 48].v30;
               var38.v31 = (*(((var0 + 0) + 16) + 4))[1 * 48].v31;
               var38.v32 = (*(((var0 + 0) + 16) + 4))[1 * 48].v32;
               var38.v33 = (*(((var0 + 0) + 16) + 4))[1 * 48].v33;
               var38.v34 = (*(((var0 + 0) + 16) + 4))[1 * 48].v34;
               var38.v35 = (*(((var0 + 0) + 16) + 4))[1 * 48].v35;
               var38.v36 = (*(((var0 + 0) + 16) + 4))[1 * 48].v36;
               var38.v37 = (*(((var0 + 0) + 16) + 4))[1 * 48].v37;
               var38.v38 = (*(((var0 + 0) + 16) + 4))[1 * 48].v38;
               var38.v39 = (*(((var0 + 0) + 16) + 4))[1 * 48].v39;
               var38.v40 = (*(((var0 + 0) + 16) + 4))[1 * 48].v40;
               var38.v41 = (*(((var0 + 0) + 16) + 4))[1 * 48].v41;
               var38.v42 = (*(((var0 + 0) + 16) + 4))[1 * 48].v42;
               var38.v43 = (*(((var0 + 0) + 16) + 4))[1 * 48].v43;
               var38.v44 = (*(((var0 + 0) + 16) + 4))[1 * 48].v44;
               var38.v45 = (*(((var0 + 0) + 16) + 4))[1 * 48].v45;
               var38.v46 = (*(((var0 + 0) + 16) + 4))[1 * 48].v46;
               var38.v47 = (*(((var0 + 0) + 16) + 4))[1 * 48].v47;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v0 = (*(((var0 + 0) + 16) + 4))[2 * 48].v0;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v1 = (*(((var0 + 0) + 16) + 4))[2 * 48].v1;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v2 = (*(((var0 + 0) + 16) + 4))[2 * 48].v2;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v3 = (*(((var0 + 0) + 16) + 4))[2 * 48].v3;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v4 = (*(((var0 + 0) + 16) + 4))[2 * 48].v4;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v5 = (*(((var0 + 0) + 16) + 4))[2 * 48].v5;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v6 = (*(((var0 + 0) + 16) + 4))[2 * 48].v6;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v7 = (*(((var0 + 0) + 16) + 4))[2 * 48].v7;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v8 = (*(((var0 + 0) + 16) + 4))[2 * 48].v8;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v9 = (*(((var0 + 0) + 16) + 4))[2 * 48].v9;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v10 = (*(((var0 + 0) + 16) + 4))[2 * 48].v10;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v11 = (*(((var0 + 0) + 16) + 4))[2 * 48].v11;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v12 = (*(((var0 + 0) + 16) + 4))[2 * 48].v12;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v13 = (*(((var0 + 0) + 16) + 4))[2 * 48].v13;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v14 = (*(((var0 + 0) + 16) + 4))[2 * 48].v14;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v15 = (*(((var0 + 0) + 16) + 4))[2 * 48].v15;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v16 = (*(((var0 + 0) + 16) + 4))[2 * 48].v16;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v17 = (*(((var0 + 0) + 16) + 4))[2 * 48].v17;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v18 = (*(((var0 + 0) + 16) + 4))[2 * 48].v18;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v19 = (*(((var0 + 0) + 16) + 4))[2 * 48].v19;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v20 = (*(((var0 + 0) + 16) + 4))[2 * 48].v20;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v21 = (*(((var0 + 0) + 16) + 4))[2 * 48].v21;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v22 = (*(((var0 + 0) + 16) + 4))[2 * 48].v22;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v23 = (*(((var0 + 0) + 16) + 4))[2 * 48].v23;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v24 = (*(((var0 + 0) + 16) + 4))[2 * 48].v24;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v25 = (*(((var0 + 0) + 16) + 4))[2 * 48].v25;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v26 = (*(((var0 + 0) + 16) + 4))[2 * 48].v26;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v27 = (*(((var0 + 0) + 16) + 4))[2 * 48].v27;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v28 = (*(((var0 + 0) + 16) + 4))[2 * 48].v28;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v29 = (*(((var0 + 0) + 16) + 4))[2 * 48].v29;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v30 = (*(((var0 + 0) + 16) + 4))[2 * 48].v30;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v31 = (*(((var0 + 0) + 16) + 4))[2 * 48].v31;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v32 = (*(((var0 + 0) + 16) + 4))[2 * 48].v32;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v33 = (*(((var0 + 0) + 16) + 4))[2 * 48].v33;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v34 = (*(((var0 + 0) + 16) + 4))[2 * 48].v34;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v35 = (*(((var0 + 0) + 16) + 4))[2 * 48].v35;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v36 = (*(((var0 + 0) + 16) + 4))[2 * 48].v36;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v37 = (*(((var0 + 0) + 16) + 4))[2 * 48].v37;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v38 = (*(((var0 + 0) + 16) + 4))[2 * 48].v38;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v39 = (*(((var0 + 0) + 16) + 4))[2 * 48].v39;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v40 = (*(((var0 + 0) + 16) + 4))[2 * 48].v40;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v41 = (*(((var0 + 0) + 16) + 4))[2 * 48].v41;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v42 = (*(((var0 + 0) + 16) + 4))[2 * 48].v42;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v43 = (*(((var0 + 0) + 16) + 4))[2 * 48].v43;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v44 = (*(((var0 + 0) + 16) + 4))[2 * 48].v44;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v45 = (*(((var0 + 0) + 16) + 4))[2 * 48].v45;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v46 = (*(((var0 + 0) + 16) + 4))[2 * 48].v46;
               (*(((var0 + 0) + 16) + 4))[1 * 48].v47 = (*(((var0 + 0) + 16) + 4))[2 * 48].v47;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v0 = var38.v0;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v1 = var38.v1;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v2 = var38.v2;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v3 = var38.v3;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v4 = var38.v4;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v5 = var38.v5;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v6 = var38.v6;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v7 = var38.v7;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v8 = var38.v8;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v9 = var38.v9;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v10 = var38.v10;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v11 = var38.v11;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v12 = var38.v12;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v13 = var38.v13;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v14 = var38.v14;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v15 = var38.v15;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v16 = var38.v16;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v17 = var38.v17;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v18 = var38.v18;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v19 = var38.v19;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v20 = var38.v20;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v21 = var38.v21;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v22 = var38.v22;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v23 = var38.v23;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v24 = var38.v24;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v25 = var38.v25;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v26 = var38.v26;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v27 = var38.v27;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v28 = var38.v28;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v29 = var38.v29;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v30 = var38.v30;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v31 = var38.v31;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v32 = var38.v32;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v33 = var38.v33;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v34 = var38.v34;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v35 = var38.v35;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v36 = var38.v36;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v37 = var38.v37;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v38 = var38.v38;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v39 = var38.v39;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v40 = var38.v40;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v41 = var38.v41;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v42 = var38.v42;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v43 = var38.v43;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v44 = var38.v44;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v45 = var38.v45;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v46 = var38.v46;
               (*(((var0 + 0) + 16) + 4))[2 * 48].v47 = var38.v47;
           }
           sub_944(&var29, 5);
           PRINTSTRING("Change Car!");
           Racer_ChangeCar((*(((var0 + 0) + 16) + 4))[1 * 48].v0, (*(var0 + 3292))[var14]);
           Racer_SetModValue((*(((var0 + 0) + 16) + 4))[1 * 48].v0, 0);
           Racer_SetCharacterName((*(((var0 + 0) + 16) + 4))[1 * 48].v0, (*(var0 + 3240))[var15]);
       }
       mcRaceArray_SortByDistance(var1, (*(((var0 + 0) + 16) + 4))[0 * 48].v0);
       if (mcMission_GetState(var7) == 3)
       {
           *(((var0 + 0) + 16) + 0) = CityDescription_GetRaceIndexByName(var6, "game/Race/Downtown/Payback/dt_payback_ds_02");
       }
       else
       {
           *(((var0 + 0) + 16) + 0) = mcRaceArray_FindNextRaceIndex(var1);
       }
       mcCareer_AddRaceToHistory(*(((var0 + 0) + 16) + 0));
       Race_Reset(*((var0 + 0) + 12));
       var86 = START_NEW_SCRIPT_WITH_ARGS(CityDescription_GetRaceNameByIndex(var6, *(((var0 + 0) + 16) + 0)), var0 + 0, 802, 3800);
       while (!IsChildFinished(var86))
       {
           WAITUNWARPED(100);
       }
       Registry_GetValueInt("raceOverTrigger", &var9);
       if (var9 == 0)
       {
           UIManager_SendEvent("calculateResults");
           var87 = vhsmState_GetDataInt(var2, "nPaybackCurrentWins");
           PRINTSTRING("PAYBACK LEG SUMMARY \n Current Wins: ");
           PRINTINT(var87);
           PRINTSTRING("\n Needed Wins: ");
           PRINTINT(var37);
           PRINTSTRING("\n");
           PropertyCtrl_SetPropertyInt(var11, 1, var87);
           var88 = 0;
           Registry_GetValueInt("nPlayerCaught", &var88);
           if (var87 == var37)
           {
               mcEvent_PostEventStr("PAYBACK_COMPLETE", *(var0 + 3208));
               var10 = 1;
           }
           else if ((var88 == 1) || Race_IsDamagedOut(*((var0 + 0) + 12)))
           {
               var10 = 1;
           }
           if (var10)
           {
               sub_d5d(1, 1, 0x3f800000, 0);
               sub_108d(var0 + 0, 0, 1, 1);
               UIManager_SendEvent("raceEnd");
           }
       }
       else
       {
           var10 = 1;
       }
       if (!var10)
       {
           var35 = 1;
       }
       else
       {
           var35 = 0;
       }
   }
   Registry_SetValueInt("nPlayerCaught", 0);
}

function sub_848(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9;

   var5 = RAND_INT_RANGE(0, (var1 - var2) - 1);
   var6 = 0;
   while (var6 < var1)
   {
       if (!(*var0)[var6])
       {
           if (var5 <= 0)
           {
               return var6;
           }
           else
           {
               var5 = var5 - 1;
           }
       }
       var6 = var6 + 1;
   }
   return 0;
}

void sub_8e4(var0, var1)
{
   auto var4, var5, var6;

   var4 = 0;
   while (var4 < var1)
   {
       (*var0)[var4] = 0;
       var4 = var4 + 1;
   }
}

void sub_944(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("Vehicle used summary:\n");
   var4 = 0;
   while (var4 < var1)
   {
       PRINTSTRING("Vehicle ");
       PRINTINT(var4);
       PRINTSTRING(" = ");
       if ((*var0)[var4])
       {
           PRINTSTRING("USED\n");
       }
       else
       {
           PRINTSTRING("UNUSED\n");
       }
       var4 = var4 + 1;
   }
}

void sub_d5d(var0, var1, var2, var3)
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

void sub_108d(var0, var1, var2, var3)
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
                   sub_1cc9(var28[0], var68);
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

void sub_1cc9(var0, var1)
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

void sub_1f11()
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

