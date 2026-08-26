/*
 * Decompiled function: Card_KhabalGhoul_CheckCreatureDeath
 * Entry Point: 004e12cf
 * Size: 1614 bytes
 */
#include "magic.h"


undefined4 Card_KhabalGhoul_CheckCreatureDeath(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) == DAT_006ff2e0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)) &&
      ((*(int *)(&g_CardSlot_TypeFlags +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2 &&
       ((char)(&g_CardSlot_DamageReceived)
              [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1)))) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != -1 &&
      ((((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId +
                          g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)
                        [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] * 0x5b20) *
          0x34] & 2) != 0 &&
       (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) < 0x13)))))) {
    *(undefined4 *)
     (&g_CardSlot_AttachedAura +
     arg_2 * 0x120 +
     arg_1 * 0x5b20 + *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) * 8) =
         *(undefined4 *)
          (&g_CardSlot_OriginalCardId +
          g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20);
    *(int *)(&g_CardSlot_CombatTarget +
            arg_2 * 0x120 +
            arg_1 * 0x5b20 + *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) * 8)
         = (int)(char)(&g_CardSlot_Toughness)
                      [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20];
    *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if (arg_3 == 0x77) {
    bVar1 = false;
    for (local_8 = 0; local_8 < *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
        local_8 = local_8 + 1) {
      if (((*(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) ==
            g_OverworldMapGrid) &&
          (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) ==
           g_OverworldPlayerCoordX)) &&
         ((&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] != '\x04'))
      {
        local_c = local_8;
        if (!bVar1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
          bVar1 = true;
        }
        while (local_c = local_c + 1,
              local_c < *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          *(undefined4 *)(&DAT_006a5f80 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8) =
               *(undefined4 *)
                (&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8);
          *(undefined4 *)(&DAT_006a5f84 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8) =
               *(undefined4 *)
                (&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8);
        }
        *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) + -1;
      }
    }
  }
  if (((g_PlayerManaPool == 0xd5) &&
      (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) &&
     ((DAT_006a4b5c == arg_1 &&
      ((arg_2 == g_OverworldMapGrid && (arg_1 == g_OverworldPlayerCoordX)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      Card_AddCounters(arg_1,arg_2,
                       *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


