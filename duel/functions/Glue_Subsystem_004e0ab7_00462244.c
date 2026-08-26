/*
 * Decompiled function: Glue_Subsystem_004e0ab7
 * Entry Point: 00462244
 * Size: 357 bytes
 */
#include "duel.h"


bool Glue_Subsystem_004e0ab7(int spell_id,int target_id,int flags)

{
  int iVar1;
  bool bVar2;
  
  if (flags == 0x73) {
    bVar2 = (*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    bVar2 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c78,s_ORCISH_ARTILLERY_004f8c64);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = FUN_004612b0(spell_id,target_id,0x72,2);
      if (iVar1 != 0) {
        Mem_AllocOrFree_004afd1c(spell_id,3,spell_id,target_id);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}


