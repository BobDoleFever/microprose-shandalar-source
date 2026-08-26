/*
 * Decompiled function: Mem_AllocOrFree_004d9810
 * Entry Point: 004d9810
 * Size: 24 bytes
 */
#include "duel.h"


int Mem_AllocOrFree_004d9810(uint arg_1)

{
  return (arg_1 ^ (int)arg_1 >> 0x1f) - ((int)arg_1 >> 0x1f);
}


