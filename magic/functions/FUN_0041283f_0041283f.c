/*
 * Decompiled function: FUN_0041283f
 * Entry Point: 0041283f
 * Size: 1750 bytes
 */
#include "magic.h"


undefined4 FUN_0041283f(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
    if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
       && (g_OverworldMapGrid != -1)) {
      if (arg_3 == 0x34) {
        g_ActivePalette =
             g_ActivePalette |
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      if (arg_3 == 0x32) {
        g_ActivePalette =
             g_ActivePalette + (int)*(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (((g_OverworldMapGrid == arg_2) && (arg_1 == g_OverworldPlayerCoordX)) &&
       ((arg_3 == 0x22 &&
        ((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1 &&
         (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x40) != 0))))
       )) {
      (&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] = 5;
    }
  }
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0) {
    if (((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
          g_OverworldMapGrid)) &&
        (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != -1))
    {
      iVar1 = FUN_0041d963(arg_1,arg_2,
                           *(int *)(&g_CardSlot_ConvertedManaCost +
                                   *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20)
                                   * 0x120 + (char)(&g_CardSlot_DamageReceived)
                                                   [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20));
      g_ActivePalette = iVar1 - 1;
    }
    if (((arg_3 == 0x77) &&
        ((char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
         g_OverworldPlayerCoordX)) &&
       (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)) {
      *(uint *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) |
           0x1000000;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  if (((&DAT_006a5f6a)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
    if ((arg_3 == 0x6a) && (arg_1 == g_DefendingPlayer)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
      *(undefined4 *)(&DAT_00680780 + arg_1 * 4) = 0;
    }
    if ((arg_3 == 0x79) &&
       ((*(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) &
        *(uint *)(&g_CardSlot_Abilities2 +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)) == 0)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
    if ((arg_3 == 0x6a) && (DAT_006ff2d8 == -1)) {
      DAT_006ff2d8 = arg_1;
    }
    if ((arg_3 == 0x22) && (DAT_007006d4 == 0)) {
      DAT_007006d4 = 1 << ((byte)arg_1 & 0x1f);
      *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffffdf;
    }
  }
  if ((g_OverworldMapGrid == arg_2) && (arg_1 == g_OverworldPlayerCoordX)) {
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
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


