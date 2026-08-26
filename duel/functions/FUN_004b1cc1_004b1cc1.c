/*
 * Decompiled function: FUN_004b1cc1
 * Entry Point: 004b1cc1
 * Size: 529 bytes
 */
#include "duel.h"


void FUN_004b1cc1(HWND hwnd)

{
  HWND hWnd;
  int iVar1;
  int *arg_4;
  int *arg_5;
  UINT uCmd;
  int arg_6;
  int local_358 [2];
  LONG local_350;
  int local_34c;
  int local_348;
  int local_344;
  int local_340;
  LONG local_33c;
  HWND local_338;
  WPARAM aWStack_334 [200];
  tagRECT local_14;
  
  local_350 = GetWindowLongA(hwnd,4);
  local_33c = GetWindowLongA(hwnd,0);
  GetClientRect(hwnd,&local_14);
  FUN_004b1ed2(hwnd);
  uCmd = 1;
  hWnd = GetWindow(hwnd,5);
  local_338 = GetWindow(hWnd,uCmd);
  local_34c = 0;
  for (; local_338 != (HWND)0x0; local_338 = GetWindow(local_338,3)) {
    iVar1 = FUN_004864b1(local_338);
    if (iVar1 == 0) {
      aWStack_334[local_34c] = (WPARAM)local_338;
      local_34c = local_34c + 1;
    }
  }
  for (local_348 = 0; local_348 < local_34c; local_348 = local_348 + 1) {
    local_338 = (HWND)aWStack_334[local_348];
    iVar1 = FUN_004864b1(local_338);
    if (iVar1 == 0) {
      SendMessageA(local_338,0x401,(WPARAM)local_358,0);
      arg_6 = 1;
      arg_5 = &local_344;
      arg_4 = &local_340;
      iVar1 = FUN_00485587(local_338);
      FUN_004b1fcf(hwnd,local_358,iVar1,arg_4,arg_5,arg_6);
      SetWindowPos(local_338,(HWND)0x0,local_340,local_344,0,0,5);
      BringWindowToTop(local_338);
    }
  }
  for (local_348 = 0; local_348 < local_34c; local_348 = local_348 + 1) {
    local_338 = (HWND)aWStack_334[local_348];
    SendMessageA(hwnd,0x410,(WPARAM)local_338,0);
  }
  SendMessageA(hwnd,0x412,0,0);
  return;
}


