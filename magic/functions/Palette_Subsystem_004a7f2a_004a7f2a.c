/*
 * Decompiled function: Palette_Subsystem_004a7f2a
 * Entry Point: 004a7f2a
 * Size: 487 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a7f2a(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_504 [320];
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,3,2);
    if ((iVar1 == 0) || (iVar1 = FUN_0040d949(arg_1,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(arg_1,3,2);
      if (g_ActivePlayer != 1) {
        uVar2 = FUN_0040a1d2(0x14);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar2;
        iVar1 = Palette_Subsystem_004a7bcd(arg_1,arg_2,(int)local_504);
        iVar1 = FUN_0040a1d2(iVar1);
        *(undefined4 *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) =
             local_504[iVar1 * 2];
        *(undefined4 *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) =
             local_504[iVar1 * 2 + 1];
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if ((arg_3 == 0x72) && ((&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')) {
      Palette_Subsystem_004a8111
                (arg_1,arg_2,
                 *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    uVar2 = 0;
  }
  return uVar2;
}


