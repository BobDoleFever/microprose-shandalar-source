/*
 * Decompiled function: Ai_Subsystem_004cced8
 * Entry Point: 004cced8
 * Size: 631 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cced8(void)

{
  int local_10;
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_0063ee50 + local_c * 4) = 0;
    *(undefined4 *)(&DAT_0063ee30 + local_c * 4) = *(undefined4 *)(&DAT_0063ee50 + local_c * 4);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0))
          && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 0x20) == 0)) {
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) < 5) {
          (&DAT_0063ee34)
          [local_8 * 8 + *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20)] =
               (&DAT_0063ee34)
               [local_8 * 8 + *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20)] + 1
          ;
        }
        else if ((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) <
                  g_MasterCardCount) ||
                (g_MasterCardCount + 0x10 <=
                 *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20))) {
          *(int *)(&DAT_0063ee30 + local_8 * 0x20) = *(int *)(&DAT_0063ee30 + local_8 * 0x20) + 1;
        }
        else {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if (*(int *)(&g_MasterCardTypeTable +
                        *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) ==
                (&DAT_006ff2c0)[local_10]) {
              (&DAT_0063ee34)[local_8 * 8 + local_10] = (&DAT_0063ee34)[local_8 * 8 + local_10] + 1;
            }
          }
        }
        *(int *)(&DAT_0063ee4c + local_8 * 0x20) = *(int *)(&DAT_0063ee4c + local_8 * 0x20) + 1;
      }
    }
  }
  return;
}


