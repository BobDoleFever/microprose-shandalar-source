/*
 * Decompiled function: Ai_Subsystem_004bbf8e
 * Entry Point: 004bbf8e
 * Size: 155 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bbf8e(int arg_1,int arg_2,int arg_3)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (6 < local_8) {
      return 1;
    }
    if (0 < *(int *)(arg_1 + local_8 * 4)) break;
    if (((*(int *)(arg_1 + local_8 * 4) == -1) && (arg_3 != -1)) && (arg_2 < arg_3)) {
      return 0;
    }
    if ((*(int *)(arg_1 + local_8 * 4) == -1) && (arg_3 == -1)) {
      return 0;
    }
    local_8 = local_8 + 1;
  }
  return 0;
}


