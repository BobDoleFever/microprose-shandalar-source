/*
 * Decompiled function: _calloc
 * Entry Point: 004daa40
 * Size: 38 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _calloc(size_t arg_1,size_t arg_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)__calloc_dbg(arg_1,arg_2,1,0,0);
  return pvVar1;
}


