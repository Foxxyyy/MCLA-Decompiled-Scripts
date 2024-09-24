void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95;

   PRINTSTRING("[mrb] Running my version of OrderedCheckpointCore.sco!");
   if ((Net_IsConnecting() || Net_IsNetworked()) && (!L[0].v4.v780))
   {
       return;
   }
   else
   {
       var2 = AmbientMgr_GetTrafficEnable();
       if (!L[0].v4.v780)
       {
           sub_85(&L[0]);
       }
       Race_SetRaceData(L[0].v3, &(L[0].v4));
       Race_LoadAmbientPathArray(L[0].v3, L[0].v0);
       var3 = LookupCity(GetCurrentCity());
       if (L[0].v4.v779 == 0)
       {
           if (!(L[0].v4.v0 == -1))
           {
               var4 = CityDescription_LookupRaceByIndex(var3, L[0].v4.v0);
               L[0].v4.v779 = RaceDescription_GetDefaultNumLaps(var4);
           }
           else
           {
               L[0].v4.v779 = 1;
           }
       }
       Registry_SetValueString("raceName", CityDescription_GetRaceNameByIndex(var3, L[0].v4.v0));
       PoliceManager_CurrentRaceLapChanged(0);
       Graphics_SetShadowDisable(1);
       var5 = Race_GetCheckpointList(L[0].v3);
       CheckpointManager_SetActiveCheckpointList(var5);
       var6 = 64;
       var75 = null;
       var76 = CheckpointList_GetListCount(var5);
       var71 = 0;
       while (var71 < var76)
       {
           var75 = CheckpointList_GetCheckpoint(var5, var71);
           var6[var71] = mcHudMapServer_CreateElement();
           Checkpoint_GetPosition(var75, &var72);
           mcHudMapServer_SetElement(var6[var71], 0, 0, &var72, (float)0);
           var71 = var71 + 1;
       }
       var77 = null;
       if (EventOptions_IsPowerUps(L[0].v4.v790))
       {
           PRINTSTRING("Script: Powerups are on -- ");
           if (L[0].v2 == null)
           {
               PRINTSTRING("Initializing from checkpoints\n");
               var77 = PickUpManager_CreatePowerUpSourcesFromCheckPoints(var5, 1);
               PickUpManager_PowerUpSourcePostInit(var77);
           }
           else
           {
               PRINTSTRING(" Initializing from manually placed locations\n");
               PickUpManager_PowerUpSourcePostInit(L[0].v2);
           }
       }
       sub_466(&L[0]);
       if (!L[0].v4.v780)
       {
           var78 = 0;
           Registry_GetValueInt("replaying", &var78);
           PRINTSTRING("REPLAY VALUE ");
           PRINTINT(var78);
           PRINTSTRING("\n");
           L[0].v4.v786 = var78 != 0;
           Registry_SetValueInt("replaying", 0);
           RubberBandMgr_SetupRace(L[0].v4.v775, 0, L[0].v4.v786);
       }
       SetExceptionMask(3);
       var79 = ;
       switch (var79)
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
               PoliceManager_EvaluateCopZones();
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
               PRINTINT(var79);
               PRINTSTRING("\n");
               if (L[0].v4.v780 && (!Net_IsCruiseMode()))
               {
                   PRINTSTRING("Script: OrderedCheckpointCore.sc: Disabling traffic for pre-race countdown\n");
                   if (AmbientMgr_GetTrafficEnable())
                   {
                       AmbientMgr_SetTrafficEnable(0);
                   }
               }
               Registry_SetValueInt("raceOverTrigger", 0);
               Registry_SetValueString("raceOverCommand", "");
               TriggerManager_ResetTriggers();
               PropManager_ResetProps();
               PickUpManager_OnRaceReset();
               sub_75b(&(L[0].v4), var76, &var6);
               sub_8c5(&(L[0].v4));
               if (!L[0].v4.v780)
               {
                   Notify(0);
               }
               Race_SetRaceData(L[0].v3, &(L[0].v4));
               sub_a17(&L[0]);
               sub_eeb(&L[0], var5);
               sub_14dc(&L[0]);
               if (L[0].v4.v780)
               {
                   PRINTSTRING("Script: OrderedCheckpointCore.sc: Pre-race countdown ended, switching to the selected traffic level\n");
                   sub_85(&L[0]);
               }
               sub_16af(&L[0], var76, &var6);
               if ((!L[0].v4.v780) && (!ReplayMgr_GetFinishedRace()))
               {
                   Form_CloseForm(Form_GetForm(72));
                   strcpy(&var80, 64, "");
                   Registry_GetValueString("raceOverCommand", &var80);
                   if (StringCaseCompare(&var80, "showRaceOverDialog"))
                   {
                       Registry_SetValueInt("raceOverTrigger", 0);
                       sub_367a();
                       ReplayMgr_End(1);
                       sub_36f9();
                       Racer_Activate(Player_FindRacerObject(0));
                   }
                   else if (StringCaseCompare(&var80, "quit"))
                   {
                       ReplayMgr_End(0);
                       Racer_Activate(Player_FindRacerObject(0));
                   }
                   else if (!L[0].v4.v786)
                   {
                       ReplayMgr_End(1);
                   }
                   Notify(1);
               }
               break;
           }
       }
       if (!L[0].v4.v780)
       {
           RubberBandMgr_ShutdownRace();
       }
       var71 = 0;
       while (var71 < L[0].v4.v770)
       {
           if (L[0].v4.v1[var71 * 48].v2 == 0)
           {
               if (L[0].v4.v780 && (!Racer_IsDamagedOut(L[0].v4.v1[var71 * 48].v0)))
               {
                   Racer_Activate(L[0].v4.v1[var71 * 48].v0);
               }
               UILogic_RemoveGPSDestination(var71);
           }
           var71 = var71 + 1;
       }
       Graphics_SetShadowDisable(0);
       if (var77 != null)
       {
           PickUpManager_DeletePowerUpSources(var77);
           var77 = null;
       }
       if (L[0].v2 != null)
       {
           PickUpManager_DeletePowerUpSources(L[0].v2);
           L[0].v2 = null;
       }
       Race_UnloadAmbientPathArray(L[0].v3);
       Race_SetRaceData(L[0].v3, &(L[0].v4));
       var71 = 0;
       while (var71 < var76)
       {
           mcHudMapServer_DeleteElement(var6[var71]);
           var71 = var71 + 1;
       }
       CheckpointManager_ClearActiveCheckpointList();
       if (var2 != AmbientMgr_GetTrafficEnable())
       {
           PRINTSTRING("Script: OrderedCheckpointCore.sc: Restoring original traffic setting (end of race)\n");
           AmbientMgr_SetTrafficEnable(var2);
       }
       SetExceptionMask(0);
       ThrowRecursive(1);
       return;
   }
}

