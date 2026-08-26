/*
 * Decompiled function: _memset
 * Entry Point: 00407440
 * Size: 88 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *ptr_1,int arg_2,size_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  size_t len_3;
  uint32_t *puVar4;
  
  if (arg_3 == 0) {
    return ptr_1;
  }
  uval_1 = arg_2 & 0xff;
  puVar4 = ptr_1;
  if (3 < arg_3) {
    uval_2 = -(int)ptr_1 & 3;
    len_3 = arg_3;
    if (uval_2 != 0) {
      len_3 = arg_3 - uval_2;
      do {
        *(uint8_t *)puVar4 = (uint8_t)arg_2;
        puVar4 = (uint32_t *)((int)puVar4 + 1);
        uval_2 = uval_2 - 1;
      } while (uval_2 != 0);
    }
    uval_1 = uval_1 * 0x1010101;
    arg_3 = len_3 & 3;
    uval_2 = len_3 >> 2;
    if (uval_2 != 0) {
      for (; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar4 = uval_1;
        puVar4 = puVar4 + 1;
      }
      if (arg_3 == 0) {
        return ptr_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uval_1;
    puVar4 = (uint32_t *)((int)puVar4 + 1);
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return ptr_1;
}


