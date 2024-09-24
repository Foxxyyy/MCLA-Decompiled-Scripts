void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/FIND_SH_01_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/FIND_SH_01_CORE");
   }
   var3 = mcHookman_SetMission(var2, "FIND_SH_01");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
   mcSlotSystem_HideDistrict(3, 0);
   mcSlotSystem_UnlockDistrict(3, 1);
}

