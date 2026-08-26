/*
 * Decompiled function: FUN_004485c7
 * Entry Point: 004485c7
 * Size: 140 bytes
 */
#include "duel.h"


undefined4 FUN_004485c7(void *arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00446de2(arg_2,arg_3);
    if (iVar2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      FID_conflict__memcpy(arg_1,&DAT_00601620 + arg_2 * 0x5b20 + arg_3 * 0x120,0x120);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


