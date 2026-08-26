/*
 * Decompiled function: FUN_100147ed
 * Entry Point: 100147ed
 * Size: 59 bytes
 */
#include "deckdll.h"


int32_t FUN_100147ed(char *str_1)

{
  int32_t uval_1;
  
  if ((*str_1 == '.') && (str_1[1] != 'v')) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


