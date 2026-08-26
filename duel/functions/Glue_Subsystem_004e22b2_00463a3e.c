/*
 * Decompiled function: Glue_Subsystem_004e22b2
 * Entry Point: 00463a3e
 * Size: 988 bytes
 */
#include "duel.h"


bool Glue_Subsystem_004e22b2(int spell_id,int target_id,int flags)

{
  int arg_2;
  uint *arg2;
  bool bVar1;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0;
  }
  else {
    if ((flags == 0x6d) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      if ((spell_id == 1) || ((DAT_0066aaf4 == 1 || (DAT_0068f0b0 != 0)))) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_0068ece0)[local_c]) &&
             (((int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120] &
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
        FUN_00434660(s_prompts_txt_004f8cf0,s_BIRDS_OF_PARADISE_004f8cdc);
        arg_2 = FUN_004513fa(spell_id,&DAT_006679f0,1,local_10,
                             (int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120]);
        if (arg_2 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0049b235(spell_id,arg_2,1);
          FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120],1)
          ;
          *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
               *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
          DAT_0068f0f4 = arg_2;
          if (spell_id != DAT_00676510) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_to_produce_004f8cfc);
            arg2 = (uint *)Mem_AllocOrFree_0048c420(arg_2);
            FUN_004d9640((uint *)&DAT_005f6810,arg2);
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_mana__004f8d08);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,0);
          }
        }
      }
    }
    if ((((flags == 0x7f) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
       ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_0049af5c(spell_id,(int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c +
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + spell_id * 0x20) + 2));
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + spell_id * 0x20) + 2));
    }
    bVar1 = false;
  }
  return bVar1;
}


