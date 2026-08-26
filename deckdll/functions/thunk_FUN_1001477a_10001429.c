/*
 * Decompiled function: thunk_FUN_1001477a
 * Entry Point: 10001429
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1001477a(FILE *fp,uint8_t *arg2)

{
  int val_1;
  int iStack_c;
  uint8_t uStack_8;
  
  iStack_c = 0;
  while ((val_1 = fgetc(fp), val_1 != 10 && (val_1 != -1))) {
    uStack_8 = (uint8_t)val_1;
    *arg2 = uStack_8;
    arg2 = arg2 + 1;
    iStack_c = iStack_c + 1;
  }
  *arg2 = 0;
  if (val_1 == -1) {
    iStack_c = -1;
  }
  return iStack_c;
}


