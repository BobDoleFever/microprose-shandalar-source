/*
 * Decompiled function: Minit_Subsystem_00463cd1
 * Entry Point: 00416a4b
 * Size: 543 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_00463cd1(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x60;
  }
  if (flags == 0x73) {
    iVar1 = FUN_0049b309(spell_id,7,8);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
          2) != 0)))) || (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
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
    if (((flags == 0x6d) && (iVar1 = FUN_0049b309(spell_id,7,8), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,8), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2b2c,s_ALADDIN_RING_004f2b1c);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,4);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


