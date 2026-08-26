/*
 * Decompiled function: Pic_Load_0044a862
 * Entry Point: 0044a862
 * Size: 2560 bytes
 */
#include "magic.h"


HGDIOBJ Pic_Load_0044a862(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

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
  char local_dc [200];
  tagRECT local_14;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_33c = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_324);
      local_338 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_33c,local_338);
      SetTextColor(local_33c,0);
      SetBkMode(local_33c,1);
      if (DAT_00538bc0 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_33c,&local_324,hbr);
      }
      else {
        FUN_004f3b5f((int)local_33c,(int)&local_324,DAT_00538bc0);
      }
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004f3b5f((int)local_33c,(int)&local_334,DAT_00538bc8);
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
      FUN_004f3b5f((int)local_33c,(int)&local_334,DAT_00538bc8);
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
        FUN_004f3955(local_3a0);
        Ai_Subsystem_004b73ce((int)local_420,&local_344,(int)local_3e0,&local_35c);
        if (local_344 != 0) {
          for (local_358 = 0; local_358 < local_344; local_358 = local_358 + 1) {
            Pic_Subsystem_0044b26c(&local_354,hwnd,1,local_358);
            local_340 = local_420[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(WPARAM *)(&DAT_006b3070 + local_340 * 0x98),0,0x12
                       ,0);
          }
        }
        if (local_35c != 0) {
          for (local_358 = 0; local_358 < local_35c; local_358 = local_358 + 1) {
            Pic_Subsystem_0044b26c(&local_354,hwnd,0,local_358);
            local_340 = local_3e0[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(WPARAM *)(&DAT_006b3070 + local_340 * 0x98),0,0x12
                       ,0);
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
      sprintf(local_1e4,s__s_WINBK_Ante_pic_00522338,&DAT_006b2e90);
      DAT_00538bc0 = (HANDLE)Pic_Load_00423833(local_1e4);
      sprintf(local_1e4,s__s_WINBK_AnteLabel_pic_0052234c,&DAT_006b2e90);
      DAT_00538bc8 = (HANDLE)Pic_Load_00423833(local_1e4);
      DAT_00538bc4 = 0;
      Ai_Subsystem_004b6f49(local_dc);
      strcat(local_dc,s_ante__00522364);
      SetDlgItemTextA(hwnd,0x43a,local_dc);
      strcpy(local_dc,s_Your_ante__0052236c);
      SetDlgItemTextA(hwnd,0x43b,local_dc);
      local_1fc = GetDC(hwnd);
      FUN_004f3955(local_1fc);
      local_1f0 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_1fc,local_1f0);
      GetDlgItemTextA(hwnd,0x43a,local_dc,200);
      psizl = &local_1ec;
      c = strlen(local_dc);
      GetTextExtentPoint32A(local_1fc,local_dc,c,psizl);
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
LAB_0044ab14:
      FUN_004f4548(DAT_00538bc0);
      FUN_004f4548(DAT_00538bc8);
      EndDialog(hwnd,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_2a8 = wParam;
      FUN_004f3955(wParam);
      local_2b0 = lParam;
      local_2ac = GetDlgCtrlID(lParam);
      SetBkMode(local_2a8,1);
      SetTextColor(local_2a8,DAT_00538bc4);
      pvVar3 = GetStockObject(5);
      return pvVar3;
    }
    if (uMsg == 0x111) goto LAB_0044ab14;
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar3 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar3;
    }
    if (uMsg != 0x200) {
      if (uMsg == 0x201) {
        FUN_004f4548(DAT_00538bc0);
        FUN_004f4548(DAT_00538bc8);
        EndDialog(hwnd,0);
        return (HGDIOBJ)0x1;
      }
      if (uMsg != 0x204) {
        return (HGDIOBJ)0x0;
      }
    }
    Ai_Subsystem_004b73ce((int)local_2a4,&local_204,(int)local_264,&local_21c);
    local_224 = (uint)lParam & 0xffff;
    local_220 = (uint)lParam >> 0x10;
    if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
      local_200 = 0xffffffff;
      if (local_21c != 0) {
        while ((local_218 = local_21c + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          Pic_Subsystem_0044b26c(&local_214,hwnd,0,local_218);
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
          Pic_Subsystem_0044b26c(&local_214,hwnd,1,local_218);
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
        SendMessageA(DAT_0069f744,0x401,local_200,0);
      }
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


