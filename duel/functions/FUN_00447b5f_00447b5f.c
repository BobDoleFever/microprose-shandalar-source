/*
 * Decompiled function: FUN_00447b5f
 * Entry Point: 00447b5f
 * Size: 168 bytes
 */
#include "duel.h"


bool FUN_00447b5f(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = FUN_00447114(arg1,arg2);
    if (iVar1 == -1) {
      bVar2 = false;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      bVar2 = ((&DAT_00601658)[arg1 * 0x5b20 + arg2 * 0x120] & 6) != 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


