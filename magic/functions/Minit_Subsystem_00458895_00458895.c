/*
 * Decompiled function: Minit_Subsystem_00458895
 * Entry Point: 00458895
 * Size: 882 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00458895(int arg_1,int arg_2,int arg_3)

{
  undefined1 uVar1;
  int iVar2;
  int local_18;
  
  if (arg_3 != 0x73) {
    if ((((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
       (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0)) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    if (((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) &&
       ((arg_1 == g_OverworldPlayerCoordX &&
        ((iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0 &&
         (Ai_CalcManaRequirement_004ba890(arg_1,0,2), local_18 != -1)))))) {
      iVar2 = FUN_0041d963(arg_1,arg_2,1);
      uVar1 = FUN_0041d963(arg_1,arg_2,1);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
           *(undefined4 *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
            *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120);
      *(int *)(&g_CardSlot_CardId +
              *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
           iVar2 + -1;
      (&DAT_006a5f4c)
      [*(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120] = uVar1;
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
               *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                    *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) |
           0x200;
    }
    if (((arg_3 == 0x77) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      iVar2 = Pic_Subsystem_0045268f(0x391);
      iVar2 = Pic_Subsystem_00451291(arg_1,iVar2);
      if (iVar2 != -1) {
        *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_1 * 0x5b20) | 2;
      }
    }
  }
  return 0;
}


