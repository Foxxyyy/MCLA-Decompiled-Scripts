void main()
{
   auto var2, var3, var4, var5;

   var2 = mcSlotSystem_RequestSlot(4, "GH_31", 0, 1, "SC_GH_31_2_vpd_lr_hse_08", 2, 0, "sc/Career/Story/BESTOF_GH_31_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "GH_31", 0, 1, "SC_GH_31_2_vpd_lr_hse_08", 2, 0, "sc/Career/Story/BESTOF_GH_31_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_GH_31");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
   if (mcSlotSystem_IsDistrictLocked(4))
   {
       mcSlotSystem_HideDistrict(4, 0);
       mcSlotSystem_UnlockDistrict(4, 1);
       mcCareer_SetAltHookmanVisibility(354, 1);
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/sc_redlight_hk1", 3800);
   }
   var5 = mcCareer_GetHookman(306);
   mcCareer_SetAltHookmanVisibility(306, 1);
   if (var5 != null)
   {
       mcHookman_Hide(var5, 0);
   }
   else
   {
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman7", 1500);
   }
   var5 = mcCareer_GetHookman(307);
   mcCareer_SetAltHookmanVisibility(307, 1);
   if (var5 != null)
   {
       mcHookman_Hide(var5, 0);
   }
   else
   {
       mcCareer_StartNewScript_SC("sc/CruisingHookmen/freeway_hookman8", 1500);
   }
}

