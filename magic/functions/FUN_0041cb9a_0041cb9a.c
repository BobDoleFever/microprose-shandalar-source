/*
 * Decompiled function: FUN_0041cb9a
 * Entry Point: 0041cb9a
 * Size: 1029 bytes
 */
#include "magic.h"


uint FUN_0041cb9a(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = g_PlayerHandCardCount & 4;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) ==
          DAT_006ff2e0) {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_Toughness)
             [*(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)
              (&g_CardSlot_OriginalCardId +
              *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20);
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = g_TurnCounter;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
    }
    if (((arg_3 == 0x6e) &&
        (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) &&
        ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]))))
    {
      iVar2 = FUN_0040a305(*(int *)(&g_CardSlot_ConvertedManaCost +
                                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120),0,
                           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20))
      ;
      *(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) - iVar2;
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) - iVar2;
    }
    if (arg_3 == 0x73) {
      if (((g_PlayerHandCardCount & 4) == 0) || (iVar2 = FUN_0040d949(arg_1,7,1), iVar2 == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(arg_1,0,-1), g_ActivePlayer != 1)) {
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) +
             g_TurnCounter;
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


