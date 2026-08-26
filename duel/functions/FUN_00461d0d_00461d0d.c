/*
 * Decompiled function: FUN_00461d0d
 * Entry Point: 00461d0d
 * Size: 565 bytes
 */
#include "duel.h"


uint FUN_00461d0d(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    uVar1 = *(uint *)(&DAT_0066aad0 + arg_1 * 4) & 0x40;
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_00468a84(arg_1);
      if (iVar2 != 0) {
        *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) * -2;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) * -2;
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


