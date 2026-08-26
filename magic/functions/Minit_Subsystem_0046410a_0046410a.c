/*
 * Decompiled function: Minit_Subsystem_0046410a
 * Entry Point: 0046410a
 * Size: 1157 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_0046410a(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     (iVar1 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),-1),
     iVar1 == 0)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) -
         *(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((arg_3 == 0x82) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint *)(&DAT_006a6038 + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) =
         *(uint *)(&DAT_006a6038 + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (((g_ScWillyScore == 1) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))))) {
    if ((arg_3 == 0x7d) &&
       ((iVar1 = FUN_00403250((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x800,
                              0), iVar1 == 0 &&
        (iVar1 = FUN_00403250((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400,
                              0), iVar1 != 0)))) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      if (g_DefendingPlayer == 1) {
        local_10 = g_DefendingPlayer;
        local_c = Pic_Subsystem_00441a42(1,1);
        Ai_Subsystem_004cc56d
                  (arg_1,arg_1,arg_2,local_10,local_c,s_Opponent_chooses_to_untap__00524684,0);
      }
      else {
        Action_ValidateTarget_00405802
                  (g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,0x200,1,0,0,0,0,0,-1,-1,
                   0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Winter_Orb__Select_la_005246a0,0,
                   &local_10);
      }
      *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) =
           *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) | 2;
      for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
          local_8 = local_8 + 1) {
        iVar1 = FUN_00471c32(g_DefendingPlayer,local_8);
        if ((((iVar1 != 0) &&
             (((&g_CardSlot_Flags)[g_DefendingPlayer * 0x5b20 + local_8 * 0x120] & 0x10) != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) * 0x34] &
             1) != 0)) && (((&DAT_006a6038)[g_DefendingPlayer * 0x5b20 + local_8 * 0x120] & 2) == 0)
           ) {
          *(uint *)(&DAT_006a6038 + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&DAT_006a6038 + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) & 0xfffffffe;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


