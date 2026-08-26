/*
 * Decompiled function: Pic_Load_004420a1
 * Entry Point: 004420a1
 * Size: 6620 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Load_004420a1(HWND hwnd,uint y,void *arg_3,int *height)

{
  POINT Point;
  DWORD _Seed;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  HDC *arg_3_00;
  BITMAPINFO *arg_4;
  HGDIOBJ *arg_5;
  undefined4 *arg_6;
  int *arg_7;
  int local_630;
  char local_62c [264];
  char local_524 [500];
  char local_330 [52];
  int local_2fc;
  undefined4 local_2f8;
  int local_2f4;
  int local_2f0;
  uint local_2ec;
  DWORD local_2e8;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  char local_2d4 [260];
  char local_1d0 [260];
  WPARAM local_cc;
  int local_c8;
  int local_c4;
  char local_c0 [100];
  int local_5c;
  void *local_58;
  int *local_54;
  int local_50;
  int local_4c;
  tagPOINT local_48;
  uint local_40;
  HWND local_3c;
  void *local_38;
  tagMSG local_34;
  DWORD local_18;
  int *local_14;
  BOOL local_10;
  uint local_c;
  int local_8;
  
  if (y < 0x11) {
    if (y == 0x10) {
      DAT_0067f3c4 = 1;
      g_PlayerCreatureCount = 0;
      return 0;
    }
    if (y == 1) {
      DAT_006fe484 = (HANDLE)0x0;
      iVar2 = Pic_Clip_00443b63(hwnd);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      PostMessageA(hwnd,0x400,0,0);
      DAT_006a49e4 = CreateWindowExA(0,s_MAGIC_PaletteClass_00521b20,s_Palette_00521b18,0x80cc0000,
                                     0x14,0x14,300,0x15e,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0)
      ;
      DAT_006fdbd4 = (void *)0x14;
      DAT_006ff1a8 = (HWND)0x0;
      return 0;
    }
    if (y == 2) {
      strcpy(local_62c,&DAT_006807a0);
      strcat(local_62c,s__duel_hlp_00521b34);
      WinHelpA(g_MainAppHwnd,local_62c,2,0);
      KillTimer(hwnd,(UINT_PTR)DAT_006fdbd4);
      return 0;
    }
    if (y == 5) {
      if ((arg_3 == (void *)0x0) && (DAT_005219d4 == 0)) {
        LockWindowUpdate(hwnd);
        Pic_Subsystem_004441cc(hwnd,DAT_006fe444);
        Duel_BringCardWindowToTop(DAT_006a4924);
        Duel_BringCardWindowToTop(DAT_006b2e2c);
        LockWindowUpdate((HWND)0x0);
      }
      if (arg_3 == (void *)0x1) {
        DAT_005219d4 = 1;
      }
      else if (arg_3 == (void *)0x0) {
        DAT_005219d4 = 0;
      }
      if ((arg_3 == (void *)0x1) && (_hwndScreen != (HWND)0x0)) {
        ShowWindow(_hwndScreen,5);
      }
      return 0;
    }
  }
  else if (y < 0x7f) {
    if (y == 0x7e) {
      if (DAT_006ff554 != arg_3) {
        for (local_630 = 0; local_630 < DAT_006a49f4; local_630 = local_630 + 1) {
          FUN_0046c1b3(local_630);
        }
        for (local_630 = 0; local_630 < DAT_00680778; local_630 = local_630 + 1) {
          FUN_004788e0((&DAT_006fefc0)[local_630 * 6],(&DAT_006fefc4)[local_630 * 6]);
        }
        DAT_00680778 = 0;
      }
      DAT_006ff554 = arg_3;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      FUN_004f3b2c(g_HdcBackBuffer,DAT_006ff384);
      arg_7 = &DAT_006b2e1c;
      arg_6 = (undefined4 *)&DAT_007006dc;
      arg_5 = &DAT_006ff384;
      arg_4 = (BITMAPINFO *)&DAT_006a4a20;
      arg_3_00 = &g_HdcBackBuffer;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      iVar2 = FUN_004f39a4(iVar3,iVar2,arg_3_00,arg_4,arg_5,arg_6,arg_7);
      if (iVar2 == 0) {
        MessageBoxA(hwnd,s_Not_enough_system_memory_to_run_a_00521b58,
                    s_Magic__The_Gathering_00521b40,0x30);
        ShowWindow(hwnd,0);
      }
      else {
        ShowWindow(hwnd,5);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      BVar4 = IsIconic(hwnd);
      if (BVar4 == 0) {
        MoveWindow(hwnd,1,0,((uint)height & 0xffff) - 1,(uint)height >> 0x10,1);
      }
      else {
        DAT_005219d0 = 1;
      }
      return 0;
    }
    if (y == 0x13) {
      if (DAT_005219d0 != 0) {
        PostMessageA(hwnd,0x501,0,0);
      }
      if (_hwndScreen != (HWND)0x0) {
        ShowWindow(_hwndScreen,5);
      }
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uVar5 = FUN_004f5d1a(hwnd,y,arg_3,height);
      return uVar5;
    }
    if (y == 0x111) {
      switch((uint)arg_3 & 0xffff) {
      case 599:
        DAT_0068a718 = (uint)(DAT_0068a718 == 0);
        if (DAT_006b2d38 == 0) {
          DAT_0068a718 = 0;
        }
        break;
      case 0x25c:
        if (DAT_0068a718 != 0) {
          DAT_00695e90 = (uint)(DAT_00695e90 == 0);
          Pic_Subsystem_0044cfe4(DAT_006fe400);
        }
        break;
      case 0x25d:
        if (DAT_0068a718 != 0) {
          FUN_0040a16e(DAT_0052eff8);
        }
        break;
      case 0x25e:
        if (DAT_0068a718 != 0) {
          Mem_AllocOrFree_0040a1a3(DAT_0052eff8);
        }
        break;
      case 0x263:
        if (DAT_0068a718 != 0) {
          g_PlayerCreatureCount = 0;
          DAT_006a4a04 = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x267:
      case 0x268:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) == 0x267);
          (&g_PlayerCreatureCount)[local_2ec] = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x269:
      case 0x26a:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x269);
          FUN_0046f5d1(local_2ec);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26b:
      case 0x26c:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26b);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_play_00521a60,-1,-1);
          local_2f8 = *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98)
          ;
          *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
               *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) & 0xfffe;
          local_2f4 = Pic_Subsystem_00451291(local_2ec,local_2f0);
          if (local_2f4 != -1) {
            Pic_Subsystem_0042ac1f(local_2ec,local_2f4);
          }
          *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) = local_2f8
          ;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26d:
      case 0x26e:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26d);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_hand_00521a80,-1,-1);
          local_2f4 = Pic_Subsystem_00451291(local_2ec,local_2f0);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26f:
      case 0x270:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26f);
          uVar1 = Ai_Subsystem_004b1b38
                            (0,s_Set_player_lives_to__00521aa0 + ((local_2ec == 0) - 1 & 0x18),
                             (&g_PlayerCreatureCount)[local_2ec]);
          (&g_PlayerCreatureCount)[local_2ec] = uVar1;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x271:
        if (DAT_0068a718 != 0) {
          ShowWindow(DAT_006a49e4,5);
        }
        break;
      case 0x272:
        if (DAT_0068a718 != 0) {
          DAT_006808c4 = (uint)(DAT_006808c4 == 0);
          SendMessageA(DAT_006a4924,0x435,0,0);
          SendMessageA(DAT_006b2e2c,0x435,0,0);
          SendMessageA(DAT_0069e720,0x435,0,0);
          SendMessageA(DAT_006fe400,0x435,0,0);
          InvalidateRect(DAT_006fe48c,(RECT *)0x0,1);
          InvalidateRect(DAT_006ff388,(RECT *)0x0,1);
        }
        break;
      case 0x273:
        if (DAT_0068a718 != 0) {
          DAT_00695ea4 = (uint)(DAT_00695ea4 == 0);
          SendMessageA(DAT_006a4924,0x435,0,0);
          SendMessageA(DAT_006b2e2c,0x435,0,0);
          SendMessageA(DAT_0069e720,0x435,0,0);
          SendMessageA(DAT_006fe400,0x435,0,0);
          InvalidateRect(DAT_0069f744,(RECT *)0x0,0);
        }
        break;
      case 0x274:
        if (DAT_0068a718 != 0) {
          DAT_006fedc0 = 0;
        }
        break;
      case 0x275:
        if (DAT_0068a718 != 0) {
          sprintf(local_524,s__d_big_arts_are_in__max_is__d__00521ad0,DAT_00680778,0x14);
          for (local_2fc = 0; local_2fc < DAT_00680778; local_2fc = local_2fc + 1) {
            sprintf(local_330,s__3d__d___dx_d_00521af0,(&DAT_006fefc0)[local_2fc * 6],
                    (&DAT_006fefc4)[local_2fc * 6],*(undefined4 *)(&DAT_006fefb8 + local_2fc * 0x18)
                    ,*(undefined4 *)(&DAT_006fefbc + local_2fc * 0x18));
            strcat(local_524,local_330);
          }
          MessageBoxA(hwnd,local_524,s_These_big_arts_are_in__00521b00,0);
        }
        break;
      case 0x276:
        if (DAT_0068a718 != 0) {
          if (DAT_0068a674 == 0) {
            DAT_0068a674 = 1;
          }
          else {
            DAT_0068a674 = 0;
          }
        }
        break;
      case 0x277:
        if (DAT_0068a718 != 0) {
          BVar4 = IsWindowVisible(DAT_0064a0bc);
          ShowWindow(DAT_0064a0bc,-(uint)(BVar4 == 0) & 5);
        }
        break;
      case 0x279:
        DAT_006fe438 = (uint)(DAT_006fe438 == 0);
        SendMessageA(DAT_006a4924,0x435,0,0);
        SendMessageA(DAT_006b2e2c,0x435,0,0);
        SendMessageA(DAT_006b3064,0x435,0,0);
        SendMessageA(DAT_006fe3fc,0x435,0,0);
        break;
      case 0x27a:
        DAT_006fe43c = (uint)(DAT_006fe43c == 0);
        Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        break;
      case 0x27b:
        _DAT_006a2864 = g_MainAppHwnd;
        _DAT_006a2890 = s_Save_Game_00521a54;
        _DAT_006a2894 = 0x2a000c;
        BVar4 = GetSaveFileNameA((LPOPENFILENAMEA)&DAT_006a2860);
        if (BVar4 != 0) {
          Pic_Subsystem_0044ef03(DAT_006a287c);
        }
        break;
      case 0x27c:
        DAT_006fe440 = (uint)(DAT_006fe440 == 0);
        SendMessageA(DAT_006a4924,0x435,0,0);
        SendMessageA(DAT_006b2e2c,0x435,0,0);
        SendMessageA(DAT_006b3064,0x435,0,0);
        SendMessageA(DAT_006fe3fc,0x435,0,0);
      }
      return 0;
    }
    if (y == 0x113) {
      if (((DAT_006fdbd4 == arg_3) && (DAT_006b1578 == 0)) && (DAT_006ff1a8 == (HWND)0x0)) {
        Pic_Subsystem_0044559e();
      }
      return 0;
    }
  }
  else if (y < 0x435) {
    if (0x432 < y) {
      return 0;
    }
    if (y == 0x400) {
      DAT_0067f3c4 = 0;
      if (DAT_006fe444 == 2) {
        ShowWindow(DAT_0069f744,0);
      }
      else {
        SendMessageA(DAT_0069f744,0x401,0xffffffff,0);
      }
      SendMessageA(DAT_0069e720,0x40c,0,0);
      SendMessageA(DAT_006fe400,0x40c,0,0);
      SendMessageA(DAT_006a4924,0x40c,0,0);
      SendMessageA(DAT_006b2e2c,0x40c,0,0);
      DAT_006808ac = 0xffffffff;
      DAT_006a2834 = 0xffffffff;
      DAT_006a48e0 = 0;
      DAT_0068a678 = 0xffffffff;
      SendMessageA(DAT_006a284c,0x432,0,0);
      ShowWindow(DAT_006a284c,5);
      ShowWindow(DAT_006a283c,0);
      DAT_006ff194 = 0;
      DAT_006a3f7c = 0;
      DAT_007006d8 = 0;
      DAT_00695ed8 = 0;
      SendMessageA(DAT_006b2530,0x432,0,0);
      SendMessageA(DAT_006ff4a8,0x432,0,0);
      for (local_c8 = 0; local_c8 < 7; local_c8 = local_c8 + 1) {
        *(undefined4 *)(&DAT_00695ee0 + local_c8 * 4) = 0;
        *(undefined4 *)(&DAT_0069f6e0 + local_c8 * 4) =
             *(undefined4 *)(&DAT_00695ee0 + local_c8 * 4);
      }
      SendMessageA(DAT_006b2d60,0x432,0,0);
      SendMessageA(DAT_006ff560,0x432,0,0);
      DAT_006b2e20 = 1;
      DAT_006b2d30 = 1;
      SendMessageA(DAT_006fe48c,0x432,0,0);
      SendMessageA(DAT_006ff388,0x432,0,0);
      DAT_007006b4 = 0;
      DAT_006ff1a0 = 0;
      DAT_006b2d34 = 0;
      DAT_006ff2e4 = 0;
      SendMessageA(DAT_006b2e10,0x432,0,0);
      SendMessageA(DAT_006a4928,0x432,0,0);
      SendMessageA(DAT_006b3064,0x40c,0,0);
      DAT_006b2e28 = 0;
      DAT_006fecc0 = 0xffffffff;
      SendMessageA(DAT_006fe3fc,0x40c,0,0);
      DAT_006b1578 = 0;
      ShowWindow(DAT_006a49f0,0);
      ShowWindow(DAT_0068a620,0);
      UpdateWindow(hwnd);
      SetFocus(hwnd);
      _Seed = GetTickCount();
      srand(_Seed);
      if (g_IsAiThinking == -10) {
        FUN_0048e1bf(DAT_006a287c);
        DAT_0052effc = 0;
        DAT_0052eff8 = 1;
      }
      else if (((byte)DAT_006fe410 & 4) == 0) {
        if (((byte)DAT_006fe410 & 1) != 0) {
          DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
          DAT_006a3f60 = FUN_004f3579(DAT_0052effc);
        }
      }
      else {
        DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
        DAT_006a3f60 = FUN_004f3579(DAT_0052effc);
      }
      if (((byte)DAT_006fe410 & 0x10) == 0) {
        if (((byte)DAT_006fe410 & 1) == 0) {
          if (DAT_006a49e8 == -1) {
            sprintf(local_2d4,s__s__03d_pic_00521a3c,&DAT_006a4a50,_OpponFace);
          }
          else {
            sprintf(local_2d4,s__s__03d_pic_00521a30,&DAT_006a4a50,DAT_006a49e8);
          }
          local_cc = Pic_Load_00423833(local_2d4);
          SendMessageA(DAT_006a49f0,0x439,local_cc,0);
          sprintf(local_2d4,s__s__03d_pic_00521a48,&DAT_006a4a50,_PlayerFace);
          local_cc = Pic_Load_00423833(local_2d4);
          SendMessageA(DAT_0068a620,0x439,local_cc,0);
        }
        else {
          if (DAT_006a49e8 == -1) {
            local_cc = 0;
          }
          else {
            sprintf(local_1d0,s__s__03d_pic_00521a24,&DAT_006a4a50,DAT_006a49e8);
            local_cc = Pic_Load_00423833(local_1d0);
          }
          SendMessageA(DAT_006a49f0,0x439,local_cc,0);
          local_cc = DAT_0067bdd8;
          SendMessageA(DAT_0068a620,0x439,DAT_0067bdd8,1);
        }
      }
      else {
        SendMessageA(DAT_006a49f0,0x439,0,0);
        SendMessageA(DAT_0068a620,0x439,0,0);
      }
      if (((byte)DAT_006fe410 & 0x10) == 0) {
        if (DAT_0068a648 == 0) {
          local_2dc = DAT_006fe490;
          local_2e4 = rand();
          local_2e4 = local_2e4 % 3;
          if (DAT_006fe448 == -1) {
            local_2e0 = DAT_006a3f60;
          }
          else {
            local_2e0 = DAT_006fe448;
          }
          local_2d8 = DAT_006fe44c;
          if ((local_2e0 == local_2dc) && (DAT_006fe44c == local_2e4)) {
            local_2e4 = (local_2e4 + 1) % 3;
          }
          DAT_006a4930 = local_2e4;
        }
        else {
          local_2dc = DAT_006fe490;
          local_2e4 = DAT_006a4930;
          if (DAT_006fe448 == -1) {
            local_2e0 = DAT_006a3f60;
          }
          else {
            local_2e0 = DAT_006fe448;
          }
          local_2d8 = DAT_006fe44c;
        }
      }
      else {
        local_2e0 = 1;
        local_2dc = 1;
        local_2d8 = 2;
        local_2e4 = 2;
      }
      Pic_Load_004450c3(1,local_2dc,local_2e4);
      Pic_Load_004450c3(0,local_2e0,local_2d8);
      BVar4 = IsWindowVisible(hwnd);
      if (BVar4 == 0) {
        ShowWindow(hwnd,5);
        SetForegroundWindow(hwnd);
        UpdateWindow(hwnd);
        ShowWindow(DAT_0069e720,5);
        ShowWindow(DAT_006fe400,5);
      }
      if (((byte)DAT_006fe410 & 0x10) == 0) {
        DAT_006fe484 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,Pic_Subsystem_00443b0c,(LPVOID)0x0,
                                    0,&local_2e8);
        SetThreadPriority(DAT_006fe484,0);
      }
      else {
        DAT_006fe484 = (HANDLE)0x0;
        PostMessageA(hwnd,0x401,0,0);
      }
      return 0;
    }
    if (y == 0x401) {
      local_58 = arg_3;
      local_5c = 1;
      if (DAT_006fe484 != (HANDLE)0x0) {
        WaitForSingleObject(DAT_006fe484,0xffffffff);
        CloseHandle(DAT_006fe484);
        DAT_006fe484 = (HANDLE)0x0;
      }
      if (((byte)DAT_006fe410 & 1) == 0) {
        if (((byte)DAT_006fe410 & 2) != 0) {
          local_c4 = 1;
          if (local_58 == (void *)0x1) {
            strcpy(local_c0,s_Congratulations__005219d8);
          }
          else if (local_58 == (void *)0x0) {
            strcpy(local_c0,s_Too_bad_005219ec);
          }
          else if (local_58 == (void *)0xffffffff) {
            strcpy(local_c0,s_Oh_well____005219f4);
          }
          else {
            local_c4 = 0;
          }
          if (local_c4 != 0) {
            strcat(local_c0,s_Want_to_play_again__00521a00);
            iVar2 = MessageBoxA(hwnd,local_c0,s_End_of_duel_00521a18,4);
            if (iVar2 == 6) {
              local_5c = 0;
              SendMessageA(hwnd,0x400,0,0);
            }
          }
        }
      }
      else if (DAT_006fe434 != 0) {
        Ai_Subsystem_004ae779((int)local_58);
      }
      if (local_5c != 0) {
        DestroyWindow(hwnd);
        DAT_00627a80 = local_58;
        PostQuitMessage((int)local_58);
      }
      return 0;
    }
    if (y == 0x403) {
      if (DAT_006ff1a8 != (HWND)0x0) {
        SendMessageA(DAT_006ff1a8,0x10,0,0);
      }
      KillTimer(hwnd,(UINT_PTR)DAT_006fdbd4);
      local_38 = arg_3;
      local_14 = height;
      DAT_006b1578 = 1;
      memcpy(&DAT_006feec0,arg_3,0xe8);
      GetCursorPos(&local_48);
      Point.y = local_48.y;
      Point.x = local_48.x;
      local_3c = WindowFromPoint(Point);
      local_40 = SendMessageA(local_3c,0x84,0,local_48.y << 0x10 | local_48.x & 0xffffU);
      SendMessageA(local_3c,0x20,(WPARAM)local_3c,local_40 & 0xffff | 0x2000000);
      FUN_00409b2c(1,*(int *)((int)local_38 + 0xe0));
      FUN_00409b2c(0,*(int *)((int)local_38 + 0xe4));
      FUN_00477d73(DAT_007006b0,(char *)((int)local_38 + 0x18),*(uint *)((int)local_38 + 0x14));
      Ai_Subsystem_004b74b1(&local_4c,&local_50);
      if (((local_50 == 0x15) && (local_4c == 1)) && (iVar2 = Ai_Subsystem_004b75a4(), iVar2 != 0))
      {
        DAT_0069f6d0 = 1;
      }
      local_8 = 0;
      while (local_8 == 0) {
        GetExitCodeThread(DAT_006fe484,&local_18);
        if (local_18 != 0x103) {
          local_8 = 1;
        }
        local_10 = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
        if (DAT_0067f3c4 != 0) {
          if ((local_10 != 0) && (local_34.message == 0x464)) {
            local_10 = 0;
          }
          local_8 = 1;
          *local_14 = -5;
          local_14[1] = -1;
          local_14[2] = -1;
          if (*local_14 == 0) {
            local_c = 1;
          }
          else {
            local_c = 0;
          }
        }
        if (local_10 != 0) {
          if (local_34.message == 0x464) {
            local_54 = (int *)local_34.lParam;
            local_8 = 1;
            local_c = (uint)(*(int *)local_34.lParam == 0);
            memcpy(local_14,(void *)local_34.lParam,0x10);
          }
          else if (local_34.message == 0x12) {
            PostQuitMessage(local_34.wParam);
            local_8 = 1;
            local_c = 0;
            *local_14 = -2;
          }
          else {
            Palette_Subsystem_00495cde(&local_34);
          }
        }
      }
      FUN_00477d73(DAT_007006b0,(char *)0x0,0);
      FUN_00409b2c(1,0);
      FUN_00409b2c(0,0);
      UpdateWindow(g_MainAppHwnd);
      DAT_006b1578 = 0;
      SetTimer(hwnd,(UINT_PTR)DAT_006fdbd4,45000,(TIMERPROC)0x0);
      return local_c;
    }
  }
  else {
    if (y == 0x464) {
      Ai_EvalAttackCandidate_004b4a3f(0,(uint)arg_3);
      return 0;
    }
    if (y == 0x501) {
      DAT_005219d0 = 0;
      BVar4 = 1;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      MoveWindow(hwnd,1,0,iVar3 + -1,iVar2,BVar4);
      return 0;
    }
  }
  uVar5 = DefWindowProcA(hwnd,y,(WPARAM)arg_3,(LPARAM)height);
  return uVar5;
}


