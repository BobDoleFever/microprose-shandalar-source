/*
 * Decompiled function: Glue_Subsystem_004d212c
 * Entry Point: 004538cb
 * Size: 1247 bytes
 */
#include "duel.h"


void Glue_Subsystem_004d212c(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  undefined4 uVar1;
  int iVar2;
  int local_10;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1 - arg_1;
      uVar1 = Ai_Subsystem_004cc56d
                        (*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2,-1,-1,
                         s_Swap_cards__Lose_10_life__Conced_004f87b8,0);
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar1;
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      iVar2 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (iVar2 == 0) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) ^ 0x1000;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0xf);
        }
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,3);
        if (arg_1 == DAT_00676510) {
          FUN_004d76dd(*(uint *)(&DAT_006826c4 +
                                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120));
        }
        else {
          Ai_Subsystem_004cc1e8
                    (*(uint *)(&DAT_006826c4 +
                              *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120));
        }
        *(undefined4 *)
         (&DAT_006826c4 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0xffffffff;
        local_10 = 0;
        do {
          do {
            iVar2 = FUN_00439892((&DAT_00666408)[arg_4]);
          } while (*(int *)(&DAT_006826c4 + iVar2 * 0x120 + arg_4 * 0x5b20) == -1);
        } while ((((&DAT_006826cc)[iVar2 * 0x120 + arg_4 * 0x5b20] & 2) != 0) &&
                (local_10 = local_10 + 1, local_10 < 999));
        if (local_10 < 999) {
          Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_4,iVar2,s_randomly_chooses____004f87e4,0);
          *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg_4 * 0x5b20) =
               *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg_4 * 0x5b20) ^ 0x1000;
          FUN_0046f02d(arg_4,iVar2);
          if (arg_1 == DAT_00676510) {
            Ai_Subsystem_004cc1e8(*(uint *)(&DAT_006826c4 + iVar2 * 0x120 + arg_4 * 0x5b20));
          }
          else {
            FUN_004d76dd(*(uint *)(&DAT_006826c4 + iVar2 * 0x120 + arg_4 * 0x5b20));
          }
          *(undefined4 *)(&DAT_006826c4 + iVar2 * 0x120 + arg_4 * 0x5b20) = 0xffffffff;
        }
      }
      else if (iVar2 == 1) {
        (&DAT_00681ea8)[arg_4] = (&DAT_00681ea8)[arg_4] + -10;
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
      }
      else if (iVar2 == 2) {
        (&DAT_00681ea8)[arg_4] = 0xffffff9d;
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
      }
    }
  }
  return;
}


