/*
 * Decompiled function: FUN_0044883c
 * Entry Point: 0044883c
 * Size: 91 bytes
 */
#include "duel.h"


undefined4 FUN_0044883c(void *arg_1)

{
  undefined4 uVar1;
  
  if (arg_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uVar1 = DAT_00618984;
    FID_conflict__memcpy(arg_1,&DAT_00615470,0x1580);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return uVar1;
}


