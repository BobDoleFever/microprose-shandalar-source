/*
 * Decompiled function: FUN_004486f6
 * Entry Point: 004486f6
 * Size: 163 bytes
 */
#include "duel.h"


undefined4 FUN_004486f6(void *arg1,int arg2)

{
  int iVar1;
  undefined4 local_8;
  
  if (arg1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    iVar1 = Mem_AllocOrFree_004483e2(arg2);
    if (iVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        local_8 = DAT_00664b68;
      }
      else {
        local_8 = DAT_00618948;
      }
      FID_conflict__memcpy(arg1,(void *)((int)&DAT_00663e70 + ((arg2 == 0) - 1 & 0xfffb3b10)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}


