/*
 * Decompiled function: FUN_004c2fbb
 * Entry Point: 004c2fbb
 * Size: 158 bytes
 */
#include "duel.h"


undefined4 FUN_004c2fbb(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ee70 + (7 - arg_1) * 4) - (&DAT_0068ee88)[arg_1]) * 0xc;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


