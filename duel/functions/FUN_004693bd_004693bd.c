/*
 * Decompiled function: FUN_004693bd
 * Entry Point: 004693bd
 * Size: 147 bytes
 */
#include "duel.h"


int FUN_004693bd(int arg_1)

{
  int arg2;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while ((local_8 < 500 && (*(int *)(&DAT_006669f0 + local_8 * 4 + arg_1 * 2000) != -1))) {
    local_8 = local_8 + 1;
  }
  arg2 = FUN_00439892(local_8);
  local_c = FUN_00469450(arg_1,arg2);
  if (local_c == 0) {
    local_c = FUN_00469450(arg_1,0);
  }
  return local_c;
}


