/*
 * sid/glue_duel_ui.c - Tactical Duel Combat Arena Window, Debug Cheats & Status Banners
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"

/*
 * Duel_MainArena_WndProc
 * Purpose: Main duel arena combat window procedure and context debug cheat menus.
 * Procedure:
 * 1. Handle WM_PAINT to render active duel battlefield.
 * 2. Handle WM_COMMAND to process debug menu options (life, reveal hand/library, force win/tie).
 * 3. Handle mouse clicks and drag drop card actions.
 * 4. Forward unhandled messages to DefWindowProcA.
 */
/*
 * Decompiled function: Duel_MainArena_WndProc
 * Entry Point: 004ecfe5
 * Size: 7254 bytes
 */

/* WARNING: Switch with 1 destination removed at 0x004ee2dd : 24 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Duel_MainArena_WndProc(HWND hwnd,uint32_t y,HWND wParam,uint32_t height)

{
  LONG LVar1;
  HWND pHVar2;
  uint32_t uval_3;
  int val_4;
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
  uint32_t local_534 [2];
  char local_52c [264];
  ULONG_PTR local_424;
  int local_420;
  tagRECT local_41c;
  int local_40c;
  int local_408;
  int auStack_404 [200];
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  HWND local_cc;
  uint32_t local_c8;
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
  uint32_t local_34;
  HWND local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  HWND color_idx;
  int target_idx;
  int player_idx;
  void *card_idx;
  HWND match_count;
  HWND slot_idx;
  
  if (y < 0x15) {
    if (y == 0x14) {
      match_count = (HWND)GetWindowLongA(hwnd,8);
      local_548 = wParam;
      GDI_RealizeAndFlushPalette_Magic((HDC)wParam);
      GetClientRect(hwnd,&local_544);
      if (DAT_0068a674 != 0) {
        pHVar5 = GetStockObject(0);
        FillRect((HDC)local_548,&local_544,pHVar5);
        Sleep(300);
      }
      if (match_count == (HANDLE)0x0) {
        pHVar5 = GetStockObject(4);
        FillRect((HDC)local_548,&local_544,pHVar5);
      }
      else {
        FUN_004f3b5f((int)local_548,(int)&local_544,match_count);
      }
      return 1;
    }
    if (y == 1) {
      player_idx = 0;
      SetWindowLongA(hwnd,4,0);
      card_idx = malloc(800);
      SetWindowLongA(hwnd,0,(LONG)card_idx);
      match_count = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      val_4 = GetDlgCtrlID(hwnd);
      local_534[0] = (uint32_t)(val_4 != 0x79);
      local_534[1] = 0xffffffff;
      slot_idx = CreateWindowExA(0,s_MAGICGAME_CardClass_0052fce4,s_Player_Card_0052fcd8,0x44000000,0
                                ,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,local_534);
      SetWindowLongA(hwnd,0xc,(LONG)slot_idx);
      if ((card_idx != (void *)0x0) && (slot_idx != (HWND)0x0)) {
        return 0;
      }
      return -1;
    }
    if (y == 2) {
      card_idx = (void *)GetWindowLongA(hwnd,0);
      free(card_idx);
      match_count = (HWND)GetWindowLongA(hwnd,8);
      if (match_count != (HANDLE)0x0) {
        Pic_DestroyDIBSection(match_count);
      }
      return 0;
    }
switchD_004eecac_caseD_403:
    LVar7 = DefWindowProcA(hwnd,y,(WPARAM)wParam,height);
    return LVar7;
  }
  if (0x111 < y) {
    if (y < 0x120) {
      if (y == 0x11f) {
        if (((uint32_t)wParam >> 0x10 == 0xffff) && (height == 0)) {
          local_618 = GetMenuItemCount(g_CampaignMenuHandle);
          while (local_618 != 0) {
            RemoveMenu(g_CampaignMenuHandle,0,0x400);
            local_618 = local_618 + -1;
          }
        }
        return 0;
      }
      if (y == 0x116) {
        if (DAT_006b1578 != 0) {
          if ((DAT_006feed4 & 2) != 0) {
            AppendMenuA(g_CampaignMenuHandle,0,0x66,&DAT_0068a680);
          }
          if ((DAT_006feed4 & 1) != 0) {
            AppendMenuA(g_CampaignMenuHandle,0,0x65,&DAT_006b2d70);
          }
          Pic_Draw_00427e36((int *)0x0,(int *)0x0,local_5b0);
          sprintf(local_614,s_Go_to___s_0052fcf8,local_5b0);
          AppendMenuA(g_CampaignMenuHandle,0,100,local_614);
        }
        val_4 = GetMenuItemCount(g_CampaignMenuHandle);
        if (0 < val_4) {
          AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
        }
        if (g_TurnPriorityState == hwnd) {
          AppendMenuA(g_CampaignMenuHandle,0,0x67,s_Arrange_your_cards_DblClk_0052fd04);
        }
        else {
          AppendMenuA(g_CampaignMenuHandle,0,0x67,s_Arrange_opponent_s_cards_DblClk_0052fd20);
        }
        AppendMenuA(g_CampaignMenuHandle,0,0x68,s_Duel_Options____0052fd40);
        AppendMenuA(g_CampaignMenuHandle,0,0x69,s_Show_ID_tags_Ctrl_T_0052fd50);
        if (DAT_006fe438 != 0) {
          CheckMenuItem(g_CampaignMenuHandle,0x69,8);
        }
        AppendMenuA(g_CampaignMenuHandle,0,0x6a,s_Show_invisible_effects_Ctrl_I_0052fd64);
        if (DAT_006fe43c != 0) {
          CheckMenuItem(g_CampaignMenuHandle,0x6a,8);
        }
        AppendMenuA(g_CampaignMenuHandle,0,0x6b,s_Show_all_cards__summoning_sickne_0052fd84);
        if (DAT_006fe440 != 0) {
          CheckMenuItem(g_CampaignMenuHandle,0x6b,8);
        }
        AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
        if (((uint8_t)DAT_006fe410 & 1) == 0) {
          AppendMenuA(g_CampaignMenuHandle,0,0x6d,s_Minimize_0052fdb0);
          AppendMenuA(g_CampaignMenuHandle,0,0x6f,s_Save_game____Ctrl_S_0052fdbc);
        }
        AppendMenuA(g_CampaignMenuHandle,0,0x70,s_About____0052fdd0);
        AppendMenuA(g_CampaignMenuHandle,0,0x6e,s_Help____0052fddc);
        if (DAT_006b1578 != 0) {
          AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
          AppendMenuA(g_CampaignMenuHandle,0x10,DAT_005659e0,s_Concede_0052fde4);
        }
        if (DAT_0068a718 != 0) {
          AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
          AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
          DAT_005659fc = g_CampaignMenuHandle;
          AppendMenuA(g_CampaignMenuHandle,0,0x272,s_Show_player_card_and___on_librar_0052fdec);
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
          DAT_005659e4 = g_CampaignMenuHandle;
          AppendMenuA(g_CampaignMenuHandle,0x800,0,(LPCSTR)0x0);
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
          AppendMenuA(g_CampaignMenuHandle,0,599,s_Turn_off_cheats_F12_0052ffb4);
        }
        return 0;
      }
    }
    else if (y < 0x312) {
      if (0x30e < y) {
        val_4 = GDI_RealizePaletteTree_Magic(hwnd,y,wParam,height);
        return val_4;
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
        TrackPopupMenu(g_CampaignMenuHandle,2,local_560.x,local_560.y,0,hwnd,&local_558);
        return 0;
      }
    }
    else {
      switch(y) {
      case 0x400:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        slot_idx = (HWND)GetWindowLongA(hwnd,0xc);
        for (local_7c = 0; local_7c < player_idx; local_7c = local_7c + 1) {
          SendMessageA(*(HWND *)((int)card_idx + local_7c * 4),0x401,(WPARAM)&local_8c,0);
          local_84 = Ai_Subsystem_004b5cbb(local_8c,local_88);
          Ai_Subsystem_004b5f74(&local_94,local_8c,local_88);
          uval_3 = Ai_Subsystem_004b5de4(local_8c,local_88);
          if (((uval_3 & 0x10) == 0) ||
             ((local_84 < DAT_00695e94 &&
              ((*(int *)(&DAT_006b3084 + local_84 * 0x98) != 2 ||
               (*(int *)(&DAT_006b3088 + local_84 * 0x98) == 0xda)))))) {
            if ((local_84 == DAT_00695e94) && ((local_94 != -1 && (local_90 == -1)))) {
              SendMessageA(*(HWND *)((int)card_idx + local_7c * 4),0x402,(WPARAM)slot_idx,0);
            }
            else {
              SendMessageA(*(HWND *)((int)card_idx + local_7c * 4),0x402,0,0);
            }
          }
          else {
            val_4 = Duel_HitTestCardSlot(hwnd,&local_94,(int *)0x0,&local_78);
            if (val_4 == 0) {
              if (g_TurnPriorityState == hwnd) {
                local_80 = g_AiSelectedActionCode;
              }
              else {
                local_80 = g_TurnPriorityState;
              }
              val_4 = Duel_HitTestCardSlot(local_80,&local_94,(int *)0x0,&local_78);
              if (val_4 != 0) {
                SendMessageA(hwnd,0x40b,(WPARAM)&local_8c,0);
                SendMessageA(local_80,0x40a,(WPARAM)&local_8c,0);
                PostMessageA(local_80,0x400,0,0);
              }
            }
            else {
              SendMessageA(*(HWND *)((int)card_idx + local_7c * 4),0x402,local_78,0);
            }
          }
        }
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (local_7c = 0; local_7c < player_idx; local_7c = local_7c + 1) {
          SendMessageA(hwnd,0x410,*(WPARAM *)((int)card_idx + local_7c * 4),0);
        }
        SendMessageA(hwnd,0x410,(WPARAM)slot_idx,0);
        return 0;
      case 0x401:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (local_d4 = 0; local_d4 < player_idx; local_d4 = local_d4 + 1) {
          BVar6 = IsWindowVisible(*(HWND *)((int)card_idx + local_d4 * 4));
          if (BVar6 == 0) {
            ShowWindow(*(HWND *)((int)card_idx + local_d4 * 4),5);
          }
        }
        return 0;
      case 0x402:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_cc = wParam;
        local_c8 = height;
        if (wParam == (HWND)0x0) {
          return 0;
        }
        ShowWindow(wParam,(height == 0) - 1 & 5);
        for (local_d0 = 0; local_d0 < player_idx; local_d0 = local_d0 + 1) {
          pHVar2 = (HWND)FUN_0046bc92(*(HWND *)((int)card_idx + local_d0 * 4));
          if (pHVar2 == local_cc) {
            SendMessageA(hwnd,0x402,*(WPARAM *)((int)card_idx + local_d0 * 4),local_c8);
          }
        }
        return 0;
      case 0x40a:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        if (199 < player_idx) {
          return 0;
        }
        local_38 = wParam;
        if ((wParam == (HWND)0x0) ||
           (val_4 = Ai_Subsystem_004b5cbb(wParam->unused,wParam[1].unused), g_CardsDatLoadedHandle < val_4))
        {
          return 0;
        }
        val_4 = Duel_HitTestCardSlot(hwnd,&local_38->unused,(int *)0x0,&local_3c);
        if (val_4 != 0) {
          return player_idx;
        }
        local_3c = CreateWindowExA(0,s_MAGICGAME_CardClass_0052fcb8,s_In_play_Card_0052fca8,
                                   0x44000000,0,0,g_PlayerGoldCoins,g_PlayerAmuletGems,hwnd,(HMENU)0x1,
                                   g_AppHInstance,local_38);
        if (local_3c != (HWND)0x0) {
          arg_6 = 1;
          arg_5 = &local_44;
          arg_4 = &local_40;
          val_4 = FUN_0046ad4a(local_3c);
          Duel_LayoutCardSlots(hwnd,&local_38->unused,val_4,arg_4,arg_5,arg_6);
          SetWindowPos(local_3c,(HWND)0x0,local_40,local_44,0,0,5);
          *(HWND *)((int)card_idx + player_idx * 4) = local_3c;
          player_idx = player_idx + 1;
          SetWindowLongA(hwnd,4,player_idx);
          BringWindowToTop(local_3c);
          SendMessageA(hwnd,0x400,0,0);
          ShowWindow(local_3c,5);
          return player_idx;
        }
        return 0;
      case 0x40b:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_54 = wParam;
        local_48 = 0;
        local_4c = 0;
        while( true ) {
          if (player_idx <= local_4c) {
            return local_48;
          }
          if (local_48 != 0) break;
          val_4 = FUN_0046bb29(*(HWND *)((int)card_idx + local_4c * 4),&local_54->unused);
          if (val_4 != 0) {
            local_48 = 1;
            DestroyWindow(*(HWND *)((int)card_idx + local_4c * 4));
            player_idx = player_idx + -1;
            for (local_50 = local_4c; local_50 < player_idx; local_50 = local_50 + 1) {
              *(int *)((int)card_idx + local_50 * 4) =
                   *(int *)((int)card_idx + 4 + local_50 * 4);
            }
            SetWindowLongA(hwnd,4,player_idx);
            for (local_50 = 0; local_50 < player_idx; local_50 = local_50 + 1) {
              val_4 = FUN_0046bc92(*(HWND *)((int)card_idx + local_50 * 4));
              if (val_4 == *(int *)((int)card_idx + local_4c * 4)) {
                SendMessageA(*(HWND *)((int)card_idx + local_50 * 4),0x402,0,0);
              }
            }
          }
          local_4c = local_4c + 1;
        }
        return local_48;
      case 0x40c:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (local_58 = 0; local_58 < player_idx; local_58 = local_58 + 1) {
          DestroyWindow(*(HWND *)((int)card_idx + local_58 * 4));
        }
        player_idx = 0;
        SetWindowLongA(hwnd,4,0);
        Duel_GetBattlefieldClientRect(hwnd);
        return 0;
      case 0x40d:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_74 = wParam;
        local_6c = 0;
        local_70 = 0;
        while( true ) {
          if (player_idx <= local_70) {
            return local_6c;
          }
          if (local_6c != 0) break;
          val_4 = FUN_0046bb29(*(HWND *)((int)card_idx + local_70 * 4),&local_74->unused);
          if (val_4 != 0) {
            local_6c = 1;
            BringWindowToTop(*(HWND *)((int)card_idx + local_70 * 4));
            SendMessageA(hwnd,0x400,0,0);
          }
          local_70 = local_70 + 1;
        }
        return local_6c;
      case 0x40e:
      case 0x40f:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_64 = wParam;
        local_5c = 0;
        local_68 = 0;
        while ((local_68 < player_idx && (local_5c == 0))) {
          val_4 = FUN_0046bb29(*(HWND *)((int)card_idx + local_68 * 4),&local_64->unused);
          if (val_4 != 0) {
            local_5c = 1;
            if (y == 0x40e) {
              local_60 = FUN_0046bc2f(*(HWND *)((int)card_idx + local_68 * 4));
            }
            else {
              local_60 = *(int *)((int)card_idx + local_68 * 4);
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
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_ac = wParam;
        if (wParam == (HWND)0x0) {
          return 0;
        }
        local_c0 = 5;
        local_c4 = DAT_006ff67c;
        GetWindowRect(wParam,&local_a8);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_a8,2);
        local_b0 = local_a8.left + local_c0;
        local_b4 = local_a8.top - local_c4;
        local_98 = local_ac;
        for (local_b8 = 0; local_b8 < player_idx; local_b8 = local_b8 + 1) {
          pHVar2 = (HWND)FUN_0046bc92(*(HWND *)((int)card_idx + local_b8 * 4));
          if (pHVar2 == local_ac) {
            SetWindowPos(*(HWND *)((int)card_idx + local_b8 * 4),local_98,local_b0,local_b4,0,0,1);
            local_b4 = local_b4 - local_c4;
            local_bc = Duel_GetCardSlotWindowHandle(hwnd,*(int *)((int)card_idx + local_b8 * 4));
            if (0 < local_bc) {
              local_b4 = local_b4 - local_bc * local_c4;
            }
            local_98 = *(HWND *)((int)card_idx + local_b8 * 4);
          }
        }
        return 0;
      case 0x411:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (local_dc = 0; local_dc < player_idx; local_dc = local_dc + 1) {
          auStack_404[local_dc] = *(int *)((int)card_idx + local_dc * 4);
        }
        local_e4 = 0;
        for (local_dc = 0; local_dc < player_idx; local_dc = local_dc + 1) {
          if (*(int *)((int)card_idx + local_dc * 4) != 0) {
            SendMessageA(*(HWND *)((int)card_idx + local_dc * 4),0x401,(WPARAM)&local_40c,0);
            uval_3 = Ai_Subsystem_004b5de4(local_40c,local_408);
            if ((uval_3 & 4) != 0) {
              local_e4 = local_e4 + 1;
              local_d8 = Ai_Subsystem_004b5b6f(local_40c,local_408);
              if (local_d8 != -1) {
                for (local_e0 = local_dc + 1; local_e0 < player_idx; local_e0 = local_e0 + 1) {
                  SendMessageA(*(HWND *)((int)card_idx + local_e0 * 4),0x401,(WPARAM)&local_40c,0);
                  val_4 = Ai_Subsystem_004b5b6f(local_40c,local_408);
                  if (val_4 == local_d8) {
                    *(int *)((int)card_idx + local_e0 * 4) = 0;
                  }
                }
              }
            }
          }
        }
        for (local_dc = 0; local_dc < player_idx; local_dc = local_dc + 1) {
          *(int *)((int)card_idx + local_dc * 4) = auStack_404[local_dc];
        }
        return local_e4;
      case 0x412:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        slot_idx = (HWND)GetWindowLongA(hwnd,0xc);
        GetClientRect(hwnd,&local_41c);
        local_420 = Duel_GetCardSlotWindowHandle(hwnd,(int)slot_idx);
        if (local_420 < 1) {
          ShowWindow(slot_idx,0);
        }
        else {
          SetWindowPos(slot_idx,(HWND)0x0,local_41c.right + g_PlayerGoldCoins * -2,
                       (local_41c.bottom - g_PlayerAmuletGems) + -5,0,0,5);
          ShowWindow(slot_idx,5);
        }
        return 0;
      case 0x432:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (loop_idx = 0; loop_idx < player_idx; loop_idx = loop_idx + 1) {
          BVar6 = IsWindowVisible(*(HWND *)((int)card_idx + loop_idx * 4));
          if (BVar6 != 0) {
            SendMessageA(*(HWND *)((int)card_idx + loop_idx * 4),0x432,0,0);
          }
        }
        return 0;
      case 0x433:
      case 0x434:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        color_idx = wParam;
        for (target_idx = 0; target_idx < player_idx; target_idx = target_idx + 1) {
          val_4 = FUN_0046bbab(*(HWND *)((int)card_idx + target_idx * 4),(int)color_idx);
          if (val_4 != 0) {
            InvalidateRect(*(HWND *)((int)card_idx + target_idx * 4),(RECT *)0x0,0);
          }
        }
        return 0;
      case 0x435:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        for (local_24 = 0; local_24 < player_idx; local_24 = local_24 + 1) {
          InvalidateRect(*(HWND *)((int)card_idx + local_24 * 4),(RECT *)0x0,0);
        }
        return 0;
      case 0x436:
        card_idx = (void *)GetWindowLongA(hwnd,0);
        player_idx = GetWindowLongA(hwnd,4);
        local_30 = wParam;
        local_34 = height;
        local_28 = 0;
        local_2c = 0;
        while ((local_2c < player_idx && (local_28 == 0))) {
          val_4 = FUN_0046bb29(*(HWND *)((int)card_idx + local_2c * 4),&local_30->unused);
          if (val_4 != 0) {
            local_28 = 1;
            if (local_34 == 0) {
              InvalidateRect(*(HWND *)((int)card_idx + local_2c * 4),(RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)((int)card_idx + local_2c * 4),0x432,0,0);
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
        match_count = (HWND)GetWindowLongA(hwnd,8);
        if (match_count != (HGDIOBJ)0x0) {
          DeleteObject(match_count);
        }
        match_count = wParam;
        SetWindowLongA(hwnd,8,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      }
    }
    goto switchD_004eecac_caseD_403;
  }
  if (y != 0x111) {
    if (y == 0x20) {
      val_4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,height);
      return val_4;
    }
    goto switchD_004eecac_caseD_403;
  }
  uval_3 = (uint32_t)wParam & 0xffff;
  if ((uval_3 < 0x259) && (uval_3 != 600)) {
    switch(uval_3) {
    case 100:
      Pic_Draw_00427e36(&DAT_00627a84,&DAT_00627a88,(char *)0x0);
      g_AiTemporaryCardState = 0;
      _DAT_005659e8 = 0xfffffffe;
      _DAT_005659ec = 0xffffffff;
      _DAT_005659f0 = 0xffffffff;
      PostMessageA(g_MainAppHwnd,0x464,0,0x5659e8);
      break;
    case 0x65:
      DAT_00627a88 = 0xffffffff;
      DAT_00627a84 = 0xffffffff;
      g_AiTemporaryCardState = 0;
      _DAT_005659e8 = 0xfffffffe;
      _DAT_005659ec = 0xffffffff;
      _DAT_005659f0 = 0xffffffff;
      PostMessageA(g_MainAppHwnd,0x464,0,0x5659e8);
      break;
    case 0x66:
      DAT_00627a88 = 0xffffffff;
      DAT_00627a84 = 0xffffffff;
      g_AiTemporaryCardState = 0;
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
      strcpy(local_52c,&g_GameInstallDirectory);
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
    SendMessageA(g_MainAppHwnd,0x111,(WPARAM)wParam,height);
  }
  return 0;
}

/*
 * Duel_UpdateWindowScroll
 * Purpose: Update horizontal and vertical card table scroll positions.
 * Procedure:
 * 1. Calculate visible card boundaries and update scrollbars.
 */
