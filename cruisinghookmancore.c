void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24;

   mcRacerManager_ToggleRacerFlashedFlag(0);
   var2 = mcHookman_GetId(L[0].v97.v0);
   var3 = mcHookman_GetType(L[0].v97.v0);
   var4 = Opponent_GetRacer(L[0].v97.v1);
   var5 = sub_48(0);
   var6 = UIManager_GetState("GPSScene");
   var7 = UIManager_GetState("Cruising_Offline");
   var8 = 0;
   var9 = 0;
   var10 = 0;
   var11 = 0;
   var13 = 0;
   var17 = 0;
   var18 = 0;
   var19 = 0.0f;
   var20 = null;
   var21 = null;
   Racer_HideIcon(var4, 0);
   var22 = mcHookman_IsHidden(L[0].v97.v0);
   var23 = var22;
   if (!var22)
   {
       if (L[0].v101)
       {
           Racer_HideIcon(var4, 1);
           mcHudMapServer_RemoveElement(L[0].v97.v2);
           mcTargetManager_HideTarget(var2, 1);
       }
       else
       {
           mcHudMapServer_AddElement(L[0].v97.v2);
           mcTargetManager_HideTarget(var2, 0);
       }
   }
   SetExceptionMask(2);
   var24 = ;
   if (var24 == 2)
   {
       PRINTSTRING("restart exception\n");
   }
   else
   {
       var20 = BrainFactory_CreateBrainCruising(var4);
   }
   var18 = 0;
   if (L[0].v100)
   {
       var10 = 1;
       Racer_InitializeResetPosition(var4, &(L[0].v0[0 * 3]), L[0].v95);
       Racer_Reset(var4);
   }
   else
   {
       Racer_GetPosition(var4, &var14);
       var10 = sub_1f9(var14.v0, var14.v1, var14.v2, &(L[0].v0), L[0].v94);
   }
   if (L[0].v94 > 1)
   {
       BrainCruising_SetCurrentDest(var20, &(L[0].v0[var10 * 3]));
       var11 = var10;
       var12 = 2;
       while (var12 <= L[0].v94)
       {
           var11 = var11 + 1;
           if (var11 >= L[0].v94)
           {
               var11 = 0;
           }
           BrainCruising_AppendDest(var20, &(L[0].v0[var11 * 3]));
           var12 = var12 + 1;
       }
       BrainCruising_SetLooping(var20, 1);
   }
   if (L[0].v100)
   {
       BrainCruising_TeleportToNearestRail(var20);
   }
   else
   {
       BrainCruising_DriveToNearestRail(var20);
   }
   Racer_Activate(var4);
   while (!var17)
   {
       var22 = mcHookman_IsHidden(L[0].v97.v0);
       if ((!var22) && var23)
       {
           mcSlotSystem_UnlockSlot(L[0].v97.v0);
           mcTargetManager_HideTarget(var2, 0);
           mcHudMapServer_AddElement(L[0].v97.v2);
       }
       var23 = var22;
       Registry_GetValueInt("Script_SuspendAllOpponents", &var18);
       if (var18 == 1)
       {
           PRINTSTRING("CRUISING HOOKMAN - ");
           PRINTINT(var2);
           PRINTSTRING(" - has been suspended.\n");
           if (!var22)
           {
               Racer_HideIcon(var4, 1);
               mcHudMapServer_RemoveElement(L[0].v97.v2);
               mcTargetManager_HideTarget(var2, 1);
           }
           SetExceptionMask(0);
           Racer_SetStreamingLockedOut(var4);
           Racer_Reset(var4);
           while (var18 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var18);
               if (IsExitFlagSet())
               {
                   PRINTSTRING("CRUISING HOOKMAN - ");
                   PRINTINT(var2);
                   PRINTSTRING(" - Shutting down\n");
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           PRINTSTRING("CRUISING HOOKMAN - ");
           PRINTINT(var2);
           PRINTSTRING(" - has been unsuspended.\n");
           Racer_SetStreamingUnlocked(var4);
           if (mcHookman_GetState(L[0].v97.v0) == 4)
           {
           }
           else
           {
               if (var3 == 0)
               {
                   var13 = sub_5a6(var4);
                   mcHookman_SetDifficulty(L[0].v97.v0, var13);
               }
               Racer_SetIconColorByDifficulty(var4, mcHookman_GetDifficulty(L[0].v97.v0));
               SetExceptionMask(2);
               var22 = mcHookman_IsHidden(L[0].v97.v0);
               if ((!var22) && (!L[0].v101))
               {
                   Racer_HideIcon(var4, 0);
                   mcHudMapServer_AddElement(L[0].v97.v2);
                   mcTargetManager_HideTarget(var2, 0);
               }
               if (Racer_IsBrainValid(var4))
               {
               }
           }
       }
       if ((mcHookman_GetState(L[0].v97.v0) == 4) || IsExitFlagSet())
       {
       }
       else if (L[0].v101)
       {
           var11 = BrainCruising_GetCurrentDestinationIndex(var20);
           if (var11 != 0)
           {
               L[0].v101 = 0;
           }
           if (Racer_GetLoadState(var4) == 0)
           {
               L[0].v101 = 0;
               Racer_InitializeResetPosition(var4, &(L[0].v0[BrainCruising_GetCurrentDestinationIndex(var20) * 3]), L[0].v95);
               BrainCruising_TeleportToNextDestination(var20);
           }
           if ((!L[0].v101) && (!var22))
           {
               Racer_HideIcon(var4, 0);
               mcHudMapServer_AddElement(L[0].v97.v2);
               mcTargetManager_HideTarget(var2, 0);
           }
       }
       else if (((vhsmState_IsListener(var7) && (!Game_IsPaused())) && (!Player_IsInIdleCam(0))) && (PoliceManager_CheckPoliceActivity(1) < 2))
       {
           if (var5 == null)
           {
               var5 = Player_FindRacerObject(0);
               WAITUNWARPED(100);
           }
           else if ((!UIManager_IsDisplayingMenu()) || (var21 != null))
           {
               var19 = Racer_DistanceBetween(var5, var4);
               if ((!CineScript_IsScenePlaying()) && var22)
               {
                   if (var19 < ((float)80))
                   {
                       PRINTSTRING("CRUISING HOOKMAN - ");
                       PRINTINT(var2);
                       PRINTSTRING(" - Discovered.\n");
                       if (var3 == 5)
                       {
                           SplashManager_Splash(0, 4, "HOOKMAN_FOUND_FREEWAY", 0x40000000, 1, 0);
                           AudioManager_PlayFrontendSound("RACER_FOUND_MASTER");
                       }
                       else if (var3 == 2)
                       {
                           SplashManager_Splash(0, 4, "HOOKMAN_FOUND_REDLIGHT", 0x40000000, 1, 0);
                           AudioManager_PlayFrontendSound("RACER_FOUND_MASTER");
                       }
                       mcHookman_Hide(L[0].v97.v0, 0);
                   }
               }
               if (((!CineScript_IsScenePlaying()) && (!mcRacerManager_HasRacerBeenFlashed())) && Racer_CanFlashHookman(var5, var4, var19))
               {
                   var9 = Player_FlashingHighbeams(0);
                   if (!GetNoTutorialCommandLine())
                   {
                       if (!var8)
                       {
                           if (StatsManager_GetIntValue("tTFL", 0) == 0)
                           {
                               var21 = Form_GetForm(82);
                           }
                           else if (StatsManager_GetIntValue("tTFB", 0) == 0)
                           {
                               var21 = Form_GetForm(83);
                           }
                           if (var21 != null)
                           {
                               Form_ShowForm(Form_GetForm(-1), var21);
                           }
                           var8 = 1;
                       }
                       if ((var3 == 2) && (StatsManager_GetIntValue("tTRL", 0) == 0))
                       {
                           StatsManager_UpdateStatInt("tTRL", 0, 3, 1);
                           AudioManager_SetActiveTimeSlow(1);
                           sub_99f(0, 0x3f000000, 108);
                           sub_a34(-1, 86, "TUTORIAL_REDLIGHT_INGAME", "drv_mb_04_set", "PLAYER");
                           AudioManager_SetActiveTimeSlow(0);
                           sub_ae9(108, 0x3f000000);
                           var9 = 0;
                       }
                       else if ((var3 == 5) && (StatsManager_GetIntValue("tTFR", 0) == 0))
                       {
                           StatsManager_UpdateStatInt("tTFR", 0, 3, 1);
                           AudioManager_SetActiveTimeSlow(1);
                           sub_99f(0, 0x3f000000, 108);
                           sub_a34(-1, 87, "TUTORIAL_FREEWAY_INGAME", "drv_mb_04_set", "PLAYER");
                           AudioManager_SetActiveTimeSlow(0);
                           sub_ae9(108, 0x3f000000);
                           var9 = 0;
                       }
                       else if ((var3 == 4) && (StatsManager_GetIntValue("tTTO", 0) == 0))
                       {
                           StatsManager_UpdateStatInt("tTTO", 0, 3, 1);
                           AudioManager_SetActiveTimeSlow(1);
                           sub_99f(0, 0x3f000000, 108);
                           sub_a34(-1, 95, "TUTORIAL_TOURNAMENT_INGAME", "drv_mb_04_set", "PLAYER");
                           AudioManager_SetActiveTimeSlow(0);
                           sub_ae9(108, 0x3f000000);
                           var9 = 0;
                       }
                       else if ((var3 == 3) && (StatsManager_GetIntValue("tTTT", 0) == 0))
                       {
                           StatsManager_UpdateStatInt("tTTT", 0, 3, 1);
                           AudioManager_SetActiveTimeSlow(1);
                           sub_99f(0, 0x3f000000, 108);
                           sub_a34(-1, 96, "TUTORIAL_TIME_TRIAL_INGAME", "drv_mb_04_set", "PLAYER");
                           AudioManager_SetActiveTimeSlow(0);
                           sub_ae9(108, 0x3f000000);
                           var9 = 0;
                       }
                   }
                   if (var9 && (!(Racer_GetIconType(var4) == 0)))
                   {
                       if (!vhsmState_IsActive(var6))
                       {
                           if ((var21 != null) && Form_GetFormVisible(var21))
                           {
                               Form_CloseForm(var21);
                               if (StatsManager_GetIntValue("tTFL", 0) == 0)
                               {
                                   StatsManager_UpdateStatInt("tTFL", 0, 3, 1);
                               }
                               else if (StatsManager_GetIntValue("tTFB", 0) == 0)
                               {
                                   StatsManager_UpdateStatInt("tTFB", 0, 3, 1);
                               }
                           }
                           var17 = 1;
                           mcRacerManager_ToggleRacerFlashedFlag(1);
                       }
                   }
               }
               else if (((var21 != null) && Form_GetFormVisible(var21)) && var8)
               {
                   Form_CloseForm(var21);
                   var8 = 0;
               }
           }
       }
       if (!var17)
       {
           WAITUNWARPED(10);
       }
   }
   PRINTSTRING("CRUISING HOOKMAN - ");
   PRINTINT(var2);
   PRINTSTRING(" - has been flashed.\n");
   Racer_HideIcon(var4, 1);
   if (!L[0].v102)
   {
       BrainCruising_RemoveFromTraffic(var20);
       sub_ea9(L[0].v97.v1);
   }
   PRINTSTRING("CRUISING HOOKMAN - ");
   PRINTINT(var2);
   PRINTSTRING(" - has been shut down.\n");
}

