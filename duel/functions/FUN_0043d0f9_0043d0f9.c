/*
 * Decompiled function: FUN_0043d0f9
 * Entry Point: 0043d0f9
 * Size: 202 bytes
 */
#include "duel.h"


char * FUN_0043d0f9(undefined4 *arg_1)

{
  char *pcVar1;
  char *local_14;
  char *local_8;
  
  local_8 = (char *)*arg_1;
  if (*local_8 == '\"') {
    local_8 = local_8 + 1;
    local_14 = _strchr(local_8,0x22);
    *local_14 = '\0';
    if (local_14[1] == ',') {
      local_14 = local_14 + 2;
    }
    else {
      local_14 = local_14 + 3;
    }
  }
  else {
    local_14 = _strchr(local_8,0x2c);
    pcVar1 = _strchr(local_8,0xd);
    if (local_14 < pcVar1) {
      *local_14 = '\0';
      local_14 = local_14 + 1;
    }
    else {
      *pcVar1 = '\0';
      local_14 = pcVar1 + 2;
    }
  }
  *arg_1 = local_8;
  return local_14;
}


