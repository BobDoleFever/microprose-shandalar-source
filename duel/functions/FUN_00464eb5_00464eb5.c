/*
 * Decompiled function: FUN_00464eb5
 * Entry Point: 00464eb5
 * Size: 90 bytes
 */
#include "duel.h"


undefined4 FUN_00464eb5(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar1 = FUN_004af7bb(arg_1,arg_2,4);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar1 - 1U & 0x1f);
  }
  return 0;
}


