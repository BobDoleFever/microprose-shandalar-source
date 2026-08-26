/*
 * Decompiled function: ___addl
 * Entry Point: 004ec1b0
 * Size: 73 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___addl
   
   Library: Visual Studio 1998 Debug */

undefined4 ___addl(uint arg_1,uint arg_2,uint *arg_3)

{
  uint uVar1;
  undefined4 local_c;
  
  local_c = 0;
  uVar1 = arg_2 + arg_1;
  if ((uVar1 < arg_1) || (uVar1 < arg_2)) {
    local_c = 1;
  }
  *arg_3 = uVar1;
  return local_c;
}


