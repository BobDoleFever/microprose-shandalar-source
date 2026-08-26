/*
 * Decompiled function: UI_Register_MAGICGAME_BigCardCardClass_00401000
 * Entry Point: 00401000
 * Size: 3212 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
UI_Register_MAGICGAME_BigCardCardClass_00401000(HWND hwnd,uint y,HDC hdc,undefined4 *arg_4)

{
  POINT pt;
  POINT pt_00;
  LRESULT LVar1;
  undefined4 uVar2;
  HBRUSH hbr;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  HWND pHVar6;
  uint arg_1;
  size_t sVar7;
  HGDIOBJ ho;
  tagRECT *lpRect;
  char local_134 [12];
  HDC local_128;
  tagPAINTSTRUCT local_124;
  undefined4 local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint local_d0;
  uint local_cc;
  WPARAM local_c8;
  WPARAM local_c4;
  tagRECT local_c0;
  uint local_b0;
  tagRECT local_ac;
  HDC local_9c;
  tagRECT local_98;
  LRESULT local_88;
  uint local_84;
  HGDIOBJ local_80;
  LOGFONTA local_7c;
  HFONT local_40;
  HANDLE local_3c;
  int local_38;
  int local_34;
  HWND local_30;
  tagRECT local_2c;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
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
      local_d0 = (uint)arg_4 & 0xffff;
      local_cc = (uint)arg_4 >> 0x10;
      if (((y == 0x200) && (DAT_006fe444 != 2)) || ((y == 0x204 && (DAT_006fe444 == 2)))) {
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
      if (DAT_006fedc0 != 0) {
        SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
      }
      lpRect = &local_2c;
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      GetWindowRect(pHVar6,lpRect);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
      GetClientRect(hwnd,&local_14);
      local_1c = local_2c.top;
      local_18 = local_14.right - local_2c.right;
      InflateRect(&local_14,-local_2c.top,-local_18);
      CopyRect((LPRECT)&DAT_00536d78,&local_14);
      _DAT_00536d80 = local_2c.left - local_1c;
      CopyRect((LPRECT)&DAT_00536d90,&local_14);
      DAT_00536d90 = local_2c.left;
      DAT_00536d94 = local_2c.bottom;
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
                                   DAT_00536d94,DAT_006a28b0,DAT_006b2e30,hwnd,(HMENU)0x1,
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
      if ((((uint)arg_4 & 0xffff) == 1) || (((uint)arg_4 & 0xffff) == 2)) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      else if (((uint)hdc & 0xffff) == 0x3f1) {
        local_84 = (uint)hdc >> 0x10;
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
      iVar3 = abs(local_c0.top - local_ac.top);
      iVar4 = abs(local_c0.left - local_ac.left);
      local_b0 = (uint)(4 < iVar3 + iVar4);
      if (local_b0 == 0) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      return 1;
    }
  }
  else if ((0x30e < y) && (y < 0x312)) {
    uVar2 = FUN_004f5d1a(hwnd,y,(HWND)hdc,arg_4);
    return uVar2;
  }
  return 0;
}


