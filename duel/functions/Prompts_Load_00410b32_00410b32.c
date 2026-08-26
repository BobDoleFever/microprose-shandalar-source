/*
 * Decompiled function: Prompts_Load_00410b32
 * Entry Point: 00410b32
 * Size: 716 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00410b32(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x73) {
    iVar1 = FUN_0049b309(spell_id,7,3);
    if ((((iVar1 == 0) || (DAT_00666458 != spell_id)) ||
        ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
          2) != 0)))) || (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0))
        && (iVar1 = FUN_0049b309(spell_id,7,3), iVar1 != 0)) &&
       ((DAT_00666458 == spell_id && (FUN_0042b6b0(spell_id,0,3), DAT_00681ea4 != 1)))) {
      FUN_00434660(s_prompts_txt_004f29a4,s_DISRUPTING_SCEPTER_004f2990);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Prompts_Load_00488150(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),0,0);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


