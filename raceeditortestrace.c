void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   OpponentManager_CleanupOpponentArray();
   sub_1b(0, 0.0f, 0, 0, 1, 1, 1);
   var2 = 0;
   strcpy(&var3, 64, "");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   sub_675(&L[0]);
   var19 = START_NEW_SCRIPT_WITH_ARGS("game/racetypes/OrderedCheckpointCore", &L[0], 802, 0);
   while (!IsChildFinished(var19))
   {
       WAIT(100);
   }
   Registry_GetValueInt("raceOverTrigger", &var2);
   if (var2 == 0)
   {
       sub_797(0, 0x3f000000, 108);
       UIManager_SendEvent("raceEnd");
       while (var2 == 0)
       {
           Registry_GetValueInt("raceOverTrigger", &var2);
           WAITUNWARPED(20);
       }
       sub_83d(108, 0x3f000000);
   }
   strcpy(&var3, 64, "");
   Registry_GetValueString("raceOverCommand", &var3);
   PRINTSTRING("Test race command: ");
   PRINTSTRING(&var3);
   PRINTSTRING("\n");
   if (StringCaseCompare(&var3, "restart"))
   {
       PRINTSTRING("Test race restart\n");
       UILogic_RestartRace();
   }
   if (StringCaseCompare(&var3, "returnToCruise"))
   {
       PRINTSTRING("Test race exit\n");
   }
   sub_3b6();
}

void sub_1b(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   PRINTSTRING("EvaluatePolice() - police probability: ");
   PRINTFLOAT(var1);
   PRINTSTRING("\n");
   var9 = 0;
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var1 > 0.0f) && (var9 >= 4))
   {
       PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races >= 4, setting police probability to 1.0\n");
       var1 = 1.0f;
   }
   var10 = 0;
   if (GetRaceCopChaseCommandLine(&var10))
   {
       if (var10 == 1)
       {
           if (var1 > 0.0f)
           {
               PRINTSTRING("EvaluatePolice() - racecopchase=1, setting police probability to 1.0\n");
               var1 = 1.0f;
           }
       }
       else
       {
           PRINTSTRING("EvaluatePolice() - racecopchase=0, setting police probability to 0.0\n");
           var1 = 0.0f;
       }
   }
   if (GetDemoCommandLine())
   {
       PRINTSTRING("EvaluatePolice() - demo, setting police probability to 0.0\n");
       var1 = 0.0f;
   }
   var11 = RAND_FLOAT_RANGE(0.0f, 1.0f);
   PRINTSTRING("EvaluatePolice() - random probability: ");
   PRINTFLOAT(var11);
   PRINTSTRING("\n");
   var12 = RaceDescription_GetNumCopZones(var0);
   PRINTSTRING("EvaluatePolice() - number of cop zones: ");
   PRINTINT(var12);
   PRINTSTRING("\n");
   if ((var12 == 0) || (var11 > var1))
   {
       PoliceManager_DestroyAllPolice();
       PRINTSTRING("EvaluatePolice() - police destroyed, not available in race\n");
       if (var1 > 0.0f)
       {
           var9 = var9 + 1;
       }
   }
   else
   {
       sub_3b6();
       var9 = 0;
   }
   PoliceManager_SetChaseProperties(var4, var5, var6);
   PoliceManager_SetRaceChaseTarget(var2, var3);
   Registry_SetValueInt("nNumNoCopRaces", var9);
   PRINTSTRING("EvaluatePolice() - new number of consecutive no-cop races: ");
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTINT(var9);
   PRINTSTRING("\n");
}

void sub_3b6()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34;

   var2 = 3;
   var6 = 3;
   var16 = 3;
   var20 = 3;
   var2[0] = "vp_chv_police_96";
   var6[0 * 3].v0 = 2030.1f;
   var6[0 * 3].v1 = 6.8f;
   var6[0 * 3].v2 = -813.7f;
   var16[0] = (float)90;
   var20[0 * 3].v0 = -510.0f;
   var20[0 * 3].v1 = 9.5f;
   var20[0 * 3].v2 = -400.0f;
   var2[1] = "vp_chv_police_96";
   var6[1 * 3].v0 = -646.8f;
   var6[1 * 3].v1 = 18.5f;
   var6[1 * 3].v2 = -643.8f;
   var16[1] = (float)90;
   var20[1 * 3].v0 = -500.0f;
   var20[1 * 3].v1 = 9.5f;
   var20[1 * 3].v2 = -400.0f;
   var2[2] = "vp_chv_police_96";
   var6[2 * 3].v0 = -2434.4f;
   var6[2 * 3].v1 = 1.9f;
   var6[2 * 3].v2 = -577.9f;
   var16[2] = 84.9f;
   var20[2 * 3].v0 = -490.0f;
   var20[2 * 3].v1 = 9.5f;
   var20[2 * 3].v2 = -400.0f;
   var30 = 3;
   var34 = 0;
   while (var34 < 3)
   {
       var30[var34] = PoliceManager_CreatePolice(var2[var34], 1, &(var6[var34 * 3]), var16[var34], &(var20[var34 * 3]), 400 + var34);
       var34 = var34 + 1;
   }
}

void sub_675(var0)
{
   auto var3, var4, var5;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var4 = Racer_GetUID((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var4 == 0)
       {
           var4 = 5000 + var3;
           while (Racer_FindFromUID(var4) != null)
           {
               var4 = var4 + 1;
               WAITUNWARPED(10);
           }
           Racer_SetUID((*((var0 + 16) + 4))[var3 * 48].v0, var4);
       }
       CineScript_Cars_AssignIdToSlot(var4, var3);
       var3 = var3 + 1;
   }
}

void sub_797(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

void sub_83d(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

