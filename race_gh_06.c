void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "GH_06", 1, 1, "GH_06_0_vp_dsn_280z_75", 0, 0, "Game/Career/Story/RACE_GH_06_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "GH_06", 1, 1, "GH_06_0_vp_dsn_280z_75", 0, 0, "Game/Career/Story/RACE_GH_06_CORE");
   }
   var3 = mcHookman_SetMission(var2, "RACE_GH_06");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