/*
 * Decompiled function: Duel_UpdateWindowScroll
 * Entry Point: 004eed47
 * Size: 263 bytes
 */

void Duel_UpdateWindowScroll(HWND hwnd)

{
  LONG LVar1;
  LONG LVar2;
  int loop_idx;
  tagRECT target_idx;
  HWND slot_idx;
  
  GetClientRect(hwnd,&target_idx);
  LVar1 = GetWindowLongA(hwnd,4);
  LVar2 = GetWindowLongA(hwnd,0);
  slot_idx = (HWND)GetWindowLongA(hwnd,0xc);
  for (loop_idx = 0; loop_idx < LVar1; loop_idx = loop_idx + 1) {
    SetWindowPos(*(HWND *)(LVar2 + loop_idx * 4),(HWND)0x0,0,0,g_PlayerGoldCoins,g_PlayerAmuletGems,6);
  }
  for (loop_idx = 0; loop_idx < LVar1; loop_idx = loop_idx + 1) {
    SendMessageA(hwnd,0x410,*(WPARAM *)(LVar2 + loop_idx * 4),0);
  }
  SetWindowPos(slot_idx,(HWND)0x0,0,0,g_PlayerGoldCoins,g_PlayerAmuletGems,6);
  SendMessageA(hwnd,0x410,(WPARAM)slot_idx,0);
  return;
}

