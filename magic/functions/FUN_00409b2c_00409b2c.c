/*
 * Decompiled function: FUN_00409b2c
 * Entry Point: 00409b2c
 * Size: 327 bytes
 */
#include "magic.h"


void FUN_00409b2c(int arg1,int arg2)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  undefined4 local_c;
  
  if (arg1 == 0) {
    local_c = DAT_006b2d60;
    hWnd = DAT_006b2e10;
    hWnd_00 = DAT_006fe48c;
    hWnd_01 = DAT_006b2530;
    hWnd_02 = DAT_0068a620;
  }
  else {
    local_c = DAT_006ff560;
    hWnd = DAT_006a4928;
    hWnd_00 = DAT_006ff388;
    hWnd_01 = DAT_006ff4a8;
    hWnd_02 = DAT_006a49f0;
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
    if (DAT_006fe444 != 2) {
      ShowWindow(hWnd_00,0);
      ShowWindow(hWnd,0);
      ShowWindow(local_c,0);
    }
  }
  return;
}


