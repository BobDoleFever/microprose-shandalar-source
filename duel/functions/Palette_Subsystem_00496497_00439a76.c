/*
 * Decompiled function: Palette_Subsystem_00496497
 * Entry Point: 00439a76
 * Size: 1556 bytes
 */
#include "duel.h"


HGDIOBJ Palette_Subsystem_00496497(HWND hwnd,uint y,HDC hdc,HWND param_4)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  HWND pHVar4;
  UINT UVar5;
  HGDIOBJ pvVar6;
  HBRUSH hbr;
  tagRECT local_334;
  HWND local_324;
  int local_320;
  HDC local_31c;
  WPARAM local_314;
  undefined1 local_310 [32];
  uint local_2f0 [66];
  uint local_1e8 [66];
  HWND local_e0;
  int local_dc;
  char local_d8 [200];
  WPARAM local_10;
  FILE *local_c;
  char *local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      DAT_005168d8 = param_4;
      local_e0 = CreateWindowExA(0,s_LISTBOX_004f771c,&DAT_004f7718,0x40a00003,0,0,0,0,hwnd,
                                 (HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      if (local_e0 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      Mem_AllocOrFree_004d9630(local_1e8,(uint *)&DAT_00664a60);
      FUN_004d9640(local_1e8,(uint *)s____DCK_004f7724);
      SendMessageA(local_e0,0x18d,0,(LPARAM)local_1e8);
      local_dc = SendMessageA(local_e0,0x18b,0,0);
      for (local_10 = 0; (int)local_10 < local_dc; local_10 = local_10 + 1) {
        SendMessageA(local_e0,0x189,local_10,(LPARAM)local_1e8);
        Mem_AllocOrFree_004d9630(local_2f0,(uint *)&DAT_00664a60);
        FUN_004d9640(local_2f0,(uint *)&DAT_004f772c);
        FUN_004d9640(local_2f0,local_1e8);
        local_c = _fopen((char *)local_2f0,&DAT_004f7730);
        if (local_c != (FILE *)0x0) {
          local_d8[0] = '\0';
          sVar2 = _strlen(local_d8);
          local_8 = local_d8 + sVar2;
          while( true ) {
            iVar3 = _fgetc(local_c);
            *local_8 = (char)iVar3;
            if (*local_8 == '\n') break;
            local_8 = local_8 + 1;
          }
          *local_8 = '\0';
          _fclose(local_c);
          SendDlgItemMessageA(hwnd,1000,0x143,0,(LPARAM)local_d8);
          SendDlgItemMessageA(hwnd,0x3e9,0x143,0,(LPARAM)local_d8);
        }
      }
      SendDlgItemMessageA(hwnd,1000,0x14e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0x14e,0,0);
      if ((DAT_005168d8[0x83].unused < 0) || (3 < DAT_005168d8[0x83].unused)) {
        DAT_005168d8[0x83].unused = 1;
      }
      CheckRadioButton(hwnd,0x3eb,0x3ee,DAT_005168d8[0x83].unused + 0x3eb);
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      FUN_004707a4(hdc);
      GetClientRect(hwnd,&local_334);
      hbr = GetStockObject(1);
      FillRect(hdc,&local_334,hbr);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint)hdc & 0xffff) == 0x3ef) {
        FUN_00480690(DAT_00618990);
        pHVar4 = GetDlgItem(hwnd,1);
        SetFocus(pHVar4);
      }
      else if (((uint)hdc & 0xffff) == 1) {
        local_314 = SendDlgItemMessageA(hwnd,1000,0x147,0,0);
        SendDlgItemMessageA(hwnd,1000,0x148,local_314,(LPARAM)local_310);
        _sprintf((char *)DAT_005168d8,s__s__s_dck_004f7734,&DAT_00664a60,local_310);
        local_314 = SendDlgItemMessageA(hwnd,0x3e9,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3e9,0x148,local_314,(LPARAM)local_310);
        _sprintf((char *)((int)DAT_005168d8 + 0x105),s__s__s_dck_004f7740,&DAT_00664a60,local_310);
        UVar5 = IsDlgButtonChecked(hwnd,0x3eb);
        if (UVar5 == 0) {
          UVar5 = IsDlgButtonChecked(hwnd,0x3ec);
          if (UVar5 == 0) {
            UVar5 = IsDlgButtonChecked(hwnd,0x3ed);
            if (UVar5 == 0) {
              UVar5 = IsDlgButtonChecked(hwnd,0x3ee);
              if (UVar5 != 0) {
                pcVar1 = (char *)DAT_005168d8;
                pcVar1[0x20c] = '\x03';
                pcVar1[0x20d] = '\0';
                pcVar1[0x20e] = '\0';
                pcVar1[0x20f] = '\0';
              }
            }
            else {
              pcVar1 = (char *)DAT_005168d8;
              pcVar1[0x20c] = '\x02';
              pcVar1[0x20d] = '\0';
              pcVar1[0x20e] = '\0';
              pcVar1[0x20f] = '\0';
            }
          }
          else {
            pcVar1 = (char *)DAT_005168d8;
            pcVar1[0x20c] = '\x01';
            pcVar1[0x20d] = '\0';
            pcVar1[0x20e] = '\0';
            pcVar1[0x20f] = '\0';
          }
        }
        else {
          pcVar1 = (char *)DAT_005168d8;
          pcVar1[0x20c] = '\0';
          pcVar1[0x20d] = '\0';
          pcVar1[0x20e] = '\0';
          pcVar1[0x20f] = '\0';
        }
        EndDialog(hwnd,1);
      }
      else if (((uint)hdc & 0xffff) == 0x471) {
        FUN_004328ba(1);
        DAT_0066aaf4 = 0xfffffffe;
        EndDialog(hwnd,0);
      }
      else if (((uint)hdc & 0xffff) == 0x472) {
        FUN_004328ba(0);
        DAT_0066aaf4 = 0xffffffff;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_31c = hdc;
      FUN_004707a4(hdc);
      local_324 = param_4;
      local_320 = GetDlgCtrlID(param_4);
      if (local_320 != 0x3ea) {
        SetBkMode(local_31c,1);
        pvVar6 = GetStockObject(5);
        return pvVar6;
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}


