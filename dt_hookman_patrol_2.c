void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98;

   var2 = 6;
   var2[0 * 3].v0 = 1493.1f;
   var2[0 * 3].v1 = -4.06148f;
   var2[0 * 3].v2 = 161.768f;
   var2[1 * 3].v0 = 1740.68f;
   var2[1 * 3].v1 = -3.149f;
   var2[1 * 3].v2 = 349.221f;
   var2[2 * 3].v0 = 1662.64f;
   var2[2 * 3].v1 = -5.34691f;
   var2[2 * 3].v2 = 391.195f;
   var2[3 * 3].v0 = 1484.79f;
   var2[3 * 3].v1 = -10.189f;
   var2[3 * 3].v2 = 393.821f;
   var2[4 * 3].v0 = 1407.16f;
   var2[4 * 3].v1 = -10.7674f;
   var2[4 * 3].v2 = 346.134f;
   var2[5 * 3].v0 = 1406.46f;
   var2[5 * 3].v1 = -7.25592f;
   var2[5 * 3].v2 = 206.036f;
   var21 = 6;
   var21[0] = 5.5f;
   var21[1] = 3.5f;
   var21[2] = 5.5f;
   var21[3] = 5.5f;
   var21[4] = 2.5f;
   var21[5] = 4.5f;
   var28 = 6;
   var28[0] = (float)20;
   var28[1] = (float)20;
   var28[2] = (float)20;
   var28[3] = (float)20;
   var28[4] = (float)20;
   var28[5] = (float)20;
   var35 = 6;
   var35[0] = (float)100;
   var35[1] = (float)100;
   var35[2] = (float)100;
   var35[3] = (float)100;
   var35[4] = (float)100;
   var35[5] = (float)100;
   var42 = 6;
   var42[0] = (float)0;
   var42[1] = (float)0;
   var42[2] = (float)0;
   var42[3] = (float)0;
   var42[4] = (float)0;
   var42[5] = (float)0;
   var49 = 6;
   var49[0] = (float)0;
   var49[1] = (float)0;
   var49[2] = (float)0;
   var49[3] = (float)0;
   var49[4] = (float)0;
   var49[5] = (float)0;
   var56 = 6;
   var56[0 * 3].v0 = (float)0;
   var56[0 * 3].v1 = (float)0;
   var56[0 * 3].v2 = (float)0;
   var56[1 * 3].v0 = (float)0;
   var56[1 * 3].v1 = (float)0;
   var56[1 * 3].v2 = (float)0;
   var56[2 * 3].v0 = (float)0;
   var56[2 * 3].v1 = (float)0;
   var56[2 * 3].v2 = (float)0;
   var56[3 * 3].v0 = (float)0;
   var56[3 * 3].v1 = (float)0;
   var56[3 * 3].v2 = (float)0;
   var56[4 * 3].v0 = (float)0;
   var56[4 * 3].v1 = (float)0;
   var56[4 * 3].v2 = (float)0;
   var56[5 * 3].v0 = (float)0;
   var56[5 * 3].v1 = (float)0;
   var56[5 * 3].v2 = (float)0;
   var75 = 6;
   var75[0] = (float)0;
   var75[1] = (float)0;
   var75[2] = (float)0;
   var75[3] = (float)0;
   var75[4] = (float)0;
   var75[5] = (float)0;
   var82 = 6;
   var82[0] = "Normal";
   var82[1] = "Normal";
   var82[2] = "Normal";
   var82[3] = "Normal";
   var82[4] = "Normal";
   var82[5] = "Normal";
   var89 = 6;
   var89[0] = (float)-1;
   var89[1] = (float)-1;
   var89[2] = (float)-1;
   var89[3] = (float)-1;
   var89[4] = (float)-1;
   var89[5] = (float)-1;
   var96 = Race_GetCheckpointList(L[0].v3);
   CheckpointList_Reset(var96);
   var97 = 0;
   var98 = null;
   CheckpointList_ResizeList(var96, 6);
   var97 = 0;
   while (var97 < 6)
   {
       var98 = CheckpointList_GetCheckpoint(var96, var97);
       Checkpoint_SetPosition(var98, &(var2[var97 * 3]));
       Checkpoint_SetHeight(var98, var28[var97]);
       Checkpoint_SetActivationHeight(var98, var35[var97]);
       Checkpoint_SetActivationRadius(var98, var21[var97]);
       Checkpoint_SetMaxSpeed(var98, var89[var97]);
       if (StringCompare(var82[var97], "Line"))
       {
           Checkpoint_IsLineCheckpoint(var98, 1);
           Checkpoint_SetPositionSecond(var98, &(var56[var97 * 3]));
           Checkpoint_SetDrawPosLine(var98, var75[var97]);
       }
       Checkpoint_SetArrowLookatPosition(var98, var42[var97], var49[var97]);
       var97 = var97 + 1;
   }
   sub_497(&L[0]);
}

void sub_497(var0)
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

