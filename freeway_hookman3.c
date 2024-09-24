void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143;

   var2 = 9;
   var12 = 9;
   var12[0 * 3].v0 = 1413.92f;
   var12[0 * 3].v1 = 5.58993f;
   var12[0 * 3].v2 = 1092.63f;
   var2[0] = "GREETING_FREEWAY_GRAND";
   var12[1 * 3].v0 = 1742.78f;
   var12[1 * 3].v1 = 5.62099f;
   var12[1 * 3].v2 = 1097.15f;
   var2[1] = "GREETING_FREEWAY_10";
   var12[2 * 3].v0 = 2720.45f;
   var12[2 * 3].v1 = -2.7048f;
   var12[2 * 3].v2 = -122.27f;
   var2[2] = "GREETING_FREEWAY_2NDSTREET";
   var12[3 * 3].v0 = 2465.93f;
   var12[3 * 3].v1 = -3.49863f;
   var12[3 * 3].v2 = -1077.43f;
   var2[3] = "GREETING_FREEWAY_HOPE";
   var12[4 * 3].v0 = 1595.07f;
   var12[4 * 3].v1 = 2.00746f;
   var12[4 * 3].v2 = -1094.64f;
   var2[4] = "GREETING_FREEWAY_110";
   var12[5 * 3].v0 = 1507.83f;
   var12[5 * 3].v1 = -0.458572f;
   var12[5 * 3].v2 = -749.74f;
   var2[5] = "GREETING_FREEWAY_4TH";
   var12[6 * 3].v0 = 1194.57f;
   var12[6 * 3].v1 = -7.79114f;
   var12[6 * 3].v2 = -94.3399f;
   var2[6] = "GREETING_FREEWAY_WILSHIRE";
   var12[7 * 3].v0 = 1075.76f;
   var12[7 * 3].v1 = -0.949989f;
   var12[7 * 3].v2 = 482.54f;
   var2[7] = "GREETING_FREEWAY_110";
   var12[8 * 3].v0 = 1050.82f;
   var12[8 * 3].v1 = 0.052849f;
   var12[8 * 3].v2 = 964.086f;
   var2[8] = "GREETING_FREEWAY_110";
   var40.v0 = 31;
   var40.v95 = 90.0f;
   var40.v96 = 30.0f;
   var40.v100 = 0;
   var40.v97.v0 = mcCareer_FindAvailableHookman();
   mcHookman_SetId(var40.v97.v0, 302);
   mcHookman_SetType(var40.v97.v0, 5);
   mcHookman_SetName(var40.v97.v0, "GH_09");
   mcHookman_SetDifficulty(var40.v97.v0, RAND_INT_RANGE(0, 3));
   var40.v94 = 9;
   var143 = 0;
   while (var143 < var40.v94)
   {
       var40.v0[var143 * 3].v0 = var12[var143 * 3].v0;
       var40.v0[var143 * 3].v1 = var12[var143 * 3].v1;
       var40.v0[var143 * 3].v2 = var12[var143 * 3].v2;
       var143 = var143 + 1;
   }
   sub_2df(&var40, &var2);
}

