/*
 * Decompiled function: UI_DialogProc_0049c2d0
 * Entry Point: 0049c2d0
 * Size: 3256 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBRUSH UI_DialogProc_0049c2d0(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  INT_PTR IVar4;
  WPARAM wParam_00;
  HWND pHVar5;
  HBRUSH pHVar6;
  BOOL BVar7;
  char *pcVar8;
  LPARAM lParam_00;
  tagRECT local_40;
  COLORREF local_30;
  HWND local_2c;
  HWND local_28;
  int local_24;
  HDC local_20;
  HWND local_18;
  HWND local_14;
  char local_10 [12];
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_40);
      if (DAT_005dccd8 == (HANDLE)0x0) {
        pHVar6 = GetStockObject(2);
        FillRect(wParam,&local_40,pHVar6);
      }
      else {
        FUN_004709ae((int)wParam,(int)&local_40,DAT_005dccd8);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 2) {
      FUN_0049d0dc(DAT_005dccd8,DAT_005dcce8,DAT_005dcd0c,DAT_005dccdc);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      if (DAT_005f64b0 == 0) {
        CheckDlgButton(hwnd,0x453,1);
        CheckRadioButton(hwnd,0x453,0x454,0x453);
        CheckDlgButton(hwnd,0x467,1);
        CheckRadioButton(hwnd,0x467,0x468,0x467);
        DAT_005f6c54 = 0;
        BVar7 = 0;
        pHVar5 = GetDlgItem(hwnd,0x468);
        EnableWindow(pHVar5,BVar7);
        BVar7 = 0;
        pHVar5 = GetDlgItem(hwnd,0x463);
        EnableWindow(pHVar5,BVar7);
      }
      else {
        CheckDlgButton(hwnd,0x454,1);
        CheckRadioButton(hwnd,0x453,0x454,0x454);
        if (DAT_005f6c54 == 1) {
          CheckDlgButton(hwnd,0x468,1);
          CheckRadioButton(hwnd,0x467,0x468,0x468);
        }
        else {
          CheckDlgButton(hwnd,0x467,1);
          CheckRadioButton(hwnd,0x467,0x468,0x467);
        }
      }
      if (DAT_005f76c4 == 1) {
        CheckDlgButton(hwnd,0x465,1);
        CheckRadioButton(hwnd,0x465,0x466,0x465);
      }
      else {
        CheckDlgButton(hwnd,0x466,1);
        CheckRadioButton(hwnd,0x465,0x466,0x466);
      }
      _sprintf(local_10,&DAT_00505d54,DAT_005f2f50);
      pcVar8 = local_10;
      pHVar5 = GetDlgItem(hwnd,0x455);
      SetWindowTextA(pHVar5,pcVar8);
      DAT_005f6288 = Palette_Subsystem_00496497(hwnd);
      if (DAT_005f6288 == -1) {
        EndDialog(hwnd,-1);
        return (HBRUSH)0x1;
      }
      DAT_005f649c = DAT_005f6288;
      if (0x13 < DAT_005f6288) {
        DAT_005f649c = 0x14;
      }
      FUN_0049e6f9();
      DAT_005f64a8 = FUN_0049e65c(hwnd,&DAT_00664734);
      SendDlgItemMessageA(hwnd,0x462,0x14e,DAT_005f64a8,0);
      DAT_005f64ac = FUN_0049e65c(hwnd,&DAT_00664752);
      SendDlgItemMessageA(hwnd,0x463,0x14e,DAT_005f64ac,0);
      Pic_Load_s_GAUN_Startup_0049cff7
                (&DAT_005dccd8,(undefined4 *)&DAT_005dccd0,&DAT_005dcce4,(int *)&DAT_005dcce8,
                 (int *)&DAT_005dcd0c,(int *)&DAT_005dccdc,&DAT_005dccc8,&DAT_005dcd08);
      pHVar5 = GetDlgItem(hwnd,1);
      SetFocus(pHVar5);
      SendMessageA(hwnd,0x401,1,0);
      FUN_00472552(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x2b) {
      local_2c = lParam;
      pHVar5 = GetFocus();
      if (pHVar5 == (HWND)local_2c[5].unused) {
        local_30 = DAT_005dcd08;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005dccc8;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_00471f45((int)local_2c,DAT_005dcce8,DAT_005dcd0c,DAT_005dccdc,local_30,0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_0049cd5b:
      local_20 = wParam;
      FUN_004707a4(wParam);
      local_28 = lParam;
      local_24 = GetDlgCtrlID(lParam);
      if ((local_24 != 0x46e) && (local_24 != 0x455)) {
        pHVar5 = GetFocus();
        if (pHVar5 == local_28) {
          SetTextColor(local_20,DAT_005dcd08);
        }
        else {
          SetTextColor(local_20,DAT_005dcce4);
        }
        SetBkMode(local_20,1);
        pHVar6 = GetStockObject(5);
        return pHVar6;
      }
      SetTextColor(local_20,DAT_005dcce4);
      SetBkMode(local_20,1);
      return DAT_005dcce8;
    }
    if (uMsg == 0x111) {
      uVar1 = (uint)wParam & 0xffff;
      if (uVar1 < 0x44f) {
        if (uVar1 == 0x44e) {
          UVar2 = IsDlgButtonChecked(hwnd,0x453);
          DAT_005f64b0 = (uint)(UVar2 == 0);
          UVar2 = IsDlgButtonChecked(hwnd,0x467);
          DAT_005f6c54 = (uint)(UVar2 == 0);
          UVar2 = IsDlgButtonChecked(hwnd,0x465);
          if (UVar2 == 0) {
            DAT_005f76c4 = 2;
          }
          else {
            DAT_005f76c4 = 1;
          }
          FUN_0049e807(hwnd,DAT_005f76c4);
          FUN_0049e921(hwnd,DAT_005f6c54);
          FUN_0048d3af();
          (&DAT_004f71c4)[DAT_00505988 * 0xa0] = 0;
          *(undefined4 *)(&DAT_004f71c0 + DAT_00505988 * 0x280) =
               (&DAT_004f71c4)[DAT_00505988 * 0xa0];
          _deck = 0xffffffff;
          DeckBuilderMain(DAT_005f67ec,0x18,1);
          FUN_0048d320();
          InvalidateRect(hwnd,(RECT *)0x0,1);
          InvalidateRect(DAT_00617378,(RECT *)0x0,1);
          InvalidateRect(DAT_00618988,(RECT *)0x0,1);
          SendDlgItemMessageA(hwnd,0x462,0x14b,0,0);
          SendDlgItemMessageA(hwnd,0x463,0x14b,0,0);
          DAT_005f6288 = Palette_Subsystem_00496497(hwnd);
          if (DAT_005f6288 == -1) {
            EndDialog(hwnd,-1);
            return (HBRUSH)0x1;
          }
          DAT_005f649c = DAT_005f6288;
          if (0x13 < DAT_005f6288) {
            DAT_005f649c = 0x14;
          }
          if (szDeckName == '\0') {
            DAT_005f64a8 = FUN_0049e65c(hwnd,&DAT_006015b0);
          }
          else {
            DAT_005f64a8 = FUN_0049e65c(hwnd,&szDeckName);
          }
          DAT_005f64ac = FUN_0049e65c(hwnd,&DAT_00664b90);
          SendDlgItemMessageA(hwnd,0x462,0x14e,DAT_005f64a8,0);
          SendDlgItemMessageA(hwnd,0x463,0x14e,DAT_005f64ac,0);
          CheckRadioButton(hwnd,0x465,0x466,0x466);
        }
        else {
          if (uVar1 == 1) {
            UVar2 = IsDlgButtonChecked(hwnd,0x453);
            DAT_005f64b0 = (uint)(UVar2 == 0);
            UVar2 = IsDlgButtonChecked(hwnd,0x467);
            DAT_005f6c54 = (uint)(UVar2 == 0);
            UVar2 = IsDlgButtonChecked(hwnd,0x465);
            if (UVar2 == 0) {
              DAT_005f76c4 = 2;
            }
            else {
              DAT_005f76c4 = 1;
            }
            FUN_0049e807(hwnd,DAT_005f76c4);
            FUN_0049e921(hwnd,DAT_005f6c54);
            EndDialog(hwnd,4);
            return (HBRUSH)0x1;
          }
          if (uVar1 == 2) {
            EndDialog(hwnd,5);
            return (HBRUSH)0x1;
          }
        }
      }
      else {
        switch(uVar1) {
        case 0x453:
          CheckDlgButton(hwnd,0x467,1);
          CheckRadioButton(hwnd,0x467,0x468,0x467);
          BVar7 = 0;
          pHVar5 = GetDlgItem(hwnd,0x468);
          EnableWindow(pHVar5,BVar7);
          BVar7 = 0;
          pHVar5 = GetDlgItem(hwnd,0x463);
          EnableWindow(pHVar5,BVar7);
          break;
        case 0x454:
          BVar7 = 1;
          pHVar5 = GetDlgItem(hwnd,0x468);
          EnableWindow(pHVar5,BVar7);
          iVar3 = 0;
          pHVar5 = GetDlgItem(hwnd,0x468);
          ShowWindow(pHVar5,iVar3);
          iVar3 = 5;
          pHVar5 = GetDlgItem(hwnd,0x468);
          ShowWindow(pHVar5,iVar3);
          BVar7 = 1;
          pHVar5 = GetDlgItem(hwnd,0x463);
          EnableWindow(pHVar5,BVar7);
          break;
        case 0x469:
          IVar4 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe8,hwnd,UI_DialogProc_0049eaa0,0);
          if (IVar4 != 0) {
            FUN_00481f02();
          }
          pHVar5 = GetDlgItem(hwnd,1);
          SetFocus(pHVar5);
          break;
        case 0x47d:
          FUN_004328ba(1);
          DAT_0066aaf4 = 0xfffffffe;
          EndDialog(hwnd,4);
          break;
        case 0x47e:
          FUN_004328ba(0);
          DAT_0066aaf4 = 0xffffffff;
          EndDialog(hwnd,4);
          break;
        case 0x47f:
          FUN_00480690(hwnd);
          pHVar5 = GetDlgItem(hwnd,1);
          SetFocus(pHVar5);
          break;
        case 0x49c:
          _DAT_00615304 = hwnd;
          _DAT_00615330 = s_Load_Saved_Game_00505d58;
          _DAT_00615334 = 0x2a100c;
          BVar7 = GetOpenFileNameA((LPOPENFILENAMEA)&DAT_00615300);
          if (BVar7 != 0) {
            iVar3 = FUN_00433d45(DAT_0061531c);
            if (iVar3 == 0) {
              MessageBoxA(hwnd,s_Couldn_t_load_the_save_game__cor_00505d78,
                          s_Load_saved_game_00505d68,0);
            }
            else {
              DAT_0066aaf4 = 0xfffffff6;
              DAT_00601578 = 1;
              DAT_005f64b0 = 1;
              DAT_005f628c = 1;
              EndDialog(hwnd,4);
            }
          }
          return (HBRUSH)0x1;
        }
      }
      _sprintf(local_10,&DAT_00505dc0,DAT_005f2f50);
      pcVar8 = local_10;
      pHVar5 = GetDlgItem(hwnd,0x455);
      SetWindowTextA(pHVar5,pcVar8);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_0049cd5b;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar6 = (HBRUSH)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar6;
    }
    if (uMsg == 0x4c8) {
      local_14 = (HWND)wParam;
      local_18 = lParam;
      pHVar5 = GetDlgItem(hwnd,1);
      if ((((pHVar5 == local_14) || (pHVar5 = GetDlgItem(hwnd,2), pHVar5 == local_14)) ||
          (pHVar5 = GetDlgItem(hwnd,0x469), pHVar5 == local_14)) ||
         ((pHVar5 = GetDlgItem(hwnd,0x47f), pHVar5 == local_14 ||
          (pHVar5 = GetDlgItem(hwnd,0x44e), pHVar5 == local_14)))) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(local_14);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_14 != (HWND)0x0) {
        InvalidateRect(local_14,(RECT *)0x0,1);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}


