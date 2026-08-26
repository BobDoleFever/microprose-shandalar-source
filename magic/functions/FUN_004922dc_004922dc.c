/*
 * Decompiled function: FUN_004922dc
 * Entry Point: 004922dc
 * Size: 194 bytes
 */
#include "magic.h"


int FUN_004922dc(void)

{
  int local_10;
  int local_8;
  
  local_10 = -DAT_006410b4;
  for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
    if ((&DAT_0067be01)[local_8 * 100] != '\0') {
      local_10 = local_10 + -2;
    }
  }
  local_10 = local_10 * 3;
  for (local_8 = 0; local_8 < 1000; local_8 = local_8 + 1) {
    if ((&DAT_0067b9b0)[local_8] != '\0') {
      local_10 = local_10 + ((int)(char)(&DAT_0067b9b0)[local_8] & 0xfU) + 2;
      if (((int)(char)(&DAT_0067b9b0)[local_8] & 0xfU) == 0xc) {
        local_10 = local_10 + 0x19;
      }
    }
  }
  return local_10 << 1;
}


