/*
 * Decompiled function: FUN_10006d68
 * Entry Point: 10006d68
 * Size: 4118 bytes
 */
#include "deckdll.h"


LRESULT FUN_10006d68(HWND hwnd,uint32_t y,HDC hdc,uint32_t height)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  LRESULT LVar5;
  tagPOINT local_8c;
  HDC local_84;
  tagPAINTSTRUCT local_80;
  HDC local_40;
  tagRECT local_3c;
  HDC local_2c;
  POINT local_28;
  LRESULT local_20;
  HWND local_1c;
  HMENU local_18;
  HDC local_14;
  int local_10;
  int local_c;
  HWND local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_84 = BeginPaint(hwnd,&local_80);
      thunk_FUN_10031425(local_84);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128960,&DAT_10040b4c);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128900,&DAT_10040b54);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128910,s_Black_10040b5c);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128920,&DAT_10040b64);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128950,&DAT_10040b6c);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128930,s_Green_10040b70);
      thunk_FUN_10007dbf(local_84,(RECT *)&DAT_10128940,s_White_10040b78);
      EndPaint(hwnd,&local_80);
      return 0;
    }
    if (y == 1) {
      SetWindowTextA(hwnd,s_Trade_10040ab4);
      DAT_101289d0 = CreatePopupMenu();
      AppendMenuA(DAT_101289d0,0,0xcc,s__New_deck_10040abc);
      AppendMenuA(DAT_101289d0,0,0xcd,s__Load_deck_10040ac8);
      AppendMenuA(DAT_101289d0,0,0xce,s__Save_deck_10040ad4);
      AppendMenuA(DAT_101289d0,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_101289d0,0,200,s__Consolidate_duplicate_cards_tra_10040ae0);
      AppendMenuA(DAT_101289d0,0,0xca,s_C_lear_trade_10040b04);
      AppendMenuA(DAT_101289d0,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_101289d0,0,0xd3,s_M_inimize_10040b14);
      AppendMenuA(DAT_101289d0,0,0xd1,s__Music_10040b20);
      AppendMenuA(DAT_101289d0,0,0xd2,s_Sound__Effects_10040b28);
      AppendMenuA(DAT_101289d0,0,0xcf,s_E_xit_deck_builder_10040b38);
      return 0;
    }
    if (y == 2) {
      DestroyMenu(DAT_101289d0);
      return 0;
    }
    if (y == 5) {
      val_1 = (height & 0xffff) - 0x32;
      val_2 = (int)(val_1 + (val_1 >> 0x1f & 3U)) >> 2;
      val_3 = (int)((height >> 0x10) - 0x1e) / 2;
      SetRect((LPRECT)&DAT_10128960,10,10,val_2 + 10,val_3 + 10);
      val_1 = val_2 + 0x14;
      SetRect((LPRECT)&DAT_10128900,val_1,10,val_1 + val_2,val_3 + 10);
      val_1 = val_1 + val_2 + 10;
      SetRect((LPRECT)&DAT_10128910,val_1,10,val_1 + val_2,val_3 + 10);
      val_1 = val_1 + val_2 + 10;
      SetRect((LPRECT)&DAT_10128940,val_1,10,val_1 + val_2,val_3 + 10);
      val_4 = val_2 + 0x14;
      val_1 = val_3 + 0x14;
      SetRect((LPRECT)&DAT_10128920,val_4,val_1,val_4 + val_2,val_1 + val_3);
      val_4 = val_4 + val_2 + 10;
      SetRect((LPRECT)&DAT_10128930,val_4,val_1,val_4 + val_2,val_1 + val_3);
      val_4 = val_4 + val_2 + 10;
      SetRect((LPRECT)&DAT_10128950,val_4,val_1,val_4 + val_2,val_1 + val_3);
      SendMessageA(hwnd,0x111,0xc9,0);
      return 0;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      switch((uint32_t)hdc & 0xffff) {
      case 200:
        DAT_101cfa68 = (uint32_t)(DAT_101cfa68 == 0);
        SendMessageA(DAT_101cf33c,0x401,0,0);
        SendMessageA(DAT_10176850,0x401,0,0);
        SendMessageA(DAT_101625ec,0x401,0,0);
        break;
      case 0xc9:
        thunk_FUN_1000862d(hwnd,0x10128900,7);
        break;
      case 0xca:
        if (((((DAT_101cf048 != 0) || (DAT_101cf0c4 != 0)) || (DAT_101cf140 != 0)) ||
            ((DAT_101cf1bc != 0 || (DAT_101cf238 != 0)))) ||
           ((DAT_101cf2b4 != 0 || (DAT_101cf330 != 0)))) {
          DAT_10040508 = DAT_101cf048;
          DAT_1004050c = DAT_101cf0c4;
          DAT_10040510 = DAT_101cf140;
          DAT_10040514 = DAT_101cf1bc;
          DAT_10040518 = DAT_101cf238;
          DAT_1004051c = DAT_101cf2b4;
          DAT_10040520 = DAT_101cf330;
          DAT_101cf1bc = 0;
          DAT_101cf140 = 0;
          DAT_101cf0c4 = 0;
          DAT_101cf048 = 0;
          DAT_101cf330 = 0;
          DAT_101cf2b4 = 0;
          DAT_101cf238 = 0;
          DeleteMenu(DAT_101289d0,0xca,0);
          AppendMenuA(DAT_101289d0,0,0xcb,s__Restore_trade_10040a94);
          SendMessageA(DAT_101625ec,0x401,0,0);
        }
        break;
      case 0xcb:
        DAT_101cf048 = DAT_10040508;
        DAT_101cf0c4 = DAT_1004050c;
        DAT_101cf140 = DAT_10040510;
        DAT_101cf1bc = DAT_10040514;
        DAT_101cf238 = DAT_10040518;
        DAT_101cf2b4 = DAT_1004051c;
        DAT_101cf330 = DAT_10040520;
        DAT_10040514 = 0;
        DAT_10040510 = 0;
        DAT_1004050c = 0;
        DAT_10040508 = 0;
        DAT_10040520 = 0;
        DAT_1004051c = 0;
        DAT_10040518 = 0;
        AppendMenuA(DAT_101289d0,0,0xca,s_C_lear_trade_10040aa4);
        DeleteMenu(DAT_101289d0,0xcb,0);
        SendMessageA(DAT_101625ec,0x401,0,0);
        break;
      case 0xcd:
        SendMessageA(DAT_10176868,0x111,0xc,0);
        break;
      case 0xce:
        SendMessageA(DAT_10176868,0x111,0xd,0);
        break;
      case 0xcf:
        SendMessageA(DAT_10176868,0x10,0,0);
        break;
      case 0xd1:
        SendMessageA(DAT_10176868,0x111,0xe,0);
        break;
      case 0xd2:
        SendMessageA(DAT_10176868,0x111,0xf,0);
        break;
      case 0xd3:
        SendMessageA(DAT_10176868,0x112,0xf020,0);
      }
      return 0;
    }
    if (y == 0x14) {
      local_40 = hdc;
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_3c);
      FillRect(local_40,&local_3c,DAT_1016e4ac);
      return 1;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
      BringWindowToTop(hwnd);
      SetFocus(DAT_10176868);
      return 0;
    }
    if (y == 0x116) {
      CheckMenuItem(DAT_101289d0,200,(DAT_101cfa68 == 0) - 1 & 8);
      CheckMenuItem(DAT_101289d0,0xd2,(DAT_101cf542 == '\0') - 1 & 8);
      CheckMenuItem(DAT_101289d0,0xd1,(DAT_101cf541 == '\0') - 1 & 8);
      return 0;
    }
  }
  else if (y < 0x402) {
    if (y == 0x401) {
      local_c = 1;
      thunk_FUN_1000849a(hwnd);
      for (local_10 = 0; local_10 < DAT_101cf048; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100409c8,&DAT_100409c4,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x6,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cefd0 + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf0c4; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100409e0,&DAT_100409dc,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x0,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf04c + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf140; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100409f8,&DAT_100409f4,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x1,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf0c8 + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf1bc; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040a10,&DAT_10040a0c,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x2,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf144 + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf238; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040a28,&DAT_10040a24,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x3,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf1c0 + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf330; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040a40,&DAT_10040a3c,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x5,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf2b8 + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      for (local_10 = 0; local_10 < DAT_101cf2b4; local_10 = local_10 + 1) {
        if ((local_c == 0) ||
           (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040a58,&DAT_10040a54,0x54000000,0,0,
                                      DAT_10175558,DAT_10176860,hwnd,(HMENU)0x4,DAT_101cf334,
                                      *(LPVOID *)(&DAT_101cf23c + local_10 * 0xc)),
           local_8 == (HWND)0x0)) {
          local_c = 0;
        }
        else {
          local_c = 1;
        }
      }
      SendMessageA(hwnd,0x111,0xc9,0);
      return local_c;
    }
    if (y == 0x204) {
      local_8c.x = height & 0xffff;
      local_8c.y = height >> 0x10;
      ClientToScreen(hwnd,&local_8c);
      TrackPopupMenu(DAT_101289d0,2,local_8c.x,local_8c.y,0,hwnd,(RECT *)0x0);
      return 0;
    }
  }
  else {
    if (y == 0x466) {
      local_2c = hdc;
      thunk_FUN_1000842b(hwnd,(int)hdc);
      return 0;
    }
    if (y == 0x4c8) {
      local_20 = 1;
      local_14 = hdc;
      local_28.x = height & 0xffff;
      local_28.y = height >> 0x10;
      local_18 = (HMENU)thunk_FUN_10008085(0x10128900,7,&local_28);
      local_1c = CreateWindowExA(0,s_MAGICDECK_CardClass_10040a70,&DAT_10040a6c,0x54000000,
                                 local_28.x,local_28.y,DAT_10175558,DAT_10176860,hwnd,local_18,
                                 DAT_101cf334,local_14);
      if (local_1c == (HWND)0x0) {
        local_20 = 0;
      }
      else {
        BringWindowToTop(local_1c);
        thunk_FUN_1003947f((int)local_18,(int)local_14,1,0x101cded0);
        SendMessageA(hwnd,0x111,0xc9,0);
      }
      if ((((DAT_10040508 == 0) && (DAT_1004050c == 0)) && (DAT_10040510 == 0)) &&
         (((DAT_10040514 == 0 && (DAT_10040518 == 0)) &&
          ((DAT_1004051c == 0 && (DAT_10040520 == 0)))))) {
        return local_20;
      }
      AppendMenuA(DAT_101289d0,0,0xca,s_C_lear_trade_10040a84);
      DeleteMenu(DAT_101289d0,0xcb,0);
      DAT_10040508 = 0;
      DAT_1004050c = 0;
      DAT_10040510 = 0;
      DAT_10040514 = 0;
      DAT_10040518 = 0;
      DAT_1004051c = 0;
      DAT_10040520 = 0;
      return local_20;
    }
  }
  LVar5 = DefWindowProcA(hwnd,y,(WPARAM)hdc,height);
  return LVar5;
}


