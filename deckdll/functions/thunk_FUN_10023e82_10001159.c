/*
 * Decompiled function: thunk_FUN_10023e82
 * Entry Point: 10001159
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10023e82(char arg_1,char *str_2,int arg_3)

{
  int iStack_8;
  
  iStack_8 = 0;
  while ((arg_3 != 0 && (*str_2 == arg_1))) {
    iStack_8 = iStack_8 + 1;
    str_2 = str_2 + 1;
    arg_3 = arg_3 + -1;
  }
  return iStack_8;
}


