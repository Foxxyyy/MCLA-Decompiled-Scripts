void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51;

   var2.v1.v30 = 3;
   var2.v1.v30.v34 = 3;
   var2.v1.v30.v34.v44 = 3;
   var2.v1.v1 = 543;
   var2.v1.v0 = mcCareer_GetLocationId(var2.v1.v1);
   var2.v1.v26 = "sc_garage_state";
   var2.v1.v2 = UILogic_FindMapElementByUID(var2.v1.v1);
   mcHudMapElement_GetPosition(var2.v1.v2, &(var2.v1.v3));
   mcHudMapServer_AddElement(var2.v1.v2);
   var2.v1.v23.v0 = -53.6f;
   var2.v1.v23.v1 = -19.6f;
   var2.v1.v23.v2 = 1331.6f;
   var2.v1.v6.v0 = -54.75f;
   var2.v1.v6.v1 = -15.488f;
   var2.v1.v6.v2 = 1315.646f;
   var2.v1.v9.v0 = -54.808f;
   var2.v1.v9.v1 = -12.893f;
   var2.v1.v9.v2 = 1315.64f;
   var2.v1.v12.v0 = -54.368f;
   var2.v1.v12.v1 = -15.433f;
   var2.v1.v12.v2 = 1336.608f;
   var2.v1.v15.v0 = 861.773f;
   var2.v1.v15.v1 = 17.061f;
   var2.v1.v15.v2 = -809.745f;
   var2.v1.v18 = (float)41;
   var2.v1.v19.v0 = -52.1f;
   var2.v1.v19.v1 = -19.8f;
   var2.v1.v19.v2 = 1299.2f;
   var2.v1.v22 = 43.0f;
   var2.v1.v27 = "SC_GARAGE_ENTER";
   var2.v1.v28 = "SC_GARAGE_EXIT";
   var2.v1.v29 = 0;
   var2.v1.v30[0] = "vp_frd_focus_04";
   var2.v1.v30[1] = "vp_nsn_240sx_98";
   var2.v1.v30[2] = "vp_chv_cobalt_05";
   var2.v1.v34[0 * 3].v0 = 879.696f;
   var2.v1.v34[0 * 3].v1 = 17.037f;
   var2.v1.v34[0 * 3].v2 = -817.192f;
   var2.v1.v34[1 * 3].v0 = 878.772f;
   var2.v1.v34[1 * 3].v1 = 17.176f;
   var2.v1.v34[1 * 3].v2 = -810.215f;
   var2.v1.v34[2 * 3].v0 = 875.242f;
   var2.v1.v34[2 * 3].v1 = 19.227f;
   var2.v1.v34[2 * 3].v2 = -803.332f;
   var2.v1.v44[0] = 40.0f;
   var2.v1.v44[1] = 60.0f;
   var2.v1.v44[2] = -120.0f;
   var51 = START_NEW_SCRIPT_WITH_ARGS("Game/Garages/garage_core", &var2, 49, 0);
   while (!IsChildFinished(var51))
   {
       WAITUNWARPED(10);
   }
   mcHudMapServer_RemoveElement(var2.v1.v2);
   mcHudMapServer_DeleteElement(var2.v1.v2);
}

