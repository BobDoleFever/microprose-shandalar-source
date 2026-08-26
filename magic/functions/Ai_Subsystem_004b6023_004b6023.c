/*
 * Decompiled function: Ai_Subsystem_004b6023
 * Entry Point: 004b6023
 * Size: 280 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b6023(int *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg_2,arg_3);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_0068a743)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0068a75c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uVar2 = *(undefined4 *)(&DAT_0068a774 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_0068a743)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0068a75c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


