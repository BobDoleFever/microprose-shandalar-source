/*
 * Decompiled function: Pic_Subsystem_004455e3
 * Entry Point: 004455e3
 * Size: 704 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004455e3(HWND hwnd,uint y,HDC hdc,undefined4 arg_4)

{
  undefined4 uVar1;
  HBRUSH hbr;
  HGDIOBJ h;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_30;
  undefined4 local_20;
  undefined4 local_1c;
  HWND local_18;
  tagRECT local_14;
  
  if (y < 0x101) {
    if (y == 0x100) {
LAB_004457c6:
      EndDialog(hwnd,0);
      return 1;
    }
    if (y == 0x14) {
      FUN_004f3955(hdc);
      GetClientRect(hwnd,&local_30);
      hbr = GetStockObject(4);
      FillRect(hdc,&local_30,hbr);
      h = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x49d,0x31,0,0);
      SelectObject(hdc,h);
      SetBkMode(hdc,1);
      SetTextColor(hdc,DAT_00538b94);
      lpRect = &local_30;
      hWnd = GetDlgItem(hwnd,0x49d);
      GetWindowRect(hWnd,lpRect);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_30,2);
      SetTextColor(hdc,DAT_00538b90);
      DrawTextA(hdc,s_Still_thinking____005220f4,-1,&local_30,1);
      OffsetRect(&local_30,-2,-2);
      SetTextColor(hdc,DAT_00538b94);
      DrawTextA(hdc,s_Still_thinking____00522108,-1,&local_30,1);
      return 1;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
LAB_004457dc:
      EndDialog(hwnd,0);
      return 1;
    }
    if (y == 0x110) {
      DAT_006ff1a8 = hwnd;
      DAT_00538b94 = 0x100009a;
      DAT_00538b90 = 0x10000c9;
      local_20 = 1;
      local_1c = 0xffffffff;
      GetClientRect(hwnd,&local_14);
      local_18 = CreateWindowExA(0,s_MAGICGAME_CardClass_005220e0,
                                 s_StillThinking_small_card_005220c4,0x50000000,
                                 (local_14.right - DAT_006a28b0) / 2,
                                 (local_14.bottom - DAT_006b2e30) + -10,DAT_006a28b0,DAT_006b2e30,
                                 hwnd,(HMENU)0x1,g_AppHInstance,&local_20);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (y == 0x111) goto LAB_004457c6;
    if (y == 0x113) {
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (y == 0x204) goto LAB_004457dc;
    if ((0x30e < y) && (y < 0x312)) {
      uVar1 = FUN_004f5d1a(hwnd,y,(HWND)hdc,arg_4);
      return uVar1;
    }
  }
  return 0;
}


