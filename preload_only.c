void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52;

   var2.v0 = L[0].v0;
   var3 = "CSCamera";
   var4 = 20;
   var25 = 20;
   var46 = 0;
   while (var46 < L[0].v4)
   {
       var47 = L[0].v5[var46 * 6].v5;
       if ((var47 < 0) || (!CineScript_Characters_GetSlotToUseUnscaledCharacter(var46)))
       {
           PRINTSTRING("Remapping the character ");
           PRINTSTRING(L[0].v5[var46 * 6].v1);
           var48 = 0;
           var4[var46] = CineScript_Characters_LookupDriverToCutscenePath(L[0].v5[var46 * 6].v1, var48);
           var25[var46] = CineScript_Characters_LookupDriverToCutsceneName(L[0].v5[var46 * 6].v1, var48);
           PRINTSTRING("to ");
           PRINTSTRING(var25[var46]);
           PRINTSTRING(var4[var46]);
           PRINTSTRING("\n");
       }
       else
       {
           PRINTSTRING("NOT remapping character\n");
       }
       if (StringCompare(var4[var46], "") || StringCompare(var25[var46], ""))
       {
           var4[var46] = L[0].v5[var46 * 6].v0;
           var25[var46] = L[0].v5[var46 * 6].v1;
       }
       var46 = var46 + 1;
   }
   var49 = 1;
   var50 = 0;
   var51 = CineScript_DoesCutsceneAnimPackExist();
   if (var51)
   {
       CineScript_StartLoadCutsceneAnimPack();
   }
   else
   {
       var46 = 0;
       while (var46 < L[0].v4)
       {
           var50 = CineScript_Characters_LoadAnimationWithFace(L[0].v5[var46 * 6].v2, L[0].v5[var46 * 6].v3, L[0].v5[var46 * 6].v4);
           var49 = var49 && var50;
           if (!var50)
           {
               PRINTSTRING("Trying to load ");
               PRINTSTRING(L[0].v5[var46 * 6].v3);
               PRINTSTRING("\n");
           }
           var46 = var46 + 1;
       }
       var46 = 0;
       while (var46 < L[0].v126)
       {
           if (L[0].v127[var46 * 5].v2 && (!L[0].v322))
           {
               var50 = CineScript_Cars_LoadMoverAnimation(L[0].v127[var46 * 5].v3, L[0].v127[var46 * 5].v4);
               var49 = var49 && var50;
           }
           if (!var50)
           {
               PRINTSTRING("Trying to load ");
               PRINTSTRING(L[0].v127[var46 * 5].v4);
               PRINTSTRING("\n");
           }
           var46 = var46 + 1;
       }
       var49 = var49 && CineScript_Camera_LoadAnimation(L[0].v1, var3);
   }
   var52 = 0;
   while ((!var52) && var49)
   {
       var52 = 1;
       if (var51)
       {
           var50 = CineScript_IsLoadedCutsceneAnimPack();
           var52 = var52 && var50;
           if (!var50)
           {
               PRINTSTRING("Trying to load Cutscene animpack ");
               PRINTSTRING("\n");
           }
       }
       var46 = 0;
       while (var46 < L[0].v4)
       {
           var50 = CineScript_Characters_LoadType(var4[var46], var25[var46]);
           var52 = var52 && var50;
           if (!var50)
           {
               PRINTSTRING("Trying to load ");
               PRINTSTRING(var25[var46]);
               PRINTSTRING("\n");
           }
           var46 = var46 + 1;
       }
       if (!StringCompare(L[0].v3, ""))
       {
           var50 = CineScript_Prop_LoadSetDressing(L[0].v3, 1);
           var52 = var52 && var50;
           if (!var50)
           {
               PRINTSTRING("CineScript_Prop_LoadSetDressing() is not done\n");
           }
       }
       if (CineScript_Prop_IsSetDressingLoading(L[0].v3))
       {
           PRINTSTRING("CineScript_Prop_IsSetDressingLoading is true\n");
           var52 = 0;
       }
       if (!var52)
       {
           WAITUNWARPED(10);
       }
   }
}

