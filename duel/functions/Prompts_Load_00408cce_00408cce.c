/*
 * Decompiled function: Prompts_Load_00408cce
 * Entry Point: 00408cce
 * Size: 642 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00408cce(int spell_id,int target_id,int flags)

{
  int arg_5;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (flags == 0x74) {
    if ((DAT_00676504 == spell_id) && (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
      FUN_00434660(s_prompts_txt_004f2658,s_DISINTEGRATE_004f2648);
      iVar1 = FUN_00461047(spell_id,target_id);
      if (iVar1 != 0) {
        iVar1 = FUN_00404a71(spell_id,*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20
                                              ));
        DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x30 / (longlong)iVar1);
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      arg_5 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = FUN_004612b0(spell_id,target_id,0x71,
                           *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 != 0) && (*(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        iVar3 = FUN_004a2b00(spell_id,target_id,DAT_00676514,iVar1,arg_5);
        if (iVar3 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar3 * 0x120 + spell_id * 0x5b20) = 0x200;
        }
        *(undefined4 *)(&DAT_006826fc + iVar1 * 0x5b20 + arg_5 * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


