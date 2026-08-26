/*
 * Decompiled function: __free_base
 * Entry Point: 004e1de0
 * Size: 105 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __free_base
   
   Library: Visual Studio 1998 Debug */

void __free_base(LPVOID arg_1)

{
  int local_10;
  char *local_c;
  uint local_8;
  
  if (arg_1 != (LPVOID)0x0) {
    local_c = (char *)___sbh_find_block(arg_1,&local_10,&local_8);
    if (local_c == (char *)0x0) {
      HeapFree(DAT_006c1c94,0,arg_1);
    }
    else {
      ___sbh_free_block(local_10,local_8,local_c);
    }
  }
  return;
}


