/*
 * Decompiled function: Glue_Subsystem_004cdb4f
 * Entry Point: 00493e30
 * Size: 14669 bytes
 */
#include "duel.h"


uint Glue_Subsystem_004cdb4f(HWND hwnd,uint y,HWND param_3,HWND param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  LONG LVar4;
  HWND pHVar5;
  HWND pHVar6;
  HBRUSH hbr;
  HGDIOBJ pvVar7;
  uint uVar8;
  UINT UVar9;
  HMENU hMenu;
  WPARAM wParam;
  HINSTANCE hInstance;
  LPARAM LVar10;
  LPVOID lpParam;
  int local_598;
  tagPOINT local_594;
  tagRECT local_58c;
  uint local_57c;
  int local_574;
  HGDIOBJ local_570;
  tagRECT local_56c;
  HBITMAP local_55c;
  CHAR local_558 [100];
  HBRUSH local_4f4;
  HDC local_4f0;
  undefined1 local_4ec [4];
  int local_4e8;
  int local_4e4;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  int local_4c4;
  int local_4c0;
  uint local_4bc;
  tagRECT local_4b8;
  tagRECT local_4a8;
  HGDIOBJ local_498;
  tagRECT local_494;
  int local_484;
  HGDIOBJ local_480;
  HWND local_47c;
  int local_474;
  uint local_470;
  tagRECT local_46c;
  int local_45c;
  HWND local_454;
  int local_450;
  uint local_44c;
  uint local_448;
  int local_444;
  tagRECT local_440;
  tagRECT local_430;
  HWND local_420;
  uint local_41c;
  uint local_418;
  uint local_414 [66];
  HWND local_30c;
  undefined1 local_308 [4];
  int local_304;
  tagRECT local_2f0;
  tagRECT local_2e0;
  LRESULT local_2d0;
  HWND local_2cc;
  uint local_2c8 [66];
  ULONG_PTR local_1c0;
  int local_1bc;
  undefined1 local_1b8 [4];
  int local_1b4;
  int local_1b0;
  int local_1a0;
  int local_19c;
  int local_198;
  tagRECT local_194;
  LPARAM local_184;
  int local_180 [2];
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  uint local_168;
  HWND local_164;
  int local_160;
  int local_15c;
  int local_158;
  uint local_154;
  uint local_150;
  int local_14c;
  uint local_148;
  HWND local_144;
  uint local_140;
  int local_13c;
  int local_138;
  HWND local_134;
  HWND local_130;
  int local_12c;
  int local_128;
  HWND local_124;
  uint local_120;
  int local_118;
  int local_114;
  HWND local_110;
  uint local_10c;
  int local_108;
  int local_104;
  int local_100;
  HWND local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  HWND local_e8;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  HWND local_c8;
  tagRECT local_c4;
  HWND local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  HWND local_a4;
  HWND local_a0;
  int local_9c;
  int local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_88;
  int local_84;
  int local_80;
  int local_7c;
  uint local_78;
  int local_74;
  HWND local_70;
  HWND local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  HWND local_4c;
  int local_48;
  int local_44;
  int local_40;
  tagPOINT local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  tagRECT local_24;
  int local_14;
  HWND local_10;
  void *local_c;
  LONG local_8;
  
  if (y == 0x464) {
    local_2c = param_3;
    local_c = (void *)GetWindowLongA(hwnd,0);
    local_8 = GetWindowLongA(hwnd,4);
    local_10 = GetDlgItem(hwnd,0);
    local_14 = 0;
    local_30 = 0;
    while ((local_30 < local_8 && (local_14 == 0))) {
      if (*(HWND *)((int)local_c + local_30 * 0x19c) == local_2c) {
        local_14 = 1;
        local_28 = 5000;
        local_40 = -5000;
        for (local_34 = 0; local_34 < *(int *)((int)local_c + 0xcc + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 4 + (int)local_c),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
        for (local_34 = 0; local_34 < *(int *)((int)local_c + 0x198 + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 0xd0 + (int)local_c),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
      }
      local_30 = local_30 + 1;
    }
    if (local_14 != 0) {
      GetWindowRect(hwnd,&local_24);
      if (local_28 < local_24.left) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
      else if (local_24.right < local_40) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
    }
    return 0;
  }
  if (y < 7) {
    if (y == 6) {
      if ((((uint)param_3 & 0xffff) == 1) || (((uint)param_3 & 0xffff) == 2)) {
        SendMessageA(DAT_00694748,0x86,1,0);
      }
      else {
        SendMessageA(DAT_00694748,0x86,0,0);
      }
      uVar8 = DefWindowProcA(hwnd,6,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = _malloc(0xa0f0);
      SetWindowLongA(hwnd,0,(LONG)local_c);
      local_2cc = CreateWindowExA(0,s_MAGICGAME_ScrollbarClass_0050565c,&DAT_00505658,0x50000000,0,0
                                  ,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      if (local_2cc != (HWND)0x0) {
        SendMessageA(local_2cc,0x464,DAT_005dc2c0,1);
        SendMessageA(local_2cc,0x466,DAT_005dc2ac,DAT_00505550);
      }
      lpParam = (LPVOID)0x0;
      hMenu = (HMENU)0x0;
      hInstance = DAT_00664680;
      pHVar6 = GetParent(hwnd);
      DAT_00694748 = CreateWindowExA(0,s_AttackSwordShield_0050567c,&DAT_00505678,0x80c00000,0,0,0,0
                                     ,pHVar6,hMenu,hInstance,lpParam);
      DAT_005dc2bc = CreateWindowExA(0,s_AttackMinimized_00505694,&DAT_00505690,0x80000000,0,0,0,0,
                                     hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      if ((((local_c != (void *)0x0) && (local_2cc != (HWND)0x0)) && (DAT_00694748 != (HWND)0x0)) &&
         (DAT_005dc2bc != (HWND)0x0)) {
        return 0;
      }
      if (local_c != (void *)0x0) {
        FUN_004db150(local_c);
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_c = (void *)GetWindowLongA(hwnd,0);
      FUN_004db150(local_c);
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      local_30c = param_3;
      FUN_004707a4((HDC)param_3);
      GetClientRect(hwnd,&local_2e0);
      local_2d0 = SendDlgItemMessageA(hwnd,0,0xe1,0,0);
      if (DAT_005dc30c == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_414,(uint *)&DAT_006189a0);
        FUN_004d9640(local_414,(uint *)s__WINBK_Attack_pic_005056a4);
        DAT_005dc30c = (HANDLE)Pic_Load_00423833((char *)local_414);
      }
      if (DAT_005dc30c == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect((HDC)local_30c,&local_2e0,hbr);
      }
      else {
        CopyRect(&local_2f0,&local_2e0);
        GetObjectA(DAT_005dc30c,0x18,local_308);
        local_2f0.left = -(local_2d0 % local_304);
        FUN_00470b60((HDC)local_30c,&local_2f0.left,DAT_005dc30c);
      }
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_005dc2bc,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      uVar8 = UI_WndProc_00471df6(hwnd,0x20,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 0x18) {
      if (param_3 == (HWND)0x0) {
        ShowWindow(DAT_00694748,0);
      }
      else {
        ShowWindow(DAT_00694748,5);
      }
      PostMessageA(DAT_00664d90,0x403,0,0);
      uVar8 = DefWindowProcA(hwnd,0x18,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      local_47c = param_3;
      if (param_3 == (HWND)0x8) {
        SendMessageA(hwnd,0x111,0x65,0);
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0xa1,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    switch(y) {
    case 0x83:
      local_454 = param_4;
      local_45c = param_4->unused;
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      local_454->unused = local_45c;
      return uVar8;
    case 0x84:
      local_470 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      if (local_470 != 2) {
        return local_470;
      }
      local_474 = GetSystemMetrics(0x1e);
      GetClientRect(hwnd,&local_46c);
      MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_46c,2);
      return 8;
    case 0x85:
    case 0x86:
      GetWindowRect(hwnd,&local_494);
      OffsetRect(&local_494,-local_494.left,-local_494.top);
      if ((local_494.right != local_494.left) && (local_494.bottom != local_494.top)) {
        local_4bc = (uint)(y != 0x85);
        local_4f0 = GetWindowDC(hwnd);
        if (local_4f0 == (HDC)0x0) {
          return local_4bc;
        }
        FUN_004707a4(local_4f0);
        GetWindowRect(hwnd,&local_494);
        GetClientRect(hwnd,&local_56c);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_56c,2);
        OffsetRect(&local_56c,-local_494.left,-local_494.top);
        OffsetRect(&local_494,-local_494.left,-local_494.top);
        GetWindowTextA(hwnd,local_558,100);
        local_574 = local_494.right - local_56c.right;
        local_4c4 = local_494.bottom - local_56c.bottom;
        FUN_0044897a(&local_484,(undefined4 *)0x0);
        if (local_484 == 0) {
          local_498 = DAT_005dc2cc;
          local_570 = DAT_005dc2fc;
          local_480 = DAT_005dc2b8;
          local_4f4 = DAT_005dc2d4;
        }
        else {
          local_498 = DAT_005dc2e4;
          local_570 = DAT_005dc2e8;
          local_480 = DAT_005dc2c4;
          local_4f4 = DAT_005dc2f4;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = 0;
        MoveToEx(local_4f0,0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -1,local_4c8);
        SelectObject(local_4f0,local_498);
        local_4c8 = 1;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,(local_494.right - local_574) + 1,local_4c8);
          local_4c8 = local_4c8 + 1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_4c4 + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c0 = local_494.right + -1;
        MoveToEx(local_4f0,local_4c0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_494.bottom);
        SelectObject(local_4f0,local_480);
        local_4c0 = local_494.right + -2;
        for (local_4cc = 1; local_4cc <= local_574 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,local_4c0,1,(LPPOINT)0x0);
          LineTo(local_4f0,local_4c0,local_494.bottom + -1);
          local_4c0 = local_4c0 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c0 = local_56c.right;
        MoveToEx(local_4f0,local_56c.right,local_4c4 + -1,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_56c.bottom + 1);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c8 = local_494.bottom + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right,local_4c8);
        SelectObject(local_4f0,local_480);
        local_4c8 = local_494.bottom + -2;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,local_494.right + -1,local_4c8);
          local_4c8 = local_4c8 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_494.bottom - local_4c4;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -2,local_4c8);
        SelectObject(local_4f0,local_570);
        local_4c8 = local_56c.top + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        SetRect(&local_4a8,0,local_4c4,local_56c.right,local_56c.top + -1);
        FillRect(local_4f0,&local_4a8,local_4f4);
        SetBkMode(local_4f0,1);
        OffsetRect(&local_4a8,1,1);
        SetTextColor(local_4f0,DAT_005dc308);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        OffsetRect(&local_4a8,-1,-1);
        SetTextColor(local_4f0,DAT_005dc2c8);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        local_55c = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fed);
        GetObjectA(local_55c,0x18,local_4ec);
        local_4d0 = local_4e8;
        local_4d4 = local_4e4;
        SetRect(&local_4b8,local_56c.right - local_4e8,local_56c.top - local_4e4,local_56c.right,
                local_56c.top);
        FUN_004709ae((int)local_4f0,(int)&local_4b8,DAT_005dc2f8);
        DeleteObject(local_55c);
        ReleaseDC(hwnd,local_4f0);
        return local_4bc;
      }
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uVar8 = (uint)param_3 & 0xffff;
      if (uVar8 == 100) {
        local_1c0 = 0xbbc;
        Mem_AllocOrFree_004d9630(local_2c8,(uint *)&DAT_005f76e0);
        FUN_004d9640(local_2c8,(uint *)s__duel_hlp_0050564c);
        WinHelpA(DAT_00618990,(LPCSTR)local_2c8,1,local_1c0);
      }
      else if (uVar8 == 0x65) {
        ShowWindow(hwnd,0);
        UpdateWindow(DAT_00618988);
        GetWindowRect(DAT_006152ec,&local_194);
        local_198 = local_194.left;
        local_1a0 = local_194.right - local_194.left;
        if (DAT_005dc2f8 == (HANDLE)0x0) {
          local_1bc = local_1a0 * 2;
        }
        else {
          GetObjectA(DAT_005dc2f8,0x18,local_1b8);
          local_1bc = (local_1b0 * local_1a0) / local_1b4;
        }
        local_19c = (local_194.bottom - local_194.top) / 2 + local_1bc / 2 + 2;
        MoveWindow(DAT_005dc2bc,local_198,local_19c,local_1a0,local_1bc,1);
        ShowWindow(DAT_005dc2bc,5);
        BringWindowToTop(DAT_005dc2bc);
        SendMessageA(DAT_00664d90,0x403,0,0);
      }
      else if (uVar8 == 0x66) {
        ShowWindow(DAT_005dc2bc,0);
        ShowWindow(hwnd,5);
        SendMessageA(DAT_00664d90,0x403,0,0);
        FUN_0047283d();
      }
      return 0;
    }
    if (y == 0xa4) {
LAB_00497475:
      local_594.x = (uint)param_4 & 0xffff;
      local_594.y = (uint)param_4 >> 0x10;
      if (y == 0x204) {
        ClientToScreen(hwnd,&local_594);
      }
      SetRect(&local_58c,local_594.x,local_594.y,local_594.x + 1,local_594.y + 1);
      TrackPopupMenu(DAT_005dc2d8,2,local_594.x,local_594.y,0,hwnd,&local_58c);
      return 0;
    }
  }
  else if (y < 0x120) {
    if (y == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (param_4 == (HWND)0x0)) {
        local_598 = GetMenuItemCount(DAT_005dc2d8);
        while (local_598 != 0) {
          DeleteMenu(DAT_005dc2d8,0,0x400);
          local_598 = local_598 + -1;
        }
      }
      return 0;
    }
    if (y == 0x112) {
      local_57c = (uint)param_3 & 0xfff0;
      if (local_57c == 0xf010) {
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0x112,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 0x114) {
      local_420 = GetDlgItem(hwnd,0);
      SendMessageA(local_420,0xe3,(WPARAM)&local_448,(LPARAM)&local_41c);
      local_44c = SendMessageA(local_420,0xe1,0,0);
      local_444 = DAT_0061534c;
      GetClientRect(hwnd,&local_430);
      local_450 = local_430.right;
      switch((uint)param_3 & 0xffff) {
      case 0:
        local_418 = local_44c - local_444;
        break;
      case 1:
        local_418 = local_44c + local_444;
        break;
      case 2:
        local_418 = local_44c - local_430.right;
        break;
      case 3:
        local_418 = local_44c + local_430.right;
        break;
      case 4:
      case 5:
        local_418 = (uint)param_3 >> 0x10;
        break;
      case 6:
        local_418 = local_448;
        break;
      case 7:
        local_418 = local_41c;
        break;
      default:
        local_418 = local_44c;
      }
      if ((int)local_418 < (int)local_448) {
        local_418 = local_448;
      }
      if ((int)local_41c < (int)local_418) {
        local_418 = local_41c;
      }
      if (local_418 != local_44c) {
        SendMessageA(local_420,0xe0,local_418,1);
        GetWindowRect(local_420,&local_440);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_440,2);
        ScrollWindow(hwnd,local_44c - local_418,0,(RECT *)0x0,(RECT *)0x0);
        MoveWindow(local_420,local_440.left,local_440.top,local_440.right - local_440.left,
                   local_440.bottom - local_440.top,0);
        UpdateWindow(hwnd);
      }
      return 0;
    }
    if (y == 0x117) {
      AppendMenuA(DAT_005dc2d8,0,0x65,s__Minimize_005056b8);
      AppendMenuA(DAT_005dc2d8,0,100,s_Help____005056c4);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_00497475;
    if (y == 0x201) {
      return 0;
    }
  }
  else if (y < 0x402) {
    if (0x3ff < y) {
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_88 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      FUN_004994f8(hwnd,&param_3->unused,(undefined4 *)0x0,&local_8c,&local_84);
      if ((local_8c == (HWND)0x0) ||
         (((local_84 == 0 || (y != 0x400)) && ((local_84 != 0 || (y != 0x401)))))) {
        local_7c = 0;
      }
      else {
        local_7c = 1;
      }
      if (local_7c == 0) {
        local_8c = CreateWindowExA(0,s_MAGICGAME_CardClass_00505614,s_Card_in_attack_00505604,
                                   0x54000000,0,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,local_88);
        if (local_8c == (HWND)0x0) {
          return 0;
        }
        if (y == 0x400) {
          local_80 = FUN_00447038(local_88->unused,local_88[1].unused);
          if (local_80 == -1) {
            local_80 = local_88[1].unused;
          }
        }
        else {
          local_80 = FUN_00447038(local_88->unused,local_88[1].unused);
        }
        local_90 = 0;
        local_7c = 0;
        while ((local_90 < local_8 && (local_7c == 0))) {
          if (*(int *)((int)local_c + local_90 * 0x19c) == local_80) {
            local_7c = 1;
            if ((y == 0x400) && (*(int *)((int)local_c + 0xcc + local_90 * 0x19c) < 0x32)) {
              *(HWND *)(local_90 * 0x19c + *(int *)((int)local_c + 0xcc + local_90 * 0x19c) * 4 + 4
                       + (int)local_c) = local_8c;
              piVar1 = (int *)((int)local_c + 0xcc + local_90 * 0x19c);
              *piVar1 = *piVar1 + 1;
            }
            else {
              if ((y != 0x401) || (0x31 < *(int *)((int)local_c + 0x198 + local_90 * 0x19c))) {
                DestroyWindow(local_8c);
                return 0;
              }
              *(HWND *)(local_90 * 0x19c + *(int *)((int)local_c + 0x198 + local_90 * 0x19c) * 4 +
                        0xd0 + (int)local_c) = local_8c;
              piVar1 = (int *)((int)local_c + 0x198 + local_90 * 0x19c);
              *piVar1 = *piVar1 + 1;
            }
          }
          local_90 = local_90 + 1;
        }
        if (local_7c == 0) {
          if (99 < local_8) {
            DestroyWindow(local_8c);
            return 0;
          }
          *(int *)((int)local_c + local_8 * 0x19c) = local_80;
          if (y == 0x400) {
            *(HWND *)((int)local_c + 4 + local_8 * 0x19c) = local_8c;
            *(undefined4 *)((int)local_c + 0xcc + local_8 * 0x19c) = 1;
            *(undefined4 *)((int)local_c + 0x198 + local_8 * 0x19c) = 0;
          }
          else {
            *(HWND *)((int)local_c + 0xd0 + local_8 * 0x19c) = local_8c;
            *(undefined4 *)((int)local_c + 0x198 + local_8 * 0x19c) = 1;
            *(undefined4 *)((int)local_c + 0xcc + local_8 * 0x19c) = 0;
          }
          local_8 = local_8 + 1;
          SetWindowLongA(hwnd,4,local_8);
        }
        BringWindowToTop(local_8c);
      }
      return 1;
    }
    if ((0x30e < y) && (y < 0x312)) {
      uVar8 = FUN_00472b60(hwnd,y,param_3,param_4);
      return uVar8;
    }
  }
  else {
    switch(y) {
    case 0x402:
    case 0x403:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_fc = param_3;
      if (param_3 == (HWND)0x0) {
        local_e8 = param_4;
      }
      else {
        FUN_004994f8(hwnd,&param_3->unused,(undefined4 *)0x0,&local_e8,(undefined4 *)0x0);
      }
      if ((local_e8 != (HWND)0x0) && (pHVar6 = GetParent(local_e8), pHVar6 == hwnd)) {
        for (local_ec = 0; local_ec < local_8; local_ec = local_ec + 1) {
          local_e4 = 0;
          local_f0 = 0;
          while ((local_f0 < *(int *)((int)local_c + 0xcc + local_ec * 0x19c) && (local_e4 == 0))) {
            if ((y == 0x403) &&
               (*(HWND *)(local_f0 * 4 + local_ec * 0x19c + 4 + (int)local_c) == local_e8)) {
              local_e4 = 1;
              FUN_00497849((int)local_e8,local_ec * 0x19c + (int)local_c + 4,
                           *(int *)((int)local_c + 0xcc + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)local_c + 0xcc + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)local_c) != 0) {
                  *(undefined4 *)(local_f8 * 4 + local_ec * 0x19c + 4 + (int)local_c) =
                       *(undefined4 *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)local_c);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)local_c + 0xcc + local_ec * 0x19c) = local_f8;
            }
            else if ((y == 0x402) &&
                    (*(HWND *)(local_f0 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c) == local_e8))
            {
              local_e4 = 1;
              FUN_00497849((int)local_e8,local_ec * 0x19c + (int)local_c + 0xd0,
                           *(int *)((int)local_c + 0x198 + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)local_c + 0x198 + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c) != 0) {
                  *(undefined4 *)(local_f8 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c) =
                       *(undefined4 *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)local_c + 0x198 + local_ec * 0x19c) = local_f8;
            }
            local_f0 = local_f0 + 1;
          }
        }
        return local_e4;
      }
      return 0;
    case 0x404:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_134 = param_3;
      local_130 = param_4;
      if ((param_4 != (HWND)0x0) && (param_3 != (HWND)0xffffffff)) {
        local_140 = 0;
        for (local_138 = 0; local_138 < local_8; local_138 = local_138 + 1) {
          if (*(HWND *)((int)local_c + local_138 * 0x19c) == local_134) {
            for (local_13c = 0; local_13c < *(int *)((int)local_c + 0xcc + local_138 * 0x19c);
                local_13c = local_13c + 1) {
              iVar3 = FUN_004864b1(*(HWND *)(local_13c * 4 + local_138 * 0x19c + 4 + (int)local_c));
              if (iVar3 == 0) {
                local_130[local_140].unused =
                     *(int *)(local_13c * 4 + local_138 * 0x19c + 4 + (int)local_c);
                local_140 = local_140 + 1;
              }
            }
          }
        }
        return local_140;
      }
      return 0;
    case 0x405:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_124 = param_3;
      if ((param_3 == (HWND)0x0) || (pHVar6 = GetParent(param_3), pHVar6 != hwnd)) {
        return 0xffffffff;
      }
      bVar2 = false;
      for (local_128 = 0; local_128 < local_8; local_128 = local_128 + 1) {
        local_12c = 0;
        while ((local_12c < *(int *)((int)local_c + 0xcc + local_128 * 0x19c) && (!bVar2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 4 + (int)local_c) == local_124) {
            bVar2 = true;
            local_120 = 1;
          }
          local_12c = local_12c + 1;
        }
        local_12c = 0;
        while ((local_12c < *(int *)((int)local_c + 0x198 + local_128 * 0x19c) && (!bVar2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 0xd0 + (int)local_c) == local_124) {
            bVar2 = true;
            local_120 = 0;
          }
          local_12c = local_12c + 1;
        }
      }
      if (bVar2) {
        return local_120;
      }
      return 0xffffffff;
    case 0x406:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_a0 = param_3;
      local_94 = param_4;
      if (((param_3 == (HWND)0x0) || (param_4 == (HWND)0x0)) ||
         (pHVar6 = GetParent(param_4), pHVar6 != hwnd)) {
        return 0;
      }
      iVar3 = FUN_004994f8(hwnd,&local_a0->unused,(undefined4 *)0x0,(undefined4 *)0x0,
                           (undefined4 *)0x0);
      if (iVar3 != 0) {
        return 1;
      }
      local_a8 = 0;
      local_ac = 0;
      while ((local_ac < local_8 && (local_a8 == 0))) {
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)local_c + 0xcc + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 4 + (int)local_c) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 1;
          }
          local_b0 = local_b0 + 1;
        }
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)local_c + 0x198 + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 0xd0 + (int)local_c) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 0;
          }
          local_b0 = local_b0 + 1;
        }
        local_ac = local_ac + 1;
      }
      if (local_a8 == 0) {
        return 0;
      }
      local_a4 = CreateWindowExA(0,s_MAGICGAME_CardClass_00505638,s_Card_in_attack_00505628,
                                 0x54000000,0,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,local_a0);
      if (local_a4 == (HWND)0x0) {
        return 0;
      }
      SendMessageA(local_a4,0x402,(WPARAM)local_94,0);
      if ((local_9c == 0) || (0x31 < *(int *)((int)local_c + 0xcc + local_98 * 0x19c))) {
        if ((local_9c != 0) || (0x31 < *(int *)((int)local_c + 0x198 + local_98 * 0x19c))) {
          DestroyWindow(local_a4);
          return 0;
        }
        *(HWND *)(local_98 * 0x19c + *(int *)((int)local_c + 0x198 + local_98 * 0x19c) * 4 + 0xd0 +
                 (int)local_c) = local_a4;
        piVar1 = (int *)((int)local_c + 0x198 + local_98 * 0x19c);
        *piVar1 = *piVar1 + 1;
      }
      else {
        *(HWND *)(local_98 * 0x19c + *(int *)((int)local_c + 0xcc + local_98 * 0x19c) * 4 + 4 +
                 (int)local_c) = local_a4;
        piVar1 = (int *)((int)local_c + 0xcc + local_98 * 0x19c);
        *piVar1 = *piVar1 + 1;
      }
      return 1;
    case 0x40c:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      ShowWindow(hwnd,0);
      ShowWindow(DAT_005dc2bc,0);
      for (local_100 = 0; local_100 < local_8; local_100 = local_100 + 1) {
        for (local_104 = 0; local_104 < *(int *)((int)local_c + 0xcc + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 4 + (int)local_c));
        }
        *(undefined4 *)((int)local_c + 0xcc + local_100 * 0x19c) = 0;
        for (local_104 = 0; local_104 < *(int *)((int)local_c + 0x198 + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 0xd0 + (int)local_c));
        }
        *(undefined4 *)((int)local_c + 0x198 + local_100 * 0x19c) = 0;
      }
      local_8 = 0;
      SetWindowLongA(hwnd,4,0);
      LVar10 = 1;
      wParam = 0;
      UVar9 = 0xe0;
      pHVar6 = GetDlgItem(hwnd,0);
      SendMessageA(pHVar6,UVar9,wParam,LVar10);
      return 0;
    case 0x40e:
    case 0x40f:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_110 = param_3;
      if (param_3 == (HWND)0x0) {
        local_108 = 0;
      }
      else {
        local_108 = 0;
        for (local_114 = 0; local_114 < local_8; local_114 = local_114 + 1) {
          local_118 = 0;
          while ((local_118 < *(int *)((int)local_c + 0xcc + local_114 * 0x19c) && (local_108 == 0))
                ) {
            iVar3 = FUN_00486348(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)local_c),
                                 &local_110->unused);
            if (iVar3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0048644e(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 +
                                                  (int)local_c));
              }
              else {
                local_10c = *(uint *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)local_c);
              }
            }
            local_118 = local_118 + 1;
          }
          local_118 = 0;
          while ((local_118 < *(int *)((int)local_c + 0x198 + local_114 * 0x19c) && (local_108 == 0)
                 )) {
            iVar3 = FUN_00486348(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)local_c),
                                 &local_110->unused);
            if (iVar3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0048644e(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 +
                                                  (int)local_c));
              }
              else {
                local_10c = *(uint *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)local_c);
              }
            }
            local_118 = local_118 + 1;
          }
        }
      }
      if (local_108 != 0) {
        return local_10c;
      }
      if (y == 0x40e) {
        return 0xffffffff;
      }
      return 0;
    case 0x410:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_c8 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_dc = 5;
      local_e0 = DAT_00664d4c;
      GetWindowRect(param_3,&local_c4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c4,2);
      local_cc = local_c4.left + local_dc;
      local_d0 = local_c4.top - local_e0;
      local_b4 = local_c8;
      for (local_d4 = 0; local_d4 < local_8; local_d4 = local_d4 + 1) {
        for (local_d8 = 0; local_d8 < *(int *)((int)local_c + 0xcc + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_004864b1(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c))
          ;
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c),local_b4,
                         local_cc,local_d0,DAT_0061534c,DAT_0061898c,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c);
          }
        }
        for (local_d8 = 0; local_d8 < *(int *)((int)local_c + 0x198 + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_004864b1(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 +
                                               (int)local_c));
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)local_c),local_b4,
                         local_cc,local_d0,DAT_0061534c,DAT_0061898c,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)local_c);
          }
        }
      }
      return 0;
    case 0x411:
      local_c = (void *)GetWindowLongA(hwnd,0);
      LVar4 = GetWindowLongA(hwnd,4);
      local_78 = 0;
      for (local_74 = 0; local_74 < LVar4; local_74 = local_74 + 1) {
        if (*(int *)((int)local_c + 0xcc + local_74 * 0x19c) != 0) {
          local_78 = local_78 + 1;
        }
      }
      return local_78;
    case 0x412:
      local_164 = param_3;
      local_154 = 0;
      for (local_14c = 0; local_14c < 2; local_14c = local_14c + 1) {
        for (local_16c = 0; local_16c < 0x50; local_16c = local_16c + 1) {
          local_174 = local_14c;
          local_170 = local_16c;
          local_158 = FUN_00447114(local_14c,local_16c);
          local_15c = FUN_004471f7(local_14c,local_16c);
          local_150 = FUN_00448124(local_14c,local_16c);
          FUN_004994f8(hwnd,&local_174,(undefined4 *)0x0,&local_178,&local_160);
          iVar3 = FUN_004b26c4(DAT_00617378,&local_174,(undefined4 *)0x0,&local_144);
          if (iVar3 == 0) {
            FUN_004b26c4(DAT_00618988,&local_174,(undefined4 *)0x0,&local_144);
          }
          if ((local_158 != DAT_0068eee0) && (local_15c != 2)) {
            if (((local_158 == -1) || (local_15c != 1)) ||
               (((local_150 & 0x10000) != 0 && (DAT_00663e1c == 0)))) {
              if (local_178 != 0) {
                if (local_160 == 0) {
                  uVar8 = SendMessageA(hwnd,0x402,0,local_178);
                  local_154 = local_154 | uVar8;
                }
                else {
                  uVar8 = SendMessageA(hwnd,0x403,0,local_178);
                  local_154 = local_154 | uVar8;
                }
              }
              LVar10 = 1;
              UVar9 = 0x402;
              pHVar6 = local_144;
              pHVar5 = GetParent(local_144);
              SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
            }
            else {
              local_148 = FUN_004472ad(local_14c,local_16c);
              local_168 = FUN_004478fb(local_14c,local_16c);
              if ((local_148 & 0x10) == 0) {
                if (((((local_148 & 8) == 0) || ((local_168 & 4) != 0)) || ((local_168 & 0x40) != 0)
                    ) && ((local_168 & 8) == 0)) {
                  if ((local_178 != 0) && (local_160 == 0)) {
                    uVar8 = SendMessageA(hwnd,0x402,0,local_178);
                    local_154 = local_154 | uVar8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x401,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  FUN_004b24c6(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
                if ((((local_148 & 4) == 0) && ((local_168 & 4) == 0)) && ((local_168 & 0x40) == 0))
                {
                  if ((local_178 != 0) && (local_160 != 0)) {
                    uVar8 = SendMessageA(hwnd,0x403,0,local_178);
                    local_154 = local_154 | uVar8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x400,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  FUN_004b24c6(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
              }
              else {
                iVar3 = FUN_004994f8(hwnd,&local_174,(undefined4 *)0x0,(undefined4 *)0x0,
                                     (undefined4 *)0x0);
                if (iVar3 == 0) {
                  FUN_0044743d(local_180,local_14c,local_16c);
                  iVar3 = FUN_004994f8(hwnd,local_180,(undefined4 *)0x0,&local_184,(undefined4 *)0x0
                                      );
                  if (iVar3 != 0) {
                    SendMessageA(hwnd,0x406,(WPARAM)&local_174,local_184);
                    local_154 = 1;
                  }
                }
              }
            }
          }
        }
      }
      if ((local_154 != 0) || (local_164 != (HWND)0x0)) {
        FUN_0049793e(hwnd);
      }
      return 0;
    case 0x432:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      for (local_50 = 0; local_50 < local_8; local_50 = local_50 + 1) {
        for (local_54 = 0; local_54 < *(int *)((int)local_c + 0xcc + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 4 + (int)local_c),0x432,0,0);
        }
        for (local_54 = 0; local_54 < *(int *)((int)local_c + 0x198 + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 0xd0 + (int)local_c),0x432,0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_4c = param_3;
      for (local_44 = 0; local_44 < local_8; local_44 = local_44 + 1) {
        for (local_48 = 0; local_48 < *(int *)((int)local_c + 0xcc + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          iVar3 = FUN_004863ca(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)local_c),
                               (int)local_4c);
          if (iVar3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)local_c),(RECT *)0x0
                           ,0);
          }
        }
        for (local_48 = 0; local_48 < *(int *)((int)local_c + 0x198 + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          iVar3 = FUN_004863ca(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)local_c),
                               (int)local_4c);
          if (iVar3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)local_c),
                           (RECT *)0x0,0);
          }
        }
      }
      return 0;
    case 0x435:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      for (local_58 = 0; local_58 < local_8; local_58 = local_58 + 1) {
        for (local_5c = 0; local_5c < *(int *)((int)local_c + 0xcc + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 4 + (int)local_c),(RECT *)0x0,0
                        );
        }
        for (local_5c = 0; local_5c < *(int *)((int)local_c + 0x198 + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 0xd0 + (int)local_c),
                         (RECT *)0x0,0);
        }
      }
      return 0;
    case 0x436:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_6c = param_3;
      local_70 = param_4;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_60 = 0;
      for (local_64 = 0; local_64 < local_8; local_64 = local_64 + 1) {
        for (local_68 = 0; local_68 < *(int *)((int)local_c + 0xcc + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          iVar3 = FUN_00486348(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),
                               &local_6c->unused);
          if (iVar3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),0x432,0,0);
            }
          }
        }
        for (local_68 = 0; local_68 < *(int *)((int)local_c + 0x198 + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          iVar3 = FUN_00486348(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),
                               &local_6c->unused);
          if (iVar3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),0x432,0,
                           0);
            }
          }
        }
      }
      return 0;
    case 0x437:
      return 0;
    }
  }
  uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
  return uVar8;
}


