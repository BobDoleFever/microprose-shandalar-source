/*
 * Decompiled function: FUN_004afe55
 * Entry Point: 004afe55
 * Size: 7257 bytes
 */
#include "duel.h"


/* WARNING: Switch with 1 destination removed at 0x004b114d : 24 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004afe55(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  LONG LVar1;
  undefined4 uVar2;
  HWND pHVar3;
  uint uVar4;
  int iVar5;
  HBRUSH pHVar6;
  BOOL BVar7;
  LRESULT LVar8;
  int local_618;
  char local_614 [100];
  undefined1 local_5b0 [80];
  tagPOINT local_560;
  tagRECT local_558;
  HWND local_548;
  tagRECT local_544;
  uint local_534 [2];
  CHAR local_52c [264];
  ULONG_PTR local_424;
  int local_420;
  tagRECT local_41c;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 auStack_404 [200];
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  HWND local_cc;
  uint local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  HWND local_ac;
  tagRECT local_a8;
  HWND local_98;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  HWND local_80;
  int local_7c;
  WPARAM local_78;
  HWND local_74;
  int local_70;
  int local_6c;
  int local_68;
  HWND local_64;
  int local_60;
  int local_5c;
  int local_58;
  HWND local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  HWND local_3c;
  HWND local_38;
  uint local_34;
  HWND local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  HWND local_1c;
  int local_18;
  int local_14;
  void *local_10;
  HWND local_c;
  HWND local_8;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_c = (HWND)GetWindowLongA(param_1,8);
      local_548 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_544);
      if (DAT_00601580 != 0) {
        pHVar6 = GetStockObject(0);
        FillRect((HDC)local_548,&local_544,pHVar6);
        Sleep(300);
      }
      if (local_c == (HWND)0x0) {
        pHVar6 = GetStockObject(4);
        FillRect((HDC)local_548,&local_544,pHVar6);
      }
      else {
        FUN_004709ae(local_548,&local_544,local_c);
      }
      return 1;
    }
    if (param_2 == 1) {
      local_14 = 0;
      SetWindowLongA(param_1,4,0);
      local_10 = _malloc(800);
      SetWindowLongA(param_1,0,(LONG)local_10);
      local_c = (HWND)0x0;
      SetWindowLongA(param_1,8,0);
      iVar5 = GetDlgCtrlID(param_1);
      local_534[0] = (uint)(iVar5 != 0x79);
      local_534[1] = 0xffffffff;
      local_8 = CreateWindowExA(0,s_MAGICGAME_CardClass_005065e4,s_Player_Card_005065d8,0x44000000,0
                                ,0,0,0,param_1,(HMENU)0x0,DAT_00664680,local_534);
      SetWindowLongA(param_1,0xc,(LONG)local_8);
      if ((local_10 != (void *)0x0) && (local_8 != (HWND)0x0)) {
        return 0;
      }
      return -1;
    }
    if (param_2 == 2) {
      local_10 = (void *)GetWindowLongA(param_1,0);
      FUN_004db150(local_10);
      local_c = (HWND)GetWindowLongA(param_1,8);
      if (local_c != (HWND)0x0) {
        FUN_00471395(local_c);
      }
      return 0;
    }
switchD_004b1b1f_caseD_403:
    LVar8 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
    return LVar8;
  }
  if (0x111 < param_2) {
    if (param_2 < 0x120) {
      if (param_2 == 0x11f) {
        if (((uint)param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
          local_618 = GetMenuItemCount(DAT_005dcd98);
          while (local_618 != 0) {
            RemoveMenu(DAT_005dcd98,0,0x400);
            local_618 = local_618 + -1;
          }
        }
        return 0;
      }
      if (param_2 == 0x116) {
        if (DAT_00618158 != 0) {
          if ((DAT_00664794 & 2) != 0) {
            AppendMenuA(DAT_005dcd98,0,0x66,&DAT_00601590);
          }
          if ((DAT_00664794 & 1) != 0) {
            AppendMenuA(DAT_005dcd98,0,0x65,&DAT_00618960);
          }
          FUN_004500a1(0,0,local_5b0);
          _sprintf(local_614,s_Go_to___s_005065f8,local_5b0);
          AppendMenuA(DAT_005dcd98,0,100,local_614);
        }
        iVar5 = GetMenuItemCount(DAT_005dcd98);
        if (0 < iVar5) {
          AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
        }
        if (DAT_00617378 == param_1) {
          AppendMenuA(DAT_005dcd98,0,0x67,s_Arrange_your_cards_DblClk_00506604);
        }
        else {
          AppendMenuA(DAT_005dcd98,0,0x67,s_Arrange_opponent_s_cards_DblClk_00506620);
        }
        AppendMenuA(DAT_005dcd98,0,0x68,s_Duel_Options____00506640);
        AppendMenuA(DAT_005dcd98,0,0x69,s_Show_ID_tags_Ctrl_T_00506650);
        if (DAT_00663e18 != 0) {
          CheckMenuItem(DAT_005dcd98,0x69,8);
        }
        AppendMenuA(DAT_005dcd98,0,0x6a,s_Show_invisible_effects_Ctrl_I_00506664);
        if (DAT_00663e1c != 0) {
          CheckMenuItem(DAT_005dcd98,0x6a,8);
        }
        AppendMenuA(DAT_005dcd98,0,0x6b,s_Show_all_cards__summoning_sickne_00506684);
        if (DAT_00663e20 != 0) {
          CheckMenuItem(DAT_005dcd98,0x6b,8);
        }
        AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
        if (((byte)DAT_00663dfc & 1) == 0) {
          AppendMenuA(DAT_005dcd98,0,0x6d,s_Minimize_005066b0);
          AppendMenuA(DAT_005dcd98,0,0x6f,s_Save_game____Ctrl_S_005066bc);
        }
        AppendMenuA(DAT_005dcd98,0,0x70,s_About____005066d0);
        AppendMenuA(DAT_005dcd98,0,0x6e,s_Help____005066dc);
        if (DAT_00618158 != 0) {
          AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dcd98,0x10,DAT_005dcd80,s_Concede_005066e4);
        }
        if (DAT_00601618 != 0) {
          AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
          DAT_005dcd9c = DAT_005dcd98;
          AppendMenuA(DAT_005dcd98,0,0x272,s_Show_player_card_and___on_librar_005066ec);
          if (DAT_005f77f0 != 0) {
            CheckMenuItem(DAT_005dcd9c,0x272,8);
          }
          AppendMenuA(DAT_005dcd9c,0,0x275,s_Which_arts_are_in__Z_00506710);
          AppendMenuA(DAT_005dcd9c,0,0x271,s_Show_the_palette_P_00506728);
          AppendMenuA(DAT_005dcd9c,0,0x276,s_Flash_small_cards_on_repaint_F_0050673c);
          if (DAT_00601580 != 0) {
            CheckMenuItem(DAT_005dcd9c,0x276,8);
          }
          AppendMenuA(DAT_005dcd9c,0,0x277,s_Show_Kim_debug_window_K_0050675c);
          BVar7 = IsWindowVisible(DAT_00694744);
          if (BVar7 != 0) {
            CheckMenuItem(DAT_005dcd9c,0x277,8);
          }
          DAT_005dcd84 = DAT_005dcd98;
          AppendMenuA(DAT_005dcd98,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dcd84,0,0x25f,s_Save_game_S_00506774);
          AppendMenuA(DAT_005dcd84,0,0x26b,s_Put_a_specific_card_IN_PLAY__you_00506780);
          AppendMenuA(DAT_005dcd84,0,0x26d,s_Put_a_specific_card_into_your_op_005067bc);
          AppendMenuA(DAT_005dcd84,0,0x269,s_DRAW_a_card_into_your_oppon_s_ha_005067f0);
          AppendMenuA(DAT_005dcd84,0,0x26f,s__10_to_your_oppon_s_LIFE_L_AltL_0050681c);
          AppendMenuA(DAT_005dcd84,0,0x267,s_Win_W_0050683c);
          AppendMenuA(DAT_005dcd84,0,0x263,s_Tie__draw__T_00506844);
          AppendMenuA(DAT_005dcd84,0,0x25c,s_Show_opponent_s_hand_F8_00506854);
          if (DAT_0060cc60 != 0) {
            CheckMenuItem(DAT_005dcd84,0x25c,8);
          }
          AppendMenuA(DAT_005dcd84,0,0x25d,s_Show_opponent_s_library_F9_0050686c);
          AppendMenuA(DAT_005dcd84,0,0x25e,s_Show_your_library_F10_00506888);
          AppendMenuA(DAT_005dcd84,0,0x273,s_Show_art_on_cards_A_005068a0);
          if (DAT_0060cc70 != 0) {
            CheckMenuItem(DAT_005dcd84,0x273,8);
          }
          AppendMenuA(DAT_005dcd98,0,599,s_Turn_off_cheats_F12_005068b4);
        }
        return 0;
      }
    }
    else if (param_2 < 0x312) {
      if (0x30e < param_2) {
        iVar5 = FUN_00472b60(param_1,param_2,param_3,param_4);
        return iVar5;
      }
      if (param_2 == 0x201) {
        return 0;
      }
      if (param_2 == 0x203) {
        SendMessageA(param_1,0x111,0x67,0);
        return 0;
      }
      if (param_2 == 0x204) {
        local_560.x = param_4 & 0xffff;
        local_560.y = param_4 >> 0x10;
        ClientToScreen(param_1,&local_560);
        SetRect(&local_558,local_560.x,local_560.y,local_560.x + 1,local_560.y + 1);
        TrackPopupMenu(DAT_005dcd98,2,local_560.x,local_560.y,0,param_1,&local_558);
        return 0;
      }
    }
    else {
      switch(param_2) {
      case 0x400:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_8 = (HWND)GetWindowLongA(param_1,0xc);
        for (local_7c = 0; local_7c < local_14; local_7c = local_7c + 1) {
          SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x401,(WPARAM)&local_8c,0);
          local_84 = FUN_00447184(local_8c,local_88);
          FUN_0044743d(&local_94,local_8c,local_88);
          uVar4 = FUN_004472ad(local_8c,local_88);
          if (((uVar4 & 0x10) == 0) ||
             ((local_84 < DAT_00666720 &&
              ((*(int *)(&DAT_00618ad4 + local_84 * 0x98) != 2 ||
               (*(int *)(&DAT_00618ad8 + local_84 * 0x98) == 0xda)))))) {
            if ((local_84 == DAT_00666720) && ((local_94 != -1 && (local_90 == -1)))) {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,(WPARAM)local_8,0);
            }
            else {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,0,0);
            }
          }
          else {
            iVar5 = FUN_004b26c4(param_1,&local_94,0,&local_78);
            if (iVar5 == 0) {
              if (DAT_00617378 == param_1) {
                local_80 = DAT_00618988;
              }
              else {
                local_80 = DAT_00617378;
              }
              iVar5 = FUN_004b26c4(local_80,&local_94,0,&local_78);
              if (iVar5 != 0) {
                SendMessageA(param_1,0x40b,(WPARAM)&local_8c,0);
                SendMessageA(local_80,0x40a,(WPARAM)&local_8c,0);
                PostMessageA(local_80,0x400,0,0);
              }
            }
            else {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,local_78,0);
            }
          }
        }
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_7c = 0; local_7c < local_14; local_7c = local_7c + 1) {
          SendMessageA(param_1,0x410,*(WPARAM *)((int)local_10 + local_7c * 4),0);
        }
        SendMessageA(param_1,0x410,(WPARAM)local_8,0);
        return 0;
      case 0x401:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_d4 = 0; local_d4 < local_14; local_d4 = local_d4 + 1) {
          BVar7 = IsWindowVisible(*(HWND *)((int)local_10 + local_d4 * 4));
          if (BVar7 == 0) {
            ShowWindow(*(HWND *)((int)local_10 + local_d4 * 4),5);
          }
        }
        return 0;
      case 0x402:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_cc = param_3;
        local_c8 = param_4;
        if (param_3 == (HWND)0x0) {
          return 0;
        }
        ShowWindow(param_3,(param_4 == 0) - 1 & 5);
        for (local_d0 = 0; local_d0 < local_14; local_d0 = local_d0 + 1) {
          pHVar3 = (HWND)FUN_004864b1(*(undefined4 *)((int)local_10 + local_d0 * 4));
          if (pHVar3 == local_cc) {
            SendMessageA(param_1,0x402,*(WPARAM *)((int)local_10 + local_d0 * 4),local_c8);
          }
        }
        return 0;
      case 0x40a:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        if (199 < local_14) {
          return 0;
        }
        local_38 = param_3;
        if ((param_3 == (HWND)0x0) ||
           (iVar5 = FUN_00447184(param_3->unused,param_3[1].unused), DAT_0061743c < iVar5)) {
          return 0;
        }
        iVar5 = FUN_004b26c4(param_1,local_38,0,&local_3c);
        if (iVar5 != 0) {
          return local_14;
        }
        local_3c = CreateWindowExA(0,s_MAGICGAME_CardClass_005065b8,s_In_play_Card_005065a8,
                                   0x44000000,0,0,DAT_0061534c,DAT_0061898c,param_1,(HMENU)0x1,
                                   DAT_00664680,local_38);
        if (local_3c != (HWND)0x0) {
          uVar2 = FUN_00485587(local_3c,&local_40,&local_44,1);
          FUN_004b1fcf(param_1,local_38,uVar2);
          SetWindowPos(local_3c,(HWND)0x0,local_40,local_44,0,0,5);
          *(HWND *)((int)local_10 + local_14 * 4) = local_3c;
          local_14 = local_14 + 1;
          SetWindowLongA(param_1,4,local_14);
          BringWindowToTop(local_3c);
          SendMessageA(param_1,0x400,0,0);
          ShowWindow(local_3c,5);
          return local_14;
        }
        return 0;
      case 0x40b:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_54 = param_3;
        local_48 = 0;
        local_4c = 0;
        while( true ) {
          if (local_14 <= local_4c) {
            return local_48;
          }
          if (local_48 != 0) break;
          iVar5 = FUN_00486348(*(undefined4 *)((int)local_10 + local_4c * 4),local_54);
          if (iVar5 != 0) {
            local_48 = 1;
            DestroyWindow(*(HWND *)((int)local_10 + local_4c * 4));
            local_14 = local_14 + -1;
            for (local_50 = local_4c; local_50 < local_14; local_50 = local_50 + 1) {
              *(undefined4 *)((int)local_10 + local_50 * 4) =
                   *(undefined4 *)((int)local_10 + 4 + local_50 * 4);
            }
            SetWindowLongA(param_1,4,local_14);
            for (local_50 = 0; local_50 < local_14; local_50 = local_50 + 1) {
              iVar5 = FUN_004864b1(*(undefined4 *)((int)local_10 + local_50 * 4));
              if (iVar5 == *(int *)((int)local_10 + local_4c * 4)) {
                SendMessageA(*(HWND *)((int)local_10 + local_50 * 4),0x402,0,0);
              }
            }
          }
          local_4c = local_4c + 1;
        }
        return local_48;
      case 0x40c:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_58 = 0; local_58 < local_14; local_58 = local_58 + 1) {
          DestroyWindow(*(HWND *)((int)local_10 + local_58 * 4));
        }
        local_14 = 0;
        SetWindowLongA(param_1,4,0);
        FUN_004b1ed2(param_1);
        return 0;
      case 0x40d:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_74 = param_3;
        local_6c = 0;
        local_70 = 0;
        while( true ) {
          if (local_14 <= local_70) {
            return local_6c;
          }
          if (local_6c != 0) break;
          iVar5 = FUN_00486348(*(undefined4 *)((int)local_10 + local_70 * 4),local_74);
          if (iVar5 != 0) {
            local_6c = 1;
            BringWindowToTop(*(HWND *)((int)local_10 + local_70 * 4));
            SendMessageA(param_1,0x400,0,0);
          }
          local_70 = local_70 + 1;
        }
        return local_6c;
      case 0x40e:
      case 0x40f:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_64 = param_3;
        local_5c = 0;
        local_68 = 0;
        while ((local_68 < local_14 && (local_5c == 0))) {
          iVar5 = FUN_00486348(*(undefined4 *)((int)local_10 + local_68 * 4),local_64);
          if (iVar5 != 0) {
            local_5c = 1;
            if (param_2 == 0x40e) {
              local_60 = FUN_0048644e(*(undefined4 *)((int)local_10 + local_68 * 4));
            }
            else {
              local_60 = *(int *)((int)local_10 + local_68 * 4);
            }
          }
          local_68 = local_68 + 1;
        }
        if (local_5c != 0) {
          return local_60;
        }
        if (param_2 == 0x40e) {
          return -1;
        }
        return 0;
      case 0x410:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_ac = param_3;
        if (param_3 == (HWND)0x0) {
          return 0;
        }
        local_c0 = 5;
        local_c4 = DAT_00664d4c;
        GetWindowRect(param_3,&local_a8);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_a8,2);
        local_b0 = local_a8.left + local_c0;
        local_b4 = local_a8.top - local_c4;
        local_98 = local_ac;
        for (local_b8 = 0; local_b8 < local_14; local_b8 = local_b8 + 1) {
          pHVar3 = (HWND)FUN_004864b1(*(undefined4 *)((int)local_10 + local_b8 * 4));
          if (pHVar3 == local_ac) {
            SetWindowPos(*(HWND *)((int)local_10 + local_b8 * 4),local_98,local_b0,local_b4,0,0,1);
            local_b4 = local_b4 - local_c4;
            local_bc = FUN_004b289b(param_1,*(undefined4 *)((int)local_10 + local_b8 * 4));
            if (0 < local_bc) {
              local_b4 = local_b4 - local_bc * local_c4;
            }
            local_98 = *(HWND *)((int)local_10 + local_b8 * 4);
          }
        }
        return 0;
      case 0x411:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_dc = 0; local_dc < local_14; local_dc = local_dc + 1) {
          auStack_404[local_dc] = *(undefined4 *)((int)local_10 + local_dc * 4);
        }
        local_e4 = 0;
        for (local_dc = 0; local_dc < local_14; local_dc = local_dc + 1) {
          if (*(int *)((int)local_10 + local_dc * 4) != 0) {
            SendMessageA(*(HWND *)((int)local_10 + local_dc * 4),0x401,(WPARAM)&local_40c,0);
            uVar4 = FUN_004472ad(local_40c,local_408);
            if ((uVar4 & 4) != 0) {
              local_e4 = local_e4 + 1;
              local_d8 = FUN_00447038(local_40c,local_408);
              if (local_d8 != -1) {
                for (local_e0 = local_dc + 1; local_e0 < local_14; local_e0 = local_e0 + 1) {
                  SendMessageA(*(HWND *)((int)local_10 + local_e0 * 4),0x401,(WPARAM)&local_40c,0);
                  iVar5 = FUN_00447038(local_40c,local_408);
                  if (iVar5 == local_d8) {
                    *(undefined4 *)((int)local_10 + local_e0 * 4) = 0;
                  }
                }
              }
            }
          }
        }
        for (local_dc = 0; local_dc < local_14; local_dc = local_dc + 1) {
          *(undefined4 *)((int)local_10 + local_dc * 4) = auStack_404[local_dc];
        }
        return local_e4;
      case 0x412:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_8 = (HWND)GetWindowLongA(param_1,0xc);
        GetClientRect(param_1,&local_41c);
        local_420 = FUN_004b289b(param_1,local_8);
        if (local_420 < 1) {
          ShowWindow(local_8,0);
        }
        else {
          SetWindowPos(local_8,(HWND)0x0,local_41c.right + DAT_0061534c * -2,
                       (local_41c.bottom - DAT_0061898c) + -5,0,0,5);
          ShowWindow(local_8,5);
        }
        return 0;
      case 0x432:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_20 = 0; local_20 < local_14; local_20 = local_20 + 1) {
          BVar7 = IsWindowVisible(*(HWND *)((int)local_10 + local_20 * 4));
          if (BVar7 != 0) {
            SendMessageA(*(HWND *)((int)local_10 + local_20 * 4),0x432,0,0);
          }
        }
        return 0;
      case 0x433:
      case 0x434:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_1c = param_3;
        for (local_18 = 0; local_18 < local_14; local_18 = local_18 + 1) {
          iVar5 = FUN_004863ca(*(undefined4 *)((int)local_10 + local_18 * 4),local_1c);
          if (iVar5 != 0) {
            InvalidateRect(*(HWND *)((int)local_10 + local_18 * 4),(RECT *)0x0,0);
          }
        }
        return 0;
      case 0x435:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        for (local_24 = 0; local_24 < local_14; local_24 = local_24 + 1) {
          InvalidateRect(*(HWND *)((int)local_10 + local_24 * 4),(RECT *)0x0,0);
        }
        return 0;
      case 0x436:
        local_10 = (void *)GetWindowLongA(param_1,0);
        local_14 = GetWindowLongA(param_1,4);
        local_30 = param_3;
        local_34 = param_4;
        local_28 = 0;
        local_2c = 0;
        while ((local_2c < local_14 && (local_28 == 0))) {
          iVar5 = FUN_00486348(*(undefined4 *)((int)local_10 + local_2c * 4),local_30);
          if (iVar5 != 0) {
            local_28 = 1;
            if (local_34 == 0) {
              InvalidateRect(*(HWND *)((int)local_10 + local_2c * 4),(RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)((int)local_10 + local_2c * 4),0x432,0,0);
            }
          }
          local_2c = local_2c + 1;
        }
        return 0;
      case 0x437:
        return 0;
      case 0x438:
        LVar1 = GetWindowLongA(param_1,8);
        return LVar1;
      case 0x439:
        local_c = (HWND)GetWindowLongA(param_1,8);
        if (local_c != (HGDIOBJ)0x0) {
          DeleteObject(local_c);
        }
        local_c = param_3;
        SetWindowLongA(param_1,8,(LONG)param_3);
        InvalidateRect(param_1,(RECT *)0x0,1);
        return 0;
      }
    }
    goto switchD_004b1b1f_caseD_403;
  }
  if (param_2 != 0x111) {
    if (param_2 == 0x20) {
      iVar5 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return iVar5;
    }
    goto switchD_004b1b1f_caseD_403;
  }
  uVar4 = (uint)param_3 & 0xffff;
  if ((uVar4 < 0x259) && (uVar4 != 600)) {
    switch(uVar4) {
    case 100:
      FUN_004500a1(&DAT_0066aac4,&DAT_0066ab04,0);
      DAT_0066643c = 0;
      _DAT_005dcd88 = 0xfffffffe;
      _DAT_005dcd8c = 0xffffffff;
      _DAT_005dcd90 = 0xffffffff;
      PostMessageA(DAT_00618990,0x464,0,0x5dcd88);
      break;
    case 0x65:
      DAT_0066ab04 = 0xffffffff;
      DAT_0066aac4 = 0xffffffff;
      DAT_0066643c = 0;
      _DAT_005dcd88 = 0xfffffffe;
      _DAT_005dcd8c = 0xffffffff;
      _DAT_005dcd90 = 0xffffffff;
      PostMessageA(DAT_00618990,0x464,0,0x5dcd88);
      break;
    case 0x66:
      DAT_0066ab04 = 0xffffffff;
      DAT_0066aac4 = 0xffffffff;
      DAT_0066643c = 0;
      _DAT_005dcd88 = 0xfffffffe;
      _DAT_005dcd8c = 0xffffffff;
      _DAT_005dcd90 = 0xfffffffe;
      PostMessageA(DAT_00618990,0x464,0,0x5dcd88);
      break;
    case 0x67:
      FUN_004b1cc1(param_1);
      break;
    case 0x68:
      FUN_00480690(DAT_00618990);
      break;
    case 0x69:
      SendMessageA(DAT_00618990,0x111,0x279,0);
      break;
    case 0x6a:
      SendMessageA(DAT_00618990,0x111,0x27a,0);
      break;
    case 0x6b:
      SendMessageA(DAT_00618990,0x111,0x27c,0);
      break;
    case 0x6c:
      SendMessageA(DAT_00618990,0x10,0,0);
      break;
    case 0x6d:
      SendMessageA(DAT_00618990,0x112,0xf020,0);
      break;
    case 0x6e:
      local_424 = 0x7e2;
      FUN_004d9630(local_52c,&DAT_005f76e0);
      FUN_004d9640(local_52c,s__duel_hlp_005065cc);
      WinHelpA(DAT_00618990,local_52c,1,local_424);
      break;
    case 0x6f:
      SendMessageA(DAT_00618990,0x111,0x27b,0);
      break;
    case 0x70:
      DialogBoxParamA(DAT_00664680,(LPCSTR)0xf7,param_1,FUN_004b29b6,0);
      break;
    default:
      goto switchD_004b10ed_default;
    }
  }
  else {
switchD_004b10ed_default:
    SendMessageA(DAT_00618990,0x111,(WPARAM)param_3,param_4);
  }
  return 0;
}


