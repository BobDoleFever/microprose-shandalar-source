/*
 * Decompiled function: Duel_MainArena_WndProc
 * Entry Point: 004ecfe5
 * Size: 7254 bytes
 */
#include "magic.h"


/* WARNING: Switch with 1 destination removed at 0x004ee2dd : 24 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Duel_MainArena_WndProc(HWND hwnd,uint y,HWND param_3,uint height)

{
  LONG LVar1;
  HWND pHVar2;
  uint uVar3;
  int iVar4;
  HBRUSH pHVar5;
  BOOL BVar6;
  LRESULT LVar7;
  int *arg_4;
  int *arg_5;
  int arg_6;
  int local_618;
  char local_614 [100];
  char local_5b0 [80];
  tagPOINT local_560;
  tagRECT local_558;
  HWND local_548;
  tagRECT local_544;
  uint local_534 [2];
  char local_52c [264];
  ULONG_PTR local_424;
  int local_420;
  tagRECT local_41c;
  int local_40c;
  int local_408;
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
  int local_8c;
  int local_88;
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
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_c = (HWND)GetWindowLongA(hwnd,8);
      local_548 = param_3;
      FUN_004f3955((HDC)param_3);
      GetClientRect(hwnd,&local_544);
      if (DAT_0068a674 != 0) {
        pHVar5 = GetStockObject(0);
        FillRect((HDC)local_548,&local_544,pHVar5);
        Sleep(300);
      }
      if (local_c == (HANDLE)0x0) {
        pHVar5 = GetStockObject(4);
        FillRect((HDC)local_548,&local_544,pHVar5);
      }
      else {
        FUN_004f3b5f((int)local_548,(int)&local_544,local_c);
      }
      return 1;
    }
    if (y == 1) {
      local_14 = 0;
      SetWindowLongA(hwnd,4,0);
      local_10 = malloc(800);
      SetWindowLongA(hwnd,0,(LONG)local_10);
      local_c = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      iVar4 = GetDlgCtrlID(hwnd);
      local_534[0] = (uint)(iVar4 != 0x79);
      local_534[1] = 0xffffffff;
      local_8 = CreateWindowExA(0,s_MAGICGAME_CardClass_0052fce4,s_Player_Card_0052fcd8,0x44000000,0
                                ,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,local_534);
      SetWindowLongA(hwnd,0xc,(LONG)local_8);
      if ((local_10 != (void *)0x0) && (local_8 != (HWND)0x0)) {
        return 0;
      }
      return -1;
    }
    if (y == 2) {
      local_10 = (void *)GetWindowLongA(hwnd,0);
      free(local_10);
      local_c = (HWND)GetWindowLongA(hwnd,8);
      if (local_c != (HANDLE)0x0) {
        FUN_004f4548(local_c);
      }
      return 0;
    }
switchD_004eecac_caseD_403:
    LVar7 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
    return LVar7;
  }
  if (0x111 < y) {
    if (y < 0x120) {
      if (y == 0x11f) {
        if (((uint)param_3 >> 0x10 == 0xffff) && (height == 0)) {
          local_618 = GetMenuItemCount(DAT_005659f8);
          while (local_618 != 0) {
            RemoveMenu(DAT_005659f8,0,0x400);
            local_618 = local_618 + -1;
          }
        }
        return 0;
      }
      if (y == 0x116) {
        if (DAT_006b1578 != 0) {
          if ((DAT_006feed4 & 2) != 0) {
            AppendMenuA(DAT_005659f8,0,0x66,&DAT_0068a680);
          }
          if ((DAT_006feed4 & 1) != 0) {
            AppendMenuA(DAT_005659f8,0,0x65,&DAT_006b2d70);
          }
          Pic_Draw_00427e36((int *)0x0,(undefined4 *)0x0,local_5b0);
          sprintf(local_614,s_Go_to___s_0052fcf8,local_5b0);
          AppendMenuA(DAT_005659f8,0,100,local_614);
        }
        iVar4 = GetMenuItemCount(DAT_005659f8);
        if (0 < iVar4) {
          AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
        }
        if (DAT_006a4924 == hwnd) {
          AppendMenuA(DAT_005659f8,0,0x67,s_Arrange_your_cards_DblClk_0052fd04);
        }
        else {
          AppendMenuA(DAT_005659f8,0,0x67,s_Arrange_opponent_s_cards_DblClk_0052fd20);
        }
        AppendMenuA(DAT_005659f8,0,0x68,s_Duel_Options____0052fd40);
        AppendMenuA(DAT_005659f8,0,0x69,s_Show_ID_tags_Ctrl_T_0052fd50);
        if (DAT_006fe438 != 0) {
          CheckMenuItem(DAT_005659f8,0x69,8);
        }
        AppendMenuA(DAT_005659f8,0,0x6a,s_Show_invisible_effects_Ctrl_I_0052fd64);
        if (DAT_006fe43c != 0) {
          CheckMenuItem(DAT_005659f8,0x6a,8);
        }
        AppendMenuA(DAT_005659f8,0,0x6b,s_Show_all_cards__summoning_sickne_0052fd84);
        if (DAT_006fe440 != 0) {
          CheckMenuItem(DAT_005659f8,0x6b,8);
        }
        AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
        if (((byte)DAT_006fe410 & 1) == 0) {
          AppendMenuA(DAT_005659f8,0,0x6d,s_Minimize_0052fdb0);
          AppendMenuA(DAT_005659f8,0,0x6f,s_Save_game____Ctrl_S_0052fdbc);
        }
        AppendMenuA(DAT_005659f8,0,0x70,s_About____0052fdd0);
        AppendMenuA(DAT_005659f8,0,0x6e,s_Help____0052fddc);
        if (DAT_006b1578 != 0) {
          AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005659f8,0x10,DAT_005659e0,s_Concede_0052fde4);
        }
        if (DAT_0068a718 != 0) {
          AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
          DAT_005659fc = DAT_005659f8;
          AppendMenuA(DAT_005659f8,0,0x272,s_Show_player_card_and___on_librar_0052fdec);
          if (DAT_006808c4 != 0) {
            CheckMenuItem(DAT_005659fc,0x272,8);
          }
          AppendMenuA(DAT_005659fc,0,0x275,s_Which_arts_are_in__Z_0052fe10);
          AppendMenuA(DAT_005659fc,0,0x271,s_Show_the_palette_P_0052fe28);
          AppendMenuA(DAT_005659fc,0,0x276,s_Flash_small_cards_on_repaint_F_0052fe3c);
          if (DAT_0068a674 != 0) {
            CheckMenuItem(DAT_005659fc,0x276,8);
          }
          AppendMenuA(DAT_005659fc,0,0x277,s_Show_Kim_debug_window_K_0052fe5c);
          BVar6 = IsWindowVisible(DAT_0064a0bc);
          if (BVar6 != 0) {
            CheckMenuItem(DAT_005659fc,0x277,8);
          }
          DAT_005659e4 = DAT_005659f8;
          AppendMenuA(DAT_005659f8,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005659e4,0,0x25f,s_Save_game_S_0052fe74);
          AppendMenuA(DAT_005659e4,0,0x26b,s_Put_a_specific_card_IN_PLAY__you_0052fe80);
          AppendMenuA(DAT_005659e4,0,0x26d,s_Put_a_specific_card_into_your_op_0052febc);
          AppendMenuA(DAT_005659e4,0,0x269,s_DRAW_a_card_into_your_oppon_s_ha_0052fef0);
          AppendMenuA(DAT_005659e4,0,0x26f,s__10_to_your_oppon_s_LIFE_L_AltL_0052ff1c);
          AppendMenuA(DAT_005659e4,0,0x267,s_Win_W_0052ff3c);
          AppendMenuA(DAT_005659e4,0,0x263,s_Tie__draw__T_0052ff44);
          AppendMenuA(DAT_005659e4,0,0x25c,s_Show_opponent_s_hand_F8_0052ff54);
          if (DAT_00695e90 != 0) {
            CheckMenuItem(DAT_005659e4,0x25c,8);
          }
          AppendMenuA(DAT_005659e4,0,0x25d,s_Show_opponent_s_library_F9_0052ff6c);
          AppendMenuA(DAT_005659e4,0,0x25e,s_Show_your_library_F10_0052ff88);
          AppendMenuA(DAT_005659e4,0,0x273,s_Show_art_on_cards_A_0052ffa0);
          if (DAT_00695ea4 != 0) {
            CheckMenuItem(DAT_005659e4,0x273,8);
          }
          AppendMenuA(DAT_005659f8,0,599,s_Turn_off_cheats_F12_0052ffb4);
        }
        return 0;
      }
    }
    else if (y < 0x312) {
      if (0x30e < y) {
        iVar4 = FUN_004f5d1a(hwnd,y,param_3,height);
        return iVar4;
      }
      if (y == 0x201) {
        return 0;
      }
      if (y == 0x203) {
        SendMessageA(hwnd,0x111,0x67,0);
        return 0;
      }
      if (y == 0x204) {
        local_560.x = height & 0xffff;
        local_560.y = height >> 0x10;
        ClientToScreen(hwnd,&local_560);
        SetRect(&local_558,local_560.x,local_560.y,local_560.x + 1,local_560.y + 1);
        TrackPopupMenu(DAT_005659f8,2,local_560.x,local_560.y,0,hwnd,&local_558);
        return 0;
      }
    }
    else {
      switch(y) {
      case 0x400:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_8 = (HWND)GetWindowLongA(hwnd,0xc);
        for (local_7c = 0; local_7c < local_14; local_7c = local_7c + 1) {
          SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x401,(WPARAM)&local_8c,0);
          local_84 = Ai_Subsystem_004b5cbb(local_8c,local_88);
          Ai_Subsystem_004b5f74(&local_94,local_8c,local_88);
          uVar3 = Ai_Subsystem_004b5de4(local_8c,local_88);
          if (((uVar3 & 0x10) == 0) ||
             ((local_84 < DAT_00695e94 &&
              ((*(int *)(&DAT_006b3084 + local_84 * 0x98) != 2 ||
               (*(int *)(&DAT_006b3088 + local_84 * 0x98) == 0xda)))))) {
            if ((local_84 == DAT_00695e94) && ((local_94 != -1 && (local_90 == -1)))) {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,(WPARAM)local_8,0);
            }
            else {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,0,0);
            }
          }
          else {
            iVar4 = Duel_HitTestCardSlot(hwnd,&local_94,(undefined4 *)0x0,&local_78);
            if (iVar4 == 0) {
              if (DAT_006a4924 == hwnd) {
                local_80 = DAT_006b2e2c;
              }
              else {
                local_80 = DAT_006a4924;
              }
              iVar4 = Duel_HitTestCardSlot(local_80,&local_94,(undefined4 *)0x0,&local_78);
              if (iVar4 != 0) {
                SendMessageA(hwnd,0x40b,(WPARAM)&local_8c,0);
                SendMessageA(local_80,0x40a,(WPARAM)&local_8c,0);
                PostMessageA(local_80,0x400,0,0);
              }
            }
            else {
              SendMessageA(*(HWND *)((int)local_10 + local_7c * 4),0x402,local_78,0);
            }
          }
        }
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_7c = 0; local_7c < local_14; local_7c = local_7c + 1) {
          SendMessageA(hwnd,0x410,*(WPARAM *)((int)local_10 + local_7c * 4),0);
        }
        SendMessageA(hwnd,0x410,(WPARAM)local_8,0);
        return 0;
      case 0x401:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_d4 = 0; local_d4 < local_14; local_d4 = local_d4 + 1) {
          BVar6 = IsWindowVisible(*(HWND *)((int)local_10 + local_d4 * 4));
          if (BVar6 == 0) {
            ShowWindow(*(HWND *)((int)local_10 + local_d4 * 4),5);
          }
        }
        return 0;
      case 0x402:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_cc = param_3;
        local_c8 = height;
        if (param_3 == (HWND)0x0) {
          return 0;
        }
        ShowWindow(param_3,(height == 0) - 1 & 5);
        for (local_d0 = 0; local_d0 < local_14; local_d0 = local_d0 + 1) {
          pHVar2 = (HWND)FUN_0046bc92(*(HWND *)((int)local_10 + local_d0 * 4));
          if (pHVar2 == local_cc) {
            SendMessageA(hwnd,0x402,*(WPARAM *)((int)local_10 + local_d0 * 4),local_c8);
          }
        }
        return 0;
      case 0x40a:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        if (199 < local_14) {
          return 0;
        }
        local_38 = param_3;
        if ((param_3 == (HWND)0x0) ||
           (iVar4 = Ai_Subsystem_004b5cbb(param_3->unused,param_3[1].unused), DAT_006a49f4 < iVar4))
        {
          return 0;
        }
        iVar4 = Duel_HitTestCardSlot(hwnd,&local_38->unused,(undefined4 *)0x0,&local_3c);
        if (iVar4 != 0) {
          return local_14;
        }
        local_3c = CreateWindowExA(0,s_MAGICGAME_CardClass_0052fcb8,s_In_play_Card_0052fca8,
                                   0x44000000,0,0,DAT_006a28b0,DAT_006b2e30,hwnd,(HMENU)0x1,
                                   g_AppHInstance,local_38);
        if (local_3c != (HWND)0x0) {
          arg_6 = 1;
          arg_5 = &local_44;
          arg_4 = &local_40;
          iVar4 = FUN_0046ad4a(local_3c);
          Duel_LayoutCardSlots(hwnd,&local_38->unused,iVar4,arg_4,arg_5,arg_6);
          SetWindowPos(local_3c,(HWND)0x0,local_40,local_44,0,0,5);
          *(HWND *)((int)local_10 + local_14 * 4) = local_3c;
          local_14 = local_14 + 1;
          SetWindowLongA(hwnd,4,local_14);
          BringWindowToTop(local_3c);
          SendMessageA(hwnd,0x400,0,0);
          ShowWindow(local_3c,5);
          return local_14;
        }
        return 0;
      case 0x40b:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_54 = param_3;
        local_48 = 0;
        local_4c = 0;
        while( true ) {
          if (local_14 <= local_4c) {
            return local_48;
          }
          if (local_48 != 0) break;
          iVar4 = FUN_0046bb29(*(HWND *)((int)local_10 + local_4c * 4),&local_54->unused);
          if (iVar4 != 0) {
            local_48 = 1;
            DestroyWindow(*(HWND *)((int)local_10 + local_4c * 4));
            local_14 = local_14 + -1;
            for (local_50 = local_4c; local_50 < local_14; local_50 = local_50 + 1) {
              *(undefined4 *)((int)local_10 + local_50 * 4) =
                   *(undefined4 *)((int)local_10 + 4 + local_50 * 4);
            }
            SetWindowLongA(hwnd,4,local_14);
            for (local_50 = 0; local_50 < local_14; local_50 = local_50 + 1) {
              iVar4 = FUN_0046bc92(*(HWND *)((int)local_10 + local_50 * 4));
              if (iVar4 == *(int *)((int)local_10 + local_4c * 4)) {
                SendMessageA(*(HWND *)((int)local_10 + local_50 * 4),0x402,0,0);
              }
            }
          }
          local_4c = local_4c + 1;
        }
        return local_48;
      case 0x40c:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_58 = 0; local_58 < local_14; local_58 = local_58 + 1) {
          DestroyWindow(*(HWND *)((int)local_10 + local_58 * 4));
        }
        local_14 = 0;
        SetWindowLongA(hwnd,4,0);
        Duel_GetBattlefieldClientRect(hwnd);
        return 0;
      case 0x40d:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_74 = param_3;
        local_6c = 0;
        local_70 = 0;
        while( true ) {
          if (local_14 <= local_70) {
            return local_6c;
          }
          if (local_6c != 0) break;
          iVar4 = FUN_0046bb29(*(HWND *)((int)local_10 + local_70 * 4),&local_74->unused);
          if (iVar4 != 0) {
            local_6c = 1;
            BringWindowToTop(*(HWND *)((int)local_10 + local_70 * 4));
            SendMessageA(hwnd,0x400,0,0);
          }
          local_70 = local_70 + 1;
        }
        return local_6c;
      case 0x40e:
      case 0x40f:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_64 = param_3;
        local_5c = 0;
        local_68 = 0;
        while ((local_68 < local_14 && (local_5c == 0))) {
          iVar4 = FUN_0046bb29(*(HWND *)((int)local_10 + local_68 * 4),&local_64->unused);
          if (iVar4 != 0) {
            local_5c = 1;
            if (y == 0x40e) {
              local_60 = FUN_0046bc2f(*(HWND *)((int)local_10 + local_68 * 4));
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
        if (y == 0x40e) {
          return -1;
        }
        return 0;
      case 0x410:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_ac = param_3;
        if (param_3 == (HWND)0x0) {
          return 0;
        }
        local_c0 = 5;
        local_c4 = DAT_006ff67c;
        GetWindowRect(param_3,&local_a8);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_a8,2);
        local_b0 = local_a8.left + local_c0;
        local_b4 = local_a8.top - local_c4;
        local_98 = local_ac;
        for (local_b8 = 0; local_b8 < local_14; local_b8 = local_b8 + 1) {
          pHVar2 = (HWND)FUN_0046bc92(*(HWND *)((int)local_10 + local_b8 * 4));
          if (pHVar2 == local_ac) {
            SetWindowPos(*(HWND *)((int)local_10 + local_b8 * 4),local_98,local_b0,local_b4,0,0,1);
            local_b4 = local_b4 - local_c4;
            local_bc = Duel_GetCardSlotWindowHandle(hwnd,*(int *)((int)local_10 + local_b8 * 4));
            if (0 < local_bc) {
              local_b4 = local_b4 - local_bc * local_c4;
            }
            local_98 = *(HWND *)((int)local_10 + local_b8 * 4);
          }
        }
        return 0;
      case 0x411:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_dc = 0; local_dc < local_14; local_dc = local_dc + 1) {
          auStack_404[local_dc] = *(undefined4 *)((int)local_10 + local_dc * 4);
        }
        local_e4 = 0;
        for (local_dc = 0; local_dc < local_14; local_dc = local_dc + 1) {
          if (*(int *)((int)local_10 + local_dc * 4) != 0) {
            SendMessageA(*(HWND *)((int)local_10 + local_dc * 4),0x401,(WPARAM)&local_40c,0);
            uVar3 = Ai_Subsystem_004b5de4(local_40c,local_408);
            if ((uVar3 & 4) != 0) {
              local_e4 = local_e4 + 1;
              local_d8 = Ai_Subsystem_004b5b6f(local_40c,local_408);
              if (local_d8 != -1) {
                for (local_e0 = local_dc + 1; local_e0 < local_14; local_e0 = local_e0 + 1) {
                  SendMessageA(*(HWND *)((int)local_10 + local_e0 * 4),0x401,(WPARAM)&local_40c,0);
                  iVar4 = Ai_Subsystem_004b5b6f(local_40c,local_408);
                  if (iVar4 == local_d8) {
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
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_8 = (HWND)GetWindowLongA(hwnd,0xc);
        GetClientRect(hwnd,&local_41c);
        local_420 = Duel_GetCardSlotWindowHandle(hwnd,(int)local_8);
        if (local_420 < 1) {
          ShowWindow(local_8,0);
        }
        else {
          SetWindowPos(local_8,(HWND)0x0,local_41c.right + DAT_006a28b0 * -2,
                       (local_41c.bottom - DAT_006b2e30) + -5,0,0,5);
          ShowWindow(local_8,5);
        }
        return 0;
      case 0x432:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_20 = 0; local_20 < local_14; local_20 = local_20 + 1) {
          BVar6 = IsWindowVisible(*(HWND *)((int)local_10 + local_20 * 4));
          if (BVar6 != 0) {
            SendMessageA(*(HWND *)((int)local_10 + local_20 * 4),0x432,0,0);
          }
        }
        return 0;
      case 0x433:
      case 0x434:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_1c = param_3;
        for (local_18 = 0; local_18 < local_14; local_18 = local_18 + 1) {
          iVar4 = FUN_0046bbab(*(HWND *)((int)local_10 + local_18 * 4),(int)local_1c);
          if (iVar4 != 0) {
            InvalidateRect(*(HWND *)((int)local_10 + local_18 * 4),(RECT *)0x0,0);
          }
        }
        return 0;
      case 0x435:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        for (local_24 = 0; local_24 < local_14; local_24 = local_24 + 1) {
          InvalidateRect(*(HWND *)((int)local_10 + local_24 * 4),(RECT *)0x0,0);
        }
        return 0;
      case 0x436:
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_14 = GetWindowLongA(hwnd,4);
        local_30 = param_3;
        local_34 = height;
        local_28 = 0;
        local_2c = 0;
        while ((local_2c < local_14 && (local_28 == 0))) {
          iVar4 = FUN_0046bb29(*(HWND *)((int)local_10 + local_2c * 4),&local_30->unused);
          if (iVar4 != 0) {
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
        LVar1 = GetWindowLongA(hwnd,8);
        return LVar1;
      case 0x439:
        local_c = (HWND)GetWindowLongA(hwnd,8);
        if (local_c != (HGDIOBJ)0x0) {
          DeleteObject(local_c);
        }
        local_c = param_3;
        SetWindowLongA(hwnd,8,(LONG)param_3);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      }
    }
    goto switchD_004eecac_caseD_403;
  }
  if (y != 0x111) {
    if (y == 0x20) {
      iVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,height);
      return iVar4;
    }
    goto switchD_004eecac_caseD_403;
  }
  uVar3 = (uint)param_3 & 0xffff;
  if ((uVar3 < 0x259) && (uVar3 != 600)) {
    switch(uVar3) {
    case 100:
      Pic_Draw_00427e36(&DAT_00627a84,&DAT_00627a88,(char *)0x0);
      DAT_00627864 = 0;
      _DAT_005659e8 = 0xfffffffe;
      _DAT_005659ec = 0xffffffff;
      _DAT_005659f0 = 0xffffffff;
      PostMessageA(g_MainAppHwnd,0x464,0,0x5659e8);
      break;
    case 0x65:
      DAT_00627a88 = 0xffffffff;
      DAT_00627a84 = 0xffffffff;
      DAT_00627864 = 0;
      _DAT_005659e8 = 0xfffffffe;
      _DAT_005659ec = 0xffffffff;
      _DAT_005659f0 = 0xffffffff;
      PostMessageA(g_MainAppHwnd,0x464,0,0x5659e8);
      break;
    case 0x66:
      DAT_00627a88 = 0xffffffff;
      DAT_00627a84 = 0xffffffff;
      DAT_00627864 = 0;
      _DAT_005659e8 = 0xfffffffe;
      _DAT_005659ec = 0xffffffff;
      _DAT_005659f0 = 0xfffffffe;
      PostMessageA(g_MainAppHwnd,0x464,0,0x5659e8);
      break;
    case 0x67:
      Duel_BringCardWindowToTop(hwnd);
      break;
    case 0x68:
      FUN_004ff450(g_MainAppHwnd);
      break;
    case 0x69:
      SendMessageA(g_MainAppHwnd,0x111,0x279,0);
      break;
    case 0x6a:
      SendMessageA(g_MainAppHwnd,0x111,0x27a,0);
      break;
    case 0x6b:
      SendMessageA(g_MainAppHwnd,0x111,0x27c,0);
      break;
    case 0x6c:
      SendMessageA(g_MainAppHwnd,0x10,0,0);
      break;
    case 0x6d:
      SendMessageA(g_MainAppHwnd,0x112,0xf020,0);
      break;
    case 0x6e:
      local_424 = 0x7e2;
      strcpy(local_52c,&DAT_006807a0);
      strcat(local_52c,s__duel_hlp_0052fccc);
      WinHelpA(g_MainAppHwnd,local_52c,1,local_424);
      break;
    case 0x6f:
      SendMessageA(g_MainAppHwnd,0x111,0x27b,0);
      break;
    case 0x70:
      DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf7,hwnd,Duel_PaintBattlefieldBackground,0);
      break;
    default:
      goto switchD_004ee27d_default;
    }
  }
  else {
switchD_004ee27d_default:
    SendMessageA(g_MainAppHwnd,0x111,(WPARAM)param_3,height);
  }
  return 0;
}


