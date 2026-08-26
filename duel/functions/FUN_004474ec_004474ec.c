/*
 * Decompiled function: FUN_004474ec
 * Entry Point: 004474ec
 * Size: 280 bytes
 */
#include "duel.h"


undefined4 FUN_004474ec(int *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00446de2(arg_2,arg_3);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_00601633)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0060164c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uVar2 = *(undefined4 *)(&DAT_00601664 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_00601633)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0060164c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


