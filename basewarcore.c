void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28;

   L[0] = null;
   L[1] = -1;
   L[2] = -1;
   L[3] = null;
   L[4] = 100;
   L[5] = 100;
   L[6].v4.v774 = 17;
   var2 = L[6].v801;
   if (L[6].v4.v773 == 10)
   {
       CtfMap_ComputeBaseLocations(Ctf_GetMap(var2));
   }
   var3 = AmbientMgr_GetTrafficEnable();
   if (!L[6].v4.v780)
   {
       sub_74(&L[6]);
   }
   Race_SetRaceData(L[6].v3, &(L[6].v4));
   Race_LoadAmbientPathArray(L[6].v3, L[6].v0);
   Map_SetCheckpointStrobe(0);
   var4 = 0;
   var21 = LookupCity(GetCurrentCity());
   L[3] = CityDescription_LookupRaceByIndex(var21, L[6].v4.v0);
   var22 = null;
   if (EventOptions_IsPowerUps(L[6].v4.v790))
   {
       PRINTSTRING("Script: Powerups are on -- ");
       if (L[6].v2 == null)
       {
           PRINTSTRING("Initializing from checkpoints\n");
           var23 = Race_GetCheckpointList(L[6].v3);
           var22 = PickUpManager_CreatePowerUpSourcesFromCheckPoints(var23, 0);
           PickUpManager_PowerUpSourcePostInit(var22);
       }
       else
       {
           PRINTSTRING(" Initializing from manually placed locations\n");
           PickUpManager_PowerUpSourcePostInit(L[6].v2);
       }
   }
   var25 = 0;
   if (!L[6].v4.v780)
   {
       var25 = 1;
       var26 = 0;
       while (var26 < L[6].v4.v770)
       {
           L[6].v4.v1[var26 * 48].v4 = mcHudMapServer_CreateElement();
           var26 = var26 + 1;
       }
   }
   var26 = 0;
   while (var26 < L[6].v4.v770)
   {
       if (L[6].v4.v1[var26 * 48].v42 == 2)
       {
           mcHudMapServer_SetSubType(L[6].v4.v1[var26 * 48].v4, 8);
       }
       else if (L[6].v4.v1[var26 * 48].v42 == 1)
       {
           mcHudMapServer_SetSubType(L[6].v4.v1[var26 * 48].v4, 16);
       }
       else
       {
           mcHudMapServer_ClearSubType(L[6].v4.v1[var26 * 48].v4, 8);
           mcHudMapServer_ClearSubType(L[6].v4.v1[var26 * 48].v4, 16);
       }
       var26 = var26 + 1;
   }
   var26 = 0;
   while (var26 < L[6].v4.v770)
   {
       if (L[6].v4.v1[var26 * 48].v2 == 0)
       {
           UILogic_RemoveGPSDestination(var26);
       }
       var26 = var26 + 1;
   }
   var27 = HUD_GetHUDCtrl(6);
   SetExceptionMask(3);
   var28 = ;
   switch (var28)
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
           PRINTINT(var28);
           PRINTSTRING("\n");
           if (L[6].v4.v780 && (!Net_IsCruiseMode()))
           {
               PRINTSTRING("Script: BaseWarCore.sc: Disabling traffic for pre-race countdown\n");
               if (AmbientMgr_GetTrafficEnable())
               {
                   AmbientMgr_SetTrafficEnable(0);
               }
           }
           Ctf_Reset(var2);
           sub_613(&(L[6].v4));
           Registry_SetValueInt("raceOverTrigger", 0);
           Registry_SetValueString("raceName", CityDescription_GetRaceNameByIndex(var21, L[6].v4.v0));
           var4 = 0;
           if (!L[6].v4.v780)
           {
               Registry_GetValueInt("replaying", &var4);
               Registry_SetValueInt("replaying", 0);
           }
           if (!L[6].v4.v780)
           {
               Notify(0);
           }
           sub_7d9(&L[6]);
           sub_12a4(&(L[6].v4), L[6].v3);
           sub_1371(&L[6]);
           if (Net_IsArbiterLocal())
           {
               if (L[6].v4.v773 == 10)
               {
                   sub_1535(var2);
               }
               else if (L[6].v4.v773 == 9)
               {
                   sub_15e2(var2);
               }
               else if (L[6].v4.v773 == 8)
               {
                   sub_168d(var2);
               }
               else if (L[6].v4.v773 == 12)
               {
                   sub_18ba(var2);
               }
               else if (L[6].v4.v773 == 11)
               {
                   sub_1980(var2);
               }
               else if (L[6].v4.v773 == 13)
               {
                   sub_1a35(var2);
               }
               else
               {
                   PRINTSTRING("[ctfscript] Restart Error, unsupported race subtype!\n");
               }
           }
           if (var4 == 0)
           {
               UIManager_SendEventTo("driveMode", "hangoutRace");
               UIManager_SendEventTo("hudManager", "refresh");
           }
           if (L[6].v4.v780)
           {
               PRINTSTRING("Script: BaseWarCore.sc: Pre-race countdown ended, switching to the selected traffic level\n");
               sub_74(&L[6]);
           }
           sub_1bb2(var2, &L[6], &var24);
           if (!L[6].v4.v780)
           {
               if (var24 || (!ReplayMgr_GetFinishedRace()))
               {
                   ReplayMgr_End(1);
                   if (var4 == 1)
                   {
                       Form_CloseForm(Form_GetForm(72));
                       if (ReplayMgr_GetFinishedRace())
                       {
                           var24 = 0;
                       }
                   }
               }
               Notify(1);
           }
           if (L[6].v4.v780)
           {
               var26 = 0;
               while (var26 < L[6].v4.v770)
               {
                   if (L[6].v4.v1[var26 * 48].v2 == 0)
                   {
                       if (var24)
                       {
                           Net_SetRacerDisconnect(L[6].v4.v1[var26 * 48].v0);
                           PRINTSTRING("[ctfscript] Local racer aborted BaseWar\n");
                       }
                       else
                       {
                           Net_SetRacerFinished(L[6].v4.v1[var26 * 48].v0);
                           PRINTSTRING("[ctfscript] Local racer finished BaseWar\n");
                       }
                   }
                   var26 = var26 + 1;
               }
           }
           break;
       }
   }
   if (L[6].v4.v780)
   {
       var26 = 0;
       while (var26 < L[6].v4.v770)
       {
           if ((L[6].v4.v1[var26 * 48].v2 == 0) && (!Racer_IsDamagedOut(L[6].v4.v1[var26 * 48].v0)))
           {
               Racer_Activate(L[6].v4.v1[var26 * 48].v0);
           }
           var26 = var26 + 1;
       }
   }
   if ((!StringCaseCompare(&var5, "nextRace")) || L[6].v4.v783)
   {
       UIManager_SendEventTo("driveMode", "cruise");
       UIManager_SendEventTo("hudManager", "refresh");
   }
   var26 = 0;
   while (var26 < L[6].v4.v770)
   {
       if (!(L[6].v4.v1[var26 * 48].v4 == null))
       {
           if (var25)
           {
               mcHudMapServer_DeleteElement(L[6].v4.v1[var26 * 48].v4);
           }
           else if (!Net_IsDeadGamer(L[6].v4.v1[var26 * 48].v0))
           {
               mcHudMapServer_AddElement(L[6].v4.v1[var26 * 48].v4);
               mcHudMapServer_ClearSubType(L[6].v4.v1[var26 * 48].v4, 8);
               mcHudMapServer_ClearSubType(L[6].v4.v1[var26 * 48].v4, 16);
           }
       }
       Racer_SetIconType(L[6].v4.v1[var26 * 48].v0, 0);
       Racer_HideIcon(L[6].v4.v1[var26 * 48].v0, 1);
       var26 = var26 + 1;
   }
   SplashManager_Cleanup();
   PropertyCtrl_SetPropertyBool(var27, 0, 0);
   if (L[0] != null)
   {
       mcHudMapServer_SetSelected(L[0], 0);
       L[0] = null;
   }
   var26 = 0;
   while (var26 < L[6].v4.v770)
   {
       if (L[6].v4.v1[var26 * 48].v2 == 0)
       {
           UILogic_RemoveGPSDestination(var26);
       }
       var26 = var26 + 1;
   }
   Graphics_SetShadowDisable(0);
   PRINTSTRING("restored UI\n");
   if (var22 != null)
   {
       PickUpManager_DeletePowerUpSources(var22);
       var22 = null;
   }
   if (L[6].v2 != null)
   {
       PickUpManager_DeletePowerUpSources(L[6].v2);
       L[6].v2 = null;
   }
   Race_UnloadAmbientPathArray(L[6].v3);
   if (L[6].v3 != null)
   {
       Race_SetRaceData(L[6].v3, &(L[6].v4));
   }
   Ctf_Reset(var2);
   if (var3 != AmbientMgr_GetTrafficEnable())
   {
       PRINTSTRING("Script: BaseWarCore.sc: Restoring original traffic setting (end of CTF)\n");
       AmbientMgr_SetTrafficEnable(var3);
   }
   PRINTSTRING("[ctfscript] QUIT NOW!!!\n");
}

