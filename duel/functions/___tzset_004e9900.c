/*
 * Decompiled function: ___tzset
 * Entry Point: 004e9900
 * Size: 35 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 1998 Debug */

void ___tzset(void)

{
  if (DAT_0050a80c == 0) {
    __tzset();
    DAT_0050a80c = DAT_0050a80c + 1;
  }
  return;
}


