/*
 * Decompiled function: Prompts_Load_004a805d
 * Entry Point: 004a805d
 * Size: 777 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004a805d(int spell_id,int target_id,int flags)

{
  int color_mask;
  int iVar1;
  undefined4 uVar2;
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
    if ((DAT_00676504 == spell_id) && (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
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
      uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,spell_id,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,
                           arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_0050620c,s_HOWL_FROM_BEYOND_005061f8);
      iVar1 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + (((DAT_0068f2c4 < 0x15) - 1 & 0xfffffffe) * 3 + 9) * -4;
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
        if ((DAT_00676504 == spell_id) &&
           (((&DAT_006826ce)
             [*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120] & 3) != 0)) {
          DAT_0068f2d4 = DAT_0068f2d4 + -99;
        }
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
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
                        (iVar1,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,
                         arg_13,iVar3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = FUN_004a2b00(spell_id,target_id,DAT_0066aaec,iVar1,color_mask);
        if (iVar1 != -1) {
          *(short *)(&DAT_006826d8 + iVar1 * 0x120 + spell_id * 0x5b20) =
               (short)*(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


