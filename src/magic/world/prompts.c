/*
 * magic/world/prompts.c - Shandalar UI - Dialog Procedures, Prompts & Window Handlers
 * Reconstructed Module containing 45 functions
 */
#include "magic.h"

/*
 * Decompiled function: UI_Register_MAGICGAME_BigCardCardClass_00401000
 * Entry Point: 00401000
 * Size: 3212 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t
UI_Register_MAGICGAME_BigCardCardClass_00401000(HWND hwnd,uint32_t y,HDC hdc,int32_t *arg_4)

{
  POINT pt;
  POINT pt_00;
  LRESULT LVar1;
  int32_t uval_2;
  HBRUSH hbr;
  int val_3;
  int val_4;
  BOOL BVar5;
  HWND pHVar6;
  uint32_t arg_1;
  size_t sVar7;
  HGDIOBJ ho;
  tagRECT *lpRect;
  char local_134 [12];
  HDC local_128;
  tagPAINTSTRUCT local_124;
  int32_t local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint32_t local_d0;
  uint32_t local_cc;
  WPARAM local_c8;
  WPARAM local_c4;
  tagRECT local_c0;
  uint32_t local_b0;
  tagRECT local_ac;
  HDC local_9c;
  tagRECT local_98;
  LRESULT local_88;
  uint32_t local_84;
  HGDIOBJ local_80;
  LOGFONTA local_7c;
  HFONT local_40;
  HANDLE local_3c;
  int local_38;
  int local_34;
  HWND local_30;
  tagRECT local_2c;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_9c = hdc;
      FUN_004f3955(hdc);
      GetClientRect(hwnd,&local_98);
      if (DAT_00536e70 == (HANDLE)0x0) {
        hbr = GetStockObject(0);
        FillRect(local_9c,&local_98,hbr);
      }
      else {
        FUN_004f3b5f((int)local_9c,(int)&local_98,DAT_00536e70);
      }
      return 1;
    }
    if (y == 0xf) {
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      UpdateWindow(pHVar6);
      local_128 = BeginPaint(hwnd,&local_124);
      if (local_128 != (HDC)0x0) {
        FUN_004f3955(local_128);
        local_dc = Ai_Subsystem_004b5cbb(*DAT_00536d88,DAT_00536d88[1]);
        arg_1 = Ai_Subsystem_004b6e3b(*DAT_00536d88,DAT_00536d88[1]);
        local_e0 = Ai_Subsystem_004cbd67(arg_1);
        if (local_dc == -1) {
          if ((((local_e0 != -1) && (local_e0 != DAT_006ff2e8)) && (local_e0 != DAT_00695e94)) &&
             (((local_e0 != DAT_0068a70c && (local_e0 != DAT_0068a694)) &&
              ((local_e0 != DAT_006a2848 &&
               ((local_e0 != DAT_006ff2dc &&
                (Palette_Subsystem_0049c7c7
                           (local_128,&DAT_00536d78,(WPARAM *)(&DAT_006b3070 + local_e0 * 0x98),0,
                            0x12,0), DAT_006808c4 != 0)))))))) {
            sprintf(local_134,s__d__d_0051604c,*DAT_00536d88,DAT_00536d88[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = strlen(local_134);
            TextOutA(local_128,DAT_00536d78 + 5,
                     DAT_00536d7c + ((DAT_00536d84 - DAT_00536d7c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = strlen(local_134);
            TextOutA(local_128,DAT_00536d78 + 4,
                     DAT_00536d7c + ((DAT_00536d84 - DAT_00536d7c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        else {
          local_e4 = FUN_00478aa4(local_dc,*DAT_00536d88,DAT_00536d88[1]);
          if (local_dc == DAT_006ff2e8) {
            Palette_Subsystem_0049c6cb(local_128,(RECT *)&DAT_00536d78);
          }
          else if ((((local_dc == DAT_00695e94) || (local_dc == DAT_0068a70c)) ||
                   (local_dc == DAT_0068a694)) || (local_dc == DAT_006a2848)) {
            Palette_Subsystem_0049eda9
                      (local_128,&DAT_00536d78,local_dc,*DAT_00536d88,DAT_00536d88[1]);
          }
          else if (local_dc == DAT_006ff2dc) {
            Palette_Subsystem_0049ebf6
                      (local_128,(RECT *)&DAT_00536d78,*DAT_00536d88,DAT_00536d88[1]);
          }
          else {
            Palette_Subsystem_0049d843
                      (local_128,&DAT_00536d78,(int)(&DAT_006b3070 + local_dc * 0x98),*DAT_00536d88,
                       DAT_00536d88[1],0x12,0);
          }
          if (DAT_006808c4 != 0) {
            sprintf(local_134,s__d__d_00516044,*DAT_00536d88,DAT_00536d88[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = strlen(local_134);
            TextOutA(local_128,DAT_00536d78 + 5,
                     DAT_00536d7c + ((DAT_00536d84 - DAT_00536d7c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = strlen(local_134);
            TextOutA(local_128,DAT_00536d78 + 4,
                     DAT_00536d7c + ((DAT_00536d84 - DAT_00536d7c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        EndPaint(hwnd,&local_124);
      }
      return 1;
    }
  }
  else if (y < 0x201) {
    if (y == 0x200) {
LAB_0040152c:
      local_d0 = (uint32_t)arg_4 & 0xffff;
      local_cc = (uint32_t)arg_4 >> 0x10;
      if (((y == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((y == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
        local_c8 = Ai_Subsystem_004b5cbb(*DAT_00536d88,DAT_00536d88[1]);
        if ((DAT_00536d88[2] == -1) || (DAT_00536d88[3] == -1)) {
          local_c4 = 0xffffffff;
        }
        else {
          local_c4 = Ai_Subsystem_004b5cbb(DAT_00536d88[2],DAT_00536d88[3]);
        }
        if ((local_c8 == 0xffffffff) ||
           (pt.y = local_cc, pt.x = local_d0, BVar5 = PtInRect((RECT *)&DAT_00536d78,pt), BVar5 == 0
           )) {
          if ((local_c4 != 0xffffffff) &&
             (pt_00.y = local_cc, pt_00.x = local_d0, BVar5 = PtInRect((RECT *)&DAT_00536d90,pt_00),
             BVar5 != 0)) {
            local_d8 = DAT_00536d88[2];
            local_d4 = DAT_00536d88[3];
            SendMessageA(DAT_0069f744,0x401,local_c4,(LPARAM)&local_d8);
          }
        }
        else {
          local_d8 = *DAT_00536d88;
          local_d4 = DAT_00536d88[1];
          SendMessageA(DAT_0069f744,0x401,local_c8,(LPARAM)&local_d8);
        }
      }
      return 0;
    }
    if (y == 0x110) {
      _DAT_00536da0 = 0;
      if (g_AiTurnDecisionFlag != 0) {
        SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
      }
      lpRect = &local_2c;
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      GetWindowRect(pHVar6,lpRect);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
      GetClientRect(hwnd,&player_idx);
      color_idx = local_2c.top;
      target_idx = player_idx.right - local_2c.right;
      InflateRect(&player_idx,-local_2c.top,-target_idx);
      CopyRect((LPRECT)&DAT_00536d78,&player_idx);
      _DAT_00536d80 = local_2c.left - color_idx;
      CopyRect((LPRECT)&DAT_00536d90,&player_idx);
      DAT_00536d90 = local_2c.left;
      g_DialogPromptTemplate = local_2c.bottom;
      if (DAT_00536d9c - local_2c.bottom < DAT_00536d98 - local_2c.left) {
        DAT_00536d98 = (DAT_00536d9c - local_2c.bottom) + local_2c.left;
      }
      else {
        DAT_00536d9c = (DAT_00536d98 - local_2c.left) + local_2c.bottom;
      }
      DAT_00536d88 = arg_4;
      SetDlgItemTextA(hwnd,0x3f1,(LPCSTR)arg_4[4]);
      SendDlgItemMessageA(hwnd,0x3f1,0x401,DAT_00536d88[5],0);
      if (DAT_00536d88[2] != -1) {
        local_38 = DAT_00536d88[2];
        local_34 = DAT_00536d88[3];
        local_30 = CreateWindowExA(0,s_MAGICGAME_BigCardCardClass_00516028,
                                   s_BigCard_small_card_00516014,0x50000000,DAT_00536d90,
                                   g_DialogPromptTemplate,g_PlayerGoldCoins,g_PlayerAmuletGems,hwnd,(HMENU)0x1,
                                   g_AppHInstance,&local_38);
      }
      local_3c = (HANDLE)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
      GetObjectA(local_3c,0x3c,&local_7c);
      local_7c.lfWeight = 700;
      local_40 = CreateFontIndirectA(&local_7c);
      SendDlgItemMessageA(hwnd,0x3f1,0x30,(WPARAM)local_40,0);
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      SetFocus(pHVar6);
      LVar1 = SendDlgItemMessageA(hwnd,0x3f1,0x400,0,0);
      if ((LVar1 == 0) || (DAT_00536d88[5] == 0)) {
        SetTimer(hwnd,1,DAT_00696900,(TIMERPROC)0x0);
      }
      return 0;
    }
    if (y == 0x111) {
      if ((((uint32_t)arg_4 & 0xffff) == 1) || (((uint32_t)arg_4 & 0xffff) == 2)) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      else if (((uint32_t)hdc & 0xffff) == 0x3f1) {
        local_84 = (uint32_t)hdc >> 0x10;
        local_88 = SendDlgItemMessageA(hwnd,0x3f1,0x400,0,0);
        if (local_84 == 0) {
          if ((local_88 == 0) || (DAT_00536d88[5] == 0)) {
            local_80 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
            SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
            DeleteObject(local_80);
            EndDialog(hwnd,local_84);
          }
        }
        else {
          local_80 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
          SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
          DeleteObject(local_80);
          EndDialog(hwnd,local_84);
        }
      }
      return 1;
    }
    if (y == 0x113) {
      ho = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
      SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
      DeleteObject(ho);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_0040152c;
    if (y == 0x201) {
      GetWindowRect(hwnd,&local_c0);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_ac);
      val_3 = abs(local_c0.top - local_ac.top);
      val_4 = abs(local_c0.left - local_ac.left);
      local_b0 = (uint32_t)(4 < val_3 + val_4);
      if (local_b0 == 0) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      return 1;
    }
  }
  else if ((0x30e < y) && (y < 0x312)) {
    uval_2 = FUN_004f5d1a(hwnd,y,(HWND)hdc,arg_4);
    return uval_2;
  }
  return 0;
}

/*
 * Decompiled function: UI_RegisterSmallCardClass
 * Entry Point: 00401c91
 * Size: 146 bytes
 */


bool UI_RegisterSmallCardClass(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_00401d2e;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}

/*
 * Decompiled function: UI_WndProc_00401d2e
 * Entry Point: 00401d2e
 * Size: 306 bytes
 */


LRESULT UI_WndProc_00401d2e(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam)

{
  HWND pHVar1;
  uint32_t lParam_00;
  LRESULT LVar2;
  tagPOINT *lpPoints;
  UINT cPoints;
  tagPOINT match_count;
  
  if (uMsg < 0x10) {
    if ((uMsg == 0xf) || ((uMsg != 0 && (uMsg < 3)))) goto LAB_00401d42;
  }
  else if (uMsg < 0x203) {
    if (0x200 < uMsg) {
      match_count.x = lParam & 0xffff;
      match_count.y = lParam >> 0x10;
      cPoints = 1;
      lpPoints = &match_count;
      pHVar1 = GetParent(hwnd);
      MapWindowPoints(hwnd,pHVar1,lpPoints,cPoints);
      lParam_00 = match_count.y << 0x10 | match_count.x & 0xffffU;
      pHVar1 = GetParent(hwnd);
      SendMessageA(pHVar1,uMsg,wParam,lParam_00);
      return 0;
    }
    if (uMsg == 0x14) {
LAB_00401d42:
      LVar2 = CallWindowProcA(Card_Setup_00467a68,hwnd,uMsg,wParam,lParam);
      return LVar2;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) goto LAB_00401d42;
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar2;
}

/*
 * Decompiled function: UI_Register_WINBK_BigCard_00401e65
 * Entry Point: 00401e65
 * Size: 219 bytes
 */


int32_t UI_Register_WINBK_BigCard_00401e65(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_CardListWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_BigCard_pic_00516054);
  DAT_00536e70 = Pic_LoadKimPicture(local_138);
  DAT_00696900 = 9000;
  return local_30;
}

/*
 * Decompiled function: UI_CardListWndProc
 * Entry Point: 00401f70
 * Size: 4340 bytes
 */


LRESULT UI_CardListWndProc(HWND hwnd,uint32_t uMsg,WPARAM wParam,LONG *lParam)

