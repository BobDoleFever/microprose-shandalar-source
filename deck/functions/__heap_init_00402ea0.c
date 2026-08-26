/*
 * Decompiled function: __heap_init
 * Entry Point: 00402ea0
 * Size: 93 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heap_init(void)

{
  int val_1;
  uint8_t **ppuVar2;
  
  DAT_004156ac = HeapCreate(1,0x1000,0);
  if (DAT_004156ac == (HANDLE)0x0) {
    val_1 = 0;
  }
  else {
    ppuVar2 = ___sbh_new_region();
    if (ppuVar2 == (uint8_t **)0x0) {
      HeapDestroy(DAT_004156ac);
      val_1 = 0;
    }
    else {
      val_1 = 1;
    }
  }
  return val_1;
}


