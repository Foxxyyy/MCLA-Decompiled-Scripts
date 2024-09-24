void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("hw_local_hangout2_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hw_local_hangout2_setup", 1500);
   }
   StatsManager_UpdateStatInt("tNOR", 0, 3, 1);
   mcCareer_UnlockDistrictRaces(0, 2, 6);
}

