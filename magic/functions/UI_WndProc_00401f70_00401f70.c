/*
 * Decompiled function: UI_WndProc_00401f70
 * Entry Point: 00401f70
 * Size: 4340 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_00401f70(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam)

{
  bool bVar1;
  char *pcVar2;
  SHORT SVar3;
  HWND pHVar4;
  LONG LVar5;
  HWND pHVar6;
  int iVar7;
  int iVar8;
  HBRUSH hbr;
  WPARAM WVar9;
  size_t sVar10;
  uint uVar11;
  LRESULT LVar12;
  UINT UVar13;
  tagRECT *ptVar14;
  LPARAM lParam_00;
  tagSIZE *lpsz;
  uint local_394;
  int local_38c;
  LONG *local_384;
  tagRECT local_380;
  tagSIZE local_370;
  COLORREF local_368;
  HDC local_364;
  int local_360;
  tagPAINTSTRUCT local_35c;
  int local_31c;
  int local_318;
  COLORREF local_314;
  COLORREF local_310;
  COLORREF local_30c;
  COLORREF local_308;
  CHAR local_304 [500];
  tagTEXTMETRICA local_110;
  COLORREF local_d8;
  tagRECT local_d4;
  COLORREF local_c4;
  char *local_c0;
  int local_bc;
  tagRECT local_b8;
  int local_a8;
  tagRECT local_a4;
  uint local_94;
  uint local_90;
  HDC local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  tagTEXTMETRICA local_78;
  tagRECT local_40;
  tagRECT local_30;
  int local_20;
  int local_1c;
  int local_18;
  LONG local_14;
  WPARAM local_10;
  HGDIOBJ local_c;
  char *local_8;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      local_384 = lParam;
      local_38c = 0;
      bVar1 = false;
      while (((char)*local_384 != '\0' && (!bVar1))) {
        if (((char)*local_384 == ' ') || ((char)*local_384 == '>')) {
          (&DAT_00536da8)[local_38c] = 0;
          bVar1 = true;
        }
        else {
          for (; ((char)*local_384 != '\0' && ((char)*local_384 != '\n'));
              local_384 = (LONG *)((int)local_384 + 1)) {
            (&DAT_00536da8)[local_38c] = (char)*local_384;
            local_38c = local_38c + 1;
          }
          if ((char)*local_384 != '\0') {
            (&DAT_00536da8)[local_38c] = (char)*local_384;
            local_384 = (LONG *)((int)local_384 + 1);
            local_38c = local_38c + 1;
          }
        }
      }
      (&DAT_00536da8)[local_38c] = 0;
      while (sVar10 = strlen(&DAT_00536da8), (&DAT_00536da6)[sVar10] == '\n') {
        sVar10 = strlen(&DAT_00536da8);
        (&DAT_00536da6)[sVar10] = 0;
      }
      LVar12 = DefWindowProcA(hwnd,0xc,wParam,0x536da8);
      local_8 = (char *)GetWindowLongA(hwnd,4);
      local_18 = 0;
      local_14 = -1;
      if ((char)*local_384 != '\0') {
        local_38c = 0;
        while ((char)*local_384 != '\0') {
          for (; (char)*local_384 == ' '; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          if ((char)*local_384 == '>') {
            local_14 = local_18;
            local_384 = (LONG *)((int)local_384 + 1);
          }
          for (; (char)*local_384 == '\n'; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          for (; ((char)*local_384 != '\0' && ((char)*local_384 != '\n'));
              local_384 = (LONG *)((int)local_384 + 1)) {
            *(char *)(local_38c + (int)local_8) = (char)*local_384;
            local_38c = local_38c + 1;
          }
          *(undefined1 *)(local_38c + (int)local_8) = 0;
          local_38c = local_38c + 1;
          if ((char)*local_384 != '\0') {
            local_384 = (LONG *)((int)local_384 + 1);
          }
          local_18 = local_18 + 1;
        }
        *(undefined1 *)(local_38c + (int)local_8) = 0;
      }
      if ((local_18 != 0) && (local_14 == -1)) {
        local_14 = 0;
      }
      local_394 = 0;
      for (local_38c = 0; local_38c < local_18; local_38c = local_38c + 1) {
        uVar11 = FUN_00403189(hwnd,local_38c);
        local_394 = local_394 | uVar11;
      }
      if (local_394 == 0) {
        local_10 = 0;
        SetWindowLongA(hwnd,0x10,0);
      }
      SetWindowLongA(hwnd,8,local_18);
      SetWindowLongA(hwnd,4,(LONG)local_8);
      SetWindowLongA(hwnd,0xc,local_14);
      return LVar12;
    }
    if (uMsg == 1) {
      local_c = (HGDIOBJ)0x0;
      SetWindowLongA(hwnd,0,0);
      local_8 = malloc(1000);
      local_18 = 0;
      local_14 = -1;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)local_8);
      SetWindowLongA(hwnd,0xc,local_14);
      local_10 = *lParam;
      SetWindowLongA(hwnd,0x10,local_10);
      local_1c = lParam[9];
      if (local_1c != 0) {
        PostMessageA(hwnd,0xc,0,local_1c);
      }
      return 0;
    }
    if (uMsg == 2) {
      local_8 = (char *)GetWindowLongA(hwnd,4);
      if (local_8 != (void *)0x0) {
        free(local_8);
      }
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      return 1;
    }
    if (uMsg == 0xf) {
      local_c = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_18 = GetWindowLongA(hwnd,8);
      local_8 = (char *)GetWindowLongA(hwnd,4);
      local_14 = GetWindowLongA(hwnd,0xc);
      local_10 = GetWindowLongA(hwnd,0x10);
      GetWindowTextA(hwnd,local_304,500);
      local_c0 = local_8;
      local_314 = 0x1000097;
      local_310 = 0x1000097;
      local_30c = 0x1000097;
      local_d8 = 0x10000c3;
      local_308 = 0x10000bf;
      local_c4 = 0x10000c9;
      local_364 = BeginPaint(hwnd,&local_35c);
      if (local_364 != (HDC)0x0) {
        FUN_004f3955(local_364);
        GetClientRect(hwnd,&local_d4);
        SetBkMode(local_364,1);
        SelectObject(local_364,local_c);
        SetTextColor(local_364,local_c4);
        OffsetRect(&local_d4,1,1);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        OffsetRect(&local_d4,-1,-1);
        SetTextColor(local_364,local_314);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        local_bc = DrawTextA(local_364,local_304,-1,&local_d4,0x410);
        if (local_18 != 0) {
          local_31c = local_d4.top + local_bc + 0x14;
          GetTextMetricsA(local_364,&local_110);
          local_360 = local_110.tmExternalLeading + (local_110.tmHeight * 10) / 100 +
                      local_110.tmHeight;
          SetBkMode(local_364,1);
          for (local_318 = 0; local_318 < local_18; local_318 = local_318 + 1) {
            iVar8 = FUN_00403189(hwnd,local_318);
            pcVar2 = local_c0;
            if ((iVar8 == 0) && (pcVar2 = local_c0 + 1, local_c0[1] == ' ')) {
              pcVar2 = local_c0 + 2;
            }
            local_c0 = pcVar2;
            if (local_10 == 0) {
              if (local_318 == local_14) {
                lpsz = &local_370;
                sVar10 = strlen(local_c0);
                GetTextExtentPointA(local_364,local_c0,sVar10,lpsz);
                SetRect(&local_380,local_d4.left + -5,local_31c,local_d4.left + local_370.cx + 5,
                        local_31c + local_360);
                hbr = GetStockObject(0);
                FillRect(local_364,&local_380,hbr);
              }
              iVar8 = FUN_00403189(hwnd,local_318);
              if (iVar8 == 0) {
                local_368 = local_d8;
              }
              else {
                local_368 = local_30c;
              }
            }
            else {
              iVar8 = FUN_00403189(hwnd,local_318);
              if (iVar8 == 0) {
                local_368 = local_d8;
              }
              else if (local_318 == local_14) {
                local_368 = local_308;
              }
              else {
                local_368 = local_310;
              }
            }
            SetTextColor(local_364,local_c4);
            sVar10 = strlen(local_c0);
            TextOutA(local_364,local_d4.left + 1,local_31c + 1,local_c0,sVar10);
            SetTextColor(local_364,local_368);
            sVar10 = strlen(local_c0);
            TextOutA(local_364,local_d4.left,local_31c,local_c0,sVar10);
            local_31c = local_31c + local_360;
            sVar10 = strlen(local_c0);
            local_c0 = local_c0 + sVar10 + 1;
          }
        }
        if (local_18 != 0) {
          GetClientRect(hwnd,&local_d4);
          local_d4.bottom = local_31c;
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_d4.right - local_d4.left,local_31c - local_d4.top,6)
          ;
        }
        EndPaint(hwnd,&local_35c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x88) {
    if (uMsg == 0x87) {
      return 4;
    }
    if (uMsg == 0x30) {
      WVar9 = GetWindowLongA(hwnd,0);
      if (WVar9 != wParam) {
        local_c = (HGDIOBJ)wParam;
        SetWindowLongA(hwnd,0,wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x31) {
      LVar5 = GetWindowLongA(hwnd,0);
      return LVar5;
    }
  }
  else if (uMsg < 0x203) {
    if (0x1ff < uMsg) {
      local_18 = GetWindowLongA(hwnd,8);
      local_c = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_14 = GetWindowLongA(hwnd,0xc);
      local_10 = GetWindowLongA(hwnd,0x10);
      if (uMsg == 0x201) {
        ptVar14 = &local_b8;
        pHVar6 = GetParent(hwnd);
        GetWindowRect(pHVar6,ptVar14);
        lParam_00 = 0;
        WVar9 = 0xf012;
        UVar13 = 0x112;
        pHVar6 = GetParent(hwnd);
        SendMessageA(pHVar6,UVar13,WVar9,lParam_00);
        uMsg = 0x202;
        ptVar14 = &local_40;
        pHVar6 = GetParent(hwnd);
        GetWindowRect(pHVar6,ptVar14);
        iVar8 = abs(local_b8.left - local_40.left);
        iVar7 = abs(local_b8.top - local_40.top);
        local_7c = (uint)(4 < iVar8 + iVar7);
      }
      else {
        local_7c = 0;
      }
      if (local_7c == 0) {
        local_88 = local_14 + 1;
        if (local_10 == 0) {
          if (uMsg == 0x202) {
            pHVar6 = hwnd;
            uVar11 = GetDlgCtrlID(hwnd);
            uVar11 = uVar11 & 0xffff | local_88 << 0x10;
            UVar13 = 0x111;
            pHVar4 = GetParent(hwnd);
            SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
          }
        }
        else if (local_18 < 1) {
          if (uMsg == 0x202) {
            pHVar6 = hwnd;
            uVar11 = GetDlgCtrlID(hwnd);
            uVar11 = uVar11 & 0xffff;
            UVar13 = 0x111;
            pHVar4 = GetParent(hwnd);
            SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
          }
        }
        else {
          local_94 = (uint)lParam & 0xffff;
          local_90 = (uint)lParam >> 0x10;
          local_8c = GetDC(hwnd);
          FUN_004f3955(local_8c);
          SelectObject(local_8c,local_c);
          GetTextMetricsA(local_8c,&local_78);
          local_a8 = local_78.tmExternalLeading + local_78.tmHeight;
          ReleaseDC(hwnd,local_8c);
          local_88 = 0;
          GetClientRect(hwnd,&local_30);
          local_80 = local_30.bottom - local_a8;
          local_84 = local_18;
          while ((0 < local_84 && (local_88 == 0))) {
            if (local_80 < (int)local_90) {
              local_88 = local_84;
              SetRect(&local_a4,0,local_80,local_30.right,local_80 + local_a8);
            }
            local_80 = local_80 - local_a8;
            local_84 = local_84 + -1;
          }
          iVar8 = FUN_00403189(hwnd,local_88 + -1);
          if (iVar8 != 0) {
            local_14 = local_88 + -1;
            SetWindowLongA(hwnd,0xc,local_14);
            InvalidateRect(hwnd,(RECT *)0x0,0);
            UpdateWindow(hwnd);
            if (uMsg == 0x202) {
              Sleep(0x2ee);
              pHVar6 = hwnd;
              uVar11 = GetDlgCtrlID(hwnd);
              uVar11 = uVar11 & 0xffff | local_88 << 0x10;
              UVar13 = 0x111;
              pHVar4 = GetParent(hwnd);
              SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
            }
          }
        }
      }
      return 0;
    }
    if (uMsg == 0x100) {
      local_18 = GetWindowLongA(hwnd,8);
      local_14 = GetWindowLongA(hwnd,0xc);
      local_10 = GetWindowLongA(hwnd,0x10);
      if (local_10 != 0) {
        if ((wParam == 0xd) || (wParam == 0x20)) {
          local_20 = local_14 + 1;
          pHVar6 = hwnd;
          uVar11 = GetDlgCtrlID(hwnd);
          uVar11 = uVar11 & 0xffff | local_20 << 0x10;
          UVar13 = 0x111;
          pHVar4 = GetParent(hwnd);
          SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
        }
        else {
          if (wParam == 9) {
            SVar3 = GetKeyState(0x10);
            if (((int)SVar3 & 0x8000U) == 0) {
              wParam = 0x28;
            }
            else {
              wParam = 0x26;
            }
          }
          switch(wParam) {
          case 0x23:
            local_14 = local_18;
            do {
              local_14 = local_14 + -1;
              iVar8 = FUN_00403189(hwnd,local_14);
            } while (iVar8 == 0);
            break;
          case 0x24:
            local_14 = 0;
            while (iVar8 = FUN_00403189(hwnd,local_14), iVar8 == 0) {
              local_14 = local_14 + 1;
            }
            break;
          case 0x26:
            local_14 = local_14 + -1;
            if (local_14 < 0) {
              local_14 = local_18 + -1;
            }
            while (iVar8 = FUN_00403189(hwnd,local_14), iVar8 == 0) {
              local_14 = local_14 + -1;
              if (local_14 < 0) {
                local_14 = local_18 + -1;
              }
            }
            break;
          case 0x28:
            local_14 = local_14 + 1;
            if (local_18 + -1 < local_14) {
              local_14 = 0;
            }
            while (iVar8 = FUN_00403189(hwnd,local_14), iVar8 == 0) {
              local_14 = local_14 + 1;
              if (local_18 + -1 < local_14) {
                local_14 = 0;
              }
            }
          }
          SetWindowLongA(hwnd,0xc,local_14);
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
      }
      return 0;
    }
    if (uMsg == 0x102) {
      pHVar6 = hwnd;
      uVar11 = GetDlgCtrlID(hwnd);
      uVar11 = uVar11 & 0xffff;
      UVar13 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar12 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar12;
    case 0x400:
      LVar5 = GetWindowLongA(hwnd,8);
      return LVar5;
    case 0x401:
      local_10 = wParam;
      SetWindowLongA(hwnd,0x10,wParam);
      return 0;
    }
  }
  LVar12 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar12;
}


