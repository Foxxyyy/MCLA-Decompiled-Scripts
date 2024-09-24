void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51;

   var2.v1.v30 = 3;
   var2.v1.v30.v34 = 3;
   var2.v1.v30.v34.v44 = 3;
   var2.v1.v1 = 512;
   var2.v1.v0 = mcCareer_GetLocationId(var2.v1.v1);
   var2.v1.v26 = "be_garage_state";
   var2.v1.v2 = UILogic_FindMapElementByUID(var2.v1.v1);
   mcHudMapElement_GetPosition(var2.v1.v2, &(var2.v1.v3));
   mcHudMapServer_AddElement(var2.v1.v2);
   var2.v1.v23.v0 = -3079.0f;
   var2.v1.v23.v1 = -24.8f;
   var2.v1.v23.v2 = 159.1f;
   var2.v1.v6.v0 = -3059.591f;
   var2.v1.v6.v1 = -16.802f;
   var2.v1.v6.v2 = 166.12f;
   var2.v1.v9.v0 = -3059.659f;
   var2.v1.v9.v1 = -14.206f;
   var2.v1.v9.v2 = 166.116f;
   var2.v1.v12.v0 = -3070.43f;
   var2.v1.v12.v1 = -17.059f;
   var2.v1.v12.v2 = 182.095f;
   var2.v1.v15.v0 = -3102.23f;
   var2.v1.v15.v1 = -24.74f;
   var2.v1.v15.v2 = 188.62f;
   var2.v1.v18 = (float)41;
   var2.v1.v19.v0 = -3045.2f;
   var2.v1.v19.v1 = -24.9f;
   var2.v1.v19.v2 = 161.0f;
   var2.v1.v22 = 211.5f;
   var2.v1.v27 = "BE_GARAGE_ENTER";
   var2.v1.v28 = "BE_GARAGE_EXIT";
   var2.v1.v29 = 0;
   var2.v1.v30[0] = "vp_lam_gallardo_06";
   var2.v1.v30[1] = "vp_nsn_350Z_06";
   var2.v1.v30[2] = "vp_cry_300c_06";
   var2.v1.v34[0 * 3].v0 = -3084.964f;
   var2.v1.v34[0 * 3].v1 = -24.74f;
   var2.v1.v34[0 * 3].v2 = 195.427f;
   var2.v1.v34[1 * 3].v0 = -3087.082f;
   var2.v1.v34[1 * 3].v1 = -23.597f;
   var2.v1.v34[1 * 3].v2 = 177.568f;
   var2.v1.v34[2 * 3].v0 = -3107.945f;
   var2.v1.v34[2 * 3].v1 = -24.655f;
   var2.v1.v34[2 * 3].v2 = 177.604f;
   var2.v1.v44[0] = 0.0f;
   var2.v1.v44[1] = 180.0f;
   var2.v1.v44[2] = 0.0f;
   var51 = START_NEW_SCRIPT_WITH_ARGS("Game/Garages/garage_core", &var2, 49, 0);
   while (!IsChildFinished(var51))
   {
       WAITUNWARPED(10);
   }
   mcHudMapServer_RemoveElement(var2.v1.v2);
   mcHudMapServer_DeleteElement(var2.v1.v2);
}

