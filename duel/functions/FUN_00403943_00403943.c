/*
 * Decompiled function: FUN_00403943
 * Entry Point: 00403943
 * Size: 540 bytes
 */
#include "duel.h"


undefined4 FUN_00403943(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((arg_1 == DAT_00676504) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      iVar1 = FUN_00404a71(arg_1,*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120));
      DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x24 / (longlong)iVar1);
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
    }
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_004afd1c
                  (local_8,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar1 = FUN_0048a33f(local_8,local_c);
          if (((iVar1 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
               & 2) != 0)) &&
             (uVar3 = FUN_0048b81a(local_8,local_c,0x34,0xffffffff), (uVar3 & 0x20) != 0)) {
            FUN_004af950(local_8,local_c,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),
                         arg_1,arg_2);
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


