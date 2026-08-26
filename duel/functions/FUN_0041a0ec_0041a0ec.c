/*
 * Decompiled function: FUN_0041a0ec
 * Entry Point: 0041a0ec
 * Size: 255 bytes
 */
#include "duel.h"


undefined4 FUN_0041a0ec(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_00681eb0 = DAT_00681eb0 | 0x800 << ((byte)arg_1 & 0x1f);
  }
  if (((arg_3 == 0x1f) && (arg_1 == DAT_00666458)) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    DAT_0066642c = DAT_0066642c + 1;
  }
  if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_00681eb0 = DAT_00681eb0 & ~(0x800 << ((byte)arg_1 & 0x1f));
  }
  return 0;
}


