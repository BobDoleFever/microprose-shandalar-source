/*
 * Decompiled function: FUN_00448412
 * Entry Point: 00448412
 * Size: 93 bytes
 */
#include "duel.h"


void FUN_00448412(char *str_1)

{
  char *local_c;
  char *local_8;
  
  if (str_1 != (char *)0x0) {
    local_8 = str_1;
  }
  for (local_c = &DAT_00664b90; (*local_c != '\0' && (*local_c != '-')); local_c = local_c + 1) {
    *local_8 = *local_c;
    local_8 = local_8 + 1;
  }
  *local_8 = '\0';
  return;
}


