/*
 * Decompiled function: Minit_Subsystem_0045350d
 * Entry Point: 0045350d
 * Size: 670 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045350d(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((g_ScWillyScore < 0x1a) || (0x1d < g_ScWillyScore)) ||
         (iVar2 = Ai_Subsystem_004cc814
                            (arg_1,s_Desert__00523f64,1,s_Damage_00523f5c,&DAT_00523f54,(char *)0x0)
         , iVar2 != 0)) {
        FUN_0040d875(arg_1,0,1);
        DAT_006ff2d4 = 0;
      }
      else {
        iVar2 = CardTarget_PromptTargetCreature(arg_1,1 - arg_1,arg_2);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          if (((&g_CardSlot_Flags)
               [*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x44)
              != 0) {
            FUN_0041db67(*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),1,arg_1
                         ,arg_2);
          }
          (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
          FUN_0040d82b(arg_1,0,1);
          *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        }
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


