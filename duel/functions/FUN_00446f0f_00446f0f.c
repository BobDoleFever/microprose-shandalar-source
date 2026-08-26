/*
 * Decompiled function: FUN_00446f0f
 * Entry Point: 00446f0f
 * Size: 114 bytes
 */
#include "duel.h"


uint FUN_00446f0f(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uVar2 = *(uint *)(&DAT_0060166c + arg1 * 0x5b20 + arg2 * 0x120) & 0xff;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


