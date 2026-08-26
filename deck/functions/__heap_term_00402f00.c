/*
 * Decompiled function: __heap_term
 * Entry Point: 00402f00
 * Size: 93 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 1998 Debug */

void __cdecl __heap_term(void)

{
  uint8_t **local_8;
  
  local_8 = &PTR_LOOP_00413090;
  do {
    if (local_8[0x204] != (uint8_t *)0x0) {
      VirtualFree(local_8[0x204],0,0x8000);
    }
    local_8 = (uint8_t **)*local_8;
  } while (local_8 != &PTR_LOOP_00413090);
  HeapDestroy(DAT_004156ac);
  return;
}


