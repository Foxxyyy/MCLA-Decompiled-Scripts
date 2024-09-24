void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120;

   var2.v0.v0 = 31;
   var2.v0.v0.v103.v1 = 6;
   var2.v115 = "TOURNAMENT_HOLLYWOOD";
   var2.v103.v11 = 0;
   var2.v116 = "GREETING_TOURNAMENT_HOLLYWOOD_MISSION";
   var2.v117 = "GREETING_TOURNAMENT_HOLLYWOOD";
   var2.v103.v0 = "hw_tournament1";
   var2.v103.v8 = 3;
   var2.v103.v1[0] = "Game/Race/Hollywood/Ordered/hw_ordered_gs_01";
   var2.v103.v1[1] = "Game/Race/Hollywood/Circuit/hw_circuit_ds_02a";
   var2.v103.v1[2] = "Game/Race/Hollywood/Ordered/hw_ordered_mb_05";
   var2.v103.v9 = 3;
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 200);
   mcHookman_SetType(var2.v0.v97.v0, 4);
   mcHookman_SetName(var2.v0.v97.v0, "GH_11");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "GH_11_1_vp_pon_transam_79");
   var2.v0.v94 = 6;
   var2.v0.v95 = 97.1086f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = -1483.55f;
   var2.v0.v0[0 * 3].v1 = 1.15479f;
   var2.v0.v0[0 * 3].v2 = 286.879f;
   var2.v0.v0[1 * 3].v0 = -1682.52f;
   var2.v0.v0[1 * 3].v1 = -5.7244f;
   var2.v0.v0[1 * 3].v2 = 279.733f;
   var2.v0.v0[2 * 3].v0 = -1837.75f;
   var2.v0.v0[2 * 3].v1 = -5.5455f;
   var2.v0.v0[2 * 3].v2 = 176.936f;
   var2.v0.v0[3 * 3].v0 = -1781.13f;
   var2.v0.v0[3 * 3].v1 = -3.9989f;
   var2.v0.v0[3 * 3].v2 = 36.1543f;
   var2.v0.v0[4 * 3].v0 = -1555.43f;
   var2.v0.v0[4 * 3].v1 = -6.02548f;
   var2.v0.v0[4 * 3].v2 = -51.4969f;
   var2.v0.v0[5 * 3].v0 = -1414.29f;
   var2.v0.v0[5 * 3].v1 = -1.0658f;
   var2.v0.v0[5 * 3].v2 = 113.215f;
   var120 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_tournament_hookman", &var2, 118, 1500);
   while (!IsChildFinished(var120))
   {
       WAIT(100);
   }
}

