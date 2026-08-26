/*
 * Decompiled function: xcptlookup
 * Entry Point: 004e7940
 * Size: 97 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _xcptlookup
   
   Library: Visual Studio 1998 Debug */

int * __cdecl xcptlookup(int arg_1)

{
  int *local_8;
  
  local_8 = &DAT_0050a5e8;
  do {
    if (*local_8 == arg_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_0050a5e8 + DAT_0050a668 * 3);
  if (*local_8 != arg_1) {
    local_8 = (int *)0x0;
  }
  return local_8;
}


