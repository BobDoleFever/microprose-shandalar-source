/*
 * Decompiled function: FUN_004d76dd
 * Entry Point: 004d76dd
 * Size: 88 bytes
 */
#include "duel.h"


void FUN_004d76dd(uint arg_1)

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
  FUN_004d7735(local_8);
  return;
}


