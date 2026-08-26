/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00407a1e
 * Size: 533 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((DAT_00676504 == spell_id) && (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_004f2424,s_MINDTWIST_004f2418);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_10);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      for (local_8 = 0; local_8 < *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
          local_8 = local_8 + 1) {
        Palette_Color_0049ae00(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),1,0);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


