/*
 * Decompiled function: FUN_0040fdb5
 * Entry Point: 0040fdb5
 * Size: 457 bytes
 */
#include "duel.h"


undefined4 FUN_0040fdb5(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  int local_14;
  int local_c;
  
  if (arg_3 == 0x3c) {
    (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] | 0x40;
  }
  if (((arg_3 == 0x1a) && (arg_4 = 1 - arg_1, DAT_00666458 == arg_1)) &&
     (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0)) {
    if ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
      local_14 = arg_2;
    }
    else {
      local_14 = (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    for (local_c = 0; local_c < (int)(&DAT_00666408)[arg_4]; local_c = local_c + 1) {
      if ((((char)(&DAT_006826de)[local_c * 0x120 + arg_4 * 0x5b20] == local_14) &&
          ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + local_c * 0x120 + arg_4 * 0x5b20) * 0x34] ==
           '\0')) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + arg_4 * 0x5b20) * 0x34] & 2)
          != 0)) {
        FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg_4,local_c);
      }
    }
  }
  return 0;
}


