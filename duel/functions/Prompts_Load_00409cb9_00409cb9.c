/*
 * Decompiled function: Prompts_Load_00409cb9
 * Entry Point: 00409cb9
 * Size: 897 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00409cb9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int arg_2;
  uint *arg2;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
      if (((spell_id == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_0068ece0)[local_c]) &&
             (((int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20] &
              1 << ((byte)local_c & 0x1f)) != 0)) {
            local_10 = local_c;
          }
          local_c = local_c + 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ece0)) {
          local_10 = 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ecf8)) {
          local_10 = 1;
        }
        if (local_10 == -1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        local_10 = -1;
      }
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f26b8,s_BLACK_LOTUS_004f26ac);
        arg_2 = FUN_004513fa(spell_id,&DAT_006679f0,1,local_10,
                             (int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20]);
        if (arg_2 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0049b235(spell_id,arg_2,3);
          DAT_0068f0f4 = arg_2;
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0xf);
          }
          *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          if (DAT_00676510 != spell_id) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_to_produce_004f26c4);
            arg2 = (uint *)Mem_AllocOrFree_0048c420(arg_2);
            FUN_004d9640((uint *)&DAT_005f6810,arg2);
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_mana__004f26d0);
            FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,0);
          }
          FUN_0046e571(spell_id,target_id,3);
        }
      }
    }
    if ((((flags == 0x7f) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0049af5c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


