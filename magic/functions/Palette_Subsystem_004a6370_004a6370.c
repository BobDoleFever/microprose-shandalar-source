/*
 * Decompiled function: Palette_Subsystem_004a6370
 * Entry Point: 004a6370
 * Size: 1581 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a6370(HWND hwnd,uint uMsg,uint wParam,byte *lParam)

{
  uint uVar1;
  HWND pHVar2;
  UINT UVar3;
  WPARAM WVar4;
  LRESULT nResult;
  undefined4 uVar5;
  byte bVar6;
  int nIndex;
  byte bVar7;
  LONG dwNewLong;
  
  if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      uVar5 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return uVar5;
    }
    if (uMsg == 0x110) {
      DAT_0054be3c = (uint *)lParam;
      if (*(int *)(lParam + 8) != 0) {
        SetWindowTextA(hwnd,*(LPCSTR *)(lParam + 8));
      }
      SendDlgItemMessageA(hwnd,0x3f2,0x401,0xffffffff,0);
      dwNewLong = 1;
      nIndex = 0xc;
      pHVar2 = GetDlgItem(hwnd,0x3f2);
      SetWindowLongA(pHVar2,nIndex,dwNewLong);
      if ((*(byte *)DAT_0054be3c & 2) == 0) {
        if ((*(byte *)DAT_0054be3c & 4) == 0) {
          if ((*(byte *)DAT_0054be3c & 8) == 0) {
            if ((*(byte *)DAT_0054be3c & 0x10) == 0) {
              CheckDlgButton(hwnd,0x3f8,1);
            }
            else {
              CheckDlgButton(hwnd,0x3f7,1);
            }
          }
          else {
            CheckDlgButton(hwnd,0x3f6,1);
          }
        }
        else {
          CheckDlgButton(hwnd,0x3f5,1);
        }
      }
      else {
        CheckDlgButton(hwnd,0x3f4,1);
      }
      if ((*(byte *)((int)DAT_0054be3c + 4) & 1) == 0) {
        if ((*(byte *)((int)DAT_0054be3c + 4) & 2) == 0) {
          if ((*(byte *)((int)DAT_0054be3c + 4) & 4) == 0) {
            if ((*(byte *)((int)DAT_0054be3c + 4) & 8) == 0) {
              if ((*(byte *)((int)DAT_0054be3c + 4) & 0x10) == 0) {
                if ((*(byte *)((int)DAT_0054be3c + 4) & 0x20) == 0) {
                  CheckDlgButton(hwnd,0x3fa,1);
                }
                else {
                  CheckDlgButton(hwnd,0x3fd,1);
                }
              }
              else {
                CheckDlgButton(hwnd,0x3fd,1);
              }
            }
            else {
              CheckDlgButton(hwnd,0x3fc,1);
            }
          }
          else {
            CheckDlgButton(hwnd,0x3fb,1);
          }
        }
        else {
          CheckDlgButton(hwnd,0x3f9,1);
        }
      }
      else {
        CheckDlgButton(hwnd,0x3fe,1);
      }
      bVar7 = (byte)*(undefined4 *)((int)DAT_0054be3c + 4);
      bVar6 = (byte)*DAT_0054be3c;
      pHVar2 = GetDlgItem(hwnd,0x3f3);
      Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
      pHVar2 = GetDlgItem(hwnd,0x3f3);
      SetFocus(pHVar2);
      return 0;
    }
    if (uMsg == 0x111) {
      uVar1 = wParam & 0xffff;
      if (uVar1 < 0x3f4) {
        if (uVar1 == 0x3f3) {
          if (wParam >> 0x10 == 1) {
            WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x188,0,0);
            WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x199,WVar4,0);
            SendDlgItemMessageA(hwnd,0x3f2,0x401,WVar4,0);
          }
          else if (wParam >> 0x10 == 2) {
            pHVar2 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,1,(LPARAM)pHVar2);
          }
        }
        else if (uVar1 == 1) {
          WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x188,0,0);
          nResult = SendDlgItemMessageA(hwnd,0x3f3,0x199,WVar4,0);
          EndDialog(hwnd,nResult);
        }
        else if (uVar1 == 2) {
          EndDialog(hwnd,-1);
        }
      }
      else {
        switch(uVar1) {
        case 0x3f4:
        case 0x3f5:
        case 0x3f6:
        case 0x3f7:
        case 0x3f8:
          if (wParam >> 0x10 == 0) {
            *DAT_0054be3c = 0;
            UVar3 = IsDlgButtonChecked(hwnd,0x3f4);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 2;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f8);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 0x20;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f5);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 4;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f7);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 0x10;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f6);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 8;
            }
            bVar7 = (byte)DAT_0054be3c[1];
            bVar6 = (byte)*DAT_0054be3c;
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            SetFocus(pHVar2);
          }
          break;
        case 0x3f9:
        case 0x3fa:
        case 0x3fb:
        case 0x3fc:
        case 0x3fd:
        case 0x3fe:
          if (wParam >> 0x10 == 0) {
            DAT_0054be3c[1] = 0;
            UVar3 = IsDlgButtonChecked(hwnd,0x3fe);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 1;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f9);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 2;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fb);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 4;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fc);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 8;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fd);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 0x30;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fa);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 0x40;
            }
            bVar7 = (byte)DAT_0054be3c[1];
            bVar6 = (byte)*DAT_0054be3c;
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            SetFocus(pHVar2);
          }
        }
      }
      return 1;
    }
  }
  return 0;
}


