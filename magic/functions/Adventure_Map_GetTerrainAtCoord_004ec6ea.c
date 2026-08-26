/*
 * Decompiled function: Adventure_Map_GetTerrainAtCoord
 * Entry Point: 004ec6ea
 * Size: 271 bytes
 */
#include "magic.h"


int Adventure_Map_GetTerrainAtCoord(uint arg_1)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_18 [5];
  
  local_1c = 0;
  local_18[0] = arg_1 & 0x20;
  local_18[1] = arg_1 & 0x10;
  local_18[2] = arg_1 & 4;
  local_18[3] = arg_1 & 8;
  local_18[4] = arg_1 & 2;
  for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
    if (local_18[local_20] != 0) {
      local_1c = local_1c + 1;
    }
  }
  if (local_1c == 1) {
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (local_18[local_20] != 0) {
        return local_20;
      }
    }
  }
  else {
    local_24 = FUN_0040a1d2(local_1c);
    local_24 = local_24 + 1;
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (local_18[local_20] != 0) {
        local_24 = local_24 + -1;
      }
      if (local_24 == 0) {
        return local_20;
      }
    }
  }
  return -1;
}