void sub_85(var0)
{
   auto var3;

   if (*((var0 + 16) + 3160) != null)
   {
       if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) == 0)
       {
           PRINTSTRING("Script: OrderedCheckpointCore.sc: SetTrafficLevelFromOptions - Traffic is Disabled\n");
           if (AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(0);
           }
       }
       else if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) > 0)
       {
           PRINTSTRING("Script: OrderedCheckpointCore.sc: SetTrafficLevelFromOptions - Traffic is Enabled\n");
           if (!AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(1);
           }
       }
   }
   else
   {
       PRINTSTRING("Script: OrderedCheckpointCore.sc: SetTrafficLevelFromOptions - EventOptions is NULL (is this career?)\n");
   }
}

void sub_466(var0)
{
   auto var3, var4;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v41 = 0;
       var3 = var3 + 1;
   }
   if (*(var0 + 12) != null)
   {
       Race_SetRaceData(*(var0 + 12), var0 + 16);
   }
}

void sub_75b(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   sub_76f(var1, var2, *(var0 + 3116));
   var5 = 0;
   while (var5 < *(var0 + 3080))
   {
       sub_824(&((*(var0 + 4))[var5 * 48]), var5, 0, var1, *(var0 + 3116));
       var5 = var5 + 1;
   }
}

void sub_76f(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = 0;
   while (var5 < var0)
   {
       mcHudMapServer_AddElement((*var1)[var5]);
       mcHudMapServer_SetMutExSubtype((*var1)[var5], 3);
       var5 = var5 + 1;
   }
   if (var0 > 1)
   {
       mcHudMapServer_SetMutExSubtype((*var1)[0], 1);
   }
   if (var2 <= 1)
   {
       mcHudMapServer_SetMutExSubtype((*var1)[var0 - 1], 5);
   }
   else
   {
       mcHudMapServer_SetMutExSubtype((*var1)[var0 - 1], 4);
   }
}

void sub_824(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   if (*(var0 + 8) == 0)
   {
       var7 = CheckpointManager_GetCheckpoint(var2);
       Checkpoint_GetPosition(var7, &var8);
       UILogic_SetGPSDestination(var1, &var8);
   }
   var11 = 0;
   if (var3 <= 1)
   {
       var11 = 17;
   }
   else if (var2 >= (var3 - 1))
   {
       if (*(var0 + 28) >= (var4 - 1))
       {
           var11 = 2;
       }
       else
       {
           var11 = 3;
       }
   }
   CheckpointManager_ActivateSingleCheckpoint(var1, var2, var11);
}

void sub_8c5(var0)
{
   auto var3, var4;

   if (*(var0 + 3120))
   {
       PRINTSTRING("Script: NETWORKED!\n");
   }
   else
   {
       PRINTSTRING("Script: OFFLINE!\n");
   }
   var3 = 0;
   while (var3 <= (*(var0 + 3080) - 1))
   {
       PRINTSTRING("Script: Racer #");
       PRINTINT(var3);
       PRINTSTRING(": ");
       if ((*(var0 + 4))[var3 * 48].v2 == 0)
       {
           PRINTSTRING("LOCAL PLAYER\n");
       }
       else if ((*(var0 + 4))[var3 * 48].v2 == 1)
       {
           PRINTSTRING("REMOTE PLAYER\n");
       }
       else if ((*(var0 + 4))[var3 * 48].v2 == 2)
       {
           PRINTSTRING("AI\n");
       }
       var3 = var3 + 1;
   }
}

void sub_a17(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52;

   PRINTSTRING("CORE INFO\n");
   PRINTSTRING("Num Racers");
   PRINTINT(*((var0 + 16) + 3080));
   PRINTSTRING("\n");
   sub_a65(var0);
   PerspectiveForm_SetSlowMotion(Form_GetForm(60), 1.0f, 0.0f, 0, 0, 1.0f);
   var4.v9 = 15;
   var4.v9.v25 = 15;
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var4.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var4.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var4.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var4.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var4.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var4.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var4.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var4.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var4.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var4.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var4.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var4.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var4.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var4.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var4.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var4.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var4.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var4.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var4.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var4.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var4.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var4.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var4.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var4.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var4.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var4.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var4.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var4.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var4.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var4.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var4.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var4.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var4.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var4.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var4.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var4.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var4.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var4.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var4.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var4.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var4.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var4.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var4.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var4.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var4.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var4.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var4.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var4.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       if (var4.v2 == 2)
       {
           mcHudMapServer_AddElement(var4.v4);
       }
       Racer_SetInvincible(var4.v0, 0);
       var3 = var3 + 1;
   }
}

