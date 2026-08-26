/*
 * Decompiled function: _atexit
 * Entry Point: 00513d50
 * Size: 48 bytes
 */
#include "magic.h"


/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  int iVar1;
  
  iVar1 = __onexit((_onexit_t)ptr_1);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


