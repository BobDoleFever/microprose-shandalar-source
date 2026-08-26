/*
 * Decompiled function: ___shr_12
 * Entry Point: 004ec330
 * Size: 119 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___shr_12
   
   Library: Visual Studio 1998 Debug */

void ___shr_12(uint *arg_1)

{
  uint local_c;
  uint local_8;
  
  if ((arg_1[2] & 1) == 0) {
    local_c = 0;
  }
  else {
    local_c = 0x80000000;
  }
  if ((arg_1[1] & 1) == 0) {
    local_8 = 0;
  }
  else {
    local_8 = 0x80000000;
  }
  arg_1[2] = arg_1[2] >> 1;
  arg_1[1] = arg_1[1] >> 1 | local_c;
  *arg_1 = *arg_1 >> 1 | local_8;
  return;
}


