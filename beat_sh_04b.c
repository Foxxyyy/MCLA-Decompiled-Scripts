void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/BEAT_SH_04B_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/BEAT_SH_04B_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_04B");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

