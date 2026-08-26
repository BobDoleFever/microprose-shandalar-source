/*
 * Decompiled function: Pic_Subsystem_0042ca53
 * Entry Point: 0042ca53
 * Size: 1040 bytes
 */
#include "magic.h"


int Pic_Subsystem_0042ca53(int arg1,int arg2)

{
  int iVar1;
  int arg1_00;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  undefined1 local_8;
  
  arg1_00 = 1 - arg1;
  iVar1 = *(int *)(&g_CardSlot_DisplayIndex + arg1 * 0x5b20 + arg2 * 0x120);
  iVar2 = Pic_Subsystem_00451291
                    (arg1_00,*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120));
  if (iVar2 != -1) {
    memcpy(&g_ActiveCardsInPlay + arg1_00 * 0x5b20 + iVar2 * 0x120,
           &g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20,0x120);
    if (*(int *)(&g_MasterCardTypeTable +
                *(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg1_00 * 0x5b20) * 0x34) != 0xab) {
      *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) | 0x30000;
    }
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) & 0xfffffff3;
    *(int *)(&DAT_007006e0 + iVar1 * 4) = arg1_00;
    *(int *)(&DAT_006a5750 + iVar1 * 4) = iVar2;
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
          local_18 = local_18 + 1) {
        local_8 = (undefined1)arg1_00;
        if (((char)(&g_CardSlot_Toughness)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&g_CardSlot_Toughness)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if (((char)(&g_CardSlot_DamageReceived)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_TypeFlags + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&g_CardSlot_DamageReceived)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&g_CardSlot_TypeFlags + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if ((&g_CardSlot_TurnPlayed)[local_18 * 0x120 + local_14 * 0x5b20] != '\0') {
          for (local_1c = 0;
              local_1c < (char)(&g_CardSlot_TurnPlayed)[local_18 * 0x120 + local_14 * 0x5b20];
              local_1c = local_1c + 1) {
            if ((*(int *)(&g_CardSlot_CombatTarget +
                         local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) == arg1) &&
               (*(int *)(&g_CardSlot_AttachedAura +
                        local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) == arg2)) {
              *(int *)(&g_CardSlot_CombatTarget +
                      local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) = arg1_00;
              *(int *)(&g_CardSlot_AttachedAura +
                      local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) = iVar2;
            }
          }
        }
      }
    }
  }
  *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  Pic_Subsystem_0044867e(arg1,arg2,4);
  return iVar2;
}


