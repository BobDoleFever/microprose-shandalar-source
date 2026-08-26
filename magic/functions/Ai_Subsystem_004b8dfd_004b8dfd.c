/*
 * Decompiled function: Ai_Subsystem_004b8dfd
 * Entry Point: 004b8dfd
 * Size: 80 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b8dfd(int arg1,int arg2)

{
  undefined4 local_8;
  
  if ((arg1 == 0) || (arg2 == 0)) {
    local_8 = 0;
  }
  else {
    local_8 = (arg1 - (arg2 + -1)) / arg2;
    if (local_8 < 1) {
      local_8 = 0;
    }
  }
  return local_8;
}