/*
 * Duel_BringCardWindowToTop
 * Purpose: Bring selected card slot window to front of Z-order.
 * Procedure:
 * 1. Call BringWindowToTop on selected card control.
 */
/*
 * Decompiled function: Duel_BringCardWindowToTop
 * Entry Point: 004eee4e
 * Size: 529 bytes
 */

void Duel_BringCardWindowToTop(HWND hwnd)

{
  HWND hWnd;
  int status;
  int *arg4;
  int *arg5;
  UINT uCmd;
  int arg6;
  int local_358 [2];
  LONG local_350;
  int local_34c;
  int local_348;
  int local_344;
  int local_340;
  LONG local_33c;
  HWND local_338;
  WPARAM aWStack_334 [200];
  tagRECT player_idx;
  
  local_350 = GetWindowLongA(hwnd,4);
  local_33c = GetWindowLongA(hwnd,0);
  GetClientRect(hwnd,&player_idx);
  Duel_GetBattlefieldClientRect(hwnd);
  uCmd = 1;
  hWnd = GetWindow(hwnd,5);
  local_338 = GetWindow(hWnd,uCmd);
  local_34c = 0;
  for (; local_338 != (HWND)0x0; local_338 = GetWindow(local_338,3)) {
    status = FUN_0046bc92(local_338);
    if (status == 0) {
      aWStack_334[local_34c] = (WPARAM)local_338;
      local_34c = local_34c + 1;
    }
  }
  for (local_348 = 0; local_348 < local_34c; local_348 = local_348 + 1) {
    local_338 = (HWND)aWStack_334[local_348];
    status = FUN_0046bc92(local_338);
    if (status == 0) {
      SendMessageA(local_338,0x401,(WPARAM)local_358,0);
      arg6 = 1;
      arg5 = &local_344;
      arg4 = &local_340;
      status = FUN_0046ad4a(local_338);
      Duel_LayoutCardSlots(hwnd,local_358,status,arg4,arg5,arg6);
      SetWindowPos(local_338,(HWND)0x0,local_340,local_344,0,0,5);
      BringWindowToTop(local_338);
    }
  }
  for (local_348 = 0; local_348 < local_34c; local_348 = local_348 + 1) {
    local_338 = (HWND)aWStack_334[local_348];
    SendMessageA(hwnd,0x410,(WPARAM)local_338,0);
  }
  SendMessageA(hwnd,0x412,0,0);
  return;
}

