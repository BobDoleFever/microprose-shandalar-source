/*
 * Decompiled function: Pic_Subsystem_0042ce63
 * Entry Point: 0042ce63
 * Size: 2028 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042ce63(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_10;
  
  iVar1 = *(int *)(&g_CardSlot_DisplayIndex + y * 0x120 + x * 0x5b20);
  iVar2 = *(int *)(&g_CardSlot_DisplayIndex + height * 0x120 + width * 0x5b20);
  iVar3 = Pic_Subsystem_00451291(x,*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20));
  if (iVar3 == -1) {
    uVar4 = 0;
  }
  else {
    iVar5 = Pic_Subsystem_00451291(width,*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20));
    if (iVar5 == -1) {
      *(undefined4 *)(&g_CardSlot_CardId + iVar3 * 0x120 + x * 0x5b20) = 0xffffffff;
      uVar4 = 0;
    }
    else {
      memcpy(&g_ActiveCardsInPlay + x * 0x5b20 + iVar3 * 0x120,
             &g_ActiveCardsInPlay + width * 0x5b20 + height * 0x120,0x120);
      memcpy(&g_ActiveCardsInPlay + width * 0x5b20 + iVar5 * 0x120,
             &g_ActiveCardsInPlay + x * 0x5b20 + y * 0x120,0x120);
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + iVar3 * 0x120 + x * 0x5b20) * 0x34) != 0xab) {
        *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) | 0x30000;
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + iVar5 * 0x120 + width * 0x5b20) * 0x34) != 0xab) {
        *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) | 0x30000;
      }
      *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) & 0xfffffff3;
      *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) & 0xfffffff3;
      *(int *)(&DAT_007006e0 + iVar1 * 4) = width;
      *(int *)(&DAT_006a5750 + iVar1 * 4) = iVar5;
      *(int *)(&DAT_007006e0 + iVar2 * 4) = x;
      *(int *)(&DAT_006a5750 + iVar2 * 4) = iVar3;
      *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) | 0x400000;
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_10];
            local_1c = local_1c + 1) {
          if (((char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if (((char)(&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if ((&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == x) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == y)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = width;
                *(int *)(&g_CardSlot_AttachedAura +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = iVar5;
              }
            }
          }
          if (((char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) == height)
             ) {
            (&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if (((char)(&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) == height)) {
            (&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if ((&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == width) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == height)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = x;
                *(int *)(&g_CardSlot_AttachedAura +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = iVar3;
              }
            }
          }
        }
      }
      *(undefined4 *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = 0xffffffff;
      *(undefined4 *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) = 0xffffffff;
      FUN_00472fae();
      uVar4 = 1;
    }
  }
  return uVar4;
}


