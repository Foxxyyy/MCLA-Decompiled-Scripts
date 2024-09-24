void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120;

   var2.v0.v0 = 31;
   var2.v0.v0.v103.v1 = 6;
   var2.v115 = "TOURNAMENT_BEACHES";
   var2.v103.v11 = 3;
   var2.v116 = "GREETING_TOURNAMENT_BEACHES_MISSION";
   var2.v117 = "GREETING_TOURNAMENT_BEACHES";
   var2.v103.v0 = "be_tournament1";
   var2.v103.v8 = 3;
   var2.v103.v1[0] = "Game/Race/Beaches/Ordered/be_ordered_mb_06";
   var2.v103.v1[1] = "Game/Race/Hollywood/Ordered/hw_ordered_mb_02";
   var2.v103.v1[2] = "Game/Race/Beaches/Ordered/be_ordered_ds_02";
   var2.v103.v9 = 3;
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 201);
   mcHookman_SetType(var2.v0.v97.v0, 4);
   mcHookman_SetName(var2.v0.v97.v0, "GH_06");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "GH_06_2_vp_chv_camaro_06");
   var2.v0.v94 = 5;
   var2.v0.v95 = -108.99f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = -2466.05f;
   var2.v0.v0[0 * 3].v1 = 0.963593f;
   var2.v0.v0[0 * 3].v2 = -582.813f;
   var2.v0.v0[1 * 3].v0 = -2433.54f;
   var2.v0.v0[1 * 3].v1 = 1.069f;
   var2.v0.v0[1 * 3].v2 = -472.938f;
   var2.v0.v0[2 * 3].v0 = -2561.95f;
   var2.v0.v0[2 * 3].v1 = -3.24664f;
   var2.v0.v0[2 * 3].v2 = -198.593f;
   var2.v0.v0[3 * 3].v0 = -2825.43f;
   var2.v0.v0[3 * 3].v1 = -4.78784f;
   var2.v0.v0[3 * 3].v2 = -295.62f;
   var2.v0.v0[4 * 3].v0 = -2714.29f;
   var2.v0.v0[4 * 3].v1 = -4.64645f;
   var2.v0.v0[4 * 3].v2 = -550.358f;
   var120 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_tournament_hookman", &var2, 118, 1500);
   while (!IsChildFinished(var120))
   {
       WAIT(100);
   }
}

