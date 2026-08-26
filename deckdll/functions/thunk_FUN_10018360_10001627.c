/*
 * Decompiled function: thunk_FUN_10018360
 * Entry Point: 10001627
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10018360(char *str_1,int arg2)

{
  int val_1;
  int val_2;
  int iStack_10;
  int iStack_8;
  
  iStack_10 = 0;
  iStack_8 = arg2 + -1;
  while( true ) {
    while( true ) {
      if (iStack_8 < iStack_10) {
        return -1;
      }
      val_1 = (iStack_8 + iStack_10) / 2;
      val_2 = strcmp(&DAT_101cb780 + val_1 * 100,str_1);
      if (-1 < val_2) break;
      iStack_10 = val_1 + 1;
    }
    val_2 = strcmp(&DAT_101cb780 + val_1 * 100,str_1);
    if (val_2 < 1) break;
    iStack_8 = val_1 + -1;
  }
  return val_1;
}


