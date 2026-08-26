/*
 * Decompiled function: x_ismbbtype
 * Entry Point: 00401a80
 * Size: 110 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl x_ismbbtype(uint8_t arg_1,uint32_t arg_2,uint8_t arg_3)

{
  uint32_t local_8;
  
  if ((arg_3 & (&DAT_00412b69)[arg_1]) == 0) {
    if (arg_2 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(uint16_t *)(&DAT_00412e62 + (uint32_t)arg_1 * 2) & arg_2;
    }
    if (local_8 == 0) {
      return 0;
    }
  }
  return 1;
}


