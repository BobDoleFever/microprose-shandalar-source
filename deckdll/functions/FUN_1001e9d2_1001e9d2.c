/*
 * Decompiled function: FUN_1001e9d2
 * Entry Point: 1001e9d2
 * Size: 212 bytes
 */
#include "deckdll.h"


void FUN_1001e9d2(LPRECT arg1,int *arg2)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      val_1 = arg2[2];
      val_2 = *arg2;
      val_3 = arg2[3];
      val_4 = arg2[1];
      arg1->left = *arg2 + ((val_1 - val_2) * 0x41) / 100;
      arg1->right = arg2[2] - ((val_1 - val_2) * 3) / 100;
      arg1->top = arg2[1] + ((val_3 - val_4) * 8) / 100;
      arg1->bottom = arg2[1] + ((val_3 - val_4) * 0x1c) / 100;
    }
  }
  return;
}


