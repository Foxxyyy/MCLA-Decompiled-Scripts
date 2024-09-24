void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(202);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(202);
   }
   START_NEW_SCRIPT("Game/CruisingHookmen/hl_tournament_hk1", 1500);
}

