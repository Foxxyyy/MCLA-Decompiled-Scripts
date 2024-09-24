void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(3, "SH_05", 0, 1, "SH_05_2_vp_vw_golf_07", 2, 0, "Game/Career/Story/BESTOF_SH_05_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_05", 0, 1, "SH_05_2_vp_vw_golf_07", 2, 0, "Game/Career/Story/BESTOF_SH_05_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_SH_05");
   var4 = mcMission_GetObjective(var3, 1);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

