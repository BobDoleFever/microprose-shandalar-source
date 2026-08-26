/*
 * Decompiled function: __initterm
 * Entry Point: 004da3c0
 * Size: 49 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 1998 Debug */

void __initterm(int *arg1,int *arg2)

{
  for (; arg1 < arg2; arg1 = arg1 + 1) {
    if (*arg1 != 0) {
      (*(code *)*arg1)();
    }
  }
  return;
}


