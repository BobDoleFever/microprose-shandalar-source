/*
 * Decompiled function: Mana_Init_0045b7d9
 * Entry Point: 0045b7d9
 * Size: 1202 bytes
 */
#include "magic.h"


undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int arg_2;
  char *str_2;
  int local_10;
  int local_c;
  
  if (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) {
    FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
    (&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] = (&DAT_0063eed0)[(1 - spell_id) * 4];
    FUN_0040d59c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if ((char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] < '\x01') {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
          local_10 = -1;
          local_c = 1;
          while ((local_c < 6 && (local_10 == -1))) {
            if ((0 < (&DAT_006b2d40)[local_c]) &&
               (((int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] &
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
          Pic_Subsystem_00424500(s_prompts_txt_0052442c,s_FELLWAR_STONE_0052441c);
          arg_2 = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,local_10,
                             (int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120]);
          if (arg_2 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_10._0_1_ = (byte)arg_2;
            if ((*(uint *)(&DAT_0063eed0 + (1 - spell_id) * 4) & 1 << ((byte)local_10 & 0x1f)) == 0)
            {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,arg_2,1);
            FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],
                         1);
            *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
            DAT_006ff2d4 = arg_2;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524438);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_2);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524444);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    if ((((flags == 0x77) && (target_id == g_OverworldMapGrid)) &&
        (spell_id == g_OverworldPlayerCoordX)) &&
       (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


