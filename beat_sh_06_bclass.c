void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(4, "SH_06", 0, 1, "SH_06_1_vp_frd_boss302_69", 2, 0, "sc/Career/Story/BEAT_SH_06_BCLASS_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(4, "SH_06", 0, 1, "SH_06_1_vp_frd_boss302_69", 2, 0, "sc/Career/Story/BEAT_SH_06_BCLASS_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_06_BCLASS");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

