void main()
{
   auto var2, var3, var4, var5;

   var2 = sub_a(0);
   while (!Racer_IsVinylStreamed(var2))
   {
       WAITUNWARPED(30);
   }
   mcCareer_UnlockDistrictRaces(4, -1, -1);
   WAITUNWARPED(6000);
   PRINTSTRING("RYAN: CHECKING MISSION GARAGE_SC \n");
   var3 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   var4 = mcMissionManager_GetMission("GARAGE_SC");
   if ((mcMission_GetState(var3) == 5) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   var3 = mcMissionManager_GetMission("DELIVERY");
   var4 = mcMissionManager_GetMission("BESTOF_GH_31");
   if ((mcMission_GetState(var3) == 5) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   var3 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   var4 = mcMissionManager_GetMission("LOWRIDER_REP");
   if ((mcMission_GetState(var3) == 5) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   var3 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   var5 = mcMissionManager_GetMission("DELIVERY");
   var4 = mcMissionManager_GetMission("DELIVERY_SC");
   if (((mcMission_GetState(var3) == 5) && (mcMission_GetState(var5) == 5)) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   var3 = mcMissionManager_GetMission("HANGOUT_SERIES_SC");
   var4 = mcMissionManager_GetMission("TOURNAMENT_SC");
   if ((mcMission_GetState(var3) == 5) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   var3 = mcMissionManager_GetMission("HANGOUT_SERIES_SC");
   var5 = mcMissionManager_GetMission("HANGOUT_SERIES_DOWNTOWN");
   var4 = mcMissionManager_GetMission("RACES_IN_SC");
   if (((mcMission_GetState(var3) == 5) && (mcMission_GetState(var5) == 5)) && (mcMission_GetState(var4) == 1))
   {
       mcMission_ChangeState(var4, 2, 0);
   }
   while (1)
   {
       WAITUNWARPED(1000);
   }
}

function sub_a(var0)
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

