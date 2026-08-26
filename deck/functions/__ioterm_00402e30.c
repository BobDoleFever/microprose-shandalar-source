/*
 * Decompiled function: __ioterm
 * Entry Point: 00402e30
 * Size: 104 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 1998 Debug */

void __cdecl __ioterm(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
    if ((&DAT_004156c0)[local_8] != 0) {
      __free_dbg((void *)(&DAT_004156c0)[local_8],2);
    }
  }
  return;
}


