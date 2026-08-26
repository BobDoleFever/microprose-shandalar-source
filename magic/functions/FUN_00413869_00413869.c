/*
 * Decompiled function: FUN_00413869
 * Entry Point: 00413869
 * Size: 457 bytes
 */
#include "magic.h"


undefined4 FUN_00413869(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x22) && (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20));
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
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
  }
  if ((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid))
     && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) {
    g_ActivePalette = *(undefined4 *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return 0;
}


