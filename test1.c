void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11;

   var2 = 1;
   var2[0 * 3].v0 = -250.786f;
   var2[0 * 3].v1 = -2.4574f;
   var2[0 * 3].v2 = -82.0039f;
   var6 = 1;
   var6[0] = "PickUp_or_DropOff";
   var8 = 1;
   var8[0] = 0;
   var10 = 0;
   var11 = Ctf_GetMap(L[0].v801);
   CtfMap_Init(var11, 1, 1);
   var10 = 0;
   while (var10 < 1)
   {
       CtfMap_AddItem(var11, var6[var10], &(var2[var10 * 3]), var8[var10]);
       var10 = var10 + 1;
   }
   sub_ab(&L[0]);
}

void sub_ab(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17;

   var8.v0 = (float)0;
   var8.v1 = (float)1;
   var8.v2 = (float)0;
   var11.v0 = (float)0;
   var11.v1 = (float)0;
   var11.v2 = (float)-1;
   RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), 0, &var4, &var7);
   Math_VecRotateY(&var11, &var11, var7);
   var11.v0 = var4.v0 + var11.v0;
   var11.v1 = var4.v1 + var11.v1;
   var11.v2 = var4.v2 + var11.v2;
   var8.v0 = var4.v0 + var8.v0;
   var8.v1 = var4.v1 + var8.v1;
   var8.v2 = var4.v2 + var8.v2;
   UILogic_LockStreaming(&var4, &var8, &var11);
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       Racer_SetStreamingLockedIn((*((var0 + 16) + 4))[var3 * 48].v0);
       var3 = var3 + 1;
   }
   var14 = 1;
   var15 = 0;
   while (var14 > 0)
   {
       var14 = *((var0 + 16) + 3080);
       var3 = 0;
       while (var3 < *((var0 + 16) + 3080))
       {
           if (Racer_IsSimStreamed((*((var0 + 16) + 4))[var3 * 48].v0))
           {
               var14 = var14 - 1;
           }
           var3 = var3 + 1;
       }
       if (var14 > 0)
       {
           if ((!var15) && (!*((var0 + 16) + 3132)))
           {
               sub_1cb(1, 0, 0x3f800000, 0);
               var15 = 1;
           }
           WAIT(100);
       }
   }
   while (OpponentManager_StillStreamingOut())
   {
       WAIT(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           PRINTSTRING(" BRAIN CREATED!");
           (*((var0 + 16) + 4))[var3 * 48].v3 = BrainFactory_CreateBrainRacing((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
   var16 = START_NEW_SCRIPT_WITH_ARGS("game/racetypes/BaseWarCore", var0, 802, 1500);
   while (!IsChildFinished(var16))
   {
       WAIT(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           BrainFactory_DeleteBrain((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
}

void sub_1cb(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           PRINTSTRING("SCRIPT: waiting for transition movie to stream in...\n");
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE DOWN REPORT\n");
   PRINTSTRING("================\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var8 == 0) && ((var9 == 0) || ((var7 == 1) && (var9 == 2))))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", var2);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", 0.01f);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 0);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 1);
       if (var0)
       {
           var8 = 1;
           while (var8 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
               if (var8 == 1)
               {
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

