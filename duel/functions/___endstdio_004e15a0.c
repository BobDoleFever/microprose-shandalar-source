/*
 * Decompiled function: ___endstdio
 * Entry Point: 004e15a0
 * Size: 36 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___endstdio
   
   Library: Visual Studio 1998 Debug */

void ___endstdio(void)

{
  __flushall();
  if (DAT_00509460 != '\0') {
    __fcloseall();
  }
  return;
}


