/*
 * Decompiled function: __initterm
 * Entry Point: 00401510
 * Size: 49 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 1998 Debug */

void __cdecl __initterm(int *ptr_1,int *ptr_2)

{
  for (; ptr_1 < ptr_2; ptr_1 = ptr_1 + 1) {
    if (*ptr_1 != 0) {
      (*(code *)*ptr_1)();
    }
  }
  return;
}


