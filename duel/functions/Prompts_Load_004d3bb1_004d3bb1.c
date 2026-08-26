/*
 * Decompiled function: Prompts_Load_004d3bb1
 * Entry Point: 004d3bb1
 * Size: 946 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004d3bb1(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00509038,s_WILD_GROWTH_0050902c);
      iVar2 = FUN_00468550(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068edec + DAT_00676504 * 0x20) * 0xc;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar2,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_00682718)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (DAT_0068f0f4 != -1)))))) {
      FUN_0049b235((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],3,1);
    }
    if ((((flags == 0x7f) &&
         (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48)) &&
        ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0)) &&
       ((DAT_00690c48 != -1 &&
        (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 0x10) == 0)))) {
      FUN_0049b1a9(DAT_0068ecb0,3,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


