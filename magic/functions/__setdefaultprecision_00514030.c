/*
 * Decompiled function: __setdefaultprecision
 * Entry Point: 00514030
 * Size: 29 bytes
 */
#include "magic.h"


/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Debug */

void __setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}


