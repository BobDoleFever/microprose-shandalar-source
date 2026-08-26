/*
 * Decompiled function: Ai_Subsystem_004b6ba8
 * Entry Point: 004b6ba8
 * Size: 179 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b6ba8(int arg_1,int arg_2,void *arg_3)

{
  int iVar1;
  
  iVar1 = Ai_Subsystem_004b5919(arg_1,arg_2);
  if (iVar1 == 0) {
    if (arg_3 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      iVar1 = (int)(char)(&DAT_0068a828)[arg_1 * 0x5b20 + arg_2 * 0x120];
      memcpy(arg_3,(void *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x68a788),0xa0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


