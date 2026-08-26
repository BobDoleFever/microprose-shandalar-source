/*
 * Decompiled function: FUN_00491ef3
 * Entry Point: 00491ef3
 * Size: 1064 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00491ef3(int *arg_1)

{
  POINT Point;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  LRESULT LVar4;
  undefined4 uVar5;
  tagPOINT local_f0;
  tagPOINT local_e8;
  HWND local_e0;
  int local_dc;
  char local_d8 [100];
  tagPOINT local_74;
  int local_6c;
  char local_68 [100];
  
  switch(arg_1[1]) {
  case 0x113:
    if ((*arg_1 == 0) && (arg_1[2] == DAT_00618974)) {
      KillTimer((HWND)0x0,DAT_00618974);
      DAT_00618974 = 0;
      GetCursorPos(&local_e8);
      Point.y = local_e8.y;
      Point.x = local_e8.x;
      local_e0 = WindowFromPoint(Point);
      local_f0.x = local_e8.x;
      local_f0.y = local_e8.y;
      ScreenToClient(local_e0,&local_f0);
      LVar4 = SendMessageA(local_e0,0x437,(WPARAM)local_68,local_f0.y << 0x10 | local_f0.x & 0xffffU
                          );
      if ((LVar4 != 0) && (DAT_00663e00 != 0)) {
        SendMessageA(DAT_00618150,0x400,
                     (local_e8.y + _DAT_0061746c) * 0x10000 | local_e8.x + _DAT_00664d98 & 0xffffU,
                     (LPARAM)local_68);
      }
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    break;
  default:
    uVar5 = 0;
    break;
  case 0x200:
    BVar1 = IsWindowVisible(DAT_00618150);
    if (BVar1 == 0) {
      if (DAT_00618974 != 0) {
        KillTimer((HWND)0x0,DAT_00618974);
        DAT_00618974 = 0;
      }
      DAT_00618974 = SetTimer((HWND)0x0,0,DAT_006152f0,(TIMERPROC)0x0);
    }
    else if (*arg_1 == DAT_00505390) {
      local_6c = 1;
      local_dc = 1;
      if (*arg_1 == DAT_00505390) {
        iVar3 = Mem_AllocOrFree_004d9810(((uint)arg_1[3] >> 0x10) - _DAT_0050539c);
        iVar2 = Mem_AllocOrFree_004d9810(*(ushort *)(arg_1 + 3) - _DAT_00505398);
        if (DAT_0060ccb8 < iVar3 + iVar2) {
          local_dc = SendMessageA((HWND)*arg_1,0x437,(WPARAM)local_68,arg_1[3]);
        }
        else {
          local_6c = 0;
        }
      }
      else {
        local_dc = SendMessageA((HWND)*arg_1,0x437,(WPARAM)local_68,arg_1[3]);
      }
      if (local_dc == 0) {
        ShowWindow(DAT_00618150,0);
      }
      else if (local_6c != 0) {
        DAT_00505390 = *arg_1;
        _DAT_00505398 = (uint)*(ushort *)(arg_1 + 3);
        _DAT_0050539c = (uint)arg_1[3] >> 0x10;
        GetCursorPos(&local_74);
        if (DAT_00663e00 == 0) {
          ShowWindow(DAT_00618150,0);
        }
        else {
          SendMessageA(DAT_00618150,0x401,0,(LPARAM)local_d8);
          iVar3 = _strcmp(local_d8,local_68);
          if (iVar3 != 0) {
            SendMessageA(DAT_00618150,0x400,
                         (local_74.y + _DAT_0061746c) * 0x10000 |
                         local_74.x + _DAT_00664d98 & 0xffffU,(LPARAM)local_68);
          }
        }
      }
    }
    else {
      if (DAT_00618974 != 0) {
        KillTimer((HWND)0x0,DAT_00618974);
        DAT_00618974 = 0;
      }
      DAT_00618974 = SetTimer((HWND)0x0,0,DAT_006152f0,(TIMERPROC)0x0);
      DAT_00505390 = *arg_1;
      ShowWindow(DAT_00618150,0);
    }
    uVar5 = 0;
    break;
  case 0x201:
  case 0x204:
  case 0x207:
    ShowWindow(DAT_00618150,0);
    if (DAT_00618974 != 0) {
      KillTimer((HWND)0x0,DAT_00618974);
      DAT_00618974 = 0;
    }
    uVar5 = 0;
  }
  return uVar5;
}


