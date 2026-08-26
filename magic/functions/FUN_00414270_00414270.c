/*
 * Decompiled function: FUN_00414270
 * Entry Point: 00414270
 * Size: 813 bytes
 */
#include "magic.h"


undefined4 FUN_00414270(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if ((((g_PlayerManaPool == 0xd5) && (g_OverworldMapGrid == arg_2)) &&
      (g_OverworldPlayerCoordX == arg_1)) && (arg_1 == DAT_006a4b5c)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      iVar1 = Pic_Subsystem_0045268f(0x200);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        if ((g_IsAiThinking == 1) && (arg_1 == g_CurrentTurnPhase)) {
          (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
        }
        else {
          (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 2;
        }
      }
      iVar1 = Pic_Subsystem_0045268f(0xb5);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        (&g_PlayerCreatureCount)
        [(*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc] =
             (int)(&g_PlayerCreatureCount)
                  [(*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc]
             / 2;
      }
      iVar1 = Pic_Subsystem_0045268f(0x32);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,
                   arg_2);
      }
      iVar1 = Pic_Subsystem_0045268f(0x109);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          Mem_AllocOrFree_0041df33
                    (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120
                                     ),arg_1,arg_2);
          for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8];
              local_c = local_c + 1) {
            iVar1 = FUN_00471c32(local_8,local_c);
            if ((iVar1 != 0) &&
               (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) !=
                0)) {
              FUN_0041db67(local_8,local_c,
                           *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                           arg_1,arg_2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
  }
  return 0;
}


