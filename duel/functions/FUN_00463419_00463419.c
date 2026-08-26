/*
 * Decompiled function: FUN_00463419
 * Entry Point: 00463419
 * Size: 266 bytes
 */
#include "duel.h"


undefined4 FUN_00463419(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x15) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    iVar1 = FUN_00439892(2);
    if (iVar1 != 0) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