void sub_2df(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143, var144, var145, var146, var147, var148, var149, var150, var151, var152, var153, var154, var155, var156, var157, var158, var159, var160, var161, var162, var163, var164, var165, var166, var167, var168, var169, var170, var171, var172, var173, var174, var175, var176, var177, var178, var179, var180, var181, var182, var183, var184, var185, var186, var187, var188, var189, var190, var191, var192, var193, var194, var195, var196, var197, var198, var199, var200, var201, var202, var203, var204, var205, var206, var207, var208, var209, var210, var211, var212, var213, var214, var215, var216, var217, var218, var219, var220, var221, var222, var223, var224, var225, var226, var227, var228, var229, var230, var231, var232, var233, var234, var235, var236, var237, var238, var239, var240, var241, var242, var243, var244, var245, var246, var247, var248, var249, var250, var251, var252, var253, var254, var255, var256, var257, var258, var259, var260, var261, var262, var263, var264, var265, var266, var267, var268, var269, var270, var271, var272, var273, var274, var275, var276, var277, var278, var279, var280, var281, var282, var283, var284, var285, var286, var287, var288, var289, var290, var291, var292, var293, var294, var295, var296, var297, var298, var299, var300, var301, var302, var303, var304, var305, var306, var307, var308, var309, var310, var311, var312, var313, var314, var315, var316, var317, var318, var319, var320, var321, var322, var323, var324, var325, var326, var327, var328, var329, var330, var331, var332, var333, var334, var335, var336, var337, var338, var339, var340, var341, var342, var343, var344, var345, var346, var347, var348, var349, var350, var351, var352, var353, var354, var355, var356, var357, var358, var359, var360, var361, var362, var363, var364, var365, var366, var367, var368, var369, var370, var371, var372, var373, var374, var375, var376, var377, var378, var379, var380, var381, var382, var383, var384, var385, var386, var387, var388, var389, var390, var391, var392, var393, var394, var395, var396, var397, var398, var399, var400, var401, var402, var403, var404, var405, var406, var407, var408, var409, var410, var411, var412, var413, var414, var415, var416, var417, var418, var419, var420, var421, var422, var423, var424, var425, var426, var427, var428, var429, var430, var431, var432, var433, var434, var435, var436, var437, var438, var439, var440, var441, var442, var443, var444, var445, var446, var447, var448, var449, var450, var451, var452, var453, var454, var455, var456, var457, var458, var459, var460, var461, var462, var463, var464, var465, var466, var467, var468, var469, var470, var471, var472, var473, var474, var475, var476, var477, var478, var479, var480, var481, var482, var483, var484, var485, var486, var487, var488, var489, var490, var491, var492, var493, var494, var495, var496, var497, var498, var499, var500, var501, var502, var503, var504, var505, var506, var507, var508, var509, var510, var511, var512, var513, var514, var515, var516, var517, var518, var519, var520, var521, var522, var523, var524, var525, var526, var527, var528, var529, var530, var531, var532, var533, var534, var535, var536, var537, var538, var539, var540, var541, var542, var543, var544, var545, var546, var547, var548, var549, var550, var551, var552, var553, var554, var555, var556, var557, var558, var559, var560, var561, var562, var563, var564, var565, var566, var567, var568, var569, var570, var571, var572, var573, var574, var575, var576, var577, var578, var579, var580, var581, var582, var583, var584, var585, var586, var587, var588, var589, var590, var591, var592, var593, var594, var595, var596, var597, var598, var599, var600, var601, var602, var603, var604, var605, var606, var607, var608, var609, var610, var611, var612, var613, var614, var615, var616, var617, var618, var619, var620, var621, var622, var623, var624, var625, var626, var627, var628, var629, var630, var631, var632, var633, var634, var635, var636, var637, var638, var639, var640, var641, var642, var643, var644, var645, var646, var647, var648, var649, var650, var651, var652, var653, var654, var655, var656, var657, var658, var659, var660, var661, var662, var663, var664, var665, var666, var667, var668, var669, var670, var671, var672, var673, var674, var675, var676, var677, var678, var679, var680, var681, var682, var683, var684, var685, var686, var687, var688, var689, var690, var691, var692, var693, var694, var695, var696, var697, var698, var699, var700, var701, var702, var703, var704, var705, var706, var707, var708, var709, var710, var711, var712, var713, var714, var715, var716, var717, var718, var719, var720, var721, var722, var723, var724, var725, var726, var727, var728, var729, var730, var731, var732, var733, var734, var735, var736, var737, var738, var739, var740, var741, var742, var743, var744, var745, var746, var747, var748, var749, var750, var751, var752, var753, var754, var755, var756, var757, var758, var759, var760, var761, var762, var763, var764, var765, var766, var767, var768, var769, var770, var771, var772, var773, var774, var775, var776, var777, var778, var779, var780, var781, var782, var783, var784, var785, var786, var787, var788, var789, var790, var791, var792, var793, var794, var795, var796, var797, var798, var799, var800, var801, var802, var803, var804, var805, var806, var807, var808, var809, var810, var811, var812, var813, var814, var815, var816, var817, var818, var819, var820, var821, var822, var823, var824;

   var4 = sub_2e9(0);
   var5 = mcHookman_GetId(*((var0 + 388) + 0));
   var6 = mcHookman_GetDifficulty(*((var0 + 388) + 0));
   var7 = OpponentManager_FindCharacterConfigData(mcHookman_GetName(*((var0 + 388) + 0)));
   var8 = mcCharacterConfigData_GetCarConfigData(var7, Racer_GetCarConfig(var4), var6, 247, 1);
   var9 = mcCarConfigData_GetRandomConfigData(var8);
   PRINTSTRING("Freeway Hookman - ");
   PRINTINT(var5);
   PRINTSTRING(" - Init Car name - ");
   PRINTSTRING(mcConfigData_GetName(var9));
   PRINTSTRING("\n");
   PRINTSTRING("Freeway Hookman - ");
   PRINTINT(var5);
   PRINTSTRING(" - Init Difficulty - ");
   PRINTINT(var6);
   PRINTSTRING("\n");
   *((var0 + 388) + 4) = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(*((var0 + 388) + 4), mcConfigData_GetName(var9), &((*(var0 + 0))[*(var0 + 376) - 1 * 3]), 0);
   OpponentManager_AddOpponentToWorld(*((var0 + 388) + 4));
   var10 = Opponent_GetRacer(*((var0 + 388) + 4));
   Racer_SetModValue(var10, mcCarConfigData_GetModValue(var8));
   Racer_SetUIDAndCharacterName(var10, var5, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(*((var0 + 388) + 0))));
   mcTargetManager_RegisterRacer(var5, var10);
   *((var0 + 388) + 8) = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(*((var0 + 388) + 8), 5, var10);
   if (GetNoCareerCommandLine())
   {
       mcCareer_SetAltHookmanVisibility(var5, 1);
   }
   var11 = mcCareer_GetAltHookmanVisibility(var5);
   if (var11)
   {
       mcHookman_Hide(*((var0 + 388) + 0), 0);
       mcHudMapServer_AddElement(*((var0 + 388) + 8));
       mcTargetManager_HideTarget(var5, 0);
   }
   else
   {
       mcTargetManager_HideTarget(var5, 1);
   }
   Racer_SetIconType(var10, 8);
   Racer_HideIcon(var10, 0);
   Racer_SetIconColorByDifficulty(var10, var6);
   mcHookman_SetState(*((var0 + 388) + 0), 2);
   *(var0 + 400) = 0;
   *(var0 + 408) = 1;
   while (!Racer_IsCarStreamed(var4))
   {
       WAITUNWARPED(100);
   }
   var12 = Racer_GetCarTypeIndex(var4);
   var13 = var12;
   var14 = 0;
   var17.v4.v1 = 16;
   var17.v4.v1.v1.v9 = 15;
   var17.v4.v1.v1.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var17.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v791 = 3;
   var819 = 0;
   var820 = 0;
   var821 = -1;
   var822 = UIManager_GetState("GPSScene");
   while (!var819)
   {
       var15 = mcHookman_GetState(*((var0 + 388) + 0));
       PRINTSTRING("Freeway Hookman - ");
       PRINTINT(var5);
       PRINTSTRING(" - State - ");
       PRINTINT(var15);
       PRINTSTRING("\n");
       if (var15 == 1)
       {
           while (var15 == 1)
           {
               var15 = mcHookman_GetState(*((var0 + 388) + 0));
               WAITUNWARPED(100);
           }
           PRINTSTRING("Freeway Hookman - ");
           PRINTINT(var5);
           PRINTSTRING(" - State change from RESERVED ");
           PRINTINT(1);
           PRINTSTRING(" to ");
           PRINTINT(var15);
           PRINTSTRING("\n");
       }
       if ((var15 == 4) || IsExitFlagSet())
       {
           PRINTSTRING("Freeway Hookman - ");
           PRINTINT(var5);
           PRINTSTRING(" Shuting down\n");
       }
       else
       {
           var16 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/CruisingHookmanCore", var0, 103, 1500);
           while (!IsChildFinished(var16))
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var821);
               while (var821 == 1)
               {
                   Registry_GetValueInt("Script_SuspendAllOpponents", &var821);
                   if (IsExitFlagSet())
                   {
                   }
                   else
                   {
                       WAITUNWARPED(100);
                       var820 = 1;
                   }
               }
               var13 = Racer_GetCarTypeIndex(var4);
               if (((!(var13 == var12)) && (!(var13 == -1))) || var820)
               {
                   PRINTSTRING("Freeway Hookman - ");
                   PRINTINT(var5);
                   PRINTSTRING(" - Changing vehicles\n");
                   if (GetDemoCommandLine())
                   {
                       var6 = 1;
                   }
                   else
                   {
                       var6 = RAND_INT_RANGE(0, 3);
                   }
                   mcHookman_SetDifficulty(*((var0 + 388) + 0), var6);
                   Racer_SetIconColorByDifficulty(var10, var6);
                   var12 = var13;
                   var8 = mcCharacterConfigData_GetCarConfigData(var7, Racer_GetCarConfig(var4), var6, 247, 1);
                   var9 = mcCarConfigData_GetRandomConfigData(var8);
                   Racer_SetModValue(var10, mcCarConfigData_GetModValue(var8));
                   Racer_ChangeCar(var10, mcConfigData_GetName(var9));
                   PRINTSTRING("Freeway Hookman - ");
                   PRINTINT(var5);
                   PRINTSTRING(" - Change Car name - ");
                   PRINTSTRING(mcConfigData_GetName(var9));
                   PRINTSTRING("\n");
                   PRINTSTRING("Freeway Hookman - ");
                   PRINTINT(var5);
                   PRINTSTRING(" - New Difficulty - ");
                   PRINTINT(var6);
                   PRINTSTRING("\n");
                   var820 = 0;
               }
               WAITUNWARPED(200);
               if ((!mcHookman_IsHidden(*((var0 + 388) + 0))) && (!mcCareer_GetAltHookmanVisibility(var5)))
               {
                   mcCareer_SetAltHookmanVisibility(var5, 1);
               }
           }
           *(var0 + 404) = 1;
           if (IsExitFlagSet())
           {
               PRINTSTRING("Freeway Hookman - ");
               PRINTINT(var5);
               PRINTSTRING(" is shuting down.\n");
           }
           else
           {
               var17.v4.v1[0 * 48].v0 = var4;
               var17.v4.v1[0 * 48].v2 = 0;
               var17.v4.v1[0 * 48].v5 = 1;
               var17.v4.v1[0 * 48].v6 = 0;
               var17.v4.v1[0 * 48].v41 = 0;
               var17.v4.v1[0 * 48].v8 = 0x7fffffff;
               var17.v4.v1[1 * 48].v0 = var10;
               var17.v4.v1[1 * 48].v2 = 2;
               var17.v4.v1[1 * 48].v5 = 1;
               var17.v4.v1[1 * 48].v6 = 0;
               var17.v4.v1[1 * 48].v41 = 0;
               var17.v4.v1[1 * 48].v8 = 0x7fffffff;
               Racer_SetStreamingLockedIn(var10);
               var17.v4.v770 = 2;
               var17.v4.v771 = 0;
               var17.v4.v775 = var6;
               var17.v4.v780 = 0;
               var17.v4.v0 = -1;
               sub_cfd(&var17, var0, var4, var1);
               Racer_SetStreamingUnlocked(var10);
               mcHookman_SetState(*((var0 + 388) + 0), 2);
               sub_2926();
           }
       }
   }
   mcHudMapServer_DeleteElement(*((var0 + 388) + 8));
   mcTargetManager_UnRegisterTarget(var5);
   OpponentManager_DeleteOpponent(*((var0 + 388) + 4));
   mcHookman_SetState(*((var0 + 388) + 0), 0);
   PRINTSTRING("Freeway Hookman - ");
   PRINTINT(var5);
   PRINTSTRING(" deleted.\n");
}

