void main()
{
   auto var2, var3, var4;

   if (!GetNoTutorialCommandLine())
   {
       var2 = sub_17(0);
       var3 = UIManager_GetState("Racing");
       var4 = 0;
       while (!var4)
       {
           WAITUNPAUSED(100);
           if (((((vhsmState_IsListener(var3) && (!FlashNavigator_IsTransitioning())) && (!Net_IsNetworked())) && (!Game_IsPaused())) && (!Warper_IsWarping())) && (!UIManager_IsDisplayingMenu()))
           {
               if (Racer_GetTurboLevel(var2) > 0.3f)
               {
                   var4 = 1;
                   Registry_SetValueInt("nInTutorial", 1);
               }
           }
       }
       AudioManager_SetActiveTimeSlow(1);
       sub_fe(0, 0x3f000000, 108);
       sub_18e(-1, 78, "TUTORIAL_SST_INGAME", "drv_mb_04_set", "PLAYER");
       AudioManager_SetActiveTimeSlow(0);
       sub_243(108, 0x3f000000);
       Registry_SetValueInt("nInTutorial", 0);
       var4 = 0;
       while (!var4)
       {
           WAITUNPAUSED(100);
           if (((((vhsmState_IsListener(var3) && (!FlashNavigator_IsTransitioning())) && (!Net_IsNetworked())) && (!Game_IsPaused())) && (!Warper_IsWarping())) && (!UIManager_IsDisplayingMenu()))
           {
               if (Racer_GetTurboLevel(var2) > 0.99f)
               {
                   var4 = 1;
                   Registry_SetValueInt("nInTutorial", 1);
               }
           }
       }
       sub_18e(-1, 79, 0, 0, 0);
       Registry_SetValueInt("nInTutorial", 0);
   }
}

function sub_17(var0)
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

void sub_fe(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_18e(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15;

   var7 = 1;
   var8 = Form_GetForm(var0);
   var9 = Form_GetForm(var1);
   Form_ShowForm(var8, var9);
   if (!StringCompare(var2, ""))
   {
       var10 = mcCareerSpeech_FindScenario(var2);
       if (var10 != null)
       {
           mcCareerSpeech_Stop();
           mcCareerSpeech_PlayScenario(var10, var3, var4);
       }
   }
   while (var7)
   {
       var7 = Form_GetFormVisible(var9);
       WAITUNWARPED(100);
   }
   return Form_GetFormResult(var9);
}

void sub_243(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