void sub_74(var0)
{
   auto var3;

   if (*((var0 + 16) + 3160) != null)
   {
       if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) == 0)
       {
           PRINTSTRING("Script: BaseWarCore.sc: SetTrafficLevelFromOptions - Traffic is Disabled\n");
           if (AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(0);
           }
       }
       else if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) > 0)
       {
           PRINTSTRING("Script: BaseWarCore.sc: SetTrafficLevelFromOptions - Traffic is Enabled\n");
           if (!AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(1);
           }
       }
   }
   else
   {
       PRINTSTRING("Script: BaseWarCore.sc: SetTrafficLevelFromOptions - EventOptions is NULL (is this career?)\n");
   }
}

void sub_613(var0)
{
   auto var3, var4;

   if (*(var0 + 3120))
   {
       PRINTSTRING("[ctfscript] NETWORKED!\n");
   }
   else
   {
       PRINTSTRING("[ctfscript] OFFLINE!\n");
   }
   var3 = 0;
   while (var3 <= (*(var0 + 3080) - 1))
   {
       PRINTSTRING("[ctfscript] Racer #");
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

void sub_7d9(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58;

   sub_7e2();
   PRINTSTRING("CORE INFO\n");
   PRINTSTRING("Num Racers");
   PRINTINT(*((var0 + 16) + 3080));
   PRINTSTRING("\n");
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
       var56 = var3;
       if (*((var0 + 16) + 3120))
       {
           var56 = Net_GetRacerGridIndex(var4.v0);
       }
       if ((var4.v42 == 0) || (var4.v42 == 2))
       {
           RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), var56, &var52, &var55);
       }
       else
       {
           RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 1), var56, &var52, &var55);
       }
       Racer_InitializeResetPosition(var4.v0, &var52, var55);
       if ((*((var0 + 16) + 3120) && Racer_IsLocalPlayer(var4.v0)) && Racer_IsDamagedOut(var4.v0))
       {
           PRINTSTRING("SCRIPT: QuickFixing damaged out local racer before starting race...\n");
           Racer_QuickFix(var4.v0);
       }
       else
       {
           Racer_ResetWithDamageIntact(var4.v0);
       }
       Registry_GetValueInt("revertDamage", &var57);
       if (var57 == 1)
       {
           UILogic_RevertCarDamage();
           Registry_SetValueInt("revertDamage", 0);
       }
       if (!((*((var0 + 16) + 4))[var3 * 48].v4 == null))
       {
           if (var4.v2 == 0)
           {
               mcHudMapServer_SetVehicleElement((*((var0 + 16) + 4))[var3 * 48].v4, 0, var4.v0);
           }
           else
           {
               mcHudMapServer_SetVehicleElement((*((var0 + 16) + 4))[var3 * 48].v4, 6, var4.v0);
           }
           mcHudMapServer_AddElement((*((var0 + 16) + 4))[var3 * 48].v4);
       }
       if (var4.v2 == 0)
       {
           sub_b82(*(var0 + 3204), var0 + 16, &((*((var0 + 16) + 4))[var3 * 48]), 0);
       }
       var3 = var3 + 1;
   }
   Graphics_SetShadowDisable(1);
   Registry_SetValueInt("abortRace", 0);
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
       Racer_PreRaceBurnout(var4.v0);
       var3 = var3 + 1;
   }
   sub_f6a(0, 1, 0x3f800000, 0);
}

void sub_7e2()
{
   auto var2, var3;

   var2 = UIManager_GetState("GPSScene");
   var3 = vhsmState_IsActive(var2);
   if (!var3)
   {
       if (!Warper_IsReadyToLoadStuff())
       {
           PRINTSTRING("WarpUp: Waiting for previous warp to complete\n");
           while (!Warper_IsReadyToLoadStuff())
           {
               WAITUNWARPED(100);
               PRINTSTRING("WarpUp: Waiting for previous warp\n");
           }
           PRINTSTRING("WarpUp: Previous Warp is complete\n");
       }
       PRINTSTRING("WarpUp! USER_WAIT_NO_CUT_UP\n");
       Warper_Warp("USER_WAIT_NO_CUT_UP");
   }
}

void sub_b82(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14;

   var6 = *(var1 + 3092);
   if (L[0] != null)
   {
       mcHudMapServer_SetSelected(L[0], 0);
       L[0] = null;
   }
   var7 = 0;
   if (var6 == 10)
   {
       var7 = sub_bc3(var0, var1, var2, &var8);
   }
   else if (var6 == 13)
   {
       var7 = sub_d8e(var0, var2, &var8);
   }
   else
   {
       var7 = sub_e01(var0, var2, &var8);
   }
   if (var7)
   {
       UILogic_SetGPSDestination(var3, &var8);
   }
   else
   {
       UILogic_RemoveGPSDestination(var3);
   }
   if (L[0] != null)
   {
       mcHudMapServer_SetSelected(L[0], 1);
   }
}

function sub_bc3(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15;

   if (Racer_HasFlag(*(var2 + 0)))
   {
       var6 = Ctf_GetNearestActiveDropIndex(var0, *(var2 + 0), *(var2 + 168));
       if (var6 >= 0)
       {
           Ctf_GetDropPosition(var0, var6, var3);
           L[0] = Ctf_GetDropIcon(var0, var6);
           return 1;
       }
       else
       {
       }
   }
   else
   {
       var7 = 0;
       while (var7 < *(var1 + 3080))
       {
           if (!((*(var1 + 4))[var7 * 48].v42 == *(var2 + 168)))
           {
               var8 = Ctf_GetRacerHeldFlagIndex(var0, (*(var1 + 4))[var7 * 48].v0);
               if (var8 >= 0)
               {
                   if (sub_c7f(var0, var8, *(var2 + 168)))
                   {
                       Racer_GetPosition((*(var1 + 4))[var7 * 48].v0, var3);
                       L[0] = Ctf_GetFlagIcon(var0, var8);
                       return 1;
                   }
               }
           }
           var7 = var7 + 1;
       }
       if (*(var2 + 168) == 2)
       {
           var9 = 1;
       }
       else
       {
           var9 = 2;
       }
       var10 = Ctf_GetNearestActiveFlagIndex(var0, *(var2 + 0), var9);
       if (var10 >= 0)
       {
           Ctf_GetFlagPosition(var0, var10, var3);
           if (Ctf_IsFlagAtHomePosition(var0, var10))
           {
               var11 = Ctf_GetFlagHomeBaseDropIndex(var0, var10);
               if (var11 >= 0)
               {
                   L[0] = Ctf_GetDropIcon(var0, var11);
               }
           }
           else
           {
               L[0] = Ctf_GetFlagIcon(var0, var10);
           }
           return 1;
       }
   }
   return 0;
}

