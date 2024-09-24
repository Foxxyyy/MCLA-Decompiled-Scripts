void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(1, "GH_10", 0, 1, "GH_10_3_vp_lam_gallardo_06", 2, 0, "Game/Career/Story/DISTRICT_CHAMPS_BEACHES_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "GH_10", 0, 1, "GH_10_3_vp_lam_gallardo_06", 2, 0, "Game/Career/Story/DISTRICT_CHAMPS_BEACHES_CORE");
   }
   var3 = mcHookman_SetMission(var2, "DISTRICT_CHAMPS_BEACHES");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

