/*
 * Decompiled function: Ai_Subsystem_004b5f74
 * Entry Point: 004b5f74
 * Size: 175 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b5f74(int *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_1 != (int *)0x0) {
    iVar1 = Ai_Subsystem_004b5919(arg_2,arg_3);
    if (iVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      *arg_1 = (int)(char)(&DAT_0068a742)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0068a758 + arg_3 * 0x120 + arg_2 * 0x5b20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      *arg_1 = -1;
      arg_1[1] = -1;
    }
  }
  return;
}


