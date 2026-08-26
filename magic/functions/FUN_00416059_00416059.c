/*
 * Decompiled function: FUN_00416059
 * Entry Point: 00416059
 * Size: 208 bytes
 */
#include "magic.h"


undefined4 FUN_00416059(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      Card_DirectDamage_EvaluateBestTarget(arg_1,arg_2);
    }
    if (arg_3 == 0x71) {
      iVar2 = Card_DirectDamage_PromptAndDealDamage(arg_1,arg_2,0x71,4);
      if (iVar2 != 0) {
        Mem_AllocOrFree_0041df33(arg_1,2,arg_1,arg_2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


