/*
 * Decompiled function: __free_base
 * Entry Point: 004078e0
 * Size: 105 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __free_base
   
   Library: Visual Studio 1998 Debug */

void __cdecl __free_base(uint8_t *ptr_1)

{
  int local_10;
  char *local_c;
  uint32_t local_8;
  
  if (ptr_1 != (uint8_t *)0x0) {
    local_c = (char *)___sbh_find_block(ptr_1,&local_10,&local_8);
    if (local_c == (char *)0x0) {
      HeapFree(DAT_004156ac,0,ptr_1);
    }
    else {
      ___sbh_free_block(local_10,local_8,local_c);
    }
  }
  return;
}


