/*
 * Decompiled function: FUN_100272be
 * Entry Point: 100272be
 * Size: 119 bytes
 */
#include "deckdll.h"


void FUN_100272be(int arg_1,int arg_2,int *arg_3)

{
  bool flag_1;
  int32_t local_10;
  int32_t local_c;
  
  local_10 = *arg_3;
  flag_1 = false;
  for (local_c = 0; local_c < local_10; local_c = local_c + 1) {
    if (*(int *)(arg_2 + local_c * 4) == arg_1) {
      flag_1 = true;
    }
  }
  if (!flag_1) {
    *(int *)(arg_2 + local_10 * 4) = arg_1;
    local_10 = local_10 + 1;
  }
  *arg_3 = local_10;
  return;
}


