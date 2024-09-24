void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117;

   var2.v0.v0 = 31;
   var2.v0.v0.v105 = 4;
   var2.v103 = "TIMETRIAL_DT";
   var2.v104 = "Game/Race/Downtown/Ordered/dt_ordered_mb_04";
   var2.v113 = "GREETING_TIMETRIAL_DOWNTOWN_MISSION";
   var2.v114 = "GREETING_TIMETRIAL_DOWNTOWN";
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 253);
   mcHookman_SetType(var2.v0.v97.v0, 3);
   mcHookman_SetName(var2.v0.v97.v0, "GH_25");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "GH_25_2_vp_dge_charger_06");
   mcHookman_SetDistrict(var2.v0.v97.v0, 3);
   var2.v111 = 4;
   var2.v105[0] = "timetrial_vp_mit_3000gt_99";
   mcCareer_SetTimeTrialTargetTime(3, 0, 0, 180000);
   mcCareer_SetTimeTrialTargetTime(3, 0, 1, 150000);
   var2.v105[1] = "timetrial_vp_dge_challenger_70";
   mcCareer_SetTimeTrialTargetTime(3, 1, 0, 170000);
   mcCareer_SetTimeTrialTargetTime(3, 1, 1, 150000);
   var2.v105[2] = "timetrial_vp_mbz_sl65_07";
   mcCareer_SetTimeTrialTargetTime(3, 2, 0, 150000);
   mcCareer_SetTimeTrialTargetTime(3, 2, 1, 130000);
   var2.v105[3] = "timetrial_vp_kaw_ninja_zx14_06";
   mcCareer_SetTimeTrialTargetTime(3, 3, 0, 135000);
   mcCareer_SetTimeTrialTargetTime(3, 3, 1, 115000);
   var2.v0.v94 = 7;
   var2.v0.v95 = 57.0254f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = 1930.21f;
   var2.v0.v0[0 * 3].v1 = -3.11997f;
   var2.v0.v0[0 * 3].v2 = 173.45f;
   var2.v0.v0[1 * 3].v0 = 1920.17f;
   var2.v0.v0[1 * 3].v1 = 2.18803f;
   var2.v0.v0[1 * 3].v2 = 31.0801f;
   var2.v0.v0[2 * 3].v0 = 2083.53f;
   var2.v0.v0[2 * 3].v1 = 3.851f;
   var2.v0.v0[2 * 3].v2 = -253.218f;
   var2.v0.v0[3 * 3].v0 = (float)2207;
   var2.v0.v0[3 * 3].v1 = 3.90883f;
   var2.v0.v0[3 * 3].v2 = -512.292f;
   var2.v0.v0[4 * 3].v0 = 2320.46f;
   var2.v0.v0[4 * 3].v1 = -1.15707f;
   var2.v0.v0[4 * 3].v2 = -421.143f;
   var2.v0.v0[5 * 3].v0 = 2257.98f;
   var2.v0.v0[5 * 3].v1 = -3.1449f;
   var2.v0.v0[5 * 3].v2 = -200.227f;
   var2.v0.v0[6 * 3].v0 = 2069.78f;
   var2.v0.v0[6 * 3].v1 = -4.28085f;
   var2.v0.v0[6 * 3].v2 = 125.087f;
   var117 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_timetrial_hookman", &var2, 115, 1500);
   while (!IsChildFinished(var117))
   {
       WAIT(100);
   }
}

