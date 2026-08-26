/*
 * Decompiled function: FUN_00446e30
 * Entry Point: 00446e30
 * Size: 114 bytes
 */
#include "duel.h"


uint FUN_00446e30(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uVar2 = *(uint *)(&DAT_00601658 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


