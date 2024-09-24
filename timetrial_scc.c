void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(254);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(254);
   }
   START_NEW_SCRIPT("sc/CruisingHookmen/sc_time_trial_hk1", 1500);
}

