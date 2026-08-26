/*
 * Decompiled function: FUN_004498e5
 * Entry Point: 004498e5
 * Size: 2209 bytes
 */
#include "duel.h"


HGDIOBJ FUN_004498e5(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  POINT pt;
  uint uVar1;
  UINT UVar2;
  undefined4 uVar3;
  HGDIOBJ pvVar4;
  HBRUSH hbr;
  HDC pHVar5;
  HWND pHVar6;
  int nCmdShow;
  BOOL BVar7;
  tagRECT *ptVar8;
  tagPAINTSTRUCT local_118;
  tagRECT local_d8;
  uint local_c8;
  uint local_c4;
  tagRECT local_c0;
  HWND local_b0;
  tagRECT local_ac;
  COLORREF local_9c;
  HWND local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_84;
  HWND local_80;
  uint local_7c;
  UINT local_78;
  UINT local_74;
  HWND local_70;
  char local_6c [100];
  UINT local_8;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_b0 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_ac);
      if (DAT_00516ad0 == 0) {
        hbr = GetStockObject(3);
        FillRect((HDC)local_b0,&local_ac,hbr);
      }
      else {
        FUN_004709ae(local_b0,&local_ac,DAT_00516ad0);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0xf) {
      pHVar5 = BeginPaint(param_1,&local_118);
      if ((pHVar5 != (HDC)0x0) && (FUN_004707a4(pHVar5), DAT_00516984 != 0xffffffff)) {
        ptVar8 = &local_d8;
        pHVar6 = GetDlgItem(param_1,0x475);
        GetWindowRect(pHVar6,ptVar8);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_d8,2);
        FUN_0042053a(pHVar5,&local_d8,&DAT_00618ac0 + DAT_00516984 * 0x98,0,0x11,0);
      }
      EndPaint(param_1,&local_118);
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      DAT_00516ac0 = param_4;
      DAT_00516984 = param_4[5].unused;
      nCmdShow = 0;
      pHVar6 = GetDlgItem(param_1,0x475);
      ShowWindow(pHVar6,nCmdShow);
      _sprintf(local_6c,s__max__d__004f7fb0,DAT_00516ac0->unused);
      SetDlgItemTextA(param_1,0x478,local_6c);
      _sprintf(local_6c,s__max__d__004f7fbc,DAT_00516ac0[1].unused);
      SetDlgItemTextA(param_1,0x47b,local_6c);
      FUN_0044a18b(&DAT_00516ad0,&DAT_00516ae0,&DAT_00516960,&DAT_005169f8,&DAT_00516ab4,
                   &DAT_005169d0,&DAT_00516b14);
      SendDlgItemMessageA(param_1,0x476,0x465,0,(uint)(ushort)DAT_00516ac0->unused);
      SendDlgItemMessageA(param_1,0x47a,0x465,0,(uint)(ushort)DAT_00516ac0[1].unused);
      SendDlgItemMessageA(param_1,0x476,0x467,0,(uint)(ushort)DAT_00516ac0[2].unused);
      SendDlgItemMessageA(param_1,0x47a,0x467,0,(uint)(ushort)DAT_00516ac0[3].unused);
      local_8 = FUN_0044a2c4(DAT_00516ac0[2].unused,DAT_00516ac0[3].unused);
      SetDlgItemInt(param_1,0x47c,local_8,1);
      pHVar6 = GetDlgItem(param_1,1);
      SetFocus(pHVar6);
      SendMessageA(param_1,0x401,1,0);
      local_70 = GetDlgItem(param_1,1);
      uVar1 = GetWindowLongA(local_70,-0x10);
      SetWindowLongA(local_70,-0x10,uVar1 | 0x800000);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x2b) {
      local_98 = param_4;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_98[5].unused) {
        local_9c = DAT_00516b14;
      }
      else {
        local_9c = DAT_005169d0;
      }
      FUN_00471f45(local_98,DAT_00516960,DAT_005169f8,DAT_00516ab4,local_9c,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_8c = param_3;
      FUN_004707a4(param_3);
      local_94 = param_4;
      local_90 = GetDlgCtrlID(param_4);
      pHVar6 = GetFocus();
      if (pHVar6 == local_94) {
        SetTextColor((HDC)local_8c,DAT_00516b14);
      }
      else {
        SetTextColor((HDC)local_8c,DAT_00516ae0);
      }
      if (((local_90 != 0x47c) && (local_90 != 0x49a)) && (local_90 != 0x49b)) {
        SetBkMode((HDC)local_8c,1);
        pvVar4 = GetStockObject(5);
        return pvVar4;
      }
      SetBkMode((HDC)local_8c,1);
      return DAT_00516960;
    }
    if (param_2 == 0x111) {
      local_7c = (uint)param_3 & 0xffff;
      if (local_7c == 1) {
        UVar2 = GetDlgItemInt(param_1,0x477,(BOOL *)0x0,0);
        *(UINT *)((int)DAT_00516ac0 + 8) = UVar2;
        local_74 = *(undefined4 *)((int)DAT_00516ac0 + 8);
        UVar2 = GetDlgItemInt(param_1,0x479,(BOOL *)0x0,0);
        *(UINT *)((int)DAT_00516ac0 + 0xc) = UVar2;
        local_78 = *(undefined4 *)((int)DAT_00516ac0 + 0xc);
        uVar3 = FUN_0044a2c4(local_74,local_78);
        *(undefined4 *)((int)DAT_00516ac0 + 0x10) = uVar3;
        FUN_0044a267(DAT_00516ad0,DAT_00516960,DAT_005169f8,DAT_00516ab4);
        EndDialog(param_1,1);
      }
      else if (local_7c == 2) {
        FUN_0044a267(DAT_00516ad0,DAT_00516960,DAT_005169f8,DAT_00516ab4);
        EndDialog(param_1,-2);
      }
      else if (((local_7c == 0x477) || (local_7c == 0x479)) && ((uint)param_3 >> 0x10 == 0x400)) {
        local_74 = GetDlgItemInt(param_1,0x477,(BOOL *)0x0,0);
        local_78 = GetDlgItemInt(param_1,0x479,(BOOL *)0x0,0);
        SetDlgItemInt(param_1,0x49a,local_74 - (local_78 - 1),1);
        SetDlgItemInt(param_1,0x49b,local_78 - 1,1);
        BVar7 = 1;
        UVar2 = FUN_0044a2c4(local_74,local_78);
        SetDlgItemInt(param_1,0x47c,UVar2,BVar7);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (param_2 < 0x312) {
      if (0x30e < param_2) {
        pvVar4 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
        return pvVar4;
      }
      if (param_2 != 0x200) {
        if (param_2 == 0x201) {
          SendMessageA(param_1,0x112,0xf012,0);
          return (HGDIOBJ)0x0;
        }
        if (param_2 != 0x204) {
          return (HGDIOBJ)0x0;
        }
      }
      local_c8 = (uint)param_4 & 0xffff;
      local_c4 = (uint)param_4 >> 0x10;
      if (((param_2 == 0x200) && (DAT_00663e24 != 2)) || ((param_2 == 0x204 && (DAT_00663e24 == 2)))
         ) {
        ptVar8 = &local_c0;
        pHVar6 = GetDlgItem(param_1,0x475);
        GetWindowRect(pHVar6,ptVar8);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_c0,2);
        if ((DAT_00516984 != 0xffffffff) &&
           (pt.y = local_c4, pt.x = local_c8, BVar7 = PtInRect(&local_c0,pt), BVar7 != 0)) {
          SendMessageA(DAT_006152e0,0x401,DAT_00516984,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x4c8) {
      local_80 = param_3;
      local_84 = param_4;
      pHVar6 = GetDlgItem(param_1,2);
      if (pHVar6 == local_80) {
        SendMessageA(param_1,0x401,2,0);
      }
      else {
        SendMessageA(param_1,0x401,1,0);
      }
      if (local_80 != (HWND)0x0) {
        InvalidateRect(local_80,(RECT *)0x0,1);
      }
      if (local_84 != (HWND)0x0) {
        InvalidateRect(local_84,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}


