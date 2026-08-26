/*
 * Decompiled function: Glue_Subsystem_004df678
 * Entry Point: 00460e05
 * Size: 578 bytes
 */
#include "duel.h"


bool Glue_Subsystem_004df678(int spell_id,int target_id,int flags)

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
      FUN_00434660(s_prompts_txt_004f8c1c,s_PRODIGAL_SORCERER_004f8c08);
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
    if ((flags == 0x3b) &&
       ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00666738 + (1 - spell_id) * 4) =
           *(int *)(&DAT_00666738 + (1 - spell_id) * 4) + -1;
    }
    if ((((flags == 199) && (spell_id == DAT_00666458)) && (spell_id == DAT_00676504)) &&
       ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
    bVar1 = false;
  }
  return bVar1;
}


