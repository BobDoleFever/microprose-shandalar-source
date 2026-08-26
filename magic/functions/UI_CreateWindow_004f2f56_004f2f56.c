/*
 * Decompiled function: UI_CreateWindow_004f2f56
 * Entry Point: 004f2f56
 * Size: 1561 bytes
 */
#include "magic.h"


HGDIOBJ UI_CreateWindow_004f2f56(HWND hwnd,uint y,HDC hdc,HWND param_4)

{
  size_t sVar1;
  int iVar2;
  HWND pHVar3;
  UINT UVar4;
  HGDIOBJ pvVar5;
  HBRUSH hbr;
  tagRECT local_334;
  HWND local_324;
  int local_320;
  HDC local_31c;
  WPARAM local_314;
  undefined1 local_310 [32];
  char local_2f0 [264];
  char local_1e8 [264];
  HWND local_e0;
  int local_dc;
  char local_d8 [200];
  WPARAM local_10;
  FILE *local_c;
  char *local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      DAT_0061d7e8 = param_4;
      local_e0 = CreateWindowExA(0,s_LISTBOX_00530150,&DAT_0053014c,0x40a00003,0,0,0,0,hwnd,
                                 (HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_e0 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      strcpy(local_1e8,&DAT_006ff1b0);
      strcat(local_1e8,s____DCK_00530158);
      SendMessageA(local_e0,0x18d,0,(LPARAM)local_1e8);
      local_dc = SendMessageA(local_e0,0x18b,0,0);
      for (local_10 = 0; (int)local_10 < local_dc; local_10 = local_10 + 1) {
        SendMessageA(local_e0,0x189,local_10,(LPARAM)local_1e8);
        strcpy(local_2f0,&DAT_006ff1b0);
        strcat(local_2f0,&DAT_00530160);
        strcat(local_2f0,local_1e8);
        local_c = fopen(local_2f0,&DAT_00530164);
        if (local_c != (FILE *)0x0) {
          local_d8[0] = '\0';
          sVar1 = strlen(local_d8);
          local_8 = local_d8 + sVar1;
          while( true ) {
            iVar2 = fgetc(local_c);
            *local_8 = (char)iVar2;
            if (*local_8 == '\n') break;
            local_8 = local_8 + 1;
          }
          *local_8 = '\0';
          fclose(local_c);
          SendDlgItemMessageA(hwnd,1000,0x143,0,(LPARAM)local_d8);
          SendDlgItemMessageA(hwnd,0x3e9,0x143,0,(LPARAM)local_d8);
        }
      }
      SendDlgItemMessageA(hwnd,1000,0x14e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0x14e,0,0);
      if ((DAT_0061d7e8[0x83].unused < 0) || (3 < DAT_0061d7e8[0x83].unused)) {
        DAT_0061d7e8[0x83].unused = 1;
      }
      CheckRadioButton(hwnd,0x3eb,0x3ee,DAT_0061d7e8[0x83].unused + 0x3eb);
      pHVar3 = GetDlgItem(hwnd,1);
      SetFocus(pHVar3);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      FUN_004f3955(hdc);
      GetClientRect(hwnd,&local_334);
      hbr = GetStockObject(1);
      FillRect(hdc,&local_334,hbr);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint)hdc & 0xffff) == 0x3ef) {
        FUN_004ff450(g_MainAppHwnd);
        pHVar3 = GetDlgItem(hwnd,1);
        SetFocus(pHVar3);
      }
      else if (((uint)hdc & 0xffff) == 1) {
        local_314 = SendDlgItemMessageA(hwnd,1000,0x147,0,0);
        SendDlgItemMessageA(hwnd,1000,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)DAT_0061d7e8,s__s__s_dck_00530168,&DAT_006ff1b0,local_310);
        local_314 = SendDlgItemMessageA(hwnd,0x3e9,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3e9,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)((int)&DAT_0061d7e8[0x41].unused + 1),s__s__s_dck_00530174,&DAT_006ff1b0,
                local_310);
        UVar4 = IsDlgButtonChecked(hwnd,0x3eb);
        if (UVar4 == 0) {
          UVar4 = IsDlgButtonChecked(hwnd,0x3ec);
          if (UVar4 == 0) {
            UVar4 = IsDlgButtonChecked(hwnd,0x3ed);
            if (UVar4 == 0) {
              UVar4 = IsDlgButtonChecked(hwnd,0x3ee);
              if (UVar4 != 0) {
                DAT_0061d7e8[0x83].unused = 3;
              }
            }
            else {
              DAT_0061d7e8[0x83].unused = 2;
            }
          }
          else {
            DAT_0061d7e8[0x83].unused = 1;
          }
        }
        else {
          DAT_0061d7e8[0x83].unused = 0;
        }
        EndDialog(hwnd,1);
      }
      else if (((uint)hdc & 0xffff) == 0x471) {
        FUN_0048c72a(1);
        g_IsAiThinking = 0xfffffffe;
        EndDialog(hwnd,0);
      }
      else if (((uint)hdc & 0xffff) == 0x472) {
        FUN_0048c72a(0);
        g_IsAiThinking = 0xffffffff;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_31c = hdc;
      FUN_004f3955(hdc);
      local_324 = param_4;
      local_320 = GetDlgCtrlID(param_4);
      if (local_320 != 0x3ea) {
        SetBkMode(local_31c,1);
        pvVar5 = GetStockObject(5);
        return pvVar5;
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}


