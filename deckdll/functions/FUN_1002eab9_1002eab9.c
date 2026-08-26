/*
 * Decompiled function: FUN_1002eab9
 * Entry Point: 1002eab9
 * Size: 584 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1002eab9(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  HWND pHVar1;
  HGDIOBJ buf_ptr_2;
  HBRUSH hbr;
  char *char_ptr_3;
  int nMaxCount;
  tagRECT local_128;
  int32_t local_118;
  HDC local_114;
  char local_10c [264];
  
  if (y < 0x111) {
    if (y == 0x110) {
      sprintf(local_10c,&DAT_1004646c,DAT_101cfb9c);
      char_ptr_3 = local_10c;
      pHVar1 = GetDlgItem(hwnd,1000);
      SetWindowTextA(pHVar1,char_ptr_3);
      SetWindowTextA(hwnd,&DAT_1013ead8);
      sprintf(local_10c,s__s_GAUN_Options_pic_10046470,&DAT_10176870);
      DAT_1013eb0c = (HANDLE)thunk_FUN_1003afa3(local_10c);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_128);
      if (DAT_1013eb0c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_128,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_128,DAT_1013eb0c);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        nMaxCount = 0x105;
        char_ptr_3 = local_10c;
        pHVar1 = GetDlgItem(hwnd,1000);
        GetWindowTextA(pHVar1,char_ptr_3,nMaxCount);
        DAT_1013eaa8 = atoi(local_10c);
        EndDialog(hwnd,1);
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_114 = hdc;
      thunk_FUN_10031425(hdc);
      local_118 = arg_4;
      SetBkMode(local_114,1);
      buf_ptr_2 = GetStockObject(5);
      return buf_ptr_2;
    }
  }
  return (HGDIOBJ)0x0;
}


