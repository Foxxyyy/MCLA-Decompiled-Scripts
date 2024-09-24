void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("be_payback_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/be_payback_setup", 1500);
   }
   if (!mcCareer_IsPoliceUnlocked())
   {
       mcCareer_UnlockPolice();
   }
   mcSlotSystem_HideDistrict(1, 0);
   mcSlotSystem_UnlockDistrict(1, 1);
}

