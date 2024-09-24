void main()
{
   auto var2, var3, var4, var5;

   if (L[0].v0 == 3)
   {
   }
   var2 = null;
   if (GetDemoCommandLine())
   {
       mcCareer_StartNewScript("game/Career/CareerSetupPlayer", 1500);
   }
   else
   {
       var3 = START_NEW_SCRIPT_WITH_ARGS("game/Career/CarSelection", &null, 0, 1500);
       while (!IsChildFinished(var3))
       {
           WAITUNWARPED(10);
       }
       mcCareer_StartNewScript("game/Career/CareerSetupPlayer", 1500);
   }
   if (GetUnlockCareerCommandLine())
   {
       mcSlotSystem_HideDistrict(0, 0);
       mcSlotSystem_HideDistrict(1, 0);
       mcSlotSystem_HideDistrict(2, 0);
       mcSlotSystem_HideDistrict(3, 0);
       mcSlotSystem_HideDistrict(4, 0);
       mcSlotSystem_UnlockDistrict(0, 0);
       mcSlotSystem_UnlockDistrict(1, 0);
       mcSlotSystem_UnlockDistrict(2, 0);
       mcSlotSystem_UnlockDistrict(3, 0);
       mcSlotSystem_UnlockDistrict(4, 0);
       mcCareer_UnlockDistrictRaces(6, 63, 255);
       mcCareer_StartNewScript("Game/CruisingHookmen/hw_time_trial_hk1", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/hw_tournament_hk1", 1500);
       mcCareer_StartNewScript("Game/Garages/hw_garage_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hw_delivery_setup", 1500);
       mcCareer_StartNewScript("Game/Garages/be_garage_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/be_payback_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hw_wager_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hw_local_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hw_local_hangout2_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hw_local_hangout3_setup", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/be_time_trial_hk1", 1500);
       mcCareer_StartNewScript("Game/Hangouts/be_wager_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/be_local_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/dt_time_trial_hk1", 1500);
       mcCareer_StartNewScript("Game/Hangouts/dt_wager_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/dt_local_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/hl_time_trial_hk1", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hl_wager_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/Hangouts/hl_local_hangout1_setup", 1500);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/sc_time_trial_hk1", 1500);
       mcCareer_StartNewScript_SC("sc/Hangouts/sc_wager_hangout1_setup", 1500);
       mcCareer_StartNewScript_SC("sc/Hangouts/sc_local_hangout1_setup", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/hw_redlight_hk1", 3800);
       mcCareer_StartNewScript("Game/CruisingHookmen/be_redlight_hk1", 3800);
       mcCareer_StartNewScript("Game/CruisingHookmen/hl_redlight_hk1", 3800);
       mcCareer_StartNewScript("Game/CruisingHookmen/dt_redlight_hk1", 3800);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/sc_redlight_hk1", 3800);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman1", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman2", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman3", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman4", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman5", 1500);
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman6", 1500);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman7", 1500);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman8", 1500);
       mcCareer_StartNewScript("Game/Race/TelephoneChallenge", 1500);
       StatsManager_UpdateStatInt("tNOR", 0, 3, 1);
   }
   mcCareer_StartNewScript("game/Garages/ratemyride_setup", 1500);
   mcCareer_StartNewScript("game/MiscTasks/GasStations", 1500);
   mcCareer_StartNewScript("Game/MiscTasks/Collectables", 1500);
   mcCareer_StartNewScript("Game/MiscTasks/SoundTriggers", 1500);
   mcCareer_StartNewScript("Game/Flow/BootDebug", 1500);
   mcCareer_UnlockRace("game/Race/Hollywood/Ordered/hw_ordered_jp_11");
   mcCareer_UnlockRace("game/Race/Hollywood/Ordered/hw_ordered_mg_01");
   mcCareer_UnlockRace("game/Race/Hollywood/Ordered/hw_ordered_ds_02");
   mcCareer_UnlockRace("game/Race/Downtown/Circuit/dt_circuit_as_01");
   mcCareer_UnlockRace("game/Race/Hollywood/Circuit/hw_circuit_jp_03");
   mcCareer_UnlockRace("game/Race/Beaches/Circuit/be_circuit_jj_02");
   mcCareer_UnlockRace("game/Race/Hollywood/Circuit/hw_circuit_mb_04a");
   mcCareer_UnlockRace("game/Race/Hills/Ordered/hl_ordered_ts_05");
   mcCareer_UnlockRace("game/Race/Beaches/Ordered/be_ordered_mg_02");
   mcCareer_UnlockRace("game/Race/Hills/Circuit/hl_circuit_ds_01");
   mcCareer_UnlockRace("game/Race/Hollywood/Circuit/hw_circuit_jj_01c");
   mcCareer_UnlockRace("game/Race/Downtown/Circuit/dt_circuit_mb_01");
   mcCareer_UnlockDistrictRaces(6, 8, -1);
   WAIT(10);
   var4 = null;
   var4 = mcMissionManager_GetMission("RACE_GH_06");
   if (mcMission_GetState(var4) == 0)
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
   while (!IsExitFlagSet())
   {
       WAIT(0);
   }
   PRINTSTRING("Passing exit into child scripts\n");
   var5 = GetChildThread();
   while (var5 != null)
   {
       SetExitFlag(var5);
       var5 = GetNextChildThread(var5);
   }
   PRINTSTRING("Exit Career setup script\n");
}

