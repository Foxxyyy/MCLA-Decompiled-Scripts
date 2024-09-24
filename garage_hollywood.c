void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("hw_garage_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Garages/hw_garage_setup", 1500);
   }
}

