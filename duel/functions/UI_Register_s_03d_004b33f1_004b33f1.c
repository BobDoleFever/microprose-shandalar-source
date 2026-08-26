/*
 * Decompiled function: UI_Register_s_03d_004b33f1
 * Entry Point: 004b33f1
 * Size: 6694 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_Register_s_03d_004b33f1(HWND hwnd,uint y,HWND param_3,int *height)

{
  POINT Point;
  DWORD arg_1;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  undefined4 *arg_3;
  BITMAPINFO *arg_4;
  undefined4 *arg_5;
  undefined4 *arg_6;
  int *arg_7;
  int local_630;
  uint local_62c [66];
  uint local_524 [125];
  uint local_330 [13];
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
  uint local_c0 [25];
  int local_5c;
  HWND local_58;
  int *local_54;
  int local_50;
  int local_4c;
  tagPOINT local_48;
  uint local_40;
  HWND local_3c;
  HWND local_38;
  tagMSG local_34;
  DWORD local_18;
  int *local_14;
  BOOL local_10;
  uint local_c;
  int local_8;
  
  if (y < 0x11) {
    if (y == 0x10) {
      DAT_005f2f9c = 1;
      DAT_00681ea8 = 0;
      return 0;
    }
    if (y == 1) {
      DAT_00663e64 = (HANDLE)0x0;
      iVar2 = UI_Register_MAGICGAME_AttackClass_004b4efc(hwnd);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      PostMessageA(hwnd,0x400,0,0);
      DAT_00617430 = CreateWindowExA(0,s_MAGIC_PaletteClass_00506a4c,s_Palette_00506a44,0x80cc0000,
                                     0x14,0x14,300,0x15e,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      DAT_00663610 = (HWND)0x14;
      DAT_00664a5c = (HWND)0x0;
      return 0;
    }
    if (y == 2) {
      Mem_AllocOrFree_004d9630(local_62c,(uint *)&DAT_005f76e0);
      FUN_004d9640(local_62c,(uint *)s__duel_hlp_00506a60);
      WinHelpA(DAT_00618990,(LPCSTR)local_62c,2,0);
      KillTimer(hwnd,(UINT_PTR)DAT_00663610);
      return 0;
    }
    if (y == 5) {
      if ((param_3 == (HWND)0x0) && (DAT_00506900 == 0)) {
        LockWindowUpdate(hwnd);
        FUN_004b5565(hwnd,DAT_00663e24);
        FUN_004b1cc1(DAT_00617378);
        FUN_004b1cc1(DAT_00618988);
        LockWindowUpdate((HWND)0x0);
      }
      if (param_3 == (HWND)0x1) {
        DAT_00506900 = 1;
      }
      else if (param_3 == (HWND)0x0) {
        DAT_00506900 = 0;
      }
      if ((param_3 == (HWND)0x1) && (DAT_005f67ec != (HWND)0x0)) {
        ShowWindow(DAT_005f67ec,5);
      }
      return 0;
    }
  }
  else if (y < 0x7f) {
    if (y == 0x7e) {
      if (DAT_00664c30 != param_3) {
        for (local_630 = 0; local_630 < DAT_0061743c; local_630 = local_630 + 1) {
          FUN_00438e72(local_630);
        }
        for (local_630 = 0; local_630 < DAT_005f76d4; local_630 = local_630 + 1) {
          FUN_00486a4e((&DAT_00664880)[local_630 * 6],(&DAT_00664884)[local_630 * 6]);
        }
        DAT_005f76d4 = 0;
      }
      DAT_00664c30 = param_3;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      FUN_0047097b(DAT_0060157c,DAT_00664c00);
      arg_7 = &DAT_0061897c;
      arg_6 = (undefined4 *)&DAT_00664db0;
      arg_5 = &DAT_00664c00;
      arg_4 = (BITMAPINFO *)&DAT_00617440;
      arg_3 = &DAT_0060157c;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      iVar2 = FUN_004707f3(iVar3,iVar2,arg_3,arg_4,arg_5,arg_6,arg_7);
      if (iVar2 == 0) {
        MessageBoxA(hwnd,s_Not_enough_system_memory_to_run_a_00506a84,
                    s_Magic__The_Gathering_00506a6c,0x30);
        ShowWindow(hwnd,0);
      }
      else {
        ShowWindow(hwnd,5);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      BVar4 = IsIconic(hwnd);
      if (BVar4 == 0) {
        MoveWindow(hwnd,1,0,((uint)height & 0xffff) - 1,(uint)height >> 0x10,1);
      }
      else {
        DAT_005068fc = 1;
      }
      return 0;
    }
    if (y == 0x13) {
      if (DAT_005068fc != 0) {
        PostMessageA(hwnd,0x501,0,0);
      }
      if (DAT_005f67ec != (HWND)0x0) {
        ShowWindow(DAT_005f67ec,5);
      }
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uVar5 = FUN_00472b60(hwnd,y,param_3,height);
      return uVar5;
    }
    if (y == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 599:
        DAT_00601618 = (uint)(DAT_00601618 == 0);
        if (DAT_0061894c == 0) {
          DAT_00601618 = 0;
        }
        break;
      case 0x25c:
        if (DAT_00601618 != 0) {
          DAT_0060cc60 = (uint)(DAT_0060cc60 == 0);
          FUN_004baa8b(DAT_00663df4);
        }
        break;
      case 0x25d:
        if (DAT_00601618 != 0) {
          FUN_0043982e(DAT_00505984);
        }
        break;
      case 0x25e:
        if (DAT_00601618 != 0) {
          Mem_AllocOrFree_00439863(DAT_00505984);
        }
        break;
      case 0x263:
        if (DAT_00601618 != 0) {
          DAT_00681ea8 = 0;
          DAT_00681eac = 0;
          SendMessageA(DAT_00618160,0x432,0,0);
          SendMessageA(DAT_00664c28,0x432,0,0);
        }
        break;
      case 0x267:
      case 0x268:
        if (DAT_00601618 != 0) {
          local_2ec = (uint)(((uint)param_3 & 0xffff) == 0x267);
          (&DAT_00681ea8)[local_2ec] = 0;
          SendMessageA(DAT_00618160,0x432,0,0);
          SendMessageA(DAT_00664c28,0x432,0,0);
        }
        break;
      case 0x269:
      case 0x26a:
        if (DAT_00601618 != 0) {
          local_2ec = (uint)(((uint)param_3 & 0xffff) != 0x269);
          FUN_00487ce1(local_2ec);
          FUN_00445f05(0,0xff);
        }
        break;
      case 0x26b:
      case 0x26c:
        if (DAT_00601618 != 0) {
          local_2ec = (uint)(((uint)param_3 & 0xffff) != 0x26b);
          local_2f0 = FUN_004b8160(s_Pick_a_card_to_put_into_play_0050698c,-1,-1);
          local_2f8 = *(undefined4 *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98);
          *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
               *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) & 0xfffe;
          local_2f4 = FUN_004d695b(local_2ec,local_2f0);
          if (local_2f4 != -1) {
            FUN_004bda20(local_2ec,local_2f4);
          }
          *(undefined4 *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) = local_2f8;
          FUN_00445f05(0,0xff);
        }
        break;
      case 0x26d:
      case 0x26e:
        if (DAT_00601618 != 0) {
          local_2ec = (uint)(((uint)param_3 & 0xffff) != 0x26d);
          local_2f0 = FUN_004b8160(s_Pick_a_card_to_put_into_hand_005069ac,-1,-1);
          local_2f4 = FUN_004d695b(local_2ec,local_2f0);
          FUN_00445f05(0,0xff);
        }
        break;
      case 0x26f:
      case 0x270:
        if (DAT_00601618 != 0) {
          local_2ec = (uint)(((uint)param_3 & 0xffff) != 0x26f);
          uVar1 = FUN_00443000(0,s_Set_player_lives_to__005069cc + ((local_2ec == 0) - 1 & 0x18),
                               (&DAT_00681ea8)[local_2ec]);
          (&DAT_00681ea8)[local_2ec] = uVar1;
          FUN_00445f05(0,0xff);
        }
        break;
      case 0x271:
        if (DAT_00601618 != 0) {
          ShowWindow(DAT_00617430,5);
        }
        break;
      case 0x272:
        if (DAT_00601618 != 0) {
          DAT_005f77f0 = (uint)(DAT_005f77f0 == 0);
          SendMessageA(DAT_00617378,0x435,0,0);
          SendMessageA(DAT_00618988,0x435,0,0);
          SendMessageA(DAT_006152b0,0x435,0,0);
          SendMessageA(DAT_00663df4,0x435,0,0);
          InvalidateRect(DAT_00663e68,(RECT *)0x0,1);
          InvalidateRect(DAT_00664c04,(RECT *)0x0,1);
        }
        break;
      case 0x273:
        if (DAT_00601618 != 0) {
          DAT_0060cc70 = (uint)(DAT_0060cc70 == 0);
          SendMessageA(DAT_00617378,0x435,0,0);
          SendMessageA(DAT_00618988,0x435,0,0);
          SendMessageA(DAT_006152b0,0x435,0,0);
          SendMessageA(DAT_00663df4,0x435,0,0);
          InvalidateRect(DAT_006152e0,(RECT *)0x0,0);
        }
        break;
      case 0x274:
        if (DAT_00601618 != 0) {
          DAT_0068f0b0 = 0;
        }
        break;
      case 0x275:
        if (DAT_00601618 != 0) {
          _sprintf((char *)local_524,s__d_big_arts_are_in__max_is__d__005069fc,DAT_005f76d4,0x14);
          for (local_2fc = 0; local_2fc < DAT_005f76d4; local_2fc = local_2fc + 1) {
            _sprintf((char *)local_330,s__3d__d___dx_d_00506a1c,(&DAT_00664880)[local_2fc * 6],
                     (&DAT_00664884)[local_2fc * 6],
                     *(undefined4 *)(&DAT_00664878 + local_2fc * 0x18),
                     *(undefined4 *)(&DAT_0066487c + local_2fc * 0x18));
            FUN_004d9640(local_524,local_330);
          }
          MessageBoxA(hwnd,(LPCSTR)local_524,s_These_big_arts_are_in__00506a2c,0);
        }
        break;
      case 0x276:
        if (DAT_00601618 != 0) {
          if (DAT_00601580 == 0) {
            DAT_00601580 = 1;
          }
          else {
            DAT_00601580 = 0;
          }
        }
        break;
      case 0x277:
        if (DAT_00601618 != 0) {
          BVar4 = IsWindowVisible(DAT_00694744);
          ShowWindow(DAT_00694744,-(uint)(BVar4 == 0) & 5);
        }
        break;
      case 0x279:
        DAT_00663e18 = (uint)(DAT_00663e18 == 0);
        SendMessageA(DAT_00617378,0x435,0,0);
        SendMessageA(DAT_00618988,0x435,0,0);
        SendMessageA(DAT_00618ab0,0x435,0,0);
        SendMessageA(DAT_00663df0,0x435,0,0);
        break;
      case 0x27a:
        DAT_00663e1c = (uint)(DAT_00663e1c == 0);
        FUN_00445f05(0,0xff);
        break;
      case 0x27b:
        _DAT_00615304 = DAT_00618990;
        _DAT_00615330 = s_Save_Game_00506980;
        _DAT_00615334 = 0x2a000c;
        BVar4 = GetSaveFileNameA((LPOPENFILENAMEA)&DAT_00615300);
        if (BVar4 != 0) {
          FUN_0049ae63(DAT_0061531c);
        }
        break;
      case 0x27c:
        DAT_00663e20 = (uint)(DAT_00663e20 == 0);
        SendMessageA(DAT_00617378,0x435,0,0);
        SendMessageA(DAT_00618988,0x435,0,0);
        SendMessageA(DAT_00618ab0,0x435,0,0);
        SendMessageA(DAT_00663df0,0x435,0,0);
      }
      return 0;
    }
    if (y == 0x113) {
      if (((DAT_00663610 == param_3) && (DAT_00618158 == 0)) && (DAT_00664a5c == (HWND)0x0)) {
        FUN_004b693d();
      }
      return 0;
    }
  }
  else if (y < 0x435) {
    if (0x432 < y) {
      return 0;
    }
    if (y == 0x400) {
      DAT_005f2f9c = 0;
      if (DAT_00663e24 == 2) {
        ShowWindow(DAT_006152e0,0);
      }
      else {
        SendMessageA(DAT_006152e0,0x401,0xffffffff,0);
      }
      SendMessageA(DAT_006152b0,0x40c,0,0);
      SendMessageA(DAT_00663df4,0x40c,0,0);
      SendMessageA(DAT_00617378,0x40c,0,0);
      SendMessageA(DAT_00618988,0x40c,0,0);
      DAT_005f77e8 = 0xffffffff;
      DAT_006152e4 = 0xffffffff;
      DAT_00617370 = 0;
      DAT_00601584 = 0xffffffff;
      SendMessageA(DAT_006152ec,0x432,0,0);
      ShowWindow(DAT_006152ec,5);
      ShowWindow(DAT_006152e8,0);
      DAT_00664a50 = 0;
      DAT_00616a00 = 0;
      DAT_00664dac = 0;
      DAT_0060cc80 = 0;
      SendMessageA(DAT_00618160,0x432,0,0);
      SendMessageA(DAT_00664c28,0x432,0,0);
      for (local_c8 = 0; local_c8 < 7; local_c8 = local_c8 + 1) {
        *(undefined4 *)(&DAT_0060cc90 + local_c8 * 4) = 0;
        *(undefined4 *)(&DAT_006152c0 + local_c8 * 4) =
             *(undefined4 *)(&DAT_0060cc90 + local_c8 * 4);
      }
      SendMessageA(DAT_00618950,0x432,0,0);
      SendMessageA(DAT_00664c34,0x432,0,0);
      DAT_00618980 = 1;
      DAT_00618944 = 1;
      SendMessageA(DAT_00663e68,0x432,0,0);
      SendMessageA(DAT_00664c04,0x432,0,0);
      DAT_00664d94 = 0;
      DAT_00664a54 = 0;
      DAT_00618948 = 0;
      DAT_00664b68 = 0;
      SendMessageA(DAT_00618978,0x432,0,0);
      SendMessageA(DAT_0061737c,0x432,0,0);
      SendMessageA(DAT_00618ab0,0x40c,0,0);
      DAT_00618984 = 0;
      DAT_0068efb0 = 0xffffffff;
      SendMessageA(DAT_00663df0,0x40c,0,0);
      DAT_00618158 = 0;
      ShowWindow(DAT_00617438,0);
      ShowWindow(DAT_00601550,0);
      UpdateWindow(hwnd);
      SetFocus(hwnd);
      arg_1 = GetTickCount();
      Mem_AllocOrFree_004d9830(arg_1);
      if (DAT_0066aaf4 == -10) {
        FUN_00433d45(DAT_0061531c);
        DAT_00505988 = 0;
        DAT_00505984 = 1;
      }
      else if (((byte)DAT_00663dfc & 4) == 0) {
        if (((byte)DAT_00663dfc & 1) != 0) {
          DAT_00663e6c = FUN_0043a094(DAT_00505984);
          DAT_006169f0 = FUN_0043a094(DAT_00505988);
        }
      }
      else {
        DAT_00663e6c = FUN_0043a094(DAT_00505984);
        DAT_006169f0 = FUN_0043a094(DAT_00505988);
      }
      if (((byte)DAT_00663dfc & 0x10) == 0) {
        if (((byte)DAT_00663dfc & 1) == 0) {
          if (DAT_00617434 == -1) {
            _sprintf(local_2d4,s__s__03d_pic_00506968,&DAT_00617470,_OpponFace);
          }
          else {
            _sprintf(local_2d4,s__s__03d_pic_0050695c,&DAT_00617470,DAT_00617434);
          }
          local_cc = FUN_0043d713(local_2d4);
          SendMessageA(DAT_00617438,0x439,local_cc,0);
          _sprintf(local_2d4,s__s__03d_pic_00506974,&DAT_00617470,_PlayerFace);
          local_cc = FUN_0043d713(local_2d4);
          SendMessageA(DAT_00601550,0x439,local_cc,0);
        }
        else {
          if (DAT_00617434 == -1) {
            local_cc = 0;
          }
          else {
            _sprintf(local_1d0,s__s__03d_pic_00506950,&DAT_00617470,DAT_00617434);
            local_cc = FUN_0043d713(local_1d0);
          }
          SendMessageA(DAT_00617438,0x439,local_cc,0);
          local_cc = DAT_005f6280;
          SendMessageA(DAT_00601550,0x439,DAT_005f6280,1);
        }
      }
      else {
        SendMessageA(DAT_00617438,0x439,0,0);
        SendMessageA(DAT_00601550,0x439,0,0);
      }
      if (((byte)DAT_00663dfc & 0x10) == 0) {
        if (DAT_00601578 == 0) {
          local_2dc = DAT_00663e6c;
          local_2e4 = _rand();
          local_2e4 = local_2e4 % 3;
          if (DAT_00663e28 == -1) {
            local_2e0 = DAT_006169f0;
          }
          else {
            local_2e0 = DAT_00663e28;
          }
          local_2d8 = DAT_00663e2c;
          if ((local_2e0 == local_2dc) && (DAT_00663e2c == local_2e4)) {
            local_2e4 = (local_2e4 + 1) % 3;
          }
          DAT_00617380 = local_2e4;
        }
        else {
          local_2dc = DAT_00663e6c;
          local_2e4 = DAT_00617380;
          if (DAT_00663e28 == -1) {
            local_2e0 = DAT_006169f0;
          }
          else {
            local_2e0 = DAT_00663e28;
          }
          local_2d8 = DAT_00663e2c;
        }
      }
      else {
        local_2e0 = 1;
        local_2dc = 1;
        local_2d8 = 2;
        local_2e4 = 2;
      }
      Pic_Load_s_s_004b6466(1,local_2dc,local_2e4);
      Pic_Load_s_s_004b6466(0,local_2e0,local_2d8);
      BVar4 = IsWindowVisible(hwnd);
      if (BVar4 == 0) {
        ShowWindow(hwnd,5);
        SetForegroundWindow(hwnd);
        UpdateWindow(hwnd);
        ShowWindow(DAT_006152b0,5);
        ShowWindow(DAT_00663df4,5);
      }
      if (((byte)DAT_00663dfc & 0x10) == 0) {
        DAT_00663e64 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_004b4ea6,(LPVOID)0x0,0,
                                    &local_2e8);
        SetThreadPriority(DAT_00663e64,0);
      }
      else {
        DAT_00663e64 = (HANDLE)0x0;
        PostMessageA(hwnd,0x401,0,0);
      }
      return 0;
    }
    if (y == 0x401) {
      local_58 = param_3;
      local_5c = 1;
      if (DAT_00663e64 != (HANDLE)0x0) {
        WaitForSingleObject(DAT_00663e64,0xffffffff);
        CloseHandle(DAT_00663e64);
        DAT_00663e64 = (HANDLE)0x0;
      }
      if (((byte)DAT_00663dfc & 1) == 0) {
        if (((byte)DAT_00663dfc & 2) == 0) {
          if (((byte)DAT_00663dfc & 4) != 0) {
            iVar2 = FUN_0049ba93(hwnd,(int)local_58);
            if (iVar2 == 0) {
              FUN_00481f02();
            }
            else {
              local_5c = 0;
              SendMessageA(hwnd,0x400,0,0);
            }
          }
        }
        else {
          local_c4 = 1;
          if (local_58 == (HWND)0x1) {
            Mem_AllocOrFree_004d9630(local_c0,(uint *)s_Congratulations__00506904);
          }
          else if (local_58 == (HWND)0x0) {
            Mem_AllocOrFree_004d9630(local_c0,(uint *)s_Too_bad_00506918);
          }
          else if (local_58 == (HWND)0xffffffff) {
            Mem_AllocOrFree_004d9630(local_c0,(uint *)s_Oh_well____00506920);
          }
          else {
            local_c4 = 0;
          }
          if (local_c4 != 0) {
            FUN_004d9640(local_c0,(uint *)s_Want_to_play_again__0050692c);
            iVar2 = MessageBoxA(hwnd,(LPCSTR)local_c0,s_End_of_duel_00506944,4);
            if (iVar2 == 6) {
              local_5c = 0;
              SendMessageA(hwnd,0x400,0,0);
            }
          }
        }
      }
      else if (DAT_00663e14 != 0) {
        FUN_0043fc31((int)local_58);
      }
      if (local_5c != 0) {
        DestroyWindow(hwnd);
        DAT_006679e0 = local_58;
        PostQuitMessage((int)local_58);
      }
      return 0;
    }
    if (y == 0x403) {
      if (DAT_00664a5c != (HWND)0x0) {
        SendMessageA(DAT_00664a5c,0x10,0,0);
      }
      KillTimer(hwnd,(UINT_PTR)DAT_00663610);
      local_38 = param_3;
      local_14 = height;
      DAT_00618158 = 1;
      FID_conflict__memcpy(&DAT_00664780,param_3,0xe8);
      GetCursorPos(&local_48);
      Point.y = local_48.y;
      Point.x = local_48.x;
      local_3c = WindowFromPoint(Point);
      local_40 = SendMessageA(local_3c,0x84,0,local_48.y << 0x10 | local_48.x & 0xffffU);
      SendMessageA(local_3c,0x20,(WPARAM)local_3c,local_40 & 0xffff | 0x2000000);
      FUN_0043753a(1,local_38[0x38].unused);
      FUN_0043753a(0,local_38[0x39].unused);
      FUN_004b7b63(DAT_00664d90,(char *)(local_38 + 6),local_38[5].unused);
      FUN_0044897a(&local_4c,&local_50);
      if (((local_50 == 0x15) && (local_4c == 1)) && (iVar2 = FUN_00448a6d(), iVar2 != 0)) {
        DAT_006152b4 = 1;
      }
      local_8 = 0;
      while (local_8 == 0) {
        GetExitCodeThread(DAT_00663e64,&local_18);
        if (local_18 != 0x103) {
          local_8 = 1;
        }
        local_10 = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
        if (DAT_005f2f9c != 0) {
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
            FID_conflict__memcpy(local_14,(void *)local_34.lParam,0x10);
          }
          else if (local_34.message == 0x12) {
            PostQuitMessage(local_34.wParam);
            local_8 = 1;
            local_c = 0;
            *local_14 = -2;
          }
          else {
            FUN_00437fb8(&local_34);
          }
        }
      }
      FUN_004b7b63(DAT_00664d90,(char *)0x0,0);
      FUN_0043753a(1,0);
      FUN_0043753a(0,0);
      UpdateWindow(DAT_00618990);
      DAT_00618158 = 0;
      SetTimer(hwnd,(UINT_PTR)DAT_00663610,45000,(TIMERPROC)0x0);
      return local_c;
    }
  }
  else {
    if (y == 0x464) {
      FUN_00445f05(0,(uint)param_3);
      return 0;
    }
    if (y == 0x501) {
      DAT_005068fc = 0;
      BVar4 = 1;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      MoveWindow(hwnd,1,0,iVar3 + -1,iVar2,BVar4);
      return 0;
    }
  }
  uVar5 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)height);
  return uVar5;
}