void sub_a65(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61;

   AmbientMgr_Reset();
   var9.v9 = 15;
   var9.v9.v25 = 15;
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var9.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var9.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var9.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var9.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var9.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var9.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var9.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var9.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var9.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var9.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var9.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var9.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var9.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var9.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var9.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var9.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var9.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var9.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var9.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var9.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var9.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var9.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var9.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var9.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var9.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var9.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var9.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var9.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var9.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var9.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var9.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var9.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var9.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var9.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var9.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var9.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var9.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var9.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var9.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var9.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var9.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var9.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var9.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var9.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var9.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var9.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var9.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var9.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       if (*((var0 + 16) + 3120))
       {
           var4 = Net_GetRacerGridIndex(var9.v0);
       }
       else
       {
           var4 = var3;
       }
       RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), var4, &var5, &var8);
       if (Racer_IsMotorcycle(var9.v0))
       {
           var57.v0 = 0.8f;
           var57.v1 = 0.0f;
           var57.v2 = 0.0f;
           Math_VecRotateY(&var57, &var57, var8);
           var5.v0 = var57.v0 + var5.v0;
           var5.v1 = var57.v1 + var5.v1;
           var5.v2 = var57.v2 + var5.v2;
       }
       PRINTSTRING("Opponent: ");
       PRINTINT(var3);
       PRINTSTRING(" - INFO\n");
       PRINTSTRING("Opponent: Racer name = ");
       PRINTSTRING(Racer_GetName(var9.v0));
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Car name = ");
       PRINTSTRING(mcCarConfig_GetVehicleTypeName(Racer_GetCarConfig(var9.v0)));
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Mod value = ");
       PRINTINT(Racer_GetModValue(var9.v0));
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Estimated Mod value = ");
       PRINTINT(Racer_GetEstimatedModValue(var9.v0));
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Performance value = ");
       PRINTFLOAT(Racer_GetPerformanceValue(var9.v0));
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Grid pos = ");
       PRINTVECTOR(var5.v0, var5.v1, var5.v2);
       PRINTSTRING("\n");
       PRINTSTRING("Opponent: Grid rot = ");
       PRINTFLOAT(var8);
       PRINTSTRING("\n");
       PRINTSTRING("\n");
       Racer_InitializeResetPosition(var9.v0, &var5, var8);
       if (var9.v2 == 2)
       {
           Racer_QuickFix(var9.v0);
           Racer_ResetWithDamageIntact(var9.v0);
       }
       else
       {
           if ((*((var0 + 16) + 3120) && Racer_IsLocalPlayer(var9.v0)) && Racer_IsDamagedOut(var9.v0))
           {
               PRINTSTRING("SCRIPT: QuickFixing damaged out local racer before starting race...\n");
               Racer_QuickFix(var9.v0);
           }
           else
           {
               Racer_ResetWithDamageIntact(var9.v0);
           }
           Registry_GetValueInt("revertDamage", &var60);
           if (var60 == 1)
           {
               UILogic_RevertCarDamage();
               Registry_SetValueInt("revertDamage", 0);
           }
       }
       Racer_PreRaceBurnout(var9.v0);
       var3 = var3 + 1;
   }
}

void sub_eeb(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79;

   Race_EnableRaceTimer(*(var0 + 12), 0);
   Race_SetTimer(*(var0 + 12), -60000);
   PRINTSTRING("Playing Starter Cutscene ");
   PRINTSTRING(*(var0 + 3196));
   PRINTSTRING("\n");
   sub_f50(var0);
   var4 = START_NEW_SCRIPT(*(var0 + 3196), 0);
   while (!Race_IsRaceTimerEnabled(*(var0 + 12)))
   {
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       if ((*((var0 + 16) + 3100) != 0) || (var6.v2 != 2))
       {
           Racer_LockFeature(var6.v0, 8, 0);
       }
       else
       {
           Racer_LockFeature(var6.v0, 8, 1);
       }
       var5 = var5 + 1;
   }
   if (!*((var0 + 16) + 3120))
   {
       ReplayMgr_Begin(*((var0 + 16) + 3144));
       RAND_RESET();
   }
   else
   {
       AmbientMgr_FullReset();
   }
   var54 = 0;
   var55 = 16;
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       DebugReplay(2000 + var5);
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       if (var6.v2 == 2)
       {
           BrainRacing_Reset(var6.v3);
           BrainRacing_SetupRace(var6.v3, var1, var5, *((var0 + 16) + 3116), *((var0 + 16) + 3100));
           var72.v0 = (float)0;
           var72.v1 = (float)0;
           var72.v2 = (float)0;
           BrainRacing_SetFinalHeading(var6.v3, &var72);
           BrainRacing_SetFinalSpeed(var6.v3, (float)-1);
           BrainRacing_SetRevvingEnabled(var6.v3, 1);
           BrainRacing_SetHoldStill(var6.v3, 0);
           if (*((var0 + 16) + 3100) != 0)
           {
               Racer_PreRaceBurnout(var6.v0);
           }
           else
           {
               Racer_Deactivate(var6.v0);
           }
           var55[var54] = var6.v3;
           var54 = var54 + 1;
       }
       else
       {
           Racer_PreRaceBurnout(var6.v0);
       }
       var5 = var5 + 1;
   }
   var75 = var54 / 2;
   if ((var75 == 0) && (var54 > 0))
   {
       var75 = 1;
   }
   var5 = 0;
   while (var5 < var75)
   {
       var76 = RAND_INT_RANGE(0, var54 - 1);
       BrainRacing_SetRevvingHandbrake(var55[var76], 1);
       var54 = var54 - 1;
       var55[var76] = var55[var54];
       var5 = var5 + 1;
   }
   var77 = 0;
   while ((Race_GetTimer(*(var0 + 12)) < -3000) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2100);
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       DebugReplay(2125 + var5);
       if ((var6.v2 == 2) && (*((var0 + 16) + 3100) != 0))
       {
           BrainRacing_SetRevvingHandbrake(var6.v3, 1);
       }
       var5 = var5 + 1;
   }
   while ((Race_GetTimer(*(var0 + 12)) < -1000) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2150);
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       DebugReplay(2200 + var5);
       if ((var6.v2 == 2) && (*((var0 + 16) + 3100) != 0))
       {
           BrainRacing_SetRevvingEnabled(var6.v3, 0);
       }
       var5 = var5 + 1;
   }
   while ((Race_GetTimer(*(var0 + 12)) < 0) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2300);
       WAITUNWARPED(10);
   }
   if ((!*((var0 + 16) + 3120)) && *((var0 + 16) + 3144))
   {
       Form_ShowForm(Form_GetForm(-1), Form_GetForm(72));
   }
}

