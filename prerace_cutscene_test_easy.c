void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64;

   var2 = 8;
   var2[0 * 3].v0 = -1469.26f;
   var2[0 * 3].v1 = -6.25407f;
   var2[0 * 3].v2 = 486.529f;
   var2[1 * 3].v0 = -1468.46f;
   var2[1 * 3].v1 = -6.25407f;
   var2[1 * 3].v2 = 490.957f;
   var2[2 * 3].v0 = -1460.1f;
   var2[2 * 3].v1 = -6.25407f;
   var2[2 * 3].v2 = 489.442f;
   var2[3 * 3].v0 = -1460.9f;
   var2[3 * 3].v1 = -6.25407f;
   var2[3 * 3].v2 = 485.014f;
   var2[4 * 3].v0 = -1451.73f;
   var2[4 * 3].v1 = -6.25407f;
   var2[4 * 3].v2 = 487.926f;
   var2[5 * 3].v0 = -1452.54f;
   var2[5 * 3].v1 = -6.25407f;
   var2[5 * 3].v2 = 483.499f;
   var2[6 * 3].v0 = -1442.88f;
   var2[6 * 3].v1 = -6.25407f;
   var2[6 * 3].v2 = 486.322f;
   var2[7 * 3].v0 = -1443.68f;
   var2[7 * 3].v1 = -6.25407f;
   var2[7 * 3].v2 = 481.894f;
   var27 = 8;
   var27[0] = 100.268f;
   var27[1] = 100.268f;
   var27[2] = 100.268f;
   var27[3] = 100.268f;
   var27[4] = 100.268f;
   var27[5] = 100.268f;
   var27[6] = 100.268f;
   var27[7] = 100.268f;
   var36 = 1;
   var36[0 * 3].v0 = -1749.58f;
   var36[0 * 3].v1 = -4.08521f;
   var36[0 * 3].v2 = 489.141f;
   var40 = 1;
   var40[0] = 22.5f;
   var42 = 1;
   var42[0] = (float)20;
   var44 = 1;
   var44[0] = (float)100;
   var46 = 1;
   var46[0] = (float)0;
   var48 = 1;
   var48[0] = (float)0;
   var50 = 1;
   var50[0 * 3].v0 = (float)0;
   var50[0 * 3].v1 = (float)0;
   var50[0 * 3].v2 = (float)0;
   var54 = 1;
   var54[0] = (float)0;
   var56 = 1;
   var56[0] = "Normal";
   var58 = 1;
   var58[0] = (float)-1;
   var60 = Race_GetCheckpointList(L[0].v3);
   CheckpointList_Reset(var60);
   var61 = 0;
   var62 = null;
   CheckpointList_ResizeList(var60, 1);
   var61 = 0;
   while (var61 < 1)
   {
       var62 = CheckpointList_GetCheckpoint(var60, var61);
       Checkpoint_SetPosition(var62, &(var36[var61 * 3]));
       Checkpoint_SetHeight(var62, var42[var61]);
       Checkpoint_SetActivationHeight(var62, var44[var61]);
       Checkpoint_SetActivationRadius(var62, var40[var61]);
       Checkpoint_SetMaxSpeed(var62, var58[var61]);
       if (StringCompare(var56[var61], "Line"))
       {
           Checkpoint_IsLineCheckpoint(var62, 1);
           Checkpoint_SetPositionSecond(var62, &(var50[var61 * 3]));
           Checkpoint_SetDrawPosLine(var62, var54[var61]);
       }
       Checkpoint_SetArrowLookatPosition(var62, var46[var61], var48[var61]);
       var61 = var61 + 1;
   }
   var63 = 0;
   var64 = Race_GetRaceGrid(L[0].v3, 0);
   var63 = 0;
   while (var63 < 8)
   {
       RaceGrid_SetPosition(var64, var63, &(var2[var63 * 3]), var27[var63]);
       var63 = var63 + 1;
   }
   sub_3b3(&L[0]);
}

void sub_3b3(var0)
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

