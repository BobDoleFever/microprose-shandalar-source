/*
 * Decompiled function: Ai_Subsystem_004b8421
 * Entry Point: 004b8421
 * Size: 2205 bytes
 */
#include "magic.h"


HBRUSH Ai_Subsystem_004b8421(HWND hwnd,uint uMsg,HWND wParam,HWND lParam)

{
  POINT pt;
  uint uVar1;
  UINT UVar2;
  HBRUSH pHVar3;
  HDC hdc;
  HWND pHVar4;
  int iVar5;
  BOOL BVar6;
  tagRECT *ptVar7;
  tagPAINTSTRUCT local_118;
  tagRECT local_d8;
  uint local_c8;
  uint local_c4;
  tagRECT local_c0;
  HWND local_b0;
  tagRECT local_ac;
  COLORREF local_9c;
  HWND local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_84;
  HWND local_80;
  uint local_7c;
  UINT local_78;
  UINT local_74;
  HWND local_70;
  char local_6c [100];
  UINT local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_b0 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_ac);
      if (DAT_00556aa0 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(3);
        FillRect((HDC)local_b0,&local_ac,pHVar3);
      }
      else {
        FUN_004f3b5f((int)local_b0,(int)&local_ac,DAT_00556aa0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_118);
      if ((hdc != (HDC)0x0) && (FUN_004f3955(hdc), DAT_00556954 != 0xffffffff)) {
        ptVar7 = &local_d8;
        pHVar4 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_d8,2);
        Palette_Subsystem_0049c7c7
                  (hdc,&local_d8.left,(WPARAM *)(&DAT_006b3070 + DAT_00556954 * 0x98),0,0x11,0);
      }
      EndPaint(hwnd,&local_118);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      DAT_00556a90 = lParam;
      DAT_00556954 = lParam[5].unused;
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x475);
      ShowWindow(pHVar4,iVar5);
      sprintf(local_6c,s__max__d__0052d490,DAT_00556a90->unused);
      SetDlgItemTextA(hwnd,0x478,local_6c);
      sprintf(local_6c,s__max__d__0052d49c,DAT_00556a90[1].unused);
      SetDlgItemTextA(hwnd,0x47b,local_6c);
      Ai_Subsystem_004b8cc3
                (&DAT_00556aa0,&DAT_00556ab0,(int *)&DAT_00556930,(int *)&DAT_005569c8,
                 (int *)&DAT_00556a84,&DAT_005569a0,&DAT_00556ae4);
      SendDlgItemMessageA(hwnd,0x476,0x465,0,(uint)(ushort)DAT_00556a90->unused);
      SendDlgItemMessageA(hwnd,0x47a,0x465,0,(uint)(ushort)DAT_00556a90[1].unused);
      SendDlgItemMessageA(hwnd,0x476,0x467,0,(uint)(ushort)DAT_00556a90[2].unused);
      SendDlgItemMessageA(hwnd,0x47a,0x467,0,(uint)(ushort)DAT_00556a90[3].unused);
      local_8 = Ai_Subsystem_004b8dfd(DAT_00556a90[2].unused,DAT_00556a90[3].unused);
      SetDlgItemInt(hwnd,0x47c,local_8,1);
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      local_70 = GetDlgItem(hwnd,1);
      uVar1 = GetWindowLongA(local_70,-0x10);
      SetWindowLongA(local_70,-0x10,uVar1 | 0x800000);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x2b) {
      local_98 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_98[5].unused) {
        local_9c = DAT_00556ae4;
      }
      else {
        local_9c = DAT_005569a0;
      }
      FUN_004f5107((int)local_98,DAT_00556930,DAT_005569c8,DAT_00556a84,local_9c,0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_8c = wParam;
      FUN_004f3955((HDC)wParam);
      local_94 = lParam;
      local_90 = GetDlgCtrlID(lParam);
      pHVar4 = GetFocus();
      if (pHVar4 == local_94) {
        SetTextColor((HDC)local_8c,DAT_00556ae4);
      }
      else {
        SetTextColor((HDC)local_8c,DAT_00556ab0);
      }
      if (((local_90 != 0x47c) && (local_90 != 0x49a)) && (local_90 != 0x49b)) {
        SetBkMode((HDC)local_8c,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetBkMode((HDC)local_8c,1);
      return DAT_00556930;
    }
    if (uMsg == 0x111) {
      local_7c = (uint)wParam & 0xffff;
      if (local_7c == 1) {
        UVar2 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        DAT_00556a90[2].unused = UVar2;
        local_74 = DAT_00556a90[2].unused;
        UVar2 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        DAT_00556a90[3].unused = UVar2;
        local_78 = DAT_00556a90[3].unused;
        iVar5 = Ai_Subsystem_004b8dfd(local_74,local_78);
        DAT_00556a90[4].unused = iVar5;
        Ai_Subsystem_004b8da0((int)DAT_00556aa0,DAT_00556930,DAT_005569c8,DAT_00556a84);
        EndDialog(hwnd,1);
      }
      else if (local_7c == 2) {
        Ai_Subsystem_004b8da0((int)DAT_00556aa0,DAT_00556930,DAT_005569c8,DAT_00556a84);
        EndDialog(hwnd,-2);
      }
      else if (((local_7c == 0x477) || (local_7c == 0x479)) && ((uint)wParam >> 0x10 == 0x400)) {
        local_74 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        local_78 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        SetDlgItemInt(hwnd,0x49a,local_74 - (local_78 - 1),1);
        SetDlgItemInt(hwnd,0x49b,local_78 - 1,1);
        BVar6 = 1;
        UVar2 = Ai_Subsystem_004b8dfd(local_74,local_78);
        SetDlgItemInt(hwnd,0x47c,UVar2,BVar6);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pHVar3 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
        return pHVar3;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HBRUSH)0x0;
        }
        if (uMsg != 0x204) {
          return (HBRUSH)0x0;
        }
      }
      local_c8 = (uint)lParam & 0xffff;
      local_c4 = (uint)lParam >> 0x10;
      if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
        ptVar7 = &local_c0;
        pHVar4 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c0,2);
        if ((DAT_00556954 != 0xffffffff) &&
           (pt.y = local_c4, pt.x = local_c8, BVar6 = PtInRect(&local_c0,pt), BVar6 != 0)) {
          SendMessageA(DAT_0069f744,0x401,DAT_00556954,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x4c8) {
      local_80 = wParam;
      local_84 = lParam;
      pHVar4 = GetDlgItem(hwnd,2);
      if (pHVar4 == local_80) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_80 != (HWND)0x0) {
        InvalidateRect(local_80,(RECT *)0x0,1);
      }
      if (local_84 != (HWND)0x0) {
        InvalidateRect(local_84,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}


