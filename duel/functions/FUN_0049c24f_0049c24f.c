/*
 * Decompiled function: FUN_0049c24f
 * Entry Point: 0049c24f
 * Size: 129 bytes
 */
#include "duel.h"


INT_PTR FUN_0049c24f(HWND hwnd)

{
  INT_PTR IVar1;
  
  DAT_00601578 = 0;
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe7,hwnd,UI_DialogProc_0049c2d0,0);
  if (IVar1 == -1) {
    MessageBoxA((HWND)0x0,s_Couldn_t_bring_up_the_dialog_box_00505d30,s_Duel_Error_00505d24,0);
  }
  UpdateWindow(DAT_00663df4);
  UpdateWindow(DAT_006152b0);
  UpdateWindow(DAT_006152e0);
  return IVar1;
}


