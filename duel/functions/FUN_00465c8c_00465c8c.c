/*
 * Decompiled function: FUN_00465c8c
 * Entry Point: 00465c8c
 * Size: 582 bytes
 */
#include "duel.h"


void FUN_00465c8c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) {
      FUN_0049b309(arg_1,5,2);
    }
  }
  else if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,5,2), iVar1 != 0)) &&
          (FUN_0042b6b0(arg_1,5,2), DAT_00681ea4 != 1)) {
    if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
      do {
        local_8 = Pic_Load_advfac64_004d6639
                            (arg_1,(int *)(&DAT_0068f370 + arg_1 * 2000),500,
                             s_Pick_an_artifact_004f8e24,0,s_Cancel_004f8e1c);
        if (local_8 == -1) break;
      } while (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) * 0x34] & 0x40)
               == 0);
    }
    else {
      local_8 = FUN_0040800f(arg_1,0x40);
    }
    if (((local_8 == -1) || (*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) == -1)) ||
       (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) * 0x34] & 0x40) == 0))
    {
      DAT_00681ea4 = 1;
    }
    else {
      iVar1 = FUN_004d695b(arg_1,*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000));
      if (iVar1 != -1) {
        *(undefined4 *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
      }
    }
    if (DAT_00681ea4 != 1) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
  }
  return;
}


