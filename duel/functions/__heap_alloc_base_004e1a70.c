/*
 * Decompiled function: __heap_alloc_base
 * Entry Point: 004e1a70
 * Size: 99 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heap_alloc_base
   
   Library: Visual Studio 1998 Debug */

LPVOID __heap_alloc_base(int arg_1)

{
  uint dwBytes;
  LPVOID pvVar1;
  
  dwBytes = arg_1 + 0xfU & 0xfffffff0;
  if ((DAT_0050a1fc < dwBytes) ||
     (pvVar1 = (LPVOID)___sbh_alloc_block(arg_1 + 0xfU >> 4), pvVar1 == (LPVOID)0x0)) {
    pvVar1 = HeapAlloc(DAT_006c1c94,0,dwBytes);
  }
  return pvVar1;
}


