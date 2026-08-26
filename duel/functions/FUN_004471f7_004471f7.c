/*
 * Decompiled function: FUN_004471f7
 * Entry Point: 004471f7
 * Size: 182 bytes
 */
#include "duel.h"


undefined4 FUN_004471f7(int arg1,int arg2)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 2) == 0) {
      if (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) == 0) {
        local_8 = 0;
      }
      else {
        local_8 = 2;
      }
    }
    else {
      local_8 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


