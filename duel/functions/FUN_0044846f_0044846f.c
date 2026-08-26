/*
 * Decompiled function: FUN_0044846f
 * Entry Point: 0044846f
 * Size: 102 bytes
 */
#include "duel.h"


undefined4 FUN_0044846f(int arg_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = Mem_AllocOrFree_004483e2(arg_1);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 == 0) {
      local_8 = DAT_00616a00;
    }
    else {
      local_8 = DAT_00664a50;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


