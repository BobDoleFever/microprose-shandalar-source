/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004097cf
 * Size: 492 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_004f26a0,s_DRAIN_POWER_004f2694);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_14);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      FUN_00467d65(FUN_004099bb,local_8);
      if (local_8 != spell_id) {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
          *(int *)(&DAT_0068f2e0 + local_c * 4 + spell_id * 0x20) =
               *(int *)(&DAT_0068f2e0 + local_c * 4 + spell_id * 0x20) +
               *(int *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20);
          *(undefined4 *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20) = 0;
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


