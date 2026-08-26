/*
 * Decompiled function: ___mtold12
 * Entry Point: 004ec3b0
 * Size: 312 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___mtold12
   
   Library: Visual Studio 1998 Debug */

void ___mtold12(char *str_1,int arg_2,uint *arg_3)

{
  short local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_14 = 0x404e;
  *arg_3 = 0;
  arg_3[1] = 0;
  arg_3[2] = 0;
  for (; arg_2 != 0; arg_2 = arg_2 + -1) {
    local_10 = *arg_3;
    local_c = arg_3[1];
    local_8 = arg_3[2];
    ___shl_12((int *)arg_3);
    ___shl_12((int *)arg_3);
    ___add_12(arg_3,&local_10);
    ___shl_12((int *)arg_3);
    local_10 = (uint)*str_1;
    local_c = 0;
    local_8 = 0;
    ___add_12(arg_3,&local_10);
    str_1 = str_1 + 1;
  }
  while (arg_3[2] == 0) {
    arg_3[2] = arg_3[1] >> 0x10;
    arg_3[1] = arg_3[1] << 0x10 | *arg_3 >> 0x10;
    *arg_3 = *arg_3 << 0x10;
    local_14 = local_14 + -0x10;
  }
  while ((*(byte *)((int)arg_3 + 9) & 0x80) == 0) {
    ___shl_12((int *)arg_3);
    local_14 = local_14 + -1;
  }
  *(short *)((int)arg_3 + 10) = local_14;
  return;
}


