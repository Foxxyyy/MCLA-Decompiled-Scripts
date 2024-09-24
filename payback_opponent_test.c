void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44;

   L[0] = "drv_mp_01_set";
   L[1] = "drv_mp_01_lod02_set";
   L[2] = "drv_ma_03_set";
   L[3] = "drv_ma_02_set";
   L[4] = "drv_ma_001_set";
   L[5] = "drv_fa_001_set";
   L[6] = "drv_mb_02_set";
   L[7] = "drv_mb_03_set";
   L[8] = "drv_mb_04_set";
   L[9] = "drv_mb_05_set";
   L[10] = "drv_mb_007_set";
   L[11] = "drv_mb_008_set";
   L[12] = "drv_mb_010_set";
   L[13] = "drv_mb_001_set";
   L[14] = "drv_mb_009_set";
   L[15] = "drv_mb_06_set";
   L[16] = "drv_fb_01_set";
   L[17] = "drv_mc_02_set";
   L[18] = "drv_mc_06_set";
   L[19] = "drv_mc_07_set";
   L[20] = "drv_mc_003_set";
   L[21] = "drv_mc_05_set";
   L[22] = "drv_mc_001_set";
   L[23] = "drv_fc_002_set";
   L[24] = "drv_mh_01_set";
   L[25] = "drv_mh_02_set";
   L[26] = "drv_mh_003_set";
   L[27] = "drv_mh_005_set";
   L[28] = "drv_mh_04_set";
   L[29] = "drv_mh_006_set";
   L[30] = "drv_fh_001_set";
   L[31] = "mec_mc_01_set";
   L[32] = "ped_ma_001_set";
   L[33] = "ped_mb_001_set";
   L[34] = "ped_mc_001_set";
   L[35] = "ped_mh_001_set";
   L[36] = "pol_mc_01_set";
   var2 = 3;
   var6 = 3;
   var10 = 3;
   var20 = 3;
   var24 = 3;
   var34 = 3;
   var2[0] = "pyback_gn_vp_dge_challenger_70";
   var6[0] = L[14];
   var10[0 * 3].v0 = 434.1f;
   var10[0 * 3].v1 = 24.2f;
   var10[0 * 3].v2 = -887.4f;
   var20[0] = (float)180;
   var24[0 * 3].v0 = -470.0f;
   var24[0 * 3].v1 = 9.5f;
   var24[0 * 3].v2 = -390.0f;
   var34[0] = 450;
   var2[1] = "pyback_gn_vp_dge_charger_06";
   var6[1] = L[13];
   var10[1 * 3].v0 = 116.1f;
   var10[1 * 3].v1 = 23.6f;
   var10[1 * 3].v2 = -885.2f;
   var20[1] = 0.0f;
   var24[1 * 3].v0 = -490.0f;
   var24[1 * 3].v1 = 9.5f;
   var24[1 * 3].v2 = -390.0f;
   var34[1] = 451;
   var2[2] = "pyback_gn_vp_pon_transam_79";
   var6[2] = L[7];
   var10[2 * 3].v0 = 551.7f;
   var10[2 * 3].v1 = 23.3f;
   var10[2 * 3].v2 = -869.3f;
   var20[2] = 0.0f;
   var24[2 * 3].v0 = -520.0f;
   var24[2 * 3].v1 = 9.5f;
   var24[2 * 3].v2 = -390.0f;
   var34[2] = 452;
   var38 = 3;
   var43 = null;
   var42 = 0;
   while (var42 < 3)
   {
       var38[var42] = PoliceManager_CreatePolice(var2[var42], 0, &(var10[var42 * 3]), var20[var42], &(var24[var42 * 3]), 400 + var42);
       var43 = PoliceManager_GetRacer(var38[var42]);
       Racer_SetIconType(var43, 13);
       Racer_SetCharacterName(var43, var6[var42]);
       Racer_SetUIDAndCharacterName(var43, var34[var42], var6[var42]);
       Racer_HideIcon(var43, 0);
       var42 = var42 + 1;
   }
   PoliceManager_SetAllPoliceUnderground(1, 0);
   var44 = 0;
   Registry_SetValueInt("Shutdown_PaybackOpponents", var44);
   while (var44 == 0)
   {
       Registry_GetValueInt("Shutdown_PaybackOpponents", &var44);
       WAITUNWARPED(100);
   }
   PRINTSTRING("Payback opponent shutdown\n");
   var42 = 0;
   while (var42 < 3)
   {
       PoliceManager_DestroyPolice(var38[var42]);
       var42 = var42 + 1;
   }
}

