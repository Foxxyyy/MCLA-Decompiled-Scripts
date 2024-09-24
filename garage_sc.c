void main()
{
   auto var2, var3;

   var2 = 0;
   Registry_GetValueInt("sc_garage_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript_SC("sc/Garages/sc_garage_setup", 1500);
   }
   if (mcSlotSystem_IsDistrictLocked(4))
   {
       mcSlotSystem_HideDistrict(4, 0);
       mcSlotSystem_UnlockDistrict(4, 1);
       mcCareer_SetAltHookmanVisibility(354, 1);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/sc_redlight_hk1", 3800);
   }
   var3 = mcCareer_GetHookman(306);
   mcCareer_SetAltHookmanVisibility(306, 1);
   if (var3 != null)
   {
       mcHookman_Hide(var3, 0);
   }
   else
   {
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman7", 1500);
   }
   var3 = mcCareer_GetHookman(307);
   mcCareer_SetAltHookmanVisibility(307, 1);
   if (var3 != null)
   {
       mcHookman_Hide(var3, 0);
   }
   else
   {
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman8", 1500);
   }
}
