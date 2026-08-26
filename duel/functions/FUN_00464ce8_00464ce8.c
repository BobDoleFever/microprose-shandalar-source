/*
 * Decompiled function: FUN_00464ce8
 * Entry Point: 00464ce8
 * Size: 129 bytes
 */
#include "duel.h"


undefined4 FUN_00464ce8(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    cVar2 = FUN_004af7bb(arg_1,arg_2,5);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar2 - 1U & 0x1f);
    uVar1 = DAT_0066642c;
    FUN_00464d69(arg_1,arg_2,5);
    DAT_0066642c = uVar1;
  }
  return 0;
}


