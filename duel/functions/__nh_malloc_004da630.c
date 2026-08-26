/*
 * Decompiled function: __nh_malloc
 * Entry Point: 004da630
 * Size: 38 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __nh_malloc(size_t arg_1,int arg_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)__nh_malloc_dbg(arg_1,arg_2,1,0,0);
  return pvVar1;
}


