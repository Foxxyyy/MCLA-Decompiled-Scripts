void main()
{
   auto var2;

   mcCareer_LoadPinkSlipProfile(541, "SC_pinkslip_vpd_pon_gto_66", 0);
   mcCareer_TogglePinkslipHangoutDirty(541, 1);
   var2 = 0;
   Registry_GetValueInt("sc_wager_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript_SC("sc/Hangouts/sc_wager_hangout1_setup", 1500);
   }
}

