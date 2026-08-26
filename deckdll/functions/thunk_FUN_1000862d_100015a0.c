/*
 * Decompiled function: thunk_FUN_1000862d
 * Entry Point: 100015a0
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000862d(HWND hwnd,int arg_2,int arg_3)

{
  int val_1;
  int val_2;
  HWND pHStack_b4;
  HWND pHStack_ac;
  int iStack_a8;
  int aiStack_a4 [40];
  
  val_1 = DAT_10176860 * 0x12;
  for (iStack_a8 = 0; iStack_a8 < arg_3; iStack_a8 = iStack_a8 + 1) {
    aiStack_a4[iStack_a8 * 2] =
         *(int *)(iStack_a8 * 0x10 + arg_2) +
         ((*(int *)(iStack_a8 * 0x10 + 8 + arg_2) - *(int *)(iStack_a8 * 0x10 + arg_2)) -
         DAT_10175558) / 2;
    aiStack_a4[iStack_a8 * 2 + 1] = *(int *)(iStack_a8 * 0x10 + 4 + arg_2) + DAT_10176860 / 5;
  }
  pHStack_b4 = (HWND)0x0;
  for (pHStack_ac = GetTopWindow(hwnd); pHStack_ac != (HWND)0x0;
      pHStack_ac = GetWindow(pHStack_ac,2)) {
    pHStack_b4 = pHStack_ac;
  }
  for (pHStack_ac = pHStack_b4; pHStack_ac != (HWND)0x0; pHStack_ac = GetWindow(pHStack_ac,3)) {
    for (iStack_a8 = 0; iStack_a8 < arg_3; iStack_a8 = iStack_a8 + 1) {
      val_2 = GetDlgCtrlID(pHStack_ac);
      if (val_2 == iStack_a8) {
        SetWindowPos(pHStack_ac,(HWND)0x0,aiStack_a4[iStack_a8 * 2],aiStack_a4[iStack_a8 * 2 + 1],
                     DAT_10175558,DAT_10176860,4);
        aiStack_a4[iStack_a8 * 2 + 1] = aiStack_a4[iStack_a8 * 2 + 1] + val_1 / 100;
      }
    }
  }
  return;
}


