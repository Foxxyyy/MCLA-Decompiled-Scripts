void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(2, "SH_04", 0, 1, "SH_04_3_vp_duc_999r_06", 2, 0, "Game/Career/Story/RACE_SH_04_MOTORCYCLE_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(2, "SH_04", 0, 1, "SH_04_3_vp_duc_999r_06", 2, 0, "Game/Career/Story/RACE_SH_04_MOTORCYCLE_CORE");
   }
   var3 = mcHookman_SetMission(var2, "RACE_SH_04_MOTORCYCLE");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
   mcSlotSystem_HideDistrict(2, 0);
   mcSlotSystem_UnlockDistrict(2, 1);
}