{
  bool flag_1;
  char *char_ptr_2;
  SHORT SVar3;
  HWND pHVar4;
  LONG LVar5;
  HWND pHVar6;
  int val_7;
  int val_8;
  HBRUSH hbr;
  WPARAM WVar9;
  size_t sVar10;
  uint32_t uVar11;
  LRESULT LVar12;
  UINT UVar13;
  tagRECT *ptVar14;
  LPARAM lParam_00;
  tagSIZE *lpsz;
  uint32_t local_394;
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
  uint32_t local_94;
  uint32_t local_90;
  HDC local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint32_t local_7c;
  tagTEXTMETRICA local_78;
  tagRECT local_40;
  tagRECT local_30;
  int loop_idx;
  int color_idx;
  int target_idx;
  LONG player_idx;
  WPARAM card_idx;
  HGDIOBJ match_count;
  char *slot_idx;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      local_384 = lParam;
      local_38c = 0;
      flag_1 = false;
      while (((char)*local_384 != '\0' && (!flag_1))) {
        if (((char)*local_384 == ' ') || ((char)*local_384 == '>')) {
          (&DAT_00536da8)[local_38c] = 0;
          flag_1 = true;
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
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      target_idx = 0;
      player_idx = -1;
      if ((char)*local_384 != '\0') {
        local_38c = 0;
        while ((char)*local_384 != '\0') {
          for (; (char)*local_384 == ' '; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          if ((char)*local_384 == '>') {
            player_idx = target_idx;
            local_384 = (LONG *)((int)local_384 + 1);
          }
          for (; (char)*local_384 == '\n'; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          for (; ((char)*local_384 != '\0' && ((char)*local_384 != '\n'));
              local_384 = (LONG *)((int)local_384 + 1)) {
            *(char *)(local_38c + (int)slot_idx) = (char)*local_384;
            local_38c = local_38c + 1;
          }
          *(uint8_t *)(local_38c + (int)slot_idx) = 0;
          local_38c = local_38c + 1;
          if ((char)*local_384 != '\0') {
            local_384 = (LONG *)((int)local_384 + 1);
          }
          target_idx = target_idx + 1;
        }
        *(uint8_t *)(local_38c + (int)slot_idx) = 0;
      }
      if ((target_idx != 0) && (player_idx == -1)) {
        player_idx = 0;
      }
      local_394 = 0;
      for (local_38c = 0; local_38c < target_idx; local_38c = local_38c + 1) {
        uVar11 = FUN_00403189(hwnd,local_38c);
        local_394 = local_394 | uVar11;
      }
      if (local_394 == 0) {
        card_idx = 0;
        SetWindowLongA(hwnd,0x10,0);
      }
      SetWindowLongA(hwnd,8,target_idx);
      SetWindowLongA(hwnd,4,(LONG)slot_idx);
      SetWindowLongA(hwnd,0xc,player_idx);
      return LVar12;
    }
    if (uMsg == 1) {
      match_count = (HGDIOBJ)0x0;
      SetWindowLongA(hwnd,0,0);
      slot_idx = malloc(1000);
      target_idx = 0;
      player_idx = -1;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)slot_idx);
      SetWindowLongA(hwnd,0xc,player_idx);
      card_idx = *lParam;
      SetWindowLongA(hwnd,0x10,card_idx);
      color_idx = lParam[9];
      if (color_idx != 0) {
        PostMessageA(hwnd,0xc,0,color_idx);
      }
      return 0;
    }
    if (uMsg == 2) {
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      if (slot_idx != (void *)0x0) {
        free(slot_idx);
      }
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      return 1;
    }
    if (uMsg == 0xf) {
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,0);
      target_idx = GetWindowLongA(hwnd,8);
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = GetWindowLongA(hwnd,0x10);
      GetWindowTextA(hwnd,local_304,500);
      local_c0 = slot_idx;
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
        SelectObject(local_364,match_count);
        SetTextColor(local_364,local_c4);
        OffsetRect(&local_d4,1,1);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        OffsetRect(&local_d4,-1,-1);
        SetTextColor(local_364,local_314);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        local_bc = DrawTextA(local_364,local_304,-1,&local_d4,0x410);
        if (target_idx != 0) {
          local_31c = local_d4.top + local_bc + 0x14;
          GetTextMetricsA(local_364,&local_110);
          local_360 = local_110.tmExternalLeading + (local_110.tmHeight * 10) / 100 +
                      local_110.tmHeight;
          SetBkMode(local_364,1);
          for (local_318 = 0; local_318 < target_idx; local_318 = local_318 + 1) {
            val_8 = FUN_00403189(hwnd,local_318);
            char_ptr_2 = local_c0;
            if ((val_8 == 0) && (char_ptr_2 = local_c0 + 1, local_c0[1] == ' ')) {
              char_ptr_2 = local_c0 + 2;
            }
            local_c0 = char_ptr_2;
            if (card_idx == 0) {
              if (local_318 == player_idx) {
                lpsz = &local_370;
                sVar10 = strlen(local_c0);
                GetTextExtentPointA(local_364,local_c0,sVar10,lpsz);
                SetRect(&local_380,local_d4.left + -5,local_31c,local_d4.left + local_370.cx + 5,
                        local_31c + local_360);
                hbr = GetStockObject(0);
                FillRect(local_364,&local_380,hbr);
              }
              val_8 = FUN_00403189(hwnd,local_318);
              if (val_8 == 0) {
                local_368 = local_d8;
              }
              else {
                local_368 = local_30c;
              }
            }
            else {
              val_8 = FUN_00403189(hwnd,local_318);
              if (val_8 == 0) {
                local_368 = local_d8;
              }
              else if (local_318 == player_idx) {
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
        if (target_idx != 0) {
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
        match_count = (HGDIOBJ)wParam;
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
      target_idx = GetWindowLongA(hwnd,8);
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,0);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = GetWindowLongA(hwnd,0x10);
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
        val_8 = abs(local_b8.left - local_40.left);
        val_7 = abs(local_b8.top - local_40.top);
        local_7c = (uint32_t)(4 < val_8 + val_7);
      }
      else {
        local_7c = 0;
      }
      if (local_7c == 0) {
        local_88 = player_idx + 1;
        if (card_idx == 0) {
          if (uMsg == 0x202) {
            pHVar6 = hwnd;
            uVar11 = GetDlgCtrlID(hwnd);
            uVar11 = uVar11 & 0xffff | local_88 << 0x10;
            UVar13 = 0x111;
            pHVar4 = GetParent(hwnd);
            SendMessageA(pHVar4,UVar13,uVar11,(LPARAM)pHVar6);
          }
        }
        else if (target_idx < 1) {
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
          local_94 = (uint32_t)lParam & 0xffff;
          local_90 = (uint32_t)lParam >> 0x10;
          local_8c = GetDC(hwnd);
          FUN_004f3955(local_8c);
          SelectObject(local_8c,match_count);
          GetTextMetricsA(local_8c,&local_78);
          local_a8 = local_78.tmExternalLeading + local_78.tmHeight;
          ReleaseDC(hwnd,local_8c);
          local_88 = 0;
          GetClientRect(hwnd,&local_30);
          local_80 = local_30.bottom - local_a8;
          local_84 = target_idx;
          while ((0 < local_84 && (local_88 == 0))) {
            if (local_80 < (int)local_90) {
              local_88 = local_84;
              SetRect(&local_a4,0,local_80,local_30.right,local_80 + local_a8);
            }
            local_80 = local_80 - local_a8;
            local_84 = local_84 + -1;
          }
          val_8 = FUN_00403189(hwnd,local_88 + -1);
          if (val_8 != 0) {
            player_idx = local_88 + -1;
            SetWindowLongA(hwnd,0xc,player_idx);
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
      target_idx = GetWindowLongA(hwnd,8);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = GetWindowLongA(hwnd,0x10);
      if (card_idx != 0) {
        if ((wParam == 0xd) || (wParam == 0x20)) {
          loop_idx = player_idx + 1;
          pHVar6 = hwnd;
          uVar11 = GetDlgCtrlID(hwnd);
          uVar11 = uVar11 & 0xffff | loop_idx << 0x10;
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
            player_idx = target_idx;
            do {
              player_idx = player_idx + -1;
              val_8 = FUN_00403189(hwnd,player_idx);
            } while (val_8 == 0);
            break;
          case 0x24:
            player_idx = 0;
            while (val_8 = FUN_00403189(hwnd,player_idx), val_8 == 0) {
              player_idx = player_idx + 1;
            }
            break;
          case 0x26:
            player_idx = player_idx + -1;
            if (player_idx < 0) {
              player_idx = target_idx + -1;
            }
            while (val_8 = FUN_00403189(hwnd,player_idx), val_8 == 0) {
              player_idx = player_idx + -1;
              if (player_idx < 0) {
                player_idx = target_idx + -1;
              }
            }
            break;
          case 0x28:
            player_idx = player_idx + 1;
            if (target_idx + -1 < player_idx) {
              player_idx = 0;
            }
            while (val_8 = FUN_00403189(hwnd,player_idx), val_8 == 0) {
              player_idx = player_idx + 1;
              if (target_idx + -1 < player_idx) {
                player_idx = 0;
              }
            }
          }
          SetWindowLongA(hwnd,0xc,player_idx);
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
      card_idx = wParam;
      SetWindowLongA(hwnd,0x10,wParam);
      return 0;
    }
  }
  LVar12 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar12;
}

/*
 * Decompiled function: UI_RegisterCueCardClass
 * Entry Point: 004081b0
 * Size: 289 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_RegisterCueCardClass(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  bool flag_2;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_CueCardWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  flag_2 = AVar1 != 0;
  DAT_006b2d8c = 0;
  DAT_006a2850 = 500;
  _DAT_007006b8 = 10;
  _DAT_006a4a4c = 0x12;
  DAT_00695f10 = 0x14;
  lplf = (LOGFONTA *)FUN_004f58eb(s_CueCard_00516bf0,0);
  DAT_005382dc = CreateFontIndirectA(lplf);
  DAT_005382e8 = CreateSolidBrush(0x296bed2);
  DAT_005382e4 = CreateSolidBrush(0x27f7f7f);
  DAT_005382e0 = 0x2505050;
  if ((DAT_005382e8 == (HBRUSH)0x0) || (DAT_005382e4 == (HBRUSH)0x0)) {
    flag_2 = false;
  }
  return flag_2;
}

/*
 * Decompiled function: UI_CueCardWndProc
 * Entry Point: 0040836a
 * Size: 1111 bytes
 */


LRESULT UI_CueCardWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,LPSTR lParam)

{
  int c;
  LONG LVar1;
  HWND hWnd;
  LRESULT LVar2;
  tagSIZE *psizl;
  uint32_t local_104;
  CHAR local_100 [100];
  HDC local_9c;
  tagPAINTSTRUCT local_98;
  tagRECT local_58;
  tagRECT local_48;
  uint32_t local_38;
  LPSTR local_34;
  int local_30;
  HDC local_2c;
  int local_28;
  uint32_t local_24;
  uint32_t loop_idx;
  int color_idx;
  LPSTR target_idx;
  tagSIZE player_idx;
  int match_count;
  HGDIOBJ slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_9c = BeginPaint(hwnd,&local_98);
      if (local_9c != (HDC)0x0) {
        FUN_004f3955(local_9c);
        GetClientRect(hwnd,&local_48);
        SetRect(&local_58,local_48.left,local_48.top,local_48.right + -2,local_48.bottom + -2);
        FillRect(local_9c,&local_48,DAT_005382e4);
        FillRect(local_9c,&local_58,DAT_005382e8);
        SetTextColor(local_9c,DAT_005382e0);
        SetBkMode(local_9c,1);
        GetWindowTextA(hwnd,local_100,100);
        SelectObject(local_9c,slot_idx);
        DrawTextA(local_9c,local_100,-1,&local_58,0x25);
        EndPaint(hwnd,&local_98);
      }
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = (HGDIOBJ)DAT_005382dc;
      SetWindowLongA(hwnd,0,DAT_005382dc);
      return 0;
    }
  }
  else if (uMsg < 0x31) {
    if (uMsg == 0x30) {
      local_104 = wParam;
      if (wParam == 0) {
        local_104 = DAT_005382dc;
      }
      SetWindowLongA(hwnd,0,local_104);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      SetFocus(g_MainAppHwnd);
      hWnd = GetFocus();
      PostMessageA(hWnd,uMsg,wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x31) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
  }
  else {
    switch(uMsg) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar2 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar2;
    case 0x400:
      slot_idx = (HGDIOBJ)GetWindowLongA(hwnd,0);
      loop_idx = wParam & 0xffff;
      local_24 = wParam >> 0x10;
      target_idx = lParam;
      local_2c = GetDC(hwnd);
      if (local_2c != (HDC)0x0) {
        FUN_004f3955(local_2c);
        SelectObject(local_2c,slot_idx);
        psizl = &player_idx;
        c = lstrlenA(target_idx);
        GetTextExtentPoint32A(local_2c,target_idx,c,psizl);
        local_28 = player_idx.cx + 10;
        local_30 = player_idx.cy + 6;
        ReleaseDC(hwnd,local_2c);
        color_idx = GetSystemMetrics(0);
        match_count = GetSystemMetrics(1);
        if ((int)loop_idx < 1) {
          loop_idx = 1;
        }
        if (color_idx + -1 < (int)(local_28 + loop_idx)) {
          loop_idx = (color_idx + -1) - local_28;
        }
        if ((int)local_24 < 1) {
          local_24 = 1;
        }
        if (match_count + -1 < (int)(local_30 + local_24)) {
          local_24 = (match_count + -1) - local_30;
        }
        MoveWindow(hwnd,loop_idx,local_24,local_28,local_30,1);
        SetWindowTextA(hwnd,target_idx);
        ShowWindow(hwnd,5);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    case 0x401:
      local_34 = lParam;
      local_38 = wParam;
      GetWindowTextA(hwnd,lParam,wParam);
      return 0;
    }
  }
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar2;
}

/*
 * Decompiled function: UI_Register_FACE_BLACK_00408e20
 * Entry Point: 00408e20
 * Size: 562 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t UI_Register_FACE_BLACK_00408e20(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_DuelArenaMenuProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00538308 = CreatePopupMenu();
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_MULTI_pic_00516bf8);
  _DAT_00538310 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_BLACK_pic_00516c08);
  _DAT_00538314 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_BLUE_pic_00516c18);
  _DAT_00538318 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_GREEN_pic_00516c28);
  _DAT_0053831c = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_RED_pic_00516c38);
  _DAT_00538320 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__FACE_WHITE_pic_00516c48);
  _DAT_00538324 = Pic_LoadKimPicture(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00516c58,0);
  DAT_0053830c = CreateFontIndirectA(lplf);
  DAT_005382f0 = 0x2f6f7f7;
  DAT_005382f4 = 0x2565656;
  return local_30;
}

/*
 * Decompiled function: UI_DuelArenaMenuProc
 * Entry Point: 004090f6
 * Size: 1750 bytes
 */


LRESULT UI_DuelArenaMenuProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  LONG LVar1;
  uint32_t uval_2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int val_3;
  LRESULT LVar4;
  int local_278;
  char local_274 [100];
  uint32_t local_210;
  char local_20c [100];
  tagPOINT local_1a8;
  tagRECT local_1a0;
  HDC local_190;
  tagPAINTSTRUCT local_18c;
  tagRECT local_14c;
  tagMSG local_13c;
  uint32_t local_120;
  char local_11c [264];
  ULONG_PTR player_idx;
  uint32_t card_idx;
  HANDLE match_count;
  uint32_t slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = (HANDLE)GetWindowLongA(hwnd,0);
      local_190 = BeginPaint(hwnd,&local_18c);
      if (local_190 != (HDC)0x0) {
        FUN_004f3955(local_190);
        GetClientRect(hwnd,&local_14c);
        if (match_count == (HANDLE)0x0) {
          hbr = GetStockObject(4);
          FillRect(local_190,&local_14c,hbr);
        }
        else {
          UI_RenderDuelStatusBanner(local_190,&local_14c,(uint32_t)(hwnd != DAT_0068a620));
        }
        EndPaint(hwnd,&local_18c);
      }
      return 0;
    }
    if (uMsg == 1) {
      match_count = (HANDLE)0x0;
      SetWindowLongA(hwnd,0,0);
      slot_idx = 0;
      SetWindowLongA(hwnd,4,0);
      return 0;
    }
    if (uMsg == 2) {
      match_count = (HANDLE)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      if ((match_count != (HANDLE)0x0) && (slot_idx == 0)) {
        Pic_DestroyDIBSection(match_count);
      }
      return 0;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uval_2 = wParam & 0xffff;
      if (uval_2 == 100) {
        UI_ShowDuelArenaWindow((uint32_t)(hwnd != DAT_0068a620),0);
      }
      else if (uval_2 == 0x65) {
        player_idx = 0xbdf;
        strcpy(local_11c,&g_GameInstallDirectory);
        strcat(local_11c,s__duel_hlp_00516c60);
        WinHelpA(g_MainAppHwnd,local_11c,1,player_idx);
      }
      else if (uval_2 == 0x66) {
        card_idx = (uint32_t)(hwnd != DAT_0068a620);
        g_AiTemporaryCardState = 0;
        UI_PostDuelArenaMessage(card_idx);
      }
      return 0;
    }
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_278 = GetMenuItemCount(DAT_00538308);
        while (local_278 != 0) {
          DeleteMenu(DAT_00538308,0,0x400);
          local_278 = local_278 + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      local_210 = (uint32_t)(hwnd != DAT_006b2530);
      if ((DAT_006b1578 != 0) && (val_3 = FUN_00409cb2(local_210), val_3 != 0)) {
        if (local_210 == 1) {
          Ai_Subsystem_004b6f49(local_20c);
          sprintf(local_274,s_Target__s_00516c6c,local_20c);
        }
        else {
          strcpy(local_274,s_Target_yourself_00516c78);
        }
        AppendMenuA(DAT_00538308,0,0x66,local_274);
      }
      val_3 = GetMenuItemCount(DAT_00538308);
      if (0 < val_3) {
        AppendMenuA(DAT_00538308,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00538308,0,100,s_Flip_back_to_lifepoints_00516c88);
      AppendMenuA(DAT_00538308,0,0x65,s_Help____00516ca0);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_1a8.x = lParam & 0xffff;
      local_1a8.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_1a8);
      SetRect(&local_1a0,local_1a8.x,local_1a8.y,local_1a8.x + 1,local_1a8.y + 1);
      TrackPopupMenu(DAT_00538308,2,local_1a8.x,local_1a8.y,0,hwnd,&local_1a0);
      return 0;
    }
    if (uMsg == 0x201) {
      local_120 = (uint32_t)(hwnd != DAT_0068a620);
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        g_AiTemporaryCardState = PeekMessageA(&local_13c,hwnd,0x203,0x203,0);
        UI_PostDuelArenaMessage(local_120);
      }
      return 0;
    }
  }
  else if (uMsg < 0x439) {
    if (uMsg == 0x438) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      LVar4 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg == 0x439) {
    match_count = (HANDLE)GetWindowLongA(hwnd,0);
    slot_idx = GetWindowLongA(hwnd,4);
    if ((match_count != (HANDLE)0x0) && (slot_idx == 0)) {
      Pic_DestroyDIBSection(match_count);
    }
    match_count = (HANDLE)wParam;
    slot_idx = lParam;
    SetWindowLongA(hwnd,0,wParam);
    SetWindowLongA(hwnd,4,slot_idx);
    InvalidateRect(hwnd,(RECT *)0x0,0);
    return 0;
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}

/*
 * Decompiled function: Prompts_Load_00414d99
 * Entry Point: 00414d99
 * Size: 448 bytes
 */


int32_t Prompts_Load_00414d99(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int card_idx;
  int32_t match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005197dc,s_MANASHORT_005197d0);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&card_idx);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      Glue_Subsystem_004e65e1(FUN_00414f59,val_2);
      for (slot_idx = 0; slot_idx < 8; slot_idx = slot_idx + 1) {
        *(int32_t *)(&g_AiLookaheadDepth + slot_idx * 4 + val_2 * 0x20) = 0;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_004150fe
 * Entry Point: 004150fe
 * Size: 412 bytes
 */


int32_t Prompts_Load_004150fe(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int card_idx;
  int32_t match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005197fc,s_ANCESTRAL_RECALL_005197e8);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&card_idx);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      Magic_ExecuteDrawPhase(slot_idx);
      Magic_ExecuteDrawPhase(slot_idx);
      Magic_ExecuteDrawPhase(slot_idx);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,2);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_0041529a
 * Entry Point: 0041529a
 * Size: 637 bytes
 */


