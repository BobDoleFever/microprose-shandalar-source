/*
 * Decompiled function: FUN_10004249
 * Entry Point: 10004249
 * Size: 119 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_10004249(int arg1,int *arg2)

{
  int val_1;
  bool flag_2;
  int32_t uval_3;
  int local_8;
  
  local_8 = 0;
  do {
    if ((*(int *)(&DAT_10010868 + local_8 * 4) == 0) ||
       (*(int *)(*(int *)(&DAT_10010868 + local_8 * 4) + 0x10) == arg1)) break;
    val_1 = local_8 + 1;
    flag_2 = local_8 < 3;
    local_8 = val_1;
  } while (flag_2);
  if (local_8 < 3) {
    *arg2 = local_8;
    uval_3 = 0;
  }
  else {
    uval_3 = 2;
  }
  return uval_3;
}


