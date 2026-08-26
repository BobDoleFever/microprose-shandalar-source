/*
 * Decompiled function: FUN_004d3945
 * Entry Point: 004d3945
 * Size: 620 bytes
 */
#include "duel.h"


undefined4 FUN_004d3945(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1))
    {
      iVar2 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
      if (iVar2 == 0) {
        DAT_0068f2d4 = DAT_0068f2d4 +
                       (*(int *)(&DAT_0068edf4 + DAT_00676504 * 0x20) -
                       *(int *)(&DAT_0068edf4 + DAT_00676510 * 0x20)) * 0xc;
      }
    }
    if (arg_3 == 0x71) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 5;
    }
    if (((arg_3 == 0x85) && (DAT_00690c48 == arg_2)) &&
       ((DAT_0068ecb0 == arg_1 && ((DAT_00666458 == arg_1 && (DAT_00666458 == DAT_00681eb4)))))) {
      *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006827dd)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006827dd)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
    }
    if ((arg_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) {
      iVar2 = FUN_0048a33f(arg_1,arg_2);
      if (iVar2 != 0) {
        iVar2 = FUN_0048a33f(DAT_0068ecb0,DAT_00690c48);
        if (iVar2 != 0) {
          iVar2 = FUN_004af74c(arg_1,arg_2,4);
          if (*(int *)(&DAT_0068f0dc + iVar2 * 4) == *(int *)(&DAT_004ff590 + DAT_0066642c * 0x34))
          {
            iVar2 = FUN_004af74c(arg_1,arg_2,
                                 *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
            DAT_0066642c = iVar2 + -1;
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


