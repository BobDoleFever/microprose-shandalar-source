/*
 * Decompiled function: Glue_Subsystem_004e0c1c
 * Entry Point: 004623a9
 * Size: 580 bytes
 */
#include "duel.h"


bool Glue_Subsystem_004e0c1c(int spell_id,int target_id,int flags)

{
  int iVar1;
  bool bVar2;
  
  if (((flags == 199) && (iVar1 = FUN_0048a33f(spell_id,target_id), iVar1 != 0)) &&
     (3 < *(short *)(&DAT_006826d6 + target_id * 0x120 + spell_id * 0x5b20))) {
    if (spell_id == DAT_00676504) {
      DAT_0068f2d4 = DAT_0068f2d4 + 200;
    }
    else {
      DAT_0068f2d4 = DAT_0068f2d4 + -200;
    }
  }
  if (flags == 0x73) {
    bVar2 = (*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    bVar2 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c94,s_PSIONIC_ENTITY_004f8c84);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = FUN_004612b0(spell_id,target_id,0x72,2);
      if ((iVar1 != 0) &&
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) != -1)) {
        FUN_004af950(DAT_00690af0,DAT_0068efa0,3,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}


