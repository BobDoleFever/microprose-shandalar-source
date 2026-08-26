/*
 * Decompiled function: Card_LordOfThePit_FindSacrificeCandidate
 * Entry Point: 004e2b99
 * Size: 230 bytes
 */
#include "magic.h"


int Card_LordOfThePit_FindSacrificeCandidate(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while ((local_c < (int)(&g_PlayerActiveCardCount)[arg1] && (local_8 == 0))) {
    if ((((*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) != -1) &&
         (((&g_CardSlot_Flags)[arg1 * 0x5b20 + local_c * 0x120] & 2) != 0)) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) * 0x34] & 2) != 0)) &&
       (local_c != arg2)) {
      local_8 = 1;
    }
    local_c = local_c + 1;
  }
  return local_8;
}


