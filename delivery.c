void main()
{
   auto var2, var3;

   var2 = 0;
   Registry_GetValueInt("hw_garage_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Garages/hw_garage_setup", 1500);
   }
   var3 = 0;
   Registry_GetValueInt("hw_delivery_state", &var3);
   if (var3 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hw_delivery_setup", 1500);
   }
}

