void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52;

   var2 = 2;
   var2[0 * 3].v0 = 2439.44f;
   var2[0 * 3].v1 = -3.49826f;
   var2[0 * 3].v2 = -1079.47f;
   var2[1 * 3].v0 = 2432.81f;
   var2[1 * 3].v1 = -3.49952f;
   var2[1 * 3].v2 = -1073.89f;
   var9 = 2;
   var9[0] = 90.7099f;
   var9[1] = 89.2775f;
   var12 = 2;
   var12[0 * 3].v0 = 2071.78f;
   var12[0 * 3].v1 = -2.17557f;
   var12[0 * 3].v2 = -1081.35f;
   var12[1 * 3].v0 = 1660.35f;
   var12[1 * 3].v1 = 3.49686f;
   var12[1 * 3].v2 = -1077.84f;
   var19 = 2;
   var19[0] = (float)27;
   var19[1] = 24.5f;
   var22 = 2;
   var22[0] = (float)20;
   var22[1] = (float)20;
   var25 = 2;
   var25[0] = (float)100;
   var25[1] = (float)100;
   var28 = 2;
   var28[0] = (float)0;
   var28[1] = (float)0;
   var31 = 2;
   var31[0] = (float)0;
   var31[1] = (float)0;
   var34 = 2;
   var34[0 * 3].v0 = (float)0;
   var34[0 * 3].v1 = (float)0;
   var34[0 * 3].v2 = (float)0;
   var34[1 * 3].v0 = (float)0;
   var34[1 * 3].v1 = (float)0;
   var34[1 * 3].v2 = (float)0;
   var41 = 2;
   var41[0] = (float)0;
   var41[1] = (float)0;
   var44 = 2;
   var44[0] = "Normal";
   var44[1] = "Normal";
   var47 = 2;
   var47[0] = (float)-1;
   var47[1] = (float)-1;
   var50 = Race_GetCheckpointList(L[0].v3);
   CheckpointList_Reset(var50);
   var51 = 0;
   var52 = null;
   CheckpointList_ResizeList(var50, 2);
   var51 = 0;
   while (var51 < 2)
   {
       var52 = CheckpointList_GetCheckpoint(var50, var51);
       Checkpoint_SetPosition(var52, &(var12[var51 * 3]));
       Checkpoint_SetHeight(var52, var22[var51]);
       Checkpoint_SetActivationHeight(var52, var25[var51]);
       Checkpoint_SetActivationRadius(var52, var19[var51]);
       Checkpoint_SetMaxSpeed(var52, var47[var51]);
       if (StringCompare(var44[var51], "Line"))
       {
           Checkpoint_IsLineCheckpoint(var52, 1);
           Checkpoint_SetPositionSecond(var52, &(var34[var51 * 3]));
           Checkpoint_SetDrawPosLine(var52, var41[var51]);
       }
       Checkpoint_SetArrowLookatPosition(var52, var28[var51], var31[var51]);
       var51 = var51 + 1;
   }
   sub_2da(&L[0]);
}

void sub_2da(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   PRINTSTRING("LOADING RACE with ");
   PRINTINT(*((var0 + 16) + 3080));
   PRINTSTRING(" racers\n");
   var8.v0 = (float)0;
   var8.v1 = (float)1;
   var8.v2 = (float)0;
   var11.v0 = (float)0;
   var11.v1 = (float)0;
   var11.v2 = (float)-1;
   RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), 0, &var4, &var7);
   Math_VecRotateY(&var11, &var11, var7);
   var11.v0 = var4.v0 + var11.v0;
   var11.v1 = var4.v1 + var11.v1;
   var11.v2 = var4.v2 + var11.v2;
   var8.v0 = var4.v0 + var8.v0;
   var8.v1 = var4.v1 + var8.v1;
   var8.v2 = var4.v2 + var8.v2;
   UILogic_LockStreaming(&var4, &var8, &var11);
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       PRINTSTRING("Racer - ");
       PRINTINT(var3);
       PRINTSTRING("\n");
       Racer_SetStreamingLockedIn((*((var0 + 16) + 4))[var3 * 48].v0);
       var3 = var3 + 1;
   }
   var14 = 1;
   while (var14 > 0)
   {
       var14 = *((var0 + 16) + 3080);
       var3 = 0;
       while (var3 < *((var0 + 16) + 3080))
       {
           if (Racer_IsCarStreamed((*((var0 + 16) + 4))[var3 * 48].v0))
           {
               var14 = var14 - 1;
           }
           var3 = var3 + 1;
       }
       if (var14 > 0)
       {
           WAITUNWARPED(30);
       }
   }
   while (!PoliceManager_IsAllStreamedIn())
   {
       WAITUNWARPED(30);
   }
   while (OpponentManager_StillStreamingOut())
   {
       WAITUNWARPED(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           PRINTSTRING(" BRAIN CREATED! \n");
           (*((var0 + 16) + 4))[var3 * 48].v3 = BrainFactory_CreateBrainRacing((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
   var15 = START_NEW_SCRIPT_WITH_ARGS("Game/RaceTypes/OrderedCheckpointCore", var0, 802, 3800);
   while (!IsChildFinished(var15))
   {
       WAITUNWARPED(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           BrainFactory_DeleteBrain((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
}

