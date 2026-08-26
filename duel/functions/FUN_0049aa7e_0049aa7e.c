/*
 * Decompiled function: FUN_0049aa7e
 * Entry Point: 0049aa7e
 * Size: 114 bytes
 */
#include "duel.h"


int FUN_0049aa7e(int arg1,int arg2)

{
  undefined4 local_8;
  
  if (arg1 < 0) {
    arg1 = -arg1;
  }
  if (arg2 < 0) {
    arg2 = -arg2;
  }
  if (arg2 < arg1) {
    local_8 = arg1 * 2 + arg2;
  }
  else {
    local_8 = arg2 * 2 + arg1;
  }
  if (local_8 < 0) {
    local_8 = 0x7ffe;
  }
  return local_8;
}


