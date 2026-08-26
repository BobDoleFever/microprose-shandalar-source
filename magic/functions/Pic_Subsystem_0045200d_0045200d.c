/*
 * Decompiled function: Pic_Subsystem_0045200d
 * Entry Point: 0045200d
 * Size: 88 bytes
 */
#include "magic.h"


void Pic_Subsystem_0045200d(uint arg_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if ((*(uint *)(&deck + local_8 * 4) & 0xfff) == arg_1) break;
    local_8 = local_8 + 1;
  }
  Pic_Subsystem_00452065(local_8);
  return;
}


