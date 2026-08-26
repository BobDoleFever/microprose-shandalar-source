/*
 * Decompiled function: FUN_0040cc08
 * Entry Point: 0040cc08
 * Size: 118 bytes
 */
#include "magic.h"


int FUN_0040cc08(char *str_1)

{
  char *pcVar1;
  char cVar2;
  int local_8;
  
  local_8 = 0;
  if (str_1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    while (*str_1 != '\0') {
      pcVar1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = pcVar1;
      if (cVar2 == '\n') {
        local_8 = local_8 + 1;
      }
    }
    if (str_1[-1] != '\n') {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


