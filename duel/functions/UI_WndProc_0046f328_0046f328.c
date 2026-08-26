/*
 * Decompiled function: UI_WndProc_0046f328
 * Entry Point: 0046f328
 * Size: 4272 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_WndProc_0046f328(HWND hwnd,uint uMsg,uint *wParam,LONG *lParam)

{
  short sVar1;
  LONG *pLVar2;
  LONG LVar3;
  uint *puVar4;
  HWND pHVar5;
  HWND pHVar6;
  int iVar7;
  HBRUSH pHVar8;
  uint uVar9;
  WPARAM WVar10;
  tagRECT *lpPoints;
  HDC wParam_00;
  UINT UVar11;
  LPARAM lParam_00;
  undefined1 local_174 [4];
  int local_170;
  int local_16c;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  tagRECT local_138;
  HDC local_128;
  undefined1 local_124 [4];
  int local_120;
  int local_11c;
  int local_10c;
  tagPAINTSTRUCT local_108;
  int local_c8;
  tagRECT local_c4;
  int local_b4;
  int local_b0;
  int local_ac;
  tagRECT local_a8;
  tagRECT local_98;
  tagRECT local_88;
  int local_78;
  int local_74;
  tagRECT local_70;
  int local_60;
  int local_5c;
  tagRECT local_58;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  uint *local_2c;
  LONG *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  int local_18;
  LONG local_14;
  uint *local_10;
  LONG *local_c;
  LONG *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_2c = (uint *)GetWindowLongA(hwnd,0);
      local_14 = GetWindowLongA(hwnd,0x20);
      local_18 = GetWindowLongA(hwnd,0xc);
      local_1c = (uint *)GetWindowLongA(hwnd,0x10);
      local_8 = (LONG *)GetWindowLongA(hwnd,0x14);
      local_10 = (uint *)GetWindowLongA(hwnd,0x18);
      local_28 = (LONG *)GetWindowLongA(hwnd,0x1c);
      local_20 = (uint *)GetWindowLongA(hwnd,0x24);
      local_24 = (uint *)GetWindowLongA(hwnd,4);
      local_c = (LONG *)GetWindowLongA(hwnd,8);
      local_128 = BeginPaint(hwnd,&local_108);
      if (local_128 != (HDC)0x0) {
        FUN_004707a4(local_128);
        GetClientRect(hwnd,&local_88);
        local_b0 = SaveDC(DAT_00522448);
        IntersectClipRect(DAT_00522448,0,0,local_88.right,local_88.bottom);
        GetWindowRect(hwnd,&local_98);
        UVar11 = 2;
        lpPoints = &local_98;
        pHVar6 = GetParent(hwnd);
        MapWindowPoints((HWND)0x0,pHVar6,(LPPOINT)lpPoints,UVar11);
        OffsetViewportOrgEx(DAT_00522448,-local_98.left,-local_98.top,(LPPOINT)0x0);
        lParam_00 = 0;
        UVar11 = 0x14;
        wParam_00 = DAT_00522448;
        pHVar6 = GetParent(hwnd);
        SendMessageA(pHVar6,UVar11,(WPARAM)wParam_00,lParam_00);
        OffsetViewportOrgEx(DAT_00522448,local_98.left,local_98.top,(LPPOINT)0x0);
        if (local_1c == (HANDLE)0x0) {
          pHVar8 = GetStockObject(2);
          FillRect(DAT_00522448,&local_88,pHVar8);
        }
        else {
          CopyRect(&local_138,&local_88);
          GetObjectA(local_1c,0x18,local_124);
          local_138.left = -((int)local_2c % local_120);
          local_10c = local_88.bottom;
          local_ac = local_138.left;
          if (local_8 == (LONG *)0x0) {
            local_c8 = ((local_120 / 2) * local_88.bottom) / local_11c;
            local_13c = local_120 / 2;
            local_140 = local_11c;
          }
          else {
            local_c8 = (local_120 * local_88.bottom) / (local_11c / 2);
            local_13c = local_120;
            local_140 = local_11c / 2;
          }
          for (; local_ac < local_138.right; local_ac = local_ac + local_13c) {
            for (local_b4 = local_138.top; local_b4 < local_138.bottom;
                local_b4 = local_b4 + local_140) {
              SetRect(&local_c4,local_ac,local_b4,local_ac + local_c8,local_b4 + local_10c);
              if (local_8 == (LONG *)0x0) {
                FUN_00470c78(DAT_00522448,&local_c4,local_1c);
              }
              else {
                FUN_00470cfa(DAT_00522448,&local_c4.left,local_1c,local_120,local_11c / 2,0,0,0,
                             local_11c / 2);
              }
            }
          }
        }
        if (local_20 != (uint *)0x0) {
          local_150 = local_14 % (int)local_28;
          iVar7 = FUN_00470437(hwnd,local_14);
          if ((uint *)iVar7 != local_2c) {
            local_14 = FUN_004704cd(hwnd,(int)local_2c);
            SetWindowLongA(hwnd,0x20,local_14);
          }
          if ((local_10 == (HANDLE)0x0) || (local_28 == (LONG *)0x0)) {
            SetRect(&local_a8,local_14 - local_88.right / 0x14,0,local_14 + local_88.right / 0x14,
                    local_88.bottom);
            pHVar8 = GetStockObject(4);
            FillRect(DAT_00522448,&local_a8,pHVar8);
          }
          else {
            GetObjectA(local_10,0x18,local_174);
            local_158 = local_170 / 2;
            local_15c = local_16c / (int)local_28;
            local_14c = 0;
            local_154 = local_150 * local_15c;
            local_148 = local_154;
            local_144 = local_158;
            FUN_00470560(hwnd,&local_a8);
            if (local_18 == 0) {
              SetMapMode(DAT_00522448,8);
              SetWindowExtEx(DAT_00522448,1,1,(LPSIZE)0x0);
              SetViewportExtEx(DAT_00522448,-1,1,(LPSIZE)0x0);
              SetWindowOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00522448,local_88.right,0,(LPPOINT)0x0);
              iVar7 = local_88.right - local_a8.left;
              local_a8.left = local_88.right - local_a8.right;
              local_a8.right = iVar7;
            }
            FUN_00470cfa(DAT_00522448,&local_a8.left,local_10,local_158,local_15c,local_14c,
                         local_148,local_144,local_154);
            if (local_18 == 0) {
              SetMapMode(DAT_00522448,1);
              SetWindowOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
            }
          }
        }
        RestoreDC(DAT_00522448,local_b0);
        BitBlt(local_128,0,0,local_88.right,local_88.bottom,DAT_00522448,0,0,0xcc0020);
        EndPaint(hwnd,&local_108);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_2c = (uint *)0x0;
      local_24 = (uint *)0x0;
      local_c = (LONG *)0x0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,(LONG)local_24);
      SetWindowLongA(hwnd,8,(LONG)local_c);
      local_18 = 1;
      SetWindowLongA(hwnd,0xc,1);
      local_1c = (uint *)0x0;
      local_8 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x10,0);
      SetWindowLongA(hwnd,0x14,(LONG)local_8);
      local_10 = (uint *)0x0;
      local_28 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      SetWindowLongA(hwnd,0x1c,(LONG)local_28);
      local_14 = 0;
      SetWindowLongA(hwnd,0x20,0);
      local_20 = (uint *)0x0;
      SetWindowLongA(hwnd,0x24,0);
      return 0;
    }
  }
  else if (uMsg < 0xe1) {
    if (uMsg == 0xe0) {
      puVar4 = (uint *)GetWindowLongA(hwnd,0);
      if (puVar4 != wParam) {
        local_2c = wParam;
        SetWindowLongA(hwnd,0,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else {
    sVar1 = (short)((uint)lParam >> 0x10);
    if (uMsg < 0x201) {
      if (uMsg == 0x200) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          local_18 = GetWindowLongA(hwnd,0xc);
          local_2c = (uint *)GetWindowLongA(hwnd,0);
          local_24 = (uint *)GetWindowLongA(hwnd,4);
          local_c = (LONG *)GetWindowLongA(hwnd,8);
          local_14 = GetWindowLongA(hwnd,0);
          local_44 = (int)(short)lParam;
          local_40 = (int)sVar1;
          GetClientRect(hwnd,&local_3c);
          if (local_44 < 0) {
            local_44 = 0;
          }
          if (local_3c.right < local_44) {
            local_44 = local_3c.right;
          }
          if (local_40 < 0) {
            local_40 = 0;
          }
          if (local_3c.bottom < local_40) {
            local_40 = local_3c.bottom;
          }
          if (DAT_00522450 < local_44) {
            if (local_18 == 0) {
              local_18 = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
          }
          else if ((local_44 < DAT_00522450) && (local_18 != 0)) {
            local_18 = 0;
            SetWindowLongA(hwnd,0xc,0);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          local_48 = local_44;
          if (local_44 < (int)local_24) {
            local_48 = (int)local_24;
          }
          else if ((int)local_c < local_44) {
            local_48 = (int)local_c;
          }
          if (local_48 != local_14) {
            local_14 = local_48;
            SetWindowLongA(hwnd,0x20,local_48);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          iVar7 = FUN_00470437(hwnd,local_44);
          if ((uint *)iVar7 != local_2c) {
            pHVar6 = hwnd;
            iVar7 = FUN_00470437(hwnd,local_44);
            WVar10 = CONCAT31((int3)((uint)(iVar7 << 0x10) >> 8),5);
            UVar11 = 0x114;
            pHVar5 = GetParent(hwnd);
            SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
          }
          UpdateWindow(hwnd);
          DAT_00522450 = local_44;
          _DAT_00522454 = local_40;
        }
        return 0;
      }
      if (uMsg == 0xe1) {
        uVar9 = GetWindowLongA(hwnd,0);
        return uVar9;
      }
      if (uMsg == 0xe2) {
        local_24 = (uint *)GetWindowLongA(hwnd,4);
        pLVar2 = (LONG *)GetWindowLongA(hwnd,8);
        if ((local_24 != wParam) || (pLVar2 != lParam)) {
          local_24 = wParam;
          local_c = lParam;
          SetWindowLongA(hwnd,4,(LONG)wParam);
          SetWindowLongA(hwnd,8,(LONG)local_c);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
      if (uMsg == 0xe3) {
        local_24 = (uint *)GetWindowLongA(hwnd,4);
        LVar3 = GetWindowLongA(hwnd,8);
        if (wParam != (uint *)0x0) {
          *wParam = (uint)local_24;
        }
        if (lParam != (LONG *)0x0) {
          *lParam = LVar3;
        }
        return LVar3 << 0x10 | (uint)local_24 & 0xffff;
      }
    }
    else if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        uVar9 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
        return uVar9;
      }
      if (uMsg == 0x201) {
        UpdateWindow(hwnd);
        local_14 = GetWindowLongA(hwnd,0x20);
        local_18 = GetWindowLongA(hwnd,0xc);
        local_20 = (uint *)GetWindowLongA(hwnd,0x24);
        local_60 = (int)(short)lParam;
        local_5c = (int)sVar1;
        if (local_20 == (uint *)0x0) {
          return 0;
        }
        FUN_00470560(hwnd,&local_58);
        if ((local_60 < local_58.left) || (local_58.right < local_60)) {
          if (local_58.right < local_60) {
            if (local_18 == 0) {
              local_18 = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 1;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
          else if (local_60 < local_58.left) {
            if (local_18 != 0) {
              local_18 = 0;
              SetWindowLongA(hwnd,0xc,0);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 0;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
        }
        else {
          SetCapture(hwnd);
        }
        DAT_00522450 = local_60;
        _DAT_00522454 = local_5c;
        return 0;
      }
      if (uMsg == 0x202) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          ReleaseCapture();
          local_14 = GetWindowLongA(hwnd,0x20);
          local_78 = (int)(short)lParam;
          local_74 = (int)sVar1;
          GetClientRect(hwnd,&local_70);
          if (local_78 < 0) {
            local_78 = 0;
          }
          if (local_70.right < local_78) {
            local_78 = local_70.right;
          }
          if (local_74 < 0) {
            local_74 = 0;
          }
          if (local_70.bottom < local_74) {
            local_74 = local_70.bottom;
          }
          local_14 = local_78;
          SetWindowLongA(hwnd,0x20,local_78);
          InvalidateRect(hwnd,(RECT *)0x0,1);
          pHVar6 = hwnd;
          iVar7 = FUN_00470437(hwnd,local_78);
          WVar10 = CONCAT31((int3)((uint)(iVar7 << 0x10) >> 8),4);
          UVar11 = 0x114;
          pHVar5 = GetParent(hwnd);
          SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
        }
        return 0;
      }
    }
    else {
      switch(uMsg) {
      case 0x432:
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      case 0x464:
        puVar4 = (uint *)GetWindowLongA(hwnd,0x10);
        if (puVar4 != wParam) {
          local_1c = wParam;
          local_8 = lParam;
          SetWindowLongA(hwnd,0x10,(LONG)wParam);
          SetWindowLongA(hwnd,0x14,(LONG)local_8);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x465:
        uVar9 = GetWindowLongA(hwnd,0x10);
        if (wParam == (uint *)0x0) {
          return uVar9;
        }
        *wParam = uVar9;
        return uVar9;
      case 0x466:
        local_10 = (uint *)GetWindowLongA(hwnd,0x18);
        GetWindowLongA(hwnd,0x1c);
        if (wParam != local_10) {
          local_10 = wParam;
          local_28 = lParam;
          SetWindowLongA(hwnd,0x18,(LONG)wParam);
          SetWindowLongA(hwnd,0x1c,(LONG)local_28);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x467:
        local_10 = (uint *)GetWindowLongA(hwnd,0x18);
        LVar3 = GetWindowLongA(hwnd,0x1c);
        if (wParam != (uint *)0x0) {
          *wParam = (uint)local_10;
        }
        if (lParam == (LONG *)0x0) {
          return (uint)local_10;
        }
        *lParam = LVar3;
        return (uint)local_10;
      case 0x468:
        puVar4 = (uint *)GetWindowLongA(hwnd,0x24);
        if (wParam != puVar4) {
          local_20 = wParam;
          SetWindowLongA(hwnd,0x24,(LONG)wParam);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
    }
  }
  uVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return uVar9;
}