function sub_48(var0)
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

function sub_1f9(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22;

   var8 = 0;
   var9 = 10000.0f;
   var7 = 0;
   while (var7 < var4)
   {
       var10 = VDIST(var0.v0, var0.v1, var0.v2, (*var3)[var7 * 3].v0, (*var3)[var7 * 3].v1, (*var3)[var7 * 3].v2);
       if (var10 < var9)
       {
           var9 = var10;
           var8 = var7;
       }
       var7 = var7 + 1;
   }
   var11 = var8 + 1;
   if (var11 >= var4)
   {
       var11 = 0;
   }
   var12.v0 = (*var3)[var8 * 3].v0 - var0.v0;
   var12.v1 = (*var3)[var8 * 3].v1 - var0.v1;
   var12.v2 = (*var3)[var8 * 3].v2 - var0.v2;
   var15.v0 = (*var3)[var8 * 3].v0 - (*var3)[var11 * 3].v0;
   var15.v1 = (*var3)[var8 * 3].v1 - (*var3)[var11 * 3].v1;
   var15.v2 = (*var3)[var8 * 3].v2 - (*var3)[var11 * 3].v2;
   if ((Math_VecDot(&var12, &var15) > 0.0f) || (VDIST(var0.v0, var0.v1, var0.v2, (*var3)[var8 * 3].v0, (*var3)[var8 * 3].v1, (*var3)[var8 * 3].v2) < 1.0f))
   {
       var8 = var11;
   }
   return var8;
}

function sub_5a6(var0)
{
   auto var3, var4;

   var3 = mcCareer_GetDifficultyPlayerVsRacer(var0);
   if (var3 == 0)
   {
       return 1;
   }
   else
   {
       return var3;
   }
}

void sub_99f(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_a34(var0, var1, var2, var3, var4)
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

void sub_ae9(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

void sub_ea9(var0)
{
   auto var3;

   BrainFactory_DeleteBrain(Opponent_GetRacer(var0));
}

