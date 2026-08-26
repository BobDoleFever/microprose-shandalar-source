/*
 * Decompiled function: FUN_1002449e
 * Entry Point: 1002449e
 * Size: 10724 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HGDIOBJ FUN_1002449e(HWND hwnd,uint32_t y,HDC hdc,HWND param_4)

{
  WORD WVar1;
  UINT UVar2;
  int val_3;
  uint32_t uval_4;
  WPARAM wParam;
  HWND pHVar5;
  LRESULT LVar6;
  int val_7;
  int val_8;
  HGDIOBJ pvVar9;
  LPARAM lParam;
  int local_b48;
  tagRECT local_b2c;
  int local_b1c;
  uint32_t local_b18;
  int local_b14;
  tagRECT local_b10;
  HDC local_b00;
  uint32_t local_afc;
  int local_af8;
  tagRECT local_af4;
  tagRECT local_ae4;
  tagRECT local_ad4;
  int local_ac4;
  tagSIZE local_ac0;
  tagRECT local_ab8;
  tagRECT local_aa8;
  tagPOINT local_a98;
  HWND local_a90;
  HWND local_a8c;
  tagRECT local_a88;
  HDC local_a78;
  uint8_t local_a74 [4];
  int local_a70;
  int local_a6c;
  int local_a5c;
  int local_a58;
  tagRECT local_a54;
  COLORREF local_a44;
  HWND local_a40;
  HWND local_a3c;
  int local_a38;
  HDC local_a34;
  HWND local_a2c;
  HWND local_a28;
  HDC local_a24;
  int local_a20;
  HGDIOBJ local_a1c;
  HWND local_a18;
  HDC local_a14;
  WPARAM local_a10;
  int local_a0c;
  int local_a08;
  int local_a04;
  int local_a00 [100];
  char local_870 [2000];
  HWND local_a0;
  HWND local_9c;
  WPARAM local_98;
  WPARAM local_94;
  HDC local_90;
  HDC local_8c;
  HDC local_88;
  HWND local_84;
  HDC local_80;
  uint32_t local_7c;
  FILE *local_78;
  LONG local_74;
  int local_70;
  uint32_t local_6c;
  HDC local_68;
  char local_64 [80];
  uint32_t local_14;
  int local_10;
  int local_c;
  uint32_t local_8;
  
  if (y < 0x11) {
    if (y == 0x10) {
      if (((DAT_1017646c & 10) == 0) && ((DAT_1017646c & 4) == 0)) {
        local_70 = 0;
        local_10 = 0;
        for (local_6c = 0; (int)local_6c < DAT_101cece4; local_6c = local_6c + 1) {
          local_c = thunk_FUN_10038346(*(int *)(local_6c * 0xc + 0x101cded0));
          if (0 < local_c) {
            *(int32_t *)(&DAT_10176490 + local_70 * 0xc) =
                 *(int32_t *)(local_6c * 0xc + 0x101cded0);
            *(int *)(&DAT_10176494 + local_70 * 0xc) = local_c;
            *(int32_t *)(&DAT_10176498 + local_70 * 0xc) =
                 (&DAT_10176ab4)[*(int *)(local_6c * 0xc + 0x101cded0) * 0x26];
            local_70 = local_70 + 1;
            local_10 = 1;
          }
        }
        *(int32_t *)(&DAT_10176490 + local_70 * 0xc) = 0xffffffff;
        if (local_10 == 0) {
          DestroyWindow(DAT_10176868);
        }
        else {
          val_3 = thunk_FUN_1000b79e();
          if (val_3 != 0) {
            DestroyWindow(DAT_10176868);
          }
        }
      }
      else if ((DAT_1016a618 == 0) || (val_3 = thunk_FUN_10027871(), val_3 != 2)) {
        DestroyWindow(DAT_10176868);
      }
      return (HGDIOBJ)0x0;
    }
    switch(y) {
    case 1:
      if ((DAT_101cfb98 != 0) &&
         (DAT_10175ed8 = (int)fopen(s_CardIDs_TXT_100458e8,&DAT_100458e4),
         (FILE *)DAT_10175ed8 == (FILE *)0x0)) {
        DAT_101cfb98 = 0;
        MessageBoxA(hwnd,s_Could_not_create_CARDID_TXT_10045908,s_Deck_Builder_Error_100458f4,0x10);
      }
      _DAT_1013ea20 = 0x1000007;
      DAT_1013ea24 = 0x1000001;
      DAT_1013e944 = CreateSolidBrush(0x1000086);
      DAT_1013e948 = CreatePen(0,0,0x10000c1);
      DAT_1013e94c = CreatePen(0,0,0x1000016);
      DAT_1013e940 = 0x1000001;
      DAT_1013e950 = 0x10000bf;
      memcpy(&DAT_1013e800,&DAT_10045588,0x3c);
      _DAT_1013e800 = 0x2a;
      _DAT_1013e810 = 500;
      strcpy(&DAT_1013e81c,s_Kudos_Condensed_SSi_10045924);
      DAT_101625f4 = CreateFontIndirectA((LOGFONTA *)&DAT_1013e800);
      if ((DAT_1017646c & 1) == 0) {
        thunk_FUN_1003b2b0((int)hwnd,0,0);
      }
      thunk_FUN_100278e9();
      strcpy(&DAT_101cf340,&DAT_101cf810);
      strcat(&DAT_101cf340,s__new_dck_10045938);
      DAT_101628f0 = thunk_FUN_10034b40(s_menus_10045950,s_ARTISTNAMES_10045944);
      for (local_6c = 0; (int)local_6c < DAT_101628f0; local_6c = local_6c + 1) {
        strcpy(&DAT_101cb780 + local_6c * 100,&DAT_1016e4c0 + local_6c * 0x80);
      }
      if ((DAT_1017646c & 1) == 0) {
        sprintf(&DAT_10162630,s_New_Deck_10045964);
      }
      else {
        sprintf(local_64,s_GOLD___d_10045958,*DAT_101cfb7c);
        strncpy(&DAT_10162630,local_64,0xc);
      }
      DAT_10162730 = 0;
      DAT_1016264f = 0;
      DAT_1016271c = 1;
      strcpy(&DAT_10162664,&DAT_101cf543);
      strcpy(&DAT_101626b5,&DAT_101cf593);
      GetDateFormatA(0x800,0,(SYSTEMTIME *)0x0,s_MMMM_dd____yyyy_10045970,&DAT_10162706,0x16);
      if (((DAT_1017646c & 1) != 0) || ((DAT_1017646c & 8) != 0)) {
        thunk_FUN_10027181();
      }
      DAT_10176a9c = CreateWindowExA(0,s_MAGICDECK_TitleClass_1004598c,s_DECK_TITLE_10045980,
                                     0x56000000,0,0,0,0,hwnd,(HMENU)0x1,DAT_101cf334,(LPVOID)0x0);
      DAT_1016e4a8 = CreateWindowExA(0,s_MagicFullCardClass_100459b4,s_Full_size_card_100459a4,
                                     0x56000000,0,0,0,0,hwnd,(HMENU)0x2,DAT_101cf334,(LPVOID)0x0);
      DAT_101cf33c = CreateWindowExA(0,s_MAGICDECK_DeckSurfaceClass_100459d8,s_Deck_Surface_100459c8
                                     ,0x56800000,0,0,0,0,hwnd,(HMENU)0x7,DAT_101cf334,(LPVOID)0x0);
      DAT_101cf948 = CreateWindowExA(0,s_BUTTON_100459fc,s_Stats_100459f4,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x6,DAT_101cf334,(LPVOID)0x0);
      DAT_101cf44c = CreateWindowExA(0,s_BUTTON_10045a0c,&DAT_10045a04,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x13,DAT_101cf334,(LPVOID)0x0);
      DAT_101cde94 = CreateWindowExA(0,s_BUTTON_10045a1c,&DAT_10045a14,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x14,DAT_101cf334,(LPVOID)0x0);
      DAT_10175ed4 = CreateWindowExA(0,s_BUTTON_10045a2c,s_Deck1_10045a24,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x15,DAT_101cf334,(LPVOID)0x0);
      DAT_10175ed0 = CreateWindowExA(0,s_BUTTON_10045a3c,s_Deck2_10045a34,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x16,DAT_101cf334,(LPVOID)0x0);
      DAT_10175ec8 = CreateWindowExA(0,s_BUTTON_10045a4c,s_Deck3_10045a44,0x5600000b,0,0,0,0,hwnd,
                                     (HMENU)0x17,DAT_101cf334,(LPVOID)0x0);
      DAT_101cf538 = CreateWindowExA(0,s_LISTBOX_10045a60,s_Card_List_10045a54,0x46240152,0,0,0,0,
                                     hwnd,(HMENU)0x4,DAT_101cf334,(LPVOID)0x0);
      DAT_101cfb80 = CreateWindowExA(0,s_MAGICDECK_HorzListClass_10045a7c,
                                     s_Card_Picture_List_10045a68,0x56100000,0,0,0,0,hwnd,(HMENU)0x5
                                     ,DAT_101cf334,(LPVOID)0x0);
      DAT_101628e4 = CreateWindowExA(0,s_MAGICDECK_CardListFiltersClass_10045aa8,
                                     s_Card_List_Filters_10045a94,0x56000000,0,0,0,0,hwnd,(HMENU)0x3
                                     ,DAT_101cf334,(LPVOID)0x0);
      DAT_1013e83c = CreatePopupMenu();
      DAT_10175ec0 = CreatePopupMenu();
      if (((((DAT_10176a9c == (HWND)0x0) || (DAT_1016e4a8 == (HWND)0x0)) ||
           (DAT_101cf538 == (HWND)0x0)) ||
          ((DAT_101cfb80 == (HWND)0x0 || (DAT_101628e4 == (HWND)0x0)))) ||
         ((DAT_101cf33c == (HWND)0x0 || (DAT_1013e83c == (HMENU)0x0)))) {
        if (DAT_1013e83c != (HMENU)0x0) {
          DestroyMenu(DAT_1013e83c);
        }
        if (DAT_10175ec0 != (HMENU)0x0) {
          DestroyMenu(DAT_10175ec0);
        }
        pvVar9 = (HGDIOBJ)0xffffffff;
      }
      else {
        SendMessageA(DAT_101cf538,0x197,0,0);
        SendMessageA(DAT_101cf538,0x186,0,0);
        SendMessageA(DAT_101cfb80,0x186,0,0);
        local_a10 = SendMessageA(DAT_101cfb80,0x199,0,0);
        if ((local_a10 == 0xffffffff) && (DAT_101cf920 != 0)) {
          local_a10 = DAT_1016a620;
        }
        SendMessageA(DAT_1016e4a8,0x400,local_a10,0);
        if ((DAT_1017646c & 2) == 0) {
          if ((DAT_1017646c & 8) == 0) {
            AppendMenuA(DAT_1013e83c,0,0xfa1,s_Show__full_card_text__big_card__10045c08);
            AppendMenuA(DAT_1013e83c,0,200,s__Consolidate_duplicate_cards__de_10045c28);
            AppendMenuA(DAT_1013e83c,0x800,0,(LPCSTR)0x0);
            AppendMenuA(DAT_1013e83c,0,0xe,s__Music_10045c58);
            AppendMenuA(DAT_1013e83c,0,0xf,s_Sound__Effects_10045c60);
            AppendMenuA(DAT_1013e83c,0,0x10,s__Done_10045c70);
          }
          else {
            AppendMenuA(DAT_1013e83c,0,0xb,s__New_deck_10045b74);
            AppendMenuA(DAT_1013e83c,0,0xc,s__Load_deck_10045b80);
            AppendMenuA(DAT_1013e83c,0,0xd,s__Save_deck_10045b8c);
            AppendMenuA(DAT_1013e83c,0x800,0,(LPCSTR)0x0);
            AppendMenuA(DAT_1013e83c,0,0xfa1,s_Show__full_card_text__big_card__10045b98);
            AppendMenuA(DAT_1013e83c,0,200,s__Consolidate_duplicate_cards__de_10045bb8);
            AppendMenuA(DAT_1013e83c,0x800,0,(LPCSTR)0x0);
            AppendMenuA(DAT_1013e83c,0,0xe,s__Music_10045be8);
            AppendMenuA(DAT_1013e83c,0,0xf,s_Sound__Effects_10045bf0);
            AppendMenuA(DAT_1013e83c,0,0x10,s__Done_10045c00);
          }
        }
        else {
          AppendMenuA(DAT_1013e83c,0,0xb,s__New_deck_10045ac8);
          AppendMenuA(DAT_1013e83c,0,0xc,s__Load_deck_10045ad4);
          AppendMenuA(DAT_1013e83c,0,0xd,s__Save_deck_10045ae0);
          AppendMenuA(DAT_1013e83c,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_1013e83c,0,0xfa1,s_Show__full_card_text__big_card__10045aec);
          AppendMenuA(DAT_1013e83c,0,200,s__Consolidate_duplicate_cards__de_10045b0c);
          AppendMenuA(DAT_1013e83c,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_1013e83c,0,0x12,s_M_inimize_10045b3c);
          AppendMenuA(DAT_1013e83c,0,0xe,s__Music_10045b48);
          AppendMenuA(DAT_1013e83c,0,0xf,s_Sound__Effects_10045b50);
          AppendMenuA(DAT_1013e83c,0,0x10,s_E_xit_deck_builder_10045b60);
        }
        SetFocus(DAT_101cfb80);
        thunk_FUN_100331dc(hwnd);
        thunk_FUN_10027036();
        if ((DAT_1017646c & 1) != 0) {
          if (_DAT_10162904 == 0) {
            SetWindowTextA(DAT_10175ed4,s___Deck1___10045c78);
          }
          else if (_DAT_10162904 == 1) {
            SetWindowTextA(DAT_10175ed0,s___Deck2___10045c84);
          }
          else if (_DAT_10162904 == 2) {
            SetWindowTextA(DAT_10175ec8,s___Deck3___10045c90);
          }
        }
        pvVar9 = (HGDIOBJ)0x0;
      }
      break;
    case 2:
      if (DAT_1013e944 != (HBRUSH)0x0) {
        DeleteObject(DAT_1013e944);
      }
      if (DAT_1013e948 != (HPEN)0x0) {
        DeleteObject(DAT_1013e948);
      }
      if (DAT_1013e94c != (HPEN)0x0) {
        DeleteObject(DAT_1013e94c);
      }
      local_a1c = (HGDIOBJ)SendMessageA(DAT_10176a9c,0x31,0,0);
      SendMessageA(DAT_10176a9c,0x30,0,0);
      if (local_a1c != (HGDIOBJ)0x0) {
        DeleteObject(local_a1c);
      }
      if (DAT_101625f4 != (HFONT)0x0) {
        DeleteObject(DAT_101625f4);
      }
      DAT_101625f4 = (HFONT)0x0;
      if (DAT_1013e83c != (HMENU)0x0) {
        DestroyMenu(DAT_1013e83c);
      }
      if (DAT_10175ec0 != (HMENU)0x0) {
        DestroyMenu(DAT_10175ec0);
      }
      if (DAT_1013e954 != (HGDIOBJ)0x0) {
        DeleteObject(DAT_1013e954);
      }
      if ((DAT_1017646c & 1) == 0) {
        thunk_FUN_10027a00();
      }
      if (DAT_10175ed8 != 0) {
        fclose((FILE *)DAT_10175ed8);
        DAT_10175ed8 = 0;
      }
      PostQuitMessage(0);
      pvVar9 = (HGDIOBJ)0x0;
      break;
    default:
      goto switchD_10026ee8_caseD_3;
    case 5:
      local_afc = (uint32_t)param_4 & 0xffff;
      local_b18 = (uint32_t)param_4 >> 0x10;
      LockWindowUpdate(hwnd);
      local_b14 = 10;
      local_ac4 = (int)local_afc / 3 + -0x35;
      val_3 = local_b18 - 0x28;
      val_7 = local_b18 - 0x28;
      val_8 = local_b18 - 0x28;
      local_af8 = (int)((local_b18 - 0x28) * 6) / 100;
      local_b00 = GetDC(hwnd);
      thunk_FUN_10031425(local_b00);
      GetTextExtentPointA(local_b00,s_Load_new_deck_10045d4c,0xd,&local_ac0);
      local_ac0.cx = local_ac0.cx + 10;
      local_ac0.cy = local_ac0.cy + local_ac0.cy / 2;
      ReleaseDC(hwnd,local_b00);
      SetRect(&local_af4,8,local_b14,local_ac4 + 8,(val_8 * 10) / 100 + local_b14);
      SetRect(&local_ad4,8,local_af4.bottom + local_b14,local_ac4 + 8,
              (local_af4.bottom - local_b14) + (val_3 * 0x40) / 100 + -0xd);
      SetRect(&local_ab8,8,(local_b18 - local_b14) - (val_7 * 0x16) / 100,local_afc - 8,
              local_b18 - local_b14);
      SetRect(&local_b10,local_ab8.left,local_ab8.top - local_af8,local_ab8.right,local_ab8.top);
      SetRect(&local_b2c,(local_afc - 8) - local_ac0.cx,local_b14,local_afc - 8,
              local_b14 / 2 + local_ac0.cy * 2 + local_b14);
      SetRect(&local_aa8,local_ad4.right + 8,0,local_afc,local_ad4.bottom);
      MoveWindow(DAT_10176a9c,local_af4.left,local_af4.top,local_af4.right - local_af4.left,
                 local_af4.bottom - local_af4.top,1);
      MoveWindow(DAT_1016e4a8,local_ad4.left,local_ad4.top,local_ad4.right - local_ad4.left,
                 local_ad4.bottom - local_ad4.top,1);
      local_b1c = local_aa8.top;
      MoveWindow(DAT_101cf33c,local_aa8.left,local_aa8.top,local_aa8.right - local_aa8.left,
                 local_aa8.bottom - local_aa8.top,1);
      uval_4 = GetWindowLongA(DAT_101cfb80,-0x10);
      if ((uval_4 & 0x800000) == 0) {
        local_b48 = 0;
      }
      else {
        local_b48 = GetSystemMetrics(5);
        local_b48 = local_b48 * 2;
      }
      val_7 = local_ab8.bottom - DAT_1016e4b0;
      val_3 = GetSystemMetrics(3);
      local_b10.bottom = ((val_7 + -8) - val_3) - local_b48;
      local_b10.top = local_b10.bottom - local_af8;
      local_ab8.top = local_b10.bottom;
      MoveWindow(DAT_101628e4,local_b10.left,local_b10.top,local_b10.right - local_b10.left,
                 local_b10.bottom - local_b10.top,1);
      MoveWindow(DAT_101cfb80,local_ab8.left,local_ab8.top,local_ab8.right - local_ab8.left,
                 local_ab8.bottom - local_ab8.top,1);
      SetRect(&local_ae4,local_aa8.left,local_aa8.bottom,(local_aa8.right - local_aa8.left) / 3,
              (local_b10.top - local_aa8.bottom) + -3);
      MoveWindow(DAT_101cf948,local_ae4.left,local_ae4.top,local_ae4.right,local_ae4.bottom,1);
      MoveWindow(DAT_101cde94,local_ae4.right * 2 + local_ae4.left,local_ae4.top,local_ae4.right,
                 local_ae4.bottom,1);
      if ((DAT_1017646c & 1) == 0) {
        MoveWindow(DAT_101cf44c,local_ae4.right + local_ae4.left,local_ae4.top,local_ae4.right,
                   local_ae4.bottom,1);
      }
      else {
        MoveWindow(DAT_10175ed4,local_ae4.right + local_ae4.left,local_ae4.top,local_ae4.right / 3,
                   local_ae4.bottom,1);
        MoveWindow(DAT_10175ed0,local_ae4.right + local_ae4.right / 3 + local_ae4.left,local_ae4.top
                   ,local_ae4.right / 3,local_ae4.bottom,1);
        MoveWindow(DAT_10175ec8,local_ae4.right + (local_ae4.right * 2) / 3 + local_ae4.left,
                   local_ae4.top,local_ae4.right / 3,local_ae4.bottom,1);
      }
      SendMessageA(DAT_101cfb80,0x1a0,0,(uint32_t)(uint16_t)DAT_10176468);
      SendMessageA(DAT_101628e4,0x402,local_b10.right << 0x10 | local_b10.left & 0xffffU,
                   local_b10.bottom << 0x10 | local_b10.top & 0xffffU);
      WVar1 = GetWindowWord(DAT_101cfb80,0);
      local_8 = CONCAT22(local_8._2_2_,WVar1);
      local_74 = GetWindowLongA(DAT_101cfb80,2);
      WVar1 = GetWindowWord(DAT_101cfb80,8);
      local_14 = CONCAT22(local_14._2_2_,WVar1);
      WVar1 = GetWindowWord(DAT_101cfb80,0xc);
      local_7c = CONCAT22(local_7c._2_2_,WVar1);
      local_6c = local_14 & 0xffff;
      while( true ) {
        uval_4 = (local_7c & 0xffff) + (local_14 & 0xffff);
        if ((local_8 & 0xffff) <= uval_4) {
          uval_4 = local_8 & 0xffff;
        }
        if ((int)uval_4 <= (int)local_6c) break;
        thunk_FUN_1000d7b5(DAT_101cfb80,*(int32_t *)(local_74 + local_6c * 4));
        local_6c = local_6c + 1;
      }
      BringWindowToTop(DAT_10176a9c);
      BringWindowToTop(DAT_101628e4);
      BringWindowToTop(DAT_101cfb80);
      BringWindowToTop(DAT_101cf948);
      BringWindowToTop(DAT_101cf44c);
      BringWindowToTop(DAT_101cde94);
      LockWindowUpdate((HWND)0x0);
      if (((DAT_1017646c & 1) == 0) && (DAT_101cf541 != 0)) {
        thunk_FUN_10027adb(1,400,0);
      }
      pvVar9 = (HGDIOBJ)0x0;
      break;
    case 7:
      SetFocus(DAT_101cfb80);
      pvVar9 = (HGDIOBJ)0x0;
    }
  }
  else {
    if (y < 0x15) {
      if (y == 0x14) {
        local_a78 = hdc;
        thunk_FUN_10031425(hdc);
        local_68 = CreateCompatibleDC(local_a78);
        thunk_FUN_10031425(local_68);
        SelectObject(local_68,DAT_101cfb78);
        GetClientRect(hwnd,&local_a54);
        GetObjectA(DAT_101cfb78,0x18,local_a74);
        for (local_a58 = 0; local_a58 < local_a54.right; local_a58 = local_a58 + 0x20) {
          for (local_a5c = local_a54.bottom; -0x1d < local_a5c; local_a5c = local_a5c + -0x1d) {
            BitBlt(local_a78,local_a58,local_a5c,local_a70,local_a6c,local_68,0,0,0xcc0020);
          }
        }
        DeleteDC(local_68);
        return (HGDIOBJ)0x1;
      }
      if (y == 0x11) {
        if ((DAT_1016a618 != 0) && (val_3 = thunk_FUN_10027871(), val_3 == 2)) {
          return (HGDIOBJ)0x0;
        }
        return (HGDIOBJ)0x1;
      }
    }
    else if (y < 0x7f) {
      if (y == 0x7e) {
        if (DAT_101cf94c != hdc) {
          for (local_a20 = 0; local_a20 < DAT_10175ee0; local_a20 = local_a20 + 1) {
            thunk_FUN_10028f03(local_a20);
          }
          for (local_a20 = 0; local_a20 < DAT_10158728; local_a20 = local_a20 + 1) {
            thunk_FUN_10013cd0((&DAT_101cf600)[local_a20 * 6],0);
          }
          DAT_10158728 = 0;
        }
        DAT_101cf94c = hdc;
        SelectObject(DAT_101625e8,DAT_101cfb94);
        DeleteObject(DAT_101cf924);
        local_a24 = GetDC(hwnd);
        thunk_FUN_10031425(local_a24);
        DAT_101cf924 = CreateCompatibleBitmap
                                 (local_a24,(uint32_t)param_4 & 0xffff,(uint32_t)param_4 >> 0x10);
        ReleaseDC(hwnd,local_a24);
        SelectObject(DAT_101625e8,DAT_101cf924);
        if (DAT_101cf924 == (HBITMAP)0x0) {
          MessageBoxA(hwnd,s_Not_enough_system_memory_to_run_a_10045cb4,
                      s_Magic__The_Gathering_10045c9c,0x30);
          ShowWindow(hwnd,0);
        }
        else {
          ShowWindow(hwnd,5);
        }
        MoveWindow(hwnd,0,0,(uint32_t)param_4 & 0xffff,(uint32_t)param_4 >> 0x10,1);
        return (HGDIOBJ)0x0;
      }
      if (y == 0x2b) {
        local_a40 = param_4;
        pHVar5 = GetFocus();
        if (pHVar5 == (HWND)local_a40[5].unused) {
          local_a44 = DAT_1013e950;
        }
        else if ((local_a40[4].unused & 2) == 0) {
          local_a44 = DAT_1013e940;
        }
        else {
          local_a44 = 0x10000c6;
        }
        thunk_FUN_10032bd7((int)local_a40,DAT_1013e944,DAT_1013e948,DAT_1013e94c,local_a44,0);
        return (HGDIOBJ)0x1;
      }
      if (y == 0x2c) {
        local_a8c = param_4;
        local_a90 = GetDlgItem(hwnd,(int)hdc);
        GetClientRect(local_a90,&local_a88);
        if (local_a8c[1].unused == 4) {
          local_a8c[3].unused = local_a88.right;
          local_a8c[4].unused = (int)(local_a88.bottom + (local_a88.bottom >> 0x1f & 7U)) >> 3;
        }
        return (HGDIOBJ)0x0;
      }
    }
    else if (y < 0x117) {
      if (y == 0x116) {
        LVar6 = SendMessageA(DAT_1016e4a8,0x402,0,0);
        CheckMenuItem(DAT_1013e83c,0xfa1,(LVar6 == 0) - 1 & 8);
        CheckMenuItem(DAT_1013e83c,0xf,(DAT_101cf542 == 0) - 1 & 8);
        CheckMenuItem(DAT_1013e83c,0xe,(DAT_101cf541 == 0) - 1 & 8);
        CheckMenuItem(DAT_1013e83c,200,(DAT_101cfa68 == 0) - 1 & 8);
        return (HGDIOBJ)0x0;
      }
      if (y == 0x111) {
        uval_4 = (uint32_t)hdc & 0xffff;
        if (uval_4 < 0xb) {
          if (uval_4 == 10) {
            local_a08 = 0;
            for (local_a04 = 0; local_a04 < DAT_101cece4; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(local_a04 * 0xc + 0x101cded0),(int)local_a00,&local_a08);
            }
            for (local_a04 = 0; local_a04 < DAT_101cf048; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cefd0 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101ced60; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cece8 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf0c4; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf04c + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101ceddc; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101ced64 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf140; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf0c8 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cee58; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cede0 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf1bc; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf144 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101ceed4; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cee5c + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf238; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf1c0 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cefcc; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cef54 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf330; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf2b8 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cef50; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101ceed8 + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            for (local_a04 = 0; local_a04 < DAT_101cf2b4; local_a04 = local_a04 + 1) {
              thunk_FUN_100272be(*(int *)(&DAT_101cf23c + local_a04 * 0xc),(int)local_a00,&local_a08
                                );
            }
            local_a0c = 0;
            strcpy(local_870,s_The_following_cards_are_not_in_4_100455d8);
            for (local_a04 = 0; local_a04 < local_a08; local_a04 = local_a04 + 1) {
              val_3 = thunk_FUN_10016b40(local_a00[local_a04]);
              if (val_3 == 0) {
                strcat(local_870,(char *)(&DAT_10176ab4)[local_a00[local_a04] * 0x26]);
                strcat(local_870,&DAT_10045608);
                local_a0c = local_a0c + 1;
              }
            }
            if (local_a0c == 0) {
              MessageBoxA(hwnd,s_All_cards_are_in_4th_edition_1004564c,
                          s_Checking_deck_for_legal_cards_1004562c,0);
            }
            else {
              MessageBoxA(hwnd,local_870,s_Checking_deck_for_legal_cards_1004560c,0);
            }
          }
          else if (3 < uval_4) {
            if (uval_4 < 6) {
              local_a0 = param_4;
              if (((uint32_t)hdc & 0xffff) == 4) {
                local_9c = DAT_101cfb80;
              }
              else {
                local_9c = DAT_101cf538;
              }
              if ((uint32_t)hdc >> 0x10 == 1) {
                local_98 = SendMessageA(param_4,0x188,0,0);
                local_94 = SendMessageA(local_a0,0x199,local_98,0);
                SendMessageA(DAT_1016e4a8,0x400,local_94,0);
                local_98 = SendMessageA(local_a0,0x188,0,0);
                SendMessageA(local_9c,0x186,local_98,0);
              }
            }
            else if (uval_4 == 6) {
              DialogBoxParamA(DAT_101cf334,(LPCSTR)0xc6,DAT_10176868,(DLGPROC)&LAB_10001497,0);
            }
          }
        }
        else if (uval_4 < 0xc9) {
          if (uval_4 == 200) {
            SendMessageA(DAT_101cf33c,0x111,(WPARAM)hdc,(LPARAM)param_4);
          }
          else {
            switch(uval_4) {
            case 0xb:
              SendMessageA(DAT_101cf33c,0xcc,0,0);
              break;
            case 0xc:
              if (((DAT_1016a618 == 0) || (val_3 = thunk_FUN_10027871(), val_3 != 2)) &&
                 (val_3 = thunk_FUN_10027335(&DAT_101cf340), val_3 != 0)) {
                val_3 = thunk_FUN_1001429f(&DAT_101cf340);
                if (val_3 == 0) {
                  sprintf(local_64,s__s_dck_is_not_a_valid_deck_file__1004566c,&DAT_10162630);
                  MessageBoxA(hwnd,local_64,s_Deck_Builder_10045690,0x10);
                  sprintf(&DAT_10162630,s_New_Deck_100456a0);
                  strcpy(&DAT_101cf340,&DAT_101cf810);
                  strcat(&DAT_101cf340,s__new_dck_100456ac);
                }
                else {
                  InvalidateRect(DAT_10176a9c,(RECT *)0x0,1);
                  DAT_1016a618 = 0;
                }
              }
              break;
            case 0xd:
              val_3 = strcmp(&DAT_10162630,s_New_Deck_100456b8);
              if ((val_3 == 0) || (DAT_10162630 == '\0')) {
                MessageBoxA(hwnd,s_You_must_name_your_deck_before_s_100456d4,s_Deck_Builder_100456c4
                            ,0x40);
                thunk_FUN_1000b097();
                return (HGDIOBJ)0x2;
              }
              if (DAT_101cece0 < 0x28) {
                MessageBoxA(hwnd,s_Your_deck_must_have_at_least_40_c_1004570c,
                            s_Deck_Builder_100456fc,0x40);
                return (HGDIOBJ)0x2;
              }
              if ((500 < DAT_101cece0) || (0x50 < DAT_101cece4)) {
                MessageBoxA(hwnd,s_Your_deck_has_too_many_cards__Th_1004575c,s_Deck_Builder_1004574c
                            ,0x40);
              }
              strcpy(&DAT_101cf340,&DAT_101cf810);
              strcat(&DAT_101cf340,&DAT_100457d8);
              strcat(&DAT_101cf340,&DAT_10162630);
              strcat(&DAT_101cf340,&DAT_100457dc);
              if ((DAT_10176478 != 0) &&
                 (local_78 = fopen(&DAT_101cf340,&DAT_100457e4), local_78 != (FILE *)0x0)) {
                fclose(local_78);
                sprintf(local_64,s__s_dck_already_exists__Do_you_wi_100457e8,&DAT_10162630);
                local_6c = MessageBoxA(hwnd,local_64,s_Deck_Builder_1004581c,0x23);
                if ((local_6c == 2) || (local_6c == 7)) {
                  return (HGDIOBJ)0x2;
                }
              }
              DAT_10176478 = 0;
              DAT_1016a618 = 0;
              val_3 = thunk_FUN_10014100(&DAT_101cf340);
              if (val_3 == 0) {
                sprintf(local_64,s_There_was_an_error_opening__s_dc_10045854,&DAT_10162630);
                MessageBoxA(hwnd,local_64,s_Deck_Builder_Error_10045894,0x40);
              }
              else {
                sprintf(local_64,s__s_dck_has_been_saved__1004582c,&DAT_10162630);
                MessageBoxA(hwnd,local_64,s_Deck_Builder_10045844,0x40);
              }
              if (((DAT_1017646c & 4) != 0) || ((DAT_1017646c & 8) != 0)) {
                strcpy(DAT_10175ee4,&DAT_10162630);
              }
              return (HGDIOBJ)0x6;
            case 0xe:
              DAT_101cf541 = DAT_101cf541 ^ 1;
              if (DAT_101cf541 == 0) {
                thunk_FUN_1003b5b2(1);
              }
              else {
                thunk_FUN_10027adb(1,400,0);
              }
              break;
            case 0xf:
              DAT_101cf542 = DAT_101cf542 ^ 1;
              break;
            case 0x10:
            case 0x14:
              SendMessageA(DAT_10176868,0x10,0,0);
              break;
            case 0x11:
              break;
            case 0x12:
              SendMessageA(DAT_10176868,0x112,0xf020,0);
              break;
            case 0x13:
              thunk_FUN_1000b097();
              InvalidateRect(DAT_10176a9c,(RECT *)0x0,1);
              break;
            case 0x15:
            case 0x16:
            case 0x17:
              if ((DAT_101cdea0 & 1) != 0) {
                SetWindowTextA(DAT_10175ed4,s_Deck1_100458a8);
                SetWindowTextA(DAT_10175ed0,s_Deck2_100458b0);
                SetWindowTextA(DAT_10175ec8,s_Deck3_100458b8);
                _DAT_10162904 = ((uint32_t)hdc & 0xffff) - 0x15;
                DAT_101cece0 = 0;
                DAT_101cece4 = 0;
                for (local_6c = 0; (int)local_6c < DAT_101cf920; local_6c = local_6c + 1) {
                  if ((*(uint32_t *)(&DAT_1016a62c + local_6c * 0x10) & 1 << (DAT_10162904 & 0x1f)) == 0
                     ) {
                    *(int32_t *)(&DAT_1016a628 + local_6c * 0x10) = 1;
                  }
                  else {
                    *(int32_t *)(&DAT_1016a628 + local_6c * 0x10) = 0;
                    thunk_FUN_100391f0((&DAT_1016a620)[local_6c * 4],1,0x101cded0);
                  }
                }
                thunk_FUN_1000880b();
                SendMessageA(DAT_101cf33c,0x401,0,0);
                thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
                if (_DAT_10162904 == 0) {
                  SetWindowTextA(DAT_10175ed4,s___Deck1___100458c0);
                }
                else if (_DAT_10162904 == 1) {
                  SetWindowTextA(DAT_10175ed0,s___Deck2___100458cc);
                }
                else if (_DAT_10162904 == 2) {
                  SetWindowTextA(DAT_10175ec8,s___Deck3___100458d8);
                }
                SetFocus(DAT_101cfb80);
              }
            }
          }
        }
        else if (uval_4 == 0xfa1) {
          SendMessageA(DAT_1016e4a8,0x111,(WPARAM)hdc,(LPARAM)param_4);
        }
        else if (uval_4 == 0xfa2) {
          DAT_101cdea4 = (uint32_t)(DAT_101cdea4 == 0);
        }
        return (HGDIOBJ)0x0;
      }
    }
    else if (y < 0x205) {
      if (y == 0x204) {
        local_a98.x = (uint32_t)param_4 & 0xffff;
        local_a98.y = (uint32_t)param_4 >> 0x10;
        ClientToScreen(hwnd,&local_a98);
        TrackPopupMenu(DAT_1013e83c,2,local_a98.x,local_a98.y,0,hwnd,(RECT *)0x0);
        return (HGDIOBJ)0x0;
      }
      if (y == 0x134) {
        local_a14 = hdc;
        thunk_FUN_10031425(hdc);
        local_a18 = param_4;
        SetTextColor(local_a14,0);
        if (DAT_101cf538 != local_a18) {
          return DAT_10175f00;
        }
        return DAT_10175554;
      }
      if ((y == 0x135) || (y == 0x138)) {
        local_a34 = hdc;
        thunk_FUN_10031425(hdc);
        local_a3c = param_4;
        local_a38 = GetDlgCtrlID(param_4);
        pHVar5 = GetFocus();
        if (pHVar5 == local_a3c) {
          SetTextColor(local_a34,DAT_1013e950);
        }
        else {
          SetTextColor(local_a34,DAT_1013ea24);
        }
        SetBkMode(local_a34,1);
        pvVar9 = GetStockObject(5);
        return pvVar9;
      }
    }
    else if (y < 0x467) {
      if (y == 0x466) {
        local_80 = hdc;
        local_84 = param_4;
        if (DAT_1016e4a8 != param_4) {
          SendMessageA(DAT_1016e4a8,0x466,(WPARAM)hdc,0);
        }
        return (HGDIOBJ)0x0;
      }
      if (y == 0x30f) {
        local_90 = GetDC(hwnd);
        SelectPalette(local_90,DAT_10140990,0);
        UVar2 = RealizePalette(local_90);
        if (UVar2 != 0) {
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
        ReleaseDC(hwnd,local_90);
        return (HGDIOBJ)0x1;
      }
      if (y == 0x311) {
        local_88 = hdc;
        if ((hwnd != (HWND)hdc) && (hdc != (HDC)DAT_10176868)) {
          local_8c = GetDC(hwnd);
          SelectPalette(local_8c,DAT_10140990,1);
          UVar2 = RealizePalette(local_8c);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,0);
          }
          ReleaseDC(hwnd,local_8c);
        }
        return (HGDIOBJ)0x0;
      }
    }
    else if (y == 0x4c8) {
      local_a28 = (HWND)hdc;
      local_a2c = param_4;
      pHVar5 = GetDlgItem(hwnd,6);
      if ((((pHVar5 == local_a28) || (pHVar5 = GetDlgItem(hwnd,0x13), pHVar5 == local_a28)) ||
          ((pHVar5 = GetDlgItem(hwnd,0x14), pHVar5 == local_a28 ||
           ((pHVar5 = GetDlgItem(hwnd,0x15), pHVar5 == local_a28 ||
            (pHVar5 = GetDlgItem(hwnd,0x16), pHVar5 == local_a28)))))) ||
         (pHVar5 = GetDlgItem(hwnd,0x17), pHVar5 == local_a28)) {
        lParam = 0;
        wParam = GetDlgCtrlID(local_a28);
        SendMessageA(hwnd,0x401,wParam,lParam);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_a28 != (HWND)0x0) {
        InvalidateRect(local_a28,(RECT *)0x0,1);
      }
      if (local_a2c != (HWND)0x0) {
        InvalidateRect(local_a2c,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
switchD_10026ee8_caseD_3:
    pvVar9 = (HGDIOBJ)DefWindowProcA(hwnd,y,(WPARAM)hdc,(LPARAM)param_4);
  }
  return pvVar9;
}