function sub_c7f(var0, var1, var2)
{
   auto var5, var6, var7;

   return var2 == Ctf_GetFlagColor(var0, var1);
}

function sub_d8e(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   if (Racer_HasFlag(*(var1 + 0)))
   {
       L[0] = null;
   }
   else
   {
       var5 = Ctf_GetNearestActiveFlagIndex(var0, *(var1 + 0), 0);
       if (var5 >= 0)
       {
           Ctf_GetFlagPosition(var0, var5, var2);
           L[0] = Ctf_GetFlagIcon(var0, var5);
           return 1;
       }
   }
   return 0;
}

function sub_e01(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9;

   if (Racer_HasBomb(*(var1 + 0)))
   {
       L[0] = null;
   }
   else if (Racer_HasFlag(*(var1 + 0)))
   {
       var5 = Ctf_GetNearestActiveDropIndex(var0, *(var1 + 0), *(var1 + 168));
       if (var5 >= 0)
       {
           Ctf_GetDropPosition(var0, var5, var2);
           L[0] = Ctf_GetDropIcon(var0, var5);
           return 1;
       }
       else
       {
       }
   }
   else
   {
       var6 = Ctf_GetNearestActiveFlagIndex(var0, *(var1 + 0), 0);
       if (var6 >= 0)
       {
           Ctf_GetFlagPosition(var0, var6, var2);
           L[0] = Ctf_GetFlagIcon(var0, var6);
           return 1;
       }
   }
   return 0;
}

void sub_f6a(var0, var1, var2, var3)
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

void sub_12a4(var0, var1)
{
   auto var4, var5, var6;

   Race_SetTimer(var1, -3000);
   START_NEW_SCRIPT("Game/RaceTypes/generic_countdown", 0);
   while (Race_GetTimer(var1) <= -1000)
   {
       WAIT(30);
   }
   var4 = 0;
   while (var4 < *(var0 + 3080))
   {
       if ((*(var0 + 4))[var4 * 48].v2 == 2)
       {
           BrainRacing_SetRevvingEnabled((*(var0 + 4))[var4 * 48].v3, 0);
       }
       var4 = var4 + 1;
   }
   while (Race_GetTimer(var1) <= 0)
   {
       WAIT(30);
   }
}

void sub_1371(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55;

   var5.v9 = 15;
   var5.v9.v25 = 15;
   PickUpManager_OnRaceReset();
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var5.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var5.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var5.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var5.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var5.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var5.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var5.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var5.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var5.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var5.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var5.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var5.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var5.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var5.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var5.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var5.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var5.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var5.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var5.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var5.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var5.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var5.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var5.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var5.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var5.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var5.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var5.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var5.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var5.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var5.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var5.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var5.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var5.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var5.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var5.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var5.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var5.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var5.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var5.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var5.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var5.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var5.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var5.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var5.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var5.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var5.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var5.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var5.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       var4 = 0;
       while (var4 < *((var0 + 16) + 3116))
       {
           (*((var0 + 16) + 4))[var3 * 48].v25[var4] = 0;
           (*((var0 + 16) + 4))[var3 * 48].v9[var4] = 0;
           var4 = var4 + 1;
       }
       (*((var0 + 16) + 4))[var3 * 48].v8 = 0x7fffffff;
       if (var5.v2 == 2)
       {
           var53 = LookupCity(GetCurrentCity());
           BrainRacing_BeginRace(var5.v3, CityDescription_GetRaceNameByIndex(var53, *((var0 + 16) + 0)));
       }
       if (EventOptions_GetTimeLimit(*((var0 + 16) + 3160)) > 0)
       {
           var54 = HUD_GetHUDCtrl(6);
           PropertyCtrl_SetPropertyBool(var54, 0, 1);
           Race_SetTargetTime(*(var0 + 12), EventOptions_GetTimeLimit(*((var0 + 16) + 3160)));
           Race_SetTimer(*(var0 + 12), 0);
           Race_EnableRaceTimer(*(var0 + 12), 1);
           Ctrl_SetVisible(var54, 1);
       }
       Racer_Activate((*((var0 + 16) + 4))[var3 * 48].v0);
       var3 = var3 + 1;
   }
}

void sub_1535(var0)
{
   auto var3;

   PRINTSTRING("[ctfscript] SetupBaseWar...\n");
   Ctf_SpawnFlag(var0, 2, 1, -1, -1);
   Ctf_SpawnFlag(var0, 1, 1, -1, -1);
   Ctf_ActivateDrop(var0, 2, -1);
   Ctf_ActivateDrop(var0, 1, -1);
   PRINTSTRING("[ctfscript] SetupBaseWar done...\n");
}

void sub_15e2(var0)
{
   auto var3, var4;

   PRINTSTRING("[ctfscript] SetupSplitBase...\n");
   var3 = L[1];
   L[1] = Ctf_SpawnFlag(var0, 0, 1, -1, var3);
   Ctf_ActivateDrop(var0, 2, -1);
   Ctf_ActivateDrop(var0, 1, -1);
   PRINTSTRING("[ctfscript] SetupSplitBase done...\n");
}

void sub_168d(var0)
{
   auto var3, var4, var5, var6, var7;

   PRINTSTRING("[ctfscript] SetupFreeForAll...\n");
   RaceGrid_GetPosition(Race_GetRaceGrid(Ctf_GetRace(var0), 0), 0, &var3, &var6);
   sub_16de(var0, 0, &var3);
   PRINTSTRING("[ctfscript] SetupFreeForAll done...\n");
}

void sub_16de(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18;

   var6 = Ctf_GetMaxActiveDrops();
   var5 = 0;
   while (var5 < var6)
   {
       if (Ctf_IsDropActive(var0, var5))
       {
           Ctf_DeactivateDrop(var0, var5);
       }
       var5 = var5 + 1;
   }
   var7 = 1;
   var8 = -1;
   if (var1)
   {
       sub_1734(&var7, &var8);
   }
   var9 = L[1];
   var10 = RaceDescription_GetFFAInnerRadius(L[3]);
   var11 = RaceDescription_GetFFAOuterRadius(L[3]);
   L[1] = Ctf_SpawnFlagInRange(var0, 0, var2, var10, var11, var7, var8, var9);
   if (L[1] < 0)
   {
       L[1] = Ctf_SpawnFlag(var0, 0, var7, var8, var9);
       if (L[1] < 0)
       {
           L[1] = Ctf_SpawnFlag(var0, 0, var7, var8, -1);
       }
   }
   if (L[1] >= 0)
   {
       CtfMap_GetFlagSpawnPosition(Ctf_GetMap(var0), L[1], &var12);
       var15 = L[2];
       L[2] = Ctf_ActivateDropInRange(var0, 0, &var12, var10, var11, var15);
       if (L[2] < 0)
       {
           L[2] = Ctf_ActivateDrop(var0, 0, var15);
           if (L[2] < 0)
           {
               L[2] = Ctf_ActivateDrop(var0, 0, -1);
           }
       }
   }
}

void sub_1734(var0, var1)
{
   auto var4, var5;

   *var0 = Net_NumRacers() - 1;
   if (*(var0) <= 0)
   {
       *var0 = 1;
   }
   *var1 = -1;
   if (*(var0) > 1)
   {
       *var1 = RAND_INT_RANGE(0, *(var0) - 1);
   }
}

void sub_18ba(var0)
{
   auto var3, var4, var5, var6;

   PRINTSTRING("[ctfscript] SetupSplitBaseStockpile...\n");
   sub_1734(&var3, &var4);
   var5 = L[1];
   L[1] = Ctf_SpawnFlag(var0, 0, var3, var4, var5);
   Ctf_ActivateDrop(var0, 2, -1);
   Ctf_ActivateDrop(var0, 1, -1);
   PRINTSTRING("[ctfscript] SetupSplitBaseStockpile done...\n");
}

