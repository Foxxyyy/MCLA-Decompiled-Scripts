void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "SH_03", 0, 1, "SH_03_2_vp_cry_300c_06", 2, 0, "Game/Career/Story/BESTOF_SH_03_LUXURY_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "SH_03", 0, 1, "SH_03_2_vp_cry_300c_06", 2, 0, "Game/Career/Story/BESTOF_SH_03_LUXURY_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_SH_03_LUXURY");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

