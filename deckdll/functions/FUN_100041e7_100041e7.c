/*
 * Decompiled function: FUN_100041e7
 * Entry Point: 100041e7
 * Size: 5853 bytes
 */
#include "deckdll.h"


LRESULT FUN_100041e7(HWND hwnd,uint32_t y,HDC hdc,uint32_t height)

{
  char *char_ptr_1;
  BOOL BVar2;
  HWND hWnd;
  int val_3;
  uint32_t uval_4;
  HDC pHVar5;
  LRESULT LVar6;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  tagPOINT local_a4;
  tagRECT local_9c;
  uint8_t local_8c [4];
  int local_88;
  int local_84;
  int local_74;
  int local_70;
  int local_6c;
  tagRECT local_68;
  tagRECT local_58;
  HDC local_48;
  LRESULT local_44;
  uint32_t local_40;
  uint32_t local_3c;
  LRESULT local_38;
  HWND local_34;
  HDC local_30;
  HDC local_2c;
  int local_28;
  int local_24;
  int local_20;
  HDC local_1c [4];
  HDC local_c;
  LRESULT local_8;
  
  local_8 = 1;
  if (y < 0x15) {
    if (y == 0x14) {
      local_2c = hdc;
      thunk_FUN_10031425(hdc);
      for (local_74 = 0; local_74 < 5; local_74 = local_74 + 1) {
        pHVar5 = CreateCompatibleDC(local_2c);
        local_1c[local_74] = pHVar5;
        thunk_FUN_10031425(local_1c[local_74]);
      }
      SelectObject(local_1c[0],DAT_10162600);
      SelectObject(local_1c[1],DAT_10162604);
      SelectObject(local_1c[2],DAT_1016260c);
      SelectObject(local_1c[3],DAT_10162610);
      SelectObject(local_c,DAT_10162608);
      GetClientRect(hwnd,&local_68);
      GetClientRect(hwnd,&local_9c);
      GetObjectA(DAT_10162600,0x18,local_8c);
      local_9c.right = local_68.right / 6;
      local_9c.bottom = local_68.bottom / 5;
      local_74 = 0;
      for (local_6c = 0; local_6c < local_68.right; local_6c = local_6c + local_9c.right) {
        for (local_70 = 0; local_70 < local_68.bottom; local_70 = local_70 + local_9c.bottom) {
          char_ptr_1 = &DAT_102121b0 + local_74;
          local_74 = local_74 + 1;
          StretchBlt(local_2c,local_6c,local_70,local_9c.right,local_9c.bottom,local_1c[*char_ptr_1],0,0
                     ,local_88,local_84,0xcc0020);
        }
      }
      ReleaseDC(hwnd,local_2c);
      for (local_74 = 0; local_74 < 5; local_74 = local_74 + 1) {
        DeleteDC(local_1c[local_74]);
      }
      return 1;
    }
    if (y == 1) {
      if (((DAT_1017646c & 8) != 0) || ((DAT_1017646c & 4) != 0)) {
        thunk_FUN_1000950c();
        thunk_FUN_100095ec();
      }
      for (local_20 = 0; local_20 < 0x32; local_20 = local_20 + 1) {
        uval_4 = rand();
        (&DAT_102121b0)[local_20] = (char)(((ulonglong)uval_4 & 0xffffffff000000ff) % 5);
      }
      DAT_101288f8 = CreatePopupMenu();
      if ((DAT_1017646c & 2) == 0) {
        if ((DAT_1017646c & 8) == 0) {
          if ((DAT_101cdea0 & 1) != 0) {
            AppendMenuA(DAT_101288f8,0,0xd4,s_Move_by_color__into_deck_10040700);
            AppendMenuA(DAT_101288f8,0,0xd5,s_Move_by_color_o_ut_of_deck_1004071c);
            AppendMenuA(DAT_101288f8,0x800,0,(LPCSTR)0x0);
          }
          AppendMenuA(DAT_101288f8,0,200,s__Consolidate_duplicate_cards_10040738);
          AppendMenuA(DAT_101288f8,0,0xd0,s_S_ort_deck_10040758);
          AppendMenuA(DAT_101288f8,0,0xd1,s__Music_10040764);
          AppendMenuA(DAT_101288f8,0,0xd2,s_Sound__Effects_1004076c);
          AppendMenuA(DAT_101288f8,0,0xcf,s__Done_1004077c);
        }
        else {
          AppendMenuA(DAT_101288f8,0,0xcc,s__New_deck_10040684);
          AppendMenuA(DAT_101288f8,0,0xcd,s__Load_deck_10040690);
          AppendMenuA(DAT_101288f8,0,0xce,s__Save_deck_1004069c);
          AppendMenuA(DAT_101288f8,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_101288f8,0,200,s__Consolidate_duplicate_cards_100406a8);
          AppendMenuA(DAT_101288f8,0,0xca,s_C_lear_deck_100406c8);
          AppendMenuA(DAT_101288f8,0,0xd0,s_S_ort_deck_100406d4);
          AppendMenuA(DAT_101288f8,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_101288f8,0,0xd1,s__Music_100406e0);
          AppendMenuA(DAT_101288f8,0,0xd2,s_Sound__Effects_100406e8);
          AppendMenuA(DAT_101288f8,0,0xcf,s__Done_100406f8);
        }
      }
      else {
        AppendMenuA(DAT_101288f8,0,0xcc,s__New_deck_100405f0);
        AppendMenuA(DAT_101288f8,0,0xcd,s__Load_deck_100405fc);
        AppendMenuA(DAT_101288f8,0,0xce,s__Save_deck_10040608);
        AppendMenuA(DAT_101288f8,0x800,0,(LPCSTR)0x0);
        AppendMenuA(DAT_101288f8,0,200,s__Consolidate_duplicate_cards_10040614);
        AppendMenuA(DAT_101288f8,0,0xca,s_C_lear_deck_10040634);
        AppendMenuA(DAT_101288f8,0,0xd0,s_S_ort_deck_10040640);
        AppendMenuA(DAT_101288f8,0x800,0,(LPCSTR)0x0);
        AppendMenuA(DAT_101288f8,0,0xd3,s_M_inimize_1004064c);
        AppendMenuA(DAT_101288f8,0,0xd1,s__Music_10040658);
        AppendMenuA(DAT_101288f8,0,0xd2,s_Sound__Effects_10040660);
        AppendMenuA(DAT_101288f8,0,0xcf,s_E_xit_deck_builder_10040670);
      }
      return 0;
    }
    if (y == 2) {
      DestroyMenu(DAT_101288f8);
      return 0;
    }
    if (y == 5) {
      DAT_10175558 = ((height & 0xffff) * 0x13) / 100;
      DAT_1015872c = ((height & 0xffff) * 0x13) / 100;
      DAT_10158730 = (height & 0xffff) / 7;
      DAT_10176470 = (height & 0xffff) >> 3;
      DAT_1016e4b0 = ((height & 0xffff) * 0x13) / 100;
      DAT_101628e8 = DAT_1015872c;
      DAT_10176468 = DAT_1016e4b0;
      DAT_10176860 = DAT_10175558;
      DAT_10176978 = DAT_10176470;
      DAT_101cfb84 = DAT_10158730;
      thunk_FUN_100084ce(hwnd);
      if (DAT_101cf33c != (HWND)0x0) {
        SendMessageA(DAT_101cf33c,0x401,0,0);
      }
      return 0;
    }
  }
  else if (y < 0x117) {
    if (y == 0x116) {
      CheckMenuItem(DAT_101288f8,200,(DAT_101cfa68 == 0) - 1 & 8);
      CheckMenuItem(DAT_101288f8,0xd2,(DAT_101cf542 == '\0') - 1 & 8);
      CheckMenuItem(DAT_101288f8,0xd1,(DAT_101cf541 == '\0') - 1 & 8);
      return 0;
    }
    if (y == 0x111) {
      switch((uint32_t)hdc & 0xffff) {
      case 200:
        DAT_101cfa68 = (uint32_t)(DAT_101cfa68 == 0);
        SendMessageA(DAT_101cf33c,0x401,0,0);
        SendMessageA(DAT_10176850,0x401,0,0);
        SendMessageA(DAT_101625ec,0x401,0,0);
        break;
      case 0xc9:
        GetClientRect(hwnd,&local_58);
        InflateRect(&local_58,-5,-5);
        LockWindowUpdate(DAT_10176868);
        thunk_FUN_1000852a(hwnd,&local_58.left);
        LockWindowUpdate((HWND)0x0);
        break;
      case 0xca:
        if (DAT_101cece4 != 0) {
          DAT_1016a618 = 0;
          thunk_FUN_10009244();
          thunk_FUN_1000950c();
          DAT_100404e8 = DAT_101cece4;
          DAT_100404ec = DAT_101cece0;
          DAT_101cece0 = 0;
          DAT_101cece4 = 0;
          RemoveMenu(DAT_101288f8,0xca,0);
          InsertMenuA(DAT_101288f8,0xd0,0,0xcb,s__Restore_deck_100405a0);
          SendMessageA(DAT_101cf33c,0x401,0,0);
        }
        break;
      case 0xcb:
        thunk_FUN_100093a8();
        thunk_FUN_100095ec();
        DAT_1016a618 = 1;
        DAT_101cece4 = DAT_100404e8;
        DAT_101cece0 = DAT_100404ec;
        DAT_100404ec = 0;
        DAT_100404e8 = 0;
        InsertMenuA(DAT_101288f8,0xd0,0,0xca,s_C_lear_deck_100405b0);
        DeleteMenu(DAT_101288f8,0xcb,0);
        SendMessageA(DAT_101cf33c,0x401,0,0);
        break;
      case 0xcc:
        DAT_1016271c = 1;
        DAT_101cece0 = 0;
        DAT_101cece4 = 0;
        InvalidateRect(DAT_10176a9c,(RECT *)0x0,1);
        thunk_FUN_1000950c();
        thunk_FUN_100095ec();
        BVar2 = DeleteMenu(DAT_101288f8,0xcb,0);
        if (BVar2 != 0) {
          InsertMenuA(DAT_101288f8,0xd0,0,0xca,s_C_lear_deck_100405bc);
        }
        SendMessageA(DAT_101cf33c,0x401,0,0);
        sprintf(&DAT_10162630,s_New_Deck_100405c8);
        DAT_10162730 = 0;
        DAT_1016264f = 0;
        strcpy(&DAT_10162664,&DAT_101cf543);
        strcpy(&DAT_101626b5,&DAT_101cf593);
        GetDateFormatA(0x800,0,(SYSTEMTIME *)0x0,s_MMMM_dd____yyyy_100405d4,&DAT_10162706,0x16);
        thunk_FUN_1000b097();
        break;
      case 0xcd:
        BVar2 = DeleteMenu(DAT_101288f8,0xcb,0);
        if (BVar2 != 0) {
          InsertMenuA(DAT_101288f8,0xd0,0,0xca,s_C_lear_deck_100405e4);
        }
        SendMessageA(DAT_10176868,0x111,0xc,0);
        break;
      case 0xce:
        SendMessageA(DAT_10176868,0x111,0xd,0);
        break;
      case 0xcf:
        SendMessageA(DAT_10176868,0x10,0,0);
        break;
      case 0xd0:
        SendMessageA(DAT_101cf33c,0x401,0,0);
        break;
      case 0xd1:
        SendMessageA(DAT_10176868,0x111,0xe,0);
        break;
      case 0xd2:
        SendMessageA(DAT_10176868,0x111,0xf,0);
        break;
      case 0xd3:
        SendMessageA(DAT_10176868,0x112,0xf020,0);
        lParam = 0;
        wParam = 0xf020;
        Msg = 0x112;
        hWnd = GetParent(DAT_10176868);
        SendMessageA(hWnd,Msg,wParam,lParam);
        break;
      case 0xd4:
        DAT_101cfb9c = thunk_FUN_10039c49(0);
        val_3 = thunk_FUN_1000bb7d();
        if (val_3 != 0) {
          thunk_FUN_10039fb5(1,(uint8_t)DAT_10175ecc);
          thunk_FUN_1000880b();
          SendMessageA(DAT_101cf33c,0x401,0,0);
          thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
        }
        break;
      case 0xd5:
        DAT_101cfb9c = thunk_FUN_10039c49(1);
        val_3 = thunk_FUN_1000bb7d();
        if (val_3 != 0) {
          thunk_FUN_10039fb5(0,(uint8_t)DAT_10175ecc);
          thunk_FUN_1000880b();
          SendMessageA(DAT_101cf33c,0x401,0,0);
          thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
        }
      }
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) {
      local_a4.x = height & 0xffff;
      local_a4.y = height >> 0x10;
      ClientToScreen(hwnd,&local_a4);
      TrackPopupMenu(DAT_101288f8,2,local_a4.x,local_a4.y,0,hwnd,(RECT *)0x0);
      return 0;
    }
    if (y == 0x201) {
      BringWindowToTop(hwnd);
      SetFocus(DAT_10176868);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      thunk_FUN_1000849a(hwnd);
      thunk_FUN_1003a490();
      LockWindowUpdate(DAT_10176868);
      if (DAT_101cfa68 == 0) {
        for (local_28 = 0; local_28 < 6; local_28 = local_28 + 1) {
          for (local_20 = 0; local_20 < (int)(&DAT_101c12e0)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c0e30 + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c0e30 +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
        }
        for (local_28 = 0; local_28 < 6; local_28 = local_28 + 1) {
          for (local_20 = 0; local_20 < (int)(&DAT_101c1794)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c12e4 + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c12e4 +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c1c48)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c1798 + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c1798 +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c20fc)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c1c4c + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c1c4c +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c25b0)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c2100 + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c2100 +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c2a64)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            for (local_24 = 0;
                local_24 < *(int *)(&DAT_101c25b4 + local_28 * 0x1c38 + local_20 * 4) >> 0x10;
                local_24 = local_24 + 1) {
              thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c25b4 +
                                                        local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                                 1);
            }
          }
        }
      }
      else {
        for (local_28 = 0; local_28 < 6; local_28 = local_28 + 1) {
          for (local_20 = 0; local_20 < (int)(&DAT_101c12e0)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c0e30 +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c0e30 + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
        }
        for (local_28 = 0; local_28 < 6; local_28 = local_28 + 1) {
          for (local_20 = 0; local_20 < (int)(&DAT_101c1794)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c12e4 +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c12e4 + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c1c48)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c1798 +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c1798 + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c20fc)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c1c4c +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c1c4c + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c25b0)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c2100 +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c2100 + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
          for (local_20 = 0; local_20 < (int)(&DAT_101c2a64)[local_28 * 0x70e];
              local_20 = local_20 + 1) {
            thunk_FUN_100091bd(hwnd,(LPVOID)(*(uint32_t *)(&DAT_101c25b4 +
                                                      local_28 * 0x1c38 + local_20 * 4) & 0xffff),
                               *(int *)(&DAT_101c25b4 + local_28 * 0x1c38 + local_20 * 4) >> 0x10);
          }
        }
      }
      LockWindowUpdate((HWND)0x0);
      SendMessageA(hwnd,0x111,0xc9,0);
      thunk_FUN_10027036();
      return local_8;
    }
    if (y == 0x466) {
      local_48 = hdc;
      thunk_FUN_1000842b(hwnd,(int)hdc);
      return 0;
    }
    if (y == 0x4c8) {
      local_38 = 1;
      local_30 = hdc;
      local_40 = height & 0xffff;
      local_3c = height >> 0x10;
      if ((DAT_101cfa68 == 0) ||
         (local_34 = (HWND)thunk_FUN_1000833a(hwnd,(int)hdc), local_34 == (HWND)0x0)) {
        local_34 = CreateWindowExA(0,s_MAGICDECK_CardClass_10040580,&DAT_1004057c,0x54000000,
                                   local_40,local_3c,DAT_10175558,DAT_10176860,hwnd,(HMENU)0x1,
                                   DAT_101cf334,local_30);
        if (local_34 == (HWND)0x0) {
          local_38 = 0;
        }
        else {
          BringWindowToTop(local_34);
          thunk_FUN_100391f0((int)local_30,1,0x101cded0);
          SendMessageA(hwnd,0x111,0xc9,0);
        }
      }
      else {
        thunk_FUN_100391f0((int)local_30,1,0x101cded0);
        local_44 = SendMessageA(local_34,0x402,0,0);
        SendMessageA(local_34,0x401,local_44 + 1,0);
      }
      if (DAT_100404e8 == 0) {
        return local_38;
      }
      InsertMenuA(DAT_101288f8,0xd0,0,0xca,s_C_lear_deck_10040594);
      RemoveMenu(DAT_101288f8,0xcb,0);
      DAT_100404e8 = 0;
      DAT_100404ec = 0;
      return local_38;
    }
  }
  LVar6 = DefWindowProcA(hwnd,y,(WPARAM)hdc,height);
  return LVar6;
}


