/*
 * Decompiled function: _malloc
 * Entry Point: 004da5d0
 * Size: 40 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _malloc(size_t arg_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)__nh_malloc_dbg(arg_1,DAT_005099d4,1,0,0);
  return pvVar1;
}


