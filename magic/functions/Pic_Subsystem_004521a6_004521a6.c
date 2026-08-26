/*
 * Decompiled function: Pic_Subsystem_004521a6
 * Entry Point: 004521a6
 * Size: 208 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004521a6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((arg_1 == 1) || (arg_2 == 1)) {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_00473cc5((byte)arg_1);
    iVar3 = FUN_00473cc5((byte)arg_2);
    if ((char)(&DAT_00523bc8)[iVar3 * 3] == iVar2) {
      uVar1 = 1;
    }
    else if ((arg_3 < 2) || ((char)(&DAT_00523bc9)[iVar3 * 3] != iVar2)) {
      if ((arg_3 < 3) || ((char)(&DAT_00523bca)[iVar3 * 3] != iVar2)) {
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


