/*
 * Decompiled function: FUN_004833e9
 * Entry Point: 004833e9
 * Size: 417 bytes
 */
#include "magic.h"


int FUN_004833e9(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  local_10 = 0;
  for (local_8 = 0; local_8 < LVar2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < *(int *)(LVar1 + 0xcc + local_8 * 0x19c); local_c = local_c + 1) {
      iVar3 = FUN_0046bc92(*(HWND *)(local_c * 4 + local_8 * 0x19c + 4 + LVar1));
      if (iVar3 == arg2) {
        iVar3 = FUN_004833e9(hwnd,*(int *)(local_8 * 0x19c + local_c * 4 + 4 + LVar1));
        local_10 = local_10 + 1 + iVar3;
      }
    }
    for (local_c = 0; local_c < *(int *)(LVar1 + 0x198 + local_8 * 0x19c); local_c = local_c + 1) {
      iVar3 = FUN_0046bc92(*(HWND *)(local_c * 4 + local_8 * 0x19c + 0xd0 + LVar1));
      if (iVar3 == arg2) {
        iVar3 = FUN_004833e9(hwnd,*(int *)(local_8 * 0x19c + local_c * 4 + 0xd0 + LVar1));
        local_10 = local_10 + 1 + iVar3;
      }
    }
  }
  return local_10;
}


