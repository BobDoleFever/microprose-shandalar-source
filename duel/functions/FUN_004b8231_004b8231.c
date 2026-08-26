/*
 * Decompiled function: FUN_004b8231
 * Entry Point: 004b8231
 * Size: 1597 bytes
 */
#include "duel.h"


undefined4 FUN_004b8231(HWND param_1,uint param_2,uint param_3,byte *param_4)

{
  uint uVar1;
  HWND pHVar2;
  UINT UVar3;
  WPARAM WVar4;
  LRESULT nResult;
  undefined4 uVar5;
  int nIndex;
  undefined4 uVar6;
  uint uVar7;
  LONG dwNewLong;
  
  if (param_2 < 0x312) {
    if (0x30e < param_2) {
      uVar5 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return uVar5;
    }
    if (param_2 == 0x110) {
      DAT_005dcdf8 = (uint *)param_4;
      if (*(int *)(param_4 + 8) != 0) {
        SetWindowTextA(param_1,*(LPCSTR *)(param_4 + 8));
      }
      SendDlgItemMessageA(param_1,0x3f2,0x401,0xffffffff,0);
      dwNewLong = 1;
      nIndex = 0xc;
      pHVar2 = GetDlgItem(param_1,0x3f2);
      SetWindowLongA(pHVar2,nIndex,dwNewLong);
      if ((*(byte *)DAT_005dcdf8 & 2) == 0) {
        if ((*(byte *)DAT_005dcdf8 & 4) == 0) {
          if ((*(byte *)DAT_005dcdf8 & 8) == 0) {
            if ((*(byte *)DAT_005dcdf8 & 0x10) == 0) {
              CheckDlgButton(param_1,0x3f8,1);
            }
            else {
              CheckDlgButton(param_1,0x3f7,1);
            }
          }
          else {
            CheckDlgButton(param_1,0x3f6,1);
          }
        }
        else {
          CheckDlgButton(param_1,0x3f5,1);
        }
      }
      else {
        CheckDlgButton(param_1,0x3f4,1);
      }
      if ((*(byte *)((int)DAT_005dcdf8 + 4) & 1) == 0) {
        if ((*(byte *)((int)DAT_005dcdf8 + 4) & 2) == 0) {
          if ((*(byte *)((int)DAT_005dcdf8 + 4) & 4) == 0) {
            if ((*(byte *)((int)DAT_005dcdf8 + 4) & 8) == 0) {
              if ((*(byte *)((int)DAT_005dcdf8 + 4) & 0x10) == 0) {
                if ((*(byte *)((int)DAT_005dcdf8 + 4) & 0x20) == 0) {
                  CheckDlgButton(param_1,0x3fa,1);
                }
                else {
                  CheckDlgButton(param_1,0x3fd,1);
                }
              }
              else {
                CheckDlgButton(param_1,0x3fd,1);
              }
            }
            else {
              CheckDlgButton(param_1,0x3fc,1);
            }
          }
          else {
            CheckDlgButton(param_1,0x3fb,1);
          }
        }
        else {
          CheckDlgButton(param_1,0x3f9,1);
        }
      }
      else {
        CheckDlgButton(param_1,0x3fe,1);
      }
      uVar5 = *(undefined4 *)((int)DAT_005dcdf8 + 4);
      uVar6 = *DAT_005dcdf8;
      pHVar2 = GetDlgItem(param_1,0x3f3);
      FUN_004b8899(pHVar2,uVar6,uVar5);
      pHVar2 = GetDlgItem(param_1,0x3f3);
      SetFocus(pHVar2);
      return 0;
    }
    if (param_2 == 0x111) {
      uVar1 = param_3 & 0xffff;
      if (uVar1 < 0x3f4) {
        if (uVar1 == 0x3f3) {
          if (param_3 >> 0x10 == 1) {
            WVar4 = SendDlgItemMessageA(param_1,0x3f3,0x188,0,0);
            WVar4 = SendDlgItemMessageA(param_1,0x3f3,0x199,WVar4,0);
            SendDlgItemMessageA(param_1,0x3f2,0x401,WVar4,0);
          }
          else if (param_3 >> 0x10 == 2) {
            pHVar2 = GetDlgItem(param_1,1);
            SendMessageA(param_1,0x111,1,(LPARAM)pHVar2);
          }
        }
        else if (uVar1 == 1) {
          WVar4 = SendDlgItemMessageA(param_1,0x3f3,0x188,0,0);
          nResult = SendDlgItemMessageA(param_1,0x3f3,0x199,WVar4,0);
          EndDialog(param_1,nResult);
        }
        else if (uVar1 == 2) {
          EndDialog(param_1,-1);
        }
      }
      else {
        switch(uVar1) {
        case 0x3f4:
        case 0x3f5:
        case 0x3f6:
        case 0x3f7:
        case 0x3f8:
          if (param_3 >> 0x10 == 0) {
            *DAT_005dcdf8 = 0;
            UVar3 = IsDlgButtonChecked(param_1,0x3f4);
            if (UVar3 != 0) {
              *DAT_005dcdf8 = *DAT_005dcdf8 | 2;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3f8);
            if (UVar3 != 0) {
              *DAT_005dcdf8 = *DAT_005dcdf8 | 0x20;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3f5);
            if (UVar3 != 0) {
              *DAT_005dcdf8 = *DAT_005dcdf8 | 4;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3f7);
            if (UVar3 != 0) {
              *DAT_005dcdf8 = *DAT_005dcdf8 | 0x10;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3f6);
            if (UVar3 != 0) {
              *DAT_005dcdf8 = *DAT_005dcdf8 | 8;
            }
            uVar1 = DAT_005dcdf8[1];
            uVar7 = *DAT_005dcdf8;
            pHVar2 = GetDlgItem(param_1,0x3f3);
            FUN_004b8899(pHVar2,uVar7,uVar1);
            pHVar2 = GetDlgItem(param_1,0x3f3);
            SetFocus(pHVar2);
          }
          break;
        case 0x3f9:
        case 0x3fa:
        case 0x3fb:
        case 0x3fc:
        case 0x3fd:
        case 0x3fe:
          if (param_3 >> 0x10 == 0) {
            DAT_005dcdf8[1] = 0;
            UVar3 = IsDlgButtonChecked(param_1,0x3fe);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 1;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3f9);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 2;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3fb);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 4;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3fc);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 8;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3fd);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 0x30;
            }
            UVar3 = IsDlgButtonChecked(param_1,0x3fa);
            if (UVar3 != 0) {
              DAT_005dcdf8[1] = DAT_005dcdf8[1] | 0x40;
            }
            uVar1 = DAT_005dcdf8[1];
            uVar7 = *DAT_005dcdf8;
            pHVar2 = GetDlgItem(param_1,0x3f3);
            FUN_004b8899(pHVar2,uVar7,uVar1);
            pHVar2 = GetDlgItem(param_1,0x3f3);
            SetFocus(pHVar2);
          }
        }
      }
      return 1;
    }
  }
  return 0;
}


