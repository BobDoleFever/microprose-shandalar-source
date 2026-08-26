/*
 * Decompiled function: Prompts_Load_00402cc1
 * Entry Point: 00402cc1
 * Size: 572 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00402cc1(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    if ((DAT_00676504 == spell_id) && (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      iVar1 = (&DAT_00681ea8)[spell_id];
      iVar3 = FUN_00404a71(spell_id,*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20))
      ;
      DAT_0068f2d4 = DAT_0068f2d4 - (iVar1 * 0x18) / iVar3;
      FUN_00434660(s_prompts_txt_004f2140,s_STREAMOFLIFE_004f2130);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      (&DAT_00681ea8)[*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20)] =
           (&DAT_00681ea8)[*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20)] +
           *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


