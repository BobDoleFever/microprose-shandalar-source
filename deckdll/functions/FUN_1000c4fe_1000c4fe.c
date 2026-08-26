/*
 * Decompiled function: FUN_1000c4fe
 * Entry Point: 1000c4fe
 * Size: 2352 bytes
 */
#include "deckdll.h"


uint32_t FUN_1000c4fe(HWND hwnd,uint32_t y,uint32_t width,LONG *arg_4)

{
  WORD WVar1;
  BOOL BVar2;
  size_t len_3;
  size_t sVar4;
  HWND pHVar5;
  uint32_t uval_6;
  int val_7;
  char *pcVar8;
  tagPOINT *lpPoint;
  tagRECT local_d4;
  HDC local_c4;
  tagPAINTSTRUCT local_c0;
  int local_80;
  tagRECT local_7c;
  tagMSG local_6c;
  uint32_t local_50;
  tagPOINT local_4c;
  UINT local_44;
  char local_40 [32];
  int local_20;
  WPARAM local_1c;
  tagRECT local_18;
  LONG local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      WVar1 = GetWindowWord(hwnd,4);
      local_50 = CONCAT22(local_50._2_2_,WVar1);
      local_1c = GetWindowLongA(hwnd,0);
      local_c4 = BeginPaint(hwnd,&local_c0);
      GetClientRect(hwnd,&local_7c);
      thunk_FUN_10031425(local_c4);
      FillRect(DAT_101625e8,&local_7c,DAT_101cf91c);
      thunk_FUN_1001df0d(DAT_101625e8,&local_7c,(WPARAM *)(&DAT_10176ab0 + local_1c * 0x98),1,1);
      if (1 < (local_50 & 0xffff)) {
        sprintf(local_40,&DAT_1004142c,local_50 & 0xffff);
        local_80 = SaveDC(DAT_101625e8);
        SetMapMode(DAT_101625e8,8);
        SetWindowExtEx(DAT_101625e8,200,0x118,(LPSIZE)0x0);
        SetViewportExtEx(DAT_101625e8,local_7c.right - local_7c.left,local_7c.bottom - local_7c.top,
                         (LPSIZE)0x0);
        SetViewportOrgEx(DAT_101625e8,local_7c.left,local_7c.top,(LPPOINT)0x0);
        SetBkMode(DAT_101625e8,1);
        SelectObject(DAT_101625e8,DAT_101625f4);
        SetTextAlign(DAT_101625e8,0);
        SetTextColor(DAT_101625e8,0x2434343);
        len_3 = strlen(local_40);
        pcVar8 = local_40;
        val_7 = 3;
        sVar4 = strlen(local_40);
        TextOutA(DAT_101625e8,sVar4 * -0x10 + 0xcb,val_7,pcVar8,len_3);
        SetTextColor(DAT_101625e8,0x227d9f1);
        SetBkMode(DAT_101625e8,1);
        len_3 = strlen(local_40);
        pcVar8 = local_40;
        val_7 = 0;
        sVar4 = strlen(local_40);
        TextOutA(DAT_101625e8,sVar4 * -0x10 + 200,val_7,pcVar8,len_3);
        RestoreDC(DAT_101625e8,local_80);
      }
      BitBlt(local_c4,0,0,local_7c.right,local_7c.bottom,DAT_101625e8,0,0,0xcc0020);
      EndPaint(hwnd,&local_c0);
      return 0;
    }
    if (y == 1) {
      local_1c = *arg_4;
      SetWindowLongA(hwnd,0,local_1c);
      local_50 = CONCAT22(local_50._2_2_,1);
      SetWindowWord(hwnd,4,1);
      if ((-1 < (int)local_1c) && ((int)local_1c <= DAT_10175ee0)) {
        return 0;
      }
      return 0xffffffff;
    }
    if (y == 2) {
      return 0;
    }
    if (y == 5) {
      GetWindowRect(hwnd,&local_d4);
      DAT_10175558 = local_d4.right - local_d4.left;
      DAT_10176860 = local_d4.bottom - local_d4.top;
      return 0;
    }
  }
  else if (y < 0x201) {
    if (y == 0x200) {
      local_1c = GetWindowLongA(hwnd,0);
      SendMessageA(DAT_1016e4a8,0x400,local_1c,0);
      return 0;
    }
    if (y == 0x111) {
      if ((width & 0xffff) == 1) {
        local_8 = GetWindowLongA(hwnd,0);
        WVar1 = GetWindowWord(hwnd,4);
        local_50 = CONCAT22(local_50._2_2_,WVar1);
        DAT_10175ecc = 1;
        DAT_101cfb9c = 1;
        if ((1 < WVar1) && (val_7 = thunk_FUN_1000ac70(), val_7 == 0)) {
          return 0;
        }
        if (DAT_10175ecc == 0) {
          return 0;
        }
        for (local_44 = 0; (int)local_44 < DAT_10175ecc; local_44 = local_44 + 1) {
          val_7 = thunk_FUN_1000d64e(local_8,0);
          if (val_7 == 0) {
            return 0;
          }
        }
        *DAT_101cfb7c = *DAT_101cfb7c + DAT_10175ecc * DAT_10128a20;
        thunk_FUN_1000880b();
        sprintf(local_40,s_GOLD___d_10041420,*DAT_101cfb7c);
        strncpy(&DAT_10162630,local_40,0xc);
        InvalidateRect(DAT_10176a9c,(RECT *)0x0,1);
        WVar1 = GetWindowWord(hwnd,4);
        if (DAT_10175ecc < (int)(uint32_t)WVar1) {
          SetWindowWord(hwnd,4,(short)local_50 - (short)DAT_10175ecc);
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
        else {
          DestroyWindow(hwnd);
        }
        GetClientRect(DAT_101cf33c,&local_18);
        LockWindowUpdate(DAT_10176868);
        thunk_FUN_1000852a(DAT_101cf33c,&local_18.left);
        LockWindowUpdate((HWND)0x0);
        thunk_FUN_10027036();
      }
      return 0;
    }
  }
  else if (y < 0x401) {
    if (y == 0x400) {
      uval_6 = GetWindowLongA(hwnd,0);
      return uval_6;
    }
    if (y == 0x201) {
      if ((DAT_101cdea0 & 1) == 0) {
        return 0;
      }
      local_44 = GetDoubleClickTime();
      Sleep(local_44);
      BVar2 = PeekMessageA(&local_6c,hwnd,0x203,0x203,0);
      if (BVar2 != 0) {
        return 0;
      }
      DAT_10128a18 = (uint32_t)arg_4 & 0xffff;
      DAT_10128a1c = (uint32_t)arg_4 >> 0x10;
      if ((width & 4) == 0) {
        thunk_FUN_1000ce3f(hwnd,DAT_10128a18,DAT_10128a1c,1,1);
      }
      else {
        thunk_FUN_1000ce3f(hwnd,DAT_10128a18,DAT_10128a1c,2,1);
      }
      SendMessageA(DAT_101cf33c,0x111,0xc9,0);
      return 0;
    }
    if (y == 0x203) {
      if ((DAT_101cdea0 & 1) == 0) {
        return 0;
      }
      DAT_10128a18 = (uint32_t)arg_4 & 0xffff;
      DAT_10128a1c = (uint32_t)arg_4 >> 0x10;
      if ((width & 4) == 0) {
        thunk_FUN_1000ce3f(hwnd,DAT_10128a18,DAT_10128a1c,1,0);
      }
      else {
        thunk_FUN_1000ce3f(hwnd,DAT_10128a18,DAT_10128a1c,2,0);
      }
      SendMessageA(DAT_101cf33c,0x111,0xc9,0);
      return 0;
    }
    if (y == 0x204) {
      local_4c.x = (uint32_t)arg_4 & 0xffff;
      local_4c.y = (uint32_t)arg_4 >> 0x10;
      if ((DAT_1017646c & 2) != 0) {
        ClientToScreen(hwnd,&local_4c);
        lpPoint = &local_4c;
        pHVar5 = GetParent(hwnd);
        ScreenToClient(pHVar5,lpPoint);
        uval_6 = local_4c.y << 0x10 | local_4c.x & 0xffffU;
        pHVar5 = GetParent(hwnd);
        SendMessageA(pHVar5,y,width,uval_6);
        return 0;
      }
      if ((DAT_101cdea0 & 2) == 0) {
        return 0;
      }
      local_8 = GetWindowLongA(hwnd,0);
      local_20 = thunk_FUN_1000d754(local_8);
      if (local_20 == -1) {
        return 0;
      }
      DAT_10128a20 = (*DAT_101625f8)(local_20);
      sprintf(local_40,s_Sell_Card_for__d_10041430,DAT_10128a20);
      AppendMenuA(DAT_10175ec0,0,1,local_40);
      ClientToScreen(hwnd,&local_4c);
      TrackPopupMenu(DAT_10175ec0,2,local_4c.x + 10,local_4c.y + 10,0,hwnd,(RECT *)0x0);
      DeleteMenu(DAT_10175ec0,0,0x400);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      local_50 = CONCAT22(local_50._2_2_,(WORD)width);
      SetWindowWord(hwnd,4,(WORD)width);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x402) {
      WVar1 = GetWindowWord(hwnd,4);
      local_50 = (uint32_t)WVar1;
      return local_50;
    }
  }
  uval_6 = DefWindowProcA(hwnd,y,width,(LPARAM)arg_4);
  return uval_6;
}


