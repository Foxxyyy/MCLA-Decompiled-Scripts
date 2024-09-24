void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(4, "GH_27", 0, 1, "SC_GH_27_3_vpd_mbz_clk63amg_08", 2, 0, "sc/Career/Story/BESTOF_GH_27_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "GH_27", 0, 1, "SC_GH_27_3_vpd_mbz_clk63amg_08", 2, 0, "sc/Career/Story/BESTOF_GH_27_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_GH_27");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

