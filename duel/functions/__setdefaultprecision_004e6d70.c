/*
 * Decompiled function: __setdefaultprecision
 * Entry Point: 004e6d70
 * Size: 29 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Debug */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