int32_t Prompts_Load_0041529a(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uval_1,arg_11_00,
                         arg_12_00,arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,
                         arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519814,s_SIMULACRUM_00519808);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&DAT_006b3030 + spell_id * 4);
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,2
                         ,0,0,arg_11,arg_12,arg_13,val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_PlayerCreatureCount)[spell_id] =
             (&g_PlayerCreatureCount)[spell_id] +
             *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        FUN_0041db67(val_2,color_mask,
                     *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                     ,spell_id,target_id);
        *(int32_t *)(&DAT_006b3030 + spell_id * 4) = 0;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&DAT_006b3030 + spell_id * 4);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00415517
 * Entry Point: 00415517
 * Size: 434 bytes
 */


int32_t Prompts_Load_00415517(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  int val_3;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,0,0,0,0xffffffff,0xffffffff,
                         0xffffffff,0xffffffff,0,0,0);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519828,s_SHATTER_00519820);
      val_2 = Glue_Subsystem_004e70ad(spell_id,1 - spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x10;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(val_2,color_mask,1);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_004156c9
 * Entry Point: 004156c9
 * Size: 599 bytes
 */


int32_t Prompts_Load_004156c9(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint8_t *arg_18;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x44,0,0,0,0,0,0xffffffff,0xffffffff,
                         0xffffffff,0xffffffff,0,0,0);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x10;
      Pic_Subsystem_00424500(s_prompts_txt_00519840,s_DISENCHANT_00519834);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0x44,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9
                         ,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,0x44,0,0,uval_2,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00415920
 * Entry Point: 00415920
 * Size: 1064 bytes
 */


int32_t Prompts_Load_00415920(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x43,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      Pic_Subsystem_00424500(s_prompts_txt_00519854,s_TWIDDLE_0051984c);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0x43,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9
                         ,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
          uval_1 = Ai_Subsystem_004cc56d
                            (spell_id,spell_id,target_id,match_count,slot_idx,s_Tap__Untap__00519860,
                             (*(uint32_t *)(&g_CardSlot_Flags + slot_idx * 0x120 + match_count * 0x5b20) &
                             0x10) >> 4);
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               uval_1;
        }
        else {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_ConvertedManaCost + g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20);
        }
        if (g_ActivePlayerPriority == spell_id) {
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) * 0x34] & 1) != 0)
          {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
          if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
               ) && (match_count == g_ActivePlayerPriority)) ||
             ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 1
              && (match_count == g_CurrentTurnPhase)))) {
            g_SpellStackDepth = g_SpellStackDepth + -0x60;
          }
        }
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,0x43,0,0,uval_2,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
      {
        FUN_00415d48(match_count,slot_idx);
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) & 0xffffffef;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00415df8
 * Entry Point: 00415df8
 * Size: 609 bytes
 */


int32_t Prompts_Load_00415df8(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 1;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519878,s_TUNNEL_00519870);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,1);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00416222
 * Entry Point: 00416222
 * Size: 777 bytes
 */


int32_t Prompts_Load_00416222(int spell_id,int target_id,int flags)

