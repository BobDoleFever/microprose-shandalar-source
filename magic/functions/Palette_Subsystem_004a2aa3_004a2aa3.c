/*
 * Decompiled function: Palette_Subsystem_004a2aa3
 * Entry Point: 004a2aa3
 * Size: 219 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a2aa3(LPRECT arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      iVar1 = ((arg2[2] - *arg2) * 0x3c) / 100;
      iVar2 = ((arg2[3] - arg2[1]) * 0x3c) / 100;
      arg1->left = *arg2 + ((arg2[2] - *arg2) - iVar1) / 2;
      arg1->right = arg1->left + iVar1;
      arg1->top = arg2[1] + ((arg2[3] - arg2[1]) - iVar2) / 2;
      arg1->bottom = arg1->top + iVar2;
    }
  }
  return;
}