void sub_1980(var0)
{
   auto var3, var4, var5, var6, var7;

   PRINTSTRING("[ctfscript] SetupFreeForAllStockPile...\n");
   RaceGrid_GetPosition(Race_GetRaceGrid(Ctf_GetRace(var0), 0), 0, &var3, &var6);
   sub_16de(var0, 1, &var3);
   PRINTSTRING("[ctfscript] SetupFreeForAllStockPile done...\n");
}

void sub_1a35(var0)
{
   auto var3;

   PRINTSTRING("[ctfscript] SetupKeepAway...\n");
   Ctf_SpawnFlag(var0, 0, 1, -1, -1);
   PRINTSTRING("[ctfscript] SetupKeepAway done...\n");
}

void sub_1bb2(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15;

   PRINTSTRING("[ctfscript] Running Ctf...\n");
   var5 = UIManager_FindMovie("HUDMOVIE");
   FlashHelper_SetGlobalString(var5, "LapTime", "");
   Ctrl_SetVisible(HUD_GetHUDCtrl(16), 0);
   Ctrl_SetVisible(HUD_GetHUDCtrl(7), 0);
   var7 = 0;
   var8 = *((var1 + 16) + 3092);
   if (var8 == 13)
   {
       Ctf_SetFlagPickUpTime(0);
       Ctf_SetFlagHeldTime(0);
   }
   var10 = null;
   var11 = 0;
   var12 = 0;
   while (!var9)
   {
       Race_SetRaceData(*(var1 + 12), var1 + 16);
       Registry_GetValueInt("raceOverTrigger", &var7);
       if (var7 == 1)
       {
           PRINTSTRING("[ctfscript] Aborting race\n");
           *var2 = 1;
           sub_1cc8(var1 + 16);
       }
       else
       {
           sub_1d9d(var0, var1);
           sub_2f48(var0, var8);
           sub_3280(var0);
           var6 = 0;
           while (var6 < *((var1 + 16) + 3080))
           {
               var10 = (*((var1 + 16) + 4))[var6 * 48].v0;
               if (var10 != null)
               {
                   var11 = Racer_IsPlayer(var10);
                   var12 = Racer_IsActive(var10);
                   if ((var12 && *((var1 + 16) + 3120)) && var11)
                   {
                       var12 = Net_IsPlayerActiveParticipant(var10);
                   }
                   if (var12)
                   {
                       sub_33a6(var0, &((*((var1 + 16) + 4))[var6 * 48]));
                       sub_34d6(var0, &((*((var1 + 16) + 4))[var6 * 48]));
                       if ((*((var1 + 16) + 4))[var6 * 48].v2 == 0)
                       {
                           sub_b82(var0, var1 + 16, &((*((var1 + 16) + 4))[var6 * 48]), 0);
                       }
                   }
                   sub_35ae(var0, &((*((var1 + 16) + 4))[var6 * 48]));
               }
               var6 = var6 + 1;
           }
           sub_37a7(var1 + 16);
           if (sub_3c81(var0, var1))
           {
               var9 = 1;
               sub_43e3(var1 + 16);
           }
           else
           {
               WAIT(30);
           }
       }
   }
   if (var8 == 13)
   {
       if (*(var2))
       {
           Ctf_SetFlagHeldTime(0);
           Ctf_SetFlagPickUpTime(0);
       }
   }
   sub_37a7(var1 + 16);
   sub_1cc8(var1 + 16);
   PRINTSTRING("[ctfscript] Ctf finished...\n");
}

void sub_1cc8(var0)
{
   auto var3, var4;

   PRINTSTRING("[ctfscript] Rankings:\n");
   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       PRINTSTRING("[ctfscript] Racer=");
       PRINTINT(var3);
       PRINTSTRING(": ");
       PRINTSTRING(Racer_GetName((*(var0 + 4))[var3 * 48].v0));
       PRINTSTRING(", Rank=");
       PRINTINT((*(var0 + 4))[var3 * 48].v41);
       PRINTSTRING("\n");
       var3 = var3 + 1;
   }
}

