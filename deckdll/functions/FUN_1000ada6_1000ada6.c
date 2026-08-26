/*
 * Decompiled function: FUN_1000ada6
 * Entry Point: 1000ada6
 * Size: 748 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1000ada6(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  HWND pHVar1;
  HGDIOBJ buf_ptr_2;
  HBRUSH hbr;
  char *char_ptr_3;
  int nMaxCount;
  tagRECT local_158;
  int32_t local_148;
  HDC local_144;
  int local_13c;
  char local_138 [264];
  char local_30 [12];
  tagRECT local_24;
  tagRECT local_14;
  
  if (y < 0x111) {
    if (y == 0x110) {
      sprintf(local_30,&DAT_100411f4,DAT_101cfb9c);
      SetWindowTextA(hwnd,&DAT_10176320);
      char_ptr_3 = local_30;
      pHVar1 = GetDlgItem(hwnd,1000);
      SetWindowTextA(pHVar1,char_ptr_3);
      GetWindowRect(DAT_10176868,&local_24);
      GetWindowRect(hwnd,&local_14);
      SetWindowPos(hwnd,(HWND)0x0,
                   local_24.left +
                   ((local_24.right - local_24.left) - (local_14.right - local_14.left)) / 2,
                   local_24.top +
                   ((local_24.bottom - local_24.top) - (local_14.bottom - local_14.top)) / 2,0,0,5);
      sprintf(local_138,s__s_GAUN_Options_pic_100411f8,&DAT_10176870);
      DAT_10128a04 = (HANDLE)thunk_FUN_1003afa3(local_138);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_158);
      if (DAT_10128a04 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_158,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_158,DAT_10128a04);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        nMaxCount = 10;
        char_ptr_3 = local_30;
        pHVar1 = GetDlgItem(hwnd,1000);
        local_13c = GetWindowTextA(pHVar1,char_ptr_3,nMaxCount);
        local_30[local_13c] = '\0';
        DAT_10175ecc = atoi(local_30);
        EndDialog(hwnd,1);
        if (DAT_10128a04 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a04);
        }
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        if (DAT_10128a04 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a04);
        }
        DAT_10175ecc = 0;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_144 = hdc;
      thunk_FUN_10031425(hdc);
      local_148 = arg_4;
      SetBkMode(local_144,1);
      buf_ptr_2 = GetStockObject(5);
      return buf_ptr_2;
    }
  }
  return (HGDIOBJ)0x0;
}


