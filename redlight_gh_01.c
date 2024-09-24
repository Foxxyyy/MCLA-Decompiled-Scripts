void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(350);
   mcCareer_SetAltHookmanVisibility(350, 1);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/hw_redlight_hk1", 3800);
   }
   var2 = mcCareer_GetHookman(351);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/be_redlight_hk1", 3800);
   }
   var2 = mcCareer_GetHookman(352);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/hl_redlight_hk1", 3800);
   }
   var2 = mcCareer_GetHookman(353);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/dt_redlight_hk1", 3800);
   }
   var2 = mcCareer_GetHookman(303);
   mcCareer_SetAltHookmanVisibility(303, 1);
   mcHookman_Hide(var2, 0);
   if (var2 == null)
   {
       mcCareer_StartNewScript("Game/CruisingHookmen/freeway_hookman4", 1500);
   }
}

