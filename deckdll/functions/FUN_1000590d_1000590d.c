/*
 * Decompiled function: FUN_1000590d
 * Entry Point: 1000590d
 * Size: 5146 bytes
 */
#include "deckdll.h"


LRESULT FUN_1000590d(HWND hwnd,uint32_t y,HDC hdc,uint32_t height)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  LRESULT LVar5;
  tagPOINT local_94;
  HDC local_8c;
  tagPAINTSTRUCT local_88;
  HDC local_48;
  tagRECT local_44;
  HDC local_34;
  LRESULT local_30;
  POINT local_2c;
  LRESULT local_24;
  HWND local_20;
  HMENU local_1c;
  HDC local_18;
  int local_14;
  int local_10;
  int local_c;
  HWND local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8c = BeginPaint(hwnd,&local_88);
      thunk_FUN_10031425(local_8c);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_10128970,&DAT_10040998);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_10128980,s_Black_100409a0);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_10128990,&DAT_100409a8);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_101289c0,&DAT_100409b0);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_101289a0,s_Green_100409b4);
      thunk_FUN_10007dbf(local_8c,(RECT *)&DAT_101289b0,s_White_100409bc);
      EndPaint(hwnd,&local_88);
      return 0;
    }
    if (y == 1) {
      SetWindowTextA(hwnd,s_Sideboard_100408f8);
      DAT_101289d4 = CreatePopupMenu();
      AppendMenuA(DAT_101289d4,0,0xcc,s__New_deck_10040904);
      AppendMenuA(DAT_101289d4,0,0xcd,s__Load_deck_10040910);
      AppendMenuA(DAT_101289d4,0,0xce,s__Save_deck_1004091c);
      AppendMenuA(DAT_101289d4,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_101289d4,0,200,s__Consolidate_duplicate_cards_sid_10040928);
      AppendMenuA(DAT_101289d4,0,0xca,s_C_lear_Sideboard_1004094c);
      AppendMenuA(DAT_101289d4,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_101289d4,0,0xd3,s_M_inimize_10040960);
      AppendMenuA(DAT_101289d4,0,0xd1,s__Music_1004096c);
      AppendMenuA(DAT_101289d4,0,0xd2,s_Sound__Effects_10040974);
      AppendMenuA(DAT_101289d4,0,0xcf,s_E_xit_deck_builder_10040984);
      return 0;
    }
    if (y == 2) {
      DestroyMenu(DAT_101289d4);
      return 0;
    }
    if (y == 5) {
      val_3 = (int)((height & 0xffff) - 0x28) / 3;
      val_4 = (int)((height >> 0x10) - 0x1e) / 2;
      SetRect((LPRECT)&DAT_10128970,10,10,val_3 + 10,val_4 + 10);
      val_1 = val_3 + 0x14;
      SetRect((LPRECT)&DAT_10128980,val_1,10,val_1 + val_3,val_4 + 10);
      val_1 = val_1 + val_3 + 10;
      SetRect((LPRECT)&DAT_101289b0,val_1,10,val_1 + val_3,val_4 + 10);
      val_1 = val_4 + 0x14;
      SetRect((LPRECT)&DAT_10128990,10,val_1,val_3 + 10,val_1 + val_4);
      val_2 = val_3 + 0x14;
      SetRect((LPRECT)&DAT_101289a0,val_2,val_1,val_2 + val_3,val_1 + val_4);
      val_2 = val_2 + val_3 + 10;
      SetRect((LPRECT)&DAT_101289c0,val_2,val_1,val_2 + val_3,val_1 + val_4);
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
        thunk_FUN_1000862d(hwnd,0x10128970,6);
        break;
      case 0xca:
        if (((((DAT_101ced60 != 0) || (DAT_101ceddc != 0)) || (DAT_101cee58 != 0)) ||
            ((DAT_101ceed4 != 0 || (DAT_101cef50 != 0)))) || (DAT_101cefcc != 0)) {
          DAT_100404f0 = DAT_101ced60;
          DAT_100404f4 = DAT_101ceddc;
          DAT_100404f8 = DAT_101cee58;
          DAT_100404fc = DAT_101ceed4;
          DAT_10040500 = DAT_101cef50;
          DAT_10040504 = DAT_101cefcc;
          DAT_101cee58 = 0;
          DAT_101ceddc = 0;
          DAT_101ced60 = 0;
          DAT_101cefcc = 0;
          DAT_101cef50 = 0;
          DAT_101ceed4 = 0;
          DeleteMenu(DAT_101289d4,0xca,0);
          AppendMenuA(DAT_101289d4,0,0xcb,s__Restore_sideboard_100408d0);
          SendMessageA(DAT_10176850,0x401,0,0);
        }
        break;
      case 0xcb:
        DAT_101ced60 = DAT_100404f0;
        DAT_101ceddc = DAT_100404f4;
        DAT_101cee58 = DAT_100404f8;
        DAT_101ceed4 = DAT_100404fc;
        DAT_101cef50 = DAT_10040500;
        DAT_101cefcc = DAT_10040504;
        DAT_100404f8 = 0;
        DAT_100404f4 = 0;
        DAT_100404f0 = 0;
        DAT_10040504 = 0;
        DAT_10040500 = 0;
        DAT_100404fc = 0;
        AppendMenuA(DAT_101289d4,0,0xca,s_C_lear_sideboard_100408e4);
        DeleteMenu(DAT_101289d4,0xcb,0);
        SendMessageA(DAT_10176850,0x401,0,0);
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
      local_48 = hdc;
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_44);
      FillRect(local_48,&local_44,DAT_1016e4ac);
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
      CheckMenuItem(DAT_101289d4,200,(DAT_101cfa68 == 0) - 1 & 8);
      CheckMenuItem(DAT_101289d4,0xd2,(DAT_101cf542 == '\0') - 1 & 8);
      CheckMenuItem(DAT_101289d4,0xd1,(DAT_101cf541 == '\0') - 1 & 8);
      return 0;
    }
  }
  else if (y < 0x402) {
    if (y == 0x401) {
      local_c = 1;
      thunk_FUN_1000849a(hwnd);
      if (DAT_101cfa68 == 0) {
        for (local_10 = 0; local_10 < DAT_101ced60; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101cecec + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040818,&DAT_10040814,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x0,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101cece8 + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
        for (local_10 = 0; local_10 < DAT_101ceddc; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101ced68 + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040830,&DAT_1004082c,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x1,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101ced64 + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
        for (local_10 = 0; local_10 < DAT_101cee58; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101cede4 + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040848,&DAT_10040844,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x2,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101cede0 + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
        for (local_10 = 0; local_10 < DAT_101ceed4; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101cee60 + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040860,&DAT_1004085c,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x3,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101cee5c + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
        for (local_10 = 0; local_10 < DAT_101cefcc; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101cef58 + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040878,&DAT_10040874,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x5,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101cef54 + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
        for (local_10 = 0; local_10 < DAT_101cef50; local_10 = local_10 + 1) {
          for (local_14 = 0; local_14 < *(int *)(&DAT_101ceedc + local_10 * 0xc);
              local_14 = local_14 + 1) {
            if ((local_c == 0) ||
               (local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040890,&DAT_1004088c,0x54000000,
                                          0,0,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x4,DAT_101cf334
                                          ,*(LPVOID *)(&DAT_101ceed8 + local_10 * 0xc)),
               local_8 == (HWND)0x0)) {
              local_c = 0;
            }
            else {
              local_c = 1;
            }
          }
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_101ced60; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040788,&DAT_10040784,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x0,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101cece8 + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101cecec + local_10 * 0xc),0);
          }
        }
        for (local_10 = 0; local_10 < DAT_101ceddc; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100407a0,&DAT_1004079c,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x1,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101ced64 + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101ced68 + local_10 * 0xc),0);
          }
        }
        for (local_10 = 0; local_10 < DAT_101cee58; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100407b8,&DAT_100407b4,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x2,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101cede0 + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101cede4 + local_10 * 0xc),0);
          }
        }
        for (local_10 = 0; local_10 < DAT_101ceed4; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100407d0,&DAT_100407cc,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x3,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101cee5c + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101cee60 + local_10 * 0xc),0);
          }
        }
        for (local_10 = 0; local_10 < DAT_101cefcc; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_100407e8,&DAT_100407e4,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x5,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101cef54 + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101cef58 + local_10 * 0xc),0);
          }
        }
        for (local_10 = 0; local_10 < DAT_101cef50; local_10 = local_10 + 1) {
          local_8 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040800,&DAT_100407fc,0x54000000,0,0,
                                    DAT_10175558,DAT_10176860,hwnd,(HMENU)0x4,DAT_101cf334,
                                    *(LPVOID *)(&DAT_101ceed8 + local_10 * 0xc));
          if (local_8 == (HWND)0x0) {
            local_c = 0;
          }
          else {
            SendMessageA(local_8,0x401,*(WPARAM *)(&DAT_101ceedc + local_10 * 0xc),0);
          }
        }
      }
      SendMessageA(hwnd,0x111,0xc9,0);
      return local_c;
    }
    if (y == 0x204) {
      local_94.x = height & 0xffff;
      local_94.y = height >> 0x10;
      ClientToScreen(hwnd,&local_94);
      TrackPopupMenu(DAT_101289d4,2,local_94.x,local_94.y,0,hwnd,(RECT *)0x0);
      return 0;
    }
  }
  else {
    if (y == 0x466) {
      local_34 = hdc;
      thunk_FUN_1000842b(hwnd,(int)hdc);
      return 0;
    }
    if (y == 0x4c8) {
      local_24 = 1;
      local_18 = hdc;
      local_2c.x = height & 0xffff;
      local_2c.y = height >> 0x10;
      local_1c = (HMENU)thunk_FUN_10008085(0x10128970,6,&local_2c);
      if ((DAT_101cfa68 == 0) ||
         (local_20 = (HWND)thunk_FUN_100083a9(hwnd,(int)local_1c,(int)local_18),
         local_20 == (HWND)0x0)) {
        local_20 = CreateWindowExA(0,s_MAGICDECK_CardClass_100408a8,&DAT_100408a4,0x54000000,
                                   local_2c.x,local_2c.y,DAT_10175558,DAT_10176860,hwnd,local_1c,
                                   DAT_101cf334,local_18);
        if (local_20 == (HWND)0x0) {
          local_24 = 0;
        }
        else {
          BringWindowToTop(local_20);
          thunk_FUN_100392dc((int)local_1c,(int)local_18,1,0x101cded0);
          SendMessageA(hwnd,0x111,0xc9,0);
        }
      }
      else {
        thunk_FUN_100392dc((int)local_1c,(int)local_18,1,0x101cded0);
        local_30 = SendMessageA(local_20,0x402,0,0);
        SendMessageA(local_20,0x401,local_30 + 1,0);
      }
      if ((((DAT_100404f0 == 0) && (DAT_100404f4 == 0)) && (DAT_100404f8 == 0)) &&
         (((DAT_100404fc == 0 && (DAT_10040500 == 0)) && (DAT_10040504 == 0)))) {
        return local_24;
      }
      AppendMenuA(DAT_101289d4,0,0xca,s_C_lear_sideboard_100408bc);
      DeleteMenu(DAT_101289d4,0xcb,0);
      DAT_100404f0 = 0;
      DAT_100404f4 = 0;
      DAT_100404f8 = 0;
      DAT_100404fc = 0;
      DAT_10040500 = 0;
      DAT_10040504 = 0;
      return local_24;
    }
  }
  LVar5 = DefWindowProcA(hwnd,y,(WPARAM)hdc,height);
  return LVar5;
}


