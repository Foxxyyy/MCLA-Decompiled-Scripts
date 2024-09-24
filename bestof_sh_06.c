void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(4, "GH_08", 0, 1, "GH_08_1_vp_mit_eclipse_99", 2, 0, "sc/Career/Story/BESTOF_SH_06_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "GH_08", 0, 1, "GH_08_1_vp_mit_eclipse_99", 2, 0, "sc/Career/Story/BESTOF_SH_06_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_SH_06");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

