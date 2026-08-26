/*
 * Decompiled function: FUN_1002ee16
 * Entry Point: 1002ee16
 * Size: 1411 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1002ee16(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  uint8_t *pbVar1;
  HWND hWnd;
  uint32_t uval_2;
  HGDIOBJ buf_ptr_3;
  HBRUSH hbr;
  bool bVar4;
  undefined8 uval_5;
  int val_6;
  tagRECT local_204;
  int32_t local_1f4;
  HDC local_1f0;
  int local_1e8;
  uint8_t local_1e4 [204];
  char local_118 [264];
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      SetWindowTextA(hwnd,&DAT_1013ead8);
      local_10 = thunk_FUN_10034b40(s_menus_100464fc,s_ARTISTNAMES_100464f0);
      SendDlgItemMessageA(hwnd,0x3e9,0xb,0,0);
      val_6 = 0;
      hWnd = GetDlgItem(hwnd,0x3ef);
      ShowWindow(hWnd,val_6);
      if (local_10 != 0xffffffff) {
        local_8 = 0;
        for (local_c = 0;
            ((int)local_8 <= (int)local_10 >> 0x1f &&
            (((int)local_8 < (int)local_10 >> 0x1f || (local_c < local_10)))); local_c = local_c + 1
            ) {
          val_6 = __allmul(local_c,local_8,0x80,0);
          SendDlgItemMessageA(hwnd,0x3e9,0x180,0,(LPARAM)(&DAT_1016e4c0 + val_6));
          local_8 = local_8 + (0xfffffffe < local_c);
        }
      }
      local_8 = 0;
      for (local_c = 0;
          (uval_2 = DAT_101cf808, (int)local_8 < 1 && (((int)local_8 < 0 || (local_c < 0x34))));
          local_c = local_c + 1) {
        uval_5 = __allshl((uint8_t)local_c,0);
        if (((DAT_101cf80c & (uint32_t)((ulonglong)uval_5 >> 0x20)) == 0) && ((uval_2 & (uint32_t)uval_5) == 0)
           ) {
          SendDlgItemMessageA(hwnd,0x3e9,0x185,0,local_c);
        }
        else {
          SendDlgItemMessageA(hwnd,0x3e9,0x185,1,local_c);
        }
        local_8 = local_8 + (0xfffffffe < local_c);
      }
      SendDlgItemMessageA(hwnd,0x3e9,0x19e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
      sprintf(local_118,s__s_GAUN_Options_pic_10046504,&DAT_10176870);
      DAT_1013eac4 = (HANDLE)thunk_FUN_1003afa3(local_118);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_204);
      if (DAT_1013eac4 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_204,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_204,DAT_1013eac4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      uval_2 = (uint32_t)hdc & 0xffff;
      if (uval_2 < 0x3eb) {
        if (uval_2 == 0x3ea) {
          SendDlgItemMessageA(hwnd,0x3e9,0xb,0,0);
          local_c = 0x32;
          for (local_8 = 0; (-2 < (int)local_8 && (local_8 < 0x80000000)); local_8 = local_8 - bVar4
              ) {
            SendDlgItemMessageA(hwnd,0x3e9,0x185,1,local_c);
            bVar4 = local_c == 0;
            local_c = local_c + -1;
          }
          SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
          return (HGDIOBJ)0x1;
        }
        if (uval_2 == 1) {
          for (local_1e8 = 0; local_1e8 < 0x34; local_1e8 = local_1e8 + 1) {
            pbVar1 = local_1e4 + local_1e8 * 4;
            pbVar1[0] = 0xff;
            pbVar1[1] = 0xff;
            pbVar1[2] = 0xff;
            pbVar1[3] = 0xff;
          }
          SendDlgItemMessageA(hwnd,0x3e9,0x191,0x33,(LPARAM)local_1e4);
          DAT_101cf808 = 0;
          DAT_101cf80c = 0;
          for (local_1e8 = 0; local_1e8 < 0x34; local_1e8 = local_1e8 + 1) {
            if (*(int *)(local_1e4 + local_1e8 * 4) != -1) {
              uval_5 = __allshl(local_1e4[local_1e8 * 4],0);
              DAT_101cf808 = DAT_101cf808 | (uint32_t)uval_5;
              DAT_101cf80c = DAT_101cf80c | (uint32_t)((ulonglong)uval_5 >> 0x20);
            }
          }
          EndDialog(hwnd,1);
          return (HGDIOBJ)0x1;
        }
        if (uval_2 == 2) {
          EndDialog(hwnd,0);
          return (HGDIOBJ)0x1;
        }
      }
      else if (uval_2 == 0x3eb) {
        SendDlgItemMessageA(hwnd,0x3e9,0xb,0,0);
        local_8 = 0;
        for (local_c = 0; ((int)local_8 < 1 && (((int)local_8 < 0 || (local_c < 0x33))));
            local_c = local_c + 1) {
          SendDlgItemMessageA(hwnd,0x3e9,0x185,0,local_c);
          local_8 = local_8 + (0xfffffffe < local_c);
        }
        SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_1f0 = hdc;
      thunk_FUN_10031425(hdc);
      local_1f4 = arg_4;
      SetBkMode(local_1f0,1);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
  }
  return (HGDIOBJ)0x0;
}


