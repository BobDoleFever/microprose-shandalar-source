/*
 * Decompiled function: Minit_Subsystem_0045a252
 * Entry Point: 0045a252
 * Size: 472 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045a252(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  Pic_Subsystem_0042475a(s_prompts_txt_00524318,s_TETRAVUS_0052430c);
  if (flags < 3) {
    if (flags < 2) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
  }
  else {
    local_10 = 2;
  }
  uVar1 = Ai_Subsystem_004cc56d
                    (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount + local_10 * 0xfa,0);
  *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = uVar1;
  local_8 = (int)*(short *)(&DAT_006a5f46 + target_id * 0x120 + spell_id * 0x5b20);
  if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) <= flags) {
    local_c = 0;
    while ((local_c < *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) &&
           (0 < local_8))) {
      Card_RemoveCounters(spell_id,target_id,1);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000000;
      local_8 = FUN_00473179(spell_id,target_id,0x33,0xffffffff);
      if (0 < local_8) {
        *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x4000000;
        FUN_00473179(spell_id,target_id,0x32,0xffffffff);
      }
      local_c = local_c + 1;
    }
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return 0;
}


