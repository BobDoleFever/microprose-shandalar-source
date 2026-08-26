/*
 * Decompiled function: FUN_0044853b
 * Entry Point: 0044853b
 * Size: 140 bytes
 */
#include "duel.h"


undefined4 FUN_0044853b(void *arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = Mem_AllocOrFree_004483e2(arg2);
    if (iVar2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        FID_conflict__memcpy(arg1,&DAT_006152c0,0x1c);
      }
      else {
        FID_conflict__memcpy(arg1,&DAT_0060cc90,0x1c);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


