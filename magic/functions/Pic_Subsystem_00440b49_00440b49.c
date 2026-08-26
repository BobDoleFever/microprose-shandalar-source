/*
 * Decompiled function: Pic_Subsystem_00440b49
 * Entry Point: 00440b49
 * Size: 620 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00440b49(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
      if (iVar2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e54 + g_ActivePlayerPriority * 0x20) -
             *(int *)(&DAT_006b2e54 + g_CurrentTurnPhase * 0x20)) * 0xc;
      }
    }
    if (arg_3 == 0x71) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 5;
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == arg_2)) &&
       ((g_OverworldPlayerCoordX == arg_1 &&
        ((g_DefendingPlayer == arg_1 && (g_DefendingPlayer == DAT_0063edc0)))))) {
      *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006a604d)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006a604d)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) {
      iVar2 = FUN_00471c32(arg_1,arg_2);
      if (iVar2 != 0) {
        iVar2 = FUN_00471c32(g_OverworldPlayerCoordX,g_OverworldMapGrid);
        if (iVar2 != 0) {
          iVar2 = FUN_0041d963(arg_1,arg_2,4);
          if (*(int *)(&DAT_006ff2bc + iVar2 * 4) ==
              *(int *)(&g_MasterCardTypeTable + g_ActivePalette * 0x34)) {
            iVar2 = FUN_0041d963(arg_1,arg_2,
                                 *(int *)(&g_CardSlot_ConvertedManaCost +
                                         arg_2 * 0x120 + arg_1 * 0x5b20));
            g_ActivePalette = iVar2 + -1;
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


