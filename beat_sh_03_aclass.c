void main()
{
   auto var2, var3, var4;

   var2 = mcSlotSystem_RequestSlot(1, "SH_03", 0, 1, "SH_03_3_vp_frd_cobra_04", 2, 0, "Game/Career/Story/BEAT_SH_03_ACLASS_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "SH_03", 0, 1, "SH_03_3_vp_frd_cobra_04", 2, 0, "Game/Career/Story/BEAT_SH_03_ACLASS_CORE");
   }
   var3 = mcHookman_SetMission(var2, "BEAT_SH_03_ACLASS");
   var4 = mcMission_GetObjective(var3, 0);
   mcRequirement_SetTarget(var4, mcHookman_GetId(var2));
}
