/*
 * Decompiled function: Mana_Init_0045b502
 * Entry Point: 0040e289
 * Size: 727 bytes
 */
#include "duel.h"


undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint *arg2;
  int local_8;
  
  if (flags == 0x73) {
    iVar1 = FUN_0049b309(spell_id,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
          2) != 0)) || (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((flags == 0x6d) && (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      Ai_CalcManaRequirement_004ba890(spell_id,0,2);
      if (DAT_00681ea4 != 1) {
        if (spell_id == DAT_00676510) {
          local_8 = -1;
        }
        else if (DAT_0066aaf4 == 1) {
          local_8 = DAT_0068dd00 % 5 + 1;
          DAT_0068f2c8 = local_8;
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
          if (DAT_0068f2c8 < 6) {
            local_8 = DAT_0068f2c8;
          }
          else {
            DAT_00681ea4 = 1;
          }
        }
        if (DAT_00681ea4 != 1) {
          FUN_00434660(s_prompts_txt_004f28c8,s_CELESTIAL_PRISM_004f28b8);
          iVar1 = FUN_004513fa(spell_id,&DAT_006679f0,1,local_8,
                               (int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20]);
          if (iVar1 == -1) {
            DAT_00681ea4 = 1;
          }
          if (DAT_00681ea4 != 1) {
            FUN_0049b235(spell_id,iVar1,1);
            FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20],
                         1);
            *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
            DAT_0068f0f4 = iVar1;
            if (spell_id != DAT_00676510) {
              Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_to_produce_004f28d4);
              arg2 = (uint *)Mem_AllocOrFree_0048c420(iVar1);
              FUN_004d9640((uint *)&DAT_005f6810,arg2);
              FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_mana__004f28e0);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,0);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


