/*
 * Decompiled function: FUN_1000b82a
 * Entry Point: 1000b82a
 * Size: 846 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_1000b82a(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  int val_1;
  HGDIOBJ buf_ptr_2;
  HBRUSH hbr;
  tagRECT local_134;
  int32_t local_124;
  HDC local_120;
  char local_118 [264];
  int local_10;
  int local_c;
  int local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      local_8 = 0;
      local_c = 0;
      while (local_8 == 0) {
        if (*(int *)(&DAT_10176490 + local_c * 0xc) == -1) {
          local_8 = 1;
        }
        else {
          val_1 = local_c * 0xc;
          local_c = local_c + 1;
          SendDlgItemMessageA(hwnd,0x413,0x180,0,*(LPARAM *)(&DAT_10176498 + val_1));
        }
      }
      sprintf(local_118,s__s_GAUN_Results_pic_10041290,&DAT_10176870);
      DAT_10128a0c = (HANDLE)thunk_FUN_1003afa3(local_118);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_134);
      if (DAT_10128a0c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_134,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_134,DAT_10128a0c);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        local_8 = 0;
        local_c = 0;
        while (local_8 == 0) {
          if (*(int *)(&DAT_10176490 + local_c * 0xc) == -1) {
            local_8 = 1;
          }
          else {
            for (local_10 = 0; local_10 < DAT_101cf920; local_10 = local_10 + 1) {
              if (((*(int *)(&DAT_10176490 + local_c * 0xc) == (&DAT_1016a620)[local_10 * 4]) &&
                  (*(int *)(&DAT_1016a628 + local_10 * 0x10) == 0)) &&
                 (0 < *(int *)(&DAT_10176494 + local_c * 0xc))) {
                *(int32_t *)(&DAT_1016a628 + local_10 * 0x10) = 1;
                *(uint32_t *)(&DAT_1016a62c + local_10 * 0x10) =
                     *(uint32_t *)(&DAT_1016a62c + local_10 * 0x10) & ~(1 << (DAT_10162904 & 0x1f));
                *(int *)(&DAT_10176494 + local_c * 0xc) =
                     *(int *)(&DAT_10176494 + local_c * 0xc) + -1;
              }
            }
            local_c = local_c + 1;
          }
        }
        EndDialog(hwnd,1);
        if (DAT_10128a0c != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a0c);
        }
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        if (DAT_10128a0c != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_10128a0c);
        }
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_120 = hdc;
      thunk_FUN_10031425(hdc);
      local_124 = arg_4;
      SetBkMode(local_120,1);
      buf_ptr_2 = GetStockObject(5);
      return buf_ptr_2;
    }
  }
  return (HGDIOBJ)0x0;
}


