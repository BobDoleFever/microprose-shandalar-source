/*
 * Decompiled function: FUN_0044826e
 * Entry Point: 0044826e
 * Size: 150 bytes
 */
#include "duel.h"


void FUN_0044826e(undefined4 *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  iVar1 = FUN_00446de2(arg_2,arg_3);
  if ((iVar1 == 0) && (arg_1 != (undefined4 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_1 = *(undefined4 *)(&DAT_00601710 + arg_3 * 0x120 + arg_2 * 0x5b20);
    arg_1[1] = *(undefined4 *)(&DAT_00601714 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}