void sub_1d9d(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68;

   var9 = 3;
   var10 = *((var1 + 16) + 3092);
   var11 = (var10 == 11) || (var10 == 12);
   var12 = sub_1dc6(var1);
   var14.v9 = 15;
   var14.v9.v25 = 15;
   if (var12 >= 0)
   {
       var14.v0 = (*((var1 + 16) + 4))[var12 * 48].v0;
       var14.v1 = (*((var1 + 16) + 4))[var12 * 48].v1;
       var14.v2 = (*((var1 + 16) + 4))[var12 * 48].v2;
       var14.v3 = (*((var1 + 16) + 4))[var12 * 48].v3;
       var14.v4 = (*((var1 + 16) + 4))[var12 * 48].v4;
       var14.v5 = (*((var1 + 16) + 4))[var12 * 48].v5;
       var14.v6 = (*((var1 + 16) + 4))[var12 * 48].v6;
       var14.v7 = (*((var1 + 16) + 4))[var12 * 48].v7;
       var14.v8 = (*((var1 + 16) + 4))[var12 * 48].v8;
       var14.v9 = (*((var1 + 16) + 4))[var12 * 48].v9;
       var14.v10 = (*((var1 + 16) + 4))[var12 * 48].v10;
       var14.v11 = (*((var1 + 16) + 4))[var12 * 48].v11;
       var14.v12 = (*((var1 + 16) + 4))[var12 * 48].v12;
       var14.v13 = (*((var1 + 16) + 4))[var12 * 48].v13;
       var14.v14 = (*((var1 + 16) + 4))[var12 * 48].v14;
       var14.v15 = (*((var1 + 16) + 4))[var12 * 48].v15;
       var14.v16 = (*((var1 + 16) + 4))[var12 * 48].v16;
       var14.v17 = (*((var1 + 16) + 4))[var12 * 48].v17;
       var14.v18 = (*((var1 + 16) + 4))[var12 * 48].v18;
       var14.v19 = (*((var1 + 16) + 4))[var12 * 48].v19;
       var14.v20 = (*((var1 + 16) + 4))[var12 * 48].v20;
       var14.v21 = (*((var1 + 16) + 4))[var12 * 48].v21;
       var14.v22 = (*((var1 + 16) + 4))[var12 * 48].v22;
       var14.v23 = (*((var1 + 16) + 4))[var12 * 48].v23;
       var14.v24 = (*((var1 + 16) + 4))[var12 * 48].v24;
       var14.v25 = (*((var1 + 16) + 4))[var12 * 48].v25;
       var14.v26 = (*((var1 + 16) + 4))[var12 * 48].v26;
       var14.v27 = (*((var1 + 16) + 4))[var12 * 48].v27;
       var14.v28 = (*((var1 + 16) + 4))[var12 * 48].v28;
       var14.v29 = (*((var1 + 16) + 4))[var12 * 48].v29;
       var14.v30 = (*((var1 + 16) + 4))[var12 * 48].v30;
       var14.v31 = (*((var1 + 16) + 4))[var12 * 48].v31;
       var14.v32 = (*((var1 + 16) + 4))[var12 * 48].v32;
       var14.v33 = (*((var1 + 16) + 4))[var12 * 48].v33;
       var14.v34 = (*((var1 + 16) + 4))[var12 * 48].v34;
       var14.v35 = (*((var1 + 16) + 4))[var12 * 48].v35;
       var14.v36 = (*((var1 + 16) + 4))[var12 * 48].v36;
       var14.v37 = (*((var1 + 16) + 4))[var12 * 48].v37;
       var14.v38 = (*((var1 + 16) + 4))[var12 * 48].v38;
       var14.v39 = (*((var1 + 16) + 4))[var12 * 48].v39;
       var14.v40 = (*((var1 + 16) + 4))[var12 * 48].v40;
       var14.v41 = (*((var1 + 16) + 4))[var12 * 48].v41;
       var14.v42 = (*((var1 + 16) + 4))[var12 * 48].v42;
       var14.v43 = (*((var1 + 16) + 4))[var12 * 48].v43;
       var14.v44 = (*((var1 + 16) + 4))[var12 * 48].v44;
       var14.v45 = (*((var1 + 16) + 4))[var12 * 48].v45;
       var14.v46 = (*((var1 + 16) + 4))[var12 * 48].v46;
       var14.v47 = (*((var1 + 16) + 4))[var12 * 48].v47;
       var13 = 1;
   }
   while (Ctf_PopEvent(var0, &var4))
   {
       var62 = sub_1e62(var4.v2, var1);
       var63 = sub_1e62(var4.v3, var1);
       var64 = 0;
       if (var4.v2 != null)
       {
           var64 = Racer_GetTeam(var4.v2);
       }
       if (var4.v0 == 1)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagReset\n");
           AudioManager_PlayFrontendSound("CTF_FLAG_WARP");
           SplashManager_Splash(0, var9, "CTF_FLAG_RESET", 0.5f, 1, sub_1f5d(var4.v1));
       }
       else if (var4.v0 == 2)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagSpawn ");
           PRINTSTRING("mapIndex = ");
           PRINTINT(var4.v4);
           PRINTSTRING("\n");
           L[1] = var4.v4;
       }
       else if (var4.v0 == 7)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - DropActivate ");
           PRINTSTRING("mapIndex = ");
           PRINTINT(var4.v4);
           PRINTSTRING("\n");
           L[2] = var4.v4;
       }
       else if (var4.v0 == 3)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagPickup\n");
           if (var13)
           {
               if (var14.v42 == 0)
               {
                   if (Racer_IsLocalPlayer(var4.v2))
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_PICKUP_ENEMY");
                       if (var10 == 13)
                       {
                           Ctf_SetFlagPickUpTime(Race_GetTimer(*(var1 + 12)));
                       }
                   }
                   else
                   {
                       AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_PICKUP_ENEMY");
                   }
               }
               else if (var14.v42 == Racer_GetTeam(var4.v2))
               {
                   if (Racer_GetTeam(var4.v2) == var4.v1)
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_PICKUP_TEAM");
                   }
                   else
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_PICKUP_ENEMY");
                   }
               }
               else if (Racer_GetTeam(var4.v2) == var4.v1)
               {
                   AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_PICKUP_TEAM");
               }
               else
               {
                   AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_PICKUP_ENEMY");
               }
               if (Racer_IsLocalPlayer(var4.v2))
               {
                   StatsManager_UpdateStatInt("nFPK", 0, 0, 1);
               }
               (*((var1 + 16) + 4))[var62 * 48].v45 = (*((var1 + 16) + 4))[var62 * 48].v45 + 1;
           }
           else
           {
               AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_PICKUP_ENEMY");
           }
           if ((!var11) || Racer_IsLocalPlayer(var4.v2))
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_FLAG_TAKEN", 0.5f, 1, sub_1f5d(var64));
           }
       }
       else if (var4.v0 == 4)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagReturn\n");
           if (var13)
           {
               if (var14.v42 == 0)
               {
                   if (Racer_IsLocalPlayer(var4.v2))
                   {
                       AudioManager_PlayFrontendSound("CTF_SCORE_TEAM");
                       StatsManager_UpdateStatInt("nFLG", 0, 0, 1);
                       Ctf_AddFlagHeldTime(1);
                   }
                   else
                   {
                       AudioManager_PlayFrontendSound("CTF_SCORE_ENEMY");
                   }
               }
               else if (var14.v42 == Racer_GetTeam(var4.v2))
               {
                   AudioManager_PlayFrontendSound("CTF_SCORE_TEAM");
                   if (Racer_IsLocalPlayer(var4.v2))
                   {
                       StatsManager_UpdateStatInt("nFLG", 0, 0, 1);
                   }
               }
               else
               {
                   AudioManager_PlayFrontendSound("CTF_SCORE_ENEMY");
               }
           }
           else
           {
               AudioManager_PlayFrontendSound("CTF_SCORE_ENEMY");
           }
           if ((!var11) || Racer_IsLocalPlayer(var4.v2))
           {
               sub_2463(var4.v2, "CTF_SPLASH_RACERA_NAME");
               SplashManager_Splash(0, var9, "CTF_SPLASH_FLAG_DELIVERED", 0.5f, 1, sub_1f5d(var64));
           }
           if (Racer_GetTeam(var4.v2) == 0)
           {
               (*((var1 + 16) + 4))[var62 * 48].v47 = (*((var1 + 16) + 4))[var62 * 48].v47 + 1;
           }
           else if (var4.v1 == 0)
           {
               (*((var1 + 16) + 4))[var62 * 48].v47 = (*((var1 + 16) + 4))[var62 * 48].v47 + 1;
               (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] = (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] + 1;
           }
           else
           {
               (*((var1 + 16) + 4))[var62 * 48].v47 = (*((var1 + 16) + 4))[var62 * 48].v47 + 2;
               (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] = (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] + 2;
           }
           Racer_ScoreUpdated((*((var1 + 16) + 4))[var62 * 48].v0, (*((var1 + 16) + 4))[var62 * 48].v47);
           (*((var1 + 16) + 4))[var62 * 48].v43 = (*((var1 + 16) + 4))[var62 * 48].v43 + 1;
           PRINTSTRING("[Bourassa] Flag returned!!!\n For Racer number");
           PRINTINT(var62);
           PRINTSTRING("\n");
       }
       else if (var4.v0 == 5)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagSaved\n");
           sub_2463(var4.v2, "CTF_SPLASH_RACERA_NAME");
           if (var4.v1 == 2)
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_SAVED_FLAG_RED", 0.5f, 1, sub_1f5d(var64));
           }
           else if (var4.v1 == 1)
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_SAVED_FLAG_BLUE", 0.5f, 1, sub_1f5d(var64));
           }
           (*((var1 + 16) + 4))[var62 * 48].v44 = (*((var1 + 16) + 4))[var62 * 48].v44 + 1;
           (*((var1 + 16) + 4))[var62 * 48].v47 = (*((var1 + 16) + 4))[var62 * 48].v47 + 1;
           (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] = (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] + 1;
           Racer_ScoreUpdated((*((var1 + 16) + 4))[var62 * 48].v0, (*((var1 + 16) + 4))[var62 * 48].v47);
       }
       else if (var4.v0 == 6)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - FlagDrop\n");
           if (var13)
           {
               if (var14.v42 == 0)
               {
                   if (Racer_IsLocalPlayer(var4.v2))
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_DROP_ENEMY");
                       if (var10 == 13)
                       {
                           Ctf_AddFlagHeldTime(Race_GetTimer(*(var1 + 12)) - Ctf_GetFlagPickUpTime(var4.v2));
                           Ctf_SetFlagPickUpTime(0);
                       }
                   }
                   else
                   {
                       AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_DROP_ENEMY");
                   }
               }
               else if (var14.v42 == Racer_GetTeam(var4.v2))
               {
                   if (Racer_GetTeam(var4.v2) == var4.v1)
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_DROP_TEAM");
                   }
                   else
                   {
                       AudioManager_PlayFrontendSound("CTF_TEAM_FLAG_DROP_ENEMY");
                   }
               }
               else if (Racer_GetTeam(var4.v2) == var4.v1)
               {
                   AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_DROP_TEAM");
               }
               else
               {
                   AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_DROP_ENEMY");
               }
           }
           else
           {
               AudioManager_PlayFrontendSound("CTF_ENEMY_FLAG_DROP_ENEMY");
           }
           if ((!var11) || Racer_IsLocalPlayer(var4.v2))
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_FLAG_DROPPED", 0.5f, 1, sub_1f5d(var64));
           }
       }
       else if (var4.v0 == 8)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - Swap\n");
           var65 = null;
           var66 = null;
           if (Racer_IsLocalPlayer(var4.v2))
           {
               var65 = var4.v2;
               var66 = var4.v3;
           }
           else if (Racer_IsLocalPlayer(var4.v3))
           {
               var65 = var4.v3;
               var66 = var4.v2;
           }
           if (var65 != null)
           {
               if (Racer_HasBomb(var65))
               {
                   SplashManager_Splash(0, var9, "CTF_SPLASH_YOU_GOT_BOMB", 0.5f, 1, 0);
               }
               else if (Racer_HasBomb(var66))
               {
                   SplashManager_Splash(0, var9, "CTF_SPLASH_YOU_GOT_RID_OF_BOMB", 0.5f, 1, 0);
               }
               else if (Racer_HasFlag(var65))
               {
                   SplashManager_Splash(0, var9, "CTF_SPLASH_YOU_STOLE_FLAG", 0.5f, 1, 0);
               }
               else if (Racer_HasFlag(var66))
               {
                   SplashManager_Splash(0, var9, "CTF_SPLASH_YOU_LOST_FLAG", 0.5f, 1, 0);
               }
               if (Racer_HasFlag(var65))
               {
                   StatsManager_UpdateStatInt("nFST", 0, 0, 1);
                   if (var10 == 13)
                   {
                       Ctf_SetFlagPickUpTime(Race_GetTimer(*(var1 + 12)));
                   }
               }
               if (Racer_HasFlag(var66))
               {
                   if (var10 == 13)
                   {
                       Ctf_AddFlagHeldTime(Race_GetTimer(*(var1 + 12)) - Ctf_GetFlagPickUpTime(var65));
                       Ctf_SetFlagPickUpTime(0);
                   }
               }
               AudioManager_PlayFrontendSound("CTF_FLAG_TRANSFER");
           }
           if (Racer_HasFlag(var4.v2))
           {
               (*((var1 + 16) + 4))[var62 * 48].v46 = (*((var1 + 16) + 4))[var62 * 48].v46 + 1;
               PRINTSTRING("[Bourassa] Flag stolen up !!!!\n");
           }
           else if (Racer_HasFlag(var4.v3))
           {
               (*((var1 + 16) + 4))[var63 * 48].v46 = (*((var1 + 16) + 4))[var63 * 48].v46 + 1;
               PRINTSTRING("[Bourassa] Flag stolen up !!!!\n");
           }
       }
       else if (var4.v0 == 9)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - BombPickup\n");
           if (Racer_IsLocalPlayer(var4.v2))
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_YOU_GOT_BOMB", 0.5f, 1, 0);
           }
       }
       else if (var4.v0 == 10)
       {
           PRINTSTRING("[ctfscript] CTF EVENT - BombExplode\n");
           if (Racer_IsLocalPlayer(var4.v2))
           {
               SplashManager_Splash(0, var9, "CTF_SPLASH_BOMB_DETONATED", 0.5f, 0, 0);
           }
           (*((var1 + 16) + 4))[var62 * 48].v47 = (*((var1 + 16) + 4))[var62 * 48].v47 - 1;
           if ((*((var1 + 16) + 4))[var62 * 48].v47 < 0)
           {
               (*((var1 + 16) + 4))[var62 * 48].v47 = 0;
           }
           Racer_ScoreUpdated((*((var1 + 16) + 4))[var62 * 48].v0, (*((var1 + 16) + 4))[var62 * 48].v47);
           if (!(Racer_GetTeam(var4.v2) == 0))
           {
               (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] = (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] - 1;
               if ((*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] < 0)
               {
                   (*((var1 + 16) + 3164))[Racer_GetTeam(var4.v2)] = 0;
               }
           }
       }
   }
}

