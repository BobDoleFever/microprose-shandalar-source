/*
 * Decompiled function: xcptlookup
 * Entry Point: 00401840
 * Size: 97 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _xcptlookup
   
   Library: Visual Studio 1998 Debug */

int * __cdecl xcptlookup(int arg_1)

{
  int *local_8;
  
  local_8 = &DAT_00412ad0;
  do {
    if (*local_8 == arg_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_00412ad0 + DAT_00412b50 * 3);
  if (*local_8 != arg_1) {
    local_8 = (int *)0x0;
  }
  return local_8;
}


