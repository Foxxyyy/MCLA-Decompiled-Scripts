void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23;

   var2 = 1;
   var3 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, var2);
   var4.v0 = 1351.74f;
   var4.v1 = -9.99f;
   var4.v2 = 268.81f;
   var7 = 269.74f;
   var8.v2.v0.v0 = 0.0f;
   var8.v2.v0.v1 = 0.0f;
   var8.v2.v0.v2 = 0.0f;
   var8.v2.v3 = 0.0f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var4, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var14 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var14, var3, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var14, mcHookman_GetModValue(L[0].v0.v97.v0));
   mcTargetManager_RegisterRacer(var3, var14);
   mcTargetManager_HideTarget(var3, 0);
   Racer_InitializeResetPosition(var14, &var4, var7);
   Racer_Reset(var14);
   L[0].v0.v97.v2 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 2, var14);
   Racer_SetIconType(var14, 4);
   Racer_SetIconColorByDifficulty(var14, var2);
   Racer_HideIcon(var14, 0);
   mcHudMapServer_AddElement(L[0].v0.v97.v2);
   var15 = mcMissionManager_GetMission("BEAT_SH_05");
   var16 = UIManager_GetState("Cruising_Offline");
   var17 = Player_FindRacerObject(0);
   var18 = 0.0f;
   var19 = 0;
   var20 = 0;
   var21 = 0;
   var22 = null;
   var23 = 0;
   while (!var23)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var21);
       if (var21 == 1)
       {
           Racer_HideIcon(var14, 1);
           mcHudMapServer_RemoveElement(L[0].v0.v97.v2);
           Racer_SetStreamingLockedOut(var14);
           while (var21 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var21);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var14);
           Racer_HideIcon(var14, 0);
           mcHudMapServer_AddElement(L[0].v0.v97.v2);
       }
       var19 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var19 == 1)
       {
           while (var19 == 1)
           {
               var19 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var19 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           if (vhsmState_IsListener(var16) && (!Game_IsPaused()))
           {
               if ((var20 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
               {
                   var20 = var20 - 1;
               }
               var18 = Racer_DistanceToPoint(var17, &var4);
               if (var18 < 20.0f)
               {
                   if (PoliceManager_CheckPoliceActivity(1) > 1)
                   {
                       if (var20 == 0)
                       {
                           SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                           var20 = 100;
                       }
                       WAITUNWARPED(100);
                   }
                   else
                   {
                       Racer_HideIcon(var14, 1);
                       mcHookman_SetState(L[0].v0.v97.v0, 1);
                       Racer_Activate(var17);
                       mcEvent_PostEventStr("MISSION_EVENT", "BEAT_SH_05_COMPLETE");
                   }
               }
           }
           WAITUNWARPED(30);
       }
   }
   Racer_HideIcon(var14, 1);
   mcTargetManager_UnRegisterTarget(var3);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var3);
   PRINTSTRING(" shutdown(reserved for cutscene to follow).\n");
}

