/*
 * Decompiled function: __nh_malloc_base
 * Entry Point: 004e19d0
 * Size: 150 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __nh_malloc_base
   
   Library: Visual Studio 1998 Debug */

int __nh_malloc_base(uint arg1,int arg2)

{
  int iVar1;
  int local_8;
  
  if (arg1 < 0xffffffe1) {
    if (arg1 == 0) {
      arg1 = 1;
    }
    do {
      if (arg1 < 0xffffffe1) {
        local_8 = __heap_alloc_base(arg1);
      }
      else {
        local_8 = 0;
      }
      if (local_8 != 0) {
        return local_8;
      }
      if (arg2 == 0) {
        return 0;
      }
      iVar1 = __callnewh(arg1);
    } while (iVar1 != 0);
  }
  return 0;
}


