/*
 * Decompiled function: thunk_FUN_10013a4c
 * Entry Point: 10001636
 * Size: 5 bytes
 */
#include "deckdll.h"


uint8_t * thunk_FUN_10013a4c(int arg1,int arg2)

{
  uint8_t *puStack_c;
  int iStack_8;
  
  puStack_c = (uint8_t *)0x0;
  if (arg1 == -1) {
    puStack_c = (uint8_t *)0x0;
  }
  else {
    iStack_8 = 0;
    while ((iStack_8 < DAT_10158728 && (puStack_c == (uint8_t *)0x0))) {
      if (((&DAT_101cf600)[iStack_8 * 6] == arg1) && ((&DAT_101cf604)[iStack_8 * 6] == arg2)) {
        puStack_c = &DAT_101cf5f0 + iStack_8 * 0x18;
      }
      iStack_8 = iStack_8 + 1;
    }
  }
  return puStack_c;
}


