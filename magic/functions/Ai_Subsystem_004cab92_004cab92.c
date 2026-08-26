/*
 * Decompiled function: Ai_Subsystem_004cab92
 * Entry Point: 004cab92
 * Size: 467 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cab92(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00695eb0 + local_8 * 4) = 0;
  }
  local_8 = 0;
  while( true ) {
    iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
    if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
        (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
      iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
    }
    if (iVar1 <= local_8) break;
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) {
      (**(code **)(&DAT_0051aec8 +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                  0x34))(g_CurrentTurnPhase,local_8,0x3b);
    }
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1) &&
       ((((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * 0x34]
         & 0x10) != 0)))) {
      (**(code **)(&DAT_0051aec8 +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
                  0x34))(g_ActivePlayerPriority,local_8,0x3b);
    }
    local_8 = local_8 + 1;
  }
  return;
}


