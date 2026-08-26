/*
 * Decompiled function: Pic_Subsystem_00428320
 * Entry Point: 00428320
 * Size: 1278 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00428320(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (iVar4 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),
                                arg_1), iVar4 == 0)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((g_PlayerManaPool == 0xcf) && (g_ScWillyScore == 10)) &&
        ((g_DefendingPlayer == DAT_006a4b5c &&
         ((g_OverworldMapGrid == arg_2 && (g_OverworldPlayerCoordX == arg_1)))))) &&
       (DAT_006a4b5c == arg_1)) {
      if (arg_3 == 0x7d) {
        if (g_ActivePlayerPriority == arg_1) {
          if (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
            local_c = 0;
            bVar1 = false;
            while ((local_c < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase] && (!bVar1))) {
              iVar4 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20);
              if (((iVar4 != -1) &&
                  (((((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0
                    && (((&g_MasterCardColorTable)[iVar4 * 0x34] & 2) != 0)) &&
                   (((&g_CardSlot_Abilities2)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x20)
                    == 0)))) &&
                 (((iVar5 = g_CurrentTurnPhase * 0x5b20, cVar2 = FUN_0041d963(arg_1,arg_2,2),
                   (*(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + iVar5) &
                   1 << (cVar2 - 1U & 0x1f)) == 0 && ((&DAT_0051aebd)[iVar4 * 0x34] == '\0')) &&
                  (((&DAT_006a5f69)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 8) == 0)))) {
                bVar1 = true;
              }
              local_c = local_c + 1;
            }
            if ((bVar1) && (iVar4 = FUN_0040a1d2(8 - (&DAT_006b3008)[arg_1]), iVar4 == 0)) {
              *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
            }
          }
          if (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
            g_ActivePalette = g_ActivePalette | 2;
          }
        }
        else {
          g_ActivePalette = g_ActivePalette | 1;
        }
      }
      if (arg_3 == 0x7e) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
        *(undefined4 *)(&DAT_00680780 + arg_1 * 4) = 1;
        iVar4 = FUN_00410cc0(arg_1,arg_2,DAT_006a4b64,-1,-1);
        if (iVar4 != -1) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) | 0x400020;
          cVar2 = FUN_0041d963(arg_1,arg_2,2);
          *(uint *)(&g_CardSlot_ConvertedManaCost + iVar4 * 0x120 + arg_1 * 0x5b20) =
               1 << (cVar2 - 1U & 0x1f) | 0x20;
          if (((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
            *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) | 2;
            for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
              (&DAT_006a602f)[local_10 + arg_1 * 0x5b20 + iVar4 * 0x120] =
                   (&DAT_006a602f)[local_10 + arg_1 * 0x5b20 + arg_2 * 0x120];
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


