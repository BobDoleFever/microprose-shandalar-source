/*
 * Decompiled function: ___sbh_find_block
 * Entry Point: 00405bf0
 * Size: 162 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___sbh_find_block(uint8_t *ptr_1,int32_t *ptr_2,uint32_t *ptr_3)

{
  uint32_t uval_1;
  uint8_t **local_c;
  
  local_c = &PTR_LOOP_00413090;
  while (((local_c[0x204] == (uint8_t *)0x0 || (ptr_1 <= local_c[0x204])) ||
         (local_c[0x204] + 0x400000 <= ptr_1))) {
    local_c = (uint8_t **)*local_c;
    if (local_c == &PTR_LOOP_00413090) {
      return 0;
    }
  }
  *ptr_2 = local_c;
  uval_1 = (uint32_t)ptr_1 & 0xfffff000;
  *ptr_3 = uval_1;
  return ((int)((int)ptr_1 - (uval_1 + 0x100)) >> 4) + 8 + uval_1;
}


