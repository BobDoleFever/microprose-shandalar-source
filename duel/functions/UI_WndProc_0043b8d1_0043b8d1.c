/*
 * Decompiled function: UI_WndProc_0043b8d1
 * Entry Point: 0043b8d1
 * Size: 2562 bytes
 */
#include "duel.h"


HGDIOBJ UI_WndProc_0043b8d1(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t c;
  int iVar1;
  BOOL BVar2;
  HGDIOBJ pvVar3;
  HBRUSH hbr;
  HWND pHVar4;
  HWND pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  tagSIZE *psizl;
  UINT UVar9;
  tagRECT *ptVar10;
  int local_420 [16];
  int local_3e0 [16];
  HDC local_3a0;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  int local_358;
  tagRECT local_354;
  int local_344;
  int local_340;
  HDC local_33c;
  HGDIOBJ local_338;
  tagRECT local_334;
  tagRECT local_324;
  CHAR local_314 [100];
  HWND local_2b0;
  int local_2ac;
  HDC local_2a8;
  WPARAM local_2a4 [16];
  WPARAM local_264 [16];
  uint local_224;
  uint local_220;
  int local_21c;
  int local_218;
  tagRECT local_214;
  int local_204;
  WPARAM local_200;
  HDC local_1fc;
  int local_1f8;
  int local_1f4;
  HGDIOBJ local_1f0;
  tagSIZE local_1ec;
  char local_1e4 [264];
  uint local_dc [50];
  tagRECT local_14;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_33c = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_324);
      local_338 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_33c,local_338);
      SetTextColor(local_33c,0);
      SetBkMode(local_33c,1);
      if (DAT_005168e0 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_33c,&local_324,hbr);
      }
      else {
        FUN_004709ae((int)local_33c,(int)&local_324,DAT_005168e0);
      }
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004709ae((int)local_33c,(int)&local_334,DAT_005168e8);
      GetDlgItemTextA(hwnd,0x43a,local_314,100);
      local_334.left =
           local_334.left +
           ((int)((local_334.bottom - local_334.top) +
                 (local_334.bottom - local_334.top >> 0x1f & 3U)) >> 2);
      DrawTextA(local_33c,local_314,-1,&local_334,0x24);
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004709ae((int)local_33c,(int)&local_334,DAT_005168e8);
      GetDlgItemTextA(hwnd,0x43b,local_314,100);
      local_334.left =
           local_334.left +
           ((int)((local_334.bottom - local_334.top) +
                 (local_334.bottom - local_334.top >> 0x1f & 3U)) >> 2);
      DrawTextA(local_33c,local_314,-1,&local_334,0x24);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      local_3a0 = BeginPaint(hwnd,&local_39c);
      if (local_3a0 != (HDC)0x0) {
        FUN_004707a4(local_3a0);
        FUN_00448897((int)local_420,&local_344,(int)local_3e0,&local_35c);
        if (local_344 != 0) {
          for (local_358 = 0; local_358 < local_344; local_358 = local_358 + 1) {
            FUN_0043c2dd(&local_354,hwnd,1,local_358);
            local_340 = local_420[local_358];
            FUN_0042053a(local_3a0,&local_354.left,(undefined4 *)(&DAT_00618ac0 + local_340 * 0x98),
                         0,0x12,0);
          }
        }
        if (local_35c != 0) {
          for (local_358 = 0; local_358 < local_35c; local_358 = local_358 + 1) {
            FUN_0043c2dd(&local_354,hwnd,0,local_358);
            local_340 = local_3e0[local_358];
            FUN_0042053a(local_3a0,&local_354.left,(undefined4 *)(&DAT_00618ac0 + local_340 * 0x98),
                         0,0x12,0);
          }
        }
        EndPaint(hwnd,&local_39c);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43c);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x439);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      ShowWindow(pHVar4,iVar8);
      _sprintf(local_1e4,s__s_WINBK_Ante_pic_004f7848,&DAT_006189a0);
      DAT_005168e0 = (HANDLE)FUN_0043d713(local_1e4);
      _sprintf(local_1e4,s__s_WINBK_AnteLabel_pic_004f785c,&DAT_006189a0);
      DAT_005168e8 = (HANDLE)FUN_0043d713(local_1e4);
      DAT_005168e4 = 0;
      FUN_00448412((char *)local_dc);
      FUN_004d9640(local_dc,(uint *)s_ante__004f7874);
      SetDlgItemTextA(hwnd,0x43a,(LPCSTR)local_dc);
      Mem_AllocOrFree_004d9630(local_dc,(uint *)s_Your_ante__004f787c);
      SetDlgItemTextA(hwnd,0x43b,(LPCSTR)local_dc);
      local_1fc = GetDC(hwnd);
      FUN_004707a4(local_1fc);
      local_1f0 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_1fc,local_1f0);
      GetDlgItemTextA(hwnd,0x43a,(LPSTR)local_dc,200);
      psizl = &local_1ec;
      c = _strlen((char *)local_dc);
      GetTextExtentPoint32A(local_1fc,(LPCSTR)local_dc,c,psizl);
      iVar8 = local_1ec.cy + local_1ec.cx;
      iVar1 = (local_1ec.cy * 3) / 2;
      UVar9 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      local_1f8 = iVar1;
      local_1f4 = iVar8;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      SetWindowPos(pHVar4,pHVar5,iVar6,iVar7,iVar8,iVar1,UVar9);
      UVar9 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar8 = local_1f4;
      iVar1 = local_1f8;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      SetWindowPos(pHVar4,pHVar5,iVar6,iVar7,iVar8,iVar1,UVar9);
      ReleaseDC(hwnd,local_1fc);
      GetWindowRect(hwnd,&local_14);
      UVar9 = 5;
      iVar6 = 0;
      iVar1 = 0;
      iVar8 = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(iVar8 * 0x14) / 100,local_14.top,iVar1,iVar6,UVar9);
      SetFocus(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x100) {
LAB_0043bb82:
      FUN_00471395(DAT_005168e0);
      FUN_00471395(DAT_005168e8);
      EndDialog(hwnd,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_2a8 = wParam;
      FUN_004707a4(wParam);
      local_2b0 = lParam;
      local_2ac = GetDlgCtrlID(lParam);
      SetBkMode(local_2a8,1);
      SetTextColor(local_2a8,DAT_005168e4);
      pvVar3 = GetStockObject(5);
      return pvVar3;
    }
    if (uMsg == 0x111) goto LAB_0043bb82;
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar3 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar3;
    }
    if (uMsg != 0x200) {
      if (uMsg == 0x201) {
        FUN_00471395(DAT_005168e0);
        FUN_00471395(DAT_005168e8);
        EndDialog(hwnd,0);
        return (HGDIOBJ)0x1;
      }
      if (uMsg != 0x204) {
        return (HGDIOBJ)0x0;
      }
    }
    FUN_00448897((int)local_2a4,&local_204,(int)local_264,&local_21c);
    local_224 = (uint)lParam & 0xffff;
    local_220 = (uint)lParam >> 0x10;
    if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
      local_200 = 0xffffffff;
      if (local_21c != 0) {
        while ((local_218 = local_21c + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          FUN_0043c2dd(&local_214,hwnd,0,local_218);
          pt.y = local_220;
          pt.x = local_224;
          BVar2 = PtInRect(&local_214,pt);
          local_21c = local_218;
          if (BVar2 != 0) {
            local_200 = local_264[local_218];
          }
        }
      }
      if (local_204 != 0) {
        while ((local_218 = local_204 + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          FUN_0043c2dd(&local_214,hwnd,1,local_218);
          pt_00.y = local_220;
          pt_00.x = local_224;
          BVar2 = PtInRect(&local_214,pt_00);
          local_204 = local_218;
          if (BVar2 != 0) {
            local_200 = local_2a4[local_218];
          }
        }
      }
      if (local_200 != 0xffffffff) {
        SendMessageA(DAT_006152e0,0x401,local_200,0);
      }
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


