/*
 * Decompiled function: Prompts_Load_0040cfd7
 * Entry Point: 0040cfd7
 * Size: 472 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0040cfd7(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004348b2(s_prompts_txt_004f27e4,s_TETRAVUS_004f27d8);
  if (flags < 3) {
    if (flags < 2) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
  }
  else {
    local_10 = 2;
  }
  uVar1 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_006679f0 + local_10 * 0xfa,0);
  *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = uVar1;
  local_8 = (int)*(short *)(&DAT_006826d6 + target_id * 0x120 + spell_id * 0x5b20);
  if (*(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) <= flags) {
    local_c = 0;
    while ((local_c < *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) &&
           (0 < local_8))) {
      FUN_0046801f(spell_id,target_id,1);
      *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) | 0x2000000;
      local_8 = FUN_0048b81a(spell_id,target_id,0x33,0xffffffff);
      if (0 < local_8) {
        *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826fc + target_id * 0x120 + spell_id * 0x5b20) | 0x4000000;
        FUN_0048b81a(spell_id,target_id,0x32,0xffffffff);
      }
      local_c = local_c + 1;
    }
  }
  if (0 < DAT_0068f2c0) {
    DAT_0068f2c0 = DAT_0068f2c0 + -1;
  }
  return 0;
}


