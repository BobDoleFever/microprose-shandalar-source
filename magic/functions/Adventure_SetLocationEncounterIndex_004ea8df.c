/*
 * Decompiled function: Adventure_SetLocationEncounterIndex
 * Entry Point: 004ea8df
 * Size: 128 bytes
 */
#include "magic.h"


undefined4 Adventure_SetLocationEncounterIndex(undefined4 arg_1)

{
  undefined4 local_8;
  
  switch(arg_1) {
  case 1:
    local_8 = 2;
    break;
  case 2:
    local_8 = 3;
    break;
  case 3:
    local_8 = 1;
    break;
  default:
    local_8 = 0;
    break;
  case 5:
    local_8 = 4;
    break;
  case 6:
    local_8 = 5;
  }
  return local_8;
}


