/*
 * Decompiled function: FUN_10014828
 * Entry Point: 10014828
 * Size: 84 bytes
 */
#include "deckdll.h"


int32_t FUN_10014828(char *str_1)

{
  int32_t uval_1;
  
  if (*str_1 == 'v') {
    uval_1 = 1;
  }
  else if ((*str_1 == '.') && (str_1[1] == 'v')) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


