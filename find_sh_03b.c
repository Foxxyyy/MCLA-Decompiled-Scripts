void main()
{
   auto var2;

   var2 = mcSlotSystem_RequestSlot(1, "SH_03", 0, 1, "SH_03_1_vp_pon_solstice_06", 2, 0, "Game/Career/Story/FIND_SH_03B_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(1, "SH_03", 0, 1, "SH_03_1_vp_pon_solstice_06", 2, 0, "Game/Career/Story/FIND_SH_03B_CORE");
   }
   mcSlotSystem_HideDistrict(1, 0);
   mcSlotSystem_UnlockDistrict(1, 1);
}