void sub_f50(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9;

   RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), 0, &(var3.v2.v0), &(var3.v2.v3));
   CineScript_SetGameCoordSysBinding(&var3);
   sub_f82(var0);
}

void sub_f82(var0)
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

void sub_14dc(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54;

   var5 = LookupCity(GetCurrentCity());
   var6.v9 = 15;
   var6.v9.v25 = 15;
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       var4 = 0;
       while (var4 < *((var0 + 16) + 3116))
       {
           (*((var0 + 16) + 4))[var3 * 48].v25[var4] = 0;
           (*((var0 + 16) + 4))[var3 * 48].v9[var4] = 0;
           var4 = var4 + 1;
       }
       DebugReplay(2400 + var3);
       (*((var0 + 16) + 4))[var3 * 48].v8 = 0x7fffffff;
       if (var6.v2 == 2)
       {
           BrainRacing_BeginRace(var6.v3, CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0)));
       }
       Racer_Activate((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var6.v2 == 2)
       {
           BrainRacing_SetRevvingEnabled(var6.v3, 0);
       }
       var3 = var3 + 1;
   }
}

void sub_16af(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39;

   PRINTSTRING("Script: Starting Race...\n");
   var5 = 0;
   var6 = 0;
   if ((((*((var0 + 16) + 3092) != 6) || (*((var0 + 16) + 3092) != 7)) || (*((var0 + 16) + 3092) != 3)) || (*((var0 + 16) + 3092) != 4))
   {
       PRINTSTRING("Script: This race will have Taunts..\n");
       var5 = 1;
       var6 = RAND_INT_RANGE(30000, 40000);
   }
   var7 = *((var0 + 16) + 3080) - 1;
   PRINTSTRING("Number of Opponents is : ");
   PRINTINT(var7);
   PRINTSTRING("\n");
   var8 = -1;
   var9 = 0;
   var10 = EventOptions_IsLastManOut(*((var0 + 16) + 3160));
   if (var10)
   {
       PRINTSTRING("Script: This race is Last Man Out\n");
       if (*((var0 + 16) + 3120))
       {
           Net_SetRacerToEliminate(0);
           Net_SetEliminationTimer(-1);
       }
   }
   var11 = UIManager_FindMovie("HUDMOVIE");
   FlashHelper_SetGlobalString(var11, "LapTime", "");
   var12 = 0;
   var13 = 0;
   var14 = 0;
   var15 = 0;
   var16 = 0;
   var18 = -1;
   var19 = null;
   if (Race_IsFinished(*(var0 + 12)))
   {
       PRINTSTRING("Race_IsFinished() is true before the race even started\n");
   }
   var20 = 0;
   var21 = Race_GetTargetTime(*(var0 + 12));
   var22 = 0;
   var23 = 1;
   var24 = HUD_GetHUDCtrl(6);
   var25 = 0;
   var26 = 0;
   var32 = 1;
   var34 = 0;
   var35 = 0;
   var36 = var7;
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   while (!Race_IsFinished(*(var0 + 12)))
   {
       Registry_GetValueInt("raceOverTrigger", &var15);
       if (var15 == 1)
       {
           Race_Finish(*(var0 + 12));
       }
       else
       {
           if ((!var20) && (var21 != 0))
           {
               var22 = var21 - Race_GetTimer(*(var0 + 12));
               if (var22 < 0)
               {
                   var20 = 1;
                   UIManager_SendEvent("raceTimeExpired");
               }
           }
           if (var10)
           {
               var23 = 1;
               if (*((var0 + 16) + 3120))
               {
                   var23 = Net_IsArbiterLocal();
               }
               if (var23)
               {
                   if (var8 == -1)
                   {
                       sub_19ce(var0, &var8, var14, var35);
                   }
                   if (((var8 > 0) && (Race_GetTimerHuman(*(var0 + 12)) > var8)) && (var18 == -1))
                   {
                       var18 = sub_1bf4(var0, var14 + var35);
                   }
               }
               if (*((var0 + 16) + 3120))
               {
                   var8 = Net_GetEliminationTimer();
                   Race_SetTargetTime(*(var0 + 12), var8);
                   var19 = Net_GetRacerToEliminate();
                   if (var19 != null)
                   {
                       var18 = sub_1ced(var0 + 16, var19);
                       var19 = null;
                   }
               }
               if ((var8 > 0) && (!var9))
               {
                   var9 = 1;
                   sub_1d54(var8);
               }
               if (var18 != -1)
               {
                   var8 = -1;
                   PRINTSTRING("IN KILLING BLOCK!!!!!!!!\n");
                   if (*((var0 + 16) + 3120))
                   {
                       PRINTSTRING("RACER TO KILL :");
                       PRINTINT(var18);
                       (*((var0 + 16) + 4))[var18 * 48].v8 = -1;
                       (*((var0 + 16) + 4))[var18 * 48].v41 = *((var0 + 16) + 3080) - (var14 + var35);
                       Net_SetRacerEliminated((*((var0 + 16) + 4))[var18 * 48].v0);
                       PRINTSTRING(" Rank=");
                       PRINTINT((*((var0 + 16) + 4))[var18 * 48].v41);
                       PRINTSTRING("\n");
                       sub_1eb4(var0, var18, &var14, 1);
                       Net_SetRacerToEliminate(0);
                       Net_SetEliminationTimer(-1);
                       Net_MovePlayerToLobby(var18);
                   }
                   else
                   {
                       PRINTSTRING("KIlling RACER NOW - ");
                       PRINTINT(var18);
                       PRINTSTRING("\n");
                       (*((var0 + 16) + 4))[var18 * 48].v8 = -1;
                       sub_1eb4(var0, var18, &var14, 1);
                       if (var18 > 0)
                       {
                           Racer_Deactivate((*((var0 + 16) + 4))[var18 * 48].v0);
                       }
                       if (var18 == 0)
                       {
                           PRINTSTRING("PLAYER LOST, END RACE");
                           Race_Finish(*(var0 + 12));
                           Racer_Activate((*((var0 + 16) + 4))[var18 * 48].v0);
                       }
                   }
                   PropertyCtrl_SetPropertyBool(var24, 2, 0);
                   PropertyCtrl_SetPropertyBool(var24, 0, 0);
                   Ctrl_SetVisible(var24, 1);
                   var9 = 0;
                   var18 = -1;
               }
               if ((var7 - (var14 + var35)) == 0)
               {
                   PRINTSTRING("RACE IS FINISHED");
                   Race_Finish(*(var0 + 12));
                   var14 = 0;
                   var17 = 0;
                   while (var17 < *((var0 + 16) + 3080))
                   {
                       if (*((var0 + 16) + 3120))
                       {
                           if (!Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var17 * 48].v0))
                           {
                               PRINTSTRING("FINISHING OTHER RACERS");
                               PRINTSTRING("\n");
                               if (0x7fffffff == (*((var0 + 16) + 4))[var17 * 48].v8)
                               {
                                   if ((*((var0 + 16) + 4))[var17 * 48].v41 == 1)
                                   {
                                       (*((var0 + 16) + 4))[var17 * 48].v8 = Race_GetTimerHuman(*(var0 + 12));
                                   }
                                   else
                                   {
                                       (*((var0 + 16) + 4))[var17 * 48].v8 = -1;
                                   }
                               }
                               Net_MovePlayerToCar(var17);
                               sub_1eb4(var0, var17, &var14, 0);
                           }
                       }
                       PRINTSTRING("Checking racers finish time : ");
                       PRINTINT(var17);
                       PRINTSTRING("\n");
                       if (0x7fffffff == (*((var0 + 16) + 4))[var17 * 48].v8)
                       {
                           (*((var0 + 16) + 4))[var17 * 48].v8 = -1;
                           sub_1eb4(var0, var17, &var14, 0);
                       }
                       var17 = var17 + 1;
                   }
               }
           }
           var17 = 0;
           while (var17 < *((var0 + 16) + 3080))
           {
               var12 = (*((var0 + 16) + 4))[var17 * 48].v2 == 0;
               var13 = (*((var0 + 16) + 4))[var17 * 48].v2 == 1;
               if (Racer_IsActive((*((var0 + 16) + 4))[var17 * 48].v0))
               {
                   var25 = CheckpointManager_HasHitCheckpoint((*((var0 + 16) + 4))[var17 * 48].v0, var17, (*((var0 + 16) + 4))[var17 * 48].v6);
                   if (var25 || (var12 && mcCareer_ShouldAutoWin()))
                   {
                       CheckpointManager_DeactivateSingleCheckpoint(var17, (*((var0 + 16) + 4))[var17 * 48].v6);
                       PRINTSTRING("Racer ");
                       PRINTINT(var17);
                       PRINTSTRING(" - Hit Checkpoint ");
                       PRINTINT((*((var0 + 16) + 4))[var17 * 48].v6);
                       PRINTSTRING("\n");
                       if ((*((var0 + 16) + 4))[var17 * 48].v2 == 2)
                       {
                           BrainRacing_RecordTime((*((var0 + 16) + 4))[var17 * 48].v3, (*((var0 + 16) + 4))[var17 * 48].v7, (*((var0 + 16) + 4))[var17 * 48].v6, Race_GetTimer(*(var0 + 12)));
                       }
                       (*((var0 + 16) + 4))[var17 * 48].v6 = (*((var0 + 16) + 4))[var17 * 48].v6 + 1;
                       if ((*((var0 + 16) + 4))[var17 * 48].v6 == var1)
                       {
                           PRINTSTRING("Racer ");
                           PRINTINT(var17);
                           PRINTSTRING(" - Finished Lap ");
                           PRINTINT((*((var0 + 16) + 4))[var17 * 48].v7);
                           PRINTSTRING("\n");
                           var26 = (*((var0 + 16) + 4))[var17 * 48].v7;
                           if (var12 || var13)
                           {
                               var27 = Race_GetTimerHuman(*(var0 + 12));
                           }
                           else
                           {
                               var27 = Race_GetTimerAI(*(var0 + 12));
                           }
                           (*((var0 + 16) + 4))[var17 * 48].v9[var26] = var27 - (*((var0 + 16) + 4))[var17 * 48].v25[var26];
                           var32 = (*((var0 + 16) + 4))[var17 * 48].v7 + 1;
                           if (var32 >= *((var0 + 16) + 3116))
                           {
                               if (var12)
                               {
                                   Race_Finish(*(var0 + 12));
                               }
                               if (!var13)
                               {
                                   PRINTSTRING("Racer ");
                                   PRINTINT(var17);
                                   PRINTSTRING("- Finished Race. Time ");
                                   PRINTINT(var27);
                                   PRINTSTRING(" seconds\n");
                                   (*((var0 + 16) + 4))[var17 * 48].v8 = var27;
                                   sub_1eb4(var0, var17, &var14, 0);
                               }
                           }
                           else
                           {
                               if (var12)
                               {
                                   UIManager_FormatRaceClock(&var28, (*((var0 + 16) + 4))[var17 * 48].v9[var26]);
                                   FlashHelper_SetGlobalString(var11, "LapTime", &var28);
                                   FlashHelper_SetGlobalInt(var11, "LapTimeisvisible", 1);
                               }
                               PoliceManager_CurrentRaceLapChanged(var32);
                               (*((var0 + 16) + 4))[var17 * 48].v25[var32] = var27;
                               (*((var0 + 16) + 4))[var17 * 48].v7 = var32;
                               if (var12)
                               {
                                   PRINTSTRING("Remaining laps: ");
                                   PRINTINT(*((var0 + 16) + 3116) - (*((var0 + 16) + 4))[var17 * 48].v7);
                                   PRINTSTRING("\n");
                                   sub_76f(var1, var2, *((var0 + 16) + 3116) - (*((var0 + 16) + 4))[var17 * 48].v7);
                                   AudioManager_PlayFrontendSound("HUD_CHECKPOINT_MASTER");
                               }
                               (*((var0 + 16) + 4))[var17 * 48].v6 = 0;
                               sub_824(&((*((var0 + 16) + 4))[var17 * 48]), var17, 0, var1, *((var0 + 16) + 3116));
                               Racer_ResetNitros((*((var0 + 16) + 4))[var17 * 48].v0);
                           }
                       }
                       else
                       {
                           var33 = (*((var0 + 16) + 4))[var17 * 48].v6;
                           sub_824(&((*((var0 + 16) + 4))[var17 * 48]), var17, var33, var1, *((var0 + 16) + 3116));
                           if (var12)
                           {
                               if (var33 < (var1 - 1))
                               {
                                   mcHudMapServer_SetMutExSubtype((*var2)[var33], 1);
                               }
                               AudioManager_PlayFrontendSound("HUD_CHECKPOINT_MASTER");
                               if (var33 > 0)
                               {
                                   if ((*((var0 + 16) + 3116) - (*((var0 + 16) + 4))[var17 * 48].v7) <= 1)
                                   {
                                       mcHudMapServer_RemoveElement((*var2)[var33 - 1]);
                                   }
                                   else
                                   {
                                       mcHudMapServer_RemoveElement((*var2)[var33 - 1]);
                                       mcHudMapServer_AddElement((*var2)[var33 - 1]);
                                       mcHudMapServer_SetMutExSubtype((*var2)[var33 - 1], 3);
                                   }
                               }
                               else
                               {
                                   sub_76f(var1, var2, *((var0 + 16) + 3116) - (*((var0 + 16) + 4))[var17 * 48].v7);
                               }
                           }
                       }
                   }
                   if (var13)
                   {
                       if ((*((var0 + 16) + 4))[var17 * 48].v8 == 0x7fffffff)
                       {
                           if (Net_GetRaceFinishTime((*((var0 + 16) + 4))[var17 * 48].v0, &((*((var0 + 16) + 4))[var17 * 48].v8)))
                           {
                               if ((*((var0 + 16) + 4))[var17 * 48].v8 == -1)
                               {
                               }
                               else
                               {
                                   PRINTSTRING("Racer ");
                                   PRINTINT(var17);
                                   PRINTSTRING("- Finished Race. Time ");
                                   PRINTINT(var27);
                                   PRINTSTRING(" seconds\n");
                                   sub_1eb4(var0, var17, &var14, 0);
                               }
                           }
                       }
                   }
               }
               var17 = var17 + 1;
           }
           var17 = 0;
           while (var17 < *((var0 + 16) + 3080))
           {
               var12 = (*((var0 + 16) + 4))[var17 * 48].v2 == 0;
               var13 = (*((var0 + 16) + 4))[var17 * 48].v2 == 1;
               if (((*((var0 + 16) + 4))[var17 * 48].v8 != -1) && (!Game_IsPaused()))
               {
                   (*((var0 + 16) + 4))[var17 * 48].v41 = CheckpointManager_CalculateRankOrdered(Race_GetCheckpointList(*(var0 + 12)), var0 + 16, var17, *((var0 + 16) + 3080));
               }
               if (var12)
               {
                   if (*((var0 + 16) + 3120))
                   {
                       var22 = 0;
                       var35 = 0;
                       while (var22 < *((var0 + 16) + 3080))
                       {
                           if ((*((var0 + 16) + 4))[var22 * 48].v2 == 1)
                           {
                               if (Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var22 * 48].v0) && (!((*((var0 + 16) + 4))[var22 * 48].v8 == -1)))
                               {
                                   var35 = var35 + 1;
                                   PRINTSTRING("PLAYER IS DISCONNECTED, INCREASE nDISCONNECTEDPLAYERS \n");
                                   PRINTSTRING("nDisconnectedPLayers is :");
                                   PRINTINT(var35);
                                   PRINTSTRING("\n");
                               }
                           }
                           var22 = var22 + 1;
                       }
                   }
                   if (*((var0 + 16) + 3116) > 1)
                   {
                       var34 = (*((var0 + 16) + 4))[var17 * 48].v7;
                       FlashHelper_SetGlobalInt(var11, "LapNumber", var34 + 1);
                       if (var10)
                       {
                           PRINTSTRING("Number of Disconnected player is : ");
                           PRINTINT(var35);
                           PRINTSTRING("\n");
                           var22 = var7 - var35;
                           if (var22 < 1)
                           {
                               var22 = 1;
                           }
                           if (var22 < var36)
                           {
                               var36 = var22;
                           }
                           *((var0 + 16) + 3116) = var36;
                           FlashHelper_SetGlobalInt(var11, "LapMax", var36);
                       }
                       else
                       {
                           FlashHelper_SetGlobalInt(var11, "LapMax", *((var0 + 16) + 3116));
                       }
                       Ctrl_SetVisible(HUD_GetHUDCtrl(16), 1);
                   }
                   else
                   {
                       Ctrl_SetVisible(HUD_GetHUDCtrl(16), 0);
                   }
                   FlashHelper_SetGlobalInt(var11, "PosNumber", (*((var0 + 16) + 4))[var17 * 48].v41);
                   if (var10)
                   {
                       FlashHelper_SetGlobalInt(var11, "PosMax", *((var0 + 16) + 3080) - (var14 + var35));
                   }
                   else
                   {
                       FlashHelper_SetGlobalInt(var11, "PosMax", *((var0 + 16) + 3080));
                   }
                   if ((*((var0 + 16) + 4))[1 * 48].v8 != 0x7fffffff)
                   {
                       var5 = 0;
                   }
                   if (((var5 && (var6 < Race_GetTimer(*(var0 + 12)))) && (*((var0 + 16) + 3080) > 1)) && (!*((var0 + 16) + 3120)))
                   {
                       var6 = RAND_INT_RANGE(45000 + Race_GetTimer(*(var0 + 12)), 70000 + Race_GetTimer(*(var0 + 12)));
                       if ((!SpeechSystem_IsInUse()) && Racer_IsActive((*((var0 + 16) + 4))[1 * 48].v0))
                       {
                           if (*((var0 + 16) + 3132))
                           {
                               mcCareerSpeech_PlayTauntInRace(mcRaceScriptData_GetRandomOpponent(var0 + 16), (*((var0 + 16) + 4))[var17 * 48].v0, (*((var0 + 16) + 4))[var17 * 48].v41, var0);
                           }
                           else
                           {
                               mcCareerSpeech_PlayTauntInRace((*((var0 + 16) + 4))[1 * 48].v0, (*((var0 + 16) + 4))[var17 * 48].v0, (*((var0 + 16) + 4))[var17 * 48].v41, var0);
                           }
                       }
                   }
               }
               var17 = var17 + 1;
           }
           Race_SetRaceData(*(var0 + 12), var0 + 16);
           if ((*((var0 + 16) + 3120) && (*((var0 + 16) + 3148) > 0)) && (Race_GetTimerHuman(*(var0 + 12)) >= *((var0 + 16) + 3148)))
           {
               PRINTSTRING("Script: Race timeout! nTimeout = ");
               PRINTINT(*((var0 + 16) + 3148));
               PRINTSTRING("\n");
               Race_Finish(*(var0 + 12));
               var16 = 1;
               Notify(3);
           }
           else
           {
               WAITUNWARPED(30);
           }
       }
   }
   if (*((var0 + 16) + 3120))
   {
       var17 = 0;
       var17 = 0;
       while (var17 < *((var0 + 16) + 3080))
       {
           var12 = (*((var0 + 16) + 4))[var17 * 48].v2 == 0;
           if (var12 && ((*((var0 + 16) + 4))[var17 * 48].v8 == 0x7fffffff))
           {
               (*((var0 + 16) + 4))[var17 * 48].v8 = -1;
               Registry_GetValueInt("raceOverTrigger", &var15);
               if (var16)
               {
                   PRINTSTRING("Script: Local racer timed out\n");
                   Net_SetRacerTimeout((*((var0 + 16) + 4))[var17 * 48].v0);
                   sub_1fff(var0, var17);
               }
               else if (var15 == 1)
               {
                   PRINTSTRING("Script: Local racer quit\n");
                   Net_SetRacerDisconnect((*((var0 + 16) + 4))[var17 * 48].v0);
                   (*((var0 + 16) + 4))[var17 * 48].v41 = *((var0 + 16) + 3080);
               }
           }
           var17 = var17 + 1;
       }
   }
   Race_EnableRaceTimer(*(var0 + 12), 0);
   FlashHelper_SetGlobalString(var11, "LapTime", "");
   Ctrl_SetVisible(HUD_GetHUDCtrl(16), 0);
   Ctrl_SetVisible(HUD_GetHUDCtrl(7), 0);
   PropertyCtrl_SetPropertyBool(var24, 2, 0);
   PropertyCtrl_SetPropertyBool(var24, 0, 0);
}