/*
 * Duel_GetBattlefieldClientRect
 * Purpose: Retrieve client pixel bounds of active duel arena.
 * Procedure:
 * 1. Call GetClientRect on main arena HWND.
 */
/*
 * Decompiled function: Duel_GetBattlefieldClientRect
 * Entry Point: 004ef05f
 * Size: 252 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Duel_GetBattlefieldClientRect(HWND hwnd)

{
  uint32_t target_idx;
  tagRECT player_idx;
  
  target_idx = (uint32_t)(g_TurnPriorityState != hwnd);
  GetClientRect(hwnd,&player_idx);
  *(LONG *)(&DAT_006a3f68 + target_idx * 4) = (player_idx.right + -10) - g_PlayerGoldCoins;
  *(int *)(&DAT_006b2e80 + target_idx * 4) = 10;
  *(int *)(&DAT_006ff378 + target_idx * 4) = 10;
  *(LONG *)(&DAT_00695f00 + target_idx * 4) = (player_idx.bottom + -10) - g_PlayerAmuletGems;
  _DAT_006ff1a4 = 5;
  _DAT_006b3068 = 10;
  DAT_00695ed4 = 5;
  *(int *)(&DAT_006a29d0 + target_idx * 4) =
       (*(int *)(&DAT_006a3f68 + target_idx * 4) + -10) - g_PlayerGoldCoins;
  *(int *)(&DAT_006a49d8 + target_idx * 4) = 10;
  *(int *)(&DAT_006b2ff0 + target_idx * 4) = 5;
  *(int *)(&DAT_007006c0 + target_idx * 4) = g_PlayerAmuletGems / 2;
  return;
}

/*
 * Duel_LayoutCardSlots
 * Purpose: Position player and opponent cards across battlefield rows.
 * Procedure:
 * 1. Calculate card slot X/Y positions for hand, battlefield, and graveyard.
 * 2. Reposition child card windows via MoveWindow.
 */
