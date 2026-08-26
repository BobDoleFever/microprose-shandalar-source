/*
 * Decompiled function: FUN_004088d0
 * Entry Point: 004088d0
 * Size: 1068 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004088d0(int *arg_1)

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
    if ((*arg_1 == 0) && (arg_1[2] == DAT_006b2d8c)) {
      KillTimer((HWND)0x0,DAT_006b2d8c);
      DAT_006b2d8c = 0;
      GetCursorPos(&local_e8);
      Point.y = local_e8.y;
      Point.x = local_e8.x;
      local_e0 = WindowFromPoint(Point);
      local_f0.x = local_e8.x;
      local_f0.y = local_e8.y;
      ScreenToClient(local_e0,&local_f0);
      LVar4 = SendMessageA(local_e0,0x437,(WPARAM)local_68,local_f0.y << 0x10 | local_f0.x & 0xffffU
                          );
      if ((LVar4 != 0) && (DAT_006fe420 != 0)) {
        SendMessageA(DAT_006b1570,0x400,
                     (local_e8.y + _DAT_006a4a4c) * 0x10000 | local_e8.x + _DAT_007006b8 & 0xffffU,
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
    BVar1 = IsWindowVisible(DAT_006b1570);
    if (BVar1 == 0) {
      if (DAT_006b2d8c != 0) {
        KillTimer((HWND)0x0,DAT_006b2d8c);
        DAT_006b2d8c = 0;
      }
      DAT_006b2d8c = SetTimer((HWND)0x0,0,DAT_006a2850,(TIMERPROC)0x0);
    }
    else if (*arg_1 == DAT_00516be0) {
      local_6c = 1;
      local_dc = 1;
      if (*arg_1 == DAT_00516be0) {
        iVar3 = abs(((uint)arg_1[3] >> 0x10) - _DAT_00516bec);
        iVar2 = abs(*(ushort *)(arg_1 + 3) - _DAT_00516be8);
        if (DAT_00695f10 < iVar3 + iVar2) {
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
        ShowWindow(DAT_006b1570,0);
      }
      else if (local_6c != 0) {
        DAT_00516be0 = *arg_1;
        _DAT_00516be8 = (uint)*(ushort *)(arg_1 + 3);
        _DAT_00516bec = (uint)arg_1[3] >> 0x10;
        GetCursorPos(&local_74);
        if (DAT_006fe420 == 0) {
          ShowWindow(DAT_006b1570,0);
        }
        else {
          SendMessageA(DAT_006b1570,0x401,0,(LPARAM)local_d8);
          iVar3 = strcmp(local_d8,local_68);
          if (iVar3 != 0) {
            SendMessageA(DAT_006b1570,0x400,
                         (local_74.y + _DAT_006a4a4c) * 0x10000 |
                         local_74.x + _DAT_007006b8 & 0xffffU,(LPARAM)local_68);
          }
        }
      }
    }
    else {
      if (DAT_006b2d8c != 0) {
        KillTimer((HWND)0x0,DAT_006b2d8c);
        DAT_006b2d8c = 0;
      }
      DAT_006b2d8c = SetTimer((HWND)0x0,0,DAT_006a2850,(TIMERPROC)0x0);
      DAT_00516be0 = *arg_1;
      ShowWindow(DAT_006b1570,0);
    }
    uVar5 = 0;
    break;
  case 0x201:
  case 0x204:
  case 0x207:
    ShowWindow(DAT_006b1570,0);
    if (DAT_006b2d8c != 0) {
      KillTimer((HWND)0x0,DAT_006b2d8c);
      DAT_006b2d8c = 0;
    }
    uVar5 = 0;
  }
  return uVar5;
}


