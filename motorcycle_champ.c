void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(2, "GH_23", 0, 1, "GH_23_4_vp_kaw_ninja_zx14_06", 2, 0, "Game/Career/Story/MOTORCYCLE_CHAMP_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(2, "GH_23", 0, 1, "GH_23_4_vp_kaw_ninja_zx14_06", 2, 0, "Game/Career/Story/MOTORCYCLE_CHAMP_CORE");
   }
   var3 = mcHookman_SetMission(var2, "MOTORCYCLE_CHAMP");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

