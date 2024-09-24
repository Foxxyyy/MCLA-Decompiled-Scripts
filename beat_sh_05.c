void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(3, "SH_05", 0, 1, "SH_05_3_vp_frd_gt_06", 2, 0, "Game/Career/Story/BEAT_SH_05_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_05", 0, 1, "SH_05_3_vp_frd_gt_06", 2, 0, "Game/Career/Story/BEAT_SH_05_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_05");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

