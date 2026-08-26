/*
 * Decompiled function: Minit_Subsystem_00463723
 * Entry Point: 00463723
 * Size: 1261 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00463723(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    iVar1 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
    if (iVar1 == 0) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + (1 - arg_1) * 0x20) - *(int *)(&DAT_006b2e5c + arg_1 * 0x20)) *
           0xc;
    }
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      local_c = 0;
      while( true ) {
        iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34] &
            2) != 0)) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,local_c,2);
        }
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1
             ) && (((&g_CardSlot_Flags)[local_c * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0
                  )) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) != 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,local_c,2);
        }
        local_c = local_c + 1;
      }
      Pic_Subsystem_004488a0();
      local_c = 0;
      while( true ) {
        iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           ((((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 0x44) != 0 &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 2) == 0)))) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,local_c,2);
        }
        if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
               -1) && (((&g_CardSlot_Flags)[local_c * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                       != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
               0x34] & 0x44) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) == 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,local_c,2);
        }
        local_c = local_c + 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


