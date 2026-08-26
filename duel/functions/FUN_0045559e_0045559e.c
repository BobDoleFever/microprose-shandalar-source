/*
 * Decompiled function: FUN_0045559e
 * Entry Point: 0045559e
 * Size: 418 bytes
 */
#include "duel.h"


undefined4 FUN_0045559e(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    arg_2 = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    if (arg_2 != -1) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      *(undefined4 *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) = 2;
      *(undefined4 *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x8000000;
    }
  }
  if (((DAT_00690c48 == arg_2) && (DAT_0068ecb0 == arg_1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
    if (arg_3 == 0x34) {
      DAT_0066642c = DAT_0066642c | 0x20;
    }
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c + 4;
    }
    if (arg_3 == 0x33) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if (arg_3 == 0x22) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
    }
  }
  return 0;
}


