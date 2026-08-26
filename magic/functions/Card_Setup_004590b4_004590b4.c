/*
 * Decompiled function: Card_Setup_004590b4
 * Entry Point: 004590b4
 * Size: 506 bytes
 */
#include "magic.h"


undefined4 Card_Setup_004590b4(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer && (DAT_0063edc0 == arg_1)))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
  }
  if (((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    if ((int)(&DAT_006b3008)[arg_1] < 1) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    else {
      Prompts_Load_0046fa40(arg_1,0,1);
    }
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Unable_to_discard____Mishra_s_Wa_00524248,0);
    *(uint *)(&g_CardSlot_Flags +
             *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x10;
    Mem_AllocOrFree_0041df33(arg_1,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
     (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if ((arg_3 == 199) && ((&DAT_006b3008)[arg_1] != 0)) {
    Mem_AllocOrFree_0041df33(arg_1,3,arg_1,arg_2);
    g_SpellStackDepth = g_SpellStackDepth + 0x60;
  }
  return 0;
}


