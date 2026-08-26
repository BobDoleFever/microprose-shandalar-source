/*
 * Decompiled function: FUN_0045faf0
 * Entry Point: 0045faf0
 * Size: 308 bytes
 */
#include "duel.h"


undefined4 FUN_0045faf0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_0068ecfc)) && (arg_1 == DAT_00690310)) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\0')) {
    DAT_0066642c = 1;
  }
  if ((arg_3 == 0x15) && (arg_1 == DAT_00666458)) {
    iVar1 = FUN_0048ad82(arg_1,arg_2);
    if (iVar1 != 0) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 4;
      DAT_006826b0 = DAT_006826b0 + 1;
    }
  }
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((arg_1 == DAT_00666458 &&
      ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20054) == 0)))) {
    FUN_0046e571(arg_1,arg_2,4);
  }
  return 0;
}


