/*
 * Decompiled function: _atexit
 * Entry Point: 1000cd40
 * Size: 48 bytes
 */
#include "magvid.h"


/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  _onexit_t p_Var1;
  int val_2;
  
  p_Var1 = __onexit((_onexit_t)ptr_1);
  if (p_Var1 == (_onexit_t)0x0) {
    val_2 = -1;
  }
  else {
    val_2 = 0;
  }
  return val_2;
}


