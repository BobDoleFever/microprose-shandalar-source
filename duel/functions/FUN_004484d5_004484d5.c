/*
 * Decompiled function: FUN_004484d5
 * Entry Point: 004484d5
 * Size: 102 bytes
 */
#include "duel.h"


undefined4 FUN_004484d5(int arg_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = Mem_AllocOrFree_004483e2(arg_1);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 == 0) {
      local_8 = DAT_0060cc80;
    }
    else {
      local_8 = DAT_00664dac;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


