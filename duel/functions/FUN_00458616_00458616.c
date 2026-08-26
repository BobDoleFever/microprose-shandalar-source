/*
 * Decompiled function: FUN_00458616
 * Entry Point: 00458616
 * Size: 492 bytes
 */
#include "duel.h"


undefined4 FUN_00458616(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x71) {
    iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (iVar1 != -1) {
      *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
      *(undefined4 *)(&DAT_006826f0 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10e;
      *(undefined4 *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar1;
    }
  }
  if ((((arg_3 == 0x32) || (arg_3 == 0x33)) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0))
  {
    if (arg_1 == DAT_00666458) {
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 2;
    }
    else {
      *(uint *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xfffffffd;
    }
  }
  return 0;
}


