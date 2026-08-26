/*
 * Decompiled function: FUN_0046fe86
 * Entry Point: 0046fe86
 * Size: 202 bytes
 */
#include "magic.h"


undefined4 FUN_0046fe86(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  bVar3 = DAT_00695ec4 == 0xd3;
  if (bVar3) {
    DAT_00525778 = 1;
  }
  iVar1 = FUN_0046ff50(arg1,arg2,0);
  if (((iVar1 == 0) || (iVar1 = FUN_0046ff50(arg1,arg2,1), iVar1 == 0)) ||
     (iVar1 = FUN_00470b36(arg1,arg2), iVar1 == 0)) {
    if (bVar3) {
      DAT_00525778 = 0;
    }
    uVar2 = 0;
  }
  else {
    if (bVar3) {
      DAT_00525778 = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}


