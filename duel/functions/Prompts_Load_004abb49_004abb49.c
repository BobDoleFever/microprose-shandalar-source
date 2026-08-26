/*
 * Decompiled function: Prompts_Load_004abb49
 * Entry Point: 004abb49
 * Size: 1250 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004abb49(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 arg_12;
  uint uVar5;
  undefined4 arg_13;
  undefined4 arg_14;
  int iVar6;
  undefined4 arg_15;
  uint uVar7;
  undefined4 arg_16;
  uint uVar8;
  undefined4 arg_17;
  uint uVar9;
  undefined *arg_18;
  undefined4 arg_18_00;
  uint uVar10;
  uint uVar11;
  undefined4 arg_19;
  uint uVar12;
  int *arg_20;
  uint uVar13;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (DAT_0068ecd0 == -1) {
      FUN_0043071d(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      bVar2 = FUN_004af7bb(spell_id,target_id,4);
      iVar4 = 1 << (bVar2 & 0x1f);
      uVar3 = FUN_004521e2(spell_id,target_id);
      uVar3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uVar3,iVar4,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else {
      uVar12 = 0;
      uVar10 = 0;
      uVar9 = 2;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar4 = -1;
      uVar5 = 0;
      bVar2 = FUN_004af7bb(spell_id,target_id,4);
      iVar4 = Rules_ParseFilter_0041c0ab
                        (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,spell_id,2,2,0,0,0,0,0,
                         1 << (bVar2 & 0x1f),uVar5,iVar4,iVar6,uVar7,uVar8,uVar9,uVar10,uVar12);
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_00506434,s_BLUE_BLAST_00506428);
        arg_20 = &local_10;
        uVar3 = 1;
        arg_18 = &DAT_006679f0;
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar8 = 0;
        bVar2 = FUN_004af7bb(spell_id,target_id,4);
        uVar7 = 1 << (bVar2 & 0x1f);
        uVar5 = FUN_004521e2(spell_id,target_id);
        iVar4 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uVar5,uVar7,uVar8,iVar4,iVar6,
                           uVar9,uVar10,uVar12,uVar11,uVar13,arg_18,uVar3,arg_20);
        if (iVar4 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      if (DAT_0068ecd0 == -1) {
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar8 = 0;
        bVar2 = FUN_004af7bb(spell_id,target_id,4);
        uVar7 = 1 << (bVar2 & 0x1f);
        uVar5 = FUN_004521e2(spell_id,target_id);
        iVar4 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,uVar5,uVar7,uVar8,iVar4,iVar6,
                           uVar9,uVar10,uVar12,uVar11,uVar13);
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        uVar12 = 0;
        uVar10 = 0;
        uVar9 = 2;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar5 = 0;
        bVar2 = FUN_004af7bb(spell_id,target_id,4);
        iVar4 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0,0,0,0,0,1 << (bVar2 & 0x1f),uVar5,iVar4,
                           iVar6,uVar7,uVar8,uVar9,uVar10,uVar12);
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_10 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
        local_c = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
        cVar1 = (&DAT_006826dd)[local_c * 0x120 + local_10 * 0x5b20];
        bVar2 = FUN_004af7bb(spell_id,target_id,4);
        if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
          FUN_0046e571(local_10,local_c,2);
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


