void main()
{
   auto var2, var3, var4, var5, var6;

   var2 = Form_GetForm(-1);
   var3 = Form_GetForm(70);
   var4 = UIManager_FindMovie("HUDMOVIE");
   UIManager_SendEvent("OnRaceStart");
   sub_50(1, 1, 0x3f800000, 0);
   var5 = Race_GetCurrentRace();
   UIManager_SendEventTo("countDown", "startCountdown");
   SetExceptionMask(3);
   var6 = ;
   switch (var6)
   {
       case 0:
       {
           break;
       }
       case 1:
       {
           PRINTSTRING("Shutdown exception\n");
           break;
       }
       case 2:
       {
           PRINTSTRING("restart race exception\n");
           break;
       }
       case 3:
       {
           break;
       }
       default:
       {
           PRINTSTRING("Unhandled exception\n");
           Form_ShowForm(var2, var3);
           Racer_SetScrambleInputFlags(Player_FindRacerObject(0), 2);
           Race_EnableRaceTimer(var5, 1);
           Race_SetTimer(var5, -1000);
           WAITUNWARPED(1000);
           sub_49c(var4);
           AudioManager_PlayFrontendSound("HUD_CNTDWN_GO_MASTER");
           Racer_SetScrambleInputFlags(Player_FindRacerObject(0), 0);
           Form_CloseForm(var3);
           break;
       }
   }
   UIManager_SendEventTo("countDown", "stopCountdown");
   PRINTSTRING("Countdown script finished\n");
}

void sub_50(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE UP REPORT\n");
   PRINTSTRING("==============\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var7 == 0) && ((var8 != 0) || (var9 != 0)))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", 0.01f);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", var2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 1);
       if (var0)
       {
           var7 = 1;
           while (var7 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
               if (var7 == 1)
               {
                   PRINTSTRING("SCRIPT: waiting for transition movie transition up...\n");
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

void sub_49c(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 2);
}

