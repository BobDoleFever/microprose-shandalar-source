/*
 * Decompiled function: __hextodec
 * Entry Point: 004e5200
 * Size: 102 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __hextodec
   
   Library: Visual Studio 1998 Debug */

uint __hextodec(uint arg_1)

{
  uint local_8;
  
  if (DAT_005096ac < 2) {
    local_8 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 4;
  }
  else {
    local_8 = __isctype(arg_1,4);
  }
  if (local_8 == 0) {
    arg_1 = (arg_1 & 0xffffffdf) - 7;
  }
  return arg_1;
}