function sub_2e9(var0)
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

void sub_cfd(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79;

   PRINTSTRING("TESTTEST");
   StatsManager_UpdateStatInt("xGAF", 0, 0, 1);
   var6 = 0;
   var7 = 0;
   var8 = UIManager_FindMovie("NAVSYSMOVIE");
   FlashHelper_SetGlobalString(var8, "gps_racename", StringTable_GetString("Freeway"));
   PRINTSTRING("This race will have Taunts..\n");
   var6 = 1;
   var7 = RAND_INT_RANGE(30000, 40000);
   Registry_SetValueInt("raceOverTrigger", 0);
   *(var0 + 12) = Race_Create();
   Race_SetCurrentRace(*(var0 + 12));
   *((var0 + 16) + 3088) = 1;
   *((var0 + 16) + 3092) = 1;
   *((var0 + 16) + 3096) = 5;
   var9 = Opponent_GetRacer(*((var1 + 388) + 4));
   Racer_GetPosition(var9, &var10);
   Racer_InitializeResetPosition(var9, &var10, (float)0);
   Racer_HideIcon(var9, 0);
   Racer_GetPosition(var9, &var10);
   var13 = sub_e50(var10.v0, var10.v1, var10.v2, var1 + 0, *(var1 + 376));
   var14 = var13;
   var15 = var13;
   var16 = RAND_INT_RANGE(4, 6);
   if (var16 >= *(var1 + 376))
   {
       var16 = *(var1 + 376) - 1;
   }
   var17 = Race_GetCheckpointList(*(var0 + 12));
   var18 = CheckpointList_Create();
   CheckpointList_Reset(var17);
   CheckpointList_ResizeList(var17, var16);
   CheckpointList_Reset(var18);
   CheckpointList_ResizeList(var18, var16 + 1);
   PRINTSTRING("Num Race Checkpoints: ");
   PRINTINT(var16);
   var19 = null;
   var20 = 0;
   var20 = 0;
   while (var20 < var16)
   {
       if (var13 == *(var1 + 376))
       {
           var13 = 0;
       }
       var19 = CheckpointList_GetCheckpoint(var17, var20);
       Checkpoint_SetPosition(var19, &((*(var1 + 0))[var13 * 3]));
       var15 = var13;
       var13 = var13 + 1;
       Checkpoint_SetActivationRadius(var19, 30.0f);
       var20 = var20 + 1;
   }
   var21 = 0;
   var21 = 0;
   while (var21 < (var16 + 1))
   {
       if (var14 == *(var1 + 376))
       {
           var14 = 0;
       }
       var19 = CheckpointList_GetCheckpoint(var18, var21);
       Checkpoint_SetPosition(var19, &((*(var1 + 0))[var14 * 3]));
       var14 = var14 + 1;
       Checkpoint_SetActivationRadius(var19, 30.0f);
       var21 = var21 + 1;
   }
   var22 = mcCareerSpeech_FindScenario((*var3)[var15]);
   if (var22 != null)
   {
       PRINTSTRING("Playing speach scenario: ");
       PRINTSTRING((*var3)[var15]);
       mcCareerSpeech_PlayScenario(var22, Racer_GetVehicleDriverName((*((var0 + 16) + 4))[1 * 48].v0), "PLAYER");
   }
   var23 = 16;
   var20 = 0;
   while (var20 < var16)
   {
       var19 = CheckpointList_GetCheckpoint(var17, var20);
       Checkpoint_GetPosition(var19, &var10);
       var23[var20] = mcHudMapServer_CreateElement();
       mcHudMapServer_SetElement(var23[var20], 0, 0, &var10, (float)0);
       mcHudMapServer_SetMutExSubtype(var23[var20], 3);
       mcHudMapServer_AddElement(var23[var20]);
       var20 = var20 + 1;
   }
   mcHudMapServer_SetMutExSubtype(var23[var16 - 1], 5);
   if (var16 > 1)
   {
       mcHudMapServer_SetMutExSubtype(var23[0], 1);
   }
   mcHudMapServer_AddElement(*((var1 + 388) + 8));
   (*((var0 + 16) + 4))[1 * 48].v3 = sub_1217(*((var1 + 388) + 4));
   BrainRacing_SetupRace((*((var0 + 16) + 4))[1 * 48].v3, var18, 0, 1, *((var0 + 16) + 3100));
   CheckpointManager_SetActiveCheckpointList(var17);
   CheckpointManager_ActivateSingleCheckpoint(0, 0, 0);
   CheckpointManager_ActivateSingleCheckpoint(1, 0, 0);
   var19 = CheckpointList_GetCheckpoint(var17, 0);
   Checkpoint_GetPosition(var19, &var10);
   sub_12a3(var0);
   RubberBandMgr_SetupRace(*((var0 + 16) + 3100), 0, 0);
   var40 = UIManager_FindMovie("HUDMOVIE");
   FlashHelper_SetGlobalInt(var40, "PosMax", *((var0 + 16) + 3080));
   strcpy(&var57, 64, "");
   sub_1377(var40);
   Race_SetTimer(*(var0 + 12), 0);
   Race_EnableRaceTimer(*(var0 + 12), 1);
   mcGame_ThrowEvent("freewayRace");
   UILogic_SetGPSDestination(0, &var10);
   var73 = 0;
   var74 = 0;
   while (!Race_IsFinished(*(var0 + 12)))
   {
       Race_SetRaceData(*(var0 + 12), var0 + 16);
       Registry_GetValueInt("raceOverTrigger", &var73);
       if (var73 == 1)
       {
           Registry_GetValueString("raceOverCommand", &var57);
           PRINTSTRING("RACE OEVER: ");
           PRINTSTRING(&var57);
           if (StringCaseCompare(&var57, "quit"))
           {
               mcEvent_PostEventRaceResults("RACE_QUIT", var0 + 16);
           }
           Race_Finish(*(var0 + 12));
           mcCareerSpeech_PlayTauntpostRace(var9, var2, 0);
       }
       var74 = 0;
       while (var74 < *((var0 + 16) + 3080))
       {
           var75 = CheckpointManager_HasHitCheckpoint((*((var0 + 16) + 4))[var74 * 48].v0, var74, (*((var0 + 16) + 4))[var74 * 48].v6);
           if (var75)
           {
               CheckpointManager_DeactivateSingleCheckpoint(var74, (*((var0 + 16) + 4))[var74 * 48].v6);
               if ((*((var0 + 16) + 4))[var74 * 48].v2 == 0)
               {
                   mcHudMapServer_RemoveElement(var23[(*((var0 + 16) + 4))[var74 * 48].v6]);
               }
               (*((var0 + 16) + 4))[var74 * 48].v6 = (*((var0 + 16) + 4))[var74 * 48].v6 + 1;
               if ((*((var0 + 16) + 4))[var74 * 48].v6 >= var16)
               {
                   PRINTSTRING("RACER FINSIHED ");
                   PRINTINT(var74);
                   PRINTSTRING("\n");
                   (*((var0 + 16) + 4))[var74 * 48].v8 = Race_GetTimer(*(var0 + 12));
                   if (var74 == 0)
                   {
                       Race_Finish(*(var0 + 12));
                   }
                   else if (var74 == 1)
                   {
                       StringTable_SetString("PLAYER_FINISHED_NAME", Racer_GetName(var9));
                       SplashManager_Splash(0, 3, "PLAYER_FINISHED", 1.0f, 1, 0);
                       CheckpointManager_SetActiveCheckpointList(var18);
                       CheckpointManager_ActivateSingleCheckpoint(1, (*((var0 + 16) + 4))[1 * 48].v6, 0);
                       CheckpointManager_SetActiveCheckpointList(var17);
                       mcHudMapServer_RemoveElement(*((var1 + 388) + 8));
                       Racer_HideIcon(var9, 1);
                   }
               }
               else if ((*((var0 + 16) + 4))[var74 * 48].v6 >= (var16 - 1))
               {
                   CheckpointManager_ActivateSingleCheckpoint(var74, (*((var0 + 16) + 4))[var74 * 48].v6, 2);
               }
               else
               {
                   CheckpointManager_ActivateSingleCheckpoint(var74, (*((var0 + 16) + 4))[var74 * 48].v6, 0);
                   if ((*((var0 + 16) + 4))[var74 * 48].v2 == 0)
                   {
                       mcHudMapServer_SetMutExSubtype(var23[(*((var0 + 16) + 4))[var74 * 48].v6], 1);
                   }
               }
               if ((*((var0 + 16) + 4))[var74 * 48].v2 == 0)
               {
                   var19 = CheckpointList_GetCheckpoint(var17, (*((var0 + 16) + 4))[var74 * 48].v6);
                   Checkpoint_GetPosition(var19, &var10);
                   UILogic_SetGPSDestination(var74, &var10);
                   AudioManager_PlayFrontendSound("HUD_CHECKPOINT_MASTER");
               }
           }
           (*((var0 + 16) + 4))[var74 * 48].v41 = CheckpointManager_CalculateRankOrdered(Race_GetCheckpointList(*(var0 + 12)), var0 + 16, var74, 2);
           if ((*((var0 + 16) + 4))[var74 * 48].v2 == 0)
           {
               FlashHelper_SetGlobalInt(var40, "PosNumber", (*((var0 + 16) + 4))[var74 * 48].v41);
           }
           var74 = var74 + 1;
       }
       if ((*((var0 + 16) + 4))[1 * 48].v8 != 0x7fffffff)
       {
           var6 = 0;
       }
       if ((var6 && (var7 < Race_GetTimer(*(var0 + 12)))) && (!SpeechSystem_IsInUse()))
       {
           if (mcCareerSpeech_PlayTauntInRace(var9, var2, (*((var0 + 16) + 4))[0 * 48].v41, var0) != null)
           {
               var7 = RAND_INT_RANGE(45000 + Race_GetTimer(*(var0 + 12)), 70000 + Race_GetTimer(*(var0 + 12)));
           }
       }
       WAITUNWARPED(30);
   }
   CheckpointList_Destroy(var18);
   CheckpointManager_ClearActiveCheckpointList();
   var20 = 0;
   while (var20 < var16)
   {
       mcHudMapServer_RemoveElement(var23[var20]);
       mcHudMapServer_DeleteElement(var23[var20]);
       var20 = var20 + 1;
   }
   mcHudMapServer_RemoveElement(*((var1 + 388) + 8));
   UILogic_RemoveGPSDestination(0);
   sub_1952(*((var1 + 388) + 4));
   UILogic_RemoveGPSDestination(0);
   RubberBandMgr_ShutdownRace();
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   Registry_GetValueInt("raceOverTrigger", &var73);
   if ((var73 == 0) && (!Race_IsDamagedOut(*(var0 + 12))))
   {
       PRINTSTRING("Finished race");
       UIManager_SendEvent("calculateResults");
       if ((*((var0 + 16) + 4))[0 * 48].v41 == 1)
       {
           StatsManager_UpdateStatInt("kFWN", 0, 0, 1);
           StatsManager_UpdateStatInt("kHOK", 0, 0, 1);
       }
       mcEvent_PostEventRaceResults("FREEWAY_RACE_COMPLETE", var0 + 16);
       mcEvent_PostEventRaceResults("RACE_EVENT", var0 + 16);
       sub_1a75(var0, 0, 1, 1);
       UIManager_SendEvent("raceEndNoMenu");
       if ((*((var0 + 16) + 4))[0 * 48].v41 == 1)
       {
           mcCareerSpeech_PlayTauntpostRace(var9, var2, 1);
       }
       else
       {
           mcCareerSpeech_PlayTauntpostRace(var9, var2, 0);
       }
   }
   else if (Race_IsDamagedOut(*(var0 + 12)))
   {
       mcEvent_PostEventRaceResults("RACE_QUIT", var0 + 16);
       PRINTSTRING("Damaged out");
       Registry_SetValueString("raceOverCommand", "");
       UIManager_SendEvent("calculateResults");
       sub_1a75(var0, 0, 1, 1);
       UIManager_SendEvent("raceEnd");
       while (var73 == 0)
       {
           PRINTSTRING("Waiting on race over");
           Registry_GetValueInt("raceOverTrigger", &var73);
           WAITUNWARPED(20);
       }
       mcCareerSpeech_PlayTauntpostRace(var9, var2, 0);
   }
   Racer_SetStreamingUnlocked(var9);
   Race_ResetCurrentRace();
   Race_Destroy(*(var0 + 12));
   AudioManager_SetActiveEndRace(0, 0);
}