function sub_1dc6(var0)
{
   auto var3, var4;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 0)
       {
           return var3;
       }
       else
       {
           var3 = var3 + 1;
       }
   }
   return -1;
}

function sub_1e62(var0, var1)
{
   auto var4, var5, var6;

   if (var0 != null)
   {
       var4 = 0;
       while (var4 < *((var1 + 16) + 3080))
       {
           if (var0 == (*((var1 + 16) + 4))[var4 * 48].v0)
           {
               return var4;
           }
           else
           {
               var4 = var4 + 1;
           }
       }
   }
   return -1;
}

function sub_1f5d(var0)
{
   auto var3;

   if (var0 == 2)
   {
       return 2;
   }
   else if (var0 == 1)
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

void sub_2463(var0, var1)
{
   auto var4, var5, var6;

   if (var0 != null)
   {
       var4 = Racer_GetName(var0);
       StringTable_SetString(var1, var4);
   }
}

void sub_2f48(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18;

   var5 = Ctf_GetMaxActiveFlags();
   var6 = 3;
   var4 = 0;
   while (var4 < var5)
   {
       if (Ctf_IsFlagActive(var0, var4))
       {
           var13 = Ctf_GetFlagColor(var0, var4);
           var6[var13] = var6[var13] + 1;
       }
       var4 = var4 + 1;
   }
   var14 = L[1];
   if (var1 == 10)
   {
       if (var6[2] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               L[4] = L[4] - 1;
               if (L[4] <= 0)
               {
                   PRINTSTRING("Spawning new RED flag\n");
                   Ctf_SpawnFlag(var0, 2, 1, -1, -1);
               }
           }
       }
       else
       {
           L[4] = 100;
       }
       if (var6[1] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               L[5] = L[5] - 1;
               if (L[5] <= 0)
               {
                   PRINTSTRING("Spawning new BLUE flag\n");
                   Ctf_SpawnFlag(var0, 1, 1, -1, -1);
               }
           }
       }
       else
       {
           L[5] = 100;
       }
   }
   else if (var1 == 9)
   {
       if (var6[0] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               PRINTSTRING("Spawning new NEUTRAL flag\n");
               L[1] = Ctf_SpawnFlag(var0, 0, 1, -1, var14);
           }
       }
   }
   else if (var1 == 8)
   {
       if (var6[0] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               if (L[2] >= 0)
               {
                   CtfMap_GetFlagDropPosition(Ctf_GetMap(var0), L[2], &var10);
                   sub_16de(var0, 0, &var10);
               }
               else
               {
                   sub_168d(var0);
               }
           }
       }
   }
   else if (var1 == 12)
   {
       if (var6[0] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               PRINTSTRING("Spawning new NEUTRAL flag\n");
               sub_1734(&var15, &var16);
               L[1] = Ctf_SpawnFlag(var0, 0, var15, var16, var14);
           }
       }
   }
   else if (var1 == 11)
   {
       if (var6[0] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               if (L[2] >= 0)
               {
                   CtfMap_GetFlagDropPosition(Ctf_GetMap(var0), L[2], &var10);
                   sub_16de(var0, 1, &var10);
               }
               else
               {
                   sub_168d(var0);
               }
           }
       }
   }
   else if (var1 == 13)
   {
       if (var6[0] == 0)
       {
           if (Net_IsArbiterLocal())
           {
               Ctf_SpawnFlag(var0, 0, 1, -1, -1);
           }
       }
   }
   else
   {
       PRINTSTRING("[ctfscript] UpdateFlagSpawns Error, unsupported race subtype!\n");
   }
}

void sub_3280(var0)
{
   auto var3, var4, var5;

   var4 = Ctf_GetMaxActiveFlags();
   var3 = 0;
   while (var3 < var4)
   {
       if (Ctf_IsFlagActive(var0, var3))
       {
           if (Ctf_GetFlagDroppedElapsedTimeMs(var0, var3) >= 15000)
           {
               PRINTSTRING("[ctfscript] Resetting dropped flag to spawn position...");
               Ctf_AttemptResetFlagToSpawnPosition(var0, var3);
           }
       }
       var3 = var3 + 1;
   }
}

