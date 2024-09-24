void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108;

   var2 = 16;
   var2[0 * 3].v0 = 821.136f;
   var2[0 * 3].v1 = 17.4819f;
   var2[0 * 3].v2 = -806.817f;
   var2[1 * 3].v0 = 824.828f;
   var2[1 * 3].v1 = 17.4819f;
   var2[1 * 3].v2 = -804.245f;
   var2[2 * 3].v0 = 829.687f;
   var2[2 * 3].v1 = 17.4819f;
   var2[2 * 3].v2 = -811.22f;
   var2[3 * 3].v0 = 825.994f;
   var2[3 * 3].v1 = 17.4819f;
   var2[3 * 3].v2 = -813.792f;
   var2[4 * 3].v0 = 834.545f;
   var2[4 * 3].v1 = 17.4819f;
   var2[4 * 3].v2 = -818.194f;
   var2[5 * 3].v0 = 830.852f;
   var2[5 * 3].v1 = 17.4819f;
   var2[5 * 3].v2 = -820.766f;
   var2[6 * 3].v0 = 839.689f;
   var2[6 * 3].v1 = 17.4819f;
   var2[6 * 3].v2 = -825.579f;
   var2[7 * 3].v0 = 835.996f;
   var2[7 * 3].v1 = 17.4819f;
   var2[7 * 3].v2 = -828.151f;
   var2[8 * 3].v0 = 844.261f;
   var2[8 * 3].v1 = 17.4819f;
   var2[8 * 3].v2 = -832.144f;
   var2[9 * 3].v0 = 840.569f;
   var2[9 * 3].v1 = 17.4819f;
   var2[9 * 3].v2 = -834.716f;
   var2[10 * 3].v0 = 849.12f;
   var2[10 * 3].v1 = 17.4819f;
   var2[10 * 3].v2 = -839.119f;
   var2[11 * 3].v0 = 845.427f;
   var2[11 * 3].v1 = 17.4819f;
   var2[11 * 3].v2 = -841.691f;
   var2[12 * 3].v0 = 853.978f;
   var2[12 * 3].v1 = 17.4819f;
   var2[12 * 3].v2 = -846.093f;
   var2[13 * 3].v0 = 850.285f;
   var2[13 * 3].v1 = 17.4819f;
   var2[13 * 3].v2 = -848.665f;
   var2[14 * 3].v0 = 858.836f;
   var2[14 * 3].v1 = 17.4819f;
   var2[14 * 3].v2 = -853.068f;
   var2[15 * 3].v0 = 855.144f;
   var2[15 * 3].v1 = 17.4819f;
   var2[15 * 3].v2 = -855.64f;
   var51 = 16;
   var51[0] = 145.141f;
   var51[1] = 145.141f;
   var51[2] = 145.141f;
   var51[3] = 145.141f;
   var51[4] = 145.141f;
   var51[5] = 145.141f;
   var51[6] = 145.141f;
   var51[7] = 145.141f;
   var51[8] = 145.141f;
   var51[9] = 145.141f;
   var51[10] = 145.141f;
   var51[11] = 145.141f;
   var51[12] = 145.141f;
   var51[13] = 145.141f;
   var51[14] = 145.141f;
   var51[15] = 145.141f;
   var68 = 1;
   var68[0 * 3].v0 = 1913.61f;
   var68[0 * 3].v1 = -7.64572f;
   var68[0 * 3].v2 = 514.091f;
   var72 = 1;
   var72[0] = 22.5f;
   var74 = 1;
   var74[0] = (float)20;
   var76 = 1;
   var76[0] = (float)100;
   var78 = 1;
   var78[0] = (float)0;
   var80 = 1;
   var80[0] = (float)0;
   var82 = 1;
   var82[0 * 3].v0 = (float)0;
   var82[0 * 3].v1 = (float)0;
   var82[0 * 3].v2 = (float)0;
   var86 = 1;
   var86[0] = (float)0;
   var88 = 1;
   var88[0] = "Normal";
   var90 = 1;
   var90[0] = (float)0;
   var92 = TriggerManager_CreateTriggerArray(2);
   var93 = TriggerArray_AddTriggerTimer(var92);
   Trigger_SetValueFloat(var93, "rTimer", (float)-3);
   Trigger_SetValueInt(var93, "lapActive", 0);
   Trigger_SetValueFloat(var93, "fRandomness", 1.0f);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 795.361f;
   var98.v1 = 17.9305f;
   var98.v2 = -806.716f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1749.05f;
   var98.v1 = -7.03461f;
   var98.v2 = 513.701f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1923.34f;
   var98.v1 = -6.40173f;
   var98.v2 = 511.731f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1749.05f;
   var98.v1 = -7.44318f;
   var98.v2 = 513.701f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1896.35f;
   var98.v1 = -1.89413f;
   var98.v2 = 53.2f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1800.56f;
   var98.v1 = -3.14468f;
   var98.v2 = 218.085f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1828.83f;
   var98.v1 = -3.14664f;
   var98.v2 = -225.72f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1655.27f;
   var98.v1 = -3.11005f;
   var98.v2 = -325.707f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1702.9f;
   var98.v1 = -2.26553f;
   var98.v2 = -464.878f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1555.86f;
   var98.v1 = -3.14117f;
   var98.v2 = -154.366f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 0);
   var93 = TriggerArray_AddTriggerTimer(var92);
   Trigger_SetValueFloat(var93, "rTimer", (float)-3);
   Trigger_SetValueInt(var93, "lapActive", 0);
   Trigger_SetValueFloat(var93, "fRandomness", 1.0f);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1731.96f;
   var98.v1 = -3.14667f;
   var98.v2 = -53.6084f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 1);
   var94 = Trigger_AddEvent(var93, "RoadDensity");
   var98.v0 = 1923.34f;
   var98.v1 = -6.62805f;
   var98.v2 = 511.731f;
   TriggerEvent_SetValueVector(var94, "RoadCenter", &var98);
   TriggerEvent_SetValueInt(var94, "iDensity", 1);
   var104 = Race_GetCheckpointList(L[0].v3);
   CheckpointList_Reset(var104);
   var105 = 0;
   var106 = null;
   CheckpointList_ResizeList(var104, 1);
   var105 = 0;
   while (var105 < 1)
   {
       var106 = CheckpointList_GetCheckpoint(var104, var105);
       Checkpoint_SetPosition(var106, &(var68[var105 * 3]));
       Checkpoint_SetHeight(var106, var74[var105]);
       Checkpoint_SetActivationHeight(var106, var76[var105]);
       Checkpoint_SetActivationRadius(var106, var72[var105]);
       Checkpoint_SetMaxSpeed(var106, var90[var105]);
       if (StringCompare(var88[var105], "Line"))
       {
           Checkpoint_IsLineCheckpoint(var106, 1);
           Checkpoint_SetPositionSecond(var106, &(var82[var105 * 3]));
           Checkpoint_SetDrawPosLine(var106, var86[var105]);
       }
       Checkpoint_SetArrowLookatPosition(var106, var78[var105], var80[var105]);
       var105 = var105 + 1;
   }
   var107 = 0;
   var108 = Race_GetRaceGrid(L[0].v3, 0);
   var107 = 0;
   while (var107 < 16)
   {
       RaceGrid_SetPosition(var108, var107, &(var2[var107 * 3]), var51[var107]);
       var107 = var107 + 1;
   }
   sub_abc(&L[0], "Delivery_vp_chv_impala_96");
   TriggerManager_DestroyTriggerArray(var92);
}

void sub_abc(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

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
   while (!Racer_IsCarStreamed((*((var0 + 16) + 4))[0 * 48].v0))
   {
       WAITUNWARPED(100);
   }
   var14 = START_NEW_SCRIPT_WITH_ARGS("Game/Racetypes/OrderedCheckpointCore", var0, 802, 3800);
   while (!IsChildFinished(var14))
   {
       WAITUNWARPED(100);
   }
}