{
  int color_mask;
  int val_1;
  int32_t uval_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (val_1 = FUN_0040d949(spell_id,7,2), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      Ai_GetOpponentPlayerScore(0);
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      uval_2 = FUN_00403250((int *)0x0,0,spell_id,2,spell_id,0x200,2,0,0,uval_2,arg_11_00,arg_12_00,
                           arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519898,s_HOWL_FROM_BEYOND_00519884);
      val_1 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth + (((g_ScWillyScore < 0x15) - 1 & 0xfffffffe) * 3 + 9) * -4;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        if ((g_ActivePlayerPriority == spell_id) &&
           (((&g_CardSlot_Subtypes)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            3) != 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -99;
        }
      }
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_1,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = FUN_00410cc0(spell_id,target_id,g_PlayerSelectionPriority,val_1,color_mask);
        if (val_1 != -1) {
          *(short *)(&g_CardSlot_PowerCounters + val_1 * 0x120 + spell_id * 0x5b20) =
               (short)*(int32_t *)
                       (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_0041652b
 * Entry Point: 0041652b
 * Size: 641 bytes
 */


int32_t Prompts_Load_0041652b(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t arg_10;
  int val_1;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_2;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (g_ScWillyScore < 0x1e) {
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11_00,arg_12_00,
                           arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005198ac,s_BERSERK_005198a4);
      val_1 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (val_1,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_2 = FUN_00410cc0(spell_id,target_id,DAT_006a4b64,val_1,color_mask);
        if (val_2 != -1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) = 0x80;
          *(int16_t *)(&g_CardSlot_PowerCounters + val_2 * 0x120 + spell_id * 0x5b20) =
               *(int16_t *)(&g_CardSlot_Counters + color_mask * 0x120 + val_1 * 0x5b20);
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + spell_id * 0x5b20) | 0x4000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: Prompts_Load_004167ac
 * Entry Point: 004167ac
 * Size: 702 bytes
 */


int32_t Prompts_Load_004167ac(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0x10;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005198c8,s_RIGTHEOUSNESS_005198b8);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0x10;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0x10;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        slot_idx = FUN_00410cc0(spell_id,target_id,g_PlayerSelectionPriority,card_idx,match_count);
        if (slot_idx != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 7;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 7;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00416a6a
 * Entry Point: 00416a6a
 * Size: 624 bytes
 */


int32_t Prompts_Load_00416a6a(int spell_id,int target_id,int flags)

{
  int color_mask;
  short len_1;
  int32_t uval_2;
  int val_3;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_4;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005198e0,s_BLOODLUST_005198d4);
      val_3 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + ((uint32_t)(g_ScWillyScore < 0x15) * 3 + 3) * -8;
      }
    }
    if (flags == 0x71) {
      val_3 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (val_3,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_4,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_4 = FUN_00410cc0(spell_id,target_id,g_PlayerSelectionPriority,val_3,color_mask);
        if (val_4 != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + val_4 * 0x120 + spell_id * 0x5b20) = 4;
          len_1 = FUN_0040a305(4,0,*(short *)(&DAT_006a5f46 + val_3 * 0x5b20 + color_mask * 0x120) +
                                   -1);
          *(short *)(&g_CardSlot_ToughnessCounters + val_4 * 0x120 + spell_id * 0x5b20) = -len_1;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_00416d36
 * Entry Point: 00416d36
 * Size: 484 bytes
 */


int32_t Prompts_Load_00416d36(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519900,s_SWORD_TO_PLOWSHARES_005198ec);
      val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_3 = FUN_00473179(val_2,color_mask,0x32,0xffffffff);
        (&g_PlayerCreatureCount)[val_2] = (&g_PlayerCreatureCount)[val_2] + val_3;
        Pic_Subsystem_0044867e(val_2,color_mask,4);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00416f1a
 * Entry Point: 00416f1a
 * Size: 908 bytes
 */


int32_t Prompts_Load_00416f1a(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int card_idx;
  int slot_idx;
  
  if ((flags == 0x74) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
    flag_1 = false;
    Ai_GetOpponentPlayerScore(0);
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      slot_idx = 0;
      while ((slot_idx < (int)(&g_PlayerActiveCardCount)[card_idx] && (!flag_1))) {
        if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + card_idx * 0x5b20) != -1) &&
           (((((uint8_t)*(int32_t *)(&g_CardSlot_Flags + slot_idx * 0x120 + card_idx * 0x5b20) & 0x22
              ) == 2 &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + card_idx * 0x5b20) * 0x34] & 2) != 0
             )) && ((&g_CardSlot_CardTypeIndex)[slot_idx * 0x120 + card_idx * 0x5b20] == '\x02')))) {
          flag_1 = true;
        }
        slot_idx = slot_idx + 1;
      }
    }
    if (flag_1) {
      uval_2 = 99;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    if ((flags == 0x6c) &&
       (((g_OverworldMapGrid == target_id && (g_OverworldPlayerCoordX == spell_id)) &&
        ((g_PlayerHandCardCount._1_1_ & 2) != 0)))) {
      flag_1 = false;
      do {
        Pic_Subsystem_00424500(s_prompts_txt_00519918,s_DEATH_WARD_0051990c);
        val_3 = Glue_Subsystem_004e6add(spell_id,spell_id,target_id);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        if ((&g_CardSlot_CardTypeIndex)
            [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120] ==
            '\x02') {
          flag_1 = true;
        }
        else if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_Illegal_target__not_dying___00519924);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_00519940);
        }
      } while ((g_ActivePlayer != 1) && (!flag_1));
    }
    if ((flags == 0x71) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
      val_3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Glue_Subsystem_004d7e90
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_004172a6
 * Entry Point: 004172a6
 * Size: 951 bytes
 */


int32_t Prompts_Load_004172a6(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t target_idx;
  int player_idx;
  int32_t card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_CurrentTurnPhase == spell_id) {
        Pic_Subsystem_00424500(s_prompts_txt_00519954,s_HURKYLS_RECALL_00519944);
        val_2 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,
                           0,0,&g_OverworldGoldAmount,1,&player_idx);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               card_idx;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        if (g_IsAiThinking == 1) {
          val_2 = Util_GetRandomNumber(3);
          g_AiDecisionScore = (uint32_t)(val_2 == 0);
          if (g_AiDecisionScore != 0) {
            val_2 = Glue_Subsystem_004e654a(1 - spell_id,0x40);
            if (val_2 == 0) {
              g_AiDecisionScore = 0;
            }
            else {
              val_2 = Glue_Subsystem_004e654a(spell_id,0x40);
              if (val_2 == 0) {
                g_AiDecisionScore = 1;
              }
            }
          }
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
        }
        if (g_AiDecisionScore == 0) {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = 1 - spell_id;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        }
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
             0xffffffff;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == 0) {
        target_idx = 0;
      }
      else {
        target_idx = 0x1000;
      }
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = FUN_00471c32(slot_idx,match_count);
          if (((val_2 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 0x40)
               != 0)) &&
             ((*(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + slot_idx * 0x5b20) & 0x1000) ==
              target_idx)) {
            FUN_0041da41(slot_idx,match_count);
          }
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_0041765d
 * Entry Point: 0041765d
 * Size: 700 bytes
 */


int32_t Prompts_Load_0041765d(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519968,&DAT_00519960);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + -0x18;
        }
        if (((&g_CardSlot_Abilities2)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            0x20) != 0) {
          g_SpellStackDepth = g_SpellStackDepth + -99;
        }
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_2 = FUN_00410cc0(spell_id,target_id,DAT_0069f6dc,val_2,color_mask);
        if (val_2 != -1) {
          *(int32_t *)(&g_CardSlot_Abilities2 + val_2 * 0x120 + spell_id * 0x5b20) = 0;
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) = 0x20;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00417f38
 * Entry Point: 00417f38
 * Size: 189 bytes
 */


int32_t Prompts_Load_00417f38(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(1);
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519994,s_LIGHTNING_BOLT_00519984);
      val_2 = Glue_Subsystem_004df8ba(spell_id,target_id);
      if (val_2 != 0) {
        g_SpellStackDepth = g_SpellStackDepth + -0x24;
      }
    }
    if (flags == 0x71) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x71,3);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00417ff5
 * Entry Point: 00417ff5
 * Size: 607 bytes
 */


int32_t Prompts_Load_00417ff5(int spell_id,int target_id,int flags)

{
  char cVar1;
  int color_mask;
  int32_t uval_2;
  int val_3;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_4;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_2,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005199a8,s_CRUMBLE_005199a0);
      val_3 = Glue_Subsystem_004e70ad(spell_id,1 - spell_id,target_id);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      val_3 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (val_3,color_mask,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,arg_12,
                         arg_13,val_4,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        cVar1 = (&g_MasterCardSubTypeTable2)
                [*(int *)(&g_CardSlot_CardId +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) * 0x34];
        val_4 = FUN_0040a305((int)(char)(&g_MasterCardManaCostTable)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_CombatTarget +
                                                         target_id * 0x120 + spell_id * 0x5b20) *
                                                 0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                                                  target_id * 0x120 +
                                                                  spell_id * 0x5b20) * 0x120) * 0x34
                                        ],0,99);
        (&g_PlayerCreatureCount)[val_3] = (&g_PlayerCreatureCount)[val_3] + cVar1 + val_4;
        Pic_Subsystem_0044867e(val_3,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_00418254
 * Entry Point: 00418254
 * Size: 653 bytes
 */


int32_t Prompts_Load_00418254(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth =
           g_SpellStackDepth + (((g_ScWillyScore < 0x15) - 1 & 0xfffffffe) * 3 + 0xc) * -4;
      if (g_ScWillyScore < 0x15) {
        g_SpellStackDepth = g_SpellStackDepth + -0xc;
      }
      Pic_Subsystem_00424500(s_prompts_txt_005199c4,s_GIANT_GROWTH_005199b4);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_2 = FUN_00410cc0(spell_id,target_id,g_PlayerSelectionPriority,val_2,color_mask);
        if (val_2 != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + val_2 * 0x120 + spell_id * 0x5b20) = 3;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + val_2 * 0x120 + spell_id * 0x5b20) = 3;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    if ((flags == 0x3b) && (val_2 = FUN_0040d949(spell_id,3,1), val_2 != 0)) {
      *(int *)(&DAT_00695eb0 + spell_id * 4) = *(int *)(&DAT_00695eb0 + spell_id * 4) + 3;
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 3;
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_004184e1
 * Entry Point: 004184e1
 * Size: 459 bytes
 */


int32_t Prompts_Load_004184e1(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
      Pic_Subsystem_00424500(s_prompts_txt_005199dc,s_UNSUMMON_005199d0);
      val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0041da41(val_2,color_mask);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Prompts_Load_00418785
 * Entry Point: 00418785
 * Size: 1231 bytes
 */


int32_t Prompts_Load_00418785(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  int32_t uval_2;
  int val_3;
  uint32_t uval_4;
  int32_t arg_11;
  uint32_t uval_5;
  int32_t arg_12;
  uint32_t uval_6;
  int32_t arg_13;
  int32_t arg_14;
  int val_7;
  int32_t arg_15;
  uint32_t uval_8;
  int32_t arg_16;
  uint32_t uVar9;
  int32_t arg_17;
  uint8_t *arg_18;
  uint32_t uVar10;
  int32_t arg_18_00;
  uint32_t uVar11;
  int32_t arg_19;
  int *arg_20;
  uint32_t uVar12;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if (g_SelectedTargetPlayer == -1) {
      Ai_GetOpponentPlayerScore(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      uval_2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0xff,0,0,uval_2,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else if (((spell_id == g_CurrentTurnPhase) ||
             ((spell_id == g_ActivePlayerPriority && (g_DefendingPlayer == g_CurrentTurnPhase)))) &&
            (val_3 = Rules_ParseFilter_0040360b
                               (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,spell_id,2,2,0,0xff,0,0,0,0,0,
                                -1,-1,0xffffffff,0xffffffff,2,0,0), val_3 != 0)) {
      uval_2 = 99;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      if (g_SelectedTargetPlayer == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_005199f4,s_ANY_LACE_005199e8);
        arg_20 = &player_idx;
        uval_2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        val_3 = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_4 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_3 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0xff,0,0,uval_4,uval_5,uval_6,val_3,val_7,uval_8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = player_idx;
          *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = 0;
      if (g_SelectedTargetPlayer == -1) {
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        val_3 = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_4 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120
                                   ),(char *)0x0,spell_id,2,2,0x200,0xff,0,0,uval_4,uval_5,uval_6,val_3
                           ,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
        if (val_3 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      else {
        val_3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120
                                   ),(char *)0x0,spell_id,2,2,0,0xff,0,0,0,0,0,-1,-1,0xffffffff,
                           0xffffffff,2,0,0);
        if (val_3 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      if (slot_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        player_idx = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
        card_idx = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
        match_count = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120)
                                * 0x34]);
        flag_1 = FUN_0041d9d2(spell_id,target_id,match_count);
        (&g_CardSlot_MinusOneCounters)[player_idx * 0x5b20 + card_idx * 0x120] = (char)(1 << (flag_1 & 0x1f));
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x1d);
        }
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_00418d2a
 * Entry Point: 00418d2a
 * Size: 1942 bytes
 */


int32_t Prompts_Load_00418d2a(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  int32_t uval_2;
  uint32_t arg_8;
  int val_3;
  int val_4;
  uint32_t arg_9;
  uint32_t arg_10;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int *arg_20;
  uint32_t local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  char local_d0 [200];
  int slot_idx;
  
  if (flags == 0x74) {
    if (spell_id == g_CurrentTurnPhase) {
      if (g_SelectedTargetPlayer == -1) {
        Ai_GetOpponentPlayerScore(0);
        uval_2 = 1;
      }
      else {
        uval_2 = 99;
      }
    }
    else if ((g_SelectedTargetPlayer == -1) || (g_DefendingPlayer != g_CurrentTurnPhase)) {
      Ai_GetOpponentPlayerScore(0);
      uval_2 = 1;
    }
    else {
      uval_2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_SelectedTargetPlayer == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519a10,s_MAGICAL_HACK_00519a00);
        arg_20 = &local_d8;
        uval_2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        arg_17 = 0;
        arg_16 = 0;
        arg_15 = 0;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        val_4 = -1;
        val_3 = -1;
        arg_10 = 0;
        arg_9 = 0;
        arg_8 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_3 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0x7f,0,0,arg_8,arg_9,arg_10,val_3,val_4,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18,uval_2,arg_20);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_d8;
          *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_d4;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = g_SelectedTargetPlayer;
        *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) =
             g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
      if (g_ActivePlayer != 1) {
        slot_idx = Util_GetRandomNumber(5);
        slot_idx = slot_idx + 1;
        if (spell_id == g_CurrentTurnPhase) {
          val_3 = Ai_Subsystem_004b3777
                            (spell_id,(int32_t *)
                                      (&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20),s_Magical_Hack_00519a48
                             ,(1 << ((uint8_t)slot_idx & 0x1f) & 0xffU) << 8,1);
          if (val_3 == -1) {
            slot_idx = -1;
            g_ActivePlayer = 1;
          }
          else {
            val_4 = Rules_CalculateManaCostReduction((uint8_t)((uint32_t)val_3 >> 8));
            val_3 = Rules_CalculateManaCostReduction((uint8_t)val_3);
            *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 val_4 * 0x100 + val_3;
          }
        }
        else {
          local_e4 = *(uint32_t *)(&DAT_006b3104 +
                              *(int *)(&g_MasterCardTypeTable +
                                      *(int *)(&g_CardSlot_CardId +
                                              *(int *)(&g_CardSlot_CombatTarget +
                                                      spell_id * 0x5b20 + target_id * 0x120) *
                                              0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                                               spell_id * 0x5b20 + target_id * 0x120
                                                               ) * 0x120) * 0x34) * 0x98);
          if (local_e4 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            if (((&g_CardSlot_Abilities1)
                 [*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) *
                  0x5b20 + *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120
                                   ) * 0x120] & 2) != 0) {
              val_3 = Rules_CalculateManaCostReduction((uint8_t)local_e4);
              flag_1 = FUN_0041d963(*(int *)(&g_CardSlot_CombatTarget +
                                           spell_id * 0x5b20 + target_id * 0x120),
                                   *(int *)(&g_CardSlot_AttachedAura +
                                           spell_id * 0x5b20 + target_id * 0x120),val_3);
              local_e4 = 1 << (flag_1 & 0x1f);
            }
            do {
              local_e0 = Util_GetRandomNumber(5);
              local_e0 = local_e0 + 1;
            } while ((local_e4 & 1 << ((uint8_t)local_e0 & 0x1f)) == 0);
            do {
              local_dc = Util_GetRandomNumber(5);
              local_dc = local_dc + 1;
            } while (local_dc == local_e0);
            if (g_IsAiThinking == 1) {
              g_AiDecisionScore = local_e0;
              Ai_EvaluateCreaturePower();
              g_AiDecisionScore = local_dc;
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_e0 = g_AiDecisionScore;
              Ai_CalcCardAdvantage();
              local_dc = g_AiDecisionScore;
            }
            *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 local_dc * 0x100 + local_e0;
            if (g_IsAiThinking != 1) {
              Pic_Subsystem_00424500(s_prompts_txt_00519a28,s_LANDWORDS_00519a1c);
              strcpy(local_d0,s_Hacking_00519a34);
              strcat(local_d0,&g_OverworldGoldAmount + (local_e0 * 5 + -5) * 0x32);
              strcat(local_d0,&DAT_00519a40);
              strcat(local_d0,&g_OverworldGoldAmount + (local_dc * 5 + 0x2d) * 0x32);
              Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,
                         *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         local_d0,0);
            }
          }
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
    }
    if (flags == 0x71) {
      local_d8 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      local_d4 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x1e);
      }
      *(uint32_t *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) | 2;
      FUN_00418c59(local_d8,local_d4,
                   (uint32_t)(uint8_t)(&g_CardSlot_ConvertedManaCost)
                               [spell_id * 0x5b20 + target_id * 0x120],
                   (char)((uint16_t)*(int16_t *)
                                   (&g_CardSlot_ConvertedManaCost +
                                   spell_id * 0x5b20 + target_id * 0x120) >> 8));
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_004195a4
 * Entry Point: 004195a4
 * Size: 1963 bytes
 */


