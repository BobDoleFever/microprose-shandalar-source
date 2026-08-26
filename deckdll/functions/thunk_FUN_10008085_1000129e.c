/*
 * Decompiled function: thunk_FUN_10008085
 * Entry Point: 1000129e
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10008085(int arg_1,int arg_2,POINT *arg_3)

{
  BOOL BVar1;
  int val_2;
  int val_3;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  int aiStack_d0 [50];
  int iStack_8;
  
  iStack_d8 = 0;
  iStack_8 = 0;
  while ((iStack_d8 < arg_2 && (iStack_8 == 0))) {
    BVar1 = PtInRect((RECT *)(iStack_d8 * 0x10 + arg_1),*arg_3);
    if (BVar1 == 0) {
      val_2 = abs(arg_3->x - *(int *)(iStack_d8 * 0x10 + 8 + arg_1));
      val_3 = abs(arg_3->x - *(int *)(iStack_d8 * 0x10 + arg_1));
      if (val_3 < val_2) {
        val_2 = abs(arg_3->x - *(int *)(iStack_d8 * 0x10 + arg_1));
        aiStack_d0[iStack_d8 * 2] = val_2;
      }
      else {
        val_2 = abs(arg_3->x - *(int *)(iStack_d8 * 0x10 + 8 + arg_1));
        aiStack_d0[iStack_d8 * 2] = val_2;
      }
      val_2 = abs(arg_3->y - *(int *)(iStack_d8 * 0x10 + 4 + arg_1));
      val_3 = abs(arg_3->y - *(int *)(iStack_d8 * 0x10 + 0xc + arg_1));
      if (val_2 < val_3) {
        val_2 = abs(arg_3->y - *(int *)(iStack_d8 * 0x10 + 4 + arg_1));
        aiStack_d0[iStack_d8 * 2 + 1] = val_2;
      }
      else {
        val_2 = abs(arg_3->y - *(int *)(iStack_d8 * 0x10 + 0xc + arg_1));
        aiStack_d0[iStack_d8 * 2 + 1] = val_2;
      }
    }
    else {
      iStack_d4 = iStack_d8;
      iStack_8 = 1;
    }
    iStack_d8 = iStack_d8 + 1;
  }
  if (iStack_8 == 0) {
    iStack_e0 = 1000;
    for (iStack_d8 = 0; iStack_d8 < arg_2; iStack_d8 = iStack_d8 + 1) {
      if (aiStack_d0[iStack_d8 * 2] < iStack_e0) {
        iStack_e0 = aiStack_d0[iStack_d8 * 2];
        iStack_d4 = iStack_d8;
        iStack_dc = aiStack_d0[iStack_d8 * 2 + 1];
      }
      else if ((aiStack_d0[iStack_d8 * 2] == iStack_e0) &&
              (aiStack_d0[iStack_d8 * 2 + 1] < iStack_dc)) {
        iStack_dc = aiStack_d0[iStack_d8 * 2 + 1];
        iStack_d4 = iStack_d8;
      }
    }
  }
  return iStack_d4;
}


