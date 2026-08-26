/*
 * Decompiled function: siglookup
 * Entry Point: 004e0c30
 * Size: 99 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Debug */

undefined4 * __cdecl siglookup(int arg_1)

{
  undefined4 *local_8;
  
  local_8 = &DAT_0050a5e8;
  do {
    if (local_8[1] == arg_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_0050a5e8 + DAT_0050a668 * 3);
  if (local_8[1] != arg_1) {
    local_8 = (undefined4 *)0x0;
  }
  return local_8;
}


