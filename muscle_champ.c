void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(1, "GH_05", 0, 1, "GH_05_2_vp_chv_camaro_06", 2, 0, "Game/Career/Story/MUSCLE_CHAMP_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "GH_05", 0, 1, "GH_05_2_vp_chv_camaro_06", 2, 0, "Game/Career/Story/MUSCLE_CHAMP_CORE");
   }
   var3 = mcHookman_SetMission(var2, "MUSCLE_CHAMP");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

