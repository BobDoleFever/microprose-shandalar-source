/*
 * Decompiled function: UI_WndProc_00482299
 * Entry Point: 00482299
 * Size: 12135 bytes
 */
#include "duel.h"


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_WndProc_00482299(HWND hwnd,uint uMsg,HWND wParam,int *lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  byte arg_3;
  uint uVar1;
  LONG LVar2;
  HWND pHVar3;
  HBRUSH pHVar4;
  int iVar5;
  uint uVar6;
  DWORD DVar7;
  BOOL BVar8;
  LRESULT LVar9;
  UINT UVar10;
  int *wParam_00;
  LONG *pLVar11;
  LPARAM LVar12;
  int iVar13;
  int local_960;
  undefined4 local_954;
  HWND local_950;
  int local_94c;
  uint local_948;
  uint local_944;
  uint local_940;
  undefined4 local_93c;
  undefined4 local_938;
  uint local_934;
  uint local_930;
  undefined4 local_92c;
  uint local_928;
  undefined4 local_924;
  HWND local_920;
  tagMSG local_91c;
  HWND local_900;
  int local_8fc;
  tagPOINT local_8f8;
  tagRECT local_8f0;
  undefined4 local_8e0;
  uint local_8dc;
  uint local_8d8;
  int local_8d4;
  int local_8d0;
  int local_8cc;
  int local_8c8;
  HDC local_8c4;
  tagPAINTSTRUCT local_8c0;
  tagRECT local_880;
  DWORD local_870;
  ULONG_PTR local_86c;
  undefined4 local_868;
  undefined4 local_864;
  HWND local_860;
  HWND local_85c;
  HWND local_858;
  tagRECT local_854;
  tagMSG local_844;
  BOOL local_828;
  int local_824;
  tagRECT local_820;
  LONG *local_810;
  undefined4 local_80c;
  CHAR local_808 [100];
  int local_7a4;
  int local_7a0;
  int local_79c;
  int local_798;
  int local_794;
  undefined1 local_790 [20];
  uint local_77c;
  char local_778 [208];
  int local_6a8;
  int local_6a4;
  int local_6a0;
  CHAR local_69c [100];
  int local_638;
  int local_634;
  int local_630;
  int local_62c;
  int local_628;
  undefined1 local_624 [20];
  uint local_610;
  char local_60c [208];
  int local_53c [68];
  ULONG_PTR local_42c;
  uint local_428;
  int local_424;
  int local_420;
  WPARAM local_41c;
  LONG local_418;
  LONG local_414;
  HWND local_410;
  int local_40c;
  HWND local_408 [2];
  undefined1 local_400 [288];
  HWND local_2e0;
  HDC local_2d4;
  tagRECT local_2d0;
  ULONG_PTR local_2c0;
  undefined1 local_2bc [84];
  int local_268;
  uint local_19c;
  uint local_198;
  uint local_194;
  tagRECT local_190;
  uint local_180 [25];
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  int local_108;
  uint local_104 [18];
  tagRECT local_bc;
  int local_ac;
  int local_a8;
  int local_a4;
  char *local_a0 [4];
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  uint local_5c;
  int local_58;
  tagRECT local_54;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  int local_18;
  void *local_14;
  int local_10;
  int local_c;
  HWND local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      LVar9 = SendMessageA(hwnd,0x404,0,0);
      if (LVar9 != 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_870 = GetTickCount();
      GetClientRect(hwnd,&local_880);
      local_8c4 = BeginPaint(hwnd,&local_8c0);
      if (local_8c4 != (HDC)0x0) {
        FUN_004707a4(local_8c4);
        if (DAT_00601580 != 0) {
          pHVar4 = GetStockObject(0);
          FillRect(local_8c4,&local_880,pHVar4);
          Sleep(200);
        }
        if ((local_c == -1) && (local_10 == -1)) {
          FUN_0042043e(local_8c4,&local_880);
        }
        else if (local_10 == -1) {
          FUN_004371ec(local_8c4,&local_880,local_c);
          pHVar4 = GetStockObject(4);
          FrameRect(local_8c4,&local_880,pHVar4);
        }
        else {
          local_86c = FUN_00447184(local_c,local_10);
          if ((local_86c != 0xffffffff) && ((int)local_86c < DAT_0061743c)) {
            if (DAT_0068f108 == local_86c) {
              FUN_0042043e(local_8c4,&local_880);
              iVar13 = 1;
              iVar5 = FUN_00447c07(local_c,local_10);
              FUN_00424f7b(local_8c4,&local_880.left,0x4fa6b8,iVar5,iVar13);
            }
            else if ((((local_86c == DAT_00666720) || (DAT_00666450 == local_86c)) ||
                     (local_86c == DAT_00666444)) || (local_86c == DAT_0066aae8)) {
              FUN_004474ec(&local_8cc,local_c,local_10);
              FUN_004252e0(local_8c4,&local_880.left,local_86c,local_c,local_10);
              iVar5 = FUN_00447cf8(local_c,local_10);
              iVar13 = FUN_00447c74(local_c,local_10);
              FUN_00426620(local_8c4,&local_880.left,iVar13,iVar5);
              FUN_004241e8(local_8c4,&local_880.left,local_8cc,local_8c8,DAT_00663e18);
            }
            else if (DAT_0068f0fc == local_86c) {
              FUN_0044826e(&local_8d4,local_c,local_10);
              FUN_004258dd(DAT_0060157c,&local_880,local_86c,local_c,local_10,local_8d4,local_8d0);
              iVar5 = FUN_00447cf8(local_8d4,local_8d0);
              iVar13 = FUN_00447c74(local_8d4,local_8d0);
              FUN_00426620(DAT_0060157c,&local_880.left,iVar13,iVar5);
              FUN_004241e8(DAT_0060157c,&local_880.left,local_8d4,local_8d0,DAT_00663e18);
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,DAT_0060157c,0,0,0xcc0020);
            }
            else {
              local_8d8 = FUN_004472ad(local_c,local_10);
              pHVar3 = GetParent(hwnd);
              if (pHVar3 == DAT_00618ab0) {
                local_8dc = 0;
              }
              else {
                local_8dc = local_8d8 & 4;
                local_8e0 = FUN_00447038(local_c,local_10);
              }
              FUN_00447c07(local_c,local_10);
              FUN_00425b87(DAT_0060157c,&local_880.left,local_c,local_10);
              iVar5 = FUN_00447cf8(local_c,local_10);
              iVar13 = FUN_00447c74(local_c,local_10);
              FUN_00426620(DAT_0060157c,&local_880.left,iVar13,iVar5);
              uVar6 = FUN_00448124(local_c,local_10);
              FUN_00426746(DAT_0060157c,&local_880.left,uVar6 & 0x20000);
              arg_3 = FUN_00448191(local_c,local_10);
              FUN_004267dc(DAT_0060157c,&local_880,arg_3);
              FUN_004241e8(DAT_0060157c,&local_880.left,local_c,local_10,DAT_00663e18);
              uVar6 = FUN_00447604(local_c,local_10);
              if ((((uVar6 & 2) != 0) || (DAT_00663e20 != 0)) &&
                 (uVar6 = FUN_004472ad(local_c,local_10), (uVar6 & 1) != 0)) {
                Mem_AllocOrFree_00426c5c(&DAT_00617440,DAT_0061897c,&local_880);
              }
              if ((local_8d8 & 2) != 0) {
                FUN_0047173d(0x617440,DAT_0061897c,&local_880);
              }
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,DAT_0060157c,0,0,0xcc0020);
            }
            local_14 = (void *)GetWindowLongA(hwnd,0xc);
            FUN_004485c7(local_14,local_c,local_10);
            if (DAT_005f77f0 != 0) {
              FUN_00486239(local_8c4,(int)&local_880,local_c,local_10);
            }
          }
        }
        EndPaint(hwnd,&local_8c0);
      }
      DVar7 = GetTickCount();
      _DAT_0060d494 = _DAT_0060d494 + (DVar7 - local_870);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_810 = (LONG *)*lParam;
      if (local_810 == (LONG *)0x0) {
        return -1;
      }
      local_c = *local_810;
      local_10 = local_810[1];
      SetWindowLongA(hwnd,0,local_c);
      SetWindowLongA(hwnd,4,local_10);
      local_8 = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      local_14 = _malloc(0x120);
      SetWindowLongA(hwnd,0xc,(LONG)local_14);
      SetWindowLongA(hwnd,0x10,0);
      if (local_14 == (void *)0x0) {
        return -1;
      }
      _memset(local_14,0,0x120);
      return 0;
    }
    if (uMsg == 2) {
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      FUN_004db150(local_14);
      return 0;
    }
    if (uMsg == 3) {
      LVar12 = 0;
      UVar10 = 0x410;
      pHVar3 = GetParent(hwnd);
      SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar9 = UI_WndProc_00471df6(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar9;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x117) {
    if (uMsg == 0x116) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_940 = FUN_004472ad(local_c,local_10);
      local_940 = local_940 & 4;
      if (local_940 != 0) {
        FUN_00447038(local_c,local_10);
      }
      local_938 = FUN_00447038(local_c,local_10);
      local_93c = FUN_00485361(hwnd);
      local_948 = FUN_00447751(local_c,local_10);
      local_948 = local_948 & 0x40;
      local_94c = FUN_004471f7(local_c,local_10);
      local_944 = FUN_00447114(local_c,local_10);
      local_924 = FUN_00447184(local_c,local_10);
      local_930 = FUN_004478fb(local_c,local_10);
      local_930 = local_930 & 0x40000;
      local_934 = *(uint *)(&DAT_004ff5a8 + local_944 * 0x34) & 0x1000;
      uVar6 = FUN_00447604(local_c,local_10);
      local_950 = GetParent(hwnd);
      local_928 = FUN_00448304(local_c,local_10);
      FUN_0044897a(&local_92c,&local_954);
      if (local_928 != local_944) {
        AppendMenuA(DAT_005dadac,0x10,(UINT_PTR)DAT_005dada8,s_Original_type_004fa6c4);
        iVar5 = CardIDFromType(local_928);
        ModifyMenuA(DAT_005dada8,0x72,0,0x72,*(LPCSTR *)(&DAT_00618ac4 + iVar5 * 0x98));
      }
      if (DAT_00663e24 == 2) {
        AppendMenuA(DAT_005dadac,0,0x6e,s_Show_full_card_R_DblClk_004fa6d4);
      }
      else {
        AppendMenuA(DAT_005dadac,0,0x6e,s_View_in_full_card_004fa6ec);
      }
      if (((((uVar6 & 1) != 0) && (local_934 != 0)) &&
          (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00617378)) &&
         (AppendMenuA(DAT_005dadac,0,0x70,s_Don_t_auto_tap_this_card_004fa700), local_930 != 0)) {
        CheckMenuItem(DAT_005dadac,0x70,8);
      }
      AppendMenuA(DAT_005dadac,0,0x73,s_Show_ID_tags_Ctrl_T_004fa71c);
      if (DAT_00663e18 != 0) {
        CheckMenuItem(DAT_005dadac,0x73,8);
      }
      AppendMenuA(DAT_005dadac,0,0x74,s_Show_invisible_effects_Ctrl_I_004fa730);
      if (DAT_00663e1c != 0) {
        CheckMenuItem(DAT_005dadac,0x74,8);
      }
      AppendMenuA(DAT_005dadac,0,0x75,s_Show_all_cards__summoning_sickne_004fa750);
      if (DAT_00663e20 != 0) {
        CheckMenuItem(DAT_005dadac,0x75,8);
      }
      AppendMenuA(DAT_005dadac,0,0x71,s_Help____004fa77c);
      if ((DAT_00601618 != 0) && (DAT_00618158 != 0)) {
        if (local_94c == 0) {
          AppendMenuA(DAT_005dadac,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dadac,0,0x262,s__M__Add_mana_for_this_card_004fa784);
          AppendMenuA(DAT_005dadac,0,0x264,s__B__Bury_this_card_004fa7a0);
        }
        else {
          AppendMenuA(DAT_005dadac,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dadac,0,0x262,s__M__Add_mana_for_this_card_004fa7b4);
          AppendMenuA(DAT_005dadac,0,0x263,s__T__Tap_untap_this_card_004fa7d0);
          AppendMenuA(DAT_005dadac,0,0x264,s__B__Bury_this_card_004fa7e8);
          AppendMenuA(DAT_005dadac,0,0x266,s__X__Increment_counters_for_this_c_004fa7fc);
        }
      }
      return 0;
    }
    if (uMsg == 0x111) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      local_418 = local_c;
      local_414 = local_10;
      pHVar3 = GetParent(hwnd);
      if (pHVar3 == DAT_00618ab0) {
        local_410 = hwnd;
        FUN_004b26c4(DAT_00617378,&local_418,(undefined4 *)0x0,local_408);
      }
      else {
        local_408[0] = hwnd;
        FUN_004994f8(DAT_00618ab0,&local_418,(undefined4 *)0x0,&local_410,(undefined4 *)0x0);
      }
      uVar6 = (uint)wParam & 0xffff;
      if (uVar6 < 0x263) {
        if (uVar6 == 0x262) {
          if (DAT_00601618 != 0) {
            local_40c = *(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_10 * 0x120);
            iVar5 = (int)(char)(&DAT_004ff597)[local_40c * 0x34];
            iVar13 = FUN_0048c367((&DAT_004ff596)
                                  [*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_10 * 0x120) *
                                   0x34]);
            FUN_0049b235(local_c,iVar13,iVar5);
            iVar5 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_40c * 0x34]);
            FUN_0049b235(local_c,0,iVar5);
            FUN_00446d17();
            FUN_00445f05(0,0xff);
          }
        }
        else {
          switch(uVar6) {
          case 100:
          case 0x6d:
            DAT_0066643c = 0;
            FUN_004852b1(hwnd);
            break;
          case 0x65:
            FUN_0044897a((undefined4 *)0x0,local_53c);
            iVar5 = FUN_0048ad82(local_c,local_10);
            if (iVar5 != 0) {
              local_53c[1] = 0xffffffff;
              *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) | 4;
              (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
              FUN_004457a2();
              if ((local_53c[0] < 0x15) || (0x1d < local_53c[0])) {
                LVar12 = 0;
                pLVar11 = &local_418;
                UVar10 = 0x436;
                pHVar3 = GetParent(hwnd);
                SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
              }
              else {
                SendMessageA(DAT_00618ab0,0x412,0,0);
              }
            }
            break;
          case 0x66:
            iVar5 = FUN_00447038(local_c,local_10);
            if (iVar5 != -1) {
              SendMessageA(hwnd,0x111,0x69,0);
            }
            *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) & 0xfffffffb;
            (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
            FUN_004457a2();
            if (hwnd == local_410) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x68:
            SendMessageA(hwnd,0x111,0x69,0);
          case 0x67:
            iVar5 = FUN_0048ad82(local_c,local_10);
            if (iVar5 != 0) {
              FID_conflict__memcpy(local_624,&DAT_00664780,0xe8);
              GetWindowTextA(DAT_0060cc6c,local_69c,100);
              local_628 = DAT_00618158;
              local_634 = Action_ValidateTarget_0041e2a2
                                    (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                     s_Band_with_which_attacker__004fa634,1,&local_630);
              DAT_00618158 = local_628;
              if (local_634 != 0) {
                uVar6 = FUN_004472ad(local_630,local_62c);
                if ((uVar6 & 4) == 0) {
                  UpdateWindow(DAT_00618990);
                  FUN_004469c9(s_That_isn_t_an_attacker_004fa660);
                  UpdateWindow(DAT_00664d90);
                  Sleep(2000);
                }
                else {
                  iVar5 = FUN_00498613(local_c,local_10);
                  if (iVar5 == 0) {
                    UpdateWindow(DAT_00618990);
                    FUN_004469c9(s_Illegal_band_004fa650);
                    UpdateWindow(DAT_00664d90);
                    Sleep(2000);
                  }
                  else {
                    local_638 = FUN_00447038(local_630,local_62c);
                    if (local_638 == -1) {
                      local_638 = local_62c;
                      iVar5 = local_638;
                      *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                           *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) | 4;
                      local_638._0_1_ = (undefined1)local_62c;
                      (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = (undefined1)local_638;
                      *(uint *)(&DAT_006826cc + local_630 * 0x5b20 + local_62c * 0x120) =
                           *(uint *)(&DAT_006826cc + local_630 * 0x5b20 + local_62c * 0x120) | 4;
                      (&DAT_006826de)[local_630 * 0x5b20 + local_62c * 0x120] =
                           (undefined1)local_638;
                      local_638 = iVar5;
                      FUN_004457a2();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_00618ab0);
                      if (BVar8 == 0) {
                        LVar12 = 0;
                        wParam_00 = &local_630;
                        UVar10 = 0x436;
                        pHVar3 = GetParent(local_408[0]);
                        SendMessageA(pHVar3,UVar10,(WPARAM)wParam_00,LVar12);
                      }
                      else {
                        SendMessageA(DAT_00618ab0,0x412,0,0);
                        SendMessageA(DAT_00618ab0,0x436,(WPARAM)&local_630,0);
                      }
                    }
                    else {
                      *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                           *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) | 4;
                      (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = (undefined1)local_638;
                      FUN_004457a2();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_00618ab0);
                      if (BVar8 != 0) {
                        SendMessageA(DAT_00618ab0,0x412,0,0);
                      }
                    }
                  }
                }
              }
              FID_conflict__memcpy(&DAT_00664780,local_624,0xe8);
              FUN_004b7b63(DAT_00664d90,local_60c,local_610);
              FUN_00446a07(local_69c);
            }
            break;
          case 0x69:
            local_6a0 = FUN_00447038(local_c,local_10);
            for (local_6a4 = 0; local_6a4 < (int)(&DAT_00666408)[local_c]; local_6a4 = local_6a4 + 1
                ) {
              iVar5 = FUN_00447114(local_c,local_6a4);
              if (((iVar5 != -1) && (uVar6 = FUN_004472ad(local_c,local_6a4), (uVar6 & 4) != 0)) &&
                 (iVar5 = FUN_00447038(local_c,local_6a4), iVar5 == local_6a0)) {
                (&DAT_006826de)[local_6a4 * 0x120 + local_c * 0x5b20] = 0xff;
                FUN_004457a2();
                local_418 = local_c;
                local_414 = local_6a4;
                BVar8 = IsWindowVisible(DAT_00618ab0);
                if (BVar8 == 0) {
                  LVar12 = 0;
                  pLVar11 = &local_418;
                  UVar10 = 0x436;
                  pHVar3 = GetParent(local_408[0]);
                  SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                }
                else {
                  SendMessageA(DAT_00618ab0,0x436,(WPARAM)&local_418,0);
                }
              }
            }
            BVar8 = IsWindowVisible(DAT_00618ab0);
            if (BVar8 != 0) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            break;
          case 0x6a:
          case 0x6b:
            FID_conflict__memcpy(local_790,&DAT_00664780,0xe8);
            GetWindowTextA(DAT_0060cc6c,local_808,100);
            local_794 = DAT_00618158;
            local_7a0 = Action_ValidateTarget_0041e2a2
                                  (0,1,0,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                   s_Block_which_attacker__004fa678,1,&local_79c);
            DAT_00618158 = local_794;
            if (local_7a0 != 0) {
              uVar6 = FUN_004472ad(local_79c,local_798);
              if ((uVar6 & 4) == 0) {
                UpdateWindow(DAT_00618990);
                FUN_004469c9(s_That_isn_t_an_attacker_004fa6a0);
                UpdateWindow(DAT_00664d90);
                Sleep(2000);
              }
              else {
                iVar5 = FUN_0048b4c5(local_c,local_10,local_79c,local_798);
                if (iVar5 == 0) {
                  UpdateWindow(DAT_00618990);
                  FUN_004469c9(s_Illegal_block_004fa690);
                  UpdateWindow(DAT_00664d90);
                  Sleep(2000);
                }
                else {
                  local_7a4 = FUN_00447038(local_79c,local_798);
                  local_6a8 = local_7a4;
                  if (local_7a4 == -1) {
                    local_6a8 = local_798;
                  }
                  *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                       *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) | 8;
                  (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = (undefined1)local_6a8;
                  FUN_004457a2();
                  BVar8 = IsWindowVisible(DAT_00618ab0);
                  if ((BVar8 == 0) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00618ab0)) {
                    LVar12 = 0;
                    pLVar11 = &local_418;
                    UVar10 = 0x436;
                    pHVar3 = GetParent(hwnd);
                    SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                  }
                  else {
                    SendMessageA(DAT_00618ab0,0x412,0,0);
                  }
                }
              }
            }
            FID_conflict__memcpy(&DAT_00664780,local_790,0xe8);
            FUN_004b7b63(DAT_00664d90,local_778,local_77c);
            FUN_00446a07(local_808);
            break;
          case 0x6c:
            *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) & 0xfffffff7;
            (&DAT_006826de)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
            FUN_004457a2();
            if (hwnd == local_410) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x6e:
            local_41c = FUN_00447184(local_c,local_10);
            local_424 = local_c;
            local_420 = local_10;
            SendMessageA(DAT_006152e0,0x401,local_41c,(LPARAM)&local_424);
            break;
          case 0x6f:
            pHVar3 = GetParent(hwnd);
            if ((pHVar3 == DAT_006152b0) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00663df4)) {
              LVar12 = 0;
              UVar10 = 0x400;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
            }
            break;
          case 0x70:
            uVar6 = FUN_004478fb(local_c,local_10);
            local_428 = (uint)((uVar6 & 0x40000) == 0);
            if (local_428 == 0) {
              *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) & 0xfffbffff;
            }
            else {
              *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) | 0x40000;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
            *(undefined4 *)(&DAT_0060162c + local_c * 0x5b20 + local_10 * 0x120) =
                 *(undefined4 *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
            InvalidateRect(hwnd,(RECT *)0x0,1);
            break;
          case 0x71:
            local_42c = FUN_00447184(local_c,local_10);
            if (local_42c == DAT_0068f108) {
              local_42c = 0xc1b;
            }
            if (local_42c != 0xffffffff) {
              Mem_AllocOrFree_004d9630((uint *)(local_53c + 2),(uint *)&DAT_005f76e0);
              FUN_004d9640((uint *)(local_53c + 2),(uint *)s__duel_hlp_004fa628);
              WinHelpA(DAT_00618990,(LPCSTR)(local_53c + 2),1,local_42c);
            }
            break;
          case 0x73:
            SendMessageA(DAT_00618990,0x111,0x279,0);
            break;
          case 0x74:
            SendMessageA(DAT_00618990,0x111,0x27a,0);
            break;
          case 0x75:
            SendMessageA(DAT_00618990,0x111,0x27c,0);
          }
        }
      }
      else if (uVar6 == 0x263) {
        if (DAT_00601618 != 0) {
          *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_10 * 0x120) ^ 0x10;
          FUN_00445f05(0,0xff);
        }
      }
      else if (uVar6 == 0x264) {
        if (DAT_00601618 != 0) {
          local_80c = *(undefined4 *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98);
          *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
               *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) & 0xfffe;
          *(uint *)(&DAT_006826f8 + local_c * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&DAT_006826f8 + local_c * 0x5b20 + local_10 * 0x120) | 8;
          FUN_0046e571(local_c,local_10,2);
          *(undefined4 *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) = local_80c;
          FUN_00445f05(0,0xff);
        }
      }
      else if ((uVar6 == 0x266) && (DAT_00601618 != 0)) {
        *(int *)(&DAT_0068270c + local_c * 0x5b20 + local_10 * 0x120) =
             *(int *)(&DAT_0068270c + local_c * 0x5b20 + local_10 * 0x120) + 1;
        FUN_00445f05(0,0xff);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      UVar10 = GetDoubleClickTime();
      LVar2 = GetMessageTime();
      DVar7 = GetTickCount();
      Sleep(UVar10 - (LVar2 - DVar7));
      local_828 = PeekMessageA(&local_844,hwnd,0x203,0x203,0);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 == DAT_00617378) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00618988)) {
        if (local_8 == (HWND)0x0) {
          local_85c = hwnd;
        }
        else {
          local_85c = local_8;
          pHVar3 = local_85c;
          do {
            local_85c = pHVar3;
            local_860 = (HWND)FUN_004864b1(local_85c);
            pHVar3 = local_860;
          } while (local_860 != (HWND)0x0);
          local_860 = (HWND)0x0;
        }
        GetWindowRect(local_85c,&local_854);
        local_858 = GetWindow(local_85c,3);
        SendMessageA(local_85c,0x112,0xf012,0);
        GetWindowRect(local_85c,&local_820);
        iVar5 = Mem_AllocOrFree_004d9810(local_854.top - local_820.top);
        iVar13 = Mem_AllocOrFree_004d9810(local_854.left - local_820.left);
        if (iVar5 + iVar13 < 5) {
          local_824 = 0;
          SetWindowPos(local_85c,local_858,0,0,0,0,3);
        }
        else {
          local_824 = 1;
        }
      }
      else {
        local_824 = 0;
      }
      if (local_824 == 0) {
        FUN_0044897a(&local_864,&local_868);
        iVar5 = FUN_00485361(hwnd);
        if (iVar5 != 0) {
          DAT_0066643c = local_828;
          FUN_004852b1(hwnd);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_960 = GetMenuItemCount(DAT_005dadac);
        while (local_960 != 0) {
          RemoveMenu(DAT_005dadac,0,0x400);
          local_960 = local_960 + -1;
        }
        pHVar3 = GetParent(hwnd);
        if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
          pHVar3 = (HWND)GetWindowLongA(hwnd,0x10);
          SetWindowPos(hwnd,pHVar3,0,0,0,0,3);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar9 = FUN_00472b60(hwnd,uMsg,wParam,lParam);
      return LVar9;
    }
    if (uMsg == 0x204) {
      local_8fc = 1;
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
        local_900 = GetWindow(hwnd,3);
        SetWindowLongA(hwnd,0x10,(LONG)local_900);
        BringWindowToTop(hwnd);
      }
      if (DAT_00663e24 == 2) {
        UVar10 = GetDoubleClickTime();
        Sleep(UVar10);
        BVar8 = PeekMessageA(&local_91c,hwnd,0x206,0x206,0);
        if (BVar8 != 0) {
          local_8fc = 0;
        }
      }
      if ((local_c != -1) && (local_10 == -1)) {
        local_8fc = 0;
      }
      if (local_8fc != 0) {
        local_8f8.x = (uint)lParam & 0xffff;
        local_8f8.y = (uint)lParam >> 0x10;
        ClientToScreen(hwnd,&local_8f8);
        iVar5 = GetSystemMetrics(0xd);
        local_8f8.x = local_8f8.x + iVar5;
        iVar5 = local_8f8.y + 4;
        iVar13 = local_8f8.y + 5;
        local_8f8.y = iVar5;
        SetRect(&local_8f0,local_8f8.x,iVar5,local_8f8.x + 1,iVar13);
        TrackPopupMenu(DAT_005dadac,2,local_8f8.x,local_8f8.y,0,hwnd,(RECT *)0x0);
      }
      return 0;
    }
    if (uMsg == 0x205) {
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
        local_920 = (HWND)GetWindowLongA(hwnd,0x10);
        SetWindowPos(hwnd,local_920,0,0,0,0,3);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      if ((local_c == -1) || (local_10 != -1)) {
        SendMessageA(hwnd,0x111,0x6e,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      LVar9 = FUN_00447184(local_c,local_10);
      return LVar9;
    case 0x401:
      local_c = GetWindowLongA(hwnd,0);
      LVar2 = GetWindowLongA(hwnd,4);
      if (wParam != (HWND)0x0) {
        wParam->unused = local_c;
        wParam[1].unused = LVar2;
      }
      return 0;
    case 0x402:
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      local_2e0 = wParam;
      if (local_8 != wParam) {
        if (wParam == (HWND)0x0) {
          BringWindowToTop(hwnd);
        }
        local_8 = local_2e0;
        SetWindowLongA(hwnd,8,(LONG)local_2e0);
      }
      return 0;
    case 0x403:
      LVar2 = GetWindowLongA(hwnd,8);
      return LVar2;
    case 0x404:
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      if ((local_c != -1) && (local_10 == -1)) {
        return 0;
      }
      FUN_004485c7(local_400,local_c,local_10);
      iVar5 = _memcmp(local_14,local_400,0x120);
      return iVar5;
    case 0x432:
      BVar8 = IsWindowVisible(hwnd);
      if (BVar8 == 0) {
        return 0;
      }
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      FUN_004485c7(local_2bc,local_c,local_10);
      if ((local_c != -1) && (local_10 == -1)) {
        return 0;
      }
      iVar5 = FUN_004855f9((int)local_14,(int)local_2bc);
      if (iVar5 == 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if ((DAT_00663e0c == 0) ||
              (iVar5 = FUN_00485c20((int)local_14,(int)local_2bc), iVar5 != 0)) {
        if (*(int *)((int)local_14 + 0x54) != local_268) {
          local_2c0 = FUN_00447184(local_c,local_10);
          uVar6 = FUN_004472ad(local_c,local_10);
          if ((uVar6 & 2) == 0) {
            if ((((DAT_0068f0fc == local_2c0) || (DAT_0068f108 == local_2c0)) ||
                (DAT_00666444 == local_2c0)) ||
               (((DAT_00666720 == local_2c0 || (DAT_0066aae8 == local_2c0)) ||
                (DAT_00666450 == local_2c0)))) {
              InvalidateRect(hwnd,(RECT *)0x0,0);
            }
            else if (local_2c0 != 0xffffffff) {
              local_2d4 = GetDC(hwnd);
              FUN_004707a4(local_2d4);
              GetClientRect(hwnd,&local_2d0);
              iVar5 = FUN_00447a88(local_c,local_10);
              uVar6 = (uint)(iVar5 == local_c);
              iVar5 = FUN_00447c07(local_c,local_10);
              FUN_00424f7b(local_2d4,&local_2d0.left,*(int *)(&DAT_00618ac8 + local_2c0 * 0x98),
                           iVar5,uVar6);
              ReleaseDC(hwnd,local_2d4);
              *(int *)((int)local_14 + 0x54) = local_268;
            }
          }
          else {
            InvalidateRect(hwnd,(RECT *)0x0,0);
          }
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_104[0] = 0x20;
      local_104[1] = 0x400;
      local_104[2] = 0x40;
      local_104[3] = 0x80;
      local_104[4] = 0x100;
      local_104[5] = 0x200;
      local_104[6] = 1;
      local_104[7] = 2;
      local_104[8] = 4;
      local_104[9] = 8;
      local_104[10] = 0x10;
      local_104[0xb] = 0x800;
      local_104[0xc] = 0x1000;
      local_104[0xd] = 0x2000;
      local_104[0xe] = 0x4000;
      local_104[0xf] = 0x8000;
      local_104[0x10] = 0x10000;
      local_a0[0] = s_Flying_004fa388;
      local_a0[1] = &DAT_004fa394;
      local_a0[2] = s_Banding_004fa3a0;
      local_a0[3] = s_Trample_004fa3b0;
      local_90 = s_First_strike_004fa3c8;
      local_8c = s_Regenerates_004fa3e4;
      local_88 = s_Swampwalk_004fa3fc;
      local_84 = s_Islandwalk_004fa414;
      local_80 = s_Forestwalk_004fa42c;
      local_7c = s_Mountainwalk_004fa448;
      local_78 = s_Plainswalk_004fa464;
      local_74 = s_Protection_from_black_004fa488;
      local_70 = s_Protection_from_blue_004fa4b8;
      local_6c = s_Protection_from_green_004fa4e8;
      local_68 = s_Protection_from_red_004fa514;
      local_64 = s_Protection_from_white_004fa540;
      local_60 = s_Protection_from_artifacts_004fa574;
      local_ac = 0x11;
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_3c = FUN_00447184(local_c,local_10);
      local_114 = (uint)lParam & 0xffff;
      local_110 = (uint)lParam >> 0x10;
      if ((local_c == -1) || (local_10 != -1)) {
        local_10c = 0;
        GetClientRect(hwnd,&local_54);
        uVar1 = FUN_004472ad(local_c,local_10);
        uVar6 = local_114;
        if ((uVar1 & 2) != 0) {
          local_19c = local_114;
          local_114 = local_110;
          local_110 = local_54.bottom - uVar6;
        }
        local_194 = FUN_00447751(local_c,local_10);
        local_44 = -1;
        if (local_194 != 0) {
          local_108 = 0;
          while ((local_108 < local_ac && (local_44 == -1))) {
            FUN_00424d18(&local_190,local_104[local_108],&local_54.left,local_194);
            pt.y = local_110;
            pt.x = local_114;
            BVar8 = PtInRect(&local_190,pt);
            if (BVar8 != 0) {
              local_44 = local_108;
            }
            local_108 = local_108 + 1;
          }
        }
        local_58 = FUN_00446f0f(local_c,local_10);
        FUN_00446f81(local_c,local_10,&local_5c,local_104 + 0x11,&local_118);
        FUN_0042458c(&local_bc,&local_54.left,local_58);
        local_18 = FUN_00447c74(local_c,local_10);
        iVar5 = FUN_00447cf8(local_c,local_10);
        local_198 = (uint)(iVar5 == 0);
        local_40 = FUN_004470a6(local_c,local_10);
        FUN_00424114(&local_38,&local_54.left);
        local_11c = FUN_00448191(local_c,local_10);
        FUN_00426824(&local_28,&local_54.left);
        local_a4 = FUN_00448374(local_c,local_10);
        if ((((local_11c & 1) == 0) || ((local_11c & 2) == 0)) ||
           (pt_00.y = local_110, pt_00.x = local_114, BVar8 = PtInRect(&local_28,pt_00), BVar8 == 0)
           ) {
          if (local_44 == -1) {
            if ((local_40 < 1) ||
               (pt_01.y = local_110, pt_01.x = local_114, BVar8 = PtInRect(&local_38,pt_01),
               BVar8 == 0)) {
              if ((local_58 < 1) ||
                 (pt_02.y = local_110, pt_02.x = local_114, BVar8 = PtInRect(&local_bc,pt_02),
                 BVar8 == 0)) {
                if ((((int)(local_104[0x11] + local_118 + local_5c) < 1) ||
                    ((int)local_110 <= (local_54.bottom * 0x23) / 100)) ||
                   ((local_54.bottom * 0x3e) / 100 <= (int)local_110)) {
                  iVar5 = FUN_00447a88(local_c,local_10);
                  if ((iVar5 == local_c) || ((local_54.bottom * 0xc) / 100 <= (int)local_110)) {
                    if (((local_18 == 0) && (local_198 == 0)) ||
                       (((((int)local_114 <= (local_54.right * 5) / 100 ||
                          ((local_54.right * 0x5f) / 100 <= (int)local_114)) ||
                         ((int)local_110 <= (local_54.bottom * 0xf) / 100)) ||
                        ((local_54.bottom * 0x5f) / 100 <= (int)local_110)))) {
                      if (((local_a4 == 2) && ((local_54.right * 5) / 100 < (int)local_114)) &&
                         (((int)local_114 < (local_54.right * 0x5f) / 100 &&
                          (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                           ((int)local_110 < (local_54.bottom * 0x5f) / 100)))))) {
                        Mem_AllocOrFree_004d9630(local_180,(uint *)s_Dying_004fa60c);
                        local_10c = 1;
                      }
                      else {
                        uVar6 = FUN_00447604(local_c,local_10);
                        if ((((uVar6 & 2) != 0) &&
                            (((uVar6 = FUN_004472ad(local_c,local_10), (uVar6 & 1) != 0 &&
                              ((local_54.right * 5) / 100 < (int)local_114)) &&
                             ((int)local_114 < (local_54.right * 0x5f) / 100)))) &&
                           (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                            ((int)local_110 < (local_54.bottom * 0x5f) / 100)))) {
                          Mem_AllocOrFree_004d9630(local_180,(uint *)s_Summoning_sickness_004fa614);
                          local_10c = 1;
                        }
                      }
                    }
                    else {
                      local_180[0]._0_1_ = '\0';
                      if (local_18 != 0) {
                        FUN_004d9640(local_180,(uint *)s_Is_a_target_004fa5e8);
                      }
                      if ((local_18 != 0) && (local_198 != 0)) {
                        FUN_004d9640(local_180,(uint *)&DAT_004fa5f4);
                      }
                      if (local_198 != 0) {
                        FUN_004d9640(local_180,(uint *)s_Can_t_target_this_004fa5f8);
                      }
                      local_10c = 1;
                    }
                  }
                  else {
                    Mem_AllocOrFree_004d9630
                              (local_180,(uint *)s_Card_is_not_controlled_by_owner_004fa5c8);
                    local_10c = 1;
                  }
                }
                else {
                  local_a8 = (local_54.right - local_54.left) / 3;
                  if ((int)local_114 < local_54.left + local_a8) {
                    FUN_004860aa((char *)local_180,1,local_118);
                  }
                  else if ((int)local_114 < local_a8 * 2 + local_54.left) {
                    FUN_004860aa((char *)local_180,2,local_104[0x11]);
                  }
                  else {
                    FUN_004860aa((char *)local_180,3,local_5c);
                  }
                  local_10c = 1;
                }
              }
              else {
                FUN_00485d15((char *)local_180,local_3c,local_58);
                local_10c = 1;
              }
            }
            else {
              _sprintf((char *)local_180,s_Damage___d_004fa5bc,local_40);
              local_10c = 1;
            }
          }
          else {
            Mem_AllocOrFree_004d9630(local_180,(uint *)local_a0[local_44]);
            local_10c = 1;
          }
        }
        else {
          Mem_AllocOrFree_004d9630(local_180,(uint *)s_This_card_will_untap_004fa5a4);
          local_10c = 1;
        }
      }
      else {
        local_10c = 1;
        Mem_AllocOrFree_004d9630(local_180,(uint *)s_Damage_to_player_004fa590);
      }
      if (local_10c != 0) {
        Mem_AllocOrFree_004d9630((uint *)wParam,local_180);
      }
      if (DAT_00663e24 == 2) {
        return local_10c;
      }
      SendMessageA(hwnd,0x111,0x6e,0);
      return local_10c;
    }
  }
  LVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar9;
}


