/*
 * Decompiled function: FUN_004521e2
 * Entry Point: 004521e2
 * Size: 645 bytes
 */
#include "duel.h"


uint FUN_004521e2(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068eee0) {
    local_8 = *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  else {
    local_8 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  if (((&DAT_004ff594)[local_8 * 0x34] & 4) == 0) {
    if (((&DAT_004ff594)[local_8 * 0x34] & 0x10) == 0) {
      if (((&DAT_004ff594)[local_8 * 0x34] & 0x20) == 0) {
        if (((&DAT_004ff594)[local_8 * 0x34] & 8) == 0) {
          iVar2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_004af7bb(arg1,arg2,iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f);
        }
        else {
          iVar2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_004af7bb(arg1,arg2,iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x100000;
        }
      }
      else {
        iVar2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
        cVar1 = FUN_004af7bb(arg1,arg2,iVar2);
        uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x80000;
      }
    }
    else {
      iVar2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
      cVar1 = FUN_004af7bb(arg1,arg2,iVar2);
      uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x40000;
    }
  }
  else {
    iVar2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
    cVar1 = FUN_004af7bb(arg1,arg2,iVar2);
    uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x20000;
  }
  return uVar3;
}


