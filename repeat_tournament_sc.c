void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(204);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(204);
   }
   START_NEW_SCRIPT("sc/CruisingHookmen/sc_tournament_hk1", 1500);
}

