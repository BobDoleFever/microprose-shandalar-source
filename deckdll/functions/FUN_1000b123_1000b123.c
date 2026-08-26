/*
 * Decompiled function: FUN_1000b123
 * Entry Point: 1000b123
 * Size: 1654 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1000b123(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  HWND pHVar1;
  LRESULT LVar2;
  HGDIOBJ buf_ptr_3;
  HBRUSH hbr;
  UINT UVar4;
  WPARAM WVar5;
  LPSTR pCVar6;
  LPCSTR pCVar7;
  LPARAM LVar8;
  char *pcVar9;
  int iVar10;
  tagRECT local_12c;
  int32_t local_11c;
  HDC local_118;
  uint32_t local_110;
  char local_10c [264];
  
  if (y < 0x111) {
    if (y == 0x110) {
      pCVar7 = &DAT_10162630;
      pHVar1 = GetDlgItem(hwnd,0x3fa);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x1c;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3fa);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pCVar7 = &DAT_1016264f;
      pHVar1 = GetDlgItem(hwnd,0x3f7);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x12;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3f7);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pCVar7 = &DAT_10162664;
      pHVar1 = GetDlgItem(hwnd,0x3f8);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x4e;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3f8);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pCVar7 = &DAT_101626b5;
      pHVar1 = GetDlgItem(hwnd,0x3f9);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x4e;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3f9);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pCVar7 = &DAT_10162706;
      pHVar1 = GetDlgItem(hwnd,0x3fb);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x13;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3fb);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pcVar9 = s_4th_Edition_10041238;
      pHVar1 = GetDlgItem(hwnd,0x3ff);
      SetWindowTextA(pHVar1,pcVar9);
      LVar8 = 0;
      WVar5 = 0xd;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3ff);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      pCVar7 = &DAT_10162730;
      pHVar1 = GetDlgItem(hwnd,0x3fc);
      SetWindowTextA(pHVar1,pCVar7);
      LVar8 = 0;
      WVar5 = 0x18e;
      UVar4 = 0xc5;
      pHVar1 = GetDlgItem(hwnd,0x3fc);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      for (local_110 = 0; local_110 < 0x37; local_110 = local_110 + 1) {
        pcVar9 = s_Witch_10040d28 + local_110 * 0x14;
        WVar5 = 0;
        UVar4 = 0x143;
        pHVar1 = GetDlgItem(hwnd,0x403);
        SendMessageA(pHVar1,UVar4,WVar5,(LPARAM)pcVar9);
      }
      LVar8 = 0;
      WVar5 = DAT_1016271c - 1;
      UVar4 = 0x14e;
      pHVar1 = GetDlgItem(hwnd,0x403);
      SendMessageA(pHVar1,UVar4,WVar5,LVar8);
      sprintf(local_10c,s__s_GAUN_Results_pic_10041244,&DAT_10176870);
      DAT_10128a08 = (HANDLE)thunk_FUN_1003afa3(local_10c);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_12c);
      if (DAT_10128a08 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_12c,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_12c,DAT_10128a08);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        iVar10 = 0x105;
        pcVar9 = local_10c;
        pHVar1 = GetDlgItem(hwnd,0x3fa);
        local_110 = GetWindowTextA(pHVar1,pcVar9,iVar10);
        local_10c[local_110] = '\0';
        iVar10 = strcmp(local_10c,&DAT_10162630);
        if (iVar10 != 0) {
          DAT_1016a618 = 1;
          DAT_10176478 = 1;
        }
        strcpy(&DAT_10162630,local_10c);
        local_110 = 0;
        iVar10 = 0x15;
        pCVar6 = &DAT_1016264f;
        pHVar1 = GetDlgItem(hwnd,0x3f7);
        iVar10 = GetWindowTextA(pHVar1,pCVar6,iVar10);
        (&DAT_1016264f)[iVar10] = 0;
        local_110 = 0;
        iVar10 = 0x51;
        pCVar6 = &DAT_10162664;
        pHVar1 = GetDlgItem(hwnd,0x3f8);
        iVar10 = GetWindowTextA(pHVar1,pCVar6,iVar10);
        (&DAT_10162664)[iVar10] = 0;
        local_110 = 0;
        iVar10 = 0x51;
        pCVar6 = &DAT_101626b5;
        pHVar1 = GetDlgItem(hwnd,0x3f9);
        iVar10 = GetWindowTextA(pHVar1,pCVar6,iVar10);
        (&DAT_101626b5)[iVar10] = 0;
        local_110 = 0;
        iVar10 = 0x16;
        pCVar6 = &DAT_10162706;
        pHVar1 = GetDlgItem(hwnd,0x3fb);
        local_110 = GetWindowTextA(pHVar1,pCVar6,iVar10);
        (&DAT_10162706)[local_110] = 0;
        LVar8 = 0;
        WVar5 = 0;
        UVar4 = 0x147;
        pHVar1 = GetDlgItem(hwnd,0x403);
        LVar2 = SendMessageA(pHVar1,UVar4,WVar5,LVar8);
        DAT_1016271c = LVar2 + 1;
        iVar10 = 0x10;
        pCVar6 = &DAT_10162720;
        pHVar1 = GetDlgItem(hwnd,0x3ff);
        GetWindowTextA(pHVar1,pCVar6,iVar10);
        local_110 = 0;
        iVar10 = 0x191;
        pCVar6 = &DAT_10162730;
        pHVar1 = GetDlgItem(hwnd,0x3fc);
        local_110 = GetWindowTextA(pHVar1,pCVar6,iVar10);
        (&DAT_10162730)[local_110] = 0;
        strcpy(&DAT_101cf340,&DAT_101cf810);
        strcat(&DAT_101cf340,&DAT_10041258);
        strcat(&DAT_101cf340,&DAT_10162630);
        strcat(&DAT_101cf340,&DAT_1004125c);
        EndDialog(hwnd,1);
        if (DAT_10128a08 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a08);
        }
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        if (DAT_10128a08 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a08);
        }
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_118 = hdc;
      thunk_FUN_10031425(hdc);
      local_11c = arg_4;
      SetBkMode(local_118,1);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
  }
  return (HGDIOBJ)0x0;
}