void sub_19ce(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = 0;
   var7 = 0;
   var8 = 0;
   var9 = var2;
   while (var8 < *((var0 + 16) + 3080))
   {
       if (*((var0 + 16) + 3120))
       {
           if (!Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var8 * 48].v0))
           {
               if (((*((var0 + 16) + 4))[var8 * 48].v41 == 1) && (!Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var8 * 48].v0)))
               {
                   var6 = var8;
               }
               else if ((*((var0 + 16) + 4))[var8 * 48].v41 == (*((var0 + 16) + 3080) - (var2 + var3)))
               {
                   var7 = var8;
               }
           }
           var8 = var8 + 1;
       }
       else
       {
           if ((*((var0 + 16) + 4))[var8 * 48].v41 == 1)
           {
               var6 = var8;
           }
           else if ((*((var0 + 16) + 4))[var8 * 48].v41 == (*((var0 + 16) + 3080) - (var2 + var3)))
           {
               var7 = var8;
           }
           var8 = var8 + 1;
       }
   }
   if (((*((var0 + 16) + 4))[var7 * 48].v7 != (*((var0 + 16) + 4))[var6 * 48].v7) && ((*((var0 + 16) + 4))[var6 * 48].v7 != var9))
   {
       PRINTSTRING("TIME TO START TIMER");
       PRINTSTRING("TIMER STARTED, SHOULD END AT :");
       *var1 = Race_GetTimerHuman(*(var0 + 12)) + 10000;
       Race_SetTargetTime(*(var0 + 12), *(var1));
       PRINTINT(*(var1));
       PRINTSTRING("\n");
       if (*((var0 + 16) + 3120))
       {
           Net_SendEliminationTimer(*(var1));
       }
   }
}

