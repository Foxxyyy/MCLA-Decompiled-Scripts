void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9;

   var2 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 2);
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &(L[0].v0.v0[0 * 3]), 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var3 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var3, var2, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var3, mcHookman_GetModValue(L[0].v0.v97.v0));
   mcTargetManager_RegisterRacer(var2, var3);
   mcTargetManager_HideTarget(var2, 0);
   Racer_InitializeResetPosition(var3, &(L[0].v0.v0[0 * 3]), L[0].v0.v95);
   Racer_Reset(var3);
   L[0].v0.v97.v2 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 10, var3);
   Racer_SetIconType(var3, 16);
   var4 = sub_140(0);
   var5 = null;
   var6 = 0;
   var8 = mcMissionManager_GetMission("BESTOF_SC");
   var9 = 0;
   while (!var9)
   {
       var7 = mcHookman_GetState(L[0].v0.v97.v0);
       PRINTSTRING("Story Hookman -");
       PRINTINT(var2);
       PRINTSTRING(" - State - ");
       PRINTINT(var7);
       PRINTSTRING("\n");
       if (var7 == 1)
       {
           while (var7 == 1)
           {
               var7 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
           PRINTSTRING("Story Hookman -");
           PRINTINT(var2);
           PRINTSTRING(" - State change from RESERVED ");
           PRINTINT(1);
           PRINTSTRING(" to ");
           PRINTINT(var7);
           PRINTSTRING("\n");
       }
       if ((var7 == 4) || IsExitFlagSet())
       {
           PRINTSTRING("Story Hookman -");
           PRINTINT(var2);
           PRINTSTRING(" Shuting down\n");
       }
       else
       {
           var6 = sub_306(var3);
           mcHookman_SetDifficulty(L[0].v0.v97.v0, var6);
           Racer_SetIconColorByDifficulty(var3, var6);
           var5 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/CruisingHookmanCore", &(L[0].v0), 103, 1500);
           while (!IsChildFinished(var5))
           {
               WAITUNWARPED(100);
           }
           var7 = mcHookman_GetState(L[0].v0.v97.v0);
           if ((var7 == 4) || IsExitFlagSet())
           {
           }
           else
           {
               L[0].v0.v101 = 1;
               Racer_HideIcon(var3, 0);
               sub_3fb(L[0].v0.v97.v1, var3, var4);
               if (mcMission_GetState(var8) == 5)
               {
               }
               else
               {
                   mcHookman_SetState(L[0].v0.v97.v0, 2);
                   WAITUNWARPED(100);
               }
           }
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING("\n");
   Racer_HideIcon(var3, 1);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   mcTargetManager_UnRegisterTarget(var2);
   OpponentManager_RemoveOpponentFromWorld(L[0].v0.v97.v1);
   OpponentManager_DeleteOpponent(L[0].v0.v97.v1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_140(var0)
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

function sub_306(var0)
{
   auto var3, var4;

   var3 = mcCareer_GetDifficultyPlayerVsRacer(var0);
   if (var3 == 0)
   {
       return 1;
   }
   else
   {
       return var3;
   }
}

void sub_3fb(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143, var144, var145, var146, var147, var148, var149, var150, var151, var152, var153, var154, var155, var156, var157, var158, var159, var160, var161, var162, var163, var164, var165, var166, var167, var168, var169, var170, var171, var172, var173, var174, var175, var176, var177, var178, var179, var180, var181, var182, var183, var184, var185, var186, var187, var188, var189, var190, var191, var192, var193, var194, var195, var196, var197, var198, var199, var200, var201, var202, var203, var204, var205, var206, var207, var208, var209, var210, var211, var212, var213, var214, var215, var216, var217, var218, var219, var220, var221, var222, var223, var224, var225, var226, var227, var228, var229, var230, var231, var232, var233, var234, var235, var236, var237, var238, var239, var240, var241, var242, var243, var244, var245, var246, var247, var248, var249, var250, var251, var252, var253, var254, var255, var256, var257, var258, var259, var260, var261, var262, var263, var264, var265, var266, var267, var268, var269, var270, var271, var272, var273, var274, var275, var276, var277, var278, var279, var280, var281, var282, var283, var284, var285, var286, var287, var288, var289, var290, var291, var292, var293, var294, var295, var296, var297, var298, var299, var300, var301, var302, var303, var304, var305, var306, var307, var308, var309, var310, var311, var312, var313, var314, var315, var316, var317, var318, var319, var320, var321, var322, var323, var324, var325, var326, var327, var328, var329, var330, var331, var332, var333, var334, var335, var336, var337, var338, var339, var340, var341, var342, var343, var344, var345, var346, var347, var348, var349, var350, var351, var352, var353, var354, var355, var356, var357, var358, var359, var360, var361, var362, var363, var364, var365, var366, var367, var368, var369, var370, var371, var372, var373, var374, var375, var376, var377, var378, var379, var380, var381, var382, var383, var384, var385, var386, var387, var388, var389, var390, var391, var392, var393, var394, var395, var396, var397, var398, var399, var400, var401, var402, var403, var404, var405, var406, var407, var408, var409, var410, var411, var412, var413, var414, var415, var416, var417, var418, var419, var420, var421, var422, var423, var424, var425, var426, var427, var428, var429, var430, var431, var432, var433, var434, var435, var436, var437, var438, var439, var440, var441, var442, var443, var444, var445, var446, var447, var448, var449, var450, var451, var452, var453, var454, var455, var456, var457, var458, var459, var460, var461, var462, var463, var464, var465, var466, var467, var468, var469, var470, var471, var472, var473, var474, var475, var476, var477, var478, var479, var480, var481, var482, var483, var484, var485, var486, var487, var488, var489, var490, var491, var492, var493, var494, var495, var496, var497, var498, var499, var500, var501, var502, var503, var504, var505, var506, var507, var508, var509, var510, var511, var512, var513, var514, var515, var516, var517, var518, var519, var520, var521, var522, var523, var524, var525, var526, var527, var528, var529, var530, var531, var532, var533, var534, var535, var536, var537, var538, var539, var540, var541, var542, var543, var544, var545, var546, var547, var548, var549, var550, var551, var552, var553, var554, var555, var556, var557, var558, var559, var560, var561, var562, var563, var564, var565, var566, var567, var568, var569, var570, var571, var572, var573, var574, var575, var576, var577, var578, var579, var580, var581, var582, var583, var584, var585, var586, var587, var588, var589, var590, var591, var592, var593, var594, var595, var596, var597, var598, var599, var600, var601, var602, var603, var604, var605, var606, var607, var608, var609, var610, var611, var612, var613, var614, var615, var616, var617, var618, var619, var620, var621, var622, var623, var624, var625, var626, var627, var628, var629, var630, var631, var632, var633, var634, var635, var636, var637, var638, var639, var640, var641, var642, var643, var644, var645, var646, var647, var648, var649, var650, var651, var652, var653, var654, var655, var656, var657, var658, var659, var660, var661, var662, var663, var664, var665, var666, var667, var668, var669, var670, var671, var672, var673, var674, var675, var676, var677, var678, var679, var680, var681, var682, var683, var684, var685, var686, var687, var688, var689, var690, var691, var692, var693, var694, var695, var696, var697, var698, var699, var700, var701, var702, var703, var704, var705, var706, var707, var708, var709, var710, var711, var712, var713, var714, var715, var716, var717, var718, var719, var720, var721, var722, var723, var724, var725, var726, var727, var728, var729, var730, var731, var732, var733, var734, var735, var736, var737, var738, var739, var740, var741, var742, var743, var744, var745, var746, var747, var748, var749, var750, var751, var752, var753, var754, var755, var756, var757, var758, var759, var760, var761, var762, var763, var764, var765, var766, var767, var768, var769, var770, var771, var772, var773, var774, var775, var776, var777, var778, var779, var780, var781, var782, var783, var784, var785, var786, var787, var788, var789, var790, var791, var792, var793, var794, var795, var796, var797, var798, var799, var800, var801, var802, var803, var804, var805, var806, var807, var808, var809, var810, var811, var812, var813, var814, var815, var816, var817, var818, var819, var820, var821, var822, var823, var824, var825, var826, var827;

   var5.v0.v4.v1 = 16;
   var5.v0.v4.v1.v1.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v791 = 3;
   var5.v0.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v791.v804 = 8;
   var5.v814 = 1;
   var5.v802 = "BESTOF_SC_SERIES";
   var5.v803 = 5;
   var5.v813 = 3;
   var5.v804[0] = "game/Race/SouthCentral/Ordered/sc_ordered_jp_01";
   var5.v804[1] = "game/Race/SouthCentral/Ordered/sc_ordered_dh_01";
   var5.v804[2] = "game/Race/SouthCentral/Ordered/sc_ordered_dh_02";
   var5.v804[3] = "game/Race/SouthCentral/Circuit/sc_circuit_ds_01";
   var5.v804[4] = "game/Race/SouthCentral/Ordered/sc_ordered_cb_02";
   var5.v0.v4.v1[0 * 48].v0 = var2;
   var5.v0.v4.v1[0 * 48].v2 = 0;
   var5.v0.v4.v1[0 * 48].v5 = 1;
   var5.v0.v4.v1[1 * 48].v0 = var1;
   var5.v0.v4.v1[1 * 48].v2 = 2;
   var5.v0.v4.v1[1 * 48].v5 = 1;
   var5.v0.v4.v1[1 * 48].v1 = var0;
   Racer_SetStreamingLockedIn(var1);
   var5.v0.v4.v770 = 2;
   var5.v0.v4.v771 = 0;
   var5.v0.v4.v775 = mcCareer_GetDifficultyPlayerVsRacer(var1);
   var5.v0.v4.v780 = 0;
   var5.v0.v4.v784 = 1;
   var5.v0.v4.v776 = 31;
   var5.v0.v4.v777 = 255;
   var5.v815 = "Game/CineScripts/generated/cut_reward_nikolai_generated";
   var5.v816 = "REWARD_GH_04";
   var5.v817 = "GREET_BESTOF_SC";
   var5.v818 = "TAUNT_PRE_BESTOF_SC";
   sub_81a(&var5);
   Racer_SetStreamingUnlocked(var1);
}

void sub_81a(var0)
{
   auto var3, var4;

   var3 = START_NEW_SCRIPT_WITH_ARGS("Game/Race/OrderedSeriesCore", var0, 820, 1500);
   while (!IsChildFinished(var3))
   {
       WAITUNWARPED(10);
   }
}

