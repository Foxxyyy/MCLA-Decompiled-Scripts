void main()
{
   auto var2;

   mcCareer_LoadPinkSlipProfile(521, "pinkslip_vp_mit_evo_06", 0);
   mcCareer_TogglePinkslipHangoutDirty(521, 1);
   var2 = 0;
   Registry_GetValueInt("hl_wager_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hl_wager_hangout1_setup", 1500);
   }
   mcCareer_UnlockRace("game/Race/Hills/Ordered/hl_ordered_ts_01");
}

