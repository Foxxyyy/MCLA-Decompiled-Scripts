void main()
{
   auto var2, var3;

   var2 = Player_FindRacerObject(0);
   sub_13();
   sub_1d4();
   PRINTSTRING("Script: Networking/ResumeCareer.sc: Network players are shutdown, resuming career now.\n");
   while (!Racer_IsCarStreamed(var2))
   {
       PRINTSTRING("\n[SCRIPT] ResumeCareer: Waiting for my car to stream in");
       WAIT(500);
   }
   if (!(GetNoTutorialCommandLine() || GetNoCareerCommandLine()))
   {
       var3 = mcMissionManager_GetMission("RACE_GH_06");
       if (mcMission_GetState(var3) == 2)
       {
           mcMission_ChangeState(var3, 0, 0);
           mcMission_ChangeState(var3, 2, 0);
           UIManager_SendEvent("warpingToRace");
       }
   }
   sub_471();
   PRINTSTRING("Script: Networking/ResumeCareer.sc: All done, throwing cruising event\n");
   mcGame_ThrowEvent("cruising");
}

void sub_13()
{
   auto var2, var3, var4;

   var2 = 0;
   var3 = 0;
   PRINTSTRING("Script: Networking/ResumeCareer.sc: waiting for remote players to unload...\n");
   while (!var3)
   {
       var2 = 0;
       var4 = 0;
       while (var4 < PlayerManager_GetNumPlayers())
       {
           if (PlayerManager_IsPlayerValid(var4))
           {
               if (!PlayerManager_IsLocalPlayer(var4))
               {
                   var2 = var2 + 1;
               }
           }
           var4 = var4 + 1;
       }
       if (var2 == 0)
       {
           PRINTSTRING("Script: Networking/ResumeCareer.sc: no more valid remote players remain...\n");
           var3 = 1;
       }
       else
       {
           PRINTSTRING("Script: Networking/ResumeCareer.sc: ");
           PRINTINT(var2);
           PRINTSTRING(" valid remote players remaining. Waiting for remote players to finish unloading...\n");
           WAIT(100);
       }
   }
}

void sub_1d4()
{
   auto var2, var3;

   var2 = 0;
   var3 = 0;
   PRINTSTRING("Script: Networking/ResumeCareer.sc: waiting for dead players to be deleted...\n");
   while (!var3)
   {
       var2 = PlayerManager_GetNumDeadPlayers();
       if (var2 == 0)
       {
           PRINTSTRING("Script: Networking/ResumeCareer.sc: no dead players remaining...\n");
           var3 = 1;
       }
       else
       {
           PRINTSTRING("Script: Networking/ResumeCareer.sc: ");
           PRINTINT(var2);
           PRINTSTRING(" dead players remaining. Waiting for dead players to finish unloading...\n");
           WAIT(100);
       }
   }
}

void sub_471()
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

