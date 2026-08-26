/*
 * Decompiled function: Pic_Subsystem_0045245e
 * Entry Point: 0045245e
 * Size: 125 bytes
 */
#include "magic.h"


int Pic_Subsystem_0045245e(int arg1,undefined4 arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) = arg2;
  return local_8;
}


