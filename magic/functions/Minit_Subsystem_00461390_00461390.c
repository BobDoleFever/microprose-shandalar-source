/*
 * Decompiled function: Minit_Subsystem_00461390
 * Entry Point: 00461390
 * Size: 1053 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_00461390(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
     (iVar1 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),-1),
     iVar1 != 0)) {
    g_SpellStackDepth = g_SpellStackDepth + -0xf0;
  }
  if (((arg_3 == 0x82) &&
      (iVar1 = FUN_00473179(g_OverworldPlayerCoordX,g_OverworldMapGrid,0x32,0xffffffff), 2 < iVar1))
     && ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint *)(&DAT_006a6038 + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) =
         *(uint *)(&DAT_006a6038 + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (arg_3 == 199) {
    iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
    if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
        (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
      iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
    }
    local_c = 0;
    for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20))) {
        if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_004728c3(g_CurrentTurnPhase,local_8);
          if (iVar2 == 0) {
            local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                          local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                        local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
        }
      }
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20)))
      {
        if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_004728c3(g_ActivePlayerPriority,local_8);
          if (iVar2 == 0) {
            local_c = local_c - *(short *)(&g_CardSlot_Counters +
                                          local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                        local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
        }
      }
    }
    g_SpellStackDepth = g_SpellStackDepth + local_c * 0xc;
  }
  return 0;
}