function sub_1bf4(var0, var1)
{
   auto var4, var5, var6, var7;

   var4 = 0;
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var5 * 48].v41 == 1)
       {
       }
       else if ((*((var0 + 16) + 4))[var5 * 48].v41 == (*((var0 + 16) + 3080) - var1))
       {
           var4 = var5;
       }
       var5 = var5 + 1;
   }
   if (*((var0 + 16) + 3120))
   {
       Net_SetRacerToEliminate((*((var0 + 16) + 4))[var4 * 48].v0);
       Net_SendRacerToEliminate((*((var0 + 16) + 4))[var4 * 48].v0);
   }
   return var4;
}

function sub_1ced(var0, var1)
{
   auto var4, var5, var6;

   var4 = 0;
   while (var4 < *(var0 + 3080))
   {
       if ((*(var0 + 4))[var4 * 48].v0 == var1)
       {
           return var4;
       }
       else
       {
           var4 = var4 + 1;
       }
   }
   return -1;
}

void sub_1d54(var0)
{
   auto var3, var4;

   PRINTSTRING("Starting the Eliminate clock!!!! \n");
   var3 = HUD_GetHUDCtrl(6);
   PropertyCtrl_SetPropertyBool(var3, 2, 1);
   PropertyCtrl_SetPropertyBool(var3, 0, 1);
   PropertyCtrl_SetPropertyInt(var3, 1, var0);
   Ctrl_SetVisible(var3, 1);
}

