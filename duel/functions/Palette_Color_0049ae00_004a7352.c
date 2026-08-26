/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004a7352
 * Size: 434 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  int color_mask;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (flags == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,0,0,0,0xffffffff,0xffffffff,
                         0xffffffff,0xffffffff,0,0,0);
  }
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_0050619c,s_SHATTER_00506194);
      iVar2 = FUN_00468831(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x10;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      color_mask = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      iVar3 = Rules_ParseFilter_0041c0ab
                        (iVar2,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,0x40,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(iVar2,color_mask,1);
      }
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


