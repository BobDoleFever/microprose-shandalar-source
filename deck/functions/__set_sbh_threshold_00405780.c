/*
 * Decompiled function: __set_sbh_threshold
 * Entry Point: 00405780
 * Size: 61 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __set_sbh_threshold
   
   Library: Visual Studio 1998 Debug */

bool __cdecl __set_sbh_threshold(int arg_1)

{
  uint32_t uval_1;
  
  uval_1 = arg_1 + 0xfU & 0xfffffff0;
  if (uval_1 < 0x781) {
    DAT_004138ac = uval_1;
  }
  return uval_1 < 0x781;
}


