/*
 * Decompiled function: FUN_00461b42
 * Entry Point: 00461b42
 * Size: 265 bytes
 */
#include "duel.h"


undefined4 FUN_00461b42(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_0048a33f(DAT_0068ecb0,DAT_00690c48);
  if ((iVar2 != 0) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\x01')) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_004af74c(arg_1,arg_2,2);
      DAT_0066642c = DAT_0066642c | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if ((arg_3 == 0x77) && (((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0)) {
      *(uint *)(&DAT_006826fc + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
           *(uint *)(&DAT_006826fc + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) | 0xe000000;
    }
  }
  return 0;
}


