/*
 * Decompiled function: Ai_CalcManaRequirement_004b7897
 * Entry Point: 004b7897
 * Size: 1180 bytes
 */
#include "magic.h"


undefined4 Ai_CalcManaRequirement_004b7897(HWND hwnd,uint uMsg,HDC wParam,int *lParam)

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
  char local_1d4 [200];
  char local_10c [264];
  
  if (uMsg < 0x101) {
    if (uMsg == 0x100) {
LAB_004b7c11:
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x14) {
      local_1ec = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_1e4);
      if (DAT_00556934 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_1ec,&local_1e4,hbr);
      }
      else {
        FUN_004f3b5f((int)local_1ec,(int)&local_1e4,DAT_00556934);
      }
      local_1e8 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x496,0x31,0,0);
      SelectObject(local_1ec,local_1e8);
      SetBkMode(local_1ec,1);
      SetTextColor(local_1ec,DAT_00556960);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x496);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      SetTextColor(local_1ec,DAT_00556a74);
      DrawTextA(local_1ec,s_Mana_Burn__0052d420,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00556960);
      DrawTextA(local_1ec,s_Mana_Burn__0052d42c,-1,&local_1e4,1);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x484);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      if (*DAT_00556ad0 == 0) {
        strcpy(local_1d4,&DAT_0052d438);
      }
      else {
        Ai_Subsystem_004b6f49(local_1d4);
      }
      if (*DAT_00556ad0 == 0) {
        sprintf(local_2b4,s__s_lose__d_life_0052d43c,local_1d4,DAT_00556ad0[1]);
      }
      else {
        sprintf(local_2b4,s__s_loses__d_life_0052d44c,local_1d4,DAT_00556ad0[1]);
      }
      SetTextColor(local_1ec,DAT_00556a74);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00556960);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      return 1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
LAB_004b7c35:
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x110) {
      DAT_00556ad0 = lParam;
      sprintf(local_10c,s__s_WINBK_ManaBurn_pic_0052d408,&DAT_006b2e90);
      DAT_00556934 = (HANDLE)Pic_Load_00423833(local_10c);
      DAT_00556960 = 0x100009a;
      DAT_00556a74 = 0x10000c9;
      iVar3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x496);
      ShowWindow(pHVar2,iVar3);
      iVar3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x484);
      ShowWindow(pHVar2,iVar3);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (uMsg == 0x111) goto LAB_004b7c11;
    if (uMsg == 0x113) {
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (uMsg == 0x204) goto LAB_004b7c35;
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      uVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return uVar1;
    }
  }
  return 0;
}


