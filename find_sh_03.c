void main()
{
   auto var2;

   var2 = mcSlotSystem_RequestSlot(0, "SH_03", 0, 1, "SH_03_2_vp_cry_300c_06", 2, 0, "Game/Career/Story/FIND_SH_03_CORE");
   while (var2 == null)
   {
       WAITUNWARPED(1000);
       var2 = mcSlotSystem_RequestSlot(0, "SH_03", 0, 1, "SH_03_2_vp_cry_300c_06", 2, 0, "Game/Career/Story/FIND_SH_03_CORE");
   }
}

