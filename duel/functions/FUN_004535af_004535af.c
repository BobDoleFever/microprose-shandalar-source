/*
 * Decompiled function: FUN_004535af
 * Entry Point: 004535af
 * Size: 796 bytes
 */
#include "duel.h"


undefined4 FUN_004535af(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_10;
  int local_c;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_004d7d5e(0x38f);
    iVar1 = Pic_Subsystem_00451291(1 - arg_1,iVar1);
    if (iVar1 != -1) {
      *(uint *)(&DAT_006826cc + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(undefined4 *)
            (&DAT_004ff590 + *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
    }
    *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = iVar1;
  }
  if (arg_3 == 0x73) {
    uVar2 = FUN_0049b309(arg_1,3,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar1 = FUN_0049b309(arg_1,3,1);
      if (iVar1 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,3,1);
        *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) != 0)) {
      Mem_AllocOrFree_004afd1c
                (1 - arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
      Mem_AllocOrFree_004afd1c
                (arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_c]; local_10 = local_10 + 1) {
          iVar1 = FUN_0048a33f(local_c,local_10);
          if (iVar1 != 0) {
            uVar3 = FUN_0048b81a(local_c,local_10,0x34,0xffffffff);
            if ((uVar3 & 0x20) != 0) {
              FUN_004af950(local_c,local_10,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120)
                           ,arg_1,arg_2);
            }
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      FUN_0046e571(1 - arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),4);
    }
    uVar2 = 0;
  }
  return uVar2;
}


