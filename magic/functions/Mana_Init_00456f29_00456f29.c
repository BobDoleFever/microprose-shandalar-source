/*
 * Decompiled function: Mana_Init_00456f29
 * Entry Point: 00456f29
 * Size: 897 bytes
 */
#include "magic.h"


undefined4 Mana_Init_00456f29(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int arg_2;
  char *str_2;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_006b2d40)[local_c]) &&
             (((int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20] &
              1 << ((byte)local_c & 0x1f)) != 0)) {
            local_10 = local_c;
          }
          local_c = local_c + 1;
        }
        if ((local_10 == -1) && (0 < DAT_006b2d40)) {
          local_10 = 1;
        }
        if ((local_10 == -1) && (0 < DAT_006b2d58)) {
          local_10 = 1;
        }
        if (local_10 == -1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        local_10 = -1;
      }
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_005241ec,s_BLACK_LOTUS_005241e0);
        arg_2 = Ai_Subsystem_004cc93d
                          (spell_id,&g_OverworldGoldAmount,1,local_10,
                           (int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20]);
        if (arg_2 == -1) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_0040d875(spell_id,arg_2,3);
          DAT_006ff2d4 = arg_2;
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0xf);
          }
          *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          if (g_CurrentTurnPhase != spell_id) {
            strcpy(&g_OverworldWorldState,s_to_produce_005241f8);
            str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_2);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,s_mana__00524204);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
          }
          Pic_Subsystem_0044867e(spell_id,target_id,3);
        }
      }
    }
    if ((((flags == 0x7f) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0040d59c(spell_id,(int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20],3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


