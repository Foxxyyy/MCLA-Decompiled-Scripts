void main()
{
   auto var2;

   PRINTSTRING("Script: Starting an EditorRace...\n");
   PRINTSTRING("Script: Assuming type is Ordered Ordered (Traditional) for EditorRace...\n");
   L[0].v4.v772 = 1;
   L[0].v4.v773 = 1;
   L[0].v4.v774 = 1;
   L[0].v4.v785 = 1;
   L[0].v799 = "Game/RaceTypes/generic_countdown";
   PRINTSTRING("Script: Populating checkpoint list...\n");
   Net_EditorRaceCreateCheckpoints(L[0].v3);
   PRINTSTRING("Script: Populating checkpoint list...\n");
   Net_EditorPopulateGrid(L[0].v3, 0);
   Race_SetRaceData(L[0].v3, &(L[0].v4));
   var2 = START_NEW_SCRIPT_WITH_ARGS("game/racetypes/OrderedCheckpointCore", &L[0], 802, 0);
   while (!IsChildFinished(var2))
   {
       WAIT(100);
   }
   PRINTSTRING("Script: Finished an EditorRace...\n");
}

