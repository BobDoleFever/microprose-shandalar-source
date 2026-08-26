/*
 * Decompiled function: FUN_0040a940
 * Entry Point: 0040a940
 * Size: 428 bytes
 */
#include "duel.h"


undefined4 FUN_0040a940(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_3 == 199) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    iVar1 = (&DAT_0068ee78)[arg_1] + -4;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (arg_1 == 0) {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * -0x18;
    }
    else {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * 0x18;
    }
  }
  if (((((DAT_0068f230 == 0xc9) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
      ((arg_1 == DAT_00666458 && (DAT_00681ec4 == arg_1)))) &&
     ((4 < (int)(&DAT_0068ee78)[arg_1] &&
      ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)
       ))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) && (4 < (int)(&DAT_0068ee78)[arg_1])) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + (&DAT_0068ee78)[arg_1] + -4;
    }
  }
  return 0;
}


