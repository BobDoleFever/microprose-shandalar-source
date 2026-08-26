/*
 * Decompiled function: Prompts_Load_004614c6
 * Entry Point: 004614c6
 * Size: 347 bytes
 */
#include "duel.h"


bool Prompts_Load_004614c6(int spell_id,int target_id,int flags)

{
  bool bVar1;
  
  if (flags == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    bVar1 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c34,s_PIRATE_SHIP_004f8c28);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    FUN_00461715(spell_id,target_id,flags);
    bVar1 = false;
  }
  return bVar1;
}


