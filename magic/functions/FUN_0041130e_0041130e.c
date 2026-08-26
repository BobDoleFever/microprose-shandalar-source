/*
 * Decompiled function: FUN_0041130e
 * Entry Point: 0041130e
 * Size: 1093 bytes
 */
#include "magic.h"


undefined4 FUN_0041130e(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    g_ActivePalette =
         g_ActivePalette | *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
    ;
  }
  if ((((arg_3 == 0x77) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
              g_OverworldPlayerCoordX &&
             ((g_OverworldMapGrid != -1 &&
              ((&DAT_006a5f50)
               [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] != '\x04')))
             ))) &&
     (*(int *)(&g_MasterCardTypeTable +
              *(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
              0x34) == 0x1a3)) {
    Pic_Subsystem_0044867e
              ((int)(char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20],
               *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20),2);
  }
  if ((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) {
    if ((&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x05') {
      if (((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) &&
         ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_006a4b5c)) {
        if (arg_3 == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (((arg_3 == 0x7e) || (arg_3 == 199)) &&
           (Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2),
           *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(arg_1,arg_2,2);
        }
      }
    }
    else if ((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
            ((arg_3 == 0x22 || (arg_3 == 199)))) {
      if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        *(undefined4 *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


