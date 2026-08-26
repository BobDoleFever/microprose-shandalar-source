/*
 * Decompiled function: FUN_0041a4c6
 * Entry Point: 0041a4c6
 * Size: 695 bytes
 */
#include "magic.h"


undefined4 FUN_0041a4c6(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0040360b
                        (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((arg_1 == g_CurrentTurnPhase) || (DAT_006b2d3c != -1)) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
    }
    if ((arg_3 == 0x38) && (1 < *(int *)(&DAT_0063edd8 + arg_1 * 0x20))) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (arg_3 == 0x71) {
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),1);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


