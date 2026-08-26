/*
 * Decompiled function: Ai_Subsystem_004b6f49
 * Entry Point: 004b6f49
 * Size: 93 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b6f49(char *str_1)

{
  char *local_c;
  char *local_8;
  
  if (str_1 != (char *)0x0) {
    local_8 = str_1;
  }
  for (local_c = &DAT_006ff310; (*local_c != '\0' && (*local_c != '-')); local_c = local_c + 1) {
    *local_8 = *local_c;
    local_8 = local_8 + 1;
  }
  *local_8 = '\0';
  return;
}


