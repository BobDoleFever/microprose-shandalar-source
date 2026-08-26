/*
 * Decompiled function: Prompts_Load_004a6bd4
 * Entry Point: 004a6bd4
 * Size: 448 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004a6bd4(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00506150,s_MANASHORT_00506144);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&DAT_006679f0,1,&local_10);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      FUN_00467d65(FUN_004a6d94,iVar2);
      for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
        *(undefined4 *)(&DAT_0068f2e0 + local_8 * 4 + iVar2 * 0x20) = 0;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


