void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "SH_02", 0, 1, "SH_02_0_vp_dsn_280z_75", 2, 0, "Game/Career/Story/BEAT_SH_02_DCLASS_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "SH_02", 0, 1, "SH_02_0_vp_dsn_280z_75", 2, 0, "Game/Career/Story/BEAT_SH_02_DCLASS_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_02_DCLASS");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

