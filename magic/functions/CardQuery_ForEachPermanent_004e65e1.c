/*
 * Decompiled function: CardQuery_ForEachPermanent
 * Entry Point: 004e65e1
 * Size: 210 bytes
 */
#include "magic.h"


void CardQuery_ForEachPermanent(undefined *arg1,int arg2)

{
  int local_10;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if ((arg2 == -1) || (local_8 == arg2)) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
          local_10 = local_10 + 1) {
        if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
          (*(code *)arg1)(local_8,local_10,
                          *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20));
        }
      }
    }
  }
  return;
}


