/*
 * Decompiled function: ___shl_12
 * Entry Point: 004ec2b0
 * Size: 118 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 1998 Debug */

void ___shl_12(int *arg_1)

{
  uint local_c;
  uint local_8;
  
  local_8 = (uint)((int)(*arg_1 & -0x80000000) != 0);
  local_c = (uint)((*(byte *)((int)arg_1 + 7) & 0x80) != 0);
  *arg_1 = *arg_1 << 1;
  arg_1[1] = arg_1[1] * 2 | local_8;
  arg_1[2] = arg_1[2] * 2 | local_c;
  return;
}


