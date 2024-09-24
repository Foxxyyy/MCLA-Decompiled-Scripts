void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   AudioManager_TransitionIntoGarage();
   var2 = sub_11(0);
   sub_56(var2, 0);
   var3.v0 = -3102.23f;
   var3.v1 = -24.74f;
   var3.v2 = 188.0f;
   var6 = (float)41;
   var7.v0 = (float)0;
   var7.v1 = (float)1;
   var7.v2 = (float)0;
   var10.v0 = (float)0;
   var10.v1 = (float)0;
   var10.v2 = (float)-1;
   Math_VecRotateY(&var10, &var10, var6);
   var10.v0 = var3.v0 + var10.v0;
   var10.v1 = var3.v1 + var10.v1;
   var10.v2 = var3.v2 + var10.v2;
   var7.v0 = var3.v0 + var7.v0;
   var7.v1 = var3.v1 + var7.v1;
   var7.v2 = var3.v2 + var7.v2;
   UILogic_LockStreaming(&var3, &var7, &var10);
   Racer_InitializeResetPosition(var2, &var3, var6);
   var13.v2.v0.v0 = 0.0f;
   var13.v2.v0.v1 = 0.0f;
   var13.v2.v0.v2 = 0.0f;
   var13.v2.v3 = 0.0f;
   CineScript_SetGameCoordSysBinding(&var13);
   CineScript_Prop_LoadSetDressing("cut_la_be_smb_garage_set_items", 0);
   var19 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/cut_la_be_smb_garage_01x_ent_generated", &null, 0, 1500);
   while (!IsChildFinished(var19))
   {
       WAITUNWARPED(10);
   }
   PrestreamManager_UnlockAll();
   Registry_SetValueInt("ratemyride_state", 5);
}

function sub_11(var0)
{
   auto var3, var4;

   var3 = Player_FindRacerObject(var0);
   while (var3 == null)
   {
       var3 = Player_FindRacerObject(var0);
       WAITUNWARPED(10);
   }
   return var3;
}

void sub_56(var0, var1)
{
   auto var4, var5, var6;

   var4 = Racer_GetUID(var0);
   if (var4 == 0)
   {
       var4 = 5000 + var1;
       while (Racer_FindFromUID(var4) != null)
       {
           var4 = var4 + 1;
           WAITUNWARPED(10);
       }
       Racer_SetUID(var0, var4);
   }
   CineScript_Cars_AssignIdToSlot(var4, var1);
}