function sub_e50(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22;

   var8 = 0;
   var9 = 10000.0f;
   var7 = 0;
   while (var7 < var4)
   {
       var10 = VDIST(var0.v0, var0.v1, var0.v2, (*var3)[var7 * 3].v0, (*var3)[var7 * 3].v1, (*var3)[var7 * 3].v2);
       if ((var10 < var9) && (var10 > 20.0f))
       {
           var9 = var10;
           var8 = var7;
       }
       else if (var10 < 20.0f)
       {
           if ((var7 + 1) >= var4)
           {
               var8 = 0;
           }
           else
           {
               var8 = var7 + 1;
           }
           var7 = var4;
       }
       var7 = var7 + 1;
   }
   var11 = var8 + 1;
   if (var11 >= var4)
   {
       var11 = 0;
   }
   var12.v0 = var0.v0 - (*var3)[var8 * 3].v0;
   var12.v1 = var0.v1 - (*var3)[var8 * 3].v1;
   var12.v2 = var0.v2 - (*var3)[var8 * 3].v2;
   var15.v0 = var0.v0 - (*var3)[var11 * 3].v0;
   var15.v1 = var0.v1 - (*var3)[var11 * 3].v1;
   var15.v2 = var0.v2 - (*var3)[var11 * 3].v2;
   if (Math_VecDot(&var12, &var15) < 0.0f)
   {
       var8 = var11;
   }
   return var8;
}

