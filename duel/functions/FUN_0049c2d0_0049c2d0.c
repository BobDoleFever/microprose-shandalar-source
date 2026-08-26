/*
 * Decompiled function: FUN_0049c2d0
 * Entry Point: 0049c2d0
 * Size: 3256 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HGDIOBJ FUN_0049c2d0(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  INT_PTR IVar4;
  WPARAM wParam;
  HGDIOBJ pvVar5;
  HWND pHVar6;
  HBRUSH hbr;
  BOOL BVar7;
  char *pcVar8;
  LPARAM lParam;
  tagRECT local_40;
  COLORREF local_30;
  HWND local_2c;
  HWND local_28;
  int local_24;
  HDC local_20;
  HWND local_18;
  HWND local_14;
  char local_10 [12];
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_40);
      if (DAT_005dccd8 == 0) {
        hbr = GetStockObject(2);
        FillRect(param_3,&local_40,hbr);
      }
      else {
        FUN_004709ae(param_3,&local_40,DAT_005dccd8);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 2) {
      FUN_0049d0dc(DAT_005dccd8,DAT_005dcce8,DAT_005dcd0c,DAT_005dccdc);
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      if (DAT_005f64b0 == 0) {
        CheckDlgButton(param_1,0x453,1);
        CheckRadioButton(param_1,0x453,0x454,0x453);
        CheckDlgButton(param_1,0x467,1);
        CheckRadioButton(param_1,0x467,0x468,0x467);
        DAT_005f6c54 = 0;
        BVar7 = 0;
        pHVar6 = GetDlgItem(param_1,0x468);
        EnableWindow(pHVar6,BVar7);
        BVar7 = 0;
        pHVar6 = GetDlgItem(param_1,0x463);
        EnableWindow(pHVar6,BVar7);
      }
      else {
        CheckDlgButton(param_1,0x454,1);
        CheckRadioButton(param_1,0x453,0x454,0x454);
        if (DAT_005f6c54 == 1) {
          CheckDlgButton(param_1,0x468,1);
          CheckRadioButton(param_1,0x467,0x468,0x468);
        }
        else {
          CheckDlgButton(param_1,0x467,1);
          CheckRadioButton(param_1,0x467,0x468,0x467);
        }
      }
      if (DAT_005f76c4 == 1) {
        CheckDlgButton(param_1,0x465,1);
        CheckRadioButton(param_1,0x465,0x466,0x465);
      }
      else {
        CheckDlgButton(param_1,0x466,1);
        CheckRadioButton(param_1,0x465,0x466,0x466);
      }
      _sprintf(local_10,&DAT_00505d54,DAT_005f2f50);
      pcVar8 = local_10;
      pHVar6 = GetDlgItem(param_1,0x455);
      SetWindowTextA(pHVar6,pcVar8);
      DAT_005f6288 = FUN_0049d17d(param_1);
      if (DAT_005f6288 == -1) {
        EndDialog(param_1,-1);
        return (HGDIOBJ)0x1;
      }
      DAT_005f649c = DAT_005f6288;
      if (0x13 < DAT_005f6288) {
        DAT_005f649c = 0x14;
      }
      FUN_0049e6f9();
      DAT_005f64a8 = FUN_0049e65c(param_1,&DAT_00664734);
      SendDlgItemMessageA(param_1,0x462,0x14e,DAT_005f64a8,0);
      DAT_005f64ac = FUN_0049e65c(param_1,&DAT_00664752);
      SendDlgItemMessageA(param_1,0x463,0x14e,DAT_005f64ac,0);
      FUN_0049cff7(&DAT_005dccd8,&DAT_005dccd0,&DAT_005dcce4,&DAT_005dcce8,&DAT_005dcd0c,
                   &DAT_005dccdc,&DAT_005dccc8,&DAT_005dcd08);
      pHVar6 = GetDlgItem(param_1,1);
      SetFocus(pHVar6);
      SendMessageA(param_1,0x401,1,0);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x2b) {
      local_2c = param_4;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_2c[5].unused) {
        local_30 = DAT_005dcd08;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005dccc8;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_00471f45(local_2c,DAT_005dcce8,DAT_005dcd0c,DAT_005dccdc,local_30,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x136) {
    if (param_2 == 0x135) {
LAB_0049cd5b:
      local_20 = param_3;
      FUN_004707a4(param_3);
      local_28 = param_4;
      local_24 = GetDlgCtrlID(param_4);
      if ((local_24 != 0x46e) && (local_24 != 0x455)) {
        pHVar6 = GetFocus();
        if (pHVar6 == local_28) {
          SetTextColor(local_20,DAT_005dcd08);
        }
        else {
          SetTextColor(local_20,DAT_005dcce4);
        }
        SetBkMode(local_20,1);
        pvVar5 = GetStockObject(5);
        return pvVar5;
      }
      SetTextColor(local_20,DAT_005dcce4);
      SetBkMode(local_20,1);
      return DAT_005dcce8;
    }
    if (param_2 == 0x111) {
      uVar1 = (uint)param_3 & 0xffff;
      if (uVar1 < 0x44f) {
        if (uVar1 == 0x44e) {
          UVar2 = IsDlgButtonChecked(param_1,0x453);
          DAT_005f64b0 = (uint)(UVar2 == 0);
          UVar2 = IsDlgButtonChecked(param_1,0x467);
          DAT_005f6c54 = (uint)(UVar2 == 0);
          UVar2 = IsDlgButtonChecked(param_1,0x465);
          if (UVar2 == 0) {
            DAT_005f76c4 = 2;
          }
          else {
            DAT_005f76c4 = 1;
          }
          FUN_0049e807(param_1,DAT_005f76c4);
          FUN_0049e921(param_1,DAT_005f6c54);
          FUN_0048d3af();
          (&DAT_004f71c4)[DAT_00505988 * 0xa0] = 0;
          *(undefined4 *)(&DAT_004f71c0 + DAT_00505988 * 0x280) =
               (&DAT_004f71c4)[DAT_00505988 * 0xa0];
          _deck = 0xffffffff;
          DeckBuilderMain(DAT_005f67ec,0x18,1);
          FUN_0048d320();
          InvalidateRect(param_1,(RECT *)0x0,1);
          InvalidateRect(DAT_00617378,(RECT *)0x0,1);
          InvalidateRect(DAT_00618988,(RECT *)0x0,1);
          SendDlgItemMessageA(param_1,0x462,0x14b,0,0);
          SendDlgItemMessageA(param_1,0x463,0x14b,0,0);
          DAT_005f6288 = FUN_0049d17d(param_1);
          if (DAT_005f6288 == -1) {
            EndDialog(param_1,-1);
            return (HGDIOBJ)0x1;
          }
          DAT_005f649c = DAT_005f6288;
          if (0x13 < DAT_005f6288) {
            DAT_005f649c = 0x14;
          }
          if (szDeckName == '\0') {
            DAT_005f64a8 = FUN_0049e65c(param_1,&DAT_006015b0);
          }
          else {
            DAT_005f64a8 = FUN_0049e65c(param_1,&szDeckName);
          }
          DAT_005f64ac = FUN_0049e65c(param_1,&DAT_00664b90);
          SendDlgItemMessageA(param_1,0x462,0x14e,DAT_005f64a8,0);
          SendDlgItemMessageA(param_1,0x463,0x14e,DAT_005f64ac,0);
          CheckRadioButton(param_1,0x465,0x466,0x466);
        }
        else {
          if (uVar1 == 1) {
            UVar2 = IsDlgButtonChecked(param_1,0x453);
            DAT_005f64b0 = (uint)(UVar2 == 0);
            UVar2 = IsDlgButtonChecked(param_1,0x467);
            DAT_005f6c54 = (uint)(UVar2 == 0);
            UVar2 = IsDlgButtonChecked(param_1,0x465);
            if (UVar2 == 0) {
              DAT_005f76c4 = 2;
            }
            else {
              DAT_005f76c4 = 1;
            }
            FUN_0049e807(param_1,DAT_005f76c4);
            FUN_0049e921(param_1,DAT_005f6c54);
            EndDialog(param_1,4);
            return (HGDIOBJ)0x1;
          }
          if (uVar1 == 2) {
            EndDialog(param_1,5);
            return (HGDIOBJ)0x1;
          }
        }
      }
      else {
        switch(uVar1) {
        case 0x453:
          CheckDlgButton(param_1,0x467,1);
          CheckRadioButton(param_1,0x467,0x468,0x467);
          BVar7 = 0;
          pHVar6 = GetDlgItem(param_1,0x468);
          EnableWindow(pHVar6,BVar7);
          BVar7 = 0;
          pHVar6 = GetDlgItem(param_1,0x463);
          EnableWindow(pHVar6,BVar7);
          break;
        case 0x454:
          BVar7 = 1;
          pHVar6 = GetDlgItem(param_1,0x468);
          EnableWindow(pHVar6,BVar7);
          iVar3 = 0;
          pHVar6 = GetDlgItem(param_1,0x468);
          ShowWindow(pHVar6,iVar3);
          iVar3 = 5;
          pHVar6 = GetDlgItem(param_1,0x468);
          ShowWindow(pHVar6,iVar3);
          BVar7 = 1;
          pHVar6 = GetDlgItem(param_1,0x463);
          EnableWindow(pHVar6,BVar7);
          break;
        case 0x469:
          IVar4 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe8,param_1,FUN_0049eaa0,0);
          if (IVar4 != 0) {
            FUN_00481f02();
          }
          pHVar6 = GetDlgItem(param_1,1);
          SetFocus(pHVar6);
          break;
        case 0x47d:
          FUN_004328ba(1);
          DAT_0066aaf4 = 0xfffffffe;
          EndDialog(param_1,4);
          break;
        case 0x47e:
          FUN_004328ba(0);
          DAT_0066aaf4 = 0xffffffff;
          EndDialog(param_1,4);
          break;
        case 0x47f:
          FUN_00480690(param_1);
          pHVar6 = GetDlgItem(param_1,1);
          SetFocus(pHVar6);
          break;
        case 0x49c:
          _DAT_00615304 = param_1;
          _DAT_00615330 = s_Load_Saved_Game_00505d58;
          _DAT_00615334 = 0x2a100c;
          BVar7 = GetOpenFileNameA((LPOPENFILENAMEA)&DAT_00615300);
          if (BVar7 != 0) {
            iVar3 = FUN_00433d45(DAT_0061531c);
            if (iVar3 == 0) {
              MessageBoxA(param_1,s_Couldn_t_load_the_save_game__cor_00505d78,
                          s_Load_saved_game_00505d68,0);
            }
            else {
              DAT_0066aaf4 = 0xfffffff6;
              DAT_00601578 = 1;
              DAT_005f64b0 = 1;
              DAT_005f628c = 1;
              EndDialog(param_1,4);
            }
          }
          return (HGDIOBJ)0x1;
        }
      }
      _sprintf(local_10,&DAT_00505dc0,DAT_005f2f50);
      pcVar8 = local_10;
      pHVar6 = GetDlgItem(param_1,0x455);
      SetWindowTextA(pHVar6,pcVar8);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x138) goto LAB_0049cd5b;
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar5 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar5;
    }
    if (param_2 == 0x4c8) {
      local_14 = (HWND)param_3;
      local_18 = param_4;
      pHVar6 = GetDlgItem(param_1,1);
      if ((((pHVar6 == local_14) || (pHVar6 = GetDlgItem(param_1,2), pHVar6 == local_14)) ||
          (pHVar6 = GetDlgItem(param_1,0x469), pHVar6 == local_14)) ||
         ((pHVar6 = GetDlgItem(param_1,0x47f), pHVar6 == local_14 ||
          (pHVar6 = GetDlgItem(param_1,0x44e), pHVar6 == local_14)))) {
        lParam = 0;
        wParam = GetDlgCtrlID(local_14);
        SendMessageA(param_1,0x401,wParam,lParam);
      }
      else {
        SendMessageA(param_1,0x401,1,0);
      }
      if (local_14 != (HWND)0x0) {
        InvalidateRect(local_14,(RECT *)0x0,1);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}


