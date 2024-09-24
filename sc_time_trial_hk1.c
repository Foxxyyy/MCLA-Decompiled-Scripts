void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117;

   var2.v0.v0 = 31;
   var2.v0.v0.v105 = 4;
   var2.v103 = "TIMETRIAL_SC";
   var2.v104 = "game/Race/SouthCentral/Ordered/sc_ordered_dh_11";
   var2.v113 = "GREETING_TIMETRIAL_SC_MISSION";
   var2.v114 = "GREETING_TIMETRIAL_SC";
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 254);
   mcHookman_SetType(var2.v0.v97.v0, 3);
   mcHookman_SetName(var2.v0.v97.v0, "GH_30");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "SC_GH_30_1_vpd_chv_impala_64");
   mcHookman_SetDistrict(var2.v0.v97.v0, 4);
   var2.v111 = 4;
   var2.v105[0] = "SC_timetrial_vpd_chv_impala_64";
   mcCareer_SetTimeTrialTargetTime(4, 0, 0, 180000);
   mcCareer_SetTimeTrialTargetTime(4, 0, 1, 150000);
   var2.v105[1] = "SC_timetrial_vpd_pon_gto_66";
   mcCareer_SetTimeTrialTargetTime(4, 1, 0, 160000);
   mcCareer_SetTimeTrialTargetTime(4, 1, 1, 120000);
   var2.v105[2] = "SC_timetrial_vpd_lr_hse_08";
   mcCareer_SetTimeTrialTargetTime(4, 2, 0, 165000);
   mcCareer_SetTimeTrialTargetTime(4, 2, 1, 120000);
   var2.v105[3] = "SC_timetrial_vpd_mbz_clk63amg_08";
   mcCareer_SetTimeTrialTargetTime(4, 3, 0, 135000);
   mcCareer_SetTimeTrialTargetTime(4, 3, 1, 120000);
   var2.v0.v94 = 6;
   var2.v0.v95 = 135.0f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = 1645.93f;
   var2.v0.v0[0 * 3].v1 = -14.6519f;
   var2.v0.v0[0 * 3].v2 = 1342.78f;
   var2.v0.v0[1 * 3].v0 = 1187.95f;
   var2.v0.v0[1 * 3].v1 = -19.4669f;
   var2.v0.v0[1 * 3].v2 = 1639.75f;
   var2.v0.v0[2 * 3].v0 = 944.1f;
   var2.v0.v0[2 * 3].v1 = -19.4927f;
   var2.v0.v0[2 * 3].v2 = 1538.19f;
   var2.v0.v0[3 * 3].v0 = 1118.78f;
   var2.v0.v0[3 * 3].v1 = -17.0238f;
   var2.v0.v0[3 * 3].v2 = 1440.01f;
   var2.v0.v0[4 * 3].v0 = 1453.01f;
   var2.v0.v0[4 * 3].v1 = -14.0694f;
   var2.v0.v0[4 * 3].v2 = 1327.42f;
   var2.v0.v0[5 * 3].v0 = 1629.57f;
   var2.v0.v0[5 * 3].v1 = -12.0f;
   var2.v0.v0[5 * 3].v2 = 1245.66f;
   var117 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_timetrial_hookman", &var2, 115, 1500);
   while (!IsChildFinished(var117))
   {
       WAIT(100);
   }
}

