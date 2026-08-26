/*
 * Decompiled function: thunk_FUN_1000eae7
 * Entry Point: 10001285
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000eae7(void)

{
  uint32_t uStack_10;
  int iStack_c;
  uint32_t uStack_8;
  
  for (uStack_8 = 0; (int)uStack_8 < 0x100; uStack_8 = uStack_8 + 1) {
    uStack_10 = 0x80;
    for (iStack_c = 0; iStack_c < 8; iStack_c = iStack_c + 1) {
      if ((uStack_8 & uStack_10) == 0) {
        PTR_DAT_10041574[uStack_8 * 8 + iStack_c] = 0;
      }
      else {
        PTR_DAT_10041574[uStack_8 * 8 + iStack_c] = 4;
      }
      if ((uStack_8 & uStack_10) == 0) {
        PTR_DAT_10041578[uStack_8 * 8 + iStack_c] = 0;
      }
      else {
        PTR_DAT_10041578[uStack_8 * 8 + iStack_c] = 2;
      }
      if ((uStack_8 & uStack_10) == 0) {
        PTR_DAT_1004157c[uStack_8 * 8 + iStack_c] = 0;
      }
      else {
        PTR_DAT_1004157c[uStack_8 * 8 + iStack_c] = 1;
      }
      uStack_10 = (int)uStack_10 >> 1;
    }
  }
  return 0;
}


