/*
 * Decompiled function: FUN_0045f892
 * Entry Point: 0045f892
 * Size: 192 bytes
 */
#include "duel.h"


undefined4 FUN_0045f892(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((&DAT_004ff595)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] == '\x03') &&
     (((&DAT_006826cc)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] & 2) != 0)) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_004af74c(arg_1,arg_2,4);
      DAT_0066642c = DAT_0066642c | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return 0;
}


