/*
 * Decompiled function: UI_DialogProc_00448d60
 * Entry Point: 00448d60
 * Size: 1177 bytes
 */
#include "duel.h"


undefined4 UI_DialogProc_00448d60(HWND hwnd,uint uMsg,HDC wParam,undefined4 lParam)

{
  undefined4 uVar1;
  HBRUSH hbr;
  HWND pHVar2;
  int iVar3;
  tagRECT *ptVar4;
  char local_2b4 [200];
  HDC local_1ec;
  HGDIOBJ local_1e8;
  tagRECT local_1e4;
  uint local_1d4 [50];
  char local_10c [264];
  
  if (uMsg < 0x101) {
    if (uMsg == 0x100) {
LAB_004490d7:
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x14) {
      local_1ec = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_1e4);
      if (DAT_00516964 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_1ec,&local_1e4,hbr);
      }
      else {
        FUN_004709ae((int)local_1ec,(int)&local_1e4,DAT_00516964);
      }
      local_1e8 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x496,0x31,0,0);
      SelectObject(local_1ec,local_1e8);
      SetBkMode(local_1ec,1);
      SetTextColor(local_1ec,DAT_00516990);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x496);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      SetTextColor(local_1ec,DAT_00516aa4);
      DrawTextA(local_1ec,s_Mana_Burn__004f7f40,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00516990);
      DrawTextA(local_1ec,s_Mana_Burn__004f7f4c,-1,&local_1e4,1);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x484);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      if (*DAT_00516b00 == 0) {
        Mem_AllocOrFree_004d9630(local_1d4,(uint *)&DAT_004f7f58);
      }
      else {
        FUN_00448412((char *)local_1d4);
      }
      if (*DAT_00516b00 == 0) {
        _sprintf(local_2b4,s__s_lose__d_life_004f7f5c,local_1d4,DAT_00516b00[1]);
      }
      else {
        _sprintf(local_2b4,s__s_loses__d_life_004f7f6c,local_1d4,DAT_00516b00[1]);
      }
      SetTextColor(local_1ec,DAT_00516aa4);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00516990);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      return 1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
LAB_004490fb:
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x110) {
      DAT_00516b00 = (int *)lParam;
      _sprintf(local_10c,s__s_WINBK_ManaBurn_pic_004f7f28,&DAT_006189a0);
      DAT_00516964 = (HANDLE)FUN_0043d713(local_10c);
      DAT_00516990 = 0x100009a;
      DAT_00516aa4 = 0x10000c9;
      iVar3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x496);
      ShowWindow(pHVar2,iVar3);
      iVar3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x484);
      ShowWindow(pHVar2,iVar3);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (uMsg == 0x111) goto LAB_004490d7;
    if (uMsg == 0x113) {
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (uMsg == 0x204) goto LAB_004490fb;
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      uVar1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return uVar1;
    }
  }
  return 0;
}


