/*
 * Decompiled function: Minit_Subsystem_00453c60
 * Entry Point: 00453c60
 * Size: 886 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00453c60(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(arg_1,arg_2,1,0);
    return uVar1;
  }
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      if ((((byte)g_PlayerHandCardCount & 4) == 0) ||
         (iVar2 = Ai_Subsystem_004cc814
                            (arg_1,s_Elephant_s_Graveyard__00523fb8,1,s_Regenerate_00523fac,
                             &DAT_00523fa4,(char *)0x0), iVar2 != 0)) {
        FUN_0040d875(arg_1,0,1);
        DAT_006ff2d4 = 0;
      }
      else {
        if ((local_c != -1) &&
           (((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
              * 0x34] == '\n' ||
            ((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
              * 0x34] == '\v')))) {
          (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
          *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
          *(uint *)(&g_CardSlot_Abilities2 +
                   *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities2 +
                        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) *
                          0x5b20) | 0x200;
        }
        FUN_0040d82b(arg_1,0,1);
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (((byte)g_PlayerHandCardCount & 4) == 0) {
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((((arg_3 == 0x34) &&
         (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
          g_OverworldMapGrid)) &&
        ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
       && (g_OverworldMapGrid != -1)) {
      g_ActivePalette = g_ActivePalette | 0x200;
    }
    return 0;
  }
  if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
    return 1;
  }
  return 0;
}


