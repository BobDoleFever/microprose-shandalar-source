/*
 * Decompiled function: Card_BirdsOfParadise_TapForMana
 * Entry Point: 004e22b2
 * Size: 988 bytes
 */
#include "magic.h"


bool Card_BirdsOfParadise_TapForMana(int spell_id,int target_id,int flags)

{
  int arg_2;
  char *str_2;
  bool bVar1;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0;
  }
  else {
    if ((flags == 0x6d) &&
       (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      if ((spell_id == 1) || ((g_IsAiThinking == 1 || (DAT_006fedc0 != 0)))) {
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
        Pic_Subsystem_00424500(s_prompts_txt_0052ee5c,s_BIRDS_OF_PARADISE_0052ee48);
        arg_2 = Ai_Subsystem_004cc93d
                          (spell_id,&g_OverworldGoldAmount,1,local_10,
                           (int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120]);
        if (arg_2 == -1) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_0040d875(spell_id,arg_2,1);
          FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1)
          ;
          *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
               *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
          DAT_006ff2d4 = arg_2;
          if (spell_id != g_CurrentTurnPhase) {
            strcpy(&g_OverworldWorldState,s_to_produce_0052ee68);
            str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_2);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,s_mana__0052ee74);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
          }
        }
      }
    }
    if ((((flags == 0x7f) && (target_id == g_OverworldMapGrid)) &&
        (spell_id == g_OverworldPlayerCoordX)) &&
       ((*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_0040d59c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    if (((flags == 0x8a) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c +
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0063ee4c + spell_id * 0x20) + 2));
    }
    if (((flags == 0x8b) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0063ee4c + spell_id * 0x20) + 2));
    }
    bVar1 = false;
  }
  return bVar1;
}


