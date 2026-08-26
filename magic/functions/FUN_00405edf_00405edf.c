/*
 * Decompiled function: FUN_00405edf
 * Entry Point: 00405edf
 * Size: 184 bytes
 */
#include "magic.h"


undefined4 FUN_00405edf(int arg1,int arg2)

{
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) < 5) {
    local_8 = 1;
  }
  else {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if ((&DAT_006ff2c0)[local_c] ==
          *(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)) {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


