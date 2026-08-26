/*
 * Decompiled function: ___endstdio
 * Entry Point: 0040a330
 * Size: 36 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___endstdio
   
   Library: Visual Studio 1998 Debug */

void ___endstdio(void)

{
  __flushall();
  if (DAT_00412aac != '\0') {
    __fcloseall();
  }
  return;
}


