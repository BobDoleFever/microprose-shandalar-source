/*
 * Decompiled function: FUN_0040776c
 * Entry Point: 0040776c
 * Size: 690 bytes
 */
#include "duel.h"


undefined4 FUN_0040776c(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  char cVar2;
  int arg2;
  undefined4 uVar3;
  int iVar4;
  int local_1c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
      if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
        local_8 = Pic_Load_advfac64_004d6639
                            (arg_1,(int *)(&DAT_006669f0 + arg_1 * 2000),500,
                             s_Pick_an_artifact_004f2404,1,&DAT_004f2400);
      }
      else {
        local_8 = FUN_00408121(arg_1,arg_1,0x40);
      }
      if ((local_8 == -1) || (*(int *)(&DAT_006669f0 + local_8 * 4 + arg_1 * 2000) == -1)) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar4 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if ((*(int *)(&DAT_006669f0 + iVar4 * 4 + arg_1 * 2000) != -1) &&
         (arg2 = *(int *)(&DAT_006669f0 + iVar4 * 4 + arg_1 * 2000),
         ((&DAT_004ff594)[arg2 * 0x34] & 0x40) != 0)) {
        FUN_004d7acc(arg_1,iVar4);
        if (local_1c != -1) {
          iVar4 = *(int *)(&DAT_006826c4 + local_1c * 0x120 + arg_1 * 0x5b20);
          FUN_0046e571(arg_1,local_1c,2);
          cVar1 = (&DAT_004ff598)[arg2 * 0x34];
          cVar2 = (&DAT_004ff598)[iVar4 * 0x34];
          while (0 < (int)cVar1 - (int)cVar2) {
            iVar4 = FUN_0049b309(arg_1,7,1);
            if (iVar4 == 0) break;
            FUN_0042b6b0(arg_1,0,1);
          }
          if ((int)cVar1 - (int)cVar2 < 1) {
            iVar4 = FUN_004d695b(arg_1,arg2);
            if (iVar4 != -1) {
              *(uint *)(&DAT_006826cc + iVar4 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826cc + iVar4 * 0x120 + arg_1 * 0x5b20) | 0x30002;
            }
          }
        }
      }
      FUN_004d7946(arg_1);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


