/*
 * Decompiled function: __nh_malloc_dbg
 * Entry Point: 004da660
 * Size: 101 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __nh_malloc_dbg
   
   Library: Visual Studio 1998 Debug */

int __nh_malloc_dbg(size_t arg_1,int arg_2,uint arg_3,int arg_4,undefined4 arg_5)

{
  int iVar1;
  
  while( true ) {
    iVar1 = __heap_alloc_dbg(arg_1,arg_3,arg_4,arg_5);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (arg_2 == 0) break;
    iVar1 = __callnewh(arg_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}


