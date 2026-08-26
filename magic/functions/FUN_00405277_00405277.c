/*
 * Decompiled function: FUN_00405277
 * Entry Point: 00405277
 * Size: 249 bytes
 */
#include "magic.h"


int FUN_00405277(int arg1,int arg2)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_10 == 0))) {
    local_c = 0;
    while ((local_c < (int)(&g_PlayerActiveCardCount)[local_8] && (local_10 == 0))) {
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0) &&
          ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == arg1)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == arg2)) {
        local_10 = 1;
      }
      local_c = local_c + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_10;
}


