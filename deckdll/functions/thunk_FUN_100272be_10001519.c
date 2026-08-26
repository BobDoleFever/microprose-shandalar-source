/*
 * Decompiled function: thunk_FUN_100272be
 * Entry Point: 10001519
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100272be(int arg_1,int arg_2,int *arg_3)

{
  bool flag_1;
  int32_t uStack_10;
  int32_t uStack_c;
  
  uStack_10 = *arg_3;
  flag_1 = false;
  for (uStack_c = 0; uStack_c < uStack_10; uStack_c = uStack_c + 1) {
    if (*(int *)(arg_2 + uStack_c * 4) == arg_1) {
      flag_1 = true;
    }
  }
  if (!flag_1) {
    *(int *)(arg_2 + uStack_10 * 4) = arg_1;
    uStack_10 = uStack_10 + 1;
  }
  *arg_3 = uStack_10;
  return;
}


