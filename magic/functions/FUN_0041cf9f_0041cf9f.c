/*
 * Decompiled function: FUN_0041cf9f
 * Entry Point: 0041cf9f
 * Size: 117 bytes
 */
#include "magic.h"


undefined4 FUN_0041cf9f(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == g_CurrentTurnPhase) {
      uVar1 = 1;
    }
    else {
      uVar1 = *(undefined4 *)(&DAT_006b3028 + arg_1 * 4);
    }
  }
  else {
    if (arg_3 == 0x71) {
      (&g_PlayerCreatureCount)[arg_1] =
           (&g_PlayerCreatureCount)[arg_1] + *(int *)(&DAT_006b3028 + arg_1 * 4) * 2;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


