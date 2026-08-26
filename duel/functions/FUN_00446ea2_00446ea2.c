/*
 * Decompiled function: FUN_00446ea2
 * Entry Point: 00446ea2
 * Size: 109 bytes
 */
#include "duel.h"


undefined4 FUN_00446ea2(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uVar2 = *(undefined4 *)(&DAT_00601644 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


