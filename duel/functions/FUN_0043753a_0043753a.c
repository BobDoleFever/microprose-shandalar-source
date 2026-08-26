/*
 * Decompiled function: FUN_0043753a
 * Entry Point: 0043753a
 * Size: 327 bytes
 */
#include "duel.h"


void FUN_0043753a(int arg1,int arg2)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  undefined4 local_c;
  
  if (arg1 == 0) {
    local_c = DAT_00618950;
    hWnd = DAT_00618978;
    hWnd_00 = DAT_00663e68;
    hWnd_01 = DAT_00618160;
    hWnd_02 = DAT_00601550;
  }
  else {
    local_c = DAT_00664c34;
    hWnd = DAT_0061737c;
    hWnd_00 = DAT_00664c04;
    hWnd_01 = DAT_00664c28;
    hWnd_02 = DAT_00617438;
  }
  if (arg2 == 0) {
    ShowWindow(hWnd_01,5);
    ShowWindow(hWnd_00,5);
    ShowWindow(hWnd,5);
    ShowWindow(local_c,5);
    ShowWindow(hWnd_02,0);
  }
  else {
    ShowWindow(hWnd_02,5);
    BringWindowToTop(hWnd_02);
    ShowWindow(hWnd_01,0);
    if (DAT_00663e24 != 2) {
      ShowWindow(hWnd_00,0);
      ShowWindow(hWnd,0);
      ShowWindow(local_c,0);
    }
  }
  return;
}


