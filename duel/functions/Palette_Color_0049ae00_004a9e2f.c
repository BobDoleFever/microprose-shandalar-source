/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004a9e2f
 * Size: 607 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  char cVar1;
  int color_mask;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar4;
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
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_0050631c,s_CRUMBLE_00506314);
      iVar3 = FUN_00468831(spell_id,1 - spell_id,target_id);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (flags == 0x71) {
      iVar3 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0041c0ab
                        (iVar3,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,
                         arg_12,arg_13,iVar4,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        cVar1 = (&DAT_004ff597)
                [*(int *)(&DAT_006826c4 +
                         *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) *
                 0x34];
        iVar4 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 +
                                                 *(int *)(&DAT_00682718 +
                                                         target_id * 0x120 + spell_id * 0x5b20) *
                                                 0x5b20 + *(int *)(&DAT_0068271c +
                                                                  target_id * 0x120 +
                                                                  spell_id * 0x5b20) * 0x120) * 0x34
                                        ],0,99);
        (&DAT_00681ea8)[iVar3] = (&DAT_00681ea8)[iVar3] + cVar1 + iVar4;
        FUN_0046e571(iVar3,color_mask,2);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


