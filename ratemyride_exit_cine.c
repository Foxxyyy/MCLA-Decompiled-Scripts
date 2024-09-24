void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13;

   var2.v2.v0.v0 = 0.0f;
   var2.v2.v0.v1 = 0.0f;
   var2.v2.v0.v2 = 0.0f;
   var2.v2.v3 = 0.0f;
   CineScript_SetGameCoordSysBinding(&var2);
   var8 = sub_33(0);
   sub_7a(var8, 0);
   var9.v0 = -3045.2f;
   var9.v1 = -24.9f;
   var9.v2 = 161.0f;
   var12 = 211.5f;
   Racer_InitializeResetPosition(var8, &var9, var12);
   var13 = START_NEW_SCRIPT_WITH_ARGS("Game/cinescripts/generated/cut_la_be_smb_garage_01x_ext_generated", &null, 0, 1500);
   while (!IsChildFinished(var13))
   {
       WAITUNWARPED(10);
   }
   CineScript_Prop_UnloadSetDressing("cut_la_be_smb_garage_set_items");
   Registry_SetValueInt("ratemyride_state", 2);
}

function sub_33(var0)
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

void sub_7a(var0, var1)
{
   auto var4, var5, var6, var7;

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
   var5 = Racer_GetVehicleDriverName(var0);
   CineScript_Characters_AssignNameToSlot(var5, var1);
}

