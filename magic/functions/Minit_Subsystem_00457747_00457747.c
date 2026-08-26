/*
 * Decompiled function: Minit_Subsystem_00457747
 * Entry Point: 00457747
 * Size: 562 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00457747(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    if (((&DAT_006a5f3d)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    iVar1 = (&DAT_006b3008)[local_c] + -4;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      if (local_c == 0) {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
      }
      else {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
      }
    }
  }
  if ((((g_PlayerManaPool == 0xcb) && (arg_2 == g_OverworldMapGrid)) &&
      (arg_1 == g_OverworldPlayerCoordX)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    if ((local_c == g_DefendingPlayer) && (4 < (int)(&DAT_006b3008)[local_c])) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_0041df33(local_c,(&DAT_006b3008)[local_c] + -4,arg_1,arg_2);
      }
    }
  }
  return 0;
}


