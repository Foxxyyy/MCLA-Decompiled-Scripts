void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(300);
   if (var2 != null)
   {
       mcHookman_Hide(var2, 0);
       mcCareer_SetAltHookmanVisibility(300, 1);
   }
   else
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman1", 1500);
   }
   var2 = mcCareer_GetHookman(301);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman2", 1500);
   }
   var2 = mcCareer_GetHookman(302);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman3", 1500);
   }
   var2 = mcCareer_GetHookman(303);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman4", 1500);
   }
   var2 = mcCareer_GetHookman(304);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman5", 1500);
   }
   var2 = mcCareer_GetHookman(305);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman6", 1500);
   }
}

