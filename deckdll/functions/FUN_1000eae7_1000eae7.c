/*
 * Decompiled function: FUN_1000eae7
 * Entry Point: 1000eae7
 * Size: 259 bytes
 */
#include "deckdll.h"


int32_t FUN_1000eae7(void)

{
  uint32_t local_10;
  int local_c;
  uint32_t local_8;
  
  for (local_8 = 0; (int)local_8 < 0x100; local_8 = local_8 + 1) {
    local_10 = 0x80;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if ((local_8 & local_10) == 0) {
        PTR_DAT_10041574[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_10041574[local_8 * 8 + local_c] = 4;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_10041578[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_10041578[local_8 * 8 + local_c] = 2;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_1004157c[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_1004157c[local_8 * 8 + local_c] = 1;
      }
      local_10 = (int)local_10 >> 1;
    }
  }
  return 0;
}


