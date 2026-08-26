/*
 * Decompiled function: __heap_term
 * Entry Point: 004e1f50
 * Size: 93 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 1998 Debug */

void __cdecl __heap_term(void)

{
  undefined **local_8;
  
  local_8 = &PTR_LOOP_005099e0;
  do {
    if (local_8[0x204] != (undefined *)0x0) {
      VirtualFree(local_8[0x204],0,0x8000);
    }
    local_8 = (undefined **)*local_8;
  } while (local_8 != &PTR_LOOP_005099e0);
  HeapDestroy(DAT_006c1c94);
  return;
}


