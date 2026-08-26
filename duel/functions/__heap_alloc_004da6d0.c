/*
 * Decompiled function: __heap_alloc
 * Entry Point: 004da6d0
 * Size: 34 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __heap_alloc(size_t arg_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)__heap_alloc_dbg(arg_1,1,0,0);
  return pvVar1;
}


