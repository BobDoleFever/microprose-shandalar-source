/*
 * Decompiled function: FUN_0048c50b
 * Entry Point: 0048c50b
 * Size: 157 bytes
 */
#include "duel.h"


undefined4 FUN_0048c50b(int arg_1,undefined4 arg_2,int arg_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0048cac9();
  uVar2 = DAT_0068f230;
  DAT_0066642c = 0;
  DAT_0068ecb0 = arg_1;
  DAT_00690c48 = arg_2;
  DAT_00690310 = 1 - arg_1;
  DAT_0068ecfc = 0xffffffff;
  if ((arg_3 != 0x7d) && (arg_3 != 0x7e)) {
    DAT_0068f230 = 0xffffffff;
  }
  Magic_ScanCards(arg_3);
  uVar1 = DAT_0066642c;
  DAT_0068ecb0 = 0xffffffff;
  DAT_0068f230 = uVar2;
  FUN_0048cb7f();
  return uVar1;
}


