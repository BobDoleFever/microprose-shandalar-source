/*
 * Decompiled function: FUN_1001477a
 * Entry Point: 1001477a
 * Size: 110 bytes
 */
#include "deckdll.h"


int FUN_1001477a(FILE *fp,uint8_t *arg2)

{
  int val_1;
  int local_c;
  uint8_t local_8;
  
  local_c = 0;
  while ((val_1 = fgetc(fp), val_1 != 10 && (val_1 != -1))) {
    local_8 = (uint8_t)val_1;
    *arg2 = local_8;
    arg2 = arg2 + 1;
    local_c = local_c + 1;
  }
  *arg2 = 0;
  if (val_1 == -1) {
    local_c = -1;
  }
  return local_c;
}


