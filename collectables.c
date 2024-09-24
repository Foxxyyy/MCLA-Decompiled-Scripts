void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132;

   var2.v3 = 60;
   var66 = 60;
   var127 = sub_23(&var66, &(var2.v3));
   WAIT(10000);
   var128 = 0;
   var129 = 0;
   while (var128 == 0)
   {
       var130 = PropManager_GetFirstBrokenRaceProp(var127);
       if (var130 != null)
       {
           PRINTSTRING("BrokenProp is not null!! \n");
           var131 = 0;
           var132 = 1;
           while (var132)
           {
               if (var66[var131] == var130)
               {
                   PropManager_RemoveRaceProp(var127, var130);
                   var66[var131] = null;
                   var2.v3[var131] = 1;
                   var132 = 0;
                   var129 = LocalOptions_SaveCollectables(var131);
                   PRINTSTRING("found collectable prop at idx ");
                   PRINTINT(var131);
                   PRINTSTRING("\n");
                   SplashManager_Splash(0, 1, "Collectable Found!!", 0x40000000, 1, 0);
               }
               var131 = var131 + 1;
               if (var131 >= 60)
               {
                   PRINTSTRING("didn't find collectable prop\n");
                   var132 = 0;
               }
           }
       }
       if (var129 > 0)
       {
           StatsManager_UpdateStatInt("gCOL", 0, 2, var129);
       }
       WAIT(1000);
   }
   sub_87f(var127, &var66, &(var2.v3));
}

