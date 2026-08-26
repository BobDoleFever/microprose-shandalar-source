/*
 * Decompiled function: setSBCS
 * Entry Point: 004e3d90
 * Size: 120 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Debug */

void __cdecl setSBCS(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x101; local_8 = local_8 + 1) {
    (&DAT_0050a200)[local_8] = 0;
  }
  DAT_0050a304 = 0;
  DAT_0050a308 = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(undefined2 *)(&DAT_0050a310 + local_8 * 2) = 0;
  }
  return;
}


