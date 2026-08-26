/*
 * Decompiled function: Minit_Subsystem_0045ea5b
 * Entry Point: 0045ea5b
 * Size: 388 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045ea5b(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = FUN_0040d949(arg_1,7,3);
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
        FUN_0040d875(arg_1,0,3);
        g_SpellStackDepth = g_SpellStackDepth + -0x24;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else {
        iVar2 = FUN_0040d949(arg_1,7,3);
        if ((iVar2 != 0) &&
           ((g_CurrentTurnPhase == arg_1 ||
            (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))) {
          Ai_CalcManaRequirement_004ba890(arg_1,0,3);
        }
      }
    }
    if (arg_3 == 0x72) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) ^ 0x10;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


