/*
 * Decompiled function: FUN_0046ad4a
 * Entry Point: 0046ad4a
 * Size: 114 bytes
 */
#include "magic.h"


int FUN_0046ad4a(HWND hwnd)

{
  LONG arg1;
  LONG arg2;
  uint uVar1;
  uint uVar2;
  
  arg1 = GetWindowLongA(hwnd,0);
  arg2 = GetWindowLongA(hwnd,4);
  uVar1 = Ai_Subsystem_004b5cbb(arg1,arg2);
  uVar2 = (int)uVar1 >> 0x1f;
  return (arg2 % 3) * 3 + (((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2) * 2;
}


