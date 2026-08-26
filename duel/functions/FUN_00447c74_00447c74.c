/*
 * Decompiled function: FUN_00447c74
 * Entry Point: 00447c74
 * Size: 132 bytes
 */
#include "duel.h"


bool FUN_00447c74(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    bVar2 = ((&DAT_0060162e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


