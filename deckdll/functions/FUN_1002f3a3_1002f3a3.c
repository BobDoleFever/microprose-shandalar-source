/*
 * Decompiled function: FUN_1002f3a3
 * Entry Point: 1002f3a3
 * Size: 1563 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1002f3a3(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  uint8_t flag_1;
  uint32_t uval_2;
  HGDIOBJ buf_ptr_3;
  HBRUSH hbr;
  tagRECT local_4bc;
  int32_t local_4ac;
  HDC local_4a8;
  int local_4a0;
  int local_49c;
  int local_498 [224];
  char local_118 [264];
  int local_10;
  int local_c;
  int local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      SetWindowTextA(hwnd,&DAT_1013ead8);
      local_8 = thunk_FUN_10034b40(s_menus_10046528,s_CREATURENAMES_10046518);
      SendDlgItemMessageA(hwnd,0x3e9,0xb,0,0);
      if ((DAT_101cf7d4 & 0x800) != 0) {
        SendDlgItemMessageA(hwnd,0x3ef,0xf1,1,0);
      }
      if (local_8 != -1) {
        for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
          SendDlgItemMessageA(hwnd,0x3e9,0x180,0,(LPARAM)(&DAT_1016e4c0 + local_c * 0x80));
        }
      }
      for (local_10 = 0; local_10 < 7; local_10 = local_10 + 1) {
        for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
          if ((*(uint32_t *)(&DAT_101cf7d8 + local_10 * 4) & 1 << ((uint8_t)local_c & 0x1f)) == 0) {
            SendDlgItemMessageA(hwnd,0x3e9,0x185,0,local_10 * 0x20 + local_c);
          }
          else {
            SendDlgItemMessageA(hwnd,0x3e9,0x185,1,local_10 * 0x20 + local_c);
          }
        }
      }
      SendDlgItemMessageA(hwnd,0x3e9,0x19e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
      sprintf(local_118,s__s_GAUN_Options_pic_10046530,&DAT_10176870);
      DAT_1013eaac = (HANDLE)thunk_FUN_1003afa3(local_118);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_4bc);
      if (DAT_1013eaac == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_4bc,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_4bc,DAT_1013eaac);
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
          for (local_c = 0xdc; -1 < local_c; local_c = local_c + -1) {
            SendDlgItemMessageA(hwnd,0x3e9,0x185,1,local_c);
          }
          SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
          return (HGDIOBJ)0x1;
        }
        if (uval_2 == 1) {
          for (local_49c = 0; local_49c < 0xe0; local_49c = local_49c + 1) {
            local_498[local_49c] = -1;
          }
          SendDlgItemMessageA(hwnd,0x3e9,0x191,0xdd,(LPARAM)local_498);
          for (local_49c = 0; local_49c < 7; local_49c = local_49c + 1) {
            *(int32_t *)(&DAT_101cf7d8 + local_49c * 4) = 0;
          }
          for (local_4a0 = 0; local_4a0 < 7; local_4a0 = local_4a0 + 1) {
            for (local_49c = 0; local_49c < 0xdd; local_49c = local_49c + 1) {
              if (((local_498[local_49c] != -1) && (local_4a0 * 0x20 <= local_498[local_49c])) &&
                 (local_498[local_49c] < (local_4a0 + 1) * 0x20)) {
                flag_1 = (uint8_t)(local_498[local_49c] >> 0x1f);
                *(uint32_t *)(&DAT_101cf7d8 + local_4a0 * 4) =
                     *(uint32_t *)(&DAT_101cf7d8 + local_4a0 * 4) |
                     1 << ((((uint8_t)local_498[local_49c] ^ flag_1) - flag_1 & 0x1f ^ flag_1) - flag_1 &
                          0x1f);
              }
            }
          }
          if (DAT_1013eaac != (HANDLE)0x0) {
            thunk_FUN_10032018(DAT_1013eaac);
          }
          EndDialog(hwnd,1);
          return (HGDIOBJ)0x1;
        }
        if (uval_2 == 2) {
          if (DAT_1013eaac != (HANDLE)0x0) {
            thunk_FUN_10032018(DAT_1013eaac);
          }
          EndDialog(hwnd,0);
          return (HGDIOBJ)0x1;
        }
      }
      else {
        if (uval_2 == 0x3eb) {
          SendDlgItemMessageA(hwnd,0x3e9,0xb,0,0);
          for (local_c = 0; local_c < 0xdd; local_c = local_c + 1) {
            SendDlgItemMessageA(hwnd,0x3e9,0x185,0,local_c);
          }
          SendDlgItemMessageA(hwnd,0x3e9,0xb,1,0);
          return (HGDIOBJ)0x1;
        }
        if (uval_2 == 0x3ef) {
          DAT_101cf7d4 = DAT_101cf7d4 ^ 0x800;
          return (HGDIOBJ)0x1;
        }
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_4a8 = hdc;
      thunk_FUN_10031425(hdc);
      local_4ac = arg_4;
      SetBkMode(local_4a8,1);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
  }
  return (HGDIOBJ)0x0;
}


