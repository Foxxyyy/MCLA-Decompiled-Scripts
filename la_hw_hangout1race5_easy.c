void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78;

   var2 = 8;
   var2[0 * 3].v0 = 492.101f;
   var2[0 * 3].v1 = 23.8275f;
   var2[0 * 3].v2 = -886.828f;
   var2[1 * 3].v0 = 492.12f;
   var2[1 * 3].v1 = 23.8275f;
   var2[1 * 3].v2 = -882.328f;
   var2[2 * 3].v0 = 492.082f;
   var2[2 * 3].v1 = 23.8275f;
   var2[2 * 3].v2 = -891.328f;
   var2[3 * 3].v0 = 500.62f;
   var2[3 * 3].v1 = 23.8275f;
   var2[3 * 3].v2 = -882.364f;
   var2[4 * 3].v0 = 500.582f;
   var2[4 * 3].v1 = 23.8275f;
   var2[4 * 3].v2 = -891.364f;
   var2[5 * 3].v0 = 500.601f;
   var2[5 * 3].v1 = 23.8275f;
   var2[5 * 3].v2 = -886.864f;
   var2[6 * 3].v0 = 509.12f;
   var2[6 * 3].v1 = 23.8275f;
   var2[6 * 3].v2 = -882.4f;
   var2[7 * 3].v0 = 509.082f;
   var2[7 * 3].v1 = 23.8275f;
   var2[7 * 3].v2 = -891.399f;
   var27 = 8;
   var27[0] = 90.2409f;
   var27[1] = 90.2409f;
   var27[2] = 90.2409f;
   var27[3] = 90.2409f;
   var27[4] = 90.2409f;
   var27[5] = 90.2409f;
   var27[6] = 90.2409f;
   var27[7] = 90.2409f;
   var36 = 2;
   var36[0 * 3].v0 = 53.4074f;
   var36[0 * 3].v1 = 23.9274f;
   var36[0 * 3].v2 = -871.428f;
   var36[1 * 3].v0 = -119.449f;
   var36[1 * 3].v1 = 17.8494f;
   var36[1 * 3].v2 = -736.949f;
   var43 = 2;
   var43[0] = 25.5f;
   var43[1] = (float)29;
   var46 = 2;
   var46[0] = (float)20;
   var46[1] = (float)20;
   var49 = 2;
   var49[0] = (float)100;
   var49[1] = (float)100;
   var52 = 2;
   var52[0] = (float)0;
   var52[1] = (float)0;
   var55 = 2;
   var55[0] = (float)0;
   var55[1] = (float)0;
   var58 = 2;
   var58[0 * 3].v0 = (float)0;
   var58[0 * 3].v1 = (float)0;
   var58[0 * 3].v2 = (float)0;
   var58[1 * 3].v0 = (float)0;
   var58[1 * 3].v1 = (float)0;
   var58[1 * 3].v2 = (float)0;
   var65 = 2;
   var65[0] = (float)0;
   var65[1] = (float)0;
   var68 = 2;
   var68[0] = "Normal";
   var68[1] = "Normal";
   var71 = 2;
   var71[0] = (float)0;
   var71[1] = (float)0;
   var74 = Race_GetCheckpointList(L[0].v3);
   CheckpointList_Reset(var74);
   var75 = 0;
   var76 = null;
   CheckpointList_ResizeList(var74, 2);
   var75 = 0;
   while (var75 < 2)
   {
       var76 = CheckpointList_GetCheckpoint(var74, var75);
       Checkpoint_SetPosition(var76, &(var36[var75 * 3]));
       Checkpoint_SetHeight(var76, var46[var75]);
       Checkpoint_SetActivationHeight(var76, var49[var75]);
       Checkpoint_SetActivationRadius(var76, var43[var75]);
       Checkpoint_SetMaxSpeed(var76, var71[var75]);
       if (StringCompare(var68[var75], "Line"))
       {
           Checkpoint_IsLineCheckpoint(var76, 1);
           Checkpoint_SetPositionSecond(var76, &(var58[var75 * 3]));
           Checkpoint_SetDrawPosLine(var76, var65[var75]);
       }
       Checkpoint_SetArrowLookatPosition(var76, var52[var75], var55[var75]);
       var75 = var75 + 1;
   }
   var77 = 0;
   var78 = Race_GetRaceGrid(L[0].v3, 0);
   var77 = 0;
   while (var77 < 8)
   {
       RaceGrid_SetPosition(var78, var77, &(var2[var77 * 3]), var27[var77]);
       var77 = var77 + 1;
   }
   sub_42c(&L[0]);
}

void sub_42c(var0)
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