void sub_33a6(var0, var1)
{
   auto var4, var5, var6, var7;

   if (Racer_HasFlag(*(var1 + 0)) || Racer_HasBomb(*(var1 + 0)))
   {
       return;
   }
   else
   {
       var5 = Ctf_GetMaxActiveFlags();
       var4 = 0;
       while (var4 < var5)
       {
           if (Ctf_IsFlagActive(var0, var4))
           {
               if (Ctf_GetFlagHolder(var0, var4) == null)
               {
                   if ((!sub_c7f(var0, var4, *(var1 + 168))) || sub_c7f(var0, var4, 0))
                   {
                       if (Ctf_HasHitFlag(var0, *(var1 + 0), var4))
                       {
                           Ctf_AttemptPickupFlag(var0, var1, var4);
                       }
                   }
                   else if (!Ctf_IsFlagAtHomePosition(var0, var4))
                   {
                       if (Ctf_HasHitFlag(var0, *(var1 + 0), var4))
                       {
                           PRINTSTRING("[ctfscript] Recovered own team's flag!\n");
                           Ctf_AttemptPickupFlag(var0, var1, var4);
                       }
                   }
               }
           }
           var4 = var4 + 1;
       }
       return;
   }
}

void sub_34d6(var0, var1)
{
   auto var4, var5, var6, var7;

   if (Racer_HasFlag(*(var1 + 0)))
   {
       var5 = Ctf_GetMaxActiveDrops();
       var4 = 0;
       while (var4 < var5)
       {
           if (Ctf_IsDropActive(var0, var4))
           {
               if ((*(var1 + 168) == Ctf_GetDropColor(var0, var4)) || (Ctf_GetDropColor(var0, var4) == 0))
               {
                   if (Ctf_HasHitDrop(var0, *(var1 + 0), var4))
                   {
                       Ctf_AttemptReturnFlags(var0, var1);
                       return;
                   }
               }
           }
           var4 = var4 + 1;
       }
   }
}

void sub_35ae(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   var4 = 0;
   var5 = Racer_GetImmuneTimer(*(var1 + 0));
   if (Racer_HasBomb(*(var1 + 0)) && (*(var1 + 8) == 0))
   {
       var4 = 1;
       Racer_SetIconType(*(var1 + 0), 15);
       if ((var5 <= 0) || ((var5 % 2) == 0))
       {
           Racer_HideIcon(*(var1 + 0), 0);
       }
       else
       {
           Racer_HideIcon(*(var1 + 0), 1);
       }
       var6.v0 = 0.9f;
       var6.v1 = 0.9f;
       var6.v2 = 0.9f;
       Racer_SetIconColor(*(var1 + 0), &var6);
   }
   else
   {
       var4 = 1;
       var9 = Ctf_GetRacerHeldFlagIndex(var0, *(var1 + 0));
       if (var9 >= 0)
       {
           var10 = Ctf_GetFlagColor(var0, var9);
           var11.v0 = 1.0f;
           var11.v1 = 0.9f;
           var11.v2 = 0.0f;
           if (var10 == 2)
           {
               var11.v0 = 0.7f;
               var11.v1 = 0.2f;
               var11.v2 = 0.2f;
           }
           else if (var10 == 1)
           {
               var11.v0 = 0.2f;
               var11.v1 = 0.2f;
               var11.v2 = 0.7f;
           }
           Racer_SetIconType(*(var1 + 0), 12);
           Racer_SetIconColor(*(var1 + 0), &var11);
           if ((var5 <= 0) || ((var5 % 2) == 0))
           {
               Racer_HideIcon(*(var1 + 0), 0);
           }
           else
           {
               Racer_HideIcon(*(var1 + 0), 1);
           }
       }
       else
       {
           var4 = 1;
           Racer_SetIconType(*(var1 + 0), 0);
           Racer_HideIcon(*(var1 + 0), 1);
       }
   }
   if (Net_IsDeadGamer(*(var1 + 0)))
   {
       *(var1 + 16) = null;
   }
   else
   {
       var14 = mcHudMapServer_HasElement(*(var1 + 16));
       if (var4 && (!var14))
       {
           mcHudMapServer_AddElement(*(var1 + 16));
       }
       else if ((!var4) && var14)
       {
           mcHudMapServer_RemoveElement(*(var1 + 16));
       }
   }
}

void sub_37a7(var0)
{
   auto var3, var4;

   var3 = *(var0 + 3092);
   if (var3 == 10)
   {
       sub_37c4(var0);
   }
   else if (var3 == 9)
   {
       sub_37c4(var0);
   }
   else if (var3 == 8)
   {
       sub_39d2(var0);
   }
   else if (var3 == 12)
   {
       sub_37c4(var0);
   }
   else if (var3 == 11)
   {
       sub_39d2(var0);
   }
   else if (var3 == 13)
   {
       sub_3b12(var0);
   }
   else
   {
       PRINTSTRING("[ctfscript] UpdateRankings Error, unsupported race subtype!\n");
   }
}

void sub_37c4(var0)
{
   auto var3, var4, var5, var6, var7;

   var4 = 0;
   var5 = 0;
   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       if (!Net_IsPlayerDisconnected((*(var0 + 4))[var3 * 48].v0))
       {
           if ((*(var0 + 4))[var3 * 48].v42 == 1)
           {
               var5 = var5 + 1;
           }
           else
           {
               var4 = var4 + 1;
           }
       }
       var3 = var3 + 1;
   }
   if ((var4 != 0) && (var5 != 0))
   {
       if ((*(var0 + 3164))[1] > (*(var0 + 3164))[2])
       {
           var6 = 1;
       }
       else if ((*(var0 + 3164))[1] < (*(var0 + 3164))[2])
       {
           var6 = 2;
       }
       else
       {
           var6 = 0;
       }
   }
   else if (*(var0 + 3080) > 1)
   {
       if (var4 == 0)
       {
           PRINTSTRING("No one is left on the red team, BLUE wins\n");
           var6 = 1;
           (*(var0 + 3164))[2] = -1;
       }
       else
       {
           PRINTSTRING("No one is left on the blue team, RED wins\n");
           var6 = 2;
           (*(var0 + 3164))[1] = -1;
       }
   }
   var3 = 0;
   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       if (var6 == 0)
       {
           (*(var0 + 4))[var3 * 48].v41 = 1;
       }
       else if ((*(var0 + 4))[var3 * 48].v42 == var6)
       {
           (*(var0 + 4))[var3 * 48].v41 = 1;
       }
       else
       {
           (*(var0 + 4))[var3 * 48].v41 = 2;
       }
       var3 = var3 + 1;
   }
}

void sub_39d2(var0)
{
   auto var3, var4, var5;

   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       (*(var0 + 4))[var3 * 48].v41 = 1;
       var4 = 0;
       while (var4 < *(var0 + 3080))
       {
           if ((var3 != var4) && ((*(var0 + 4))[var3 * 48].v47 < (*(var0 + 4))[var4 * 48].v47))
           {
               if (*(var0 + 3120))
               {
                   if ((!Net_IsPlayerDisconnected((*(var0 + 4))[var4 * 48].v0)) && (!Net_IsPlayerInvalid((*(var0 + 4))[var4 * 48].v0)))
                   {
                       (*(var0 + 4))[var3 * 48].v41 = (*(var0 + 4))[var3 * 48].v41 + 1;
                   }
               }
               else
               {
                   (*(var0 + 4))[var3 * 48].v41 = (*(var0 + 4))[var3 * 48].v41 + 1;
               }
           }
           var4 = var4 + 1;
       }
       var3 = var3 + 1;
   }
}

