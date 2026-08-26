/*
 * Decompiled function: FUN_004d7876
 * Entry Point: 004d7876
 * Size: 208 bytes
 */
#include "duel.h"


undefined4 FUN_004d7876(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((arg_1 == 1) || (arg_2 == 1)) {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_0048c367((byte)arg_1);
    iVar3 = FUN_0048c367((byte)arg_2);
    if ((char)(&DAT_00509058)[iVar3 * 3] == iVar2) {
      uVar1 = 1;
    }
    else if ((arg_3 < 2) || ((char)(&DAT_00509059)[iVar3 * 3] != iVar2)) {
      if ((arg_3 < 3) || ((char)(&DAT_0050905a)[iVar3 * 3] != iVar2)) {
        if (arg_3 < 4) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


