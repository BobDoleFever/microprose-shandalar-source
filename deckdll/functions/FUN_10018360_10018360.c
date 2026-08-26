/*
 * Decompiled function: FUN_10018360
 * Entry Point: 10018360
 * Size: 177 bytes
 */
#include "deckdll.h"


int FUN_10018360(char *str_1,int arg2)

{
  int val_1;
  int val_2;
  int local_10;
  int local_8;
  
  local_10 = 0;
  local_8 = arg2 + -1;
  while( true ) {
    while( true ) {
      if (local_8 < local_10) {
        return -1;
      }
      val_1 = (local_8 + local_10) / 2;
      val_2 = strcmp(&DAT_101cb780 + val_1 * 100,str_1);
      if (-1 < val_2) break;
      local_10 = val_1 + 1;
    }
    val_2 = strcmp(&DAT_101cb780 + val_1 * 100,str_1);
    if (val_2 < 1) break;
    local_8 = val_1 + -1;
  }
  return val_1;
}