function sub_1217(var0)
{
   auto var3;

   return BrainFactory_CreateBrainRacing(Opponent_GetRacer(var0));
}

void sub_12a3(var0)
{
   auto var3, var4;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v41 = 0;
       var3 = var3 + 1;
   }
   if (*(var0 + 12) != null)
   {
       Race_SetRaceData(*(var0 + 12), var0 + 16);
   }
}

void sub_1377(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 2);
}

void sub_1952(var0)
{
   auto var3;

   BrainFactory_DeleteBrain(Opponent_GetRacer(var0));
}

void sub_1a75(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72;

   while (FlashNavigator_IsTransitioning())
   {
       PRINTSTRING("RaceOver.sch: WAITING TO END TRANSITION\n");
       WAITUNWARPED(200);
   }
   SplashManager_Cleanup();
   var6 = *((var0 + 16) + 3096);
   var7 = UIManager_FindMovie("PAUSEMOVIE");
   var8 = (17 == var6) || (16 == var6);
   var9 = 0;
   if (var6 == 11)
   {
       var9 = 0;
   }
   else
   {
       var9 = Race_IsTeamGame(var0 + 16);
   }
   var10 = Race_IsDamagedOut(*(var0 + 12));
   var11 = 1;
   var12 = Race_HasBeenArrested(*(var0 + 12));
   var13 = 0;
   var14 = Registry_GetValueBool("bComplete");
   var15 = Registry_GetValueBool("bFailure");
   var16 = Registry_GetValueBool("nPlayerCaught");
   var17 = var6 == 6;
   var18 = var6 == 2;
   var19 = var6 == 7;
   var20 = (var6 == 13) || (var6 == 14);
   var21 = var6 == 9;
   var22 = var6 == 10;
   var23 = var6 == 4;
   var24 = var6 == 3;
   PRINTSTRING("SCRIPT: Starting EndOfRaceSequence() for race type ");
   PRINTINT(*((var0 + 16) + 3096));
   if (var9)
   {
       PRINTSTRING(" (TEAM GAME) ");
   }
   else
   {
       PRINTSTRING(" (FFA GAME) ");
   }
   if (var10)
   {
       PRINTSTRING(" (DAMAGED OUT)\n");
   }
   else
   {
       PRINTSTRING(" (RACE SAFE)\n");
   }
   if (var15)
   {
       PRINTSTRING(" (FAILURE)\n");
   }
   else
   {
       PRINTSTRING(" (SUCCESS)\n");
   }
   if (((*((var0 + 16) + 4))[var1 * 48].v8 == 0x7fffffff) && (!var8))
   {
       if (!((var24 || var23) && (var14 || var15)))
       {
           PRINTSTRING("SCRIPT: skipping sequence because did not finish\n");
           var11 = 0;
       }
   }
   if (var12 && (!var16))
   {
       PRINTSTRING("SCRIPT: skipping sequence because damaged out or arrested\n");
       var11 = 0;
   }
   Notify(2);
   if (var11)
   {
       var25 = (*((var0 + 16) + 4))[var1 * 48].v41;
       var26 = (*((var0 + 16) + 4))[var1 * 48].v8;
       PRINTSTRING("nFinishTime = ");
       PRINTINT(var26);
       if (var3)
       {
           if ((var18 || var17) || var19)
           {
               if (var15)
               {
                   mcPlayerAudioEntity_PlayEndRaceSpeechLose();
               }
               else
               {
                   mcPlayerAudioEntity_PlayEndRaceSpeechWin();
               }
           }
           else if (var25 == 1)
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechWin();
           }
           else if ((var25 == 2) && ((var26 - Race_GetWinningTime(*(var0 + 12))) <= 300))
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechClose();
           }
           else
           {
               mcPlayerAudioEntity_PlayEndRaceSpeechLose();
           }
           WAITUNWARPED(200);
       }
       var27 = !*((var0 + 16) + 3120);
       var28 = 16;
       var45 = Form_GetForm(-1);
       var28[9] = Form_GetForm(51);
       var28[0] = Form_GetForm(60);
       var28[1] = Form_GetForm(54);
       var28[2] = Form_GetForm(57);
       var28[3] = Form_GetForm(58);
       var28[5] = Form_GetForm(42);
       var28[6] = Form_GetForm(53);
       var28[7] = Form_GetForm(49);
       var28[8] = Form_GetForm(50);
       var28[10] = Form_GetForm(46);
       var28[11] = Form_GetForm(47);
       var28[12] = Form_GetForm(56);
       var28[13] = Form_GetForm(49);
       var28[14] = Form_GetForm(50);
       var28[15] = Form_GetForm(52);
       UIManager_SendEvent("raceEnding");
       PRINTSTRING("SCRIPT : I start the race over sequence for raceType: ");
       PRINTINT(*((var0 + 16) + 3092));
       PRINTSTRING("\n");
       PerspectiveForm_SetCameraIndex(var28[0], 0);
       Form_ShowForm(var45, var28[0]);
       if (var27)
       {
           var46 = 0.5f;
           PerspectiveForm_SetSlowMotion(var28[0], 0.0f, 1.0f / var46, 0, 1, 0.4f);
       }
       else
       {
           WAITUNWARPED(100);
       }
       var47 = 5;
       var53 = 5;
       var59 = 0;
       var60 = 0;
       var61 = 0;
       var62 = 0;
       if (!var20)
       {
           if (Form_GetFormResult(var28[2]) == 3)
           {
               var61 = 1;
               PropertyCtrl_SetPropertyInt(Form_ToCtrl(var28[2]), 0, 0);
           }
           if (Form_GetFormResult(var28[6]) == 3)
           {
               var62 = 1;
           }
       }
       if (var12 || var13)
       {
           var61 = 0;
           var62 = 0;
           var23 = 0;
           var24 = 0;
           var18 = 0;
           var9 = 0;
       }
       var47[0] = 0;
       var47[1] = 0;
       var47[2] = 0;
       var47[3] = 0;
       var47[4] = 0;
       if (var9)
       {
           var47[0] = 3;
           var60 = var60 + 1;
       }
       else if (var12 && (!var16))
       {
           var47[0] = 10;
           var60 = var60 + 1;
       }
       else if (var13 && (!var16))
       {
           var47[0] = 11;
           var60 = var60 + 1;
       }
       else if (!var10)
       {
           if ((((!var18) && (!var19)) && (!var17)) && ((*((var0 + 16) + 4))[var1 * 48].v8 != 0x7fffffff))
           {
               strcpy(&var63, 16, "");
               strcati(&var63, 16, (*((var0 + 16) + 4))[var1 * 48].v41);
               Form_SetText(var28[1], &var63);
               PRINTSTRING("POSITION=");
               PRINTSTRING(&var63);
               PRINTSTRING("\n");
               var47[0] = 1;
               var60 = var60 + 1;
           }
       }
       if (var17 && (!var10))
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 9;
           var60 = var60 + 1;
       }
       else if (var18 && (!var10))
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 5;
           var60 = var60 + 1;
       }
       else if (var19)
       {
           if (((var14 || var15) || var16) || var10)
           {
               PRINTSTRING("PAYBACK  eP_EventResultsPanel \n A: ");
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       else if (var23)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 13;
           var60 = var60 + 1;
       }
       else if (var24)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
           var47[var60] = 14;
           var60 = var60 + 1;
       }
       else if (var21)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       else if (var22)
       {
           if (var14 || var15)
           {
               var47[var60] = 12;
               var60 = var60 + 1;
           }
       }
       if (var61)
       {
           var47[var60] = 2;
           var60 = var60 + 1;
       }
       if (var62)
       {
           var47[var60] = 6;
           var60 = var60 + 1;
       }
       var67 = 0;
       while (var67 <= (var60 - 1))
       {
           if (var47[var67] == 3)
           {
               var53[var67] = 4400;
           }
           else if (var47[var67] == 9)
           {
               var53[var67] = 5000;
           }
           else if (var47[var67] == 12)
           {
               var53[var67] = 3500;
           }
           else
           {
               var53[var67] = 2200;
           }
           var67 = var67 + 1;
       }
       AudioManager_SetActiveEndRace(1, var20);
       var68 = null;
       var67 = 0;
       while (var67 <= (var60 - 1))
       {
           Registry_GetValueInt("NET_UNLOADCAREER", &var59);
           if ((var59 > 0) || Net_IsConnecting())
           {
           }
           else
           {
               PRINTSTRING("SHOWING FORM AT INDEX: ");
               PRINTINT(var67);
               PRINTSTRING(", FORM: ");
               PRINTINT(var47[var67]);
               PRINTSTRING(", WAIT:");
               PRINTINT(var53[var67]);
               PRINTSTRING("\n");
               var68 = var28[var47[var67]];
               if (var47[var67] == 1)
               {
                   Form_ShowForm(var45, var68);
                   WAITUNWARPED(var53[var67]);
               }
               else if ((var47[var67] == 3) || (var47[var67] == 12))
               {
                   Form_ShowForm(var28[0], var68);
                   WAITUNWARPED(var53[var67]);
               }
               else
               {
                   sub_26b1(var28[0], var68);
               }
               if (!(var47[var67] == 0))
               {
                   Form_CloseForm(var68);
                   PRINTSTRING("CLOSEFORM\n");
               }
               var67 = var67 + 1;
           }
       }
       Form_CloseForm(var28[0]);
   }
   if (var2)
   {
       mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
   }
   PRINTSTRING("SCRIPT: End EndOfRaceSequence()\n");
}

