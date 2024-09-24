void main()
{
   auto var2, var3, var4;

   var2 = mcMissionManager_GetMission("PAYBACK_INTRO");
   if (mcMission_GetState(var2) != 5)
   {
       mcMission_ChangeState(var2, 5, 1);
   }
   var2 = mcMissionManager_GetMission("PAYBACK");
   if (mcMission_GetState(var2) != 5)
   {
       mcMission_ChangeState(var2, 5, 1);
   }
   mcTargetManager_ToggleMapVisibiliy(513, 0);
   var3 = 0;
   Registry_GetValueInt("be_garage_state", &var3);
   if (var3 == 0)
   {
       mcCareer_StartNewScript("Game/Garages/be_garage_setup", 1500);
   }
   var4 = 0;
   Registry_GetValueInt("be_payback_state", &var4);
   if (var4 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/be_payback_setup", 1500);
   }
   if (!mcCareer_IsPoliceUnlocked())
   {
       mcCareer_UnlockPolice();
   }
   StatsManager_UpdateStatInt("tTPA", 0, 3, 1);
}

