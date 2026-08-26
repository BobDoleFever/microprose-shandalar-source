/*
 * Decompiled function: __dosmaperr
 * Entry Point: 004e5340
 * Size: 177 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Debug */

void __cdecl __dosmaperr(ulong arg_1)

{
  uint local_8;
  
  DAT_00509424 = arg_1;
  local_8 = 0;
  while( true ) {
    if (0x2c < local_8) {
      if ((arg_1 < 0x13) || (0x24 < arg_1)) {
        if ((arg_1 < 0xbc) || (0xca < arg_1)) {
          DAT_00509420 = 0x16;
        }
        else {
          DAT_00509420 = 8;
        }
      }
      else {
        DAT_00509420 = 0xd;
      }
      return;
    }
    if (*(ulong *)(&DAT_0050a428 + local_8 * 8) == arg_1) break;
    local_8 = local_8 + 1;
  }
  DAT_00509420 = *(undefined4 *)(&DAT_0050a42c + local_8 * 8);
  return;
}


