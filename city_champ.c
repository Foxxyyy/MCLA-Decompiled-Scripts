void main()
{
   auto var2;

   var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/CITY_CHAMP_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(3, "SH_01", 0, 1, "SH_01_3_vp_mbz_s600_07", 2, 0, "Game/Career/Story/CITY_CHAMP_CORE");
   }
}

