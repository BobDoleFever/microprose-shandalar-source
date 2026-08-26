/*
 * Decompiled function: Prompts_Load_0041491f
 * Entry Point: 0041491f
 * Size: 920 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0041491f(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   ((&DAT_00681ea8)[DAT_00676504] - (&DAT_00681ea8)[DAT_00676510]) * 0xc;
  }
  if (flags == 0x73) {
    if (((((byte)DAT_00681eb0 & 4) != 0) && (iVar1 = FUN_0049b309(spell_id,7,1), iVar1 != 0)) &&
       (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
          2) == 0)) &&
        ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
         (iVar1 = FUN_0041bcf0((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                               0xffffffff,0xffffffff,0,0,0), iVar1 != 0)))))) {
      return 99;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((flags == 0x6d) && (iVar1 = FUN_0049b309(spell_id,7,1), iVar1 != 0)) &&
       (FUN_0042b6b0(spell_id,0,1), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2a9c,s_JADE_MONOLITH_004f2a8c);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0x200,0
                         ,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      iVar1 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,0,0x200,0);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_00414cbc(local_c,local_8,spell_id);
      }
    }
  }
  return 0;
}


