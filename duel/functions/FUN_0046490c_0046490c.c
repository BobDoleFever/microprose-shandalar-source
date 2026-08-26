/*
 * Decompiled function: FUN_0046490c
 * Entry Point: 0046490c
 * Size: 364 bytes
 */
#include "duel.h"


undefined4 FUN_0046490c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffcffff;
  }
  if ((arg_3 == 0x8d) ||
     (((arg_3 == 0x77 && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 &&
       ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0 &&
        ((&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] != '\x04')))))))) {
    iVar1 = Pic_Subsystem_00451291(arg_1,DAT_0066aafc);
    if (iVar1 != -1) {
      *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)
            (&DAT_004ff590 + *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
    }
  }
  return 0;
}


