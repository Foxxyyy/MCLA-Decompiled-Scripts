void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(3, "GH_07", 0, 1, "GH_07_3_vp_mbz_sl65_07", 2, 0, "Game/Career/Story/LUXURY_CHAMP_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "GH_07", 0, 1, "GH_07_3_vp_mbz_sl65_07", 2, 0, "Game/Career/Story/LUXURY_CHAMP_CORE");
   }
   var3 = mcHookman_SetMission(var2, "LUXURY_CHAMP");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

