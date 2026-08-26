/*
 * Decompiled function: Ai_Subsystem_004b5ab8
 * Entry Point: 004b5ab8
 * Size: 183 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b5ab8(int arg_1,int arg_2,uint *arg_3,uint *arg_4,uint *arg_5)

{
  int iVar1;
  
  iVar1 = Ai_Subsystem_004b5919(arg_1,arg_2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg_3 = (uint)(byte)(&DAT_0068a77d)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *arg_4 = (*(uint *)(&DAT_0068a77c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) >> 0x10;
    *arg_5 = *(uint *)(&DAT_0068a77c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 0x18;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}


