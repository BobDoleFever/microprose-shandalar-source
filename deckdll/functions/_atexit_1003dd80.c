/*
 * Decompiled function: _atexit
 * Entry Point: 1003dd80
 * Size: 48 bytes
 */
#include "deckdll.h"


/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  int val_1;
  
  val_1 = __onexit((_onexit_t)ptr_1);
  if (val_1 == 0) {
    val_1 = -1;
  }
  else {
    val_1 = 0;
  }
  return val_1;
}


