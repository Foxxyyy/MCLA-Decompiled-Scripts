void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(4, "GH_26", 0, 1, "SC_GH_26_3_vpd_lr_hse_08", 2, 0, "sc/Career/Story/BEAT_GH_26_SUV_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "GH_26", 0, 1, "SC_GH_26_3_vpd_lr_hse_08", 2, 0, "sc/Career/Story/BEAT_GH_26_SUV_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_GH_26_SUV");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