/*
 * Decompiled function: Duel_LayoutCardSlots
 * Entry Point: 004ef15b
 * Size: 1264 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Duel_LayoutCardSlots(HWND hwnd,int *arg2,int arg3,int *arg4,int *arg5,int arg6)

{
  int status;
  uint32_t u_temp;
  uint32_t local_24;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  if ((((hwnd != (HWND)0x0) && (arg2 != (int *)0x0)) &&
      (status = Ai_Subsystem_004b5cbb(*arg2,arg2[1]), status != -1)) &&
     ((arg4 != (int *)0x0 && (arg5 != (int *)0x0)))) {
    local_24 = (uint32_t)(g_TurnPriorityState != hwnd);
    GetClientRect(hwnd,&player_idx);
    u_temp = Ai_Subsystem_004b613b(*arg2,arg2[1]);
    if (((u_temp & 2) == 0) || (u_temp = Ai_Subsystem_004b613b(*arg2,arg2[1]), (u_temp & 1) != 0)) {
      u_temp = Ai_Subsystem_004b613b(*arg2,arg2[1]);
      if ((u_temp & 1) == 0) {
        status = Ai_Subsystem_004b5cbb(*arg2,arg2[1]);
        if (status == DAT_00695e94) {
          target_idx = *(int *)(&DAT_006b2ff0 + local_24 * 4);
          color_idx = *(int *)(&DAT_007006c0 + local_24 * 4);
          if (arg6 != 0) {
            *(int *)(&DAT_007006c0 + local_24 * 4) =
                 *(int *)(&DAT_007006c0 + local_24 * 4) + DAT_006ff67c;
          }
        }
        else {
          color_idx = *(int *)(&DAT_006a49d8 + local_24 * 4);
          target_idx = *(int *)(&DAT_006a29d0 + local_24 * 4) + arg3;
          status = Duel_GetHoveredCardSlot(hwnd,arg2);
          if (0 < status) {
            color_idx = color_idx + DAT_006ff67c * status;
          }
          if (arg6 != 0) {
            if (status != 0) {
              *(int *)(&DAT_006a49d8 + local_24 * 4) =
                   *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c * status;
            }
            *(int *)(&DAT_006a49d8 + local_24 * 4) =
                 *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c;
            *(int *)(&DAT_006a49d8 + local_24 * 4) =
                 *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c / 2;
            if ((player_idx.bottom + -10) - g_PlayerAmuletGems < *(int *)(&DAT_006a49d8 + local_24 * 4)) {
              *(int *)(&DAT_006a49d8 + local_24 * 4) = g_PlayerAmuletGems / 2;
              *(int *)(&DAT_006a29d0 + local_24 * 4) =
                   *(int *)(&DAT_006a29d0 + local_24 * 4) - g_PlayerGoldCoins / 2;
            }
          }
        }
      }
      else {
        color_idx = *(int *)(&DAT_006b2e80 + local_24 * 4);
        target_idx = *(int *)(&DAT_006a3f68 + local_24 * 4) + arg3;
        status = Duel_GetHoveredCardSlot(hwnd,arg2);
        if (0 < status) {
          color_idx = color_idx + DAT_006ff67c * status + 5;
        }
        if (arg6 != 0) {
          if (status != 0) {
            *(int *)(&DAT_006b2e80 + local_24 * 4) =
                 *(int *)(&DAT_006b2e80 + local_24 * 4) + DAT_006ff67c * status + 5;
          }
          *(int *)(&DAT_006b2e80 + local_24 * 4) =
               *(int *)(&DAT_006b2e80 + local_24 * 4) + DAT_006ff67c;
          if ((player_idx.bottom + -5) - g_PlayerAmuletGems < *(int *)(&DAT_006b2e80 + local_24 * 4)) {
            *(int *)(&DAT_006b2e80 + local_24 * 4) = g_PlayerAmuletGems / 2;
            *(int *)(&DAT_006a3f68 + local_24 * 4) =
                 *(int *)(&DAT_006a3f68 + local_24 * 4) - g_PlayerGoldCoins / 2;
          }
        }
      }
    }
    else {
      target_idx = *(int *)(&DAT_006ff378 + local_24 * 4);
      color_idx = *(int *)(&DAT_00695f00 + local_24 * 4) - arg3 / 2;
      if (arg6 != 0) {
        *(int *)(&DAT_006ff378 + local_24 * 4) =
             *(int *)(&DAT_006ff378 + local_24 * 4) + g_PlayerGoldCoins + _DAT_006ff1a4;
        if (player_idx.right + g_PlayerGoldCoins * -2 < *(int *)(&DAT_006ff378 + local_24 * 4)) {
          DAT_0052fc94 = (DAT_0052fc94 + 1) % 3;
          if (DAT_0052fc94 == 0) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = 5;
          }
          else if (DAT_0052fc94 == 1) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = g_PlayerGoldCoins / 3;
          }
          else if (DAT_0052fc94 == 2) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = g_PlayerGoldCoins / 6;
          }
          else {
            *(int *)(&DAT_006ff378 + local_24 * 4) = g_PlayerGoldCoins / 2;
          }
          *(int *)(&DAT_00695f00 + local_24 * 4) =
               *(int *)(&DAT_00695f00 + local_24 * 4) - (g_PlayerAmuletGems + _DAT_006b3068);
        }
        if (*(int *)(&DAT_00695f00 + local_24 * 4) < 0) {
          DAT_00695ed4 = DAT_00695ed4 + (g_PlayerAmuletGems * 0x28) / 100;
          if ((player_idx.bottom + -10) - g_PlayerAmuletGems < DAT_00695ed4) {
            DAT_00695ed4 = 10;
          }
          *(LONG *)(&DAT_00695f00 + local_24 * 4) = (player_idx.bottom - DAT_00695ed4) - g_PlayerAmuletGems;
          if (DAT_0052fc94 == 0) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = 5;
          }
          else if (DAT_0052fc94 == 1) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = g_PlayerGoldCoins / 3;
          }
          else {
            *(int *)(&DAT_006ff378 + local_24 * 4) = g_PlayerGoldCoins / 6;
          }
          _DAT_006ff1a4 = _DAT_006ff1a4 + 10;
        }
      }
    }
  }
  *arg4 = target_idx;
  *arg5 = color_idx;
  return;
}

/*
 * Duel_ScrollLeftButton_Handler
 * Purpose: Scroll duel card battlefield left.
 * Procedure:
 * 1. Decrement horizontal scroll offset and refresh table.
 */
/*
 * Decompiled function: Duel_ScrollLeftButton_Handler
 * Entry Point: 004ef64b
 * Size: 245 bytes
 */

void Duel_ScrollLeftButton_Handler(HWND hwnd,HWND uMsg)

{
  int status;
  HWND pHVar2;
  int color_idx [2];
  LONG player_idx;
  LPARAM card_idx;
  int match_count;
  LONG slot_idx;
  
  player_idx = GetWindowLongA(hwnd,4);
  slot_idx = GetWindowLongA(hwnd,0);
  SendMessageA(param_2,0x401,(WPARAM)color_idx,0);
  status = FUN_00483139(g_AiDecisionMatrix_Row,color_idx,(int *)0x0,&card_idx,(int *)0x0);
  if (status != 0) {
    for (match_count = 0; match_count < player_idx; match_count = match_count + 1) {
      pHVar2 = (HWND)FUN_0046bc92(*(HWND *)(slot_idx + match_count * 4));
      if (pHVar2 == param_2) {
        SendMessageA(*(HWND *)(slot_idx + match_count * 4),0x401,(WPARAM)color_idx,0);
        SendMessageA(g_AiDecisionMatrix_Row,0x406,(WPARAM)color_idx,card_idx);
        Duel_ScrollLeftButton_Handler(hwnd,*(HWND *)(slot_idx + match_count * 4));
      }
    }
  }
  return;
}

/*
 * Duel_ScrollRightButton_Handler
 * Purpose: Scroll duel card battlefield right.
 * Procedure:
 * 1. Increment horizontal scroll offset and refresh table.
 */
/*
 * Decompiled function: Duel_ScrollRightButton_Handler
 * Entry Point: 004ef740
 * Size: 265 bytes
 */

void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM arg2,uint8_t arg3)

{
  int status;
  int color_idx;
  int target_idx;
  LONG player_idx;
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  player_idx = GetWindowLongA(hwnd,4);
  match_count = GetWindowLongA(hwnd,0);
  for (card_idx = 0; card_idx < player_idx; card_idx = card_idx + 1) {
    status = FUN_0046bc92(*(HWND *)(match_count + card_idx * 4));
    if (status == 0) {
      SendMessageA(*(HWND *)(match_count + card_idx * 4),0x401,(WPARAM)&color_idx,0);
      slot_idx = Ai_Subsystem_004b613b(color_idx,target_idx);
      if ((((((slot_idx & 1) != 0) && ((arg3 & 1) != 0)) ||
           (((slot_idx & 2) != 0 && ((arg3 & 2) != 0)))) ||
          (((slot_idx & 4) != 0 && ((arg3 & 4) != 0)))) ||
         (((slot_idx & 0x40) != 0 && ((arg3 & 8) != 0)))) {
        SendMessageA(hwnd,0x402,*(WPARAM *)(match_count + card_idx * 4),arg2);
      }
    }
  }
  return;
}

/*
 * Duel_HitTestCardSlot
 * Purpose: Perform mouse hit test against battlefield card slots.
 * Procedure:
 * 1. Translate mouse coordinates to card slot index.
 */
/*
 * Decompiled function: Duel_HitTestCardSlot
 * Entry Point: 004ef849
 * Size: 295 bytes
 */

int Duel_HitTestCardSlot(HWND hwnd,int *y,int *arg3,int *arg4)

{
  LONG LVar1;
  LONG LVar2;
  int temp_idx;
  int color_idx;
  int player_idx;
  int match_count;
  int slot_idx;
  
  if ((hwnd == (HWND)0x0) || (y == (int *)0x0)) {
    slot_idx = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = 0;
    player_idx = 0;
    while ((player_idx < LVar2 && (slot_idx == 0))) {
      temp_idx = FUN_0046bb29(*(HWND *)(LVar1 + player_idx * 4),y);
      if (temp_idx != 0) {
        slot_idx = 1;
        color_idx = FUN_0046bc2f(*(HWND *)(LVar1 + player_idx * 4));
        match_count = *(int *)(LVar1 + player_idx * 4);
      }
      player_idx = player_idx + 1;
    }
  }
  if (arg3 != (int *)0x0) {
    if (slot_idx == 0) {
      *arg3 = 0xffffffff;
    }
    else {
      *arg3 = color_idx;
    }
  }
  if (arg4 != (int *)0x0) {
    if (slot_idx == 0) {
      *arg4 = 0;
    }
    else {
      *arg4 = match_count;
    }
  }
  return slot_idx;
}

