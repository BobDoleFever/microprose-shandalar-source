/*
 * Decompiled function: Ai_Subsystem_004cb1d6
 * Entry Point: 004cb1d6
 * Size: 237 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cb1d6(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  do {
    if (1 < local_c) {
      return 0;
    }
    for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c]; local_8 = local_8 + 1) {
      if ((((char)(&g_CardSlot_Toughness)[local_8 * 0x120 + local_c * 0x5b20] == arg1) &&
          (*(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + local_c * 0x5b20) == arg2)) &&
         (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34) == 0x285
         )) {
        return 1;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


