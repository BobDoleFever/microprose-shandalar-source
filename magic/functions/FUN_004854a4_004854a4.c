/*
 * Decompiled function: FUN_004854a4
 * Entry Point: 004854a4
 * Size: 353 bytes
 */
#include "magic.h"


int FUN_004854a4(int arg_1,char *str_2,int arg_3)

{
  int iVar1;
  
  if (g_IsAiThinking != 1) {
    if (g_CurrentTurnPhase == arg_1) {
      iVar1 = FUN_0040c465(str_2);
      iVar1 = iVar1 + 0x10;
      if (0x10 < iVar1) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_00522458 / 2 - iVar1 / 2,0x5a,iVar1,0x14,
                         0xff);
        FUN_0040c3cc(str_2,DAT_00522458 / 2,0x5c,0);
        FUN_0040c3cc(&DAT_005270e0,DAT_00522458 / 2,100,0);
      }
      do {
        iVar1 = FUN_0048ac2f();
        if (iVar1 == 0x79) {
          return 1;
        }
      } while (iVar1 != 0x6e);
      arg_3 = 0;
    }
    else {
      strcpy(&g_OverworldWorldState,s__YES__005270d0 + ((arg_3 != 0) - 1 & 8));
      FUN_0040c3cc(&g_OverworldWorldState,DAT_00522458 / 2,7,0xd8);
      FUN_0040c3cc(&g_OverworldWorldState,DAT_00522458 / 2,6,0xdc);
      FUN_00501736(0x78);
    }
  }
  return arg_3;
}


