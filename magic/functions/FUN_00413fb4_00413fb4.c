/*
 * Decompiled function: FUN_00413fb4
 * Entry Point: 00413fb4
 * Size: 700 bytes
 */
#include "magic.h"


undefined4 FUN_00413fb4(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid))
     && ((((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)) &&
         (*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)))) {
    g_ActivePalette = *(uint *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint *)(&g_CardSlot_Abilities1 +
             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 0x40;
  }
  if (((g_PlayerManaPool == 0xc9) || (arg_3 == 199)) &&
     ((g_OverworldMapGrid == arg_2 &&
      (((g_OverworldPlayerCoordX == arg_1 && (g_DefendingPlayer == arg_1)) &&
       (DAT_006a4b5c == arg_1)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(undefined4 *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      *(uint *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) |
           0x1000000;
      FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x3c,
                   0xffffffff);
      Ai_Subsystem_004cced8();
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