/*
 * Duel_GetHoveredCardSlot
 * Purpose: Query currently hovered card slot index.
 * Procedure:
 * 1. Return card slot under mouse cursor.
 */
/*
 * Decompiled function: Duel_GetHoveredCardSlot
 * Entry Point: 004ef970
 * Size: 171 bytes
 */

int Duel_GetHoveredCardSlot(HWND hwnd,int *arg2)

{
  LONG LVar1;
  LONG LVar2;
  int temp_idx;
  int uval_4;
  int card_idx;
  int slot_idx;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  slot_idx = 0;
  for (card_idx = 0; card_idx < LVar2; card_idx = card_idx + 1) {
    temp_idx = FUN_0046bb29(*(HWND *)(LVar1 + card_idx * 4),arg2);
    if (temp_idx != 0) {
      slot_idx = *(int *)(LVar1 + card_idx * 4);
    }
  }
  if (slot_idx == 0) {
    uval_4 = 0;
  }
  else {
    uval_4 = Duel_GetCardSlotWindowHandle(hwnd,slot_idx);
  }
  return uval_4;
}

/*
 * Duel_GetCardSlotWindowHandle
 * Purpose: Retrieve HWND for given battlefield card slot.
 * Procedure:
 * 1. Return child window handle for card slot.
 */
/*
 * Decompiled function: Duel_GetCardSlotWindowHandle
 * Entry Point: 004efa20
 * Size: 154 bytes
 */

int Duel_GetCardSlotWindowHandle(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int temp_idx;
  int card_idx;
  int match_count;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  card_idx = 0;
  for (match_count = 0; match_count < LVar2; match_count = match_count + 1) {
    temp_idx = FUN_0046bc92(*(HWND *)(LVar1 + match_count * 4));
    if (temp_idx == arg2) {
      temp_idx = Duel_GetCardSlotWindowHandle(hwnd,*(int *)(LVar1 + match_count * 4));
      card_idx = card_idx + 1 + temp_idx;
    }
  }
  return card_idx;
}

/*
 * Duel_GetTargetSlotWindowHandle
 * Purpose: Retrieve HWND for targeted card slot.
 * Procedure:
 * 1. Return window handle for target slot.
 */
/*
 * Decompiled function: Duel_GetTargetSlotWindowHandle
 * Entry Point: 004efaba
 * Size: 129 bytes
 */

int Duel_GetTargetSlotWindowHandle(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int temp_idx;
  int card_idx;
  int match_count;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  card_idx = 0;
  for (match_count = 0; match_count < LVar2; match_count = match_count + 1) {
    temp_idx = FUN_0046bc92(*(HWND *)(LVar1 + match_count * 4));
    if (temp_idx == arg2) {
      card_idx = card_idx + 1;
    }
  }
  return card_idx;
}

/*
 * Duel_PaintBattlefieldBackground
 * Purpose: Paint solid background fill for duel table.
 * Procedure:
 * 1. Fill client area with battlefield green brush.
 */
/*
 * Decompiled function: Duel_PaintBattlefieldBackground
 * Entry Point: 004efb3b
 * Size: 259 bytes
 */

HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint32_t arg2,HDC hdc)

{
  HBRUSH hbr;
  HGDIOBJ buf_ptr_1;
  tagRECT target_idx;
  HDC slot_idx;
  
  if (arg2 < 0x103) {
    if (arg2 == 0x102) {
switchD_004efc35_caseD_201:
      EndDialog(hwnd,1);
      return (HGDIOBJ)0x1;
    }
    if (arg2 == 0x14) {
      GetClientRect(hwnd,&target_idx);
      hbr = GetStockObject(4);
      FillRect(hdc,&target_idx,hbr);
      return (HGDIOBJ)0x1;
    }
switchD_004efc35_caseD_112:
    buf_ptr_1 = (HGDIOBJ)0x0;
  }
  else {
    switch(arg2) {
    case 0x110:
      buf_ptr_1 = (HGDIOBJ)0x1;
      break;
    case 0x111:
      EndDialog(hwnd,1);
      buf_ptr_1 = (HGDIOBJ)0x1;
      break;
    default:
      goto switchD_004efc35_caseD_112;
    case 0x138:
      slot_idx = hdc;
      SetTextColor(hdc,0xffffff);
      SetBkMode(slot_idx,1);
      buf_ptr_1 = GetStockObject(5);
      break;
    case 0x201:
      goto switchD_004efc35_caseD_201;
    }
  }
  return buf_ptr_1;
}

/*
 * Duel_LogActionStatusBanner
 * Purpose: Log and display action status banner (CASTING, ACTIVATING, PROCESSING).
 * Procedure:
 * 1. Format banner string with card name and action type.
 * 2. Display banner and refresh screen.
 */
