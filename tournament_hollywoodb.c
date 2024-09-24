void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(200);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(200);
   }
   START_NEW_SCRIPT("Game/CruisingHookmen/hw_tournament_hk1", 1500);
}

