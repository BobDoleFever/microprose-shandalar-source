/*
 * Decompiled function: Prompts_Load_0045bff5
 * Entry Point: 0045bff5
 * Size: 504 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045bff5(int spell_id,int target_id,int flags)

{
  int card_id;
  int color_mask;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar1;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a20,s_ROYAL_ASSASSIN_004f8a10);
    local_8 = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else {
    if (flags == 0x72) {
      card_id = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 1;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (card_id,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12
                         ,arg_13,iVar1,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(card_id,color_mask,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      local_8 = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
  }
  return local_8;
}


