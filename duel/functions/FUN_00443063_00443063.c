/*
 * Decompiled function: FUN_00443063
 * Entry Point: 00443063
 * Size: 1344 bytes
 */
#include "duel.h"


HGDIOBJ FUN_00443063(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  HWND pHVar2;
  int iVar3;
  HBRUSH hbr;
  code *dwNewLong;
  tagRECT local_44;
  undefined4 local_34;
  HWND local_30;
  HWND local_2c;
  int local_28;
  HDC local_24;
  HWND local_20;
  HWND local_1c;
  UINT local_18;
  UINT local_14;
  int local_10;
  uint local_c;
  HWND local_8;
  
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_30 = param_4;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_30[5].unused) {
        local_34 = DAT_00516ab8;
      }
      else {
        local_34 = DAT_00516988;
      }
      FUN_00471f45(local_30,DAT_00516980,DAT_00516a78,DAT_00516a00,local_34,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_44);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      iVar3 = SaveDC(DAT_0060157c);
      hDC = DAT_0060157c;
      if (DAT_00516b0c == 0) {
        hbr = GetStockObject(2);
        FillRect(hDC,&local_44,hbr);
      }
      else {
        FUN_004709ae(DAT_0060157c,&local_44,DAT_00516b0c);
      }
      RestoreDC(DAT_0060157c,iVar3);
      GetClientRect(param_1,&local_44);
      BitBlt(param_3,0,0,local_44.right,local_44.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_24 = param_3;
      FUN_004707a4(param_3);
      local_2c = param_4;
      local_28 = GetDlgCtrlID(param_4);
      SetBkMode(local_24,1);
      SetTextColor(local_24,DAT_00516aa0);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (param_2 == 0x110) {
      local_8 = param_4;
      SetWindowLongA(param_1,8,param_4[1].unused);
      FUN_0044364b(&DAT_00516b0c,&DAT_00516aa0,&DAT_00516980,&DAT_00516a78,&DAT_00516a00,
                   &DAT_00516988,&DAT_00516ab8);
      SetDlgItemTextA(param_1,0x41a,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        iVar3 = 0;
        pHVar2 = GetDlgItem(param_1,0x41b);
        ShowWindow(pHVar2,iVar3);
      }
      SendMessageA(param_1,0x401,1,0);
      SetDlgItemInt(param_1,0x419,local_8[1].unused,0);
      dwNewLong = FUN_004435ad;
      iVar3 = -4;
      pHVar2 = GetDlgItem(param_1,0x419);
      DAT_006944c4 = SetWindowLongA(pHVar2,iVar3,(LONG)dwNewLong);
      pHVar2 = GetDlgItem(param_1,0x419);
      SetFocus(pHVar2);
      SendDlgItemMessageA(param_1,0x419,0xb1,0,-1);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x111) {
      local_c = (uint)param_3 & 0xffff;
      if (local_c == 1) {
        local_14 = GetDlgItemInt(param_1,0x419,&local_10,0);
        if (local_10 == 0) {
          pHVar2 = GetDlgItem(param_1,0x419);
          SetFocus(pHVar2);
          SendDlgItemMessageA(param_1,0x419,0xb1,0,-1);
        }
        else {
          FUN_00443727(DAT_00516b0c,DAT_00516980,DAT_00516a78,DAT_00516a00);
          EndDialog(param_1,local_14);
        }
      }
      else if (local_c == 2) {
        FUN_00443727(DAT_00516b0c,DAT_00516980,DAT_00516a78,DAT_00516a00);
        EndDialog(param_1,-1);
      }
      else if (local_c == 0x41b) {
        local_18 = GetWindowLongA(param_1,8);
        SetDlgItemInt(param_1,0x419,local_18,0);
        pHVar2 = GetDlgItem(param_1,0x419);
        SetFocus(pHVar2);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      pvVar1 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar1;
    }
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 == 0x4c8) {
    local_1c = (HWND)param_3;
    local_20 = param_4;
    pHVar2 = GetDlgItem(param_1,2);
    if (pHVar2 == local_1c) {
      SendMessageA(param_1,0x401,2,0);
    }
    else {
      SendMessageA(param_1,0x401,1,0);
    }
    if (local_1c != (HWND)0x0) {
      InvalidateRect(local_1c,(RECT *)0x0,1);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


