/*
 * Decompiled function: FUN_0048f500
 * Entry Point: 0048f500
 * Size: 3217 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048f500(HWND param_1,uint param_2,HDC param_3,uint param_4)

{
  POINT pt;
  POINT pt_00;
  LRESULT LVar1;
  HBRUSH hbr;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  HWND pHVar5;
  undefined4 uVar6;
  size_t sVar7;
  HGDIOBJ ho;
  tagRECT *lpRect;
  char local_134 [12];
  HDC local_128;
  tagPAINTSTRUCT local_124;
  undefined4 local_e4;
  int local_e0;
  int local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
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
  undefined4 local_38;
  undefined4 local_34;
  HWND local_30;
  tagRECT local_2c;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_9c = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_98);
      if (DAT_005daf00 == 0) {
        hbr = GetStockObject(0);
        FillRect(local_9c,&local_98,hbr);
      }
      else {
        FUN_004709ae(local_9c,&local_98,DAT_005daf00);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      pHVar5 = GetDlgItem(param_1,0x3f1);
      UpdateWindow(pHVar5);
      local_128 = BeginPaint(param_1,&local_124);
      if (local_128 != (HDC)0x0) {
        FUN_004707a4(local_128);
        local_dc = FUN_00447184(*DAT_005dae18,DAT_005dae18[1]);
        uVar6 = FUN_00448304(*DAT_005dae18,DAT_005dae18[1]);
        local_e0 = CardIDFromType(uVar6);
        if (local_dc == -1) {
          if ((((local_e0 != -1) && (local_e0 != DAT_0068f108)) && (local_e0 != DAT_00666720)) &&
             (((local_e0 != DAT_00666450 && (local_e0 != DAT_00666444)) &&
              ((local_e0 != DAT_0066aae8 &&
               ((local_e0 != DAT_0068f0fc &&
                (FUN_0042053a(local_128,&DAT_005dae08,&DAT_00618ac0 + local_e0 * 0x98,0,0x12,0),
                DAT_005f77f0 != 0)))))))) {
            _sprintf(local_134,s__d__d_004fb138,*DAT_005dae18,DAT_005dae18[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 5,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 4,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        else {
          local_e4 = FUN_00486c12(local_dc,*DAT_005dae18,DAT_005dae18[1]);
          if (local_dc == DAT_0068f108) {
            FUN_0042043e(local_128,&DAT_005dae08);
          }
          else if ((((local_dc == DAT_00666720) || (local_dc == DAT_00666450)) ||
                   (local_dc == DAT_00666444)) || (local_dc == DAT_0066aae8)) {
            FUN_00422b2d(local_128,&DAT_005dae08,local_dc,*DAT_005dae18,DAT_005dae18[1]);
          }
          else if (DAT_0068f0fc == local_dc) {
            FUN_0042297a(local_128,&DAT_005dae08,*DAT_005dae18,DAT_005dae18[1]);
          }
          else {
            FUN_004215c2(local_128,&DAT_005dae08,&DAT_00618ac0 + local_dc * 0x98,*DAT_005dae18,
                         DAT_005dae18[1],0x12,0);
          }
          if (DAT_005f77f0 != 0) {
            _sprintf(local_134,s__d__d_004fb130,*DAT_005dae18,DAT_005dae18[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 5,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 4,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        EndPaint(param_1,&local_124);
      }
      return 1;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
LAB_0048fa2f:
      local_d0 = param_4 & 0xffff;
      local_cc = param_4 >> 0x10;
      if (((param_2 == 0x200) && (DAT_00663e24 != 2)) || ((param_2 == 0x204 && (DAT_00663e24 == 2)))
         ) {
        local_c8 = FUN_00447184(*DAT_005dae18,DAT_005dae18[1]);
        if ((DAT_005dae18[2] == -1) || (DAT_005dae18[3] == -1)) {
          local_c4 = 0xffffffff;
        }
        else {
          local_c4 = FUN_00447184(DAT_005dae18[2],DAT_005dae18[3]);
        }
        if ((local_c8 == 0xffffffff) ||
           (pt.y = local_cc, pt.x = local_d0, BVar4 = PtInRect((RECT *)&DAT_005dae08,pt), BVar4 == 0
           )) {
          if ((local_c4 != 0xffffffff) &&
             (pt_00.y = local_cc, pt_00.x = local_d0, BVar4 = PtInRect((RECT *)&DAT_005dae20,pt_00),
             BVar4 != 0)) {
            local_d8 = DAT_005dae18[2];
            local_d4 = DAT_005dae18[3];
            SendMessageA(DAT_006152e0,0x401,local_c4,(LPARAM)&local_d8);
          }
        }
        else {
          local_d8 = *DAT_005dae18;
          local_d4 = DAT_005dae18[1];
          SendMessageA(DAT_006152e0,0x401,local_c8,(LPARAM)&local_d8);
        }
      }
      return 0;
    }
    if (param_2 == 0x110) {
      _DAT_005dae30 = 0;
      if (DAT_0068f0b0 != 0) {
        SetTimer(param_1,1,2000,(TIMERPROC)0x0);
      }
      lpRect = &local_2c;
      pHVar5 = GetDlgItem(param_1,0x3f1);
      GetWindowRect(pHVar5,lpRect);
      MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_2c,2);
      GetClientRect(param_1,&local_14);
      local_1c = local_2c.top;
      local_18 = local_14.right - local_2c.right;
      InflateRect(&local_14,-local_2c.top,-local_18);
      CopyRect((LPRECT)&DAT_005dae08,&local_14);
      _DAT_005dae10 = local_2c.left - local_1c;
      CopyRect((LPRECT)&DAT_005dae20,&local_14);
      DAT_005dae20 = local_2c.left;
      DAT_005dae24 = local_2c.bottom;
      if (DAT_005dae2c - local_2c.bottom < DAT_005dae28 - local_2c.left) {
        DAT_005dae28 = (DAT_005dae2c - local_2c.bottom) + local_2c.left;
      }
      else {
        DAT_005dae2c = (DAT_005dae28 - local_2c.left) + local_2c.bottom;
      }
      DAT_005dae18 = (undefined4 *)param_4;
      SetDlgItemTextA(param_1,0x3f1,*(LPCSTR *)(param_4 + 0x10));
      SendDlgItemMessageA(param_1,0x3f1,0x401,*(WPARAM *)((int)DAT_005dae18 + 0x14),0);
      if (*(int *)((int)DAT_005dae18 + 8) != -1) {
        local_38 = *(undefined4 *)((int)DAT_005dae18 + 8);
        local_34 = *(undefined4 *)((int)DAT_005dae18 + 0xc);
        local_30 = CreateWindowExA(0,s_MAGICGAME_BigCardCardClass_004fb114,
                                   s_BigCard_small_card_004fb100,0x50000000,DAT_005dae20,
                                   DAT_005dae24,DAT_0061534c,DAT_0061898c,param_1,(HMENU)0x1,
                                   DAT_00664680,&local_38);
      }
      local_3c = (HANDLE)SendDlgItemMessageA(param_1,0x3f1,0x31,0,0);
      GetObjectA(local_3c,0x3c,&local_7c);
      local_7c.lfWeight = 700;
      local_40 = CreateFontIndirectA(&local_7c);
      SendDlgItemMessageA(param_1,0x3f1,0x30,(WPARAM)local_40,0);
      pHVar5 = GetDlgItem(param_1,0x3f1);
      SetFocus(pHVar5);
      LVar1 = SendDlgItemMessageA(param_1,0x3f1,0x400,0,0);
      if ((LVar1 == 0) || (*(int *)((int)DAT_005dae18 + 0x14) == 0)) {
        SetTimer(param_1,1,DAT_0060d498,(TIMERPROC)0x0);
      }
      return 0;
    }
    if (param_2 == 0x111) {
      if (((param_4 & 0xffff) == 1) || ((param_4 & 0xffff) == 2)) {
        pHVar5 = GetDlgItem(param_1,0x3f1);
        SendMessageA(param_1,0x111,0x3f1,(LPARAM)pHVar5);
      }
      else if (((uint)param_3 & 0xffff) == 0x3f1) {
        local_84 = (uint)param_3 >> 0x10;
        local_88 = SendDlgItemMessageA(param_1,0x3f1,0x400,0,0);
        if (local_84 == 0) {
          if ((local_88 == 0) || (DAT_005dae18[5] == 0)) {
            local_80 = (HGDIOBJ)SendDlgItemMessageA(param_1,0x3f1,0x31,0,0);
            SendDlgItemMessageA(param_1,0x3f1,0x30,0,0);
            DeleteObject(local_80);
            EndDialog(param_1,local_84);
          }
        }
        else {
          local_80 = (HGDIOBJ)SendDlgItemMessageA(param_1,0x3f1,0x31,0,0);
          SendDlgItemMessageA(param_1,0x3f1,0x30,0,0);
          DeleteObject(local_80);
          EndDialog(param_1,local_84);
        }
      }
      return 1;
    }
    if (param_2 == 0x113) {
      ho = (HGDIOBJ)SendDlgItemMessageA(param_1,0x3f1,0x31,0,0);
      SendDlgItemMessageA(param_1,0x3f1,0x30,0,0);
      DeleteObject(ho);
      EndDialog(param_1,0);
      return 1;
    }
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) goto LAB_0048fa2f;
    if (param_2 == 0x201) {
      GetWindowRect(param_1,&local_c0);
      SendMessageA(param_1,0x112,0xf012,0);
      GetWindowRect(param_1,&local_ac);
      iVar2 = FUN_004d9810(local_c0.top - local_ac.top);
      iVar3 = FUN_004d9810(local_c0.left - local_ac.left);
      local_b0 = (uint)(4 < iVar2 + iVar3);
      if (local_b0 == 0) {
        pHVar5 = GetDlgItem(param_1,0x3f1);
        SendMessageA(param_1,0x111,0x3f1,(LPARAM)pHVar5);
      }
      return 1;
    }
  }
  else if ((0x30e < param_2) && (param_2 < 0x312)) {
    uVar6 = FUN_00472b60(param_1,param_2,param_3,param_4);
    return uVar6;
  }
  return 0;
}


