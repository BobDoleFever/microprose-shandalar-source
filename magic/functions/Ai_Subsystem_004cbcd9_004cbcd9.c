/*
 * Decompiled function: Ai_Subsystem_004cbcd9
 * Entry Point: 004cbcd9
 * Size: 137 bytes
 */
#include "magic.h"


int Ai_Subsystem_004cbcd9(int arg_1)

{
  int local_c;
  int local_8;
  
                    /* 0xcbcd9  3  CardTypeFromID */
  if (arg_1 == -1) {
    local_8 = -1;
  }
  else {
    local_8 = -1;
    local_c = 0;
    while ((*(int *)(&g_MasterCardTypeTable + local_c * 0x34) != -1 && (local_8 == -1))) {
      if (*(int *)(&g_MasterCardTypeTable + local_c * 0x34) == arg_1) {
        local_8 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