function sub_23(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143, var144, var145, var146, var147, var148, var149, var150, var151, var152, var153, var154, var155, var156, var157, var158, var159, var160, var161, var162, var163, var164, var165, var166, var167, var168, var169, var170, var171, var172, var173, var174, var175, var176, var177, var178, var179, var180, var181, var182, var183, var184, var185, var186, var187, var188, var189, var190, var191;

   var4 = PropManager_InitRaceProps(70, 5);
   var5.v0 = (float)0;
   var5.v1 = (float)0;
   var5.v2 = (float)0;
   var8 = 60;
   var8[0 * 3].v0 = -550.44f;
   var8[0 * 3].v1 = 18.83f;
   var8[0 * 3].v2 = -696.79f;
   var8[1 * 3].v0 = -1768.93f;
   var8[1 * 3].v1 = 6.94f;
   var8[1 * 3].v2 = -866.89f;
   var8[2 * 3].v0 = -2138.87f;
   var8[2 * 3].v1 = 1.25f;
   var8[2 * 3].v2 = -187.94f;
   var8[3 * 3].v0 = -1687.47f;
   var8[3 * 3].v1 = 14.89f;
   var8[3 * 3].v2 = 575.42f;
   var8[4 * 3].v0 = -1879.91f;
   var8[4 * 3].v1 = 3.41f;
   var8[4 * 3].v2 = 388.87f;
   var8[5 * 3].v0 = -300.97f;
   var8[5 * 3].v1 = -7.57f;
   var8[5 * 3].v2 = 186.05f;
   var8[6 * 3].v0 = 689.86f;
   var8[6 * 3].v1 = -13.62f;
   var8[6 * 3].v2 = 254.58f;
   var8[7 * 3].v0 = 398.92f;
   var8[7 * 3].v1 = 7.12f;
   var8[7 * 3].v2 = -221.45f;
   var8[8 * 3].v0 = -298.4f;
   var8[8 * 3].v1 = 17.4f;
   var8[8 * 3].v2 = -405.2f;
   var8[9 * 3].v0 = -940.1f;
   var8[9 * 3].v1 = -0.4f;
   var8[9 * 3].v2 = -229.9f;
   var8[10 * 3].v0 = -1765.7f;
   var8[10 * 3].v1 = -1.13f;
   var8[10 * 3].v2 = 99.56f;
   var8[11 * 3].v0 = -1548.4f;
   var8[11 * 3].v1 = 2.13f;
   var8[11 * 3].v2 = -226.13f;
   var8[12 * 3].v0 = -1266.63f;
   var8[12 * 3].v1 = 7.21f;
   var8[12 * 3].v2 = 394.22f;
   var8[13 * 3].v0 = 431.26f;
   var8[13 * 3].v1 = 23.04f;
   var8[13 * 3].v2 = -1025.88f;
   var8[14 * 3].v0 = 778.09f;
   var8[14 * 3].v1 = 30.29f;
   var8[14 * 3].v2 = -1280.96f;
   var8[15 * 3].v0 = 1024.79f;
   var8[15 * 3].v1 = 16.52f;
   var8[15 * 3].v2 = -787.0f;
   var8[16 * 3].v0 = -2083.09f;
   var8[16 * 3].v1 = 2.46f;
   var8[16 * 3].v2 = -381.07f;
   var8[17 * 3].v0 = 224.97f;
   var8[17 * 3].v1 = -20.61f;
   var8[17 * 3].v2 = 612.63f;
   var8[18 * 3].v0 = -503.45f;
   var8[18 * 3].v1 = -8.29f;
   var8[18 * 3].v2 = 145.34f;
   var8[19 * 3].v0 = -257.91f;
   var8[19 * 3].v1 = 31.54f;
   var8[19 * 3].v2 = -778.71f;
   var8[20 * 3].v0 = -3197.5f;
   var8[20 * 3].v1 = -19.76f;
   var8[20 * 3].v2 = 562.59f;
   var8[21 * 3].v0 = -2930.1f;
   var8[21 * 3].v1 = -8.64f;
   var8[21 * 3].v2 = 610.0f;
   var8[22 * 3].v0 = -2971.15f;
   var8[22 * 3].v1 = -25.86f;
   var8[22 * 3].v2 = -411.74f;
   var8[23 * 3].v0 = -2669.27f;
   var8[23 * 3].v1 = -25.81f;
   var8[23 * 3].v2 = -922.25f;
   var8[24 * 3].v0 = -2624.73f;
   var8[24 * 3].v1 = -19.71f;
   var8[24 * 3].v2 = -1093.39f;
   var8[25 * 3].v0 = -2200.68f;
   var8[25 * 3].v1 = 4.16f;
   var8[25 * 3].v2 = -662.93f;
   var8[26 * 3].v0 = -2951.74f;
   var8[26 * 3].v1 = -3.38f;
   var8[26 * 3].v2 = -273.47f;
   var8[27 * 3].v0 = -2609.16f;
   var8[27 * 3].v1 = -3.45f;
   var8[27 * 3].v2 = 273.97f;
   var8[28 * 3].v0 = -2126.11f;
   var8[28 * 3].v1 = 0.1f;
   var8[28 * 3].v2 = 320.73f;
   var8[29 * 3].v0 = -2949.34f;
   var8[29 * 3].v1 = -29.23f;
   var8[29 * 3].v2 = 1072.44f;
   var8[30 * 3].v0 = -2550.1f;
   var8[30 * 3].v1 = -10.67f;
   var8[30 * 3].v2 = 806.2f;
   var8[31 * 3].v0 = -2296.64f;
   var8[31 * 3].v1 = -4.36f;
   var8[31 * 3].v2 = 316.01f;
   var8[32 * 3].v0 = -2120.52f;
   var8[32 * 3].v1 = 10.92f;
   var8[32 * 3].v2 = -1216.81f;
   var8[33 * 3].v0 = -2496.71f;
   var8[33 * 3].v1 = 0.68f;
   var8[33 * 3].v2 = -476.8f;
   var8[34 * 3].v0 = -2644.81f;
   var8[34 * 3].v1 = -4.2f;
   var8[34 * 3].v2 = 673.13f;
   var8[35 * 3].v0 = 2638.5f;
   var8[35 * 3].v1 = -15.8f;
   var8[35 * 3].v2 = -631.5f;
   var8[36 * 3].v0 = 2327.95f;
   var8[36 * 3].v1 = -15.56f;
   var8[36 * 3].v2 = 345.34f;
   var8[37 * 3].v0 = 2045.9f;
   var8[37 * 3].v1 = -20.0f;
   var8[37 * 3].v2 = 1051.1f;
   var8[38 * 3].v0 = 1183.38f;
   var8[38 * 3].v1 = -8.21f;
   var8[38 * 3].v2 = 719.95f;
   var8[39 * 3].v0 = 1460.3f;
   var8[39 * 3].v1 = -5.6f;
   var8[39 * 3].v2 = 1021.3f;
   var8[40 * 3].v0 = 1408.36f;
   var8[40 * 3].v1 = -3.16f;
   var8[40 * 3].v2 = 10.69f;
   var8[41 * 3].v0 = 1622.39f;
   var8[41 * 3].v1 = 3.51f;
   var8[41 * 3].v2 = -526.63f;
   var8[42 * 3].v0 = 1817.88f;
   var8[42 * 3].v1 = -0.02f;
   var8[42 * 3].v2 = -674.9f;
   var8[43 * 3].v0 = 1758.86f;
   var8[43 * 3].v1 = 4.05f;
   var8[43 * 3].v2 = -907.04f;
   var8[44 * 3].v0 = 2122.52f;
   var8[44 * 3].v1 = 3.97f;
   var8[44 * 3].v2 = -220.08f;
   var8[45 * 3].v0 = 2353.5f;
   var8[45 * 3].v1 = -10.0f;
   var8[45 * 3].v2 = 92.2f;
   var8[46 * 3].v0 = 2522.18f;
   var8[46 * 3].v1 = -10.09f;
   var8[46 * 3].v2 = -122.02f;
   var8[47 * 3].v0 = 1849.67f;
   var8[47 * 3].v1 = -3.5f;
   var8[47 * 3].v2 = 252.25f;
   var8[48 * 3].v0 = 2191.49f;
   var8[48 * 3].v1 = 4.01f;
   var8[48 * 3].v2 = -57.03f;
   var8[49 * 3].v0 = 2004.04f;
   var8[49 * 3].v1 = 6.5f;
   var8[49 * 3].v2 = -1180.63f;
   var8[50 * 3].v0 = -598.06f;
   var8[50 * 3].v1 = 30.76f;
   var8[50 * 3].v2 = -1902.41f;
   var8[51 * 3].v0 = -1887.59f;
   var8[51 * 3].v1 = 20.54f;
   var8[51 * 3].v2 = -2074.37f;
   var8[52 * 3].v0 = -1707.23f;
   var8[52 * 3].v1 = 69.9f;
   var8[52 * 3].v2 = -1561.8f;
   var8[53 * 3].v0 = -1081.42f;
   var8[53 * 3].v1 = 69.69f;
   var8[53 * 3].v2 = -1636.98f;
   var8[54 * 3].v0 = -989.55f;
   var8[54 * 3].v1 = 64.11f;
   var8[54 * 3].v2 = -1446.82f;
   var8[55 * 3].v0 = -572.63f;
   var8[55 * 3].v1 = 84.1f;
   var8[55 * 3].v2 = -1324.42f;
   var8[56 * 3].v0 = 432.89f;
   var8[56 * 3].v1 = 99.77f;
   var8[56 * 3].v2 = -1655.29f;
   var8[57 * 3].v0 = 82.9f;
   var8[57 * 3].v1 = 28.74f;
   var8[57 * 3].v2 = -1933.15f;
   var8[58 * 3].v0 = -645.74f;
   var8[58 * 3].v1 = 37.67f;
   var8[58 * 3].v2 = -1814.02f;
   var8[59 * 3].v0 = 455.71f;
   var8[59 * 3].v1 = 23.15f;
   var8[59 * 3].v2 = -2268.27f;
   var189 = 0;
   while (var189 < 60)
   {
       (*var1)[var189] = LocalOptions_IsCollected(var189);
       if ((*var1)[var189] == 0)
       {
           (*var0)[var189] = PropManager_AddRaceProp(var4, &(var8[var189 * 3]), &var5, "city/la/props", "l_prop_barrel_01x");
       }
       var189 = var189 + 1;
   }
   PRINTSTRING(" I AM FREE\n");
   return var4;
}

void sub_87f(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = 0;
   while (var5 < 60)
   {
       if ((*var2)[var5] == 0)
       {
           PropManager_RemoveRaceProp(var0, (*var1)[var5]);
       }
       var5 = var5 + 1;
   }
   PropManager_ShutdownRaceProps(var0);
}

