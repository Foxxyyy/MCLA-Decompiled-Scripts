void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30;

   Registry_SetValueInt(L[0].v1.v26, 2);
   var2.v0 = 0.0f;
   var2.v1 = 0.0f;
   var2.v2 = 0.0f;
   var5 = sub_2d(0);
   var6 = 0;
   var7 = 0;
   var8 = (float)0;
   var9 = 0;
   var10 = 0;
   var11 = 0;
   var12 = 0;
   var13 = 0;
   var14 = 0;
   var15 = 3;
   var19 = 0;
   var20 = 0;
   var21 = 0;
   var22 = 0;
   var23 = 0;
   var24 = -1;
   var25 = UIManager_GetState("Cruising_Offline");
   var26 = UIManager_GetState("GPSScene");
   if (L[0].v1.v1 == 506)
   {
       var20 = 1;
   }
   if (!var20)
   {
       mcTargetManager_RegisterLocation(L[0].v1.v1, &(L[0].v1.v3));
       mcTargetManager_HideTarget(L[0].v1.v1, 0);
   }
   var30 = 0;
   while (!var14)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var9);
       if (var9 == 1)
       {
           PRINTSTRING("Garage ");
           PRINTSTRING(L[0].v1.v0);
           PRINTSTRING(" was suspended (Script_SuspendAllOpponents was set)\n");
           SetExceptionMask(0);
           mcHudMapServer_RemoveElement(L[0].v1.v2);
           var23 = 0;
           var8 = Racer_DistanceToPoint(var5, &(L[0].v1.v23));
           while (((var9 == 1) || (var8 < 8.0f)) && (!var23))
           {
               if ((var9 != 1) && (var8 < 8.0f))
               {
                   PRINTSTRING("Waiting to unsuspend garage, player is within the trigger\n");
                   if (vhsmState_IsListener(var25))
                   {
                       Registry_GetValueInt(L[0].v1.v26, &var10);
                       if (var10 == 4)
                       {
                           PRINTSTRING("Player selected Go To Garage, force unsuspend!\n");
                           var23 = 1;
                       }
                   }
               }
               Registry_GetValueInt("Script_SuspendAllOpponents", &var9);
               var8 = Racer_DistanceToPoint(var5, &(L[0].v1.v23));
               WAITUNWARPED(100);
           }
           PRINTSTRING("Garage ");
           PRINTSTRING(L[0].v1.v0);
           PRINTSTRING(" was un-suspended (Script_SuspendAllOpponents was reset)\n");
           mcHudMapServer_AddElement(L[0].v1.v2);
           SetExceptionMask(2);
       }
       if (vhsmState_IsListener(var25))
       {
           Registry_GetValueInt(L[0].v1.v26, &var10);
           if (var10 == 4)
           {
           }
           else
           {
               Registry_GetValueInt("NET_UNLOADCAREER", &var12);
               if (((((PoliceManager_CheckPoliceActivity(1) > 1) || var20) || Net_IsConnecting()) || Net_IsNetworked()) || (var12 > 0))
               {
                   WAITUNWARPED(100);
               }
               else
               {
                   var8 = Racer_DistanceToPoint(var5, &(L[0].v1.v23));
                   if ((!Game_IsPaused()) && (var8 < 8.0f))
                   {
                   }
               }
           }
           PoliceManager_DestroyAllPolice();
           mcGame_ThrowEvent("garage");
           Warper_SetIsWarpingToCutscene(1);
           Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", L[0].v1.v1, &(L[0].v1.v6), &(L[0].v1.v9), &(L[0].v1.v12), "WarpFromCarToWaitPosition_CarneySign");
           while (!Warper_IsReadyToLoadStuff())
           {
               WAITUNWARPED(30);
               PRINTSTRING("Transitioning to neutral point\n");
           }
           PRINTSTRING("Reached neutral point\n");
           if (!var20)
           {
               StatsManager_UpdateStatInt("tGAR", 0, 3, 1);
           }
           PRINTSTRING("GARAGE TRIGGERED\n");
           Registry_SetValueInt("EXITGARAGE_TRIG", 0);
           Registry_SetValueInt(L[0].v1.v26, 3);
           mcHudMapServer_RemoveElement(L[0].v1.v2);
           Racer_Deactivate(var5);
           mcEvent_PostEventStr("LOCATION_EVENT", L[0].v1.v0);
           WAITUNWARPED(500);
           mcEvent_PostEventStr("MISSION_EVENT", L[0].v1.v27);
           Registry_GetValueInt(L[0].v1.v26, &var10);
           while (var10 == 3)
           {
               Racer_SetScrambleInputFlags(var5, 1030);
               Registry_GetValueInt(L[0].v1.v26, &var10);
               WAITUNWARPED(100);
           }
           if (!var20)
           {
               sub_638(0, 1, 0x3f800000, 0);
           }
           PRINTSTRING("Ready to display UI\n");
           if (var10 == 5)
           {
               PRINTSTRING("SCRIPT: streaming garage movie\n");
               UIManager_StreamMovie("GARAGEMOVIE", "garage/garage.swf", 5500, 5500, 10000, 0, 1);
               while (UIManager_FindMovie("GARAGEMOVIE") == null)
               {
                   PRINTSTRING("Waiting for garage movie to stream in...\n");
                   WAITUNWARPED(100);
               }
               sub_a68(L[0].v1.v29, &var15, &(L[0].v1.v30), &(L[0].v1.v34), &(L[0].v1.v44));
               if (var21)
               {
                   var21 = 0;
                   Garage_TransitionOutOfTestDrive();
               }
               else if (var20)
               {
                   UIManager_SendEvent("ratemyrideTransition");
               }
               else
               {
                   UIManager_SendEvent("garageTransition");
               }
               Racer_SetScrambleInputFlags(var5, 1028);
               var11 = 0;
               var13 = 0;
               while (var11 == 0)
               {
                   Registry_GetValueInt("EXITGARAGE_TRIG", &var11);
                   Registry_GetValueInt("EXITGARAGE_TESTDRIVE", &var13);
                   if (var13 == 1)
                   {
                       var21 = 1;
                       Registry_SetValueInt("EXITGARAGE_TESTDRIVE", 0);
                       sub_bf1(1, 1, 0x3f800000, 0);
                       Garage_TransitionToTestDrive();
                       sub_f33(L[0].v0, L[0].v1, L[0].v2, L[0].v3, L[0].v4, L[0].v5, L[0].v6, L[0].v7, L[0].v8, L[0].v9, L[0].v10, L[0].v11, L[0].v12, L[0].v13, L[0].v14, L[0].v15, L[0].v16, L[0].v17, L[0].v18, L[0].v19, L[0].v20, L[0].v21, L[0].v22, L[0].v23, L[0].v24, L[0].v25, L[0].v26, L[0].v27, L[0].v28, L[0].v29, L[0].v30, L[0].v31, L[0].v32, L[0].v33, L[0].v34, L[0].v35, L[0].v36, L[0].v37, L[0].v38, L[0].v39, L[0].v40, L[0].v41, L[0].v42, L[0].v43, L[0].v44, L[0].v45, L[0].v46, L[0].v47, L[0].v48);
                       Registry_SetValueInt(L[0].v1.v26, 6);
                       sub_1318(L[0].v1.v29, &var15);
                       UIManager_UnloadMovie("GARAGEMOVIE");
                       mcHudMapServer_AddElement(L[0].v1.v2);
                       Registry_GetValueInt(L[0].v1.v26, &var10);
                       while (var10 == 6)
                       {
                           Registry_GetValueInt(L[0].v1.v26, &var10);
                           var8 = Racer_DistanceToPoint(var5, &(L[0].v1.v23));
                           if (var8 < 8.0f)
                           {
                               Registry_SetValueInt(L[0].v1.v26, 5);
                           }
                           WAITUNWARPED(100);
                       }
                       if (var10 == 7)
                       {
                           var21 = 0;
                           sub_bf1(1, 1, 0x3f800000, 0);
                           Garage_TransitionOutOfTestDriveShort();
                           mcHudMapServer_RemoveElement(L[0].v1.v2);
                       }
                       else
                       {
                           sub_1448(L[0].v0, L[0].v1, L[0].v2, L[0].v3, L[0].v4, L[0].v5, L[0].v6, L[0].v7, L[0].v8, L[0].v9, L[0].v10, L[0].v11, L[0].v12, L[0].v13, L[0].v14, L[0].v15, L[0].v16, L[0].v17, L[0].v18, L[0].v19, L[0].v20, L[0].v21, L[0].v22, L[0].v23, L[0].v24, L[0].v25, L[0].v26, L[0].v27, L[0].v28, L[0].v29, L[0].v30, L[0].v31, L[0].v32, L[0].v33, L[0].v34, L[0].v35, L[0].v36, L[0].v37, L[0].v38, L[0].v39, L[0].v40, L[0].v41, L[0].v42, L[0].v43, L[0].v44, L[0].v45, L[0].v46, L[0].v47, L[0].v48);
                           mcHudMapServer_RemoveElement(L[0].v1.v2);
                       }
                   }
                   else
                   {
                       WAITUNWARPED(100);
                   }
               }
               sub_1318(L[0].v1.v29, &var15);
               UIManager_UnloadMovie("GARAGEMOVIE");
               while (!Racer_IsVinylStreamed(var5))
               {
                   WAITUNWARPED(30);
               }
               if (var20)
               {
                   Garage_TransitionOutOfRateMyRide();
               }
               else
               {
                   Garage_TransitionOutOfGarage();
               }
               mcEvent_PostEventStr("MISSION_EVENT", L[0].v1.v28);
               Racer_Activate(var5);
               WAITUNWARPED(1000);
               while (CineScript_IsScenePlaying() || UIManager_IsDisplayingMenu())
               {
                   WAITUNWARPED(100);
               }
               if (!var20)
               {
                   Registry_GetValueInt("NET_UNLOADCAREER", &var11);
                   if (var11 < 1)
                   {
                       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                       WAITUNWARPED(1000);
                       while (UIManager_IsSaving())
                       {
                           WAITUNWARPED(100);
                       }
                       var22 = 1;
                       if (!GetNoTutorialCommandLine())
                       {
                           if (Racer_IsMotorcycle(var5) && (StatsManager_GetIntValue("tTMO", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTMO", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 88, "TUTORIAL_MOTORCYCLE_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                           while (vhsmState_IsActive(var26) || FlashNavigator_IsTransitioning())
                           {
                               Registry_GetValueInt("NET_UNLOADCAREER", &var11);
                               if (var11 > 0)
                               {
                               }
                               else
                               {
                                   WAITUNWARPED(100);
                               }
                           }
                           var24 = Racer_GetActiveAbility(var5);
                           if ((var24 == 0) && (StatsManager_GetIntValue("tTZO", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTZO", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 90, "TUTORIAL_ZONE_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                           else if ((var24 == 1) && (StatsManager_GetIntValue("tTAG", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTAG", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 91, "TUTORIAL_AGRO_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                           else if ((var24 == 2) && (StatsManager_GetIntValue("tTRO", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTRO", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 92, "TUTORIAL_ROAR_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                           else if ((var24 == 3) && (StatsManager_GetIntValue("tTEM", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTEM", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 93, "TUTORIAL_EMP_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                           if (Racer_AreHydraulicsInstalled(var5) && (StatsManager_GetIntValue("tTHY", 0) == 0))
                           {
                               StatsManager_UpdateStatInt("tTHY", 0, 3, 1);
                               AudioManager_SetActiveTimeSlow(1);
                               sub_1654(0, 0x3f000000, 108);
                               sub_16eb(-1, 111, "TUTORIAL_HYDRAULICS_INGAME", "drv_mb_04_set", "PLAYER");
                               AudioManager_SetActiveTimeSlow(0);
                               sub_17a0(108, 0x3f000000);
                           }
                       }
                   }
               }
           }
           else
           {
               UIManager_UnloadMovie("GARAGEMOVIE");
           }
           mcGame_ThrowEvent("cruising");
           sub_1ba5();
           if (var22)
           {
               sub_1d2a();
               var22 = 0;
           }
           Racer_SetScrambleInputFlags(var5, 0);
           mcHudMapServer_AddElement(L[0].v1.v2);
           Registry_SetValueInt(L[0].v1.v26, 2);
       }
       WAITUNWARPED(100);
   }
   Registry_SetValueInt(L[0].v1.v26, 0);
   if (!var20)
   {
       mcTargetManager_HideTarget(L[0].v1.v1, 1);
   }
}

function sub_2d(var0)
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

void sub_638(var0, var1, var2, var3)
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

void sub_a68(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13;

   var7 = 0;
   while (var7 < var0)
   {
       (*var1)[var7] = OpponentManager_CreateOpponent();
       OpponentManager_LoadOpponent((*var1)[var7], (*var2)[var7], &((*var3)[var7 * 3]), (*var4)[var7]);
       OpponentManager_AddOpponentToWorld((*var1)[var7]);
       var8 = Opponent_GetRacer((*var1)[var7]);
       Racer_SetStreamingLockedIn(var8);
       Racer_SetUID(var8, 201 + var7);
       Racer_SetVehicleDriverEnable(var8, 0);
       var7 = var7 + 1;
   }
}

void sub_bf1(var0, var1, var2, var3)
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

void sub_f33(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48)
{
   auto var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103;

   AmbientMgr_DisableTraffic(1);
   PropManager_ResetProps();
   var51 = sub_2d(0);
   sub_f5c(var51, 0);
   sub_fde(var51);
   Garage_TransitionOutOfGarage();
   Racer_InitializeResetPosition(var51, &(var0.v1.v19), var0.v1.v22);
   if (var0.v1.v1 == 505)
   {
       PRINTSTRING("HW Test drive ");
       var52 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/cut_la_hw_oh_garage_01x_ext_generated", &null, 0, 1500);
       while (!IsChildFinished(var52))
       {
           WAITUNWARPED(10);
       }
   }
   else if (var0.v1.v1 == 512)
   {
       PRINTSTRING("BE Test drive ");
       var53 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/cut_la_be_smb_garage_01x_ext_generated", &null, 0, 1500);
       while (!IsChildFinished(var53))
       {
           WAITUNWARPED(10);
       }
   }
   else if (var0.v1.v1 == 543)
   {
       PRINTSTRING("SC Test drive ");
       var54 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/sc_cut_garage_01_ext_generated", &null, 0, 1500);
       while (!IsChildFinished(var53))
       {
           WAITUNWARPED(10);
       }
   }
   if (var0.v1.v1 == 505)
   {
       CineScript_Prop_UnloadSetDressing("cut_la_hw_oh_garage_set_items");
   }
   else if (var0.v1.v1 == 512)
   {
       CineScript_Prop_UnloadSetDressing("cut_la_be_smb_garage_set_items");
   }
   else if (var0.v1.v1 == 543)
   {
       CineScript_Prop_UnloadSetDressing("cut_sc_cs_junkyard_garage_set_items");
   }
   AmbientMgr_DisableTraffic(0);
   Racer_Activate(var51);
}

void sub_f5c(var0, var1)
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

void sub_fde(var0)
{
   auto var3;

   while (!Racer_IsCarStreamed(var0))
   {
       PRINTSTRING("Waiting for racer to be streamed\n");
       WAITUNWARPED(10);
   }
}

void sub_1318(var0, var1)
{
   auto var4, var5, var6;

   var4 = 0;
   while (var4 < var0)
   {
       if ((*var1)[var4] != null)
       {
           OpponentManager_RemoveOpponentFromWorld((*var1)[var4]);
           OpponentManager_DeleteOpponent((*var1)[var4]);
           (*var1)[var4] = null;
       }
       var4 = var4 + 1;
   }
}

void sub_1448(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48)
{
   auto var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100;

   AmbientMgr_DisableTraffic(1);
   PropManager_ResetProps();
   var51 = sub_2d(0);
   Racer_InitializeResetPosition(var51, &(var0.v1.v15), var0.v1.v18);
   Racer_Reset(var51);
   Registry_SetValueInt("hw_garage_state", 5);
   AmbientMgr_DisableTraffic(0);
}

void sub_1654(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_16eb(var0, var1, var2, var3, var4)
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

void sub_17a0(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

void sub_1ba5()
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

void sub_1d2a()
{
   mcSlotSystem_ClearAllDistricts();
   while (!mcSlotSystem_AreDistrictsClean())
   {
       PRINTSTRING("Waiting for districts to be purged\n");
       WAITUNWARPED(100);
   }
   WAITUNWARPED(300);
   mcSlotSystem_EvaluateAllDistricts();
}

