void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117;

   var2.v0.v0 = 31;
   var2.v0.v0.v105 = 4;
   var2.v103 = "TIMETRIAL_HL";
   var2.v104 = "Game/Race/Hills/Ordered/hl_ordered_ts_03";
   var2.v113 = "GREETING_TIMETRIAL_HILLS_MISSION";
   var2.v114 = "GREETING_TIMETRIAL_HILLS";
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 252);
   mcHookman_SetType(var2.v0.v97.v0, 3);
   mcHookman_SetName(var2.v0.v97.v0, "GH_05");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "GH_05_2_vp_chv_camaro_06");
   mcHookman_SetDistrict(var2.v0.v97.v0, 2);
   var2.v111 = 4;
   var2.v105[0] = "timetrial_vp_lam_miura_71";
   mcCareer_SetTimeTrialTargetTime(2, 0, 0, 210000);
   mcCareer_SetTimeTrialTargetTime(2, 0, 1, 175000);
   var2.v105[1] = "timetrial_vp_vw_scirocco_88";
   mcCareer_SetTimeTrialTargetTime(2, 1, 0, 230000);
   mcCareer_SetTimeTrialTargetTime(2, 1, 1, 207000);
   var2.v105[2] = "timetrial_vp_pon_transam_79";
   mcCareer_SetTimeTrialTargetTime(2, 2, 0, 220000);
   mcCareer_SetTimeTrialTargetTime(2, 2, 1, 200000);
   var2.v105[3] = "timetrial_vp_vw_golf_07";
   mcCareer_SetTimeTrialTargetTime(2, 3, 0, 205000);
   mcCareer_SetTimeTrialTargetTime(2, 3, 1, 185000);
   var2.v0.v94 = 11;
   var2.v0.v95 = -126.027f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = -1064.81f;
   var2.v0.v0[0 * 3].v1 = 29.8383f;
   var2.v0.v0[0 * 3].v2 = -1906.64f;
   var2.v0.v0[1 * 3].v0 = -505.931f;
   var2.v0.v0[1 * 3].v1 = 66.8604f;
   var2.v0.v0[1 * 3].v2 = -1461.96f;
   var2.v0.v0[2 * 3].v0 = -288.576f;
   var2.v0.v0[2 * 3].v1 = 84.8494f;
   var2.v0.v0[2 * 3].v2 = -1627.76f;
   var2.v0.v0[3 * 3].v0 = -300.357f;
   var2.v0.v0[3 * 3].v1 = 93.5082f;
   var2.v0.v0[3 * 3].v2 = -1201.63f;
   var2.v0.v0[4 * 3].v0 = -990.529f;
   var2.v0.v0[4 * 3].v1 = 73.2452f;
   var2.v0.v0[4 * 3].v2 = -1441.56f;
   var2.v0.v0[5 * 3].v0 = -726.006f;
   var2.v0.v0[5 * 3].v1 = 74.3505f;
   var2.v0.v0[5 * 3].v2 = -1528.52f;
   var2.v0.v0[6 * 3].v0 = -1417.83f;
   var2.v0.v0[6 * 3].v1 = 59.993f;
   var2.v0.v0[6 * 3].v2 = -1696.56f;
   var2.v0.v0[7 * 3].v0 = -1734.19f;
   var2.v0.v0[7 * 3].v1 = 70.3518f;
   var2.v0.v0[7 * 3].v2 = -1465.46f;
   var2.v0.v0[8 * 3].v0 = -1823.34f;
   var2.v0.v0[8 * 3].v1 = 47.5787f;
   var2.v0.v0[8 * 3].v2 = -1911.56f;
   var2.v0.v0[9 * 3].v0 = -2135.36f;
   var2.v0.v0[9 * 3].v1 = 20.504f;
   var2.v0.v0[9 * 3].v2 = -1785.32f;
   var2.v0.v0[10 * 3].v0 = -1709.86f;
   var2.v0.v0[10 * 3].v1 = 29.7865f;
   var2.v0.v0[10 * 3].v2 = -1997.74f;
   var117 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_timetrial_hookman", &var2, 115, 1500);
   while (!IsChildFinished(var117))
   {
       WAIT(100);
   }
}

