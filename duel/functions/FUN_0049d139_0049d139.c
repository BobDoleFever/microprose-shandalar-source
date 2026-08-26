/*
 * Decompiled function: FUN_0049d139
 * Entry Point: 0049d139
 * Size: 68 bytes
 */
#include "duel.h"


void FUN_0049d139(uint *arg1,int arg2)

{
  uint local_10c [66];
  
  Mem_AllocOrFree_004d9630(local_10c,arg1);
  _strncpy(&DAT_005f2fb0 + arg2 * 0x80,(char *)local_10c,0x80);
  return;
}


