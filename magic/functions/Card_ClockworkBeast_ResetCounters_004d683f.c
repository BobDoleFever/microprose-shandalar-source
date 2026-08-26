/*
 * Decompiled function: Card_ClockworkBeast_ResetCounters
 * Entry Point: 004d683f
 * Size: 661 bytes
 */
#include "magic.h"


undefined4 Card_ClockworkBeast_ResetCounters(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    cVar2 = FUN_0041d9d2(arg_1,arg_2,1);
    g_ActivePalette = g_ActivePalette | 0x800 << (cVar2 - 1U & 0x1f);
    uVar1 = g_ActivePalette;
    Card_RockHydra_UpdateStatsFromHeads(arg_1,arg_2,1);
    g_ActivePalette = uVar1;
  }
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        == DAT_006ff2e0)) &&
      ((*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == -1 &&
       (((char)(&g_CardSlot_DamageReceived)
               [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1 &&
        (*(int *)(&g_CardSlot_TypeFlags +
                 g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2)))))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
  }
  if (((((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) != 0)))) &&
     (arg_1 == DAT_006a4b5c)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Card_IncrementCounter(arg_1,arg_2);
      *(short *)(&DAT_006a5f48 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(short *)(&DAT_006a5f48 + arg_1 * 0x5b20 + arg_2 * 0x120) + 1;
      *(short *)(&DAT_006a5f4a + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(short *)(&DAT_006a5f4a + arg_1 * 0x5b20 + arg_2 * 0x120) + 1;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
  }
  return 0;
}


