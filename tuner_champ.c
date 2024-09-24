void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "GH_16", 0, 1, "GH_16_2_vp_mit_evo_06", 2, 0, "Game/Career/Story/TUNER_CHAMP_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "GH_16", 0, 1, "GH_16_2_vp_mit_evo_06", 2, 0, "Game/Career/Story/TUNER_CHAMP_CORE");
   }
   var3 = mcHookman_SetMission(var2, "TUNER_CHAMP");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

