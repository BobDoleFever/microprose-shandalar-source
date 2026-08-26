/*
 * Decompiled function: FUN_1000862d
 * Entry Point: 1000862d
 * Size: 478 bytes
 */
#include "deckdll.h"


void FUN_1000862d(HWND hwnd,int arg_2,int arg_3)

{
  int val_1;
  int val_2;
  HWND local_b4;
  HWND local_ac;
  int local_a8;
  int aiStack_a4 [40];
  
  val_1 = DAT_10176860 * 0x12;
  for (local_a8 = 0; local_a8 < arg_3; local_a8 = local_a8 + 1) {
    aiStack_a4[local_a8 * 2] =
         *(int *)(local_a8 * 0x10 + arg_2) +
         ((*(int *)(local_a8 * 0x10 + 8 + arg_2) - *(int *)(local_a8 * 0x10 + arg_2)) - DAT_10175558
         ) / 2;
    aiStack_a4[local_a8 * 2 + 1] = *(int *)(local_a8 * 0x10 + 4 + arg_2) + DAT_10176860 / 5;
  }
  local_b4 = (HWND)0x0;
  for (local_ac = GetTopWindow(hwnd); local_ac != (HWND)0x0; local_ac = GetWindow(local_ac,2)) {
    local_b4 = local_ac;
  }
  for (local_ac = local_b4; local_ac != (HWND)0x0; local_ac = GetWindow(local_ac,3)) {
    for (local_a8 = 0; local_a8 < arg_3; local_a8 = local_a8 + 1) {
      val_2 = GetDlgCtrlID(local_ac);
      if (val_2 == local_a8) {
        SetWindowPos(local_ac,(HWND)0x0,aiStack_a4[local_a8 * 2],aiStack_a4[local_a8 * 2 + 1],
                     DAT_10175558,DAT_10176860,4);
        aiStack_a4[local_a8 * 2 + 1] = aiStack_a4[local_a8 * 2 + 1] + val_1 / 100;
      }
    }
  }
  return;
}


