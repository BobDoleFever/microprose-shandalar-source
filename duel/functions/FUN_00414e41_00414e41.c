/*
 * Decompiled function: FUN_00414e41
 * Entry Point: 00414e41
 * Size: 460 bytes
 */
#include "duel.h"


undefined4 FUN_00414e41(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_0049aa14((&DAT_00681ea8)[DAT_00676504],1,99);
    DAT_0068f2d4 = DAT_0068f2d4 + (int)(0x30 / (longlong)iVar1);
  }
  if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0 &&
       ((&DAT_006826e0)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\x04')))))) {
    iVar1 = Pic_Subsystem_00451291(arg_1,DAT_0068f2d0);
    if (iVar1 != -1) {
      *(undefined4 *)(&DAT_006826c0 + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x200;
      *(undefined4 *)(&DAT_00682710 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0xd5;
      (&DAT_006826e0)[iVar1 * 0x120 + arg_1 * 0x5b20] = 2;
      FUN_0048eb25(arg_1,iVar1);
    }
  }
  return 0;
}


