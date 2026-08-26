/*
 * Decompiled function: FUN_004476e3
 * Entry Point: 004476e3
 * Size: 110 bytes
 */
#include "duel.h"


int FUN_004476e3(int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    iVar1 = (int)*(short *)(&DAT_00601636 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


