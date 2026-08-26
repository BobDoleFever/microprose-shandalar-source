/*
 * Decompiled function: FUN_004071cd
 * Entry Point: 004071cd
 * Size: 880 bytes
 */
#include "duel.h"


undefined4 FUN_004071cd(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int local_c;
  
  if (param_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (param_3 == 0x71) {
      if (((param_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f2394,s_UNTAMED_WILDS_004f2384);
        bVar1 = false;
        local_14 = 0;
        while (((local_14 < 500 && (!bVar1)) &&
               (*(int *)(&DAT_006669f0 + local_14 * 4 + param_1 * 2000) != -1))) {
          if (*(int *)(&DAT_006669f0 + local_14 * 4 + param_1 * 2000) < 5) {
            bVar1 = true;
          }
          local_14 = local_14 + 1;
        }
        if (bVar1) {
          do {
            local_c = FUN_004d6639(param_1,&DAT_006669f0 + param_1 * 2000,500,&DAT_006679f0,1,
                                   &DAT_004f23a0);
            if (local_c == -1) break;
          } while (4 < *(int *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000));
        }
        else {
          local_c = -1;
          FUN_004d6639(param_1,&DAT_006669f0 + param_1 * 2000,500,&DAT_006679f0,0,&DAT_004f23a4);
        }
      }
      else {
        local_c = FUN_00408121(param_1,param_1,1);
        if ((local_c != -1) && (4 < *(int *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000))) {
          local_c = -1;
          local_14 = 0;
          while (((local_14 < 500 && (local_c == -1)) &&
                 (*(int *)(&DAT_006669f0 + local_14 * 4 + param_1 * 2000) != -1))) {
            if (*(int *)(&DAT_006669f0 + local_14 * 4 + param_1 * 2000) < 5) {
              local_c = local_14;
            }
            local_14 = local_14 + 1;
          }
        }
      }
      if ((local_c != -1) &&
         ((*(int *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000) == -1 ||
          (4 < *(int *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000))))) {
        local_c = -1;
      }
      if (((local_c != -1) && (*(int *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000) != -1)) &&
         (iVar3 = FUN_004d695b(param_1,*(undefined4 *)(&DAT_006669f0 + local_c * 4 + param_1 * 2000)
                              ), iVar3 != -1)) {
        FUN_004d7acc(param_1,local_c);
        FUN_004bda20(param_1,iVar3);
        FUN_00451482(0,0x30);
      }
      FUN_004d7946(param_1);
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


