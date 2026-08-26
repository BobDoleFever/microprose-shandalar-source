/*
 * Decompiled function: FUN_1000bc09
 * Entry Point: 1000bc09
 * Size: 912 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1000bc09(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  uint32_t uval_1;
  HWND pHVar2;
  UINT UVar3;
  HGDIOBJ pvVar4;
  HBRUSH hbr;
  tagRECT local_128;
  int32_t local_118;
  HDC local_114;
  char local_10c [264];
  
  if (y < 0x111) {
    if (y == 0x110) {
      uval_1 = DAT_101cfb9c & 1;
      pHVar2 = GetDlgItem(hwnd,0x418);
      EnableWindow(pHVar2,uval_1);
      uval_1 = (DAT_101cfb9c & 2) >> 1;
      pHVar2 = GetDlgItem(hwnd,0x417);
      EnableWindow(pHVar2,uval_1);
      uval_1 = (DAT_101cfb9c & 4) >> 2;
      pHVar2 = GetDlgItem(hwnd,0x416);
      EnableWindow(pHVar2,uval_1);
      uval_1 = (DAT_101cfb9c & 8) >> 3;
      pHVar2 = GetDlgItem(hwnd,0x415);
      EnableWindow(pHVar2,uval_1);
      uval_1 = (DAT_101cfb9c & 0x10) >> 4;
      pHVar2 = GetDlgItem(hwnd,0x414);
      EnableWindow(pHVar2,uval_1);
      uval_1 = (DAT_101cfb9c & 0x20) >> 5;
      pHVar2 = GetDlgItem(hwnd,0x419);
      EnableWindow(pHVar2,uval_1);
      sprintf(local_10c,s__s_GAUN_Options_pic_100412d0,&DAT_10176870);
      DAT_10128a10 = (HANDLE)thunk_FUN_1003afa3(local_10c);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_128);
      if (DAT_10128a10 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_128,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_128,DAT_10128a10);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        DAT_10175ecc = 0;
        UVar3 = IsDlgButtonChecked(hwnd,0x418);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 1;
        }
        UVar3 = IsDlgButtonChecked(hwnd,0x417);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 2;
        }
        UVar3 = IsDlgButtonChecked(hwnd,0x416);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 4;
        }
        UVar3 = IsDlgButtonChecked(hwnd,0x415);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 8;
        }
        UVar3 = IsDlgButtonChecked(hwnd,0x414);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 0x10;
        }
        UVar3 = IsDlgButtonChecked(hwnd,0x419);
        if (UVar3 != 0) {
          DAT_10175ecc = DAT_10175ecc | 0x20;
        }
        if (DAT_10128a10 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a10);
        }
        EndDialog(hwnd,1);
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        if (DAT_10128a10 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a10);
        }
        DAT_10175ecc = 0;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_114 = hdc;
      thunk_FUN_10031425(hdc);
      local_118 = arg_4;
      SetBkMode(local_114,1);
      pvVar4 = GetStockObject(5);
      return pvVar4;
    }
  }
  return (HGDIOBJ)0x0;
}


