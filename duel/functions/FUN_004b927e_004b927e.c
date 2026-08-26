/*
 * Decompiled function: FUN_004b927e
 * Entry Point: 004b927e
 * Size: 326 bytes
 */
#include "duel.h"


int FUN_004b927e(HDC hdc,int *y,WPARAM *arg_3,int height)

{
  tagRECT local_34;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = SaveDC(hdc);
  local_14 = 300;
  local_c = 0xf0;
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,local_14,local_c,(LPSIZE)0x0);
  SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
  SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
  SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
  SetRect(&local_24,0,0,local_14,local_c);
  CopyRect(&local_34,&local_24);
  LPtoDP(hdc,(LPPOINT)&local_34,2);
  if (height != 0) {
    FUN_004869bd(*arg_3,0,local_34.right - local_34.left,local_34.bottom - local_34.top);
  }
  local_8 = FUN_004868d1(hdc,&local_24,*arg_3,0);
  if (local_8 == 0) {
    FUN_00438c81(hdc,&local_24,*arg_3,0);
  }
  RestoreDC(hdc,local_10);
  return local_8;
}


