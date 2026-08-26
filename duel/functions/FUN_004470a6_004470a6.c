/*
 * Decompiled function: FUN_004470a6
 * Entry Point: 004470a6
 * Size: 110 bytes
 */
#include "duel.h"


int FUN_004470a6(int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    iVar1 = (int)*(short *)(&DAT_00601630 + arg1 * 0x5b20 + arg2 * 0x120);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


