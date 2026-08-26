/*
 * Decompiled function: Prompts_Load_004a9d72
 * Entry Point: 004a9d72
 * Size: 189 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004a9d72(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    FUN_0043071d(1);
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00506308,s_LIGHTNING_BOLT_005062f8);
      iVar2 = FUN_00461047(spell_id,target_id);
      if (iVar2 != 0) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
      }
    }
    if (flags == 0x71) {
      FUN_004612b0(spell_id,target_id,0x71,3);
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


