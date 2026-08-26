/*
 * Decompiled function: Mana_Init_0045b7d9
 * Entry Point: 0040e560
 * Size: 1202 bytes
 */
#include "duel.h"


undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int arg_2;
  uint *arg2;
  int local_10;
  int local_c;
  
  if (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) {
    FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],1);
    (&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20] = (&DAT_0068f360)[(1 - spell_id) * 4];
    FUN_0049af5c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],1);
  }
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
      if ((char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20] < '\x01') {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
      else {
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
          FUN_00434660(s_prompts_txt_004f28f8,s_FELLWAR_STONE_004f28e8);
          arg_2 = FUN_004513fa(spell_id,&DAT_006679f0,1,local_10,
                               (int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20]);
          if (arg_2 == -1) {
            DAT_00681ea4 = 1;
          }
          else {
            local_10._0_1_ = (byte)arg_2;
            if ((*(uint *)(&DAT_0068f360 + (1 - spell_id) * 4) & 1 << ((byte)local_10 & 0x1f)) == 0)
            {
              DAT_00681ea4 = 1;
            }
          }
          if (DAT_00681ea4 != 1) {
            FUN_0049b235(spell_id,arg_2,1);
            FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],
                         1);
            *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
            DAT_0068f0f4 = arg_2;
            if (spell_id != DAT_00676510) {
              Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_to_produce_004f2904);
              arg2 = (uint *)Mem_AllocOrFree_0048c420(arg_2);
              FUN_004d9640((uint *)&DAT_005f6810,arg2);
              FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_mana__004f2910);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,0);
            }
          }
        }
      }
    }
    if ((((flags == 0x77) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


