void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68;

   var2 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   var3.v0 = 1658.652f;
   var3.v1 = -1.997f;
   var3.v2 = 224.921f;
   mcTargetManager_RegisterLocation(602, &var3);
   mcTargetManager_HideTarget(602, 0);
   var6 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetElement(var6, 9, 602, &var3, (float)0);
   mcHudMapServer_AddElement(var6);
   var7.v0 = 1675.63f;
   var7.v1 = -2.99f;
   var7.v2 = 219.23f;
   var10 = 148.78f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var7, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var11 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var11, var2, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var11, mcHookman_GetModValue(L[0].v0.v97.v0));
   Racer_SetVehicleDriverEnable(var11, 0);
   Racer_InitializeResetPosition(var11, &var7, var10);
   Racer_Reset(var11);
   Racer_SetHeadlights(var11, 0);
   Racer_SetExhaust(var11, 0);
   Racer_Deactivate(var11);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, mcCareer_GetDifficultyPlayerVsRacer(var11));
   Racer_HideIcon(var11, 1);
   var12 = UIManager_GetState("Cruising_Offline");
   var13 = sub_1be(0);
   var14 = 0.0f;
   var15 = 0.0f;
   var16 = 0;
   var17 = 0;
   var18 = 0;
   var19 = 0;
   var20 = null;
   var21.v2.v0.v0 = 0.0f;
   var21.v2.v0.v1 = 0.0f;
   var21.v2.v0.v2 = 0.0f;
   var21.v2.v3 = 0.0f;
   var27.v0 = 1658.834f;
   var27.v1 = 1.44f;
   var27.v2 = 230.878f;
   var30.v0 = 1658.365f;
   var30.v1 = 5.153f;
   var30.v2 = 231.521f;
   var33.v0 = 1656.145f;
   var33.v1 = 1.749f;
   var33.v2 = 227.173f;
   var36 = 7;
   var44 = 7;
   var52 = 7;
   var60 = 7;
   var68 = 0;
   while (!var68)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var18);
       if (var18 == 1)
       {
           mcHudMapServer_RemoveElement(var6);
           Racer_SetStreamingLockedOut(var11);
           while (var18 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var18);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var11);
           mcHudMapServer_AddElement(var6);
       }
       var16 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var16 == 1)
       {
           while (var16 == 1)
           {
               var16 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var16 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           if (vhsmState_IsListener(var12) && (!Game_IsPaused()))
           {
               if ((var17 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
               {
                   var17 = var17 - 1;
               }
               var14 = Racer_DistanceToPoint(var13, &var3);
               if ((!Game_IsPaused()) && (var14 < 20.0f))
               {
                   Warper_SetIsWarpingToCutscene(1);
                   if (PoliceManager_CheckPoliceActivity(1) > 1)
                   {
                       if (var17 == 0)
                       {
                           SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                           var17 = 100;
                       }
                       WAITUNWARPED(100);
                   }
                   else
                   {
                       var15 = Graphics_GetTimeOfDay();
                       UILogic_RemoveGPSDestination(0);
                       mcHudMapServer_RemoveElement(var6);
                       mcHookman_SetState(L[0].v0.v97.v0, 1);
                       CineScript_SetGameCoordSysBinding(&var21);
                       sub_4a4(var13, 0);
                       sub_4a4(var11, 1);
                       Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", 602, &var27, &var30, &var33, "WarpFromCarToWaitPosition_CarneySign");
                       while (!Warper_IsReadyToLoadStuff())
                       {
                           WAITUNWARPED(100);
                           PRINTSTRING("Waiting For Camera To Get To Safe Spot\n");
                       }
                       if ((var15 > 6.0f) && (var15 < 18.0f))
                       {
                           var36[0] = "character/ped_mc_006_set";
                           var44[0] = "ped_mc_006_set";
                           var52[0] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[0] = "m_ped00_loop";
                           var36[1] = "character/ped_mc_001_set";
                           var44[1] = "ped_mc_001_set";
                           var52[1] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[1] = "m_ped01_loop";
                           var36[2] = "character/ped_fc_003_set";
                           var44[2] = "ped_fc_003_set";
                           var52[2] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[2] = "f_ped00_loop";
                           var36[3] = "character/ped_fh_007_set";
                           var44[3] = "ped_fh_007_set";
                           var52[3] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[3] = "f_ped01_loop";
                           var36[4] = "character/ped_fa_003_set";
                           var44[4] = "ped_fa_003_set";
                           var52[4] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[4] = "f_ped02_loop";
                           var36[5] = "character/ped_fh_005_set";
                           var44[5] = "ped_fh_005_set";
                           var52[5] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[5] = "f_ped03_loop";
                           var36[6] = "character/ped_mh_003_set";
                           var44[6] = "ped_mh_003_set";
                           var52[6] = "cutscene/hangout/cut_story_district_champs_peds";
                           var60[6] = "m_ped02_loop";
                           sub_9d0(7, &var36, &var44, &var52, &var60);
                           var20 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_district_champs_generated", &null, 0, 1500);
                       }
                       else
                       {
                           var36[0] = "character/ped_ma_005_set";
                           var44[0] = "ped_ma_005_set";
                           var52[0] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[0] = "m_ped00_loop";
                           var36[1] = "character/ped_mh_008_set";
                           var44[1] = "ped_mh_008_set";
                           var52[1] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[1] = "m_ped01_loop";
                           var36[2] = "character/ped_fb_001_set";
                           var44[2] = "ped_fb_001_set";
                           var52[2] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[2] = "f_ped00_loop";
                           var36[3] = "character/ped_fh_009_set";
                           var44[3] = "ped_fh_009_set";
                           var52[3] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[3] = "f_ped01_loop";
                           var36[4] = "character/ped_fb_004_set";
                           var44[4] = "ped_fb_004_set";
                           var52[4] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[4] = "f_ped02_loop";
                           var36[5] = "character/ped_fb_002_set";
                           var44[5] = "ped_fb_002_set";
                           var52[5] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[5] = "f_ped03_loop";
                           var36[6] = "character/ped_mc_001_set";
                           var44[6] = "ped_mc_001_set";
                           var52[6] = "cutscene/hangout/cut_story_district_champs_night_peds";
                           var60[6] = "m_ped02_loop";
                           sub_9d0(7, &var36, &var44, &var52, &var60);
                           var20 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_district_champs_night_generated", &null, 0, 1500);
                       }
                       PostProcessing_SetCutsceneDof();
                       while (!IsChildFinished(var20))
                       {
                           WAITUNWARPED(100);
                       }
                       PostProcessing_SetGameDof();
                       sub_1131(&var52);
                       mcEvent_PostEventStr("MISSION_EVENT", "FIND_SH_01B_OBJ_01_COMPLETE");
                       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                       Racer_Activate(var13);
                       WAITUNWARPED(1000);
                   }
               }
           }
           WAITUNWARPED(30);
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING("\n");
   Racer_HideIcon(var11, 1);
   mcTargetManager_HideTarget(602, 1);
   mcHudMapServer_DeleteElement(var6);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_1be(var0)
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

void sub_4a4(var0, var1)
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

void sub_9d0(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;

   var8 = 0;
   while (!var8)
   {
       var8 = 1;
       var7 = 0;
       while (var7 < var0)
       {
           var8 = var8 && CineScript_Characters_LoadType((*var1)[var7], (*var2)[var7]);
           var7 = var7 + 1;
       }
       WAITUNWARPED(100);
       PRINTSTRING("LoadHangoutCharacters : Streaming characters\n");
   }
   PRINTSTRING("LoadHangoutCharacters : Streaming characters load complete.\n");
   var9 = CineScript_DoesAnimPackExist((*var3)[0]);
   if (var9)
   {
       var10 = (*var3)[0];
       PRINTSTRING("Using Hangout Animpack:  ");
       PRINTSTRING(var10);
       PRINTNL();
       CineScript_StartLoadHangoutAnimPack(var10);
       while (!CineScript_IsLoadedHangoutAnimPack())
       {
           WAITUNWARPED(100);
           PRINTSTRING("LoadHangoutCharacters : Streaming animpack\n");
       }
       PRINTSTRING("LoadHangoutCharacters : Streaming animpack load complete.\n");
       var8 = var8 && 1;
   }
   else
   {
       var7 = 0;
       while (var7 < var0)
       {
           CineScript_Characters_LoadAnimation((*var3)[var7], (*var4)[var7]);
           var7 = var7 + 1;
       }
   }
   var7 = 0;
   while (var7 < var0)
   {
       var15 = CineScript_Characters_LaunchAnimAt((*var1)[var7], (*var2)[var7], (*var3)[var7], (*var4)[var7], &var11, -1);
       CineScript_PushKillBuffer(var15, 0);
       var7 = var7 + 1;
   }
}

void sub_1131(var0)
{
   auto var3, var4;

   CineScript_PopKillBuffer(0);
   var3 = CineScript_DoesAnimPackExist((*var0)[0]);
   if (var3)
   {
       CineScript_ReleaseHangoutAnimPack();
   }
}

