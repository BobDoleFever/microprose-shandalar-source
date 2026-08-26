/*
 * Decompiled function: FUN_100273d2
 * Entry Point: 100273d2
 * Size: 1178 bytes
 */
#include "deckdll.h"


HGDIOBJ FUN_100273d2(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  int val_1;
  size_t len_2;
  HGDIOBJ buf_ptr_3;
  HBRUSH hbr;
  tagRECT local_438;
  int32_t local_428;
  HDC local_424;
  WPARAM local_41c;
  uint8_t local_418 [32];
  char local_3f8 [264];
  char local_2f0 [264];
  HWND local_1e8;
  int local_1e4;
  char local_1e0 [200];
  WPARAM local_118;
  FILE *local_114;
  char *local_110;
  char local_10c [264];
  
  if (y < 0x111) {
    if (y == 0x110) {
      local_1e8 = CreateWindowExA(0,s_LISTBOX_10045dc0,&DAT_10045dbc,0x40a00003,0,0,0,0,hwnd,
                                  (HMENU)0x0,DAT_101cf334,(LPVOID)0x0);
      if (local_1e8 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      strcpy(local_2f0,&DAT_101cf810);
      strcat(local_2f0,s____DCK_10045dc8);
      SendMessageA(local_1e8,0x18d,0,(LPARAM)local_2f0);
      local_1e4 = SendMessageA(local_1e8,0x18b,0,0);
      for (local_118 = 0; (int)local_118 < local_1e4; local_118 = local_118 + 1) {
        SendMessageA(local_1e8,0x189,local_118,(LPARAM)local_2f0);
        strcpy(local_3f8,&DAT_101cf810);
        strcat(local_3f8,&DAT_10045dd0);
        strcat(local_3f8,local_2f0);
        local_114 = fopen(local_3f8,&DAT_10045dd4);
        if (local_114 != (FILE *)0x0) {
          val_1 = fgetc(local_114);
          if (val_1 == 0x3b) {
            local_1e0[0] = '\0';
            len_2 = strlen(local_1e0);
            local_110 = local_1e0 + len_2;
            while( true ) {
              val_1 = fgetc(local_114);
              *local_110 = (char)val_1;
              if (*local_110 == '\n') break;
              local_110 = local_110 + 1;
            }
            *local_110 = '\0';
            fclose(local_114);
            SendDlgItemMessageA(hwnd,0x3eb,0x143,0,(LPARAM)local_1e0);
          }
          else {
            fclose(local_114);
          }
        }
      }
      SendDlgItemMessageA(hwnd,0x3eb,0x14e,0,0);
      sprintf(local_10c,s__s_GAUN_Results_pic_10045dd8,&DAT_10176870);
      DAT_1013e7fc = (HANDLE)thunk_FUN_1003afa3(local_10c);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      GetClientRect(hwnd,&local_438);
      if (DAT_1013e7fc == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hdc,&local_438,hbr);
      }
      else {
        thunk_FUN_1003162f((int)hdc,(int)&local_438,DAT_1013e7fc);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 1) {
        local_41c = SendDlgItemMessageA(hwnd,0x3eb,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3eb,0x148,local_41c,(LPARAM)local_418);
        sprintf(&DAT_10103ca0,s__s__s_dck_10045dec,&DAT_101cf810,local_418);
        if (DAT_1013e7fc != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_1013e7fc);
        }
        EndDialog(hwnd,1);
      }
      else if (((uint32_t)hdc & 0xffff) == 2) {
        if (DAT_1013e7fc != (HANDLE)0x0) {
          thunk_FUN_10032018(DAT_1013e7fc);
        }
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_424 = hdc;
      thunk_FUN_10031425(hdc);
      local_428 = arg_4;
      SetBkMode(local_424,1);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
  }
  return (HGDIOBJ)0x0;
}


