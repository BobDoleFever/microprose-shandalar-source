/*
 * Decompiled function: _abort
 * Entry Point: 004e0770
 * Size: 41 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 1998 Debug */

void __cdecl _abort(void)

{
  __NMSG_WRITE(10);
  _raise(0x16);
  __exit(3);
  return;
}


