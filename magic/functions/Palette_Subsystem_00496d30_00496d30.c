/*
 * Decompiled function: Palette_Subsystem_00496d30
 * Entry Point: 00496d30
 * Size: 383 bytes
 */
#include "magic.h"


int Palette_Subsystem_00496d30(HDC hdc,int *y,WPARAM *arg_3,int height)

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
    FUN_0047884f(*arg_3,0,local_34.right - local_34.left,local_34.bottom - local_34.top);
  }
  if ((4 < local_34.left) && (4 < local_34.top)) {
    Surface_FillRect((int *)g_DisplaySurfaceScreen,-4,-4,local_14 + 8,local_c + 8,0xff);
  }
  local_8 = FUN_00478763(hdc,&local_24,*arg_3,0);
  if (local_8 == 0) {
    FUN_0046bfc2(hdc,&local_24,*arg_3,0);
  }
  RestoreDC(hdc,local_10);
  return local_8;
}


