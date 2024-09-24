void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(4, "GH_26", 0, 1, "SC_GH_26_1_vpd_chv_malibu_65", 2, 0, "sc/Career/Story/BESTOF_GH_26_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "GH_26", 0, 1, "SC_GH_26_1_vpd_chv_malibu_65", 2, 0, "sc/Career/Story/BESTOF_GH_26_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_GH_26");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

