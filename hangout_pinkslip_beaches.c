void main()
{
   auto var2;

   mcCareer_LoadPinkSlipProfile(511, "pinkslip_vp_mzd_rx8_06", 0);
   mcCareer_TogglePinkslipHangoutDirty(511, 1);
   var2 = 0;
   Registry_GetValueInt("be_wager_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/be_wager_hangout1_setup", 1500);
   }
}

