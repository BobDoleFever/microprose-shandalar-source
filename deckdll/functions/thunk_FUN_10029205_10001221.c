/*
 * Decompiled function: thunk_FUN_10029205
 * Entry Point: 10001221
 * Size: 5 bytes
 */
#include "deckdll.h"


uint8_t * thunk_FUN_10029205(int arg1,int arg2)

{
  int iStack_c;
  uint8_t *puStack_8;
  
  puStack_8 = (uint8_t *)0x0;
  if (arg1 == -1) {
    puStack_8 = (uint8_t *)0x0;
  }
  else {
    iStack_c = 0;
    while ((iStack_c < DAT_101cdeb0 && (puStack_8 == (uint8_t *)0x0))) {
      if ((*(int *)(&DAT_10175570 + iStack_c * 0x18) == arg1) &&
         (*(int *)(&DAT_10175574 + iStack_c * 0x18) == arg2)) {
        puStack_8 = &DAT_10175560 + iStack_c * 0x18;
      }
      iStack_c = iStack_c + 1;
    }
  }
  return puStack_8;
}


