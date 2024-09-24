void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("sc_wager_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript_SC("sc/Hangouts/sc_wager_hangout1_setup", 1500);
   }
}

