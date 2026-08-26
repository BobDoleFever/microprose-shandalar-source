/*
 * Decompiled function: FUN_00406cb0
 * Entry Point: 00406cb0
 * Size: 576 bytes
 */
#include "duel.h"


undefined4 FUN_00406cb0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
        do {
          local_8 = Pic_Load_advfac64_004d6639
                              (arg_1,(int *)(&DAT_0068f370 + arg_1 * 2000),500,
                               s_Pick_an_artifact_004f2350,1,&DAT_004f234c);
          if (local_8 == -1) break;
        } while (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) * 0x34] &
                 0x40) == 0);
      }
      else {
        local_8 = FUN_0040800f(arg_1,0x40);
      }
      if (((local_8 == -1) || (*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) == -1)) ||
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) * 0x34] & 0x40) == 0
         )) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if ((iVar1 != -1) &&
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + iVar1 * 4 + arg_1 * 2000) * 0x34] & 0x40) != 0))
      {
        FUN_004d695b(arg_1,*(int *)(&DAT_0068f370 + iVar1 * 4 + arg_1 * 2000));
        *(undefined4 *)(&DAT_0068f370 + iVar1 * 4 + arg_1 * 2000) = 0xffffffff;
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


