/*
 * Decompiled function: FUN_00424114
 * Entry Point: 00424114
 * Size: 212 bytes
 */
#include "duel.h"


void FUN_00424114(LPRECT arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      iVar1 = arg2[2];
      iVar2 = *arg2;
      iVar3 = arg2[3];
      iVar4 = arg2[1];
      arg1->left = *arg2 + ((iVar1 - iVar2) * 0x41) / 100;
      arg1->right = arg2[2] - ((iVar1 - iVar2) * 3) / 100;
      arg1->top = arg2[1] + ((iVar3 - iVar4) * 8) / 100;
      arg1->bottom = arg2[1] + ((iVar3 - iVar4) * 0x1c) / 100;
    }
  }
  return;
}


