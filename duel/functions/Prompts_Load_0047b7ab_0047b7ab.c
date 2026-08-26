/*
 * Decompiled function: Prompts_Load_0047b7ab
 * Entry Point: 0047b7ab
 * Size: 1016 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0047b7ab(int spell_id,int target_id,int flags)

{
  int color_mask;
  int iVar1;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  undefined4 local_14;
  int local_8;
  
  if (flags == 1) {
    local_14 = FUN_0047a090(spell_id,target_id,1,0);
  }
  else if (flags == 0x71) {
    local_14 = FUN_0047a090(spell_id,target_id,0x71,0);
  }
  else if (flags == 0x73) {
    local_14 = FUN_0047a090(spell_id,target_id,0x73,0);
  }
  else if (flags == 0x6d) {
    local_14 = 0;
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Get_mana__004f9af4);
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Sacrifice_to_destroy_a_land__004f9b00);
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f9b20);
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    if (DAT_00666748 == 0) {
      local_8 = 0;
    }
    else if (DAT_0068f220 == 0) {
      if (spell_id == DAT_00676510) {
        local_8 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,1);
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      local_14 = FUN_0047a090(spell_id,target_id,0x6d,0);
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    else if (local_8 == 1) {
      DAT_0068f0f4 = 0xffffffff;
      FUN_00434660(s_prompts_txt_004f9b38,s_STRIPMINE_004f9b2c);
      iVar1 = FUN_00468550(spell_id,1 - spell_id,target_id);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0xf);
        }
        FUN_0046e571(spell_id,target_id,3);
        FUN_0049b1eb(spell_id,0,1);
      }
    }
    else {
      DAT_00681ea4 = 1;
    }
    if (DAT_00681ea4 == 1) {
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
  }
  else {
    if ((flags == 0x72) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
      iVar1 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
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
                        (iVar1,color_mask,(undefined1 *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,
                         arg_13,iVar2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(iVar1,color_mask,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (flags == 0x7f) {
      local_14 = FUN_0047a090(spell_id,target_id,0x7f,0);
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}


