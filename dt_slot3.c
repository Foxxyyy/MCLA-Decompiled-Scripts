void main()
{
   auto var2;

   L[0].v0.v94 = 8;
   L[0].v0.v95 = 0.281f;
   L[0].v0.v100 = 0;
   L[0].v0.v0[0 * 3].v0 = 1992.69f;
   L[0].v0.v0[0 * 3].v1 = 6.849f;
   L[0].v0.v0[0 * 3].v2 = -512.091f;
   L[0].v0.v0[1 * 3].v0 = 2101.2f;
   L[0].v0.v0[1 * 3].v1 = 5.94235f;
   L[0].v0.v0[1 * 3].v2 = -423.966f;
   L[0].v0.v0[2 * 3].v0 = 1889.42f;
   L[0].v0.v0[2 * 3].v1 = 0.30545f;
   L[0].v0.v0[2 * 3].v2 = 45.3152f;
   L[0].v0.v0[3 * 3].v0 = 1792.26f;
   L[0].v0.v0[3 * 3].v1 = -3.14844f;
   L[0].v0.v0[3 * 3].v2 = 215.889f;
   L[0].v0.v0[4 * 3].v0 = 1670.88f;
   L[0].v0.v0[4 * 3].v1 = -3.14893f;
   L[0].v0.v0[4 * 3].v2 = 246.23f;
   L[0].v0.v0[5 * 3].v0 = 1640.5f;
   L[0].v0.v0[5 * 3].v1 = -3.14922f;
   L[0].v0.v0[5 * 3].v2 = 117.81f;
   L[0].v0.v0[6 * 3].v0 = 1829.25f;
   L[0].v0.v0[6 * 3].v1 = -3.1488f;
   L[0].v0.v0[6 * 3].v2 = -203.135f;
   L[0].v0.v0[7 * 3].v0 = 1880.29f;
   L[0].v0.v0[7 * 3].v1 = 2.4071f;
   L[0].v0.v0[7 * 3].v2 = -425.857f;
   var2 = START_NEW_SCRIPT_WITH_ARGS(mcHookman_GetCoreScriptName(L[0].v0.v97.v0), &L[0], 103, 1500);
   while (!IsChildFinished(var2))
   {
       WAITUNWARPED(100);
   }
}
