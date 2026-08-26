/*
 * Decompiled function: FUN_00505ea7
 * Entry Point: 00505ea7
 * Size: 386 bytes
 */
#include "magic.h"


void FUN_00505ea7(int arg_1)

{
  bool bVar1;
  
  if ((DAT_00627a88 == arg_1) && (DAT_00627a84 == g_DefendingPlayer)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((g_IsAiThinking != 1) &&
     (((*(uint *)(&DAT_00696740 + arg_1 * 4 + g_DefendingPlayer * 0x98) & 1) != 0 || (bVar1)))) {
    strcpy(&g_OverworldWorldState,s_Paused_005314e8);
    if (arg_1 == 4) {
      strcat(&g_OverworldWorldState,s___Upkeep_phase_005314f0);
    }
    if (arg_1 == 1) {
      strcat(&g_OverworldWorldState,s___Untap_phase_00531500);
    }
    if (arg_1 == 10) {
      strcat(&g_OverworldWorldState,s___Draw_phase_00531510);
    }
    if (arg_1 == 0x14) {
      strcat(&g_OverworldWorldState,s___Main_phase_00531520);
    }
    if (arg_1 == 0x1f) {
      strcat(&g_OverworldWorldState,s___Discard_phase_00531530);
    }
    if (arg_1 == 0x22) {
      strcat(&g_OverworldWorldState,s___Cleanup_phase_00531540);
    }
    if (arg_1 == 0x19) {
      strcat(&g_OverworldWorldState,s___First_strike_damage_resolution_00531550);
    }
    if (arg_1 == 0x1a) {
      strcat(&g_OverworldWorldState,s___Combat_damage_resolution_00531574);
    }
    FUN_00506029(&g_OverworldWorldState);
  }
  return;
}


