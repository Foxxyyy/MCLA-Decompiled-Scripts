void main()
{
   auto var2, var3, var4, var5, var6, var7;

   var2 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   while (mcMission_GetState(var2) != 5)
   {
       WAITUNWARPED(100);
   }
   var3 = sub_45(0);
   var4 = LocalOptions_GetCurrentVehicleProfileIndex();
   var5 = Racer_GetModValue(var3);
   var6 = null;
   var7 = 0;
   while (!sub_129())
   {
       WAITUNWARPED(100);
   }
   var6 = Sidekick_AppendData(5, "SIDEKICK_TITLE_TIP", 1, 28, 10.0f, "mec_mc_01_set", "Incoming Call!", "SIDEKICK_PERFORMANCE_UPGRADE_TIP_03", "Prompt_NavigateToTutorialLog", 3, 0, "SIDEKICK_PERFORMANCE_UPGRADE_TIP_03", "mec_mc_01_set", "PLAYER");
   var7 = 0;
   while ((!Sidekick_HasDataBeenAnnounced(var6)) && (!var7))
   {
       if (var4 != LocalOptions_GetCurrentVehicleProfileIndex())
       {
           var5 = Racer_GetModValue(var3);
       }
       if (var5 != Racer_GetModValue(var3))
       {
           var7 = 1;
       }
       WAITUNWARPED(200);
   }
   if (var7)
   {
       Sidekick_RemoveData(var6);
   }
}

function sub_45(var0)
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

void sub_b5(var0)
{
   auto var3, var4;

   var3 = UIManager_GetState(var0);
   while (!vhsmState_IsListener(var3))
   {
       WAITUNWARPED(100);
   }
   while (FlashNavigator_IsTransitioning() && (PoliceManager_CheckPoliceActivity(1) > 1))
   {
       WAITUNWARPED(100);
   }
   if (!vhsmState_IsListener(var3))
   {
   }
}

function sub_129()
{
   if (Sidekick_GetTypeCount(3) > 4)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}

