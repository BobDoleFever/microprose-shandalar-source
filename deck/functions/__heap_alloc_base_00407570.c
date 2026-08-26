/*
 * Decompiled function: __heap_alloc_base
 * Entry Point: 00407570
 * Size: 99 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __heap_alloc_base
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl __heap_alloc_base(int arg_1)

{
  uint32_t dwBytes;
  uint8_t *u_ptr_1;
  
  dwBytes = arg_1 + 0xfU & 0xfffffff0;
  if ((DAT_004138ac < dwBytes) ||
     (u_ptr_1 = ___sbh_alloc_block(arg_1 + 0xfU >> 4), u_ptr_1 == (uint8_t *)0x0)) {
    u_ptr_1 = HeapAlloc(DAT_004156ac,0,dwBytes);
  }
  return u_ptr_1;
}


