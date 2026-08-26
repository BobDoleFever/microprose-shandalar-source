/*
 * Decompiled function: UI_DialogProc_00443a43
 * Entry Point: 00443a43
 * Size: 3381 bytes
 */
#include "duel.h"


HGDIOBJ UI_DialogProc_00443a43(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  int iVar2;
  HBRUSH pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  tagRECT *ptVar6;
  tagRECT local_48;
  COLORREF local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  HWND local_24;
  HWND local_20;
  uint local_1c;
  tagRECT local_18;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_34 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_34[5].unused) {
        local_38 = DAT_0051698c;
      }
      else {
        local_38 = DAT_00516b20;
      }
      FUN_00471f45((int)local_34,DAT_00516ad8,DAT_00516aac,DAT_00516a74,local_38,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_48);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      iVar2 = SaveDC(DAT_0060157c);
      hDC = DAT_0060157c;
      if (DAT_00516ad4 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(hDC,&local_48,pHVar3);
      }
      else {
        FUN_004709ae((int)DAT_0060157c,(int)&local_48,DAT_00516ad4);
      }
      FUN_00444a85(&local_48,hwnd,DAT_00516b18);
      if (DAT_00516a70 == (HANDLE)0x0) {
        pHVar3 = CreateSolidBrush(0x2908c52);
        FrameRect(hDC,&local_48,pHVar3);
        DeleteObject(pHVar3);
      }
      else {
        FUN_004709ae((int)hDC,(int)&local_48,DAT_00516a70);
      }
      pHVar4 = GetDlgItem(hwnd,0x422);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c4);
      }
      pHVar4 = GetDlgItem(hwnd,0x423);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b8);
      }
      pHVar4 = GetDlgItem(hwnd,0x424);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x420);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b4);
      }
      pHVar4 = GetDlgItem(hwnd,0x425);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c0);
      }
      pHVar4 = GetDlgItem(hwnd,0x426);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169bc);
      }
      pHVar4 = GetDlgItem(hwnd,0x427);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x421);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b0);
      }
      RestoreDC(DAT_0060157c,iVar2);
      GetClientRect(hwnd,&local_48);
      BitBlt(wParam,0,0,local_48.right,local_48.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_28 = wParam;
      FUN_004707a4(wParam);
      local_30 = lParam;
      local_2c = GetDlgCtrlID(lParam);
      SetBkMode(local_28,1);
      if (local_2c == 0x489) {
        SetTextColor(local_28,DAT_005169f4);
      }
      else {
        SetTextColor(local_28,DAT_00516b10);
      }
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Pic_Load_s_QUESTMANA_Black_004447aa
                (&DAT_00516ad4,&DAT_005169f4,&DAT_00516a70,&DAT_005169b0,&DAT_00516b10,
                 (int *)&DAT_00516ad8,(int *)&DAT_00516aac,(int *)&DAT_00516a74,&DAT_00516b20,
                 &DAT_0051698c);
      SetDlgItemTextA(hwnd,0x489,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x428);
        ShowWindow(pHVar4,iVar2);
      }
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      DAT_00516b18 = local_8[1].unused;
      if (local_8[3].unused == 0) {
        SetDlgItemTextA(hwnd,0x424,s__Swamp_004f7d44);
        SetDlgItemTextA(hwnd,0x423,s__Island_004f7d4c);
        SetDlgItemTextA(hwnd,0x426,s__Forest_004f7d54);
        SetDlgItemTextA(hwnd,0x425,s__Mountain_004f7d5c);
        SetDlgItemTextA(hwnd,0x422,s__Plains_004f7d68);
        SetDlgItemTextA(hwnd,0x427,s_Generic___X__004f7d70);
      }
      if ((local_8[4].unused & 2) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x420);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x424);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 4) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x423);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 8) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x426);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x10) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x425);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x20) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x422);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 1) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x421);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x427);
        ShowWindow(pHVar4,iVar2);
      }
      FUN_00472552(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      local_1c = (uint)wParam & 0xffff;
      if (local_1c < 0x41d) {
        if (local_1c == 0x41c) {
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 5;
          FUN_00444a85(&local_18,hwnd,5);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
        }
        else if ((local_1c != 0) && (local_1c < 3)) {
          FUN_004449cf((int)DAT_00516ad4,(int)DAT_00516a70,0x5169b0,DAT_00516ad8,DAT_00516aac,
                       DAT_00516a74);
          if (local_1c == 1) {
            EndDialog(hwnd,DAT_00516b18);
          }
          else {
            EndDialog(hwnd,-2);
          }
        }
      }
      else {
        switch(local_1c) {
        case 0x41d:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 3;
          FUN_00444a85(&local_18,hwnd,3);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41e:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 2;
          FUN_00444a85(&local_18,hwnd,2);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41f:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 4;
          FUN_00444a85(&local_18,hwnd,4);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x420:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 1;
          FUN_00444a85(&local_18,hwnd,1);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x421:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = 0;
          FUN_00444a85(&local_18,hwnd,0);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x428:
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00516b18 = GetWindowLongA(hwnd,8);
          FUN_00444a85(&local_18,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&local_18,0);
          pHVar4 = GetDlgItem(hwnd,1);
          SetFocus(pHVar4);
        }
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar1 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    local_20 = (HWND)wParam;
    local_24 = lParam;
    pHVar4 = GetDlgItem(hwnd,2);
    if (pHVar4 == local_20) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    if (local_24 != (HWND)0x0) {
      InvalidateRect(local_24,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


