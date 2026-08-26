/*
 * Decompiled function: FUN_004d9810
 * Entry Point: 004d9810
 * Size: 24 bytes
 */
#include "duel.h"


int FUN_004d9810(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


