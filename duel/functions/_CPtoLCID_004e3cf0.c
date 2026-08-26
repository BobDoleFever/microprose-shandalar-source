/*
 * Decompiled function: _CPtoLCID
 * Entry Point: 004e3cf0
 * Size: 107 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Debug */

undefined4 _CPtoLCID(undefined4 arg_1)

{
  undefined4 uVar1;
  
  switch(arg_1) {
  case 0x3a4:
    uVar1 = 0x411;
    break;
  default:
    uVar1 = 0;
    break;
  case 0x3a8:
    uVar1 = 0x804;
    break;
  case 0x3b5:
    uVar1 = 0x412;
    break;
  case 0x3b6:
    uVar1 = 0x404;
  }
  return uVar1;
}


