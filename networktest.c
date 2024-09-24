void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28;

   var2 = 0;
   while (var2 < 1000000)
   {
       PRINTSTRING("NetworkTest Script: testcount = ");
       PRINTINT(var2);
       PRINTSTRING("\n");
       WAITUNWARPED(1000);
       var3 = Player_FindRacerObject(0);
       var4 = Racer_GetCarConfig(var3);
       var5 = 7;
       PRINTSTRING("NetworkTest Script: Loading remote players.\n");
       var27 = 0;
       while (var27 < 7)
       {
           Racer_GetPosition(var3, &(var5[var27 * 3]));
           LayerPlayer_LoadRemotePlayer(var27 + 1, var4, &(var5[var27 * 3]), 90.0f, 0, 0);
           PRINTSTRING("NetworkTest Script: Remote player ");
           PRINTINT(var27 + 1);
           PRINTSTRING(" loading.\n");
           WAITUNWARPED(1000);
           var27 = var27 + 1;
       }
       PRINTSTRING("NetworkTest Script: Killing remote players.\n");
       var27 = 0;
       while (var27 < 64)
       {
           var28 = Racer_FindObject(var27);
           if (var28 != null)
           {
               if (Racer_IsPlayer(var28) && (!Racer_IsLocalPlayer(var28)))
               {
                   Racer_EvictCar(var28);
                   PRINTSTRING("NetworkTest Script: Remote racer ");
                   PRINTINT(var27);
                   PRINTSTRING(" being evicted.\n");
               }
           }
           var27 = var27 + 1;
       }
       WAITUNWARPED(1000);
       var27 = 0;
       while (var27 < 7)
       {
           LayerPlayer_KillPlayer(var27 + 1);
           PRINTSTRING("NetworkTest Script: Remote player ");
           PRINTINT(var27 + 1);
           PRINTSTRING(" killed.\n");
           var27 = var27 + 1;
       }
       WAITUNWARPED(1000);
       PRINTSTRING("NetworkTest Script: Remote players killed.\n");
       var2 = var2 + 1;
   }
}

