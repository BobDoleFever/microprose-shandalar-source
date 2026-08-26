/*
 * Decompiled function: Minit_Subsystem_00463ef0
 * Entry Point: 00416c6a
 * Size: 537 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ed2c + DAT_00676504 * 0x20) * 3 + -6) * 4;
  }
  if (flags == 0x73) {
    iVar1 = FUN_0049b309(spell_id,7,3);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] &
          2) != 0)))) || (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) && (Ai_CalcManaRequirement_004ba890(spell_id,0,3), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2b44,s_ROD_OF_RUIN_004f2b38);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


