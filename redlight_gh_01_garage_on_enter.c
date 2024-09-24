void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   var2 = sub_a(0);
   var3.v0 = 861.773f;
   var3.v1 = 17.061f;
   var3.v2 = -809.715f;
   var6 = 37.7f;
   Racer_InitializeResetPosition(var2, &var3, var6);
   var7.v2.v0.v0 = 0.0f;
   var7.v2.v0.v1 = 0.0f;
   var7.v2.v0.v2 = 0.0f;
   var7.v2.v3 = 0.0f;
   CineScript_SetGameCoordSysBinding(&var7);
   CineScript_Prop_LoadSetDressing("cut_la_hw_oh_garage_set_items", 0);
   var13 = null;
   if (!GetDemoCommandLine())
   {
       var14 = OpponentManager_CreateOpponent();
       var15 = Opponent_GetRacer(var14);
       OpponentManager_LoadOpponent(var14, "CIN_01_vp_chv_camaross_69", &(var7.v2.v0), var7.v2.v3);
       OpponentManager_AddOpponentToWorld(var14);
       Racer_SetVehicleDriverEnable(var15, 0);
       Racer_SetExhaust(var15, 0);
       Racer_SetHeadlights(var15, 0);
       Racer_SetStreamingLockedIn(var15);
       UILogic_ResumeGame();
       while (!Racer_IsCarStreamed(var15))
       {
           PRINTSTRING("Waiting for racer to stream in\n");
           WAITUNWARPED(100);
       }
       sub_1a5(var2, 0);
       sub_1a5(var15, 1);
       PostProcessing_SetCutsceneDof();
       var13 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_hollywood_garage_intro_generated", &null, 0, 1500);
       while (!IsChildFinished(var13))
       {
           WAITUNWARPED(100);
       }
       PostProcessing_SetGameDof();
       Racer_SetStreamingUnlocked(var15);
       OpponentManager_RemoveOpponentFromWorld(var14);
       OpponentManager_DeleteOpponent(var14);
   }
   else
   {
       sub_1a5(var2, 0);
       var13 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/cut_la_hw_oh_garage_01x_ent_generated", &null, 0, 1500);
       while (!IsChildFinished(var13))
       {
           WAITUNWARPED(10);
       }
   }
   sub_357(1, 1, 0x3f800000, 0);
   Registry_SetValueInt("hw_garage_state", 5);
   var16 = mcMissionManager_GetMission("REDLIGHT_GH_01");
   mcMission_ChangeState(var16, 3, 0);
}

function sub_a(var0)
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

void sub_1a5(var0, var1)
{
   auto var4, var5, var6, var7;

   var4 = Racer_GetUID(var0);
   if (var4 == 0)
   {
       var4 = 5000 + var1;
       while (Racer_FindFromUID(var4) != null)
       {
           var4 = var4 + 1;
           WAITUNWARPED(10);
       }
       Racer_SetUID(var0, var4);
   }
   CineScript_Cars_AssignIdToSlot(var4, var1);
   var5 = Racer_GetVehicleDriverName(var0);
   CineScript_Characters_AssignNameToSlot(var5, var1);
}

void sub_357(var0, var1, var2, var3)
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

