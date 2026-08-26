/*
 * Decompiled function: _CPtoLCID
 * Entry Point: 004029a0
 * Size: 107 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl _CPtoLCID(int32_t arg_1)

{
  int32_t uval_1;
  
  switch(arg_1) {
  case 0x3a4:
    uval_1 = 0x411;
    break;
  default:
    uval_1 = 0;
    break;
  case 0x3a8:
    uval_1 = 0x804;
    break;
  case 0x3b5:
    uval_1 = 0x412;
    break;
  case 0x3b6:
    uval_1 = 0x404;
  }
  return uval_1;
}


