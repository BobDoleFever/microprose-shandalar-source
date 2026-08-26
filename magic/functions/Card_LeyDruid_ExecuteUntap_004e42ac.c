/*
 * Decompiled function: Card_LeyDruid_ExecuteUntap
 * Entry Point: 004e42ac
 * Size: 604 bytes
 */
#include "magic.h"


undefined4 Card_LeyDruid_ExecuteUntap(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = CardTarget_PromptTargetCreature(arg_1,0xffffffff,arg_2);
    if (iVar1 == 0) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
      g_ActivePlayer = 1;
    }
  }
  if ((arg_3 == 0x71) &&
     (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
    (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_CombatTarget)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(undefined4 *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)
          (&g_CardSlot_CardId +
          *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20);
    (&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_0051aebe)[*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34];
    *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
    (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    Magic_TriggerCardEvent(arg_1,arg_2,0x6c,1 - arg_1,0xffffffff);
  }
  return 0;
}


