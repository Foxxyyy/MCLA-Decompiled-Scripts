void main()
{
   auto var2, var3, var4, var5, var6, var7;

   var2 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   while (mcMission_GetState(var2) != 5)
   {
       WAITUNWARPED(100);
   }
   var3 = UIManager_GetState("Cruising_Offline");
   var4 = UIManager_GetState("GameState_Garage");
   var5 = sub_7d(0);
   var6 = null;
   var7 = 0;
   if (vhsmState_IsListener(var4))
   {
       PRINTSTRING("PLAYER HAS ENTERED THE GARAGE IGNORING TIP CarsUnlockTip_02\n");
   }
   else if (!vhsmState_IsListener(var3))
   {
       WAITUNWARPED(100);
   }
   else if (FlashNavigator_IsTransitioning() || (PoliceManager_CheckPoliceActivity(1) > 1))
   {
       WAITUNWARPED(100);
   }
   else if (!sub_163())
   {
       WAITUNWARPED(100);
   }
   else
   {
       var6 = Sidekick_AppendData(5, "SIDEKICK_TITLE_TIP", 1, 6, 10.0f, "mec_mc_01_set", "Incoming Call!", "SIDEKICK_CARS_UNLOCK_TIP_02", "Prompt_NavigateToTutorialLog", 3, 0, "SIDEKICK_CARS_UNLOCK_TIP_02", "mec_mc_01_set", "PLAYER");
       var7 = 0;
       while ((!Sidekick_HasDataBeenAnnounced(var6)) && (!var7))
       {
           if (vhsmState_IsListener(var4))
           {
               PRINTSTRING("PLAYER HAS ENTERED THE GARAGE REMOVING TIP CarsUnlockTip_02\n");
               var7 = 1;
           }
           WAITUNWARPED(200);
       }
   }
   if (var7)
   {
       Sidekick_RemoveData(var6);
   }
}

function sub_7d(var0)
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

function sub_163()
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

