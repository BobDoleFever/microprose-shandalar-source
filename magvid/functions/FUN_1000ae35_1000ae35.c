/*
 * Decompiled function: FUN_1000ae35
 * Entry Point: 1000ae35
 * Size: 112 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_1000ae35(int32_t *ptr_1)

{
  int32_t uval_1;
  
  uval_1 = ftol(1000000);
  ICDrawBegin(*ptr_1,0,0,0,0,0,0,0,0,0,0,0,0,0,uval_1);
  ICSendMessage(*ptr_1,0x4012,0,0);
  return 0;
}


