/*
 * Decompiled function: FUN_00446f81
 * Entry Point: 00446f81
 * Size: 183 bytes
 */
#include "duel.h"


void FUN_00446f81(int arg_1,int arg_2,uint *arg_3,uint *arg_4,uint *arg_5)

{
  int iVar1;
  
  iVar1 = FUN_00446de2(arg_1,arg_2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_3 = (uint)(byte)(&DAT_0060166d)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *arg_4 = (*(uint *)(&DAT_0060166c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) >> 0x10;
    *arg_5 = *(uint *)(&DAT_0060166c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 0x18;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}


