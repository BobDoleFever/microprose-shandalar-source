/*
 * Decompiled function: FUN_0044743d
 * Entry Point: 0044743d
 * Size: 175 bytes
 */
#include "duel.h"


void FUN_0044743d(int *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_1 != (int *)0x0) {
    iVar1 = FUN_00446de2(arg_2,arg_3);
    if (iVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      *arg_1 = (int)(char)(&DAT_00601632)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_00601648 + arg_3 * 0x120 + arg_2 * 0x5b20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      *arg_1 = -1;
      arg_1[1] = -1;
    }
  }
  return;
}


