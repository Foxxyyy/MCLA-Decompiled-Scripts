void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13;

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
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 2, var3);
   Racer_SetIconType(var3, 4);
   var4 = mcMissionManager_GetMission("BEAT_SH_02_CCLASS");
   var5 = 0;
   var6 = 0;
   var7 = 0;
   var8 = 0;
   var9 = null;
   var10 = null;
   var11 = null;
   var12 = Form_GetForm(71);
   var13 = 0;
   while (!var13)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var8);
       if (var8 == 1)
       {
           Racer_HideIcon(var3, 1);
           mcHudMapServer_RemoveElement(L[0].v0.v97.v2);
           Racer_SetStreamingLockedOut(var3);
           while (var8 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var8);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var3);
           Racer_HideIcon(var3, 0);
           mcHudMapServer_AddElement(L[0].v0.v97.v2);
       }
       var5 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var5 == 1)
       {
           while (var5 == 1)
           {
               var5 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var5 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           var6 = sub_2bd(var3);
           mcHookman_SetDifficulty(L[0].v0.v97.v0, var6);
           Racer_SetIconColorByDifficulty(var3, var6);
           var10 = START_NEW_SCRIPT_WITH_ARGS("game/CruisingHookmen/CruisingHookmanCore", &(L[0].v0), 103, 1500);
           while (!IsChildFinished(var10))
           {
               WAITUNWARPED(100);
           }
           var5 = mcHookman_GetState(L[0].v0.v97.v0);
           if ((var5 == 4) || IsExitFlagSet())
           {
           }
           else
           {
               var11 = sub_392(0);
               if (2 != Racer_GetPerformanceClass(var11))
               {
                   sub_427(var12, "BEAT_SH_02_CCLASS_RESTRICTION", "VEHICLE_CLASS_RESTRICTION", 1, 1);
                   mcHookman_SetState(L[0].v0.v97.v0, 2);
               }
               else
               {
                   var5 = mcHookman_GetState(L[0].v0.v97.v0);
                   if ((var5 == 4) || IsExitFlagSet())
                   {
                   }
                   else
                   {
                       L[0].v0.v101 = 1;
                       sub_547(L[0].v0.v97.v1, 0, mcHookman_GetDifficulty(L[0].v0.v97.v0), L[0].v0.v97.v2, 8, 2, 6, 15, 31, "BEAT_SH_02_CCLASS_RACE_COMPLETE", "GREET_BEAT_SH_02_CCLASS", "TAUNT_PRE_BEAT_SH_02_CCLASS");
                       if (mcMission_GetState(var4) == 5)
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
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING("\n");
   Racer_HideIcon(var3, 1);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   mcTargetManager_UnRegisterTarget(var2);
   var9 = BrainFactory_CreateBrainCruising(var3);
   sub_438b(RAND_INT_RANGE(0, 7), var9);
   BrainCruising_SetLooping(var9, 1);
   BrainCruising_DriveToNearestRail(var9);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var2);
   PRINTSTRING(" deleted.\n");
}

function sub_2bd(var0)
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

function sub_392(var0)
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

function sub_427(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12;

   var7 = 1;
   MessageBox_ShowMessageBox(var0, var1, var2, var3, var4);
   while (var7)
   {
       var7 = MessageBox_GetMessageBoxVisible();
       WAITUNWARPED(100);
   }
   return MessageBox_GetMessageBoxResult();
}

void sub_547(var0, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11)
{
   auto var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95, var96, var97, var98, var99, var100, var101, var102, var103, var104, var105, var106, var107, var108, var109, var110, var111, var112, var113, var114, var115, var116, var117, var118, var119, var120, var121, var122, var123, var124, var125, var126, var127, var128, var129, var130, var131, var132, var133, var134, var135, var136, var137, var138, var139, var140, var141, var142, var143, var144, var145, var146, var147, var148, var149, var150, var151, var152, var153, var154, var155, var156, var157, var158, var159, var160, var161, var162, var163, var164, var165, var166, var167, var168, var169, var170, var171, var172, var173, var174, var175, var176, var177, var178, var179, var180, var181, var182, var183, var184, var185, var186, var187, var188, var189, var190, var191, var192, var193, var194, var195, var196, var197, var198, var199, var200, var201, var202, var203, var204, var205, var206, var207, var208, var209, var210, var211, var212, var213, var214, var215, var216, var217, var218, var219, var220, var221, var222, var223, var224, var225, var226, var227, var228, var229, var230, var231, var232, var233, var234, var235, var236, var237, var238, var239, var240, var241, var242, var243, var244, var245, var246, var247, var248, var249, var250, var251, var252, var253, var254, var255, var256, var257, var258, var259, var260, var261, var262, var263, var264, var265, var266, var267, var268, var269, var270, var271, var272, var273, var274, var275, var276, var277, var278, var279, var280, var281, var282, var283, var284, var285, var286, var287, var288, var289, var290, var291, var292, var293, var294, var295, var296, var297, var298, var299, var300, var301, var302, var303, var304, var305, var306, var307, var308, var309, var310, var311, var312, var313, var314, var315, var316, var317, var318, var319, var320, var321, var322, var323, var324, var325, var326, var327, var328, var329, var330, var331, var332, var333, var334, var335, var336, var337, var338, var339, var340, var341, var342, var343, var344, var345, var346, var347, var348, var349, var350, var351, var352, var353, var354, var355, var356, var357, var358, var359, var360, var361, var362, var363, var364, var365, var366, var367, var368, var369, var370, var371, var372, var373, var374, var375, var376, var377, var378, var379, var380, var381, var382, var383, var384, var385, var386, var387, var388, var389, var390, var391, var392, var393, var394, var395, var396, var397, var398, var399, var400, var401, var402, var403, var404, var405, var406, var407, var408, var409, var410, var411, var412, var413, var414, var415, var416, var417, var418, var419, var420, var421, var422, var423, var424, var425, var426, var427, var428, var429, var430, var431, var432, var433, var434, var435, var436, var437, var438, var439, var440, var441, var442, var443, var444, var445, var446, var447, var448, var449, var450, var451, var452, var453, var454, var455, var456, var457, var458, var459, var460, var461, var462, var463, var464, var465, var466, var467, var468, var469, var470, var471, var472, var473, var474, var475, var476, var477, var478, var479, var480, var481, var482, var483, var484, var485, var486, var487, var488, var489, var490, var491, var492, var493, var494, var495, var496, var497, var498, var499, var500, var501, var502, var503, var504, var505, var506, var507, var508, var509, var510, var511, var512, var513, var514, var515, var516, var517, var518, var519, var520, var521, var522, var523, var524, var525, var526, var527, var528, var529, var530, var531, var532, var533, var534, var535, var536, var537, var538, var539, var540, var541, var542, var543, var544, var545, var546, var547, var548, var549, var550, var551, var552, var553, var554, var555, var556, var557, var558, var559, var560, var561, var562, var563, var564, var565, var566, var567, var568, var569, var570, var571, var572, var573, var574, var575, var576, var577, var578, var579, var580, var581, var582, var583, var584, var585, var586, var587, var588, var589, var590, var591, var592, var593, var594, var595, var596, var597, var598, var599, var600, var601, var602, var603, var604, var605, var606, var607, var608, var609, var610, var611, var612, var613, var614, var615, var616, var617, var618, var619, var620, var621, var622, var623, var624, var625, var626, var627, var628, var629, var630, var631, var632, var633, var634, var635, var636, var637, var638, var639, var640, var641, var642, var643, var644, var645, var646, var647, var648, var649, var650, var651, var652, var653, var654, var655, var656, var657, var658, var659, var660, var661, var662, var663, var664, var665, var666, var667, var668, var669, var670, var671, var672, var673, var674, var675, var676, var677, var678, var679, var680, var681, var682, var683, var684, var685, var686, var687, var688, var689, var690, var691, var692, var693, var694, var695, var696, var697, var698, var699, var700, var701, var702, var703, var704, var705, var706, var707, var708, var709, var710, var711, var712, var713, var714, var715, var716, var717, var718, var719, var720, var721, var722, var723, var724, var725, var726, var727, var728, var729, var730, var731, var732, var733, var734, var735, var736, var737, var738, var739, var740, var741, var742, var743, var744, var745, var746, var747, var748, var749, var750, var751, var752, var753, var754, var755, var756, var757, var758, var759, var760, var761, var762, var763, var764, var765, var766, var767, var768, var769, var770, var771, var772, var773, var774, var775, var776, var777, var778, var779, var780, var781, var782, var783, var784, var785, var786, var787, var788, var789, var790, var791, var792, var793, var794, var795, var796, var797, var798, var799, var800, var801, var802, var803, var804, var805, var806, var807, var808, var809, var810, var811, var812, var813, var814, var815, var816, var817, var818, var819, var820, var821, var822, var823, var824, var825, var826, var827, var828, var829, var830, var831, var832, var833, var834, var835, var836, var837, var838, var839, var840, var841, var842, var843, var844, var845, var846, var847, var848, var849, var850, var851, var852, var853, var854, var855, var856, var857, var858, var859, var860, var861, var862, var863, var864, var865, var866, var867, var868, var869, var870;

   Registry_SetValueInt("bNextRace", 1);
   var14.v4.v1 = 16;
   var14.v4.v1.v1.v9 = 15;
   var14.v4.v1.v1.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25 = 15;
   var14.v4.v1.v1.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v9.v25.v48.v791 = 3;
   strcpy(&var816, 64, "");
   var832 = 0;
   var833 = mcMissionManager_GetMission("RACES_IN_BEACHES");
   var834 = mcMissionManager_GetMission("RACES_IN_DOWNTOWN");
   var835 = mcMissionManager_GetMission("RACES_IN_SC");
   var836 = 6;
   var14.v4.v1[0 * 48].v0 = sub_392(0);
   var14.v4.v1[0 * 48].v2 = 0;
   var14.v4.v1[0 * 48].v5 = 1;
   var14.v4.v1[1 * 48].v1 = var0;
   var14.v4.v1[1 * 48].v0 = Opponent_GetRacer(var0);
   var14.v4.v1[1 * 48].v2 = 2;
   var14.v4.v1[1 * 48].v5 = 1;
   var14.v4.v1[1 * 48].v4 = var3;
   Racer_SetStreamingLockedIn(var14.v4.v1[1 * 48].v0);
   Racer_HideIcon(var14.v4.v1[1 * 48].v0, 0);
   var14.v4.v770 = var1 + 2;
   var14.v4.v771 = var1;
   var14.v4.v775 = var2;
   if (var14.v4.v775 < 2)
   {
       var14.v4.v778 = 0;
   }
   else
   {
       var14.v4.v778 = 1;
   }
   var14.v4.v780 = 0;
   var837 = mcRaceArray_Create();
   var838 = Racer_GetCurrentDistrict(var14.v4.v1[1 * 48].v0);
   if (mcMission_GetState(var833) == 3)
   {
       var836 = 1;
   }
   else if (mcMission_GetState(var834) == 3)
   {
       var836 = 3;
   }
   else if (mcMission_GetState(var835) == 3)
   {
       var836 = 4;
   }
   mcRaceArray_Fill(var837, var836, var5, var6);
   var14.v4.v0 = mcRaceArray_FindBeatMeThereRaceIndex(var837, var838, var14.v4.v1[1 * 48].v0, 400.0f);
   var839 = LookupCity(GetCurrentCity());
   var840 = CityDescription_LookupRaceByIndex(var839, var14.v4.v0);
   mcRaceArray_SortByDistance(var837, var14.v4.v1[1 * 48].v0);
   mcRaceArray_LocalHookmanFilter(var837, var14.v4.v0, 3);
   var841.v0 = 0.0f;
   var841.v1 = 0.0f;
   var841.v2 = 0.0f;
   var844 = 0.0f;
   OpponentManager_ClearUsedCharacters();
   var845 = mcCareer_GetHookman(Racer_GetUID(var14.v4.v1[1 * 48].v0));
   if (var845 != null)
   {
       OpponentManager_MarkCharacterAsUsed(mcHookman_GetName(var845));
   }
   var846 = mcCarArray_Create();
   mcCarArray_Fill(var846, var14.v4.v1[0 * 48].v0, var14.v4.v775, var7, var8, -1);
   var847 = null;
   var848 = null;
   var849 = null;
   var850 = null;
   var851 = null;
   var852 = 0;
   var853 = 0;
   var852 = 0;
   while (var852 < var14.v4.v771)
   {
       var853 = var852 + (var14.v4.v770 - var14.v4.v771);
       var14.v4.v1[var853 * 48].v1 = OpponentManager_CreateOpponent();
       var14.v4.v1[var853 * 48].v0 = Opponent_GetRacer(var14.v4.v1[var853 * 48].v1);
       var14.v4.v1[var853 * 48].v2 = 2;
       var14.v4.v1[var853 * 48].v5 = 0;
       var847 = mcCarArray_GetRandomCarArrayData(var846);
       var848 = mcCarArrayData_GetName(var847);
       var849 = OpponentManager_FindRandomAvailableCharacterByVehicleName(var848);
       OpponentManager_MarkCharacterAsUsed(mcCharacterConfigData_GetName(var849));
       var850 = mcCharacterConfigData_GetCarConfigDataByVehicleName(var849, var848, Racer_GetCarConfig(var14.v4.v1[0 * 48].v0), var14.v4.v775, 255, 1);
       var851 = mcCarConfigData_GetRandomConfigData(var850);
       RaceDescription_GetGridPosition(var840, var853, &var841, &var844);
       OpponentManager_LoadOpponent(var14.v4.v1[var853 * 48].v1, mcConfigData_GetName(var851), &var841, var844);
       OpponentManager_AddOpponentToWorld(var14.v4.v1[var853 * 48].v1);
       Racer_SetModValue(var14.v4.v1[var853 * 48].v0, mcCarConfigData_GetModValue(var850));
       Racer_SetCharacterName(var14.v4.v1[var853 * 48].v0, mcCareer_GetHookmanCharacterSet(mcCharacterConfigData_GetName(var849)));
       Racer_SetStreamingLockedIn(var14.v4.v1[var853 * 48].v0);
       var14.v4.v1[var853 * 48].v4 = mcHudMapServer_CreateElement();
       mcHudMapServer_SetVehicleElement(var14.v4.v1[var853 * 48].v4, 6, var14.v4.v1[var853 * 48].v0);
       var852 = var852 + 1;
   }
   var14.v3 = Race_Create();
   Race_SetCurrentRace(var14.v3);
   sub_c8e(&var14, var840, var0, 2, 1, 13, var10);
   var854 = 1;
   var855 = 0;
   var856 = 0;
   var857 = 0;
   var858 = mcCareerSpeech_FindScenario("GREETING_MEET_ME_THERE_EVENT");
   Registry_GetValueInt("raceOverTrigger", &var832);
   if (var832 == 1)
   {
       strcpy(&var816, 64, "");
       Registry_GetValueString("raceOverCommand", &var816);
       PRINTSTRING("Beat me there Race command: ");
       PRINTSTRING(&var816);
       PRINTSTRING("\n");
       if ((StringCaseCompare(&var816, "returnToCruise") || StringCaseCompare(&var816, "quit")) || StringCaseCompare(&var816, "returnToGarage"))
       {
       }
   }
   if (!StringCaseCompare(var11, ""))
   {
       CineScript_PrepareSpeechScenarioForNextCutscene(var11, var14.v4.v1[0 * 48].v0, var14.v4.v1[1 * 48].v0, 1);
   }
   var852 = 0;
   while (var852 < var14.v4.v771)
   {
       var853 = var852 + (var14.v4.v770 - var14.v4.v771);
       mcHudMapServer_AddElement(var14.v4.v1[var853 * 48].v4);
       var852 = var852 + 1;
   }
   Racer_HideIcon(var14.v4.v1[1 * 48].v0, 0);
   while (StatsManager_GetIntValue("tNOR", 0) != 0)
   {
       var14.v4.v779 = 0;
   }
   sub_2b44(&var14);
   var14.v799 = sub_2bf7(var840, var14.v4.v770, var854);
   if (StringCompare(var14.v799, ""))
   {
       var14.v799 = "Game/RaceTypes/generic_countdown";
   }
   UILogic_SaveCarDamage();
   if (var14.v4.v770 > mcRacerManager_GetNumRacersAllowedForPolice())
   {
       sub_2d47(var840, 0.0f, 0, 0, 1, 1, 1);
   }
   else
   {
       sub_2d47(var840, 0.25f, 0, 0, 1, 1, 1);
   }
   var856 = 0;
   if (var855)
   {
       PRINTSTRING("Warping\n");
       if (StringCaseCompare(&var816, "replay"))
       {
           sub_336e(1, 1, 0x3f800000, 0);
           Warper_Warp("REPLAY");
           PRINTSTRING("Setting up replay\n");
           while (!Warper_IsReadyToLoadStuff())
           {
               WAITUNWARPED(100);
               PRINTSTRING("Waiting\n");
           }
           sub_3705(1, 1, 0x3f800000, 0);
           Warper_Warp("EXIT_TO_CUT");
           PRINTSTRING("Transitioning to replay start\n");
           while (!Warper_IsReadyToLoadStuff())
           {
               WAITUNWARPED(100);
               PRINTSTRING("Waiting\n");
           }
       }
       else
       {
           Warper_Warp("DEFAULT_WITH_CUT");
           PRINTSTRING("Start Waiting\n");
           while (!Warper_IsReadyToLoadStuff())
           {
               WAITUNWARPED(100);
               PRINTSTRING("Waiting\n");
           }
           while (SpeechSystem_IsPlaying())
           {
               WAITUNWARPED(100);
               PRINTSTRING("Waiting for speech to finish\n");
           }
       }
       PRINTSTRING("Done Waiting\n");
   }
   mcGame_ThrowEvent("localRace");
   Race_SetRaceData(var14.v3, &(var14.v4));
   sub_3b7c(&var14);
   Race_GetRaceData(var14.v3, &(var14.v4));
   Registry_GetValueInt("raceOverTrigger", &var832);
   if (var832 == 0)
   {
       UIManager_SendEvent("calculateResults");
       if (((!var14.v4.v786) && (!Race_IsDamagedOut(var14.v3))) && (!Race_HasBeenArrested(var14.v3)))
       {
           mcEvent_PostEventRaceResults("GENERIC_RACE_COMPLETE", &(var14.v4));
           mcEvent_PostEventRaceResults("RACE_EVENT", &(var14.v4));
           if ((!StringCaseCompare(var9, "")) && (var14.v4.v1[0 * 48].v41 == 1))
           {
               mcEvent_PostEventStr("MISSION_EVENT", var9);
           }
       }
       var856 = 1;
       sub_18d7(&var14, 0, 1, 1);
       UIManager_SendEvent("raceEnd");
       while (var832 == 0)
       {
           Registry_GetValueInt("raceOverTrigger", &var832);
           WAITUNWARPED(20);
       }
       AudioManager_SetActiveEndRace(0, 0);
   }
   strcpy(&var816, 64, "");
   Registry_GetValueString("raceOverCommand", &var816);
   PRINTSTRING("Local Race command: ");
   PRINTSTRING(&var816);
   PRINTSTRING("\n");
   if (var14.v4.v1[0 * 48].v41 == 1)
   {
       StatsManager_UpdateStatInt("kHOK", 0, 0, 1);
   }
   if (StringCaseCompare(&var816, "nextRace"))
   {
       PRINTSTRING("Local race next\n");
       var14.v4.v0 = mcRaceArray_FindNextRaceIndex(var837);
       var840 = CityDescription_LookupRaceByIndex(var839, var14.v4.v0);
       var854 = 0;
       var855 = 1;
       if (var858 != null)
       {
           mcCareerSpeech_PlayScenario(var858, Racer_GetVehicleDriverName(var14.v4.v1[1 * 48].v0), "PLAYER");
       }
       var857 = var857 + 1;
       if (var857 == 2)
       {
           Registry_SetValueInt("bNextRace", 0);
       }
   }
   else if (StringCaseCompare(&var816, "restart"))
   {
       PRINTSTRING("Local race restart\n");
       var855 = 1;
       sub_40e4();
       if (var856)
       {
       }
       else
       {
       }
   }
   else if (StringCaseCompare(&var816, "replay"))
   {
       PRINTSTRING("Local race replay\n");
       var855 = 1;
       Registry_SetValueInt("replaying", 1);
   }
   else if (StringCaseCompare(&var816, "returnToCruise"))
   {
       PRINTSTRING("return to cruise\n");
       if (var14.v4.v1[0 * 48].v41 == 1)
       {
           mcCareerSpeech_PlayTauntpostRace(var14.v4.v1[1 * 48].v0, var14.v4.v1[0 * 48].v0, 1);
       }
       else if (mcCareerSpeech_PlayTauntpostRace(var14.v4.v1[1 * 48].v0, var14.v4.v1[0 * 48].v0, 0) != null)
       {
       }
   }
   var852 = 0;
   while (var852 < var14.v4.v771)
   {
       var853 = var852 + (var14.v4.v770 - var14.v4.v771);
       sub_430e(var14.v4.v1[0 * 48].v0, var14.v4.v1[var853 * 48].v1, var14.v4.v1[var853 * 48].v0, var853, Race_HasBeenArrested(var14.v3));
       PRINTSTRING("DELETING ELEMENT FOR RACER - ");
       PRINTINT(var853);
       PRINTSTRING(" Num Racers ");
       PRINTINT(var14.v4.v770);
       PRINTSTRING(" Num Oppponents ");
       PRINTINT(var14.v4.v771);
       PRINTSTRING("\n");
       Racer_HideIcon(var14.v4.v1[var853 * 48].v0, 1);
       mcHudMapServer_DeleteElement(var14.v4.v1[var853 * 48].v4);
       var852 = var852 + 1;
   }
   mcCareerSpeech_PlayTauntpostRace(var14.v4.v1[1 * 48].v0, var14.v4.v1[0 * 48].v0, 0);
   Racer_SetStreamingUnlocked(var14.v4.v1[1 * 48].v0);
   mcRaceArray_Destroy(var837);
   Race_ResetCurrentRace();
   Race_Destroy(var14.v3);
   mcCarArray_Destroy(var846);
   sub_30e2();
   OpponentManager_ClearUsedCharacters();
   Registry_SetValueInt("bNextRace", 0);
}

void sub_c8e(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46;

   var12 = 0;
   var13 = 0;
   var14 = 0;
   var15 = null;
   var16 = null;
   var17 = mcHudMapServer_CreateElement();
   var18 = null;
   var19 = 0;
   var20 = 40;
   var21 = null;
   strcpy(&var22, 64, "");
   var38 = HUD_GetHUDCtrl(6);
   var39 = Opponent_GetRacer(var2);
   if (Net_IsConnecting() || Net_IsNetworked())
   {
       return;
   }
   else
   {
       if ((StatsManager_GetIntValue("tTBM", 0) == 0) && (!GetNoTutorialCommandLine()))
       {
           StatsManager_UpdateStatInt("tTBM", 0, 3, 1);
           AudioManager_SetActiveTimeSlow(1);
           sub_d46(0, 0x3f000000, 108);
           sub_dd9(-1, 102, "TUTORIAL_BEAT_ME_THERE", "drv_mb_04_set", "PLAYER");
           AudioManager_SetActiveTimeSlow(0);
           sub_e8e(108, 0x3f000000);
       }
       Registry_SetValueInt("raceOverTrigger", 0);
       if (PoliceManager_IsAnyPoliceCloseToPlayer(250.0f))
       {
           PRINTSTRING("COPS TOO CLOSE!\n");
           var21 = mcCareerSpeech_FindScenario("GREETING_MEET_ME_THERE_COPS");
           if (var21 != null)
           {
               mcCareerSpeech_PlayScenario(var21, Racer_GetVehicleDriverName((*((var0 + 16) + 4))[1 * 48].v0), "PLAYER");
           }
           SplashManager_Splash(0, 4, "COPS_TOO_CLOSE", 0x40000000, 1, 0);
           PoliceManager_SetAllPoliceUnderground(1, 1);
       }
       else
       {
           SplashManager_Splash(0, 4, "RACE_TO_START", 0x40000000, 1, 0);
           if (!StringCaseCompare(var6, ""))
           {
               var21 = mcCareerSpeech_FindScenario(var6);
           }
           else
           {
               var21 = mcCareerSpeech_FindScenario("GREETING_BEAT_ME_THERE");
           }
           if (var21 != null)
           {
               mcCareerSpeech_PlayScenario(var21, Racer_GetVehicleDriverName((*((var0 + 16) + 4))[1 * 48].v0), "PLAYER");
               Racer_PlayGestureMild((*((var0 + 16) + 4))[1 * 48].v0);
           }
           PoliceManager_SetAllPoliceUnderground(1, 1);
           *((var0 + 16) + 3088) = 1;
           *((var0 + 16) + 3092) = 1;
           *((var0 + 16) + 3096) = var5;
           *((var0 + 16) + 3148) = 30000;
           var12 = 0;
           while (var12 < var3)
           {
               (*((var0 + 16) + 4))[var12 * 48].v6 = 0;
               (*((var0 + 16) + 4))[var12 * 48].v7 = 0;
               (*((var0 + 16) + 4))[var12 * 48].v25[0] = 0;
               (*((var0 + 16) + 4))[var12 * 48].v9[0] = 0;
               (*((var0 + 16) + 4))[var12 * 48].v8 = 0x7fffffff;
               var12 = var12 + 1;
           }
           mcGame_ThrowEvent("beatMeThereRace");
           Racer_GetPosition(var39, &var9);
           Racer_InitializeResetPosition(var39, &var9, (float)0);
           RaceDescription_GetStartBeaconPosition(var1, &var9);
           var12 = 0;
           while (var12 < var3)
           {
               if ((*((var0 + 16) + 4))[var12 * 48].v2 == 2)
               {
                   (*((var0 + 16) + 4))[var12 * 48].v3 = sub_11b6(var2);
                   BrainRacing_AppendGoal((*((var0 + 16) + 4))[var12 * 48].v3, &var9, 5.0f);
                   BrainRacing_SetAvoidHandbrakeTurns((*((var0 + 16) + 4))[var12 * 48].v3, 1);
               }
               var12 = var12 + 1;
           }
           mcHudMapServer_SetElement(var17, 0, 0, &var9, 0.0f);
           mcHudMapServer_SetMutExSubtype(var17, 5);
           PRINTSTRING("ADDING ELEMENT 1\n");
           mcHudMapServer_AddElement(var17);
           Race_Reset(*(var0 + 12));
           var15 = Race_GetCheckpointList(*(var0 + 12));
           CheckpointList_Reset(var15);
           CheckpointList_ResizeList(var15, 1);
           var16 = CheckpointList_GetCheckpoint(var15, 0);
           Checkpoint_SetPosition(var16, &var9);
           Checkpoint_SetActivationRadius(var16, 20.0f);
           CheckpointManager_SetActiveCheckpointList(var15);
           var12 = 0;
           while (var12 < var3)
           {
               CheckpointManager_ActivateSingleCheckpoint(var12, 0, 2);
               var12 = var12 + 1;
           }
           sub_12fa(var0);
           RubberBandMgr_SetupRace(*((var0 + 16) + 3100), 0, 0);
           var18 = UIManager_FindMovie("HUDMOVIE");
           sub_13a3(var18);
           UILogic_SetGPSDestination(0, &var9);
           AudioManager_PlayFrontendSound("HUD_CNTDWN_GO_MASTER");
           Racer_HideIcon((*((var0 + 16) + 4))[1 * 48].v0, 0);
           SETTIMERB(0);
           FlashHelper_SetGlobalInt(var18, "PosMax", 2);
           while (!Race_IsFinished(*(var0 + 12)))
           {
               Race_SetRaceData(*(var0 + 12), var0 + 16);
               if (!Racer_IsDamagedOut((*((var0 + 16) + 4))[0 * 48].v0))
               {
                   if (var19)
                   {
                       if ((UILogic_IsPressed(0, 9) && (Form_GetTopMost() == null)) && (!vhsmState_IsActive(UIManager_GetState("GPSScene"))))
                       {
                           Racer_SetInvincible((*((var0 + 16) + 4))[0 * 48].v0, 1);
                           var21 = mcCareerSpeech_FindScenario("GREETING_MEET_ME_THERE");
                           if (var21 != null)
                           {
                               mcCareerSpeech_PlayScenario(var21, Racer_GetVehicleDriverName((*((var0 + 16) + 4))[1 * 48].v0), "PLAYER");
                           }
                           Race_Finish(*(var0 + 12));
                       }
                       else
                       {
                       }
                   }
                   else if (var5 != 14)
                   {
                       var20 = var20 - 1;
                       if (var20 < 0)
                       {
                           var19 = 1;
                           UIManager_QueueDisplay("CANCEL_BEAT_ME_THERE", 10.0f);
                       }
                   }
               }
               Registry_GetValueInt("raceOverTrigger", &var14);
               if (var14 == 1)
               {
                   Race_Finish(*(var0 + 12));
               }
               else
               {
                   var12 = 0;
                   while (var12 < var3)
                   {
                       if ((*((var0 + 16) + 4))[var12 * 48].v8 != 1)
                       {
                           if (!(CheckpointManager_GetWhichHitCheckpoint(var12, (*((var0 + 16) + 4))[var12 * 48].v0) == -1))
                           {
                               CheckpointManager_DeactivateSingleCheckpoint(var12, 0);
                               (*((var0 + 16) + 4))[var12 * 48].v6 = (*((var0 + 16) + 4))[var12 * 48].v6 + 1;
                               (*((var0 + 16) + 4))[var12 * 48].v8 = TIMERB();
                               PRINTSTRING("Racer ");
                               PRINTINT(var12);
                               PRINTSTRING(" Finish time =  ");
                               PRINTINT((*((var0 + 16) + 4))[var12 * 48].v8);
                               PRINTSTRING(" Rank =  ");
                               PRINTINT((*((var0 + 16) + 4))[var12 * 48].v41);
                               if ((*((var0 + 16) + 4))[var12 * 48].v2 == 0)
                               {
                                   Race_Finish(*(var0 + 12));
                               }
                               else
                               {
                                   StringTable_SetString("PLAYER_FINISHED_NAME", Racer_GetName((*((var0 + 16) + 4))[var12 * 48].v0));
                                   SplashManager_Splash(0, 3, "PLAYER_FINISHED", 1.0f, 1, 0);
                                   var13 = 1;
                                   SETTIMERA(0);
                                   PropertyCtrl_SetPropertyBool(var38, 0, 1);
                                   Race_SetTargetTime(*(var0 + 12), *((var0 + 16) + 3148));
                                   Race_SetTimer(*(var0 + 12), 0);
                                   Race_EnableRaceTimer(*(var0 + 12), 1);
                                   Ctrl_SetVisible(var38, 1);
                               }
                           }
                       }
                       (*((var0 + 16) + 4))[var12 * 48].v41 = CheckpointManager_CalculateRankOrdered(var15, var0 + 16, var12, var3);
                       if ((*((var0 + 16) + 4))[var12 * 48].v2 == 0)
                       {
                           FlashHelper_SetGlobalInt(var18, "PosNumber", (*((var0 + 16) + 4))[var12 * 48].v41);
                       }
                       var12 = var12 + 1;
                   }
                   if (var13)
                   {
                       if ((TIMERA() >= *((var0 + 16) + 3148)) && (!Racer_IsDamagedOut((*((var0 + 16) + 4))[0 * 48].v0)))
                       {
                           CheckpointManager_DeactivateSingleCheckpoint(0, 0);
                           CheckpointManager_DeactivateSingleCheckpoint(1, 0);
                           Race_Finish(*(var0 + 12));
                       }
                   }
                   WAITUNWARPED(20);
               }
           }
           UILogic_RemoveGPSDestination(0);
           Race_SetRaceData(*(var0 + 12), var0 + 16);
           Registry_GetValueInt("raceOverTrigger", &var14);
           if (var14 == 0)
           {
               if (!Race_IsDamagedOut(*(var0 + 12)))
               {
                   CheckpointManager_ClearActiveCheckpointList();
                   mcEvent_PostEventRaceResults("BEAT_ME_THERE_RACE_COMPLETE", var0 + 16);
                   sub_18d7(var0, 0, var4, 1);
                   UIManager_SendEvent("raceEndNoMenu");
                   AudioManager_SetActiveEndRace(0, 0);
                   PRINTSTRING("Start Warping\n");
                   Warper_Warp("BEAT_ME_THERE_WITH_CUT");
               }
               else
               {
                   PRINTSTRING("BEAT ME THERE - Damaged out\n");
                   sub_18d7(var0, 0, var4, 1);
                   UIManager_SendEvent("raceEnd");
                   while (var14 == 0)
                   {
                       PRINTSTRING("BEAT ME THERE - Waiting for user to make decision\n");
                       Registry_GetValueInt("raceOverTrigger", &var14);
                       WAITUNWARPED(20);
                   }
                   AudioManager_SetActiveEndRace(0, 0);
               }
           }
           strcpy(&var22, 64, "");
           Registry_GetValueString("raceOverCommand", &var22);
           PRINTSTRING("Beat me there race command: ");
           PRINTSTRING(&var22);
           PRINTSTRING("\n");
           if (StringCaseCompare(&var22, "returnToCruise"))
           {
               PRINTSTRING("Damage out and return to game\n");
           }
           else if (StringCaseCompare(&var22, "quit"))
           {
           }
           else
           {
           }
       }
       PRINTSTRING("Skip beat me there and Start Warping\n");
       Warper_Warp("SKIP_BEAT_ME_THERE_WITH_CUT");
       CheckpointManager_ClearActiveCheckpointList();
       PRINTSTRING("Start Waiting\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       PRINTSTRING("Done Waiting\n");
       CheckpointManager_ClearActiveCheckpointList();
       PRINTSTRING("DELETING ELEMENT 1\n");
       mcHudMapServer_DeleteElement(var17);
       RubberBandMgr_ShutdownRace();
       Ctrl_SetVisible(var38, 0);
       Race_EnableRaceTimer(*(var0 + 12), 0);
       PropertyCtrl_SetPropertyBool(var38, 0, 0);
       return;
   }
}

void sub_d46(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

function sub_dd9(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15;

   var7 = 1;
   var8 = Form_GetForm(var0);
   var9 = Form_GetForm(var1);
   Form_ShowForm(var8, var9);
   if (!StringCompare(var2, ""))
   {
       var10 = mcCareerSpeech_FindScenario(var2);
       if (var10 != null)
       {
           mcCareerSpeech_Stop();
           mcCareerSpeech_PlayScenario(var10, var3, var4);
       }
   }
   while (var7)
   {
       var7 = Form_GetFormVisible(var9);
       WAITUNWARPED(100);
   }
   return Form_GetFormResult(var9);
}

void sub_e8e(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

function sub_11b6(var0)
{
   auto var3;

   return BrainFactory_CreateBrainRacing(Opponent_GetRacer(var0));
}

void sub_12fa(var0)
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

void sub_13a3(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 2);
}

void sub_18d7(var0, var1, var2, var3)
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
                   sub_2513(var28[0], var68);
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

void sub_2513(var0, var1)
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

void sub_2b44(var0)
{
   auto var3, var4, var5;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var4 = Racer_GetUID((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var4 == 0)
       {
           var4 = 5000 + var3;
           while (Racer_FindFromUID(var4) != null)
           {
               var4 = var4 + 1;
               WAITUNWARPED(10);
           }
           Racer_SetUID((*((var0 + 16) + 4))[var3 * 48].v0, var4);
       }
       CineScript_Cars_AssignIdToSlot(var4, var3);
       var3 = var3 + 1;
   }
}

function sub_2bf7(var0, var1, var2)
{
   auto var5, var6, var7;

   if (RaceDescription_UseSafetyCam(var0))
   {
       return CineScript_PickRacestartSafetyCutscene();
   }
   else
   {
       return sub_2c35(RaceDescription_GetRaceGridType(var0), var1, var2, !RaceDescription_AllowRaceStarter(var0), 0);
   }
}

function sub_2c35(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11;

   if (var1 == 0)
   {
       PRINTSTRING("PickRacestartCutsceneOrTauntEnum:  0 opponents, forcing grid-type ");
       PRINTINT(var0);
       PRINTSTRING(" to 0 (1x1)\n");
       var0 = 0;
   }
   return CineScript_PickRacestartCutsceneOrTauntFromGridEnum(var0, var2, var3, var4);
}

void sub_2d47(var0, var1, var2, var3, var4, var5, var6)
{
   auto var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   PRINTSTRING("EvaluatePolice() - police probability: ");
   PRINTFLOAT(var1);
   PRINTSTRING("\n");
   var9 = 0;
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var1 > 0.0f) && (var9 >= 4))
   {
       PRINTSTRING("EvaluatePolice() - number of consecutive no-cop races >= 4, setting police probability to 1.0\n");
       var1 = 1.0f;
   }
   var10 = 0;
   if (GetRaceCopChaseCommandLine(&var10))
   {
       if (var10 == 1)
       {
           if (var1 > 0.0f)
           {
               PRINTSTRING("EvaluatePolice() - racecopchase=1, setting police probability to 1.0\n");
               var1 = 1.0f;
           }
       }
       else
       {
           PRINTSTRING("EvaluatePolice() - racecopchase=0, setting police probability to 0.0\n");
           var1 = 0.0f;
       }
   }
   if (GetDemoCommandLine())
   {
       PRINTSTRING("EvaluatePolice() - demo, setting police probability to 0.0\n");
       var1 = 0.0f;
   }
   var11 = RAND_FLOAT_RANGE(0.0f, 1.0f);
   PRINTSTRING("EvaluatePolice() - random probability: ");
   PRINTFLOAT(var11);
   PRINTSTRING("\n");
   var12 = RaceDescription_GetNumCopZones(var0);
   PRINTSTRING("EvaluatePolice() - number of cop zones: ");
   PRINTINT(var12);
   PRINTSTRING("\n");
   if ((var12 == 0) || (var11 > var1))
   {
       PoliceManager_DestroyAllPolice();
       PRINTSTRING("EvaluatePolice() - police destroyed, not available in race\n");
       if (var1 > 0.0f)
       {
           var9 = var9 + 1;
       }
   }
   else
   {
       sub_30e2();
       var9 = 0;
   }
   PoliceManager_SetChaseProperties(var4, var5, var6);
   PoliceManager_SetRaceChaseTarget(var2, var3);
   Registry_SetValueInt("nNumNoCopRaces", var9);
   PRINTSTRING("EvaluatePolice() - new number of consecutive no-cop races: ");
   Registry_GetValueInt("nNumNoCopRaces", &var9);
   PRINTINT(var9);
   PRINTSTRING("\n");
}

void sub_30e2()
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

void sub_336e(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           PRINTSTRING("SCRIPT: waiting for transition movie to stream in...\n");
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE DOWN REPORT\n");
   PRINTSTRING("================\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var8 == 0) && ((var9 == 0) || ((var7 == 1) && (var9 == 2))))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", var2);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", 0.01f);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 0);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 1);
       if (var0)
       {
           var8 = 1;
           while (var8 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
               if (var8 == 1)
               {
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

void sub_3705(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE UP REPORT\n");
   PRINTSTRING("==============\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var7 == 0) && ((var8 != 0) || (var9 != 0)))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", 0.01f);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", var2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 1);
       if (var0)
       {
           var7 = 1;
           while (var7 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
               if (var7 == 1)
               {
                   PRINTSTRING("SCRIPT: waiting for transition movie transition up...\n");
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

void sub_3b7c(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9;

   var3 = -1;
   var3 = StatsManager_GetIntValue("xLRW", 0);
   if (var3 != 1)
   {
       PRINTSTRING("StatTracking: Previous race was not won... reset consecutive wins stat");
       StatsManager_UpdateStatInt("gCWN", 0, 3, 0);
       StatsManager_UpdateStatInt("kCWN", 0, 3, 0);
   }
   StatsManager_UpdateStatInt("xLRW", 0, 3, 0);
   OpponentManager_CleanupOpponentArray();
   while (!mcRacerManager_AreStreamStatesResolved())
   {
       PRINTSTRING("Waiting for racer stream state resolution.\n");
       if ((Net_IsConnecting() || Net_IsNetworked()) && (!*((var0 + 16) + 3120)))
       {
           return;
       }
       else
       {
           WAITUNWARPED(200);
       }
   }
   Race_Reset(*(var0 + 12));
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   var4 = 1;
   while (var4 == 1)
   {
       mcCareer_AddRaceToHistory(*((var0 + 16) + 0));
       var5 = LookupCity(GetCurrentCity());
       var6 = null;
       if (*((var0 + 16) + 3112) == 0)
       {
           var7 = CityDescription_LookupRaceByIndex(var5, *((var0 + 16) + 0));
           var6 = RaceDescription_GetEasyRaceName(var7);
           if (StringCompare(var6, ""))
           {
               var6 = CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0));
           }
       }
       else
       {
           var6 = CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0));
       }
       PRINTSTRING("Race Name ");
       PRINTSTRING(var6);
       PRINTSTRING("\n");
       var8 = START_NEW_SCRIPT_WITH_ARGS(var6, var0, 802, 3800);
       while (!IsChildFinished(var8))
       {
           WAIT(10);
       }
       Registry_GetValueInt("Script_ReloadRace", &var4);
       Registry_SetValueInt("Script_ReloadRace", 0);
   }
}

void sub_40e4()
{
   auto var2, var3, var4;

   StatsManager_UpdateStatInt("kTRS", 0, 0, 1);
   StatsManager_UpdateStatInt("xRRT", 0, 0, 1);
   var2 = StatsManager_GetIntValue("kTRS", 0);
   var3 = StatsManager_GetIntValue("kRCP", 0);
   var4 = 0.0f;
   if (var3 > 0)
   {
       var4 = TO_FLOAT(var2) / TO_FLOAT(var3);
   }
   StatsManager_UpdateStatFloat("kARS", 0, 3, var4);
}

void sub_430e(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13;

   var7 = Racer_DistanceBetween(var0, var2);
   PRINTSTRING("Opponent Distance = ");
   PRINTFLOAT(var7);
   PRINTSTRING("\n");
   if ((var7 < 500.0f) && (!var4))
   {
       Racer_SetStreamingUnlocked(var2);
       Opponent_ToggleDeleteOnEviction(var1, 1);
       var8 = BrainFactory_CreateBrainCruising(var2);
       sub_438b(var3, var8);
       BrainCruising_SetLooping(var8, 1);
       BrainCruising_DriveToNearestRail(var8);
   }
   else
   {
       OpponentManager_RemoveOpponentFromWorld(var1);
       OpponentManager_DeleteOpponent(var1);
   }
}

function sub_438b(var0, var1)
{
   auto var4, var5, var6, var7, var8;

   switch (var0)
   {
       case 0:
       {
           var4.v0 = -2171.86f;
           var4.v1 = -3.73355f;
           var4.v2 = 38.2942f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2082.38f;
           var4.v1 = -0.150024f;
           var4.v2 = -103.202f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1848.6f;
           var4.v1 = -5.57857f;
           var4.v2 = 181.021f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1889.23f;
           var4.v1 = -4.57721f;
           var4.v2 = 322.555f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2098.78f;
           var4.v1 = 0.623314f;
           var4.v2 = 382.108f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 1:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 2:
       {
           var4.v0 = -529.196f;
           var4.v1 = -8.41289f;
           var4.v2 = 203.315f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -241.864f;
           var4.v1 = -13.1316f;
           var4.v2 = 306.687f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -24.9188f;
           var4.v1 = -8.92001f;
           var4.v2 = 127.65f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -134.135f;
           var4.v1 = 18.2821f;
           var4.v2 = -9.99714f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -502.507f;
           var4.v1 = -1.23221f;
           var4.v2 = -3.32185f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -593.266f;
           var4.v1 = -5.1629f;
           var4.v2 = 79.92f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 3:
       {
           var4.v0 = 364.965f;
           var4.v1 = -4.43402f;
           var4.v2 = 120.526f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 366.118f;
           var4.v1 = -11.8294f;
           var4.v2 = 326.516f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 568.537f;
           var4.v1 = -13.1919f;
           var4.v2 = 359.886f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 778.476f;
           var4.v1 = -10.1129f;
           var4.v2 = 213.564f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 772.173f;
           var4.v1 = -4.87628f;
           var4.v2 = 26.1546f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 697.668f;
           var4.v1 = 1.48578f;
           var4.v2 = -89.3486f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 492.799f;
           var4.v1 = 2.23468f;
           var4.v2 = -31.1908f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 4:
       {
           var4.v0 = 1132.48f;
           var4.v1 = 19.5945f;
           var4.v2 = -995.254f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1181.5f;
           var4.v1 = 14.85f;
           var4.v2 = -668.24f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.25f;
           var4.v1 = 14.85f;
           var4.v2 = -587.388f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 886.057f;
           var4.v1 = 14.8471f;
           var4.v2 = -666.398f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.84f;
           var4.v1 = 19.0699f;
           var4.v2 = -984.565f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 5:
       {
           var4.v0 = 1930.96f;
           var4.v1 = -7.88059f;
           var4.v2 = 519.85f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1974.67f;
           var4.v1 = -5.14804f;
           var4.v2 = 317.939f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2161.5f;
           var4.v1 = -3.14887f;
           var4.v2 = -3.44634f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2279.15f;
           var4.v1 = -5.8414f;
           var4.v2 = -37.9429f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2287.03f;
           var4.v1 = -10.1456f;
           var4.v2 = 150.248f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2089.7f;
           var4.v1 = -10.1458f;
           var4.v2 = 494.101f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 6:
       {
           var4.v0 = 2337.39f;
           var4.v1 = -0.149963f;
           var4.v2 = -661.406f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2278.43f;
           var4.v1 = 1.57553f;
           var4.v2 = -911.264f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2154.28f;
           var4.v1 = 5.34701f;
           var4.v2 = -921.462f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2065.79f;
           var4.v1 = 6.84834f;
           var4.v2 = -679.637f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2196.87f;
           var4.v1 = 4.55591f;
           var4.v2 = -512.556f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       default:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
   }
}

