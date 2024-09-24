void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117;

   var2.v0.v0 = 31;
   var2.v0.v0.v105 = 4;
   var2.v103 = "TIMETRIAL_BE";
   var2.v104 = "Game/Race/Beaches/Ordered/be_ordered_mb_04";
   var2.v113 = "GREETING_TIMETRIAL_BEACHES_MISSION";
   var2.v114 = "GREETING_TIMETRIAL_BEACHES";
   var2.v0.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var2.v0.v97.v0, 251);
   mcHookman_SetType(var2.v0.v97.v0, 3);
   mcHookman_SetName(var2.v0.v97.v0, "GH_09");
   mcHookman_SetCarConfigName(var2.v0.v97.v0, "GH_09_1_vp_buk_grandnational_87");
   mcHookman_SetDistrict(var2.v0.v97.v0, 1);
   var2.v111 = 4;
   var2.v105[0] = "timetrial_vp_frd_boss302_69";
   mcCareer_SetTimeTrialTargetTime(1, 0, 0, 240000);
   mcCareer_SetTimeTrialTargetTime(1, 0, 1, 197000);
   var2.v105[1] = "timetrial_vp_frd_focus_04";
   mcCareer_SetTimeTrialTargetTime(1, 1, 0, 230000);
   mcCareer_SetTimeTrialTargetTime(1, 1, 1, 210000);
   var2.v105[2] = "timetrial_vp_chv_camaro_06";
   mcCareer_SetTimeTrialTargetTime(1, 2, 0, 210000);
   mcCareer_SetTimeTrialTargetTime(1, 2, 1, 185000);
   var2.v105[3] = "timetrial_vp_frd_gt_06";
   mcCareer_SetTimeTrialTargetTime(1, 3, 0, 173000);
   mcCareer_SetTimeTrialTargetTime(1, 3, 1, 150000);
   var2.v0.v94 = 6;
   var2.v0.v95 = -60.63f;
   var2.v0.v100 = 0;
   var2.v0.v0[0 * 3].v0 = -2772.92f;
   var2.v0.v0[0 * 3].v1 = -22.0402f;
   var2.v0.v0[0 * 3].v2 = 922.933f;
   var2.v0.v0[1 * 3].v0 = -2629.77f;
   var2.v0.v0[1 * 3].v1 = -17.1018f;
   var2.v0.v0[1 * 3].v2 = 810.331f;
   var2.v0.v0[2 * 3].v0 = -2540.54f;
   var2.v0.v0[2 * 3].v1 = -7.65015f;
   var2.v0.v0[2 * 3].v2 = 521.718f;
   var2.v0.v0[3 * 3].v0 = -2468.03f;
   var2.v0.v0[3 * 3].v1 = -5.37665f;
   var2.v0.v0[3 * 3].v2 = 562.656f;
   var2.v0.v0[4 * 3].v0 = -2514.57f;
   var2.v0.v0[4 * 3].v1 = -8.85196f;
   var2.v0.v0[4 * 3].v2 = 855.383f;
   var2.v0.v0[5 * 3].v0 = -2757.01f;
   var2.v0.v0[5 * 3].v1 = -23.5073f;
   var2.v0.v0[5 * 3].v2 = 1057.92f;
   var117 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/generic_timetrial_hookman", &var2, 115, 1500);
   while (!IsChildFinished(var117))
   {
       WAIT(100);
   }
}

