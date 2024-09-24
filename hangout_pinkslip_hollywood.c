void main()
{
   auto var2;

   mcCareer_LoadPinkSlipProfile(503, "pinkslip_vp_pon_transam_79", 0);
   mcCareer_TogglePinkslipHangoutDirty(503, 1);
   var2 = 0;
   Registry_GetValueInt("hw_wager_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hw_wager_hangout1_setup", 1500);
   }
   mcCareer_UnlockRace("game/Race/Hollywood/Ordered/hw_ordered_jp_04");
}

