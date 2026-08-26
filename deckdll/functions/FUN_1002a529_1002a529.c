/*
 * Decompiled function: FUN_1002a529
 * Entry Point: 1002a529
 * Size: 205 bytes
 */
#include "deckdll.h"


char * FUN_1002a529(int32_t *arg_1)

{
  char *char_ptr_1;
  char *local_14;
  char *local_8;
  
  local_8 = (char *)*arg_1;
  if (*local_8 == '\"') {
    local_8 = local_8 + 1;
    local_14 = strchr(local_8,0x22);
    *local_14 = '\0';
    if (local_14[1] == ',') {
      local_14 = local_14 + 2;
    }
    else {
      local_14 = local_14 + 3;
    }
  }
  else {
    local_14 = strchr(local_8,0x2c);
    char_ptr_1 = strchr(local_8,0xd);
    if (local_14 < char_ptr_1) {
      *local_14 = '\0';
      local_14 = local_14 + 1;
    }
    else {
      *char_ptr_1 = '\0';
      local_14 = char_ptr_1 + 2;
    }
  }
  *arg_1 = local_8;
  return local_14;
}


