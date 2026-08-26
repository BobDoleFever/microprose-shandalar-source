/*
 * Decompiled function: FUN_0041a245
 * Entry Point: 0041a245
 * Size: 636 bytes
 */
#include "magic.h"


uint FUN_0041a245(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x74) {
    if (((&g_MasterCardColorTable)[DAT_0068a708 * 0x34] & 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      Ai_GetOpponentPlayerScore(0);
      if (arg_1 == g_CurrentTurnPhase) {
        uVar1 = g_PlayerHandCardCount & 0x20;
      }
      else if (((g_PlayerHandCardCount & 0x20) == 0) || (g_DefendingPlayer != g_CurrentTurnPhase)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if (local_8 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) = local_8;
        (&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] = DAT_0063ee20;
      }
    }
    if (arg_3 == 0x71) {
      if (((*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) != -1) &&
          (((&g_CardSlot_Flags)
            [*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] & 0x20) != 0))
         && (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120
                       + (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) *
               0x34] & 0x40) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120),2);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


