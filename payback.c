void main()
{
   auto var2, var3;

   var2 = 0;
   Registry_GetValueInt("be_garage_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Garages/be_garage_setup", 1500);
   }
   mcTargetManager_ToggleMapVisibiliy(513, 0);
   var3 = 0;
   Registry_GetValueInt("be_payback_state", &var3);
   if (var3 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/be_payback_setup", 1500);
   }
   if (!mcCareer_IsPoliceUnlocked())
   {
       mcCareer_UnlockPolice();
   }
}

