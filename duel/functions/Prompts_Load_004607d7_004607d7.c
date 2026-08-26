/*
 * Decompiled function: Prompts_Load_004607d7
 * Entry Point: 004607d7
 * Size: 450 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004607d7(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (flags == 0x73) {
    iVar1 = FUN_0049b309(spell_id,4,2);
    if ((iVar1 == 0) || (iVar1 = FUN_0049b309(spell_id,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    uVar2 = 0;
  }
  else {
    if (flags == 0x6d) {
      DAT_0068ece0 = 1;
      FUN_0042b6b0(spell_id,4,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8bdc,s_BROTHERS_OF_FIRE_004f8bc8);
      }
      FUN_00461047(spell_id,target_id);
    }
    if (flags == 0x72) {
      iVar1 = FUN_004612b0(spell_id,target_id,0x72,1);
      if (iVar1 != 0) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffffffef;
        Mem_AllocOrFree_004afd1c(spell_id,1,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