/*
 * Decompiled function: Duel_LogActionStatusBanner
 * Entry Point: 004efd50
 * Size: 1932 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Duel_LogActionStatusBanner(int spell_id,int target_id,int flags,uint32_t arg4,uint32_t arg5,char *banner_text,
              int arg7)

{
  int arg2;
  int status;
  uint32_t u_temp;
  uint32_t local_210;
  int aiStack_200 [60];
  int local_110;
  int local_10c;
  int local_108;
  uint32_t local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int aiStack_f4 [60];
  
  if ((g_ActivePlayer == 1) || ((g_IsAiThinking == 1 && (spell_id == g_CurrentTurnPhase)))) {
    local_108 = -1;
  }
  else {
    if (((uint8_t)DAT_00680790 & 1) != 0) {
      flags = target_id;
    }
    if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
      if ((arg4 != 0) && (arg4 != 0xff)) {
        g_OverworldWorldState = 0;
        local_104 = FUN_00474d4a();
        if (local_104 != 0xffffffff) {
          status = *(int *)(&DAT_006fecb8 + g_AiEvaluatedMoveCount * 8);
          arg2 = *(int *)(&DAT_006fecbc + g_AiEvaluatedMoveCount * 8);
          u_temp = local_104 >> 0x10 & 0xff;
          if (u_temp == 0x71) {
            strcpy(&g_OverworldWorldState,s_CASTING__0052ffc8);
            Ai_Subsystem_004b90de(status,arg2);
          }
          if (u_temp == 0x72) {
            strcpy(&g_OverworldWorldState,s_ACTIVATING__0052ffd4);
            Ai_Subsystem_004b90de(status,arg2);
          }
          if (u_temp == 0x7e) {
            strcpy(&g_OverworldWorldState,s_PROCESSING__0052ffe4);
            Ai_Subsystem_004b90de(status,arg2);
          }
        }
        strcat(&g_OverworldWorldState,&DAT_0052fff4);
      }
      DAT_00627a88 = 0xffffffff;
      if (((arg4 == 0) || (arg4 == 0xff)) || (arg4 == 0xfffffffe)) {
        local_210 = 0xffffffff;
      }
      else {
        local_210 = arg4;
      }
      Ai_ScoreAttackerCombination
                (target_id,banner_text,arg7,local_210,arg5,0xffffffff,0xffffffff,&DAT_0063ee8c,
                 &local_10c,0,0);
      if (local_10c != -1) {
        DAT_00633434 = 0;
      }
      strcpy(&g_OverworldGoldAmount,&DAT_0052fff8);
      g_TemporaryToughnessBuffer = local_10c;
    }
    else {
      local_110 = 0;
      for (local_fc = 0; local_fc < 2; local_fc = local_fc + 1) {
        if ((flags == -1) || (local_fc == flags)) {
          for (local_100 = 0; local_100 < (int)(&g_PlayerActiveCardCount)[local_fc];
              local_100 = local_100 + 1) {
            if (((((arg4 != 0xfffffffe) &&
                  (*(int *)(&g_CardSlot_CardId + local_100 * 0x120 + local_fc * 0x5b20) != -1)) &&
                 ((((&g_CardSlot_Flags)[local_100 * 0x120 + local_fc * 0x5b20] & 2) != 0 ||
                  ((spell_id == g_CurrentTurnPhase && (g_AiTurnDecisionFlag != 0)))))) &&
                (((int)arg4 < 1 ||
                 ((arg4 & (uint8_t)(&g_MasterCardColorTable)
                                 [*(int *)(&g_CardSlot_CardId +
                                          local_100 * 0x120 + local_fc * 0x5b20) * 0x34]) != 0))))
               && (((arg5 == 1 || (arg5 == 0)) ||
                   ((arg5 & (int)(char)(&g_CardSlot_PlusOneCounters)[local_100 * 0x120 + local_fc * 0x5b20]) != 0
                   )))) {
              aiStack_f4[local_110] = local_fc;
              aiStack_200[local_110] = local_100;
              local_110 = local_110 + 1;
            }
          }
          if (((int)arg4 < 1) && ((arg5 == 1 || (arg5 == 0)))) {
            aiStack_f4[local_110] = local_fc;
            aiStack_200[local_110] = -1;
            local_110 = local_110 + 1;
          }
        }
      }
      if (local_110 == 0) {
        local_108 = -1;
      }
      else if (spell_id == g_CurrentTurnPhase) {
        do {
          while( true ) {
            do {
              do {
                local_110 = Util_GetRandomNumber(local_110);
                g_TemporaryToughnessBuffer = aiStack_f4[local_110];
                if (g_AiTurnDecisionFlag == 0) goto LAB_004f024d;
                DAT_0063ee8c = 0;
                status = Util_GetRandomNumber(0x20);
                if ((status == 0) || (DAT_0063ee10 != 0)) {
                  DAT_00627a84 = 0xffffffff;
                  DAT_00627a88 = 0xffffffff;
                  DAT_0063ee8c = 0xfffffffe;
                  return -1;
                }
              } while (g_CurrentTurnPhase != g_TemporaryToughnessBuffer);
              local_f8 = *(int *)(&g_CardSlot_CardId +
                                 g_TemporaryToughnessBuffer * 0x5b20 + aiStack_200[local_110] * 0x120);
            } while (((((&g_MasterCardColorTable)[local_f8 * 0x34] & 1) != 0) &&
                     (((&g_CardSlot_Flags)[g_TemporaryToughnessBuffer * 0x5b20 + aiStack_200[local_110] * 0x120]
                      & 2) != 0)) ||
                    ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 2) != 0 &&
                     (((&g_CardSlot_Flags)[g_TemporaryToughnessBuffer * 0x5b20 + aiStack_200[local_110] * 0x120]
                      & 4) != 0))));
            if ((g_ScWillyScore < 0x15) || (0x1d < g_ScWillyScore)) break;
            if ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 2) != 0) &&
               (((&g_CardSlot_Flags)[g_TemporaryToughnessBuffer * 0x5b20 + aiStack_200[local_110] * 0x120] & 2)
                != 0)) goto LAB_004f024d;
          }
        } while ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 0x4b) == 0) ||
                (((&g_CardSlot_Flags)[g_TemporaryToughnessBuffer * 0x5b20 + aiStack_200[local_110] * 0x120] & 2)
                 != 0));
LAB_004f024d:
        local_108 = aiStack_200[local_110];
      }
      else {
        if (g_IsAiThinking == 1) {
          g_AiChoiceValue = Util_GetRandomNumber(local_110);
          g_AiCurrentSearchPath = CONCAT31((int3)((aiStack_f4[g_AiChoiceValue] == 0) - 1 >> 8),
                                  (char)aiStack_200[g_AiChoiceValue]) & 0x1ff | 0x4000;
          Ai_RecordChoice();
        }
        else {
          Ai_ReplayChoice();
          if (g_AiChoiceValue == 99) {
            g_AiChoiceValue = Util_GetRandomNumber(local_110);
          }
        }
        g_TemporaryToughnessBuffer = aiStack_f4[g_AiChoiceValue];
        local_108 = aiStack_200[g_AiChoiceValue];
      }
    }
  }
  return local_108;
}

/*
 * Duel_RegisterChildCardWindowClass
 * Purpose: Register window class for individual interactive card controls.
 * Procedure:
 * 1. Register MAGICGAME_CardClass window class.
 * 2. Load card cursor and background brush.
 */
/*
 * Decompiled function: Duel_RegisterChildCardWindowClass
 * Entry Point: 004f04e0
 * Size: 183 bytes
 */

bool Duel_RegisterChildCardWindowClass(LPCSTR name_or_path)

{
  ATOM atom_res;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = Duel_ChildCard_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = name_or_path;
  atom_res = RegisterClassA(&local_2c);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_0052fffc,0);
  DAT_00565a04 = CreateFontIndirectA(lplf);
  DAT_00565a00 = 0x2565656;
  return atom_res != 0;
}

/*
 * Duel_UnregisterCardWindowClass
 * Purpose: Clean up card control window class resources.
 * Procedure:
 * 1. Delete card background brush and unregister class.
 */
/*
 * Decompiled function: Duel_UnregisterCardWindowClass
 * Entry Point: 004f0597
 * Size: 46 bytes
 */

void Duel_UnregisterCardWindowClass(void)

{
  if (DAT_00565a04 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565a04);
  }
  DAT_00565a04 = (HGDIOBJ)0x0;
  return;
}

/*
 * Duel_ChildCard_WndProc
 * Purpose: Window procedure for individual battlefield card control.
 * Procedure:
 * 1. Handle WM_PAINT to render card illustration and stats.
 * 2. Handle WM_LBUTTONDOWN for card selection and tapping.
 * 3. Handle mouse drag and hover highlights.
 */
/*
 * Decompiled function: Duel_ChildCard_WndProc
 * Entry Point: 004f05c5
 * Size: 1007 bytes
 */

LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam)

