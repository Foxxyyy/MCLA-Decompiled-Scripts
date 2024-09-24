void main()
{
   auto var2;

   var2 = mcSlotSystem_RequestSlot(3, "SH_02", 0, 1, "SH_02_3_vp_lam_miura_71", 2, 0, "Game/Career/Story/FIND_SH_02C_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_02", 0, 1, "SH_02_3_vp_lam_miura_71", 2, 0, "Game/Career/Story/FIND_SH_02C_CORE");
   }
}

