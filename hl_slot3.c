void main()
{
   auto var2;

   L[0].v0.v94 = 7;
   L[0].v0.v95 = (float)269;
   L[0].v0.v100 = 0;
   L[0].v0.v0[0 * 3].v0 = -1200.35f;
   L[0].v0.v0[0 * 3].v1 = 29.845f;
   L[0].v0.v0[0 * 3].v2 = -1976.91f;
   L[0].v0.v0[1 * 3].v0 = -766.665f;
   L[0].v0.v0[1 * 3].v1 = 32.722f;
   L[0].v0.v0[1 * 3].v2 = -1755.45f;
   L[0].v0.v0[2 * 3].v0 = -587.996f;
   L[0].v0.v0[2 * 3].v1 = 38.0547f;
   L[0].v0.v0[2 * 3].v2 = -1850.2f;
   L[0].v0.v0[3 * 3].v0 = -677.379f;
   L[0].v0.v0[3 * 3].v1 = 38.0332f;
   L[0].v0.v0[3 * 3].v2 = -2024.43f;
   L[0].v0.v0[4 * 3].v0 = -946.327f;
   L[0].v0.v0[4 * 3].v1 = 37.0183f;
   L[0].v0.v0[4 * 3].v2 = -2136.65f;
   L[0].v0.v0[5 * 3].v0 = -1277.53f;
   L[0].v0.v0[5 * 3].v1 = 34.6781f;
   L[0].v0.v0[5 * 3].v2 = -2276.39f;
   L[0].v0.v0[6 * 3].v0 = -1433.29f;
   L[0].v0.v0[6 * 3].v1 = 29.7817f;
   L[0].v0.v0[6 * 3].v2 = -2125.36f;
   var2 = START_NEW_SCRIPT_WITH_ARGS(mcHookman_GetCoreScriptName(L[0].v0.v97.v0), &L[0], 103, 1500);
   while (!IsChildFinished(var2))
   {
       WAITUNWARPED(100);
   }
}

