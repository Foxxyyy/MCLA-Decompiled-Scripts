void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(1, "SH_02", 0, 1, "SH_02_2_vp_dge_challenger_06", 2, 0, "Game/Career/Story/BEAT_SH_02_BCLASS_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "SH_02", 0, 1, "SH_02_2_vp_dge_challenger_06", 2, 0, "Game/Career/Story/BEAT_SH_02_BCLASS_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_02_BCLASS");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

