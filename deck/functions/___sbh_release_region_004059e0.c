/*
 * Decompiled function: ___sbh_release_region
 * Entry Point: 004059e0
 * Size: 132 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Debug */

void __cdecl ___sbh_release_region(uint8_t **ptr_1)

{
  VirtualFree(ptr_1[0x204],0,0x8000);
  if (ptr_1 == (uint8_t **)PTR_LOOP_004138a4) {
    PTR_LOOP_004138a4 = ptr_1[1];
  }
  if (ptr_1 == &PTR_LOOP_00413090) {
    DAT_004138a0 = 0;
  }
  else {
    *(uint8_t **)ptr_1[1] = *ptr_1;
    *(uint8_t **)(*ptr_1 + 4) = ptr_1[1];
    HeapFree(DAT_004156ac,0,ptr_1);
  }
  return;
}


