/*
 * Decompiled function: FUN_0044cd6f
 * Entry Point: 0044cd6f
 * Size: 4970 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0044cd6f(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  UINT dwMilliseconds;
  HBRUSH pHVar2;
  int iVar3;
  LRESULT LVar4;
  int local_5b4;
  int local_5b0;
  int local_5ac [38];
  tagPOINT local_514;
  UINT_PTR local_50c;
  int local_508;
  int local_504;
  UINT_PTR local_500;
  int local_4fc;
  UINT_PTR local_4f8;
  tagRECT local_4f4;
  tagPOINT local_4e4;
  tagRECT local_4dc;
  int local_4cc;
  undefined1 local_4c8 [264];
  HRGN local_3c0;
  HDC local_3bc;
  int local_3b8;
  undefined1 local_3b4 [4];
  int local_3b0;
  undefined4 local_3ac;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  RECT local_358;
  int local_348;
  tagRECT local_344;
  tagMSG local_334;
  uint local_318;
  BOOL local_314;
  uint local_310;
  uint local_30c;
  tagRECT local_308;
  int local_2f8;
  CHAR local_2f4 [264];
  ULONG_PTR local_1ec;
  int local_1e8;
  uint local_1e4;
  tagRECT local_1e0;
  RECT local_1d0;
  int local_1c0;
  uint local_1bc;
  int local_1b8;
  uint local_1b4;
  int local_1b0;
  int local_1ac;
  CHAR local_1a8 [264];
  ULONG_PTR local_a0;
  int local_9c;
  int local_98;
  undefined1 local_94 [100];
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  LONG local_c;
  LONG local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_c = GetWindowLongA(param_1,0);
      local_8 = GetWindowLongA(param_1,4);
      FUN_0044897a(&local_348,&local_3b8);
      if ((local_c != local_3b8) || (local_8 != local_348)) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      if (DAT_00516b58 == (HANDLE)0x0) {
        FUN_004d9630(local_4c8,&DAT_006189a0);
        FUN_004d9640(local_4c8,s__WINBK_Phase_pic_004f833c);
        DAT_00516b58 = (HANDLE)FUN_0043d713(local_4c8);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_3bc = DAT_0060157c;
      local_35c = SaveDC(DAT_0060157c);
      GetClientRect(param_1,&local_344);
      if (DAT_00516b58 == (HANDLE)0x0) {
        pHVar2 = GetStockObject(4);
        FillRect(local_3bc,&local_344,pHVar2);
      }
      else {
        GetObjectA(DAT_00516b58,0x18,local_3b4);
        FUN_00470a16(local_3bc,&local_344,DAT_00516b58,0,0,local_3b0 / DAT_00516bb0,local_3ac);
      }
      if ((local_348 != -1) && (local_3b8 != -1)) {
        FUN_0044e52d(&local_358,local_348,local_3b8,local_344.right,local_344.bottom);
        local_3c0 = CreateRectRgnIndirect(&local_358);
        SelectClipRgn(local_3bc,local_3c0);
        if (DAT_00516b58 == (HANDLE)0x0) {
          pHVar2 = GetStockObject(2);
          FillRect(local_3bc,&local_344,pHVar2);
        }
        else {
          GetObjectA(DAT_00516b58,0x18,local_3b4);
          FUN_00470a16(local_3bc,&local_344,DAT_00516b58,local_3b0 - local_3b0 / DAT_00516bb0,0,
                       local_3b0 / DAT_00516bb0,local_3ac);
        }
        SelectClipRgn(local_3bc,(HRGN)0x0);
        DeleteObject(local_3c0);
      }
      RestoreDC(DAT_0060157c,local_35c);
      FUN_0044e776(local_3bc,&local_344);
      local_3bc = BeginPaint(param_1,&local_39c);
      if (local_3bc != (HDC)0x0) {
        FUN_004707a4(local_3bc);
        GetClientRect(param_1,&local_344);
        if (DAT_00601580 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_3bc,&local_344,pHVar2);
          Sleep(200);
        }
        BitBlt(local_3bc,0,0,local_344.right,local_344.bottom,DAT_0060157c,0,0,0xcc0020);
        FUN_00448a38(&local_4cc);
        if (local_4cc != -1) {
          if (local_4cc == 0) {
            local_344.bottom = local_344.bottom - (local_344.bottom - local_344.top) / 2;
          }
          else {
            local_344.top = local_344.top + (local_344.bottom - local_344.top) / 2;
          }
          SelectObject(local_3bc,DAT_00516b74);
          SetBkMode(local_3bc,1);
          Rectangle(local_3bc,local_344.left,local_344.top,local_344.right,local_344.bottom);
        }
        EndPaint(param_1,&local_39c);
        local_c = local_3b8;
        local_8 = local_348;
        SetWindowLongA(param_1,0,local_3b8);
        SetWindowLongA(param_1,4,local_8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_c = 0;
      local_8 = 0;
      SetWindowLongA(param_1,0,0);
      SetWindowLongA(param_1,4,local_8);
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      LVar4 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar4;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x118) {
    if (param_2 == 0x117) {
      GetCursorPos(&local_514);
      ScreenToClient(param_1,&local_514);
      GetClientRect(param_1,&local_4f4);
      FUN_0044e141(&local_514,&local_4f4,&local_4fc,&local_5b0);
      if (local_4fc == 1) {
        local_508 = 10;
      }
      else {
        local_508 = 0;
      }
      if (local_5b0 == 1) {
        local_504 = 0;
      }
      else if ((((local_5b0 == 2) || (local_5b0 == 3)) || (local_5b0 == 4)) || (local_5b0 == 5)) {
        local_504 = 1;
      }
      else if (local_5b0 == 10) {
        local_504 = 2;
      }
      else if (local_5b0 == 0x14) {
        local_504 = 3;
      }
      else if ((((local_5b0 == 0x15) || (local_5b0 == 0x16)) ||
               ((local_5b0 == 0x17 || ((local_5b0 == 0x18 || (local_5b0 == 0x19)))))) ||
              ((local_5b0 == 0x1a || (local_5b0 == 0x1b)))) {
        local_504 = 4;
      }
      else if (local_5b0 == 0x1e) {
        local_504 = 5;
      }
      else if (local_5b0 == 0x1f) {
        local_504 = 6;
      }
      else if ((((local_5b0 == 0x20) || (local_5b0 == 0x21)) || (local_5b0 == 0x22)) ||
              (local_5b0 == 0x25)) {
        local_504 = 7;
      }
      else {
        local_504 = -1;
      }
      if (local_5b0 != -1) {
        if (DAT_00618158 != 0) {
          local_500 = local_504 + local_508 + 0x96;
          AppendMenuA(DAT_00516b78,0,local_500,s_Run_to_this_phase_004f8350);
        }
        iVar3 = GetMenuItemCount(DAT_00516b78);
        if (iVar3 != 0) {
          AppendMenuA(DAT_00516b78,0x800,0,(LPCSTR)0x0);
        }
        local_4f8 = local_504 + local_508 + 200;
        AppendMenuA(DAT_00516b78,0,local_4f8,s_Mark_this_phase_to_always_stop_004f8364);
        FUN_004489c3(local_5ac,local_4fc);
        if (local_5ac[local_5b0] != 0) {
          CheckMenuItem(DAT_00516b78,local_4f8,8);
        }
        local_50c = local_504 + local_508 + 0xfa;
        AppendMenuA(DAT_00516b78,0,local_50c,s_Help_for_this_phase____004f8384);
      }
      AppendMenuA(DAT_00516b78,0,100,s_Help____004f839c);
      return 0;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 100) {
        local_a0 = 0x7e5;
        FUN_004d9630(local_1a8,&DAT_005f76e0);
        FUN_004d9640(local_1a8,s__duel_hlp_004f8324);
        WinHelpA(DAT_00618990,local_1a8,1,local_a0);
      }
      else {
        param_3 = param_3 & 0xffff;
        if (param_3 < 0xfa) {
          if (param_3 < 200) {
            local_1b0 = 0x96;
          }
          else {
            local_1b0 = 200;
          }
        }
        else {
          local_1b0 = 0xfa;
        }
        local_1b8 = param_3 - local_1b0;
        bVar1 = 9 < local_1b8;
        if (bVar1) {
          local_1b8 = local_1b8 + -10;
        }
        local_1b4 = (uint)bVar1;
        local_1ac = local_1b8;
        if (local_1b0 == 0x96) {
          local_1bc = local_1b4;
          if (local_1b8 == 0) {
            local_1c0 = 1;
          }
          else if (local_1b8 == 1) {
            local_1c0 = 4;
          }
          else if (local_1b8 == 2) {
            local_1c0 = 10;
          }
          else if (local_1b8 == 3) {
            local_1c0 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1c0 = 0x15;
            }
            else {
              local_1c0 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1c0 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1c0 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1c0 = 0x20;
          }
          DAT_0066aac4 = local_1b4;
          DAT_0066ab04 = local_1c0;
          DAT_0066643c = 0;
          _DAT_00516ba0 = 0xfffffffe;
          _DAT_00516ba4 = 0xffffffff;
          _DAT_00516ba8 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516ba0);
        }
        else if (local_1b0 == 200) {
          local_1e4 = local_1b4;
          if (local_1b8 == 0) {
            local_1e8 = 1;
          }
          else if (local_1b8 == 1) {
            local_1e8 = 4;
          }
          else if (local_1b8 == 2) {
            local_1e8 = 10;
          }
          else if (local_1b8 == 3) {
            local_1e8 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1e8 = 0x15;
            }
            else {
              local_1e8 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1e8 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1e8 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1e8 = 0x20;
          }
          if (((&DAT_006667c0)[local_1e8 * 4 + local_1b4 * 0x98] & 1) == 0) {
            *(uint *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) | 1;
          }
          else {
            *(uint *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) & 0xfffffffe;
          }
          FUN_00481890();
          FUN_004457a2();
          GetClientRect(param_1,&local_1e0);
          FUN_0044e52d(&local_1d0,local_1e4,local_1e8,local_1e0.right,local_1e0.bottom);
          InvalidateRect(param_1,&local_1d0,0);
        }
        else if (local_1b0 == 0xfa) {
          if (local_1b8 == 0) {
            local_1ec = 0x7da;
          }
          else if (local_1b8 == 1) {
            local_1ec = 0x7db;
          }
          else if (local_1b8 == 2) {
            local_1ec = 0x7dc;
          }
          else if (local_1b8 == 3) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 4) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 5) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 6) {
            local_1ec = 0x7de;
          }
          else if (local_1b8 == 7) {
            local_1ec = 0x7df;
          }
          FUN_004d9630(local_2f4,&DAT_005f76e0);
          FUN_004d9640(local_2f4,s__duel_hlp_004f8330);
          WinHelpA(DAT_00618990,local_2f4,1,local_1ec);
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      dwMilliseconds = GetDoubleClickTime();
      Sleep(dwMilliseconds);
      local_314 = PeekMessageA(&local_334,param_1,0x203,0x203,0);
      local_310 = param_4 & 0xffff;
      local_30c = param_4 >> 0x10;
      GetClientRect(param_1,&local_308);
      FUN_0044e141(&local_310,&local_308,&local_318,&local_2f8);
      if ((local_2f8 != -1) && (DAT_00618158 != 0)) {
        DAT_0066aac4 = local_318;
        DAT_0066ab04 = local_2f8;
        DAT_0066643c = local_314;
        _DAT_00516b60 = 0xfffffffe;
        _DAT_00516b64 = 0xffffffff;
        _DAT_00516b68 = 0xffffffff;
        PostMessageA(DAT_00618990,0x464,0,0x516b60);
      }
      return 0;
    }
    if (param_2 == 0x11f) {
      if ((param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_5b4 = GetMenuItemCount(DAT_00516b78);
        while (local_5b4 != 0) {
          DeleteMenu(DAT_00516b78,0,0x400);
          local_5b4 = local_5b4 + -1;
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar4 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar4;
    }
    if (param_2 == 0x204) {
      local_4e4.x = param_4 & 0xffff;
      local_4e4.y = param_4 >> 0x10;
      ClientToScreen(param_1,&local_4e4);
      SetRect(&local_4dc,local_4e4.x,local_4e4.y,local_4e4.x + 1,local_4e4.y + 1);
      TrackPopupMenu(DAT_00516b78,2,local_4e4.x,local_4e4.y,0,param_1,&local_4dc);
      return 0;
    }
  }
  else {
    if (param_2 == 0x400) {
      FUN_0045033a(param_1,param_3,param_4);
      return 0;
    }
    if (param_2 == 0x432) {
      local_c = GetWindowLongA(param_1,0);
      local_8 = GetWindowLongA(param_1,4);
      FUN_0044897a(&local_98,&local_9c);
      if ((local_c != local_9c) || (local_8 != local_98)) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      return 0;
    }
    if (param_2 == 0x437) {
      local_2c = param_4 & 0xffff;
      local_28 = param_4 >> 0x10;
      GetClientRect(param_1,&local_1c);
      FUN_0044e141(&local_2c,&local_1c,&local_20,&local_30);
      local_24 = 1;
      if (local_20 == 0) {
        FUN_004d9630(local_94,s_Your_004f826c);
      }
      else {
        FUN_00448412(local_94);
        FUN_004d9640(local_94,&DAT_004f8274);
      }
      switch(local_30) {
      case 1:
        FUN_004d9640(local_94,s_Untap_phase_004f8278);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        FUN_004d9640(local_94,s_Upkeep_phase_004f8284);
        break;
      default:
        local_24 = 0;
        break;
      case 10:
        FUN_004d9640(local_94,s_Draw_phase_004f8294);
        break;
      case 0x14:
        FUN_004d9640(local_94,s_Main_phase__pre_combat__004f82a0);
        break;
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
        if (local_20 == 1) {
          FUN_004d9640(local_94,s_Main_phase__combat__004f82b8);
        }
        else {
          FUN_004d9640(local_94,s_Main_phase__declare_attack__004f82cc);
        }
        break;
      case 0x1e:
        FUN_004d9640(local_94,s_Main_phase__post_combat__004f82e8);
        break;
      case 0x1f:
        FUN_004d9640(local_94,s_Discard_phase_004f8304);
        break;
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x25:
        FUN_004d9640(local_94,s_Cleanup_phase_004f8314);
      }
      if (local_24 == 0) {
        return 0;
      }
      FUN_004d9630(param_3,local_94);
      return local_24;
    }
  }
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}


