/*
 * Decompiled function: FUN_00468831
 * Entry Point: 00468831
 * Size: 300 bytes
 */
#include "duel.h"


bool FUN_00468831(int arg_1,uint arg_2,int arg_3)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int iVar1;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &DAT_006679f0;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  iVar1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = FUN_004521e2(arg_1,arg_3);
  iVar1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,0x40,0,0,arg_8,arg_9,arg_10,iVar1,arg_12,arg_13,arg_14,
                     arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
  if (iVar1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = local_c;
    *(undefined4 *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         local_8;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return iVar1 != 0;
}


