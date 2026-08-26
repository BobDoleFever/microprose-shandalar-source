/*
 * Decompiled function: CardTypeFromID
 * Entry Point: 00450799
 * Size: 137 bytes
 */
#include "duel.h"


int CardTypeFromID(int arg_1)

{
  int local_c;
  int local_8;
  
                    /* 0x50799  3  CardTypeFromID */
  if (arg_1 == -1) {
    local_8 = -1;
  }
  else {
    local_8 = -1;
    local_c = 0;
    while ((*(int *)(&DAT_004ff590 + local_c * 0x34) != -1 && (local_8 == -1))) {
      if (*(int *)(&DAT_004ff590 + local_c * 0x34) == arg_1) {
        local_8 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


