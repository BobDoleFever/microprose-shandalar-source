/*
 * Decompiled function: __set_sbh_threshold
 * Entry Point: 004e1fd0
 * Size: 61 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __set_sbh_threshold
   
   Library: Visual Studio 1998 Debug */

bool __set_sbh_threshold(int arg_1)

{
  uint uVar1;
  
  uVar1 = arg_1 + 0xfU & 0xfffffff0;
  if (uVar1 < 0x781) {
    DAT_0050a1fc = uVar1;
  }
  return uVar1 < 0x781;
}


