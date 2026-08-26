/*
 * Decompiled function: Pic_Subsystem_0043841c
 * Entry Point: 0043841c
 * Size: 1143 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043841c(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
      if (iVar2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e5c + (1 - arg_1) * 0x20) - *(int *)(&DAT_006b2e5c + arg_1 * 0x20))
        ;
      }
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == arg_2)) &&
       ((g_OverworldPlayerCoordX == arg_1 &&
        ((g_DefendingPlayer == arg_1 && (g_DefendingPlayer == DAT_0063edc0)))))) {
      *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if (arg_3 == 199) {
      if ((int)(&DAT_0063ee38)[arg_1 * 8] < 1) {
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
      else {
        iVar2 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar2 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        local_c = 0;
        for (local_8 = 0; local_8 < iVar2; local_8 = local_8 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
              && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
              & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
              iVar3 = FUN_004728c3(g_CurrentTurnPhase,local_8);
              if (iVar3 == 0) {
                local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                              local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                            local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
            }
          }
          if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
                -1) && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                        != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
                0x34] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0
               ) {
              iVar3 = FUN_004728c3(g_ActivePlayerPriority,local_8);
              if (iVar3 == 0) {
                local_c = local_c - *(short *)(&g_CardSlot_Counters +
                                              local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                            local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
            }
          }
        }
        g_SpellStackDepth = g_SpellStackDepth + local_c * 0xc;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


