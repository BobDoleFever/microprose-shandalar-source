/*
 * Decompiled function: FUN_1003514e
 * Entry Point: 1003514e
 * Size: 8345 bytes
 */
#include "deckdll.h"


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t FUN_1003514e(HWND hwnd,uint32_t y,uint32_t width,uint32_t height)

{
  POINT pt;
  POINT pt_00;
  int *i_ptr_1;
  uint16_t uval_2;
  WORD WVar3;
  WORD WVar4;
  LONG LVar5;
  WPARAM WVar6;
  HWND pHVar7;
  int val_8;
  HRGN hrgn;
  HGDIOBJ h;
  size_t sVar9;
  BOOL BVar10;
  uint32_t uVar11;
  UINT UVar12;
  int iVar13;
  char *pcVar14;
  uint8_t uVar15;
  uint8_t uVar16;
  int16_t uVar17;
  tagRECT local_220;
  int local_210;
  HDC local_20c;
  uint8_t local_208 [4];
  int local_204;
  int local_200;
  tagPAINTSTRUCT local_1f0;
  uint32_t local_1b0;
  int local_1ac;
  tagRECT local_1a8;
  int local_198;
  uint32_t local_194;
  uint32_t local_190;
  uint32_t local_18c;
  uint32_t local_188;
  tagRECT local_184;
  int local_174;
  uint32_t local_170;
  uint32_t local_16c;
  uint32_t local_168;
  WORD local_164;
  int16_t uStack_162;
  uint32_t local_160;
  uint32_t local_15c;
  uint32_t local_158;
  HDC local_154;
  tagRECT local_150;
  WPARAM local_140;
  int32_t local_13c;
  int local_138;
  uint32_t local_134;
  HWND local_130;
  int32_t local_12c;
  uint32_t local_128;
  uint32_t local_124;
  tagRECT local_120;
  int local_110;
  int local_10c [3];
  int local_100;
  HWND local_fc;
  int32_t local_f8;
  int local_f4;
  uint32_t local_ec;
  uint32_t local_e8;
  tagRECT local_e4;
  uint32_t local_d4;
  tagRECT local_d0;
  uint32_t local_c0;
  tagRECT local_bc;
  uint32_t local_ac;
  tagRECT local_a8;
  uint32_t local_98;
  uint32_t local_94;
  tagRECT local_90;
  int32_t local_80;
  void *local_7c;
  tagMSG local_78;
  uint32_t local_5c;
  WPARAM local_58;
  tagPOINT local_54;
  UINT local_4c;
  uint32_t local_48;
  int local_44;
  char local_40 [32];
  uint32_t local_20;
  int32_t local_1c;
  tagRECT local_18;
  int32_t local_8;
  
  uVar15 = SUB41(hwnd,0);
  uVar16 = (uint8_t)((uint32_t)hwnd >> 8);
  uVar17 = (int16_t)((uint32_t)hwnd >> 0x10);
  if (y < 0x10) {
    if (y == 0xf) {
      WVar4 = GetWindowWord(hwnd,0);
      local_8 = CONCAT22(local_8._2_2_,WVar4);
      local_7c = (void *)GetWindowLongA(hwnd,2);
      WVar4 = GetWindowWord(hwnd,6);
      local_20 = CONCAT22(local_20._2_2_,WVar4);
      WVar4 = GetWindowWord(hwnd,8);
      local_1c = CONCAT22(local_1c._2_2_,WVar4);
      WVar4 = GetWindowWord(hwnd,10);
      local_48 = CONCAT22(local_48._2_2_,WVar4);
      WVar4 = GetWindowWord(hwnd,0xc);
      local_80 = CONCAT22(local_80._2_2_,WVar4);
      local_20c = BeginPaint(hwnd,&local_1f0);
      thunk_FUN_10031425(local_20c);
      hrgn = CreateRectRgn(0,0,DAT_10176468,DAT_1016e4b0);
      GetClientRect(hwnd,&local_1a8);
      GetObjectA(DAT_10162908,0x18,local_208);
      h = SelectObject(DAT_1013f18c,DAT_10162908);
      StretchBlt(local_20c,0,0,local_1a8.right,local_1a8.bottom,DAT_1013f18c,0,0,local_204,local_200
                 ,0xcc0020);
      SelectObject(DAT_1013f18c,h);
      local_1b0 = local_1c & 0xffff;
      while( true ) {
        uVar11 = (local_80 & 0xffff) + (local_1c & 0xffff);
        if ((local_8 & 0xffff) <= uVar11) {
          uVar11 = local_8 & 0xffff;
        }
        if ((int)uVar11 <= (int)local_1b0) break;
        thunk_FUN_100372c5(hwnd,local_1b0,&local_1a8);
        local_198 = *(int *)((int)local_7c + local_1b0 * 4);
        SetRect(&local_220,0,0,DAT_10176468,DAT_1016e4b0);
        SetRectRgn(hrgn,local_220.left,local_220.top,local_220.right,local_220.bottom);
        SelectClipRgn(DAT_101625e8,hrgn);
        local_210 = thunk_FUN_1003724f(local_198);
        thunk_FUN_1001df0d(DAT_101625e8,&local_220,(WPARAM *)(&DAT_10176ab0 + local_198 * 0x98),1,1)
        ;
        if (((DAT_1017646c & 1) != 0) && (1 < local_210)) {
          sprintf(local_40,&DAT_1004ba90,(char)local_210);
          local_1ac = SaveDC(DAT_101625e8);
          SetMapMode(DAT_101625e8,8);
          SetWindowExtEx(DAT_101625e8,200,0x118,(LPSIZE)0x0);
          SetViewportExtEx(DAT_101625e8,local_220.right - local_220.left,
                           local_220.bottom - local_220.top,(LPSIZE)0x0);
          SetViewportOrgEx(DAT_101625e8,local_220.left,local_220.top,(LPPOINT)0x0);
          SetBkMode(DAT_101625e8,1);
          SelectObject(DAT_101625e8,DAT_1013ec4c);
          SetTextAlign(DAT_101625e8,0);
          SetTextColor(DAT_101625e8,0x10000c9);
          sVar9 = strlen(local_40);
          uVar15 = (uint8_t)sVar9;
          uVar16 = (uint8_t)(sVar9 >> 8);
          uVar17 = (int16_t)(sVar9 >> 0x10);
          pcVar14 = local_40;
          iVar13 = 3;
          sVar9 = strlen(local_40);
          TextOutA(DAT_101625e8,sVar9 * -0x10 + 0xcb,iVar13,pcVar14,
                   CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
          SetTextColor(DAT_101625e8,0x2fefefe);
          SetBkMode(DAT_101625e8,1);
          sVar9 = strlen(local_40);
          uVar15 = (uint8_t)sVar9;
          uVar16 = (uint8_t)(sVar9 >> 8);
          uVar17 = (int16_t)(sVar9 >> 0x10);
          pcVar14 = local_40;
          iVar13 = 0;
          sVar9 = strlen(local_40);
          TextOutA(DAT_101625e8,sVar9 * -0x10 + 200,iVar13,pcVar14,
                   CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
          RestoreDC(DAT_101625e8,local_1ac);
        }
        SelectClipRgn(DAT_101625e8,(HRGN)0x0);
        local_1a8.left =
             local_1a8.left + (int)((local_1a8.right - local_1a8.left) - DAT_10176468) / 2;
        local_1a8.top = local_1a8.top + ((local_1a8.bottom - local_1a8.top) - DAT_1016e4b0) / 2;
        BitBlt(local_20c,local_1a8.left,local_1a8.top,DAT_10176468,DAT_1016e4b0,DAT_101625e8,0,0,
               0xcc0020);
        local_1b0 = local_1b0 + 1;
      }
      EndPaint(hwnd,&local_1f0);
      DeleteObject(hrgn);
      return 0;
    }
    if (y == 1) {
      GetClientRect(hwnd,&local_150);
      local_7c = malloc(4);
      local_8 = (uint32_t)local_8._2_2_ << 0x10;
      local_20 = CONCAT22(local_20._2_2_,0xffff);
      local_1c = (uint32_t)local_1c._2_2_ << 0x10;
      local_48 = CONCAT22(local_48._2_2_,(short)DAT_10176468);
      if ((short)DAT_10176468 == 0) {
        local_80 = (uint32_t)local_80._2_2_ << 0x10;
      }
      else {
        local_80 = CONCAT22(local_80._2_2_,
                            (short)((local_150.right + -4) / (int)(DAT_10176468 & 0xffff)));
      }
      SetWindowWord(hwnd,0,0);
      SetWindowLongA(hwnd,2,(LONG)local_7c);
      SetWindowWord(hwnd,6,(WORD)local_20);
      SetWindowWord(hwnd,8,(WORD)local_1c);
      SetWindowWord(hwnd,10,(WORD)local_48);
      SetWindowWord(hwnd,0xc,(WORD)local_80);
      SetScrollRange(hwnd,0,0,((local_8 & 0xffff) - (local_80 & 0xffff)) + 1,0);
      SetScrollPos(hwnd,0,local_20 & 0xffff,1);
      DAT_1013ec08 = CreatePopupMenu();
      local_154 = GetDC(hwnd);
      thunk_FUN_10031425(local_154);
      DAT_1013f18c = CreateCompatibleDC(local_154);
      thunk_FUN_10031425(DAT_1013f18c);
      ReleaseDC(hwnd,local_154);
      if (DAT_1013ec4c == (HFONT)0x0) {
        memcpy(&DAT_1013ec10,&DAT_1004ba18,0x3c);
        _DAT_1013ec10 = 0x2a;
        _DAT_1013ec20 = 500;
        strcpy(&DAT_1013ec2c,s_Kudos_Condensed_SSi_1004ba7c);
        DAT_1013ec4c = CreateFontIndirectA((LOGFONTA *)&DAT_1013ec10);
      }
      return 0;
    }
    if (y == 2) {
      local_7c = (void *)GetWindowLongA(hwnd,2);
      free(local_7c);
      DestroyMenu(DAT_1013ec08);
      DeleteDC(DAT_1013f18c);
      if (DAT_1013ec4c != (HFONT)0x0) {
        DeleteObject(DAT_1013ec4c);
      }
      DAT_1013ec4c = (HFONT)0x0;
      return 0;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uVar11 = width & 0xffff;
      if (uVar11 == 1) {
        uval_2 = thunk_FUN_1003724f(DAT_1013ec50);
        local_5c = CONCAT22(local_5c._2_2_,uval_2);
        DAT_101cfb9c = 1;
        DAT_10175ecc = 1;
        if ((1 < uval_2) && (iVar13 = thunk_FUN_1000ac70(), iVar13 == 0)) {
          return 0;
        }
        if (DAT_10175ecc == 0) {
          return 0;
        }
        if ((int)(local_5c & 0xffff) < (int)DAT_10175ecc) {
          DAT_10175ecc = local_5c & 0xffff;
        }
        for (local_4c = 0; (int)local_4c < (int)DAT_10175ecc; local_4c = local_4c + 1) {
          iVar13 = thunk_FUN_1000d64e(DAT_1013ec50,1);
          if (iVar13 == 0) {
            return 0;
          }
        }
        *DAT_101cfb7c = *DAT_101cfb7c + DAT_10175ecc * DAT_1004ba54;
        sprintf(local_40,s_GOLD___d_1004ba70,(char)*DAT_101cfb7c);
        strncpy(&DAT_10162630,local_40,0xc);
        InvalidateRect(DAT_10176a9c,(RECT *)0x0,1);
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
        InvalidateRect(DAT_101cfb80,(RECT *)0x0,0);
      }
      else if (uVar11 == 2) {
        DAT_101cfb9c = thunk_FUN_10039c49(1);
        thunk_FUN_1000bb7d();
        thunk_FUN_10039fb5(1,(uint8_t)DAT_10175ecc);
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
        InvalidateRect(DAT_101cfb80,(RECT *)0x0,1);
        SendMessageA(DAT_101cf33c,0x401,0,0);
        InvalidateRect(DAT_101cf33c,(RECT *)0x0,1);
      }
      else if (uVar11 == 3) {
        DAT_101cfb9c = thunk_FUN_10039c49(0);
        thunk_FUN_1000bb7d();
        thunk_FUN_10039fb5(0,(uint8_t)DAT_10175ecc);
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
        InvalidateRect(DAT_101cfb80,(RECT *)0x0,1);
        SendMessageA(DAT_101cf33c,0x401,0,0);
        InvalidateRect(DAT_101cf33c,(RECT *)0x0,1);
      }
      return 0;
    }
    if (y == 0x100) {
      if ((width == 0x26) || (width == 0x25)) {
        SendMessageA(hwnd,0x114,0,0);
      }
      else if ((width == 0x28) || (width == 0x27)) {
        SendMessageA(hwnd,0x114,1,0);
      }
      else if (width == 0x21) {
        SendMessageA(hwnd,0x114,2,0);
      }
      else if (width == 0x22) {
        SendMessageA(hwnd,0x114,3,0);
      }
      else if (width == 0x24) {
        SendMessageA(hwnd,0x114,6,0);
      }
      else if (width == 0x23) {
        SendMessageA(hwnd,0x114,7,0);
      }
      return 0;
    }
    if (y == 0x102) {
      if (width == 0x1b) {
        SendMessageA(DAT_10176868,0x10,0,0);
        return 0;
      }
      SendMessageA(DAT_101cf538,0x102,width,height);
      local_140 = SendMessageA(DAT_101cf538,0x188,0,0);
      SendMessageA(hwnd,0x114,CONCAT31((int3)((local_140 << 0x10) >> 8),4),0);
      SendMessageA(hwnd,0x186,local_140,0);
      uVar11 = GetDlgCtrlID(hwnd);
      uVar11 = uVar11 & 0xffff | 0x10000;
      UVar12 = 0x111;
      pHVar7 = GetParent(hwnd);
      SendMessageA(pHVar7,UVar12,uVar11,CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
      return 0;
    }
  }
  else {
    WVar4 = (WORD)width;
    if (y < 0x181) {
      if (y == 0x180) {
        local_8._0_2_ = GetWindowWord(hwnd,0);
        local_7c = (void *)GetWindowLongA(hwnd,2);
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,0xc);
        local_80 = CONCAT22(local_80._2_2_,WVar4);
        local_d4 = local_8 & 0xffff;
        local_7c = realloc(local_7c,(local_8 & 0xffff) * 4 + 4);
        if (local_7c != (void *)0x0) {
          *(uint32_t *)((int)local_7c + (local_8 & 0xffff) * 4) = height;
          WVar4 = (WORD)local_8 + 1;
          local_8 = CONCAT22(local_8._2_2_,WVar4);
          SetWindowWord(hwnd,0,WVar4);
          SetWindowLongA(hwnd,2,(LONG)local_7c);
          SetScrollRange(hwnd,0,0,((local_8 & 0xffff) - (local_80 & 0xffff)) + 1,0);
          thunk_FUN_100372c5(hwnd,local_d4,&local_d0);
          InvalidateRect(hwnd,&local_d0,1);
          return local_d4;
        }
        return 0xfffffffe;
      }
      if (y == 0x114) {
        WVar3 = GetWindowWord(hwnd,10);
        local_48 = CONCAT22(local_48._2_2_,WVar3);
        WVar3 = GetWindowWord(hwnd,0xc);
        local_80 = CONCAT22(local_80._2_2_,WVar3);
        local_170 = GetScrollPos(hwnd,0);
        GetScrollRange(hwnd,0,(LPINT)&local_16c,(LPINT)&local_160);
        local_168 = local_80 & 0xffff;
        WVar3 = GetWindowWord(hwnd,0);
        local_15c = (uint32_t)WVar3;
        _local_164 = CONCAT22(uStack_162,WVar4);
        if ((width & 0xffff) == 6) {
          local_158 = local_16c;
        }
        else if (WVar4 == 0) {
          local_158 = local_170 - 1;
        }
        else if ((width & 0xffff) == 2) {
          local_158 = local_170 - local_168;
        }
        else if ((width & 0xffff) == 4) {
          local_158 = width >> 0x10;
        }
        else if ((width & 0xffff) == 3) {
          local_158 = local_168 + local_170;
        }
        else if ((width & 0xffff) == 1) {
          local_158 = local_170 + 1;
        }
        else if ((width & 0xffff) == 7) {
          local_158 = local_160;
        }
        else {
          local_158 = local_170;
        }
        if ((int)local_158 < (int)local_16c) {
          local_158 = local_16c;
        }
        if ((int)local_160 < (int)local_158) {
          local_158 = local_160;
        }
        if (local_158 != local_170) {
          local_1c = CONCAT22(local_1c._2_2_,(WORD)local_158);
          SetWindowWord(hwnd,8,(WORD)local_158);
          UpdateWindow(hwnd);
          ScrollWindow(hwnd,(local_170 - local_158) * (local_48 & 0xffff),0,(RECT *)0x0,(RECT *)0x0)
          ;
          SetScrollPos(hwnd,0,local_158,1);
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
        return 0;
      }
    }
    else if (y < 399) {
      if (y == 0x18e) {
        WVar4 = GetWindowWord(hwnd,8);
        local_1c = (uint32_t)WVar4;
        return local_1c;
      }
      switch(y) {
      case 0x181:
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        local_7c = (void *)GetWindowLongA(hwnd,2);
        WVar4 = GetWindowWord(hwnd,0xc);
        local_80 = CONCAT22(local_80._2_2_,WVar4);
        local_ec = width;
        if (width == 0xffffffff) {
          uVar11 = SendMessageA(hwnd,0x180,0,height);
          return uVar11;
        }
        if ((int)(local_8 & 0xffff) <= (int)width) {
          uVar11 = SendMessageA(hwnd,0x180,0,height);
          return uVar11;
        }
        if ((-2 < (int)width) && ((int)width < (int)(local_8 & 0xffff))) {
          local_7c = realloc(local_7c,(local_8 & 0xffff) * 4 + 4);
          if (local_7c != (void *)0x0) {
            for (local_e8 = local_8 & 0xffff; (int)local_ec < (int)local_e8; local_e8 = local_e8 - 1
                ) {
              *(int32_t *)((int)local_7c + local_e8 * 4) =
                   *(int32_t *)((int)local_7c + local_e8 * 4 + -4);
            }
            *(uint32_t *)((int)local_7c + local_ec * 4) = height;
            WVar4 = (WORD)local_8 + 1;
            local_8 = CONCAT22(local_8._2_2_,WVar4);
            SetWindowWord(hwnd,0,WVar4);
            SetWindowLongA(hwnd,2,(LONG)local_7c);
            SetScrollRange(hwnd,0,0,((local_8 & 0xffff) - (local_80 & 0xffff)) + 1,0);
            thunk_FUN_100372c5(hwnd,local_ec,&local_e4);
            local_e4.right = 2000;
            InvalidateRect(hwnd,&local_e4,1);
            return local_ec;
          }
          return 0xfffffffe;
        }
        return 0xffffffff;
      case 0x182:
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        local_7c = (void *)GetWindowLongA(hwnd,2);
        WVar4 = GetWindowWord(hwnd,6);
        local_20 = CONCAT22(local_20._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,8);
        local_1c = CONCAT22(local_1c._2_2_,WVar4);
        local_128 = width;
        if ((-1 < (int)width) && ((int)width < (int)(local_8 & 0xffff))) {
          local_13c = 2;
          local_138 = GetDlgCtrlID(hwnd);
          local_134 = local_128;
          local_130 = hwnd;
          local_12c = *(int32_t *)((int)local_7c + local_128 * 4);
          uVar15 = SUB41(&local_13c,0);
          uVar16 = (uint8_t)((uint32_t)&local_13c >> 8);
          uVar17 = (int16_t)((uint32_t)&local_13c >> 0x10);
          WVar6 = GetDlgCtrlID(hwnd);
          UVar12 = 0x2d;
          pHVar7 = GetParent(hwnd);
          SendMessageA(pHVar7,UVar12,WVar6,CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
          for (local_124 = local_128; (int)local_124 < (int)((local_8 & 0xffff) - 1);
              local_124 = local_124 + 1) {
            *(int32_t *)((int)local_7c + local_124 * 4) =
                 *(int32_t *)((int)local_7c + 4 + local_124 * 4);
          }
          WVar4 = (WORD)local_8 - 1;
          local_8 = CONCAT22(local_8._2_2_,WVar4);
          SetWindowWord(hwnd,0,WVar4);
          if ((int)((local_8 & 0xffff) - 1) < (int)(local_20 & 0xffff)) {
            WVar4 = (short)local_20 - 1;
            local_20 = CONCAT22(local_20._2_2_,WVar4);
            SetWindowWord(hwnd,6,WVar4);
          }
          if ((int)((local_8 & 0xffff) - 1) < (int)(local_1c & 0xffff)) {
            WVar4 = (short)local_1c - 1;
            local_1c = CONCAT22(local_1c._2_2_,WVar4);
            SetWindowWord(hwnd,8,WVar4);
          }
          GetScrollRange(hwnd,0,&local_110,local_10c);
          SetScrollRange(hwnd,0,local_110,local_10c[0] + -1,1);
          thunk_FUN_100372c5(hwnd,local_128,&local_120);
          WVar4 = GetWindowWord(hwnd,10);
          local_120.right = (uint32_t)WVar4 * ((local_8 & 0xffff) + 1);
          if (local_120.left < 1) {
            local_120.left = 0;
          }
          InvalidateRect(hwnd,&local_120,1);
          if ((local_8 & 0xffff) == 0) {
            local_20 = CONCAT22(local_20._2_2_,0xffff);
            local_1c = local_1c & 0xffff0000;
            SetWindowWord(hwnd,6,0xffff);
            SetWindowWord(hwnd,8,(WORD)local_1c);
          }
          return local_8 & 0xffff;
        }
        return 0xffffffff;
      case 0x184:
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        local_7c = (void *)GetWindowLongA(hwnd,2);
        local_f4 = 0;
        while( true ) {
          if ((int)(local_8 & 0xffff) <= local_f4) break;
          local_10c[1] = 2;
          local_10c[2] = GetDlgCtrlID(hwnd);
          local_100 = local_f4;
          local_fc = hwnd;
          local_f8 = *(int32_t *)((int)local_7c + local_f4 * 4);
          i_ptr_1 = local_10c + 1;
          uVar15 = SUB41(i_ptr_1,0);
          uVar16 = (uint8_t)((uint32_t)i_ptr_1 >> 8);
          uVar17 = (int16_t)((uint32_t)i_ptr_1 >> 0x10);
          WVar6 = GetDlgCtrlID(hwnd);
          UVar12 = 0x2d;
          pHVar7 = GetParent(hwnd);
          SendMessageA(pHVar7,UVar12,WVar6,CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
          local_f4 = local_f4 + 1;
        }
        local_7c = realloc(local_7c,4);
        local_8 = local_8 & 0xffff0000;
        local_20 = CONCAT22(local_20._2_2_,0xffff);
        local_1c = (uint32_t)local_1c._2_2_ << 0x10;
        SetWindowLongA(hwnd,2,(LONG)local_7c);
        SetWindowWord(hwnd,0,(WORD)local_8);
        SetWindowWord(hwnd,6,(WORD)local_20);
        SetWindowWord(hwnd,8,(WORD)local_1c);
        SetScrollRange(hwnd,0,0,-1,0);
        SetScrollPos(hwnd,0,local_20 & 0xffff,1);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      case 0x186:
        WVar3 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar3);
        local_7c = (void *)GetWindowLongA(hwnd,2);
        WVar3 = GetWindowWord(hwnd,0xc);
        local_80 = CONCAT22(local_80._2_2_,WVar3);
        WVar3 = GetWindowWord(hwnd,6);
        local_ac = CONCAT22(local_ac._2_2_,WVar3);
        WVar3 = GetWindowWord(hwnd,8);
        local_1c = CONCAT22(local_1c._2_2_,WVar3);
        local_20 = CONCAT22(local_20._2_2_,WVar4);
        if ((width & 0xffff) < (local_8 & 0xffff)) {
          SetWindowWord(hwnd,6,WVar4);
          if ((local_ac & 0xffff) < (local_8 & 0xffff)) {
            thunk_FUN_100372c5(hwnd,local_ac & 0xffff,&local_a8);
          }
          thunk_FUN_100372c5(hwnd,local_20 & 0xffff,&local_a8);
          UpdateWindow(hwnd);
          if ((local_20 & 0xffff) < (local_1c & 0xffff)) {
            SendMessageA(hwnd,0x114,CONCAT31((int3)((local_20 << 0x10) >> 8),4),0);
          }
          if ((int)((local_80 & 0xffff) + (local_1c & 0xffff) + -1) < (int)(local_20 & 0xffff)) {
            SendMessageA(hwnd,0x114,
                         CONCAT31((int3)((((local_20 & 0xffff) - (local_80 & 0xffff)) + 1) * 0x10000
                                        >> 8),4),0);
          }
          return 0;
        }
        return 0xffffffff;
      case 0x188:
        WVar4 = GetWindowWord(hwnd,6);
        local_20 = (uint32_t)WVar4;
        return local_20;
      }
    }
    else if (y < 0x1a1) {
      if (y == 0x1a0) {
        local_c0 = height & 0xffff;
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        WVar4 = (short)local_c0 + 8;
        local_48 = CONCAT22(local_48._2_2_,WVar4);
        SetWindowWord(hwnd,10,WVar4);
        GetClientRect(hwnd,&local_bc);
        WVar4 = (WORD)((local_bc.right + -4) / (int)(local_48 & 0xffff));
        if ((int)((local_48 & 0xffff) >> 2) <= (local_bc.right + -4) % (int)(local_48 & 0xffff)) {
          WVar4 = WVar4 + 1;
        }
        local_80 = CONCAT22(local_80._2_2_,WVar4);
        SetWindowWord(hwnd,0xc,WVar4);
        SetScrollRange(hwnd,0,0,((local_8 & 0xffff) - (local_80 & 0xffff)) + 1,0);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      }
      if (y == 0x197) {
        local_1c = CONCAT22(local_1c._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        if ((local_1c & 0xffff) < (uint32_t)WVar4) {
          SetWindowWord(hwnd,8,(WORD)local_1c);
          SendMessageA(hwnd,0x114,CONCAT31((int3)((local_1c << 0x10) >> 8),4),0);
          return 0;
        }
        return 0xffffffff;
      }
      if (y == 0x199) {
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        LVar5 = GetWindowLongA(hwnd,2);
        if ((-1 < (int)width) && ((int)width < (int)(local_8 & 0xffff))) {
          return *(uint32_t *)(LVar5 + width * 4);
        }
        return 0xffffffff;
      }
    }
    else if (y < 0x465) {
      if (y == 0x464) {
        SendMessageA(DAT_10176868,0x466,width,(LPARAM)hwnd);
        return 0;
      }
      switch(y) {
      case 0x200:
        iVar13 = abs(DAT_1013ec04 - (height >> 0x10));
        val_8 = abs(DAT_1013ec00 - (height & 0xffff));
        if (iVar13 + val_8 < 2) {
          return 0;
        }
        DAT_1013ec00 = height & 0xffff;
        DAT_1013ec04 = height >> 0x10;
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,8);
        local_1c = CONCAT22(local_1c._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,10);
        local_48 = CONCAT22(local_48._2_2_,WVar4);
        WVar4 = GetWindowWord(hwnd,0xc);
        local_80 = CONCAT22(local_80._2_2_,WVar4);
        if ((local_8 & 0xffff) != 0) {
          local_194 = height & 0xffff;
          local_190 = height >> 0x10;
          local_18c = local_1c & 0xffff;
          local_174 = 0;
          while (((int)local_18c <= (int)((local_80 & 0xffff) + (local_1c & 0xffff)) &&
                 (local_174 == 0))) {
            thunk_FUN_100372c5(hwnd,local_18c,&local_184);
            pt.y._0_1_ = (char)local_190;
            pt.x = local_194;
            pt.y._1_1_ = (char)(local_190 >> 8);
            pt.y._2_2_ = (short)(local_190 >> 0x10);
            BVar10 = PtInRect(&local_184,pt);
            if (BVar10 != 0) {
              local_174 = 1;
              local_188 = local_18c;
            }
            local_18c = local_18c + 1;
          }
          if ((local_174 != 0) && (WVar6 = SendMessageA(hwnd,0x188,0,0), WVar6 != local_188)) {
            SendMessageA(hwnd,0x186,local_188,0);
            uVar11 = GetDlgCtrlID(hwnd);
            uVar11 = uVar11 & 0xffff | 0x10000;
            UVar12 = 0x111;
            pHVar7 = GetParent(hwnd);
            SendMessageA(pHVar7,UVar12,uVar11,CONCAT22(uVar17,CONCAT11(uVar16,uVar15)));
          }
        }
        return 0;
      case 0x201:
        if ((DAT_101cdea0 & 1) == 0) {
          return 0;
        }
        GetCursorPos(&local_54);
        GetCursorPos((LPPOINT)&DAT_1013f178);
        ScreenToClient(DAT_10176868,&local_54);
        ScreenToClient(DAT_101cfb80,(LPPOINT)&DAT_1013f178);
        local_4c = GetDoubleClickTime();
        Sleep(local_4c);
        BVar10 = PeekMessageA(&local_78,hwnd,0x203,0x203,0);
        if (BVar10 != 0) {
          return 0;
        }
        SetFocus(hwnd);
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        if (WVar4 != 0) {
          SendMessageA(hwnd,0x200,width & 0xfffffffe,height);
          if ((width & 4) == 0) {
            iVar13 = thunk_FUN_10037c37(hwnd,1,0);
            if (iVar13 == 0) {
              MessageBeep(0);
              return 0;
            }
          }
          else {
            iVar13 = thunk_FUN_10037c37(hwnd,1,1);
            if (iVar13 == 0) {
              MessageBeep(0);
              return 0;
            }
          }
        }
        return 0;
      case 0x203:
        if ((DAT_101cdea0 & 1) == 0) {
          return 0;
        }
        GetCursorPos(&local_54);
        GetCursorPos((LPPOINT)&DAT_1013f178);
        ScreenToClient(DAT_10176868,&local_54);
        ScreenToClient(DAT_101cfb80,(LPPOINT)&DAT_1013f178);
        SetFocus(hwnd);
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        if (WVar4 != 0) {
          SendMessageA(hwnd,0x200,width & 0xfffffffe,height);
          if ((width & 4) == 0) {
            iVar13 = thunk_FUN_10037c37(hwnd,0,0);
            if (iVar13 == 0) {
              MessageBeep(0);
              return 0;
            }
          }
          else {
            iVar13 = thunk_FUN_10037c37(hwnd,0,1);
            if (iVar13 == 0) {
              MessageBeep(0);
              return 0;
            }
          }
        }
        return 0;
      case 0x204:
        if ((DAT_101cdea0 & 2) == 0) {
          return 0;
        }
        SetFocus(hwnd);
        WVar4 = GetWindowWord(hwnd,0);
        local_8 = CONCAT22(local_8._2_2_,WVar4);
        if (WVar4 != 0) {
          SendMessageA(hwnd,0x200,width & 0xfffffffd,height);
          local_54.x = height & 0xffff;
          local_54.y = height >> 0x10;
          local_58 = SendMessageA(hwnd,0x188,0,0);
          thunk_FUN_100372c5(DAT_101cfb80,local_58,&local_18);
          pt_00.y._0_1_ = (char)local_54.y;
          pt_00.x = local_54.x;
          pt_00.y._1_1_ = (char)((uint32_t)local_54.y >> 8);
          pt_00.y._2_2_ = (short)((uint32_t)local_54.y >> 0x10);
          BVar10 = PtInRect(&local_18,pt_00);
          if (BVar10 == 0) {
            return 0;
          }
          ScreenToClient(DAT_10176868,&local_54);
          DAT_1013ec50 = SendMessageA(hwnd,0x199,local_58,0);
          local_44 = thunk_FUN_1000d754(DAT_1013ec50);
          if (local_44 == -1) {
            return 0;
          }
          DAT_1004ba54 = (*DAT_101625f8)((char)local_44);
          sprintf(local_40,s_Sell_Card_for__d_1004ba94,(char)DAT_1004ba54);
          AppendMenuA(DAT_1013ec08,0,1,local_40);
          ClientToScreen(hwnd,&local_54);
          TrackPopupMenu(DAT_1013ec08,2,local_54.x + 10,local_54.y + 10,0,hwnd,(RECT *)0x0);
          DeleteMenu(DAT_1013ec08,1,0);
        }
        return 0;
      }
    }
    else if (y == 0x466) {
      local_98 = width;
      WVar4 = GetWindowWord(hwnd,0);
      local_8 = CONCAT22(local_8._2_2_,WVar4);
      local_7c = (void *)GetWindowLongA(hwnd,2);
      WVar4 = GetWindowWord(hwnd,8);
      local_1c = CONCAT22(local_1c._2_2_,WVar4);
      WVar4 = GetWindowWord(hwnd,0xc);
      local_80 = CONCAT22(local_80._2_2_,WVar4);
      local_94 = local_1c & 0xffff;
      while( true ) {
        uVar11 = (local_80 & 0xffff) + (local_1c & 0xffff);
        if ((local_8 & 0xffff) <= uVar11) {
          uVar11 = local_8 & 0xffff;
        }
        if ((int)uVar11 <= (int)local_94) break;
        if (*(uint32_t *)((int)local_7c + local_94 * 4) == local_98) {
          thunk_FUN_100372c5(hwnd,local_94,&local_90);
          InvalidateRect(hwnd,&local_90,0);
        }
        local_94 = local_94 + 1;
      }
      return 0;
    }
  }
  uVar11 = DefWindowProcA(hwnd,y,width,height);
  return uVar11;
}


