void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(203);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(203);
   }
   START_NEW_SCRIPT("Game/CruisingHookmen/dt_tournament_hk1", 1500);
}

