/*
 * Decompiled function: FUN_00485605
 * Entry Point: 00485605
 * Size: 168 bytes
 */
#include "magic.h"


int FUN_00485605(int arg_1,char *str_2,int arg_3)

{
  int iVar1;
  
  if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
    iVar1 = FUN_0040c465(str_2);
    iVar1 = iVar1 + 0x10;
    if (0x10 < iVar1) {
      Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_00522458 / 2 - iVar1 / 2,0x5a,iVar1,0x14,
                       0xff);
      FUN_0040c3cc(str_2,DAT_00522458 / 2,0x5c,0);
    }
    iVar1 = FUN_0048ac2f();
    arg_3 = iVar1 + -0x30;
  }
  return arg_3;
}


