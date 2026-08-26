/*
 * Decompiled function: FUN_004489c3
 * Entry Point: 004489c3
 * Size: 117 bytes
 */
#include "duel.h"


void FUN_004489c3(void *arg1,int arg2)

{
  int iVar1;
  
  if ((arg1 != (void *)0x0) && (iVar1 = Mem_AllocOrFree_004483e2(arg2), iVar1 == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    FID_conflict__memcpy(arg1,&DAT_00664690 + ((arg2 == 0) - 1 & 0xfffb2d00),0x98);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}


