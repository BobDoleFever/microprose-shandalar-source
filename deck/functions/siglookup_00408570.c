/*
 * Decompiled function: siglookup
 * Entry Point: 00408570
 * Size: 99 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Debug */

int32_t * __cdecl siglookup(int arg_1)

{
  int32_t *local_8;
  
  local_8 = &DAT_00412ad0;
  do {
    if (local_8[1] == arg_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_00412ad0 + DAT_00412b50 * 3);
  if (local_8[1] != arg_1) {
    local_8 = (int32_t *)0x0;
  }
  return local_8;
}