{
  LONG LVar1;
  LRESULT LVar2;
  CHAR local_2d8 [500];
  CHAR local_e4 [100];
  HDC local_80;
  tagPAINTSTRUCT local_7c;
  tagRECT local_3c;
  tagRECT local_2c;
  tagRECT color_idx;
  HGDIOBJ match_count;
  WPARAM slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_80 = BeginPaint(hwnd,&local_7c);
      if (local_80 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_80);
        SetTextColor(local_80,DAT_00565a00);
        SetBkMode(local_80,1);
        SelectObject(local_80,match_count);
        GetWindowTextA(hwnd,local_e4,100);
        GetClientRect(hwnd,&local_3c);
        local_3c.left = local_3c.left + 10;
        SetMapMode(local_80,8);
        SetWindowExtEx(local_80,local_3c.right - local_3c.left,0x14,(LPSIZE)0x0);
        SetViewportExtEx(local_80,local_3c.right - local_3c.left,local_3c.bottom - local_3c.top,
                         (LPSIZE)0x0);
        DrawTextA(local_80,local_e4,-1,&local_3c,8);
        EndPaint(hwnd,&local_7c);
      }
      return 0;
    }
    if (uMsg == 1) {
      match_count = (HGDIOBJ)DAT_00565a04;
      SetWindowLongA(hwnd,0,DAT_00565a04);
      GetWindowRect(hwnd,&local_2c);
      slot_idx = local_2c.right - local_2c.left;
      SetWindowLongA(hwnd,4,slot_idx);
      return 0;
    }
  }
  else if (uMsg < 0x19) {
    if (uMsg == 0x18) {
      if (wParam != 0) {
        SetTimer(hwnd,1,10000,(TIMERPROC)0x0);
      }
      LVar2 = DefWindowProcA(hwnd,0x18,wParam,lParam);
      return LVar2;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
  }
  else if (uMsg < 0x114) {
    if (uMsg == 0x113) {
      KillTimer(hwnd,1);
      ShowWindow(hwnd,0);
      return 0;
    }
    if (uMsg == 0x30) {
      match_count = (HGDIOBJ)wParam;
      if (wParam == 0) {
        match_count = (HGDIOBJ)DAT_00565a04;
      }
      SetWindowLongA(hwnd,0,(LONG)match_count);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      GetWindowTextA(hwnd,local_2d8,500);
      SetWindowTextA(hwnd,local_2d8);
      return 0;
    }
    if (uMsg == 0x31) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar2 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar2;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x113,1,0);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      LVar1 = GetWindowLongA(hwnd,4);
      return LVar1;
    }
    if (uMsg == 0x401) {
      slot_idx = wParam;
      SetWindowLongA(hwnd,4,wParam);
      GetWindowRect(hwnd,&color_idx);
      if (color_idx.right - color_idx.left < (int)slot_idx) {
        SetWindowPos(hwnd,(HWND)0x0,0,0,slot_idx,color_idx.bottom - color_idx.top,6);
      }
      return 0;
    }
  }
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar2;
}

/*
 * Duel_GetCardDrawOriginX
 * Purpose: Compute screen X coordinate for card draw animation.
 * Procedure:
 * 1. Calculate source library screen X position.
 */
/*
 * Decompiled function: Duel_GetCardDrawOriginX
 * Entry Point: 004f09c0
 * Size: 138 bytes
 */

int Duel_GetCardDrawOriginX(int arg1,int arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (0x7f < slot_idx) {
      return -1;
    }
    if (((*(int *)(&g_CardSlot_CreatureType + slot_idx * 100) != -1) &&
        (*(int *)(&g_DungeonMapTileX + slot_idx * 100) == arg1)) &&
       (*(int *)(&g_DungeonMapTileY + slot_idx * 100) == arg2)) break;
    slot_idx = slot_idx + 1;
  }
  return slot_idx;
}

/*
 * Duel_GetCardDrawOriginY
 * Purpose: Compute screen Y coordinate for card draw animation.
 * Procedure:
 * 1. Calculate source library screen Y position.
 */
/*
 * Decompiled function: Duel_GetCardDrawOriginY
 * Entry Point: 004f0a4a
 * Size: 172 bytes
 */

int Duel_GetCardDrawOriginY(int arg1,int arg2)

{
  int status;
  int player_idx;
  int card_idx;
  int match_count;
  
  card_idx = -1;
  player_idx = 0x7fff;
  for (match_count = 0; match_count < 0x80; match_count = match_count + 1) {
    if ((*(int *)(&g_CardSlot_CreatureType + match_count * 100) != -1) &&
       (status = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + match_count * 100) - arg1,
                             *(int *)(&g_DungeonMapTileY + match_count * 100) - arg2), status < player_idx)) {
      card_idx = match_count;
      player_idx = status;
    }
  }
  return card_idx;
}

/*
 * Duel_TriggerCardDrawAnimation
 * Purpose: Launch visual card draw motion interpolation.
 * Procedure:
 * 1. Initialize motion trajectory from library to hand.
 */
/*
 * Decompiled function: Duel_TriggerCardDrawAnimation
 * Entry Point: 004f0af6
 * Size: 90 bytes
 */

void Duel_TriggerCardDrawAnimation(void)

{
  int status;
  uint32_t slot_idx;
  
  for (slot_idx = 0; (int)slot_idx < g_MasterCardCount; slot_idx = slot_idx + 1) {
    while( true ) {
      status = Duel_UpdateCardMotionStep(slot_idx);
      if (-1 < status) break;
      *(uint32_t *)(&deck + DAT_00565a08 * 4) = *(uint32_t *)(&deck + DAT_00565a08 * 4) | 0x4000;
    }
  }
  return;
}

/*
 * Duel_UpdateCardMotionStep
 * Purpose: Advance card motion frame step during draw/cast animations.
 * Procedure:
 * 1. Interpolate card position and redraw moving card.
 */
/*
 * Decompiled function: Duel_UpdateCardMotionStep
 * Entry Point: 004f0b50
 * Size: 576 bytes
 */

int Duel_UpdateCardMotionStep(uint32_t arg1)

{
  int status;
  int local_30;
  int local_2c;
  int local_28;
  uint32_t local_24;
  int aiStack_20 [7];
  
  if ((int)arg1 < 5) {
    local_30 = 99;
  }
  else {
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      aiStack_20[local_28] = 0;
    }
    local_2c = 0;
    local_30 = 0;
    for (local_28 = 0; local_28 < 500; local_28 = local_28 + 1) {
      if ((*(int *)(&deck + local_28 * 4) != -1) && (((&DAT_00702151)[local_28 * 4] & 0x40) == 0)) {
        local_2c = local_2c + 1;
        status = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[(*(uint32_t *)(&deck + local_28 * 4) & 0xfff) * 0x34]);
        aiStack_20[status] = aiStack_20[status] + 1;
      }
      if ((*(uint32_t *)(&deck + local_28 * 4) & 0xffff7fff) == arg1) {
        local_30 = local_30 + 1;
        DAT_00565a08 = local_28;
      }
    }
    local_24 = -1;
    for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
      if ((int)local_24 < aiStack_20[local_28]) {
        local_24 = aiStack_20[local_28];
      }
    }
    DAT_0052f000 = 0;
    for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
      if ((int)(local_24 * 2) / 3 <= aiStack_20[local_28]) {
        DAT_0052f000 = DAT_0052f000 | 1 << ((uint8_t)local_28 & 0x1f);
      }
    }
    local_24 = 1;
    if (0x27 < local_2c) {
      local_24 = 2;
    }
    if (0x3b < local_2c) {
      local_24 = 3;
    }
    if ((g_OverworldMovementFlags & 0x20) != 0) {
      local_24 = local_24 + 1;
    }
    if (((&g_MasterCardFlagsTable)[arg1 * 0x34] & 1) == 0) {
      if (((&DAT_0051aed6)[arg1 * 0x34] & 0xc1) == 0) {
        local_24 = local_24 / 2;
      }
    }
    else {
      local_24 = (uint32_t)(g_CampaignDifficultyLevel <= (int)local_24);
    }
    local_30 = local_24 - local_30;
  }
  return local_30;
}

/*
 * Duel_ResetCardAnimationState
 * Purpose: Reset active animation registers.
 * Procedure:
 * 1. Clear card animation timers and flags.
 */
/*
 * Decompiled function: Duel_ResetCardAnimationState
 * Entry Point: 004f0d90
 * Size: 88 bytes
 */

void Duel_ResetCardAnimationState(char arg1,char arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (999 < slot_idx) {
      return;
    }
    if ((&DAT_0067b9b0)[slot_idx] == '\0') break;
    slot_idx = slot_idx + 1;
  }
  (&DAT_0067b9b0)[slot_idx] = arg2 * '\x10' + arg1;
  return;
}

