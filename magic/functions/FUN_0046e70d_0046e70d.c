/*
 * Decompiled function: FUN_0046e70d
 * Entry Point: 0046e70d
 * Size: 109 bytes
 */
#include "magic.h"


void FUN_0046e70d(int arg1,int arg2)

{
  if (*(int *)(&g_OverworldFoodAmount + arg1 * 0xb4) != 0) {
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + arg1 * 0xb4));
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + arg2 * 0xb4));
    *(undefined4 *)(&g_OverworldFoodAmount + arg1 * 0xb4) = 0;
  }
  return;
}


