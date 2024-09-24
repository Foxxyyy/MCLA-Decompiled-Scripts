void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(253);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(253);
   }
   START_NEW_SCRIPT("Game/CruisingHookmen/dt_time_trial_hk1", 1500);
}