void sub_26b1(var0, var1)
{
   auto var4, var5, var6;

   var4 = 1;
   Form_ShowForm(var0, var1);
   while (var4)
   {
       var4 = Form_GetFormVisible(var1);
       WAITUNWARPED(100);
   }
}

void sub_2926()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34;

   var2 = 3;
   var6 = 3;
   var16 = 3;
   var20 = 3;
   var2[0] = "vp_chv_police_96";
   var6[0 * 3].v0 = 2030.1f;
   var6[0 * 3].v1 = 6.8f;
   var6[0 * 3].v2 = -813.7f;
   var16[0] = (float)90;
   var20[0 * 3].v0 = -510.0f;
   var20[0 * 3].v1 = 9.5f;
   var20[0 * 3].v2 = -400.0f;
   var2[1] = "vp_chv_police_96";
   var6[1 * 3].v0 = -646.8f;
   var6[1 * 3].v1 = 18.5f;
   var6[1 * 3].v2 = -643.8f;
   var16[1] = (float)90;
   var20[1 * 3].v0 = -500.0f;
   var20[1 * 3].v1 = 9.5f;
   var20[1 * 3].v2 = -400.0f;
   var2[2] = "vp_chv_police_96";
   var6[2 * 3].v0 = -2434.4f;
   var6[2 * 3].v1 = 1.9f;
   var6[2 * 3].v2 = -577.9f;
   var16[2] = 84.9f;
   var20[2 * 3].v0 = -490.0f;
   var20[2 * 3].v1 = 9.5f;
   var20[2 * 3].v2 = -400.0f;
   var30 = 3;
   var34 = 0;
   while (var34 < 3)
   {
       var30[var34] = PoliceManager_CreatePolice(var2[var34], 1, &(var6[var34 * 3]), var16[var34], &(var20[var34 * 3]), 400 + var34);
       var34 = var34 + 1;
   }
}

