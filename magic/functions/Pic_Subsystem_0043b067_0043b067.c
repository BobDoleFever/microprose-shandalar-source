/*
 * Decompiled function: Pic_Subsystem_0043b067
 * Entry Point: 0043b067
 * Size: 368 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043b067(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    uVar1 = FUN_0040dcca(arg_1,arg_2,1,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0040dcca(arg_1,arg_2,1,1);
      if (iVar2 != 0) {
        Ai_Subsystem_004be192(arg_1,arg_2,1,1);
      }
    }
    if (arg_3 == 0x72) {
      Mem_AllocOrFree_0041df33(1 - arg_1,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      Mem_AllocOrFree_0041df33(arg_1,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      CardQuery_ForEachPermanent(Pic_Subsystem_0043b1d7,-1);
    }
    if ((((g_PlayerManaPool == 0xcd) && (g_OverworldMapGrid == arg_2)) &&
        (g_OverworldPlayerCoordX == arg_1)) && (DAT_006a4b5c == arg_1)) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (arg_3 == 0x7e) {
        iVar2 = CardQuery_PlayerControlsColor(arg_1,2);
        if (iVar2 == 0) {
          iVar2 = CardQuery_PlayerControlsColor(1 - arg_1,2);
          if (iVar2 == 0) {
            Pic_Subsystem_0044867e(arg_1,arg_2,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


