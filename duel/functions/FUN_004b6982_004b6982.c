/*
 * Decompiled function: FUN_004b6982
 * Entry Point: 004b6982
 * Size: 705 bytes
 */
#include "duel.h"


undefined4 FUN_004b6982(HWND param_1,uint param_2,HDC param_3,undefined4 param_4)

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
  
  if (param_2 < 0x101) {
    if (param_2 == 0x100) {
LAB_004b6b66:
      EndDialog(param_1,0);
      return 1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_30);
      hbr = GetStockObject(4);
      FillRect(param_3,&local_30,hbr);
      h = (HGDIOBJ)SendDlgItemMessageA(param_1,0x49d,0x31,0,0);
      SelectObject(param_3,h);
      SetBkMode(param_3,1);
      SetTextColor(param_3,DAT_005dcda4);
      lpRect = &local_30;
      hWnd = GetDlgItem(param_1,0x49d);
      GetWindowRect(hWnd,lpRect);
      MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_30,2);
      SetTextColor(param_3,DAT_005dcda0);
      DrawTextA(param_3,s_Still_thinking____00507020,-1,&local_30,1);
      OffsetRect(&local_30,-2,-2);
      SetTextColor(param_3,DAT_005dcda4);
      DrawTextA(param_3,s_Still_thinking____00507034,-1,&local_30,1);
      return 1;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
LAB_004b6b7c:
      EndDialog(param_1,0);
      return 1;
    }
    if (param_2 == 0x110) {
      DAT_00664a5c = param_1;
      DAT_005dcda4 = 0x100009a;
      DAT_005dcda0 = 0x10000c9;
      local_20 = 1;
      local_1c = 0xffffffff;
      GetClientRect(param_1,&local_14);
      local_18 = CreateWindowExA(0,s_MAGICGAME_CardClass_0050700c,
                                 s_StillThinking_small_card_00506ff0,0x50000000,
                                 (local_14.right - DAT_0061534c) / 2,
                                 (local_14.bottom - DAT_0061898c) + -10,DAT_0061534c,DAT_0061898c,
                                 param_1,(HMENU)0x1,DAT_00664680,&local_20);
      SetTimer(param_1,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (param_2 == 0x111) goto LAB_004b6b66;
    if (param_2 == 0x113) {
      EndDialog(param_1,0);
      return 1;
    }
  }
  else {
    if (param_2 == 0x204) goto LAB_004b6b7c;
    if ((0x30e < param_2) && (param_2 < 0x312)) {
      uVar1 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return uVar1;
    }
  }
  return 0;
}


