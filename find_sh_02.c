void main()
{
   auto var2;

   var2 = mcSlotSystem_RequestSlot(1, "SH_02", 0, 1, "SH_02_2_vp_dge_challenger_06", 2, 0, "Game/Career/Story/FIND_SH_02_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "SH_02", 0, 1, "SH_02_2_vp_dge_challenger_06", 2, 0, "Game/Career/Story/FIND_SH_02_CORE");
   }
}

