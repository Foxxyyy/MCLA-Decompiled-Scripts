void main()
{
   auto var2;

   L[0].v0.v94 = 7;
   L[0].v0.v95 = 152.86f;
   L[0].v0.v100 = 0;
   L[0].v0.v0[0 * 3].v0 = -2681.72f;
   L[0].v0.v0[0 * 3].v1 = -24.2261f;
   L[0].v0.v0[0 * 3].v2 = -1004.79f;
   L[0].v0.v0[1 * 3].v0 = -2498.29f;
   L[0].v0.v0[1 * 3].v1 = -3.824f;
   L[0].v0.v0[1 * 3].v2 = -908.533f;
   L[0].v0.v0[2 * 3].v0 = -2598.83f;
   L[0].v0.v0[2 * 3].v1 = -1.21014f;
   L[0].v0.v0[2 * 3].v2 = -714.337f;
   L[0].v0.v0[3 * 3].v0 = -2579.52f;
   L[0].v0.v0[3 * 3].v1 = 0.205994f;
   L[0].v0.v0[3 * 3].v2 = -505.826f;
   L[0].v0.v0[4 * 3].v0 = -2724.73f;
   L[0].v0.v0[4 * 3].v1 = -3.30025f;
   L[0].v0.v0[4 * 3].v2 = -390.234f;
   L[0].v0.v0[5 * 3].v0 = -2847.21f;
   L[0].v0.v0[5 * 3].v1 = -6.87077f;
   L[0].v0.v0[5 * 3].v2 = -483.492f;
   L[0].v0.v0[6 * 3].v0 = -2751.46f;
   L[0].v0.v0[6 * 3].v1 = -29.7891f;
   L[0].v0.v0[6 * 3].v2 = -859.794f;
   var2 = START_NEW_SCRIPT_WITH_ARGS(mcHookman_GetCoreScriptName(L[0].v0.v97.v0), &L[0], 103, 1500);
   while (!IsChildFinished(var2))
   {
       WAITUNWARPED(100);
   }
}
