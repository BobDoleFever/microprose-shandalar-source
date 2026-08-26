/*
 * Decompiled function: UI_WndProc_00490233
 * Entry Point: 00490233
 * Size: 309 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_00490233(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam)

{
  HWND pHVar1;
  uint lParam_00;
  LRESULT LVar2;
  tagPOINT *lpPoints;
  UINT cPoints;
  tagPOINT local_c;
  
  if (uMsg < 0x10) {
    if ((uMsg == 0xf) || ((uMsg != 0 && (uMsg < 3)))) goto LAB_00490247;
  }
  else if (uMsg < 0x203) {
    if (0x200 < uMsg) {
      local_c.x = lParam & 0xffff;
      local_c.y = lParam >> 0x10;
      cPoints = 1;
      lpPoints = &local_c;
      pHVar1 = GetParent(hwnd);
      MapWindowPoints(hwnd,pHVar1,lpPoints,cPoints);
      lParam_00 = local_c.y << 0x10 | local_c.x & 0xffffU;
      pHVar1 = GetParent(hwnd);
      SendMessageA(pHVar1,uMsg,wParam,lParam_00);
      return 0;
    }
    if (uMsg == 0x14) {
LAB_00490247:
      LVar2 = CallWindowProcA(Card_Setup_00467a68,hwnd,uMsg,wParam,lParam);
      return LVar2;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) goto LAB_00490247;
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar2;
}