int32_t Prompts_Load_004195a4(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  int32_t uval_2;
  uint32_t arg_8;
  int val_3;
  int val_4;
  uint32_t arg_9;
  uint32_t arg_10;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int *arg_20;
  uint32_t local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  char local_d0 [200];
  int slot_idx;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      if (g_SelectedTargetPlayer == -1) {
        Ai_GetOpponentPlayerScore(0);
        uval_2 = 1;
      }
      else {
        uval_2 = 99;
      }
    }
    else if ((g_SelectedTargetPlayer == -1) || (g_DefendingPlayer != g_CurrentTurnPhase)) {
      Ai_GetOpponentPlayerScore(0);
      uval_2 = 1;
    }
    else {
      uval_2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_SelectedTargetPlayer == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519a68,s_SLEIGHT_OF_MIND_00519a58);
        arg_20 = &local_d8;
        uval_2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        arg_17 = 0;
        arg_16 = 0;
        arg_15 = 0;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        val_4 = -1;
        val_3 = -1;
        arg_10 = 0;
        arg_9 = 0;
        arg_8 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_3 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0x7f,0,0,arg_8,arg_9,arg_10,val_3,val_4,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18,uval_2,arg_20);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_d8;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_d4;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = g_SelectedTargetPlayer;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
             g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
      if (g_ActivePlayer != 1) {
        slot_idx = Util_GetRandomNumber(5);
        slot_idx = slot_idx + 1;
        if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
          val_3 = Ai_Subsystem_004b3777
                            (spell_id,(int32_t *)
                                      (&g_CardSlot_CombatTarget +
                                      spell_id * 0x5b20 + target_id * 0x120),
                             s_Sleight_of_Mind_00519aa4,(1 << ((uint8_t)slot_idx & 0x1f) & 0xffU) << 8,0
                            );
          if (val_3 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            val_4 = Rules_CalculateManaCostReduction((uint8_t)((uint32_t)val_3 >> 8));
            val_3 = Rules_CalculateManaCostReduction((uint8_t)val_3);
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 val_4 * 0x100 + val_3;
          }
        }
        else {
          local_e4 = *(uint32_t *)(&DAT_006b30cc +
                              *(int *)(&g_MasterCardTypeTable +
                                      *(int *)(&g_CardSlot_CardId +
                                              *(int *)(&g_CardSlot_CombatTarget +
                                                      target_id * 0x120 + spell_id * 0x5b20) *
                                              0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                                               target_id * 0x120 + spell_id * 0x5b20
                                                               ) * 0x120) * 0x34) * 0x98);
          if (local_e4 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            if (((&g_CardSlot_Abilities1)
                 [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                  0x5b20 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x120] & 4) != 0) {
              val_3 = Rules_CalculateManaCostReduction((uint8_t)local_e4);
              flag_1 = FUN_0041d9d2(*(int *)(&g_CardSlot_CombatTarget +
                                           target_id * 0x120 + spell_id * 0x5b20),
                                   *(int *)(&g_CardSlot_AttachedAura +
                                           target_id * 0x120 + spell_id * 0x5b20),val_3);
              local_e4 = 1 << (flag_1 & 0x1f);
            }
            do {
              local_e0 = Util_GetRandomNumber(5);
              local_e0 = local_e0 + 1;
            } while ((local_e4 & 1 << ((uint8_t)local_e0 & 0x1f)) == 0);
            do {
              local_dc = Util_GetRandomNumber(5);
              local_dc = local_dc + 1;
            } while (local_dc == local_e0);
            if (g_IsAiThinking == 1) {
              g_AiDecisionScore = local_e0;
              Ai_EvaluateCreaturePower();
              g_AiDecisionScore = local_dc;
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_e0 = g_AiDecisionScore;
              Ai_CalcCardAdvantage();
              local_dc = g_AiDecisionScore;
            }
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 local_dc * 0x100 + local_e0;
            if (g_IsAiThinking != 1) {
              Pic_Subsystem_00424500(s_prompts_txt_00519a80,s_COLORWORDS_00519a74);
              strcpy(local_d0,s_Sleighting_00519a8c);
              strcat(local_d0,&g_OverworldGoldAmount + (local_e0 * 5 + -5) * 0x32);
              strcat(local_d0,&DAT_00519a9c);
              strcat(local_d0,&g_OverworldGoldAmount + (local_dc * 5 + 0x2d) * 0x32);
              Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         local_d0,0);
            }
          }
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      local_d8 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_d4 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x1e);
      }
      *(uint32_t *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) | 4;
      FUN_004194cf(local_d8,local_d4,
                   (uint32_t)(uint8_t)(&g_CardSlot_ConvertedManaCost)
                               [target_id * 0x120 + spell_id * 0x5b20],
                   (char)((uint16_t)*(int16_t *)
                                   (&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20) >> 8));
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_00419d5e
 * Entry Point: 00419d5e
 * Size: 1250 bytes
 */


