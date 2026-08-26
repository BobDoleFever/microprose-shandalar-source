/*
 * Decompiled function: Pic_Subsystem_00439408
 * Entry Point: 00439408
 * Size: 987 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_00439408(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (iVar2 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120),
                                -1), iVar2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20) -
           *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20)) * 0xc;
    }
    if ((arg_3 == 0x82) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0))
    {
      *(uint *)(&DAT_006a6038 + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(uint *)(&DAT_006a6038 + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
           & 0xfffffffd;
      _DAT_006ff198 = _DAT_006ff198 | 2;
    }
    if (((g_ScWillyScore == 1) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) {
      if (((arg_3 == 0x7d) &&
          (iVar2 = FUN_00403250((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                                0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,
                                0x800,0), iVar2 == 0)) &&
         (iVar2 = FUN_00403250((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                               0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400
                               ,0), iVar2 != 0)) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (arg_3 == 0x7e) {
        if (g_DefendingPlayer == 1) {
          local_10 = g_DefendingPlayer;
          local_c = Pic_Subsystem_00441a42(1,2);
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,local_10,local_c,s_Opponent_chooses_to_untap__00521614,0);
        }
        else {
          Action_ValidateTarget_00405802
                    (g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,0x200,2,0,0,0,0,0,-1,-1,
                     0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Smoke__Select_creatur_00521630,0,
                     &local_10);
        }
        *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) | 2;
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
            local_8 = local_8 + 1) {
          iVar2 = FUN_00471c32(g_DefendingPlayer,local_8);
          if (((iVar2 != 0) &&
              (((&g_CardSlot_Flags)[local_8 * 0x120 + g_DefendingPlayer * 0x5b20] & 0x10) != 0)) &&
             ((((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_DefendingPlayer * 0x5b20) * 0x34]
               & 2) != 0 &&
              (((&DAT_006a6038)[local_8 * 0x120 + g_DefendingPlayer * 0x5b20] & 2) == 0)))) {
            *(uint *)(&DAT_006a6038 + local_8 * 0x120 + g_DefendingPlayer * 0x5b20) =
                 *(uint *)(&DAT_006a6038 + local_8 * 0x120 + g_DefendingPlayer * 0x5b20) &
                 0xfffffffe;
          }
        }
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


