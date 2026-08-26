/*
 * Decompiled function: Card_RockHydra_UpdateStatsFromHeads
 * Entry Point: 004e35e4
 * Size: 332 bytes
 */
#include "magic.h"


void Card_RockHydra_UpdateStatsFromHeads(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      iVar3 = FUN_00471c32(local_8,local_c);
      if (((iVar3 != 0) &&
          ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == arg_1)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == arg_2)) {
        cVar1 = (&DAT_006a5f4d)[local_c * 0x120 + local_8 * 0x5b20];
        bVar2 = FUN_0041d9d2(arg_1,arg_2,arg_3);
        if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 4) != 0))
        {
          Pic_Subsystem_0044867e(local_8,local_c,1);
        }
      }
    }
  }
  return;
}