void sub_1eb4(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14;

   var6 = (*((var0 + 16) + 4))[var1 * 48].v0;
   var7 = (*((var0 + 16) + 4))[var1 * 48].v8;
   var8 = (*((var0 + 16) + 4))[var1 * 48].v2;
   if (*((var0 + 16) + 3120) && (var8 == 0))
   {
       Net_SetRaceFinishTime(var6, var7);
       (*((var0 + 16) + 4))[var1 * 48].v41 = sub_1f18(var0, var1, var7);
       PRINTSTRING("SCRIPT: Before SkidToStop, my finish time rank is ");
       PRINTINT((*((var0 + 16) + 4))[var1 * 48].v41);
       PRINTSTRING("\n");
       sub_1fff(var0, var1);
   }
   var9 = (*((var0 + 16) + 4))[var1 * 48].v41;
   PRINTSTRING("RACER ");
   PRINTINT(var1);
   PRINTSTRING(" Finished in - ");
   PRINTINT(var9);
   PRINTSTRING(" Place\n");
   var10 = EventOptions_IsLastManOut(*((var0 + 16) + 3160));
   *var2 = *(var2) + 1;
   if (var9 == 1)
   {
       Race_SetWinningTime(*(var0 + 12), var7);
   }
   if (var8 == 0)
   {
       if (var3)
       {
           SplashManager_SplashDynamicString(0, 3, Racer_GetName(var6), "PLAYER_ELEMINATED", "LMO_ELEMINATED", 0x40000000, 0);
       }
       Racer_SetPreviousRaceTime(var6, var7);
       if (!*((var0 + 16) + 3120))
       {
           if (Racer_IsDamagedOut(var6))
           {
               Race_ToggleDamagedOut(*(var0 + 12), 0);
               Racer_SetDamagePercent(var6, 0.95f);
           }
           ReplayMgr_SetFinishedRace();
           ReplayMgr_End(1);
           if (*((var0 + 16) + 3144))
           {
               Form_CloseForm(Form_GetForm(72));
           }
       }
   }
   else if (var10)
   {
       if (var3)
       {
           SplashManager_SplashDynamicString(0, 3, Racer_GetName(var6), "PLAYER_ELEMINATED", "LMO_ELEMINATED", 0x40000000, 0);
       }
   }
   else
   {
       StringTable_SetString("PLAYER_FINISHED_NAME", Racer_GetName(var6));
       SplashManager_SplashRaw(0, 3, StringTable_GetString("PLAYER_FINISHED"), 1.0f, 1, 0);
   }
   if (var8 == 2)
   {
       BrainRacing_EndRace((*((var0 + 16) + 4))[var1 * 48].v3, var7);
       mcHudMapServer_RemoveElement((*((var0 + 16) + 4))[var1 * 48].v4);
   }
   if (*((var0 + 16) + 3120) && (*((var0 + 16) + 3148) <= 0))
   {
       if ((!(var7 == 0x7fffffff)) && (!(var7 == -1)))
       {
           *((var0 + 16) + 3148) = var7 + 60000;
           PRINTSTRING("Script: Timeout scheduled for ");
           PRINTINT(*((var0 + 16) + 3148));
           PRINTSTRING("\n");
       }
   }
}

