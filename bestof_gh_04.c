void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(0, "GH_04", 0, 1, "GH_04_1_vp_chv_camaross_69", 2, 0, "Game/Career/Story/BESTOF_GH_04_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "GH_04", 0, 1, "GH_04_1_vp_chv_camaross_69", 2, 0, "Game/Career/Story/BESTOF_GH_04_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BESTOF_GH_04");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}

