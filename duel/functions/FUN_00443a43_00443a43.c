/*
 * Decompiled function: FUN_00443a43
 * Entry Point: 00443a43
 * Size: 3381 bytes
 */
#include "duel.h"


HGDIOBJ FUN_00443a43(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  int iVar2;
  HBRUSH pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  tagRECT *ptVar6;
  tagRECT local_48;
  undefined4 local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  HWND local_24;
  HWND local_20;
  uint local_1c;
  RECT local_18;
  HWND local_8;
  
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_34 = param_4;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_34[5].unused) {
        local_38 = DAT_0051698c;
      }
      else {
        local_38 = DAT_00516b20;
      }
      FUN_00471f45(local_34,DAT_00516ad8,DAT_00516aac,DAT_00516a74,local_38,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_48);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      iVar2 = SaveDC(DAT_0060157c);
      hDC = DAT_0060157c;
      if (DAT_00516ad4 == 0) {
        pHVar3 = GetStockObject(2);
        FillRect(hDC,&local_48,pHVar3);
      }
      else {
        FUN_004709ae(DAT_0060157c,&local_48,DAT_00516ad4);
      }
      FUN_00444a85(&local_48,param_1,DAT_00516b18);
      if (DAT_00516a70 == 0) {
        pHVar3 = CreateSolidBrush(0x2908c52);
        FrameRect(hDC,&local_48,pHVar3);
        DeleteObject(pHVar3);
      }
      else {
        FUN_004709ae(hDC,&local_48,DAT_00516a70);
      }
      pHVar4 = GetDlgItem(param_1,0x422);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x41c);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c4);
      }
      pHVar4 = GetDlgItem(param_1,0x423);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x41e);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b8);
      }
      pHVar4 = GetDlgItem(param_1,0x424);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x420);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b4);
      }
      pHVar4 = GetDlgItem(param_1,0x425);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x41f);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c0);
      }
      pHVar4 = GetDlgItem(param_1,0x426);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x41d);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169bc);
      }
      pHVar4 = GetDlgItem(param_1,0x427);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(param_1,0x421);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b0);
      }
      RestoreDC(DAT_0060157c,iVar2);
      GetClientRect(param_1,&local_48);
      BitBlt(param_3,0,0,local_48.right,local_48.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_28 = param_3;
      FUN_004707a4(param_3);
      local_30 = param_4;
      local_2c = GetDlgCtrlID(param_4);
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
    if (param_2 == 0x110) {
      local_8 = param_4;
      SetWindowLongA(param_1,8,param_4[1].unused);
      FUN_004447aa(&DAT_00516ad4,&DAT_005169f4,&DAT_00516a70,&DAT_005169b0,&DAT_00516b10,
                   &DAT_00516ad8,&DAT_00516aac,&DAT_00516a74,&DAT_00516b20,&DAT_0051698c);
      SetDlgItemTextA(param_1,0x489,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x428);
        ShowWindow(pHVar4,iVar2);
      }
      pHVar4 = GetDlgItem(param_1,1);
      SetFocus(pHVar4);
      SendMessageA(param_1,0x401,1,0);
      DAT_00516b18 = local_8[1].unused;
      if (local_8[3].unused == 0) {
        SetDlgItemTextA(param_1,0x424,s__Swamp_004f7d44);
        SetDlgItemTextA(param_1,0x423,s__Island_004f7d4c);
        SetDlgItemTextA(param_1,0x426,s__Forest_004f7d54);
        SetDlgItemTextA(param_1,0x425,s__Mountain_004f7d5c);
        SetDlgItemTextA(param_1,0x422,s__Plains_004f7d68);
        SetDlgItemTextA(param_1,0x427,s_Generic___X__004f7d70);
      }
      if ((local_8[4].unused & 2) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x420);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x424);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 4) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x41e);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x423);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 8) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x41d);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x426);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x10) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x41f);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x425);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x20) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x41c);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x422);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 1) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x421);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(param_1,0x427);
        ShowWindow(pHVar4,iVar2);
      }
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x111) {
      local_1c = (uint)param_3 & 0xffff;
      if (local_1c < 0x41d) {
        if (local_1c == 0x41c) {
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 5;
          FUN_00444a85(&local_18,param_1,5);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
        }
        else if ((local_1c != 0) && (local_1c < 3)) {
          FUN_004449cf(DAT_00516ad4,DAT_00516a70,&DAT_005169b0,DAT_00516ad8,DAT_00516aac,
                       DAT_00516a74);
          if (local_1c == 1) {
            EndDialog(param_1,DAT_00516b18);
          }
          else {
            EndDialog(param_1,-2);
          }
        }
      }
      else {
        switch(local_1c) {
        case 0x41d:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 3;
          FUN_00444a85(&local_18,param_1,3);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41e:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 2;
          FUN_00444a85(&local_18,param_1,2);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41f:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 4;
          FUN_00444a85(&local_18,param_1,4);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x420:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 1;
          FUN_00444a85(&local_18,param_1,1);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x421:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = 0;
          FUN_00444a85(&local_18,param_1,0);
          InvalidateRect(param_1,&local_18,0);
          if ((uint)param_3 >> 0x10 == 5) {
            pHVar4 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x428:
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,1);
          DAT_00516b18 = GetWindowLongA(param_1,8);
          FUN_00444a85(&local_18,param_1,DAT_00516b18);
          InvalidateRect(param_1,&local_18,0);
          pHVar4 = GetDlgItem(param_1,1);
          SetFocus(pHVar4);
        }
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
    local_20 = (HWND)param_3;
    local_24 = param_4;
    pHVar4 = GetDlgItem(param_1,2);
    if (pHVar4 == local_20) {
      SendMessageA(param_1,0x401,2,0);
    }
    else {
      SendMessageA(param_1,0x401,1,0);
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