function sub_1f18(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10;

   var5 = 1;
   var6 = 0;
   var6 = 0;
   while (var6 < *((var0 + 16) + 3080))
   {
       var7 = (*((var0 + 16) + 4))[var6 * 48].v8;
       if (((var1 != var6) && (var7 != 0x7fffffff)) && (var7 != -1))
       {
           if (var7 < var2)
           {
               var5 = var5 + 1;
           }
       }
       var6 = var6 + 1;
   }
   return var5;
}

void sub_1fff(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10;

   PRINTSTRING("Script: Skidding to a stop...\n");
   var4 = (*((var0 + 16) + 4))[var1 * 48].v0;
   Racer_SetCarDrivableState(var4, 8);
   var5 = (*((var0 + 16) + 4))[var1 * 48].v8;
   var6 = Race_GetTimerHuman(*(var0 + 12)) + 2500;
   while (Race_GetTimerHuman(*(var0 + 12)) < var6)
   {
       var7 = 0;
       while (var7 < *((var0 + 16) + 3080))
       {
           if ((*((var0 + 16) + 4))[var7 * 48].v8 == 0x7fffffff)
           {
               if (Net_GetRaceFinishTime((*((var0 + 16) + 4))[var7 * 48].v0, &((*((var0 + 16) + 4))[var7 * 48].v8)))
               {
                   var8 = (*((var0 + 16) + 4))[var7 * 48].v8;
                   if (var8 != -1)
                   {
                       PRINTSTRING("During SkidToStop: Racer ");
                       PRINTINT(var7);
                       PRINTSTRING(" - Finished Race. Time ");
                       PRINTINT(var8);
                       PRINTSTRING(" seconds\n");
                       if ((var5 != -1) && (var5 != 0x7fffffff))
                       {
                           if (var8 < var5)
                           {
                               (*((var0 + 16) + 4))[var1 * 48].v41 = (*((var0 + 16) + 4))[var1 * 48].v41 + 1;
                               PRINTSTRING("Racer ");
                               PRINTINT(var7);
                               PRINTSTRING(" - Finished before me. My new rank is ");
                               PRINTINT((*((var0 + 16) + 4))[var1 * 48].v41);
                               PRINTSTRING("\n");
                           }
                       }
                   }
               }
           }
           var7 = var7 + 1;
       }
       Race_SetRaceData(*(var0 + 12), var0 + 16);
       WAITUNWARPED(30);
   }
   PRINTSTRING("Script: I finished skidding out...\n");
   if (Racer_IsDamagedOut(var4))
   {
       PRINTSTRING("SCRIPT: RaceOver.sch: QuickFixing damaged out local racer since he finished the race...\n");
       Racer_QuickFix(var4);
   }
}

void sub_367a()
{
   Warper_Warp("USER_WAIT_NO_CUT_UP");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Finished waiting\n");
}

void sub_36f9()
{
   WAITUNWARPED(10);
   Warper_Warp("USER_WAIT_NO_CUT_DOWN");
   while (Warper_IsWarping())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Finished waiting\n");
}

