/*
 * Decompiled function: Mana_Init_004532f1
 * Entry Point: 0047aac1
 * Size: 514 bytes
 */
#include "duel.h"


undefined4 Mana_Init_004532f1(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    uVar1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (arg_1 == DAT_00676510) {
        iVar2 = FUN_00439892(5);
        local_10 = iVar2 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_0068f320 + local_c * 4 + arg_1 * 0x20)) {
            local_8 = *(int *)(&DAT_0068f320 + local_c * 4 + arg_1 * 0x20);
            local_10 = local_c;
          }
        }
      }
      if (arg_1 == 1) {
        local_14 = local_10;
      }
      else {
        local_14 = -1;
      }
      iVar2 = FUN_004513fa(arg_1,s_What_kind_of_mana__004f9a64,1,local_14,0xffffffff);
      if (iVar2 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0049b235(arg_1,iVar2,1);
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        DAT_0068f0f4 = iVar2;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


