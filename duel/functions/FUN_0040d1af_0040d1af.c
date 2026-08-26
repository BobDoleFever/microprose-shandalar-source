/*
 * Decompiled function: FUN_0040d1af
 * Entry Point: 0040d1af
 * Size: 331 bytes
 */
#include "duel.h"


undefined4 FUN_0040d1af(int arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0;
      local_c < *(int *)(&DAT_006826f0 +
                        *(int *)(&DAT_006827b4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x5b20);
      local_c = local_c + 1) {
    iVar1 = FUN_004d7d5e(0x37b);
    iVar1 = Pic_Subsystem_00451291(arg1,iVar1);
    if (iVar1 != -1) {
      Pic_Subsystem_0042ac1f(arg1,iVar1);
      (&DAT_006826d3)[iVar1 * 0x120 + arg1 * 0x5b20] = (undefined1)DAT_00690af0;
      *(undefined4 *)(&DAT_006826ec + iVar1 * 0x120 + arg1 * 0x5b20) = DAT_0068efa0;
      *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg1 * 0x5b20) | 0x10;
      *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + arg1 * 0x5b20) = 1;
    }
  }
  return 0;
}


