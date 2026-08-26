/*
 * Decompiled function: Minit_Subsystem_0045a575
 * Entry Point: 0045a575
 * Size: 532 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id)

{
  bool bVar1;
  int iVar2;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined1 *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    Pic_Subsystem_00424500(s_prompts_txt_00524330,s_TETRAVITE_00524324);
    arg_20 = &local_10;
    arg_19 = 1;
    arg_18 = &g_OverworldGoldAmount;
    arg_17 = 0;
    arg_16 = 0;
    arg_15 = 0;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = -1;
    iVar2 = Pic_Subsystem_0045268f(0x37b);
    iVar2 = Action_ValidateTarget_00405802
                      (spell_id,2,2,0x200,0,0,0,0,0,0,iVar2,arg_12,arg_13,arg_14,arg_15,arg_16,
                       arg_17,arg_18,arg_19,arg_20);
    if (iVar2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      bVar1 = true;
      strcpy(&g_OverworldWorldState,s_Illegal_target__tetravite_not_re_0052433c);
      if ((((char)(&g_CardSlot_DamageReceived)[local_10 * 0x5b20 + local_c * 0x120] ==
            g_DialogPromptHwnd) &&
          (*(int *)(&g_CardSlot_TypeFlags + local_10 * 0x5b20 + local_c * 0x120) == g_DuelArenaHwnd)
          ) && (strcpy(&g_OverworldWorldState,s_Illegal_target__only_one_move_pe_00524370),
               *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) == 0))
      {
        Card_IncrementCounter(g_DialogPromptHwnd,g_DuelArenaHwnd);
        Pic_Subsystem_0044867e(local_10,local_c,4);
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) + 1;
        local_8 = local_8 + 1;
        bVar1 = false;
      }
      if ((bVar1) && (g_IsAiThinking != 1)) {
        Ai_Util_004cc42d(&g_OverworldWorldState);
        Sleep(2000);
        Ai_Util_004cc42d(&DAT_0052439c);
      }
    }
  } while ((g_ActivePlayer != 1) && (local_8 == 0));
  g_OverworldWorldState = 0;
  return 0;
}


