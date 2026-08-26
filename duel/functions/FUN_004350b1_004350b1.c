/*
 * Decompiled function: FUN_004350b1
 * Entry Point: 004350b1
 * Size: 260 bytes
 */
#include "duel.h"


undefined4 FUN_004350b1(void)

{
  uint local_10;
  int local_c;
  uint local_8;
  
  for (local_8 = 0; (int)local_8 < 0x100; local_8 = local_8 + 1) {
    local_10 = 0x80;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f461c[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f461c[local_8 * 8 + local_c] = 4;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f4620[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f4620[local_8 * 8 + local_c] = 2;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f4624[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f4624[local_8 * 8 + local_c] = 1;
      }
      local_10 = (int)local_10 >> 1;
    }
  }
  return 0;
}