void sub_3b12(var0)
{
   auto var3, var4, var5, var6, var7;

   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       (*(var0 + 4))[var3 * 48].v41 = 1;
       var5 = Ctf_GetFlagHeldTime((*(var0 + 4))[var3 * 48].v0);
       var4 = 0;
       while (var4 < *(var0 + 3080))
       {
           var6 = Ctf_GetFlagHeldTime((*(var0 + 4))[var4 * 48].v0);
           if ((var3 != var4) && (var5 < var6))
           {
               if (*(var0 + 3120))
               {
                   if ((!Net_IsPlayerDisconnected((*(var0 + 4))[var4 * 48].v0)) && (!Net_IsPlayerInvalid((*(var0 + 4))[var4 * 48].v0)))
                   {
                       (*(var0 + 4))[var3 * 48].v41 = (*(var0 + 4))[var3 * 48].v41 + 1;
                   }
               }
               else
               {
                   (*(var0 + 4))[var3 * 48].v41 = (*(var0 + 4))[var3 * 48].v41 + 1;
               }
           }
           var4 = var4 + 1;
       }
       var3 = var3 + 1;
   }
}

function sub_3c81(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9;

   var4 = *((var1 + 16) + 3092);
   if (*((var1 + 16) + 3120))
   {
       if ((Net_IsRankedMode() || Net_IsCruiseMode()) && (*((var1 + 16) + 3080) > 1))
       {
           if (sub_3cc5(var1))
           {
               PRINTSTRING("Script: Everyone disconnected, local player wins by default\n");
               var5 = sub_1dc6(var1);
               if (var5 >= 0)
               {
                   (*((var1 + 16) + 4))[var5 * 48].v41 = 1;
               }
               if (var4 == 13)
               {
                   var6 = 0;
                   while (var6 < *((var1 + 16) + 3080))
                   {
                       var7 = (*((var1 + 16) + 4))[var6 * 48].v0;
                       if (Racer_IsLocalPlayer(var7) && (Ctf_GetFlagPickUpTime(var7) > 0))
                       {
                           Ctf_AddFlagHeldTime(Race_GetTimer(*(var1 + 12)) - Ctf_GetFlagPickUpTime(var7));
                           Ctf_SetFlagPickUpTime(0);
                       }
                       var6 = var6 + 1;
                   }
               }
               return 1;
           }
       }
   }
   if (((var4 == 10) || (var4 == 9)) || (var4 == 12))
   {
       return sub_3e68(var0, var1);
   }
   else if ((var4 == 8) || (var4 == 11))
   {
       return sub_40d6(var1);
   }
   else if (var4 == 13)
   {
       return sub_42b3(var1);
   }
   else
   {
       PRINTSTRING("[ctfscript] IsCtfFinished Error, unsupported race subtype!\n");
       return 0;
   }
}

function sub_3cc5(var0)
{
   auto var3, var4;

   if (*((var0 + 16) + 3120))
   {
       var3 = 0;
       while (var3 < *((var0 + 16) + 3080))
       {
           if ((*((var0 + 16) + 4))[var3 * 48].v2 == 1)
           {
               if (Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var3 * 48].v0))
               {
               }
               else
               {
                   return 0;
               }
           }
           else
           {
               var3 = var3 + 1;
           }
       }
       PRINTSTRING("Script: Net.sch: WE ARE ALONE\n");
   }
   return 1;
}

function sub_3e68(var0, var1)
{
   auto var4, var5, var6;

   var4 = 0;
   if (EventOptions_GetFlagLimit(*((var1 + 16) + 3160)) > 0)
   {
       if (Ctf_GetTeamScore(var0, 2) >= EventOptions_GetFlagLimit(*((var1 + 16) + 3160)))
       {
           var4 = 1;
           if (Ctf_GetTeamScore(var0, 2) == Ctf_GetTeamScore(var0, 1))
           {
               PRINTSTRING("[ctfscript] Ctf is finished, tie\n");
           }
           else
           {
               PRINTSTRING("[ctfscript] Ctf is finished, Red wins\n");
           }
       }
       else if (Ctf_GetTeamScore(var0, 1) >= EventOptions_GetFlagLimit(*((var1 + 16) + 3160)))
       {
           var4 = 1;
           PRINTSTRING("[ctfscript] Ctf is finished, Blue wins\n");
       }
   }
   if ((!var4) && (EventOptions_GetTimeLimit(*((var1 + 16) + 3160)) > 0))
   {
       if (Race_GetTimer(*(var1 + 12)) > EventOptions_GetTimeLimit(*((var1 + 16) + 3160)))
       {
           SplashManager_Splash(0, 3, "CTF_TIME_EXPIRED", 0.5f, 0, 0);
           if (Ctf_GetTeamScore(var0, 1) > Ctf_GetTeamScore(var0, 2))
           {
               var4 = 1;
               PRINTSTRING("[ctfscript] Ctf is finished, Blue wins\n");
           }
           else if (Ctf_GetTeamScore(var0, 1) < Ctf_GetTeamScore(var0, 2))
           {
               var4 = 1;
               PRINTSTRING("[ctfscript] Ctf is finished, Red wins\n");
           }
           else
           {
               var4 = 1;
               PRINTSTRING("[ctfscript] Ctf is finished, tie\n");
           }
       }
   }
   return var4;
}

function sub_40d6(var0)
{
   auto var3, var4, var5, var6, var7;

   var3 = EventOptions_GetFlagLimit(*((var0 + 16) + 3160));
   if (var3 > 0)
   {
       var4 = 0;
       while (var4 < *((var0 + 16) + 3080))
       {
           if ((*((var0 + 16) + 4))[var4 * 48].v47 >= var3)
           {
               var5 = Racer_GetName((*((var0 + 16) + 4))[var4 * 48].v0);
               PRINTSTRING("[ctfscript] Racer");
               PRINTSTRING(var5);
               PRINTSTRING(" wins with ");
               PRINTINT((*((var0 + 16) + 4))[var4 * 48].v47);
               PRINTSTRING(" points!\n");
               StringTable_SetString("CTF_SPLASH_RACERA_NAME", var5);
               SplashManager_Splash(0, 3, "CTF_SPLASH_PLAYER_WON", 0.5f, 0, 0);
               return 1;
           }
           else
           {
               var4 = var4 + 1;
           }
       }
   }
   if (EventOptions_GetTimeLimit(*((var0 + 16) + 3160)) > 0)
   {
       if (Race_GetTimer(*(var0 + 12)) > EventOptions_GetTimeLimit(*((var0 + 16) + 3160)))
       {
           SplashManager_Splash(0, 3, "CTF_TIME_EXPIRED", 0.5f, 0, 0);
           var6 = 0;
           var4 = 0;
           while (var4 < *((var0 + 16) + 3080))
           {
               if ((*((var0 + 16) + 4))[var4 * 48].v47 > var6)
               {
               }
               var4 = var4 + 1;
           }
           return 1;
       }
   }
   return 0;
}

function sub_42b3(var0)
{
   auto var3, var4, var5, var6;

   var3 = EventOptions_GetTimeLimit(*((var0 + 16) + 3160));
   if (var3 > 0)
   {
       if (Race_GetTimer(*(var0 + 12)) > var3)
       {
           SplashManager_Splash(0, 3, "CTF_TIME_EXPIRED", 0.5f, 0, 0);
           var4 = 0;
           while (var4 < *((var0 + 16) + 3080))
           {
               var5 = (*((var0 + 16) + 4))[var4 * 48].v0;
               if (Racer_IsLocalPlayer(var5) && (Ctf_GetFlagPickUpTime(var5) > 0))
               {
                   Ctf_AddFlagHeldTime(var3 - Ctf_GetFlagPickUpTime(var5));
                   Ctf_SetFlagPickUpTime(0);
               }
               var4 = var4 + 1;
           }
           return 1;
       }
   }
   return 0;
}

void sub_43e3(var0)
{
   auto var3, var4;

   PRINTSTRING("[ctfscript] Skidding to a stop...\n");
   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       Racer_SetCarDrivableState((*(var0 + 4))[var3 * 48].v0, 8);
       var3 = var3 + 1;
   }
   WAITUNWARPED(2000);
   var3 = 0;
   while (var3 < *(var0 + 3080))
   {
       Racer_SetCarDrivableState((*(var0 + 4))[var3 * 48].v0, 0);
       var3 = var3 + 1;
   }
   PRINTSTRING("[ctfscript] I finished skidding out...\n");
}

