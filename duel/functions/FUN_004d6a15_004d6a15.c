/*
 * Decompiled function: FUN_004d6a15
 * Entry Point: 004d6a15
 * Size: 1837 bytes
 */
#include "duel.h"


void FUN_004d6a15(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  *(int *)(&DAT_006826c0 + arg_3 * 0x120 + arg_1 * 0x5b20) = arg_2;
  *(undefined4 *)(&DAT_006826c4 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&DAT_006826c0 + arg_3 * 0x120 + arg_1 * 0x5b20);
  *(undefined4 *)(&DAT_006826c8 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  if (arg_1 == 0) {
    *(undefined4 *)(&DAT_006826cc + arg_3 * 0x120) = 0;
  }
  else {
    *(undefined4 *)(&DAT_006826cc + arg_3 * 0x120 + arg_1 * 0x5b20) = 0x1000;
  }
  *(undefined2 *)(&DAT_006826d0 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&DAT_006826d2)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  *(undefined4 *)(&DAT_006826e8 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  (&DAT_006826d3)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  *(undefined4 *)(&DAT_006826ec + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  *(undefined2 *)(&DAT_006826d4 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined2 *)(&DAT_004ff59a + arg_2 * 0x34);
  *(undefined2 *)(&DAT_006826d6 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined2 *)(&DAT_004ff59c + arg_2 * 0x34);
  *(undefined2 *)(&DAT_006826d8 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006826da + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&DAT_006826dd)[arg_3 * 0x120 + arg_1 * 0x5b20] = (&DAT_004ff596)[arg_2 * 0x34];
  (&DAT_006826dc)[arg_3 * 0x120 + arg_1 * 0x5b20] = (&DAT_006826dd)[arg_3 * 0x120 + arg_1 * 0x5b20];
  (&DAT_006826de)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  (&DAT_006826df)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  (&DAT_006826e0)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  *(undefined4 *)(&DAT_006826f0 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&DAT_006826e4 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&DAT_006826f0 + arg_3 * 0x120 + arg_1 * 0x5b20);
  *(undefined4 *)(&DAT_006826f4 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  *(undefined4 *)(&DAT_006826f8 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&DAT_006826fc + arg_3 * 0x120 + arg_1 * 0x5b20) = 0x8000000;
  uVar1 = FUN_004d71e6(arg_1,arg_3);
  *(undefined4 *)(&DAT_00682700 + arg_3 * 0x120 + arg_1 * 0x5b20) = uVar1;
  *(undefined4 *)(&DAT_0068270c + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&DAT_00682710 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  *(undefined4 *)(&DAT_006827c8 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&DAT_006827d4 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&DAT_006827c8 + arg_3 * 0x120 + arg_1 * 0x5b20);
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    (&DAT_006827cc)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006827d8)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006827cc)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120];
  }
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    (&DAT_006827b9)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006827bf)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00682718 + arg_3 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) = 0xffffffff;
    *(undefined4 *)(&DAT_0068271c + arg_3 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) = 0xffffffff;
  }
  if (((&DAT_004ff5a9)[arg_2 * 0x34] & 0x10) != 0) {
    if (((&DAT_004ff594)[arg_2 * 0x34] == '\x01') || ((&DAT_004ff594)[arg_2 * 0x34] == '@')) {
      (&DAT_006826dd)[arg_3 * 0x120 + arg_1 * 0x5b20] = 1;
    }
    if (*(int *)(&DAT_004ff590 + arg_2 * 0x34) == 0xf) {
      (&DAT_006826dc)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0x3e;
    }
    else if (*(int *)(&DAT_004ff590 + arg_2 * 0x34) == 300) {
      (&DAT_006826dc)[arg_3 * 0x120 + arg_1 * 0x5b20] = 1;
    }
  }
  FUN_0048eb25(arg_1,arg_3);
  return;
}


