void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120;

   var2.v0.v0 = 31;
   var2.v0.v0.v103.v1 = 6;
   var2.v115 = "TOURNAMENT_SC";
   var2.v103.v11 = 2;
   var2.v116 = "GREETING_TOURNAMENT_SC_MISSION";
   var2.v117 = "GREETING_TOURNAMENT_SC";
   var2.v103.v0 = "sc_tournament1";
   var2.v103.v8 = 3;
   var2.v103.v1[0] = "game/Race/SouthCentral/Circuit/sc_circuit_jj_01b";
   var2.v103.v1[1] = "game/Race/SouthCentral/Ordered/sc_ordered_mb_01";
   var2.v103.v1[2] = "game/Race/SouthCentral/Ordered/sc_ordered_cb_02";
   var2.v103.v9 = 3;
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 204);
   mcHookman_SetType(var2.v0.v97.v0, 4);
   mcHookman_SetName(var2.v0.v97.v0, "GH_33");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "SC_GH_33_1_vpd_chv_belair_55");
   var2.v0.v94 = 10;
   var2.v0.v95 = 45.0f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = -161.567f;
   var2.v0.v0[0 * 3].v1 = -19.2945f;
   var2.v0.v0[0 * 3].v2 = 1279.87f;
   var2.v0.v0[1 * 3].v0 = -208.962f;
   var2.v0.v0[1 * 3].v1 = -17.4653f;
   var2.v0.v0[1 * 3].v2 = 1141.89f;
   var2.v0.v0[2 * 3].v0 = -161.049f;
   var2.v0.v0[2 * 3].v1 = -16.2546f;
   var2.v0.v0[2 * 3].v2 = 1004.73f;
   var2.v0.v0[3 * 3].v0 = -64.8929f;
   var2.v0.v0[3 * 3].v1 = -16.2425f;
   var2.v0.v0[3 * 3].v2 = 995.527f;
   var2.v0.v0[4 * 3].v0 = -16.7607f;
   var2.v0.v0[4 * 3].v1 = -18.1455f;
   var2.v0.v0[4 * 3].v2 = 1140.48f;
   var2.v0.v0[5 * 3].v0 = -67.0435f;
   var2.v0.v0[5 * 3].v1 = -19.8723f;
   var2.v0.v0[5 * 3].v2 = 1282.07f;
   var2.v0.v0[6 * 3].v0 = -178.724f;
   var2.v0.v0[6 * 3].v1 = -20.0914f;
   var2.v0.v0[6 * 3].v2 = 1386.58f;
   var2.v0.v0[7 * 3].v0 = -179.308f;
   var2.v0.v0[7 * 3].v1 = -20.7984f;
   var2.v0.v0[7 * 3].v2 = 1506.45f;
   var2.v0.v0[8 * 3].v0 = -53.6617f;
   var2.v0.v0[8 * 3].v1 = -20.9819f;
   var2.v0.v0[8 * 3].v2 = 1506.8f;
   var2.v0.v0[9 * 3].v0 = -56.3848f;
   var2.v0.v0[9 * 3].v1 = -20.0935f;
   var2.v0.v0[9 * 3].v2 = 1384.44f;
   var120 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_tournament_hookman", &var2, 118, 1500);
   while (!IsChildFinished(var120))
   {
       WAIT(100);
   }
}

