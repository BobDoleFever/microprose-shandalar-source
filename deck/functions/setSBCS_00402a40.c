/*
 * Decompiled function: setSBCS
 * Entry Point: 00402a40
 * Size: 120 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Debug */

void __cdecl setSBCS(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x101; local_8 = local_8 + 1) {
    (&DAT_00412b68)[local_8] = 0;
  }
  DAT_00412c6c = 0;
  _DAT_00412c70 = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(int16_t *)(&DAT_00412c78 + local_8 * 2) = 0;
  }
  return;
}