int32_t Prompts_Load_00419d5e(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  int val_4;
  int32_t arg_12;
  uint32_t uval_5;
  int32_t arg_13;
  int32_t arg_14;
  int val_6;
  int32_t arg_15;
  uint32_t uval_7;
  int32_t arg_16;
  uint32_t uval_8;
  int32_t arg_17;
  uint32_t uVar9;
  uint8_t *arg_18;
  int32_t arg_18_00;
  uint32_t uVar10;
  uint32_t uVar11;
  int32_t arg_19;
  uint32_t uVar12;
  int *arg_20;
  uint32_t uVar13;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if (g_SelectedTargetPlayer == -1) {
      Ai_GetOpponentPlayerScore(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      flag_2 = FUN_0041d9d2(spell_id,target_id,4);
      val_4 = 1 << (flag_2 & 0x1f);
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      uval_3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uval_3,val_4,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else {
      uVar12 = 0;
      uVar10 = 0;
      uVar9 = 2;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_4 = -1;
      uval_5 = 0;
      flag_2 = FUN_0041d9d2(spell_id,target_id,4);
      val_4 = Rules_ParseFilter_0040360b
                        (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,spell_id,2,2,0,0,0,0,0,
                         1 << (flag_2 & 0x1f),uval_5,val_4,val_6,uval_7,uval_8,uVar9,uVar10,uVar12);
      if (val_4 == 0) {
        uval_3 = 0;
      }
      else {
        uval_3 = 99;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_SelectedTargetPlayer == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519ac0,s_BLUE_BLAST_00519ab4);
        arg_20 = &card_idx;
        uval_3 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_8 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,4);
        uval_7 = 1 << (flag_2 & 0x1f);
        uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_4 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uval_5,uval_7,uval_8,val_4,val_6,
                           uVar9,uVar10,uVar12,uVar11,uVar13,arg_18,uval_3,arg_20);
        if (val_4 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = 0;
      if (g_SelectedTargetPlayer == -1) {
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_8 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,4);
        uval_7 = 1 << (flag_2 & 0x1f);
        uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,uval_5,uval_7,uval_8,val_4,
                           val_6,uVar9,uVar10,uVar12,uVar11,uVar13);
        if (val_4 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      else {
        uVar12 = 0;
        uVar10 = 0;
        uVar9 = 2;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_5 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,4);
        val_4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0,0,0,0,0,1 << (flag_2 & 0x1f),uval_5,
                           val_4,val_6,uval_7,uval_8,uVar9,uVar10,uVar12);
        if (val_4 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      if (slot_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
        match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        cVar1 = (&g_CardSlot_MinusOneCounters)[match_count * 0x120 + card_idx * 0x5b20];
        flag_2 = FUN_0041d9d2(spell_id,target_id,4);
        if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
          Pic_Subsystem_0044867e(card_idx,match_count,2);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Decompiled function: Prompts_Load_0041b1ae
 * Entry Point: 0041b1ae
 * Size: 1250 bytes
 */


int32_t Prompts_Load_0041b1ae(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  int val_4;
  int32_t arg_12;
  uint32_t uval_5;
  int32_t arg_13;
  int32_t arg_14;
  int val_6;
  int32_t arg_15;
  uint32_t uval_7;
  int32_t arg_16;
  uint32_t uval_8;
  int32_t arg_17;
  uint32_t uVar9;
  uint8_t *arg_18;
  int32_t arg_18_00;
  uint32_t uVar10;
  uint32_t uVar11;
  int32_t arg_19;
  uint32_t uVar12;
  int *arg_20;
  uint32_t uVar13;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if (g_SelectedTargetPlayer == -1) {
      Ai_GetOpponentPlayerScore(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      flag_2 = FUN_0041d9d2(spell_id,target_id,2);
      val_4 = 1 << (flag_2 & 0x1f);
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      uval_3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uval_3,val_4,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else {
      uVar12 = 0;
      uVar10 = 0;
      uVar9 = 2;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_4 = -1;
      uval_5 = 0;
      flag_2 = FUN_0041d9d2(spell_id,target_id,2);
      val_4 = Rules_ParseFilter_0040360b
                        (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,spell_id,2,2,0,0,0,0,0,
                         1 << (flag_2 & 0x1f),uval_5,val_4,val_6,uval_7,uval_8,uVar9,uVar10,uVar12);
      if (val_4 == 0) {
        uval_3 = 0;
      }
      else {
        uval_3 = 99;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_SelectedTargetPlayer == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519ad8,s_RED_BLAST_00519acc);
        arg_20 = &card_idx;
        uval_3 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_8 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,2);
        uval_7 = 1 << (flag_2 & 0x1f);
        uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_4 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uval_5,uval_7,uval_8,val_4,val_6,
                           uVar9,uVar10,uVar12,uVar11,uVar13,arg_18,uval_3,arg_20);
        if (val_4 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = 0;
      if (g_SelectedTargetPlayer == -1) {
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_8 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,2);
        uval_7 = 1 << (flag_2 & 0x1f);
        uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,uval_5,uval_7,uval_8,val_4,
                           val_6,uVar9,uVar10,uVar12,uVar11,uVar13);
        if (val_4 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      else {
        uVar12 = 0;
        uVar10 = 0;
        uVar9 = 2;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_4 = -1;
        uval_5 = 0;
        flag_2 = FUN_0041d9d2(spell_id,target_id,2);
        val_4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0,0,0,0,0,1 << (flag_2 & 0x1f),uval_5,
                           val_4,val_6,uval_7,uval_8,uVar9,uVar10,uVar12);
        if (val_4 != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      if (slot_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
        match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        cVar1 = (&g_CardSlot_MinusOneCounters)[card_idx * 0x5b20 + match_count * 0x120];
        flag_2 = FUN_0041d9d2(spell_id,target_id,2);
        if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
          Pic_Subsystem_0044867e(card_idx,match_count,2);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Decompiled function: Prompts_Load_0041b98a
 * Entry Point: 0041b98a
 * Size: 2213 bytes
 */


int32_t Prompts_Load_0041b98a(int spell_id,int target_id,int flags,int height)

{
  char cVar1;
  int32_t uval_2;
  int val_3;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (height == 0)) {
      uval_2 = 0;
    }
    else if (((uint8_t)g_PlayerHandCardCount & 4) == 0) {
      uval_2 = 1;
    }
    else {
      uval_2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x60;
      if (((uint8_t)g_PlayerHandCardCount & 4) == 0) {
        Pic_Subsystem_00424500(s_prompts_txt_00519af4,s_HEALING_SALVE_00519ae4);
        val_3 = Action_ValidateTarget_00405802
                          (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                           &g_OverworldGoldAmount,1,&target_idx);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = target_idx;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = height;
        }
      }
      else {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        cVar1 = -1;
        slot_idx = 0;
        g_ActivePlayer = -1;
        card_idx = 0;
        while ((((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] < height &&
                (slot_idx == 0)) && ((g_ActivePlayer != 1 && (card_idx == 0))))) {
          Pic_Subsystem_00424500(s_prompts_txt_00519b10,s_HEALING_SALVE_00519b00);
          sprintf(&g_OverworldWorldState,&DAT_0069f84a,
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + 1,height);
          val_3 = Action_ValidateTarget_00405802
                            (spell_id,2,spell_id,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,
                             0xffffffff,0,0,0,&g_OverworldWorldState,3,&target_idx);
          if (val_3 == 0) {
            if (player_idx == -1) {
              g_ActivePlayer = 1;
            }
            else {
              slot_idx = 1;
            }
          }
          else if ((((&g_CardSlot_Toughness)[target_idx * 0x5b20 + player_idx * 0x120] == cVar1) &&
                   (*(int *)(&g_CardSlot_OriginalCardId + target_idx * 0x5b20 + player_idx * 0x120) ==
                    color_idx)) || (cVar1 == -1)) {
            cVar1 = (&g_CardSlot_Toughness)[target_idx * 0x5b20 + player_idx * 0x120];
            color_idx = *(int *)(&g_CardSlot_OriginalCardId + target_idx * 0x5b20 + player_idx * 0x120);
            *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x5b20 + player_idx * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x5b20 + player_idx * 0x120) | 0x200000;
            Ai_EvaluateTacticalPosition(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 target_idx;
            *(int *)(&g_CardSlot_AttachedAura +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 player_idx;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            if ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
              card_idx = card_idx + 1;
            }
            if (g_AiTemporaryCardState == 1) {
              while (((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] < height
                     && (card_idx == 0))) {
                *(int *)(&g_CardSlot_CombatTarget +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                     target_idx;
                *(int *)(&g_CardSlot_AttachedAura +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                     player_idx;
                (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                     (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                if ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
                  card_idx = 1;
                }
              }
            }
          }
          else if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_target__prevent_damage_t_00519b1c);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_00519b4c);
          }
        }
        for (match_count = 0;
            match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            match_count = match_count + 1) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           match_count * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           match_count * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                match_count * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                match_count * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) &
               0xffcfffff;
        }
        if ((card_idx != 0) && (card_idx = 0, g_IsAiThinking != 1)) {
          Ai_Util_004cc42d(s_WARNING___target_array_overflow_i_00519b50);
          Sleep(5000);
          Ai_Util_004cc42d(&DAT_00519b84);
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      while ('\0' < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20]) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + -1;
        target_idx = *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8
                           );
        player_idx = *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8
                           );
        if (((uint8_t)g_PlayerHandCardCount & 4) == 0) {
          (&g_PlayerCreatureCount)[target_idx] =
               (&g_PlayerCreatureCount)[target_idx] +
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        }
        else {
          val_3 = Rules_ParseFilter_0040360b
                            (target_idx,player_idx,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                             g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,0,0);
          if (val_3 == 0) {
            g_ActivePlayer = 1;
          }
          else if (*(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) !=
                   0) {
            *(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) + -1
            ;
          }
        }
      }
      Pic_Subsystem_0044867e(spell_id,target_id,2);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_0041c22f
 * Entry Point: 0041c22f
 * Size: 1704 bytes
 */


int32_t Prompts_Load_0041c22f(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int local_524;
  int local_520;
  int local_51c;
  int local_518;
  int local_514 [80];
  int local_3d4;
  int local_3d0;
  int local_3cc;
  int aiStack_3c8 [160];
  int32_t local_148 [80];
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (((uint8_t)g_PlayerHandCardCount & 4) == 0) {
      uval_2 = 1;
    }
    else {
      val_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,0xffffffff,
                           0xffffffff,0xffffffff,0x20,0,0);
      if (val_1 == 0) {
        uval_2 = 0;
      }
      else {
        uval_2 = 99;
      }
    }
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) && (((uint8_t)g_PlayerHandCardCount & 4) != 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519b98,s_SAMITE_HEALER_00519b88);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0x20,0
                         ,0,&g_OverworldGoldAmount,1,&local_524);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_524;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_520;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x71) {
      if (((uint8_t)g_PlayerHandCardCount & 4) == 0) {
        local_3d4 = 0;
        local_51c = 0;
        for (local_3d0 = 0; local_3d0 < 2; local_3d0 = local_3d0 + 1) {
          for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
            if ('\0' < (char)(&DAT_00700ec0)[spell_id + local_3d0 * 0xa0 + slot_idx * 2]) {
              aiStack_3c8[local_3d4 * 2] = local_3d0;
              aiStack_3c8[local_3d4 * 2 + 1] = slot_idx;
              local_514[local_3d4] =
                   (int)(char)(&DAT_00700ec0)[spell_id + local_3d0 * 0xa0 + slot_idx * 2];
              if (*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + local_3d0 * 0x5b20) == -1) {
                local_148[local_3d4] =
                     *(int32_t *)(&g_ActiveCardsInPlay + slot_idx * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
              else {
                local_148[local_3d4] =
                     *(int32_t *)(&g_CardSlot_CardId + slot_idx * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
            }
          }
        }
        if (0 < local_3d4) {
          if ((spell_id == 1) || (g_IsAiThinking == 1)) {
            local_51c = 0;
            for (local_518 = 0; local_518 < local_3d4; local_518 = local_518 + 1) {
              if (local_51c < local_514[local_518]) {
                local_51c = local_518;
              }
            }
            local_3cc = local_51c;
          }
          else {
            local_3cc = Pic_Subsystem_004509a1
                                  (spell_id,local_148,local_514,local_3d4,
                                   s_Select_the_card_that_has_damaged_00519ba8,1,&DAT_00519ba4);
          }
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               (char)(&DAT_00700ec0)
                     [spell_id +
                      aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] * 2;
          (&DAT_00700ec0)
          [spell_id + aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] = 0;
        }
        if ((int)(&g_PlayerCreatureCount)[1 - spell_id] < 1) {
          g_SpellStackDepth = g_SpellStackDepth + 1000;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (local_51c * 100) / (int)(&g_PlayerCreatureCount)[1 - spell_id] + -100;
        }
      }
      else {
        local_524 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
        local_520 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        val_1 = Rules_ParseFilter_0040360b
                          (local_524,local_520,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                           g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0x20,0,0);
        if (val_1 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120) !=
                 0) {
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               (char)(&DAT_00700ec0)
                     [spell_id +
                      (char)(&g_CardSlot_DamageReceived)[local_524 * 0x5b20 + local_520 * 0x120] *
                      0xa0 + *(int *)(&g_CardSlot_TypeFlags + local_524 * 0x5b20 + local_520 * 0x120
                                     ) * 2] * 2 +
               *(int *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120);
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120) =
               0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_0041c8e1
 * Entry Point: 0041c8e1
 * Size: 697 bytes
 */


int32_t Prompts_Load_0041c8e1(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if ((((uint8_t)g_PlayerHandCardCount & 4) == 0) ||
       (val_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,0xffffffff,
                             0xffffffff,0xffffffff,0x20,0,0), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519bdc,s_EYE_FOR_EYE_00519bd0);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0x20,0
                         ,0,&g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if ((int)(&g_PlayerCreatureCount)[1 - spell_id] < 1) {
          g_SpellStackDepth = g_SpellStackDepth + 1000;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (*(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) * 100)
               / (int)(&g_PlayerCreatureCount)[1 - spell_id];
        }
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      Mem_AllocOrFree_0041df33
                ((int)(char)(&g_CardSlot_DamageReceived)
                            [*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x120],
                 *(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120),spell_id,target_id);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: Prompts_Load_0041d1ab
 * Entry Point: 0041d1ab
 * Size: 614 bytes
 */


int32_t Prompts_Load_0041d1ab(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,3,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519bf0,s_FISSURE_00519be8);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,3,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,3,0,0,uval_2,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,1);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: UI_RegisterClass_0041df60
 * Entry Point: 0041df60
 * Size: 132 bytes
 */


bool UI_RegisterClass_0041df60(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 8;
  local_2c.lpfnWndProc = UI_WndProc_0041dfe4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x10;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}

/*
 * Decompiled function: UI_WndProc_0041dfe4
 * Entry Point: 0041dfe4
 * Size: 874 bytes
 */


LRESULT UI_WndProc_0041dfe4(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam)

{
  POINT pt;
  LONG LVar1;
  HWND pHVar2;
  uint32_t uval_3;
  HWND pHVar4;
  LRESULT LVar5;
  UINT UVar6;
  WPARAM wParam_00;
  int nIDDlgItem;
  tagRECT local_34;
  uint32_t local_24;
  uint32_t loop_idx;
  tagRECT color_idx;
  WPARAM match_count;
  HICON slot_idx;
  
  if (uMsg < 8) {
    if (uMsg == 7) {
      pHVar2 = hwnd;
      uval_3 = GetDlgCtrlID(hwnd);
      uval_3 = uval_3 & 0xffff;
      UVar6 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar6,uval_3,(LPARAM)pHVar2);
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = LoadIconA(g_AppHInstance,*(LPCSTR *)(lParam + 0x24));
      SetWindowLongA(hwnd,0,(LONG)slot_idx);
      match_count = 0;
      SetWindowLongA(hwnd,4,0);
      return 0;
    }
    if (uMsg == 2) {
      slot_idx = (HICON)GetWindowLongA(hwnd,0);
      if (slot_idx != (HICON)0x0) {
        DestroyIcon(slot_idx);
      }
      return 0;
    }
  }
  else if (uMsg < 0x88) {
    if (uMsg == 0x87) {
      return 0x2000;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    switch(uMsg) {
    case 0x200:
      pHVar2 = GetCapture();
      if (pHVar2 == hwnd) {
        local_24 = lParam & 0xffff;
        loop_idx = lParam >> 0x10;
        GetClientRect(hwnd,&color_idx);
        pt.y = loop_idx;
        pt.x = local_24;
        match_count = PtInRect(&color_idx,pt);
        SetWindowLongA(hwnd,4,match_count);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    case 0x201:
      SetCapture(hwnd);
      match_count = 1;
      SetWindowLongA(hwnd,4,1);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    case 0x202:
      pHVar2 = GetCapture();
      if (pHVar2 == hwnd) {
        GetClientRect(hwnd,&local_34);
        match_count = PtInRect(&local_34,(POINT)(CONCAT44(lParam >> 0x10,lParam) & 0xffffffff0000ffff));
        SetWindowLongA(hwnd,4,match_count);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        ReleaseCapture();
        if (match_count != 0) {
          SetFocus(hwnd);
        }
      }
      return 0;
    case 0x203:
      nIDDlgItem = 1;
      pHVar2 = GetParent(hwnd);
      pHVar2 = GetDlgItem(pHVar2,nIDDlgItem);
      wParam_00 = 1;
      UVar6 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar6,wParam_00,(LPARAM)pHVar2);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      match_count = wParam;
      SetWindowLongA(hwnd,4,wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x401) {
      LVar1 = GetWindowLongA(hwnd,4);
      return LVar1;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar5;
}

/*
 * Decompiled function: Prompts_Load_0046fa40
 * Entry Point: 0046fa40
 * Size: 1094 bytes
 */


void Prompts_Load_0046fa40(int spell_id,int target_id,int flags)

{
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((0 < (int)(&g_ActivePlayerSpellPriority)[spell_id]) &&
     ((spell_id != g_ActivePlayerPriority || (0 < (&g_ActivePlayerSpellPriority)[spell_id] + g_PendingSpellResolutionFlag)))) {
    if ((spell_id == g_CurrentTurnPhase) && ((g_IsAiThinking != 1 && (target_id == 0)))) {
      Pic_Subsystem_00424500(s_prompts_txt_00525b70,s_DISCARD_00525b68);
      Action_ValidateTarget_00405802
                (spell_id,spell_id,spell_id,0x100,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                 &g_OverworldGoldAmount,0,&target_idx);
      color_idx = player_idx;
    }
    else {
      slot_idx = 0;
      loop_idx = 0;
      do {
        color_idx = Util_GetRandomNumber((&g_PlayerActiveCardCount)[spell_id]);
        if (((*(int *)(&g_CardSlot_CardId + color_idx * 0x120 + spell_id * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[color_idx * 0x120 + spell_id * 0x5b20] & 2) == 0)) &&
           (((&g_CardSlot_Flags)[color_idx * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          slot_idx = 1;
        }
      } while ((slot_idx == 0) && (loop_idx = loop_idx + 1, loop_idx < 999));
      if (slot_idx == 0) {
        match_count = 0;
        while ((match_count < (int)(&g_PlayerActiveCardCount)[spell_id] && (slot_idx == 0))) {
          if ((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + spell_id * 0x5b20) != -1) &&
             ((((&g_CardSlot_Flags)[match_count * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
              (((&g_CardSlot_Flags)[match_count * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))) {
            slot_idx = 1;
            color_idx = match_count;
          }
          match_count = match_count + 1;
        }
      }
    }
    if (((g_PlayerHandCardCount & 0x800 << ((uint8_t)spell_id & 0x1f)) == 0) || (flags != 0)) {
      if ((spell_id == 1) && (g_IsAiThinking != 1)) {
        if (target_id == 0) {
          Ai_Subsystem_004cc56d(1,1,color_idx,-1,-1,s_to_discard__00525b94,0);
        }
        else {
          Ai_Subsystem_004cc56d(1,1,color_idx,-1,-1,s_at_random_to_discard__00525b7c,0);
        }
      }
      Magic_TriggerCardEvent(spell_id,color_idx,0x8d,1 - spell_id,0xffffffff);
      Pic_Subsystem_0044913a(spell_id,color_idx);
      *(int32_t *)(&g_CardSlot_CardId + color_idx * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      Ai_Subsystem_004cc3f8(spell_id,color_idx,0xb,1);
    }
    else {
      card_idx = Ai_Subsystem_004cc56d
                           (spell_id,spell_id,color_idx,-1,-1,
                            s_Discard_to_Library__Discard_to_G_00525ba0,0);
      if (card_idx == 0) {
        Pic_Subsystem_004524db
                  (spell_id,*(int32_t *)
                             (&g_CardSlot_CardId + color_idx * 0x120 + spell_id * 0x5b20));
        *(int32_t *)(&g_CardSlot_CardId + color_idx * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        Ai_Subsystem_004cc3f8(spell_id,color_idx,10,1);
      }
      else {
        Magic_TriggerCardEvent(spell_id,color_idx,0x8d,1 - spell_id,0xffffffff);
        Pic_Subsystem_0044913a(spell_id,color_idx);
        *(int32_t *)(&g_CardSlot_CardId + color_idx * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        Ai_Subsystem_004cc3f8(spell_id,color_idx,0xb,1);
      }
    }
    Magic_UpkeepPhase(0x18);
    (&g_ActivePlayerSpellPriority)[spell_id] = (&g_ActivePlayerSpellPriority)[spell_id] + -1;
  }
  return;
}

/*
 * Decompiled function: UI_LoadAttackSwordShieldPics
 * Entry Point: 004822b7
 * Size: 2732 bytes
 */


uint32_t UI_LoadAttackSwordShieldPics(HWND hwnd,uint32_t uMsg,uint32_t wParam,int lParam)

{
  HGDIOBJ h;
  HWND hWnd;
  uint32_t uval_1;
  tagRECT *lpRect;
  char local_27c [264];
  int32_t local_174;
  int local_170;
  int local_16c;
  int local_168;
  HDC local_164;
  uint8_t local_160 [4];
  int local_15c;
  int local_158;
  int local_148;
  int local_144;
  tagPAINTSTRUCT local_140;
  int local_100;
  tagRECT local_fc;
  tagRECT local_ec;
  int local_dc;
  int local_d8;
  HGDIOBJ local_d4;
  tagRECT local_d0;
  CHAR local_c0 [100];
  HBRUSH local_5c;
  HDC local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  uint32_t local_44;
  tagRECT local_40;
  HGDIOBJ local_30;
  tagRECT local_2c;
  int color_idx;
  HGDIOBJ target_idx;
  int32_t card_idx;
  int match_count;
  uint32_t slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      if (DAT_00539534 == (HANDLE)0x0) {
        strcpy(local_27c,&g_AiCurrentChoiceIndex);
        strcat(local_27c,s__WINBK_AttackSword_pic_00526db8);
        DAT_00539534 = (HANDLE)Pic_LoadKimPicture(local_27c);
      }
      if (DAT_00539564 == (HANDLE)0x0) {
        strcpy(local_27c,&g_AiCurrentChoiceIndex);
        strcat(local_27c,s__WINBK_AttackShield_pic_00526dd0);
        DAT_00539564 = (HANDLE)Pic_LoadKimPicture(local_27c);
      }
      Ai_Subsystem_004b74b1(&local_dc,(int32_t *)0x0);
      local_164 = BeginPaint(hwnd,&local_140);
      if (local_164 != (HDC)0x0) {
        FUN_004f3955(local_164);
        GetClientRect(hwnd,&local_ec);
        SendMessageA(g_AiDecisionMatrix_Row,0x14,(WPARAM)local_164,0);
        lpRect = &local_fc;
        hWnd = GetDlgItem(g_AiDecisionMatrix_Row,0);
        GetWindowRect(hWnd,lpRect);
        MapWindowPoints((HWND)0x0,g_AiDecisionMatrix_Row,(LPPOINT)&local_fc,2);
        local_148 = g_PlayerAmuletGems;
        local_144 = (g_PlayerAmuletGems * 5) / 100;
        if (DAT_00539534 != (HANDLE)0x0) {
          local_100 = SaveDC(local_164);
          GetObjectA(DAT_00539534,0x18,local_160);
          local_15c = local_15c / 2;
          if (local_dc == 1) {
            local_170 = local_ec.top + DAT_00539584;
            local_168 = local_170 + local_148;
          }
          else {
            local_170 = local_fc.bottom + local_144;
            local_168 = local_170 + local_148;
            SetMapMode(local_164,8);
            SetViewportExtEx(local_164,1,-1,(LPSIZE)0x0);
            SetWindowExtEx(local_164,1,1,(LPSIZE)0x0);
            SetViewportOrgEx(local_164,0,local_ec.bottom - DAT_00539584,(LPPOINT)0x0);
            SetWindowOrgEx(local_164,0,local_170,(LPPOINT)0x0);
          }
          local_174 = 5;
          local_16c = ((local_168 - local_170) * local_15c) / local_158 + 5;
          FUN_004f3e29(local_164,&local_174,DAT_00539534);
          RestoreDC(local_164,local_100);
        }
        if (DAT_00539564 != (HANDLE)0x0) {
          GetObjectA(DAT_00539564,0x18,local_160);
          local_15c = local_15c / 2;
          if (local_dc == 0) {
            local_170 = local_ec.top + DAT_00539584;
            local_168 = local_170 + local_148;
          }
          else {
            local_168 = local_ec.bottom - DAT_00539584;
            local_170 = local_168 - local_148;
          }
          local_174 = 5;
          local_16c = ((local_168 - local_170) * local_15c) / local_158 + 5;
          FUN_004f3e29(local_164,&local_174,DAT_00539564);
        }
        EndPaint(hwnd,&local_140);
      }
      return 0;
    }
    if (uMsg == 6) {
      slot_idx = DefWindowProcA(hwnd,6,wParam,lParam);
      if (wParam == 0) {
        return slot_idx;
      }
      SetActiveWindow(g_AiDecisionMatrix_Row);
      return slot_idx;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      uval_1 = UI_WndProc_004f4fb8(hwnd,0x20,wParam,lParam);
      return uval_1;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x113) {
    if (uMsg == 0x112) {
      if ((wParam & 0xfff0) == 0xf010) {
        return 0;
      }
      uval_1 = DefWindowProcA(hwnd,0x112,wParam,lParam);
      return uval_1;
    }
    if (uMsg == 0x83) {
      match_count = lParam;
      card_idx = *(int32_t *)(lParam + 8);
      uval_1 = DefWindowProcA(hwnd,0x83,wParam,lParam);
      *(int32_t *)(match_count + 8) = card_idx;
      return uval_1;
    }
    if ((0x84 < uMsg) && (uMsg < 0x87)) {
      GetWindowRect(hwnd,&local_2c);
      OffsetRect(&local_2c,-local_2c.left,-local_2c.top);
      if ((local_2c.right != local_2c.left) && (local_2c.bottom != local_2c.top)) {
        local_44 = (uint32_t)(uMsg != 0x85);
        local_58 = GetWindowDC(hwnd);
        if (local_58 == (HDC)0x0) {
          return local_44;
        }
        FUN_004f3955(local_58);
        GetWindowRect(hwnd,&local_2c);
        GetClientRect(hwnd,&local_d0);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_d0,2);
        OffsetRect(&local_d0,-local_2c.left,-local_2c.top);
        OffsetRect(&local_2c,-local_2c.left,-local_2c.top);
        GetWindowTextA(hwnd,local_c0,100);
        local_d8 = local_d0.left - local_2c.left;
        local_4c = local_2c.bottom - local_d0.bottom;
        Ai_Subsystem_004b74b1(&color_idx,(int32_t *)0x0);
        if (color_idx == 0) {
          local_30 = DAT_00539550;
          local_d4 = DAT_00539580;
          target_idx = DAT_0053953c;
          local_5c = DAT_00539558;
        }
        else {
          local_30 = DAT_00539568;
          local_d4 = DAT_0053956c;
          target_idx = DAT_00539548;
          local_5c = DAT_00539578;
        }
        SelectObject(local_58,local_d4);
        local_50 = 0;
        MoveToEx(local_58,0,0,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,local_30);
        local_50 = 1;
        for (local_54 = 1; local_54 <= local_4c + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,1,local_50,(LPPOINT)0x0);
          LineTo(local_58,local_2c.right,local_50);
          local_50 = local_50 + 1;
        }
        SelectObject(local_58,local_d4);
        local_50 = local_4c + -1;
        MoveToEx(local_58,local_d8 + -1,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_d0.right,local_50);
        SelectObject(local_58,local_d4);
        local_48 = 0;
        MoveToEx(local_58,0,0,(LPPOINT)0x0);
        LineTo(local_58,local_48,local_2c.bottom + -1);
        SelectObject(local_58,local_30);
        local_48 = 1;
        for (local_54 = 1; local_54 <= local_d8 + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,local_48,1,(LPPOINT)0x0);
          LineTo(local_58,local_48,local_2c.bottom + -1);
          local_48 = local_48 + 1;
        }
        SelectObject(local_58,local_d4);
        local_48 = local_d0.left + -1;
        MoveToEx(local_58,local_48,local_4c + -1,(LPPOINT)0x0);
        LineTo(local_58,local_48,local_d0.bottom + 1);
        h = GetStockObject(7);
        SelectObject(local_58,h);
        local_50 = local_2c.bottom + -1;
        MoveToEx(local_58,0,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,target_idx);
        local_50 = local_2c.bottom + -2;
        for (local_54 = 1; local_54 <= local_4c + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,1,local_50,(LPPOINT)0x0);
          LineTo(local_58,local_2c.right,local_50);
          local_50 = local_50 + -1;
        }
        SelectObject(local_58,local_d4);
        local_50 = local_2c.bottom - local_4c;
        MoveToEx(local_58,local_d8 + -1,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,local_d4);
        local_50 = local_d0.top + -1;
        MoveToEx(local_58,local_d0.left,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SetRect(&local_40,local_d0.left,local_4c,local_d0.right,local_d0.top + -1);
        FillRect(local_58,&local_40,local_5c);
        SetTextColor(local_58,DAT_0053954c);
        SetBkMode(local_58,1);
        DrawTextA(local_58,local_c0,-1,&local_40,0x24);
        ReleaseDC(hwnd,local_58);
        return local_44;
      }
      uval_1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
      return uval_1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    uval_1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
    return uval_1;
  }
  uval_1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return uval_1;
}

/*
 * Decompiled function: UI_MinimizedAttackWindowWndProc
 * Entry Point: 00482dd6
 * Size: 855 bytes
 */


LRESULT UI_MinimizedAttackWindowWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam)

{
  HBRUSH hbr;
  LRESULT LVar1;
  int local_13c;
  tagPOINT local_138;
  tagRECT local_130;
  char local_120 [264];
  HDC target_idx;
  tagRECT player_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      target_idx = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&player_idx);
      IntersectClipRect(target_idx,0,0,player_idx.right,player_idx.bottom);
      if (DAT_0053957c == (HANDLE)0x0) {
        strcpy(local_120,&g_AiCurrentChoiceIndex);
        strcat(local_120,s__WINBK_AttackMin_pic_00526e18);
        DAT_0053957c = (HANDLE)Pic_LoadKimPicture(local_120);
      }
      if (DAT_0053957c == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect(target_idx,&player_idx,hbr);
      }
      else {
        FUN_004f3b5f((int)target_idx,(int)&player_idx,DAT_0053957c);
      }
      return 1;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(g_AiDecisionMatrix_Row,0);
      return 0;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_13c = GetMenuItemCount(DAT_0053955c);
        while (local_13c != 0) {
          DeleteMenu(DAT_0053955c,0,0x400);
          local_13c = local_13c + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      AppendMenuA(DAT_0053955c,0,0x66,s__Restore_00526e30);
      AppendMenuA(DAT_0053955c,0,100,s_Help____00526e3c);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_138.x = lParam & 0xffff;
      local_138.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_138);
      SetRect(&local_130,local_138.x,local_138.y,local_138.x + 1,local_138.y + 1);
      TrackPopupMenu(DAT_0053955c,2,local_138.x,local_138.y,0,g_AiDecisionMatrix_Row,&local_130);
      return 0;
    }
    if (uMsg == 0x201) {
      SendMessageA(g_AiDecisionMatrix_Row,0x111,0x66,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      strcpy((char *)wParam,s_Minimized_attack_window_00526e00);
      return 1;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}

/*
 * Decompiled function: Rules_ShufflePlayerLibrary
 * Entry Point: 0050bba0
 * Size: 310 bytes
 */


bool Rules_ShufflePlayerLibrary(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_LibraryCardCountWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_WndProc_0050c854;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ShuffleCard_005324ec;
  AVar2 = RegisterClassA(&local_2c);
  DAT_0061e118 = CreatePopupMenu();
  DAT_0061e11c = CreatePopupMenu();
  AppendMenuA(DAT_0061e11c,0,0x65,&DAT_005324f8);
  return AVar2 != 0 && AVar1 != 0;
}

/*
 * Decompiled function: UI_LibraryCardCountWndProc
 * Entry Point: 0050bd27
 * Size: 2798 bytes
 */


LRESULT UI_LibraryCardCountWndProc(HWND hwnd,uint32_t y,HWND param_3,uint32_t height)

{
  HWND pHVar1;
  HBRUSH pHVar2;
  HGDIOBJ buf_ptr_3;
  size_t c;
  LRESULT LVar4;
  int val_5;
  int local_464;
  char local_460 [12];
  tagPOINT local_454;
  tagRECT local_44c;
  char local_43c [12];
  tagRECT local_430;
  int local_420;
  int local_41c;
  int local_418;
  int local_414;
  tagRECT local_410;
  int local_400;
  int local_3fc;
  int local_3f8;
  HDC local_3f4;
  tagPAINTSTRUCT local_3f0;
  tagRECT local_3b0;
  char local_3a0 [264];
  ULONG_PTR local_298;
  int local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  tagRECT local_274;
  int aiStack_264 [100];
  int local_d4;
  char local_d0 [100];
  char local_6c [100];
  int slot_idx;
  
  if (y < 0x10) {
    if (y == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      local_3f8 = Mem_AllocOrFree_0050c82b((uint32_t)(hwnd != DAT_006fe48c));
      if (slot_idx != local_3f8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_3f4 = BeginPaint(hwnd,&local_3f0);
      if (local_3f4 != (HDC)0x0) {
        FUN_004f3955(local_3f4);
        GetClientRect(hwnd,&local_3b0);
        if (DAT_0068a674 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_3f4,&local_3b0,pHVar2);
          Sleep(200);
        }
        if (local_3f8 == 0) {
          pHVar2 = GetStockObject(4);
          FillRect(local_3f4,&local_3b0,pHVar2);
        }
        else if (local_3f8 == 1) {
          Palette_Subsystem_0049c6cb(local_3f4,&local_3b0);
        }
        else {
          pHVar2 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_3b0,pHVar2);
          val_5 = local_3f8;
          if (0x4a < local_3f8) {
            val_5 = 0x4b;
          }
          local_418 = (((local_3b0.right * 0x28) / 100) * val_5) / 0x4b;
          local_3fc = (local_3b0.bottom * local_418) / local_3b0.right;
          SetRect(&local_410,local_3b0.left,local_3b0.top,local_3b0.right - local_418,
                  local_3b0.bottom - local_3fc);
          buf_ptr_3 = GetStockObject(2);
          SelectObject(local_3f4,buf_ptr_3);
          buf_ptr_3 = GetStockObject(7);
          SelectObject(local_3f4,buf_ptr_3);
          local_41c = local_3f8 / 5;
          if (local_41c < 2) {
            local_41c = 1;
          }
          local_41c = local_418 / local_41c;
          if (local_41c < 3) {
            local_41c = 2;
          }
          local_420 = local_3f8 / 5;
          if (local_420 < 2) {
            local_420 = 1;
          }
          local_420 = local_3fc / local_420;
          if (local_420 < 4) {
            local_420 = 3;
          }
          local_414 = local_3b0.bottom;
          for (local_400 = local_3b0.right; local_410.right < local_400;
              local_400 = local_400 - local_41c) {
            SetRect(&local_430,local_400 - (local_410.right - local_410.left),
                    local_414 - (local_410.bottom - local_410.top),local_400,local_414);
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_430);
            local_414 = local_414 - local_420;
          }
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_410);
          BitBlt(local_3f4,0,0,local_3b0.right,local_3b0.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          if (DAT_006808c4 != 0) {
            sprintf(local_43c,&DAT_0053252c,local_3f8);
            SetBkMode(local_3f4,1);
            SetTextColor(local_3f4,0xffffff);
            c = strlen(local_43c);
            TextOutA(local_3f4,0,0,local_43c,c);
          }
        }
        EndPaint(hwnd,&local_3f0);
        slot_idx = local_3f8;
        SetWindowLongA(hwnd,0,local_3f8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (y == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,0,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,height);
      return LVar4;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x117) {
    if (y == 0x116) {
      slot_idx = GetWindowLongA(hwnd,0);
      sprintf(local_460,&DAT_00532530,slot_idx);
      AppendMenuA(DAT_0061e118,0x10,(UINT_PTR)DAT_0061e11c,s_Count_library_cards_00532534);
      ModifyMenuA(DAT_0061e11c,0x65,0,0x65,local_460);
      AppendMenuA(DAT_0061e118,0,100,s_Help____00532548);
      return 0;
    }
    if (y == 0x111) {
      if (((uint32_t)param_3 & 0xffff) == 100) {
        local_298 = 0x7e9;
        strcpy(local_3a0,&g_GameInstallDirectory);
        strcat(local_3a0,s__duel_hlp_00532520);
        WinHelpA(g_MainAppHwnd,local_3a0,1,local_298);
      }
      return 0;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
      return 0;
    }
    if (y == 0x11f) {
      if (((uint32_t)param_3 >> 0x10 == 0xffff) && (height == 0)) {
        local_464 = GetMenuItemCount(DAT_0061e118);
        while (local_464 != 0) {
          RemoveMenu(DAT_0061e118,0,0x400);
          local_464 = local_464 + -1;
        }
      }
      return 0;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      LVar4 = FUN_004f5d1a(hwnd,y,param_3,height);
      return LVar4;
    }
    if (y == 0x204) {
      local_454.x = height & 0xffff;
      local_454.y = height >> 0x10;
      ClientToScreen(hwnd,&local_454);
      SetRect(&local_44c,local_454.x,local_454.y,local_454.x + 1,local_454.y + 1);
      TrackPopupMenu(DAT_0061e118,2,local_454.x,local_454.y,0,hwnd,&local_44c);
      return 0;
    }
  }
  else {
    if (y == 0x400) {
      local_28c = Mem_AllocOrFree_0050c82b((uint32_t)(hwnd != DAT_006fe48c));
      GetClientRect(hwnd,&local_274);
      val_5 = local_28c;
      if (0x4a < local_28c) {
        val_5 = 0x4b;
      }
      local_294 = (((local_274.right * 0x28) / 100) * val_5) / 0x4b;
      local_290 = (local_274.bottom * local_294) / local_274.right;
      local_284 = local_274.right - local_294;
      local_288 = local_274.bottom - local_290;
      GetWindowRect(hwnd,&local_274);
      local_278 = local_274.left;
      local_27c = local_274.top;
      if (100 < local_28c) {
        local_28c = 100;
      }
      val_5 = GetSystemMetrics(0x49);
      if (val_5 == 0) {
        if ((5 < local_28c) && (local_28c = local_28c / 3, local_28c < 6)) {
          local_28c = 5;
        }
      }
      else if ((4 < local_28c) && (local_28c = local_28c / 5, local_28c < 5)) {
        local_28c = 4;
      }
      for (local_280 = 0; val_5 = local_28c, local_280 < local_28c; local_280 = local_280 + 1) {
        pHVar1 = CreateWindowExA(0,s_ShuffleCard_00532514,&DAT_00532510,0x90000000,local_278,
                                 local_27c,local_284,local_288,g_MainAppHwnd,(HMENU)0x0,
                                 g_AppHInstance,(LPVOID)0x0);
        aiStack_264[local_280] = (int)pHVar1;
        if (aiStack_264[local_280] != 0) {
          UpdateWindow((HWND)aiStack_264[local_280]);
          local_278 = local_278 + (local_284 * 0xf) / 100;
        }
      }
      while (local_280 = val_5 + -1, -1 < local_280) {
        if (aiStack_264[local_280] != 0) {
          DestroyWindow((HWND)aiStack_264[local_280]);
        }
        UpdateWindow(g_MainAppHwnd);
        val_5 = local_280;
      }
      return 0;
    }
    if (y == 0x432) {
      slot_idx = GetWindowLongA(hwnd,0);
      local_d4 = Mem_AllocOrFree_0050c82b((uint32_t)(hwnd != DAT_006fe48c));
      if (slot_idx != local_d4) {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (y == 0x437) {
      if (hwnd == DAT_006fe48c) {
        strcpy(local_6c,s_Your_005324fc);
      }
      else {
        Ai_Subsystem_004b6f49(local_6c);
      }
      sprintf(local_d0,s__s_library_00532504,local_6c);
      strcpy((char *)param_3,local_d0);
      return 1;
    }
  }
  LVar4 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
  return LVar4;
}

/*
 * Decompiled function: UI_WndProc_0050c854
 * Entry Point: 0050c854
 * Size: 179 bytes
 */


LRESULT UI_WndProc_0050c854(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam)

{
  LRESULT LVar1;
  tagRECT player_idx;
  
  if (uMsg == 0x14) {
    FUN_004f3955(wParam);
    GetClientRect(hwnd,&player_idx);
    Palette_Subsystem_0049c6cb(wParam,&player_idx);
    LVar1 = 0;
  }
  else if ((uMsg < 0x30f) || (0x311 < uMsg)) {
    LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  }
  else {
    LVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
  }
  return LVar1;
}

