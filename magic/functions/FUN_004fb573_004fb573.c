/*
 * Decompiled function: FUN_004fb573
 * Entry Point: 004fb573
 * Size: 322 bytes
 */
#include "magic.h"


undefined4 FUN_004fb573(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[arg_1] - (&g_PlayerCreatureCount)[1 - arg_1]) * 0x18;
    }
    if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
      do {
        iVar2 = Ai_Subsystem_004b7d38(s_Your_flip_00530550);
        iVar3 = Ai_Subsystem_004b7d38(s_Opponent_flip_0053055c);
        if (iVar2 == 1) {
          Mem_AllocOrFree_0041df33(0,1,arg_1,arg_2);
        }
        if (iVar3 == 1) {
          Mem_AllocOrFree_0041df33(1,1,arg_1,arg_2);
        }
        if ((iVar2 != 0) || (iVar3 != 0)) {
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,-1,-1,s_Repeating_since_a_tails_came_up__0053056c,0);
        }
      } while ((iVar2 != 0) || (iVar3 != 0));
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


