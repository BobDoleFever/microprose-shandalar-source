/*
 * Decompiled function: Prompts_Load_00454179
 * Entry Point: 00454179
 * Size: 573 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00454179(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_004f8834,s_VESUVAN_DOPPELGANGER_004f881c);
    iVar1 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &DAT_006679f0,1,(int *)local_c);
    if (iVar1 == 0) {
      FUN_0046e571(spell_id,target_id,1);
      DAT_00681ea4 = 1;
    }
    else {
      (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = local_c[0];
      *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) = local_8;
    }
  }
  if (flags == 0x71) {
    *(undefined4 *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(undefined4 *)
          (&DAT_006826c4 +
          *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
    (&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20] =
         (&DAT_004ff596)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34];
    *(uint *)(&DAT_006826f8 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006826f8 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000;
    FUN_0048c907(spell_id,target_id,0x6c,1 - spell_id,0xffffffff);
  }
  return 0;
}


