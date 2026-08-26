/*
 * Decompiled function: Minit_Subsystem_004594d8
 * Entry Point: 004594d8
 * Size: 759 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004594d8(int spell_id,int target_id,int flags)

{
  int iVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    Pic_Subsystem_0042475a(s_prompts_txt_005242a4,s_PRIMAL_CLAY_00524298);
    iVar1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,1);
    iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (iVar2 != -1) {
      if (iVar1 == 0) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 1;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 6;
        (&DAT_0051aebd)[iVar2 * 0x34] = 0;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0;
      }
      else if (iVar1 == 1) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 2;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 2;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0x20;
      }
      else if (iVar1 == 2) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 3;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 3;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0;
      }
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = iVar2;
      *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
     ((g_OverworldMapGrid == target_id &&
      ((spell_id == g_OverworldPlayerCoordX &&
       (iVar1 = FUN_00471c32(spell_id,target_id), iVar1 != 0)))))) {
    g_ActivePalette =
         *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
  }
  if (((flags == 0x77) && (g_OverworldMapGrid == target_id)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    Mem_AllocOrFree_0041d942
              (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20));
  }
  return 0;
}


