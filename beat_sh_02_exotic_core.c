void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66;

   var2.v0 = -2649.97f;
   var2.v1 = -3.81f;
   var2.v2 = 33.44f;
   mcTargetManager_RegisterLocation(604, &var2);
   mcTargetManager_HideTarget(604, 0);
   var5 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetElement(var5, 9, 604, &var2, (float)0);
   mcHudMapServer_AddElement(var5);
   var6 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   var7.v0 = -2649.97f;
   var7.v1 = -4.81f;
   var7.v2 = 33.44f;
   var10 = 268.96f;
   var12.v2.v0.v0 = 0.0f;
   var12.v2.v0.v1 = 0.0f;
   var12.v2.v0.v2 = 0.0f;
   var12.v2.v3 = 0.0f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var7, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var18 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var18, var6, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var18, mcHookman_GetModValue(L[0].v0.v97.v0));
   Racer_SetVehicleDriverEnable(var18, 0);
   Racer_SetHeadlights(var18, 0);
   Racer_SetExhaust(var18, 0);
   Racer_InitializeResetPosition(var18, &var7, var10);
   Racer_Reset(var18);
   Racer_Deactivate(var18);
   var19 = sub_19f(0);
   L[0].v0.v97.v2 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 10, var18);
   Racer_SetIconType(var18, 16);
   var20 = sub_218(var18);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, var20);
   Racer_SetIconColorByDifficulty(var18, var20);
   Racer_HideIcon(var18, 1);
   var21 = mcMissionManager_GetMission("BEAT_SH_02_EXOTIC");
   var22 = UIManager_GetState("Cruising_Offline");
   var23 = 0.0f;
   var24 = 0;
   var25 = 0;
   var26 = 0;
   var27 = null;
   var28 = Form_GetForm(71);
   var29.v0 = -2610.084f;
   var29.v1 = -4.679f;
   var29.v2 = -58.149f;
   var32.v0 = -2609.291f;
   var32.v1 = -1.315f;
   var32.v2 = -59.014f;
   var35.v0 = -2617.369f;
   var35.v1 = -0.878f;
   var35.v2 = -50.052f;
   var38 = 6;
   var45 = 6;
   var52 = 6;
   var59 = 6;
   var38[0] = "character/ped_mb_004_set";
   var45[0] = "ped_mb_004_set";
   var52[0] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[0] = "m_ped00_loop";
   var38[1] = "character/ped_mh_002_set";
   var45[1] = "ped_mh_002_set";
   var52[1] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[1] = "m_ped01_loop";
   var38[2] = "character/ped_mh_003_set";
   var45[2] = "ped_mh_003_set";
   var52[2] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[2] = "m_ped02_loop";
   var38[3] = "character/ped_mc_004_set";
   var45[3] = "ped_mc_004_set";
   var52[3] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[3] = "m_ped03_loop";
   var38[4] = "character/ped_fc_002_set";
   var45[4] = "ped_fc_002_set";
   var52[4] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[4] = "f_ped01_loop";
   var38[5] = "character/ped_fc_003_set";
   var45[5] = "ped_fc_003_set";
   var52[5] = "cutscene/hangout/cut_story_beat_sh_02_exotic_peds";
   var59[5] = "f_ped02_loop";
   var66 = 0;
   while (!var66)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var26);
       if (var26 == 1)
       {
           mcHudMapServer_RemoveElement(var5);
           Racer_SetStreamingLockedOut(var18);
           while (var26 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var26);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var18);
           var20 = sub_218(var18);
           mcHookman_SetDifficulty(L[0].v0.v97.v0, var20);
           Racer_SetIconColorByDifficulty(var18, var20);
           mcHudMapServer_AddElement(var5);
       }
       var24 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var24 == 1)
       {
           while (var24 == 1)
           {
               var24 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var24 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           if (vhsmState_IsListener(var22) && (!Game_IsPaused()))
           {
               if ((var25 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
               {
                   var25 = var25 - 1;
               }
               var23 = Racer_DistanceToPoint(var19, &var2);
               if ((!Game_IsPaused()) && (var23 < 30.0f))
               {
                   if (PoliceManager_CheckPoliceActivity(1) > 1)
                   {
                       if (var25 == 0)
                       {
                           SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                           var25 = 100;
                       }
                       WAITUNWARPED(100);
                   }
                   else
                   {
                       if (Racer_GetVehicleClass(var19) != 2)
                       {
                           sub_8d1(var28, "BESTOF_SH_02_EXOTIC_RESTRICTION", "VEHICLE_TYPE_RESTRICTION", 1, 1);
                           var23 = 0.0f;
                           while (var23 < 35.0f)
                           {
                               WAITUNWARPED(1000);
                               var23 = Racer_DistanceToPoint(var19, &var2);
                           }
                       }
                       else
                       {
                           Warper_SetIsWarpingToCutscene(1);
                           mcRequirement_Satisfy(mcMission_GetObjective(var21, 0), 1);
                           mcRequirement_AlwaysHide(mcMission_GetObjective(var21, 1), 0);
                           mcRequirement_Hide(mcMission_GetObjective(var21, 1), 0);
                           mcHudMapServer_RemoveElement(var5);
                           mcHookman_SetState(L[0].v0.v97.v0, 1);
                           Racer_Deactivate(var19);
                           CineScript_SetGameCoordSysBinding(&var12);
                           sub_9c9(var19, 0);
                           sub_9c9(var18, 1);
                           sub_a60(6, &var38, &var45, &var52, &var59);
                           Warper_Warp("BEAT_ME_THERE_WITH_CUT");
                           while (!Warper_IsReadyToLoadStuff())
                           {
                               WAITUNWARPED(100);
                               PRINTSTRING("Waiting For Camera To Get To Safe Spot\n");
                           }
                           PostProcessing_SetCutsceneDof();
                           var11 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_beat_sh_02_exotic_generated", &null, 0, 0);
                           while (!CineScript_IsScenePlaying())
                           {
                               WAITUNWARPED(100);
                           }
                           Warper_SetIsWarpingToCutscene(1);
                           while (!IsChildFinished(var11))
                           {
                               WAITUNWARPED(100);
                           }
                           PostProcessing_SetGameDof();
                           sub_dd6(&var52);
                           mcMission_ChangeState(var21, 3, 0);
                           Racer_Activate(var19);
                           Racer_SetVehicleDriverEnable(var18, 1);
                           Racer_SetExhaust(var18, 1);
                           mcHudMapServer_RemoveElement(var5);
                           mcHudMapServer_AddElement(L[0].v0.v97.v2);
                           sub_e73(L[0].v0.v97.v1, var19, mcHookman_GetDifficulty(L[0].v0.v97.v0));
                           mcHudMapServer_RemoveElement(L[0].v0.v97.v2);
                           if (mcMission_GetState(var21) == 5)
                           {
                               mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                           }
                           else
                           {
                               mcRequirement_Satisfy(mcMission_GetObjective(var21, 0), 0);
                               mcRequirement_AlwaysHide(mcMission_GetObjective(var21, 1), 1);
                               mcRequirement_Hide(mcMission_GetObjective(var21, 1), 1);
                               mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                               Racer_SetVehicleDriverEnable(var18, 0);
                               Racer_SetExhaust(var18, 0);
                               Racer_InitializeResetPosition(var18, &var7, var10);
                               Racer_Reset(var18);
                               Racer_Deactivate(var18);
                               mcHudMapServer_AddElement(var5);
                           }
                       }
                       mcHookman_SetState(L[0].v0.v97.v0, 3);
                   }
               }
           }
           WAITUNWARPED(30);
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var6);
   PRINTSTRING("\n");
   Racer_HideIcon(var18, 1);
   mcTargetManager_HideTarget(604, 1);
   mcTargetManager_UnRegisterTarget(var6);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   mcHudMapServer_DeleteElement(var5);
   var27 = BrainFactory_CreateBrainCruising(var18);
   sub_13a5(RAND_INT_RANGE(0, 7), var27);
   BrainCruising_SetLooping(var27, 1);
   BrainCruising_DriveToNearestRail(var27);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var6);
   PRINTSTRING(" deleted.\n");
}

function sub_19f(var0)
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

function sub_218(var0)
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

function sub_8d1(var0, var1, var2, var3, var4)
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

void sub_9c9(var0, var1)
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

void sub_a60(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;

   var8 = 0;
   while (!var8)
   {
       var8 = 1;
       var7 = 0;
       while (var7 < var0)
       {
           var8 = var8 && CineScript_Characters_LoadType((*var1)[var7], (*var2)[var7]);
           var7 = var7 + 1;
       }
       WAITUNWARPED(100);
       PRINTSTRING("LoadHangoutCharacters : Streaming characters\n");
   }
   PRINTSTRING("LoadHangoutCharacters : Streaming characters load complete.\n");
   var9 = CineScript_DoesAnimPackExist((*var3)[0]);
   if (var9)
   {
       var10 = (*var3)[0];
       PRINTSTRING("Using Hangout Animpack:  ");
       PRINTSTRING(var10);
       PRINTNL();
       CineScript_StartLoadHangoutAnimPack(var10);
       while (!CineScript_IsLoadedHangoutAnimPack())
       {
           WAITUNWARPED(100);
           PRINTSTRING("LoadHangoutCharacters : Streaming animpack\n");
       }
       PRINTSTRING("LoadHangoutCharacters : Streaming animpack load complete.\n");
       var8 = var8 && 1;
   }
   else
   {
       var7 = 0;
       while (var7 < var0)
       {
           CineScript_Characters_LoadAnimation((*var3)[var7], (*var4)[var7]);
           var7 = var7 + 1;
       }
   }
   var7 = 0;
   while (var7 < var0)
   {
       var15 = CineScript_Characters_LaunchAnimAt((*var1)[var7], (*var2)[var7], (*var3)[var7], (*var4)[var7], &var11, -1);
       CineScript_PushKillBuffer(var15, 0);
       var7 = var7 + 1;
   }
}

void sub_dd6(var0)
{
   auto var3, var4;

   CineScript_PopKillBuffer(0);
   var3 = CineScript_DoesAnimPackExist((*var0)[0]);
   if (var3)
   {
       CineScript_ReleaseHangoutAnimPack();
   }
}

void sub_e73(var0, var1, var2)
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
   var5.v802 = "BEAT_SH_02_EXOTIC_SERIES";
   var5.v803 = 3;
   var5.v813 = 2;
   var5.v804[0] = "game/Race/Beaches/Ordered/be_ordered_mb_04";
   var5.v804[1] = "game/Race/Beaches/Ordered/be_ordered_mb_01";
   var5.v804[2] = "game/Race/Beaches/Ordered/be_ordered_mg_02";
   var5.v0.v4.v770 = 2;
   var5.v0.v4.v771 = 0;
   var5.v0.v4.v775 = var2;
   var5.v0.v4.v1[0 * 48].v0 = var1;
   var5.v0.v4.v1[0 * 48].v2 = 0;
   var5.v0.v4.v1[0 * 48].v5 = 1;
   var5.v0.v4.v1[1 * 48].v0 = Opponent_GetRacer(var0);
   var5.v0.v4.v1[1 * 48].v2 = 2;
   var5.v0.v4.v1[1 * 48].v5 = 1;
   Racer_SetStreamingLockedIn(var5.v0.v4.v1[1 * 48].v0);
   var5.v0.v4.v780 = 0;
   var5.v0.v4.v784 = 1;
   var5.v0.v4.v776 = 15;
   var5.v0.v4.v777 = 31;
   var5.v818 = "TAUNT_PRE_BEAT_SH_02_EXOTIC";
   sub_11a3(&var5);
   Racer_SetStreamingUnlocked(var5.v0.v4.v1[1 * 48].v0);
}

void sub_11a3(var0)
{
   auto var3, var4;

   var3 = START_NEW_SCRIPT_WITH_ARGS("Game/Race/OrderedSeriesCore", var0, 820, 1500);
   while (!IsChildFinished(var3))
   {
       WAITUNWARPED(10);
   }
}

function sub_13a5(var0, var1)
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

