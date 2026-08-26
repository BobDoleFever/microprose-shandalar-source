/*
 * Decompiled function: FUN_0040f636
 * Entry Point: 0040f636
 * Size: 75 bytes
 */
#include "magic.h"


int FUN_0040f636(char *str_1)

{
  char *pcVar1;
  char cVar2;
  int local_8;
  
  local_8 = 0;
  while (*str_1 != '\0') {
    pcVar1 = str_1 + 1;
    cVar2 = *str_1;
    str_1 = pcVar1;
    if (cVar2 == '\n') {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


