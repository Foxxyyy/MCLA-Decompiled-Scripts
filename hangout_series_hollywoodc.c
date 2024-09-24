void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("hw_local_hangout3_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hw_local_hangout3_setup", 1500);
   }
}

