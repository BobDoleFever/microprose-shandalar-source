/*
 * Decompiled function: Prompts_Load_004071cd
 * Entry Point: 004071cd
 * Size: 880 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004071cd(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int arg2;
  int local_14;
  int local_c;
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (flags == 0x71) {
      if (((spell_id == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f2394,s_UNTAMED_WILDS_004f2384);
        bVar1 = false;
        local_14 = 0;
        while (((local_14 < 500 && (!bVar1)) &&
               (*(int *)(&DAT_006669f0 + local_14 * 4 + spell_id * 2000) != -1))) {
          if (*(int *)(&DAT_006669f0 + local_14 * 4 + spell_id * 2000) < 5) {
            bVar1 = true;
          }
          local_14 = local_14 + 1;
        }
        if (bVar1) {
          do {
            local_c = Pic_Load_advfac64_004d6639
                                (spell_id,(int *)(&DAT_006669f0 + spell_id * 2000),500,&DAT_006679f0
                                 ,1,&DAT_004f23a0);
            if (local_c == -1) break;
          } while (4 < *(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000));
        }
        else {
          local_c = -1;
          Pic_Load_advfac64_004d6639
                    (spell_id,(int *)(&DAT_006669f0 + spell_id * 2000),500,&DAT_006679f0,0,
                     &DAT_004f23a4);
        }
      }
      else {
        local_c = FUN_00408121(spell_id,spell_id,1);
        if ((local_c != -1) && (4 < *(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000))) {
          local_c = -1;
          local_14 = 0;
          while (((local_14 < 500 && (local_c == -1)) &&
                 (*(int *)(&DAT_006669f0 + local_14 * 4 + spell_id * 2000) != -1))) {
            if (*(int *)(&DAT_006669f0 + local_14 * 4 + spell_id * 2000) < 5) {
              local_c = local_14;
            }
            local_14 = local_14 + 1;
          }
        }
      }
      if ((local_c != -1) &&
         ((*(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000) == -1 ||
          (4 < *(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000))))) {
        local_c = -1;
      }
      if (((local_c != -1) && (*(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000) != -1)) &&
         (arg2 = FUN_004d695b(spell_id,*(int *)(&DAT_006669f0 + local_c * 4 + spell_id * 2000)),
         arg2 != -1)) {
        FUN_004d7acc(spell_id,local_c);
        FUN_004bda20(spell_id,arg2);
        FUN_00451482(0,0x30);
      }
      FUN_004d7946(spell_id);
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


