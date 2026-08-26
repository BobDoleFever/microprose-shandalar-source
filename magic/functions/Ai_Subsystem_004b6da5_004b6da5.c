/*
 * Decompiled function: Ai_Subsystem_004b6da5
 * Entry Point: 004b6da5
 * Size: 150 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b6da5(undefined4 *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  iVar1 = Ai_Subsystem_004b5919(arg_2,arg_3);
  if ((iVar1 == 0) && (arg_1 != (undefined4 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg_1 = *(undefined4 *)(&DAT_0068a820 + arg_3 * 0x120 + arg_2 * 0x5b20);
    arg_1[1] = *(undefined4 *)(&DAT_0068a824 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}


