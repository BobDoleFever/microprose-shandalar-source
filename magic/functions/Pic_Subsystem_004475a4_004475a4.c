/*
 * Decompiled function: Pic_Subsystem_004475a4
 * Entry Point: 004475a4
 * Size: 1142 bytes
 */
#include "magic.h"


void Pic_Subsystem_004475a4(void)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  if ((g_PlayerHandCardCount & 2) == 0) {
    return;
  }
  g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffd;
  g_PlayerHandCardCount = g_PlayerHandCardCount | 4;
  Ai_Subsystem_004cc9c5(0,0xff);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14]; local_18 = local_18 + 1
        ) {
      if (((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0) &&
          (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
        FUN_00473e69(local_14,local_18,0x21);
      }
    }
  }
  bVar1 = false;
  do {
    if ((g_IsAiThinking != 1) && (DAT_00633434 == 0)) {
      FUN_00472f0c(9,0xf);
      local_10 = -99999;
      bVar1 = true;
    }
    while( true ) {
      if ((DAT_006808a8 == 9) && (bVar1)) {
        Ai_GetActivePlayerScore();
        DAT_006b253c = 0;
        DAT_006b2538 = 0;
        DAT_006a2844 = 0;
        g_SpellStackDepth = 0;
      }
      iVar2 = FUN_00475c8a(-2,0xffffffff,s_Damage_prevention_005221a8,0x8e);
      if (iVar2 != 0) break;
      Magic_ScanCards(0x25);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
            local_18 = local_18 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0)
              && (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
             (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
            FUN_00473e69(local_14,local_18,0x6e);
          }
        }
      }
      FUN_00476205(g_DefendingPlayer,0xd7,s_Damage_Dealing_005221bc,0);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
            local_18 = local_18 + 1) {
          if ((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0)
             && (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0) {
              g_PlayerHandCardCount = g_PlayerHandCardCount | 2;
            }
            else {
              Pic_Subsystem_0044867e(local_14,local_18,1);
            }
          }
        }
      }
      Pic_Subsystem_00447a1a();
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffb;
      if (((g_IsAiThinking != 1) || (!bVar1)) || (DAT_006808a8 != 9)) {
        if (g_IsAiThinking == 1) {
          return;
        }
        if (!bVar1) {
          return;
        }
        DAT_00633434 = 0;
        return;
      }
      Pic_Subsystem_004488a0();
      iVar2 = Ai_SimulateCombatRound(g_ActivePlayerPriority);
      iVar2 = g_SpellStackDepth + iVar2;
      if (local_10 < iVar2) {
        Ai_ScoreBoardPosition();
        local_c = DAT_00680790;
        local_10 = iVar2;
      }
      if (DAT_006a2840 == 999) {
        DAT_006a2840 = -1;
      }
      DAT_006a2838 = 0;
      iVar2 = Mem_AllocOrFree_00501721();
      if ((DAT_006fe40c * DAT_0052244c) / 5 < iVar2) {
        g_IsAiThinking = 0;
        DAT_006a2840 = -1;
        DAT_00680790 = local_c;
      }
      g_PlayerHandCardCount = g_PlayerHandCardCount | 4;
    }
  } while( true );
}


