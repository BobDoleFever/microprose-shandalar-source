/*
 * Decompiled function: FUN_0045f72a
 * Entry Point: 0045f72a
 * Size: 199 bytes
 */
#include "duel.h"


undefined4 FUN_0045f72a(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((&DAT_004ff595)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] == '\x02') &&
     (arg_3 == 0x34)) {
    cVar1 = FUN_004af74c(arg_1,arg_2,1);
    DAT_0066642c = DAT_0066642c | (1 << (cVar1 - 1U & 0x1f)) + 0x200U;
  }
  if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    FUN_00467d65(FUN_0045f7f1,-1);
    FUN_00451482(0,0xff);
  }
  return 0;
}


