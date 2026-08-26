/*
 * Decompiled function: Prompts_Load_004cabfe
 * Entry Point: 004cabfe
 * Size: 819 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004cabfe(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
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
    uVar3 = FUN_004521e2(spell_id,target_id);
    uVar3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508c68,s_SEEKER_00508c60);
      iVar4 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
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
    if (((flags == 0x78) &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_0068ecfc)) &&
       (((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00690310 &&
        ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(spell_id,target_id,5);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) == 0) {
        DAT_0066642c = DAT_0066642c + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


