/*
 * Decompiled function: FUN_100210e3
 * Entry Point: 100210e3
 * Size: 219 bytes
 */
#include "deckdll.h"


void FUN_100210e3(LPRECT arg1,int *arg2)

{
  int val_1;
  int val_2;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      val_1 = ((arg2[2] - *arg2) * 0x3c) / 100;
      val_2 = ((arg2[3] - arg2[1]) * 0x3c) / 100;
      arg1->left = *arg2 + ((arg2[2] - *arg2) - val_1) / 2;
      arg1->right = arg1->left + val_1;
      arg1->top = arg2[1] + ((arg2[3] - arg2[1]) - val_2) / 2;
      arg1->bottom = arg1->top + val_2;
    }
  }
  return;
}


