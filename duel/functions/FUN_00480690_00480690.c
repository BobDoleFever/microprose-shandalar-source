/*
 * Decompiled function: FUN_00480690
 * Entry Point: 00480690
 * Size: 374 bytes
 */
#include "duel.h"


void FUN_00480690(HWND hwnd)

{
  INT_PTR IVar1;
  
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe1,hwnd,UI_DialogProc_00480806,0);
  if (IVar1 != 0) {
    if (DAT_00663e28 == -1) {
      Palette_Subsystem_0049c3ac(0,DAT_006169f0,DAT_00663e2c);
    }
    else {
      Palette_Subsystem_0049c3ac(0,DAT_00663e28,DAT_00663e2c);
    }
    LockWindowUpdate(DAT_00618990);
    FUN_0043753a(0,0);
    FUN_0043753a(1,0);
    FUN_004b5565(DAT_00618990,DAT_00663e24);
    FUN_004b7f54(DAT_00664d90);
    FUN_004b1cc1(DAT_00617378);
    FUN_004b1cc1(DAT_00618988);
    FUN_004baa8b(DAT_006152b0);
    FUN_004baa8b(DAT_00663df4);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(DAT_006152b0,0x435,0,0);
    SendMessageA(DAT_00663df4,0x435,0,0);
    SendMessageA(DAT_00617378,0x435,0,0);
    SendMessageA(DAT_00618988,0x435,0,0);
    SendMessageA(DAT_00618ab0,0x435,0,0);
    SendMessageA(DAT_00663df0,0x435,0,0);
    Rules_ParseFilter_00481890();
  }
  return;
}


