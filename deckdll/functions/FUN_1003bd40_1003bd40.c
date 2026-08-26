/*
 * Decompiled function: FUN_1003bd40
 * Entry Point: 1003bd40
 * Size: 757 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HGDIOBJ FUN_1003bd40(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  HGDIOBJ buf_ptr_1;
  tagRECT local_14c;
  int32_t local_13c;
  HDC local_138;
  HDC local_130;
  char local_12c [264];
  uint8_t local_24 [4];
  int local_20;
  int local_1c;
  int local_c;
  int local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      sprintf(local_12c,s__s_GAUN_Options_pic_1004bbe4,&DAT_10176870);
      DAT_1013ee08 = (HANDLE)thunk_FUN_1003afa3(local_12c);
      memcpy(&DAT_1013ecc8,&DAT_1004bba8,0x3c);
      _DAT_1013ecc8 = 0x1e;
      strcpy(&DAT_1013ece4,s_Cheltenham_ITC_Bold_BT_1004bbf8);
      DAT_1013ee04 = CreateFontIndirectA((LOGFONTA *)&DAT_1013ecc8);
      DAT_1013ee4c = 0x2f6f7f7;
      DAT_1013ee5c = 0x2efb2ae;
      DAT_1013ee60 = 0x28fb0cd;
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_14c);
      local_130 = CreateCompatibleDC(hdc);
      thunk_FUN_10031425(local_130);
      SelectObject(local_130,FUN_101cdebc);
      GetObjectA(FUN_101cdebc,0x18,local_24);
      for (local_8 = 0; local_8 < local_14c.right; local_8 = local_8 + local_20) {
        for (local_c = 0; local_c < local_14c.bottom; local_c = local_c + local_1c) {
          BitBlt(hdc,local_8,local_c,local_20,local_1c,local_130,0,0,0xcc0020);
        }
      }
      thunk_FUN_1003c03a(hdc,local_14c.left,local_14c.top,local_14c.right,local_14c.bottom,
                         DAT_1013ee04);
      DeleteDC(local_130);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if ((((uint32_t)hdc & 0xffff) == 1) || (((uint32_t)hdc & 0xffff) == 2)) {
        DeleteObject(DAT_1013ee04);
        if (DAT_1013ee08 != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_1013ee08);
        }
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_138 = hdc;
      thunk_FUN_10031425(hdc);
      local_13c = arg_4;
      SetBkMode(local_138,1);
      buf_ptr_1 = GetStockObject(5);
      return buf_ptr_1;
    }
  }
  return (HGDIOBJ)0x0;
}


