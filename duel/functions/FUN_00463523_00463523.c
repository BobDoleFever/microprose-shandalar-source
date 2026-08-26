/*
 * Decompiled function: FUN_00463523
 * Entry Point: 00463523
 * Size: 213 bytes
 */
#include "duel.h"


undefined4 FUN_00463523(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x1a) && (arg_1 != DAT_00666458)) &&
     ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    iVar1 = FUN_00439892(2);
    if (iVar1 != 0) {
      (&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


