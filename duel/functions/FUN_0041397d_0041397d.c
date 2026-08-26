/*
 * Decompiled function: FUN_0041397d
 * Entry Point: 0041397d
 * Size: 1096 bytes
 */
#include "duel.h"


undefined4 FUN_0041397d(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x82) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 &&
       ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 && (arg_1 == DAT_00666458))))
      )) && (DAT_00681eb4 == arg_1)) {
    *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    (&DAT_006827cc)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827cc)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x04';
  }
  if (((arg_3 == 1) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0xc;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006826ce)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) == 0
        )) && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b2c1(arg_1,0,3);
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      DAT_0068f0f4 = 0;
    }
    if (((DAT_0068f230 == 0xcb) || (arg_3 == 199)) &&
       ((arg_2 == DAT_00690c48 &&
        ((((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)) && (arg_1 == DAT_00681ec4)) &&
         ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 &&
          (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)))))))) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
        *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      }
    }
    if (((arg_3 == 199) && (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) < 4)) &&
       (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] - (4 - *(int *)(&DAT_0068ef6c + arg_1 * 0x20))
      ;
    }
    if (((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0))))
    {
      FUN_0049b1a9(arg_1,0,3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


