/*
 * Decompiled function: Duel_ResetCardAnimationState
 * Entry Point: 004f0d90
 * Size: 88 bytes
 */
#include "magic.h"


void Duel_ResetCardAnimationState(char arg1,char arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (999 < local_8) {
      return;
    }
    if ((&DAT_0067b9b0)[local_8] == '\0') break;
    local_8 = local_8 + 1;
  }
  (&DAT_0067b9b0)[local_8] = arg2 * '\x10' + arg1;
  return;
}


