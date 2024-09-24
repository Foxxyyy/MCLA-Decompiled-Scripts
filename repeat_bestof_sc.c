void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9;

   var2 = mcMissionManager_GetMission("REPEAT_BESTOF_SC");
   var3 = mcMission_GetHookmanNameId(var2);
   var4 = mcSlotSystem_IsCharacterUsed(4, var3);
   mcSlotSystem_ToggleCharacterUsed(4, var3, 1);
   var5 = mcSlotSystem_FindRandomAvailableCharacter(4);
   var6 = mcCharacterConfigData_GetCarConfigData(var5, Racer_GetCarConfig(sub_54(0)), 1, 247, 1);
   var7 = mcCarConfigData_GetRandomConfigData(var6);
   mcSlotSystem_ToggleCharacterUsed(1, var3, var4);
   var8 = mcSlotSystem_RequestSlot(4, mcCharacterConfigData_GetName(var5), 0, 1, mcConfigData_GetName(var7), 1, 0, "sc/Career/Story/REPEAT_BESTOF_SC_CORE");
   while (var8 == null)
   {
       WAITUNWARPED(1000);
       var8 = mcSlotSystem_RequestSlot(4, mcCharacterConfigData_GetName(var5), 0, 1, mcConfigData_GetName(var7), 1, 0, "sc/Career/Story/REPEAT_BESTOF_SC_CORE");
   }
   mcHookman_SetMission(var8, "REPEAT_BESTOF_SC");
   var9 = mcMission_GetObjective(var2, 0);
   mcRequirement_SetTarget(var9, mcHookman_GetId(var8));
   mcSlotSystem_UnlockDistrict(4, 1);
}

function sub_54(var0)
{
   auto var3, var4;

   var3 = Player_FindRacerObject(var0);
   while (var3 == null)
   {
       var3 = Player_FindRacerObject(var0);
       WAITUNWARPED(10);
   }
   return var3;
}

