void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "SH_01", 0, 1, "SH_01_2_vp_dge_charger_06", 2, 0, "Game/CruisingHookmen/generic_local_hookman");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "SH_01", 0, 1, "SH_01_2_vp_dge_charger_06", 2, 0, "Game/CruisingHookmen/generic_local_hookman");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_SH_01_MUSCLE");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

