/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004aa08e
 * Size: 653 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  int color_mask;
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar3;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (flags == 0x74) {
    FUN_0043071d(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + (((DAT_0068f2c4 < 0x15) - 1 & 0xfffffffe) * 3 + 0xc) * -4;
      if (DAT_0068f2c4 < 0x15) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0xc;
      }
      FUN_00434660(s_prompts_txt_00506338,s_GIANT_GROWTH_00506328);
      iVar2 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0041c0ab
                        (iVar2,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,
                         arg_13,iVar3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar2 = FUN_004a2b00(spell_id,target_id,DAT_0066aaec,iVar2,color_mask);
        if (iVar2 != -1) {
          *(undefined2 *)(&DAT_006826d8 + iVar2 * 0x120 + spell_id * 0x5b20) = 3;
          *(undefined2 *)(&DAT_006826da + iVar2 * 0x120 + spell_id * 0x5b20) = 3;
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    if ((flags == 0x3b) && (iVar2 = FUN_0049b309(spell_id,3,1), iVar2 != 0)) {
      *(int *)(&DAT_00666730 + spell_id * 4) = *(int *)(&DAT_00666730 + spell_id * 4) + 3;
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 3;
    }
    uVar1 = 0;
  }
  return uVar1;
}


