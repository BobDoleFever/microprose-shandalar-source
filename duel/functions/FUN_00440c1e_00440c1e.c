/*
 * Decompiled function: FUN_00440c1e
 * Entry Point: 00440c1e
 * Size: 737 bytes
 */
#include "duel.h"


LRESULT FUN_00440c1e(undefined4 arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,
                    undefined4 arg_6,undefined4 arg_7,int *arg_8,undefined4 *arg_9,undefined4 arg_10
                    ,undefined4 arg_11)

{
  POINT Point;
  POINT Point_00;
  BOOL BVar1;
  tagPOINT local_1e4;
  HWND local_1dc;
  DWORD local_1d8;
  tagPOINT local_1d4;
  HWND local_1cc;
  uint local_1c8 [50];
  int local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  LRESULT local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  uint local_d4 [50];
  undefined4 local_c;
  undefined4 local_8;
  
  if (arg_2 == 0) {
    Mem_AllocOrFree_004d9630(local_1c8,(uint *)&DAT_004f7cfc);
  }
  else {
    Mem_AllocOrFree_004d9630(local_1c8,(uint *)arg_2);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (DAT_0060d490 != -1) {
    DAT_0060d490 = -1;
    BVar1 = IsWindowVisible(DAT_006152ec);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006152e8,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006152ec,(RECT *)0x0,1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  FUN_00451482(0,0xff);
  GetCursorPos(&local_1d4);
  Point.y = local_1d4.y;
  Point.x = local_1d4.x;
  local_1cc = WindowFromPoint(Point);
  SendMessageA(local_1cc,0x20,(WPARAM)local_1cc,0x2000001);
  local_ec = arg_1;
  local_e8 = arg_4;
  local_e4 = arg_5;
  local_e0 = arg_6;
  local_dc = arg_7;
  local_c = arg_10;
  local_8 = arg_11;
  Mem_AllocOrFree_004d9630(local_d4,local_1c8);
  local_d8 = arg_3;
  local_f0 = SendMessageA(DAT_00618990,0x403,(WPARAM)&local_ec,(LPARAM)&local_100);
  *arg_8 = local_100;
  *arg_9 = local_fc;
  arg_9[1] = local_f8;
  FUN_00446a07((char *)0x0);
  if (local_100 != -5) {
    GetCursorPos(&local_1e4);
    Point_00.y = local_1e4.y;
    Point_00.x = local_1e4.x;
    local_1dc = WindowFromPoint(Point_00);
    SendMessageA(local_1dc,0x20,(WPARAM)local_1dc,0x2000001);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (DAT_0068f2cc == -2) {
      if (DAT_0066ab04 == -1) {
        DAT_0060d490 = -1;
        DAT_0060cc74 = 0xffffffff;
      }
      else {
        DAT_0060cc74 = DAT_0066aac4;
        DAT_0060d490 = DAT_0066ab04;
      }
    }
    else {
      DAT_0060d490 = -1;
      DAT_0060cc74 = 0xffffffff;
    }
    BVar1 = IsWindowVisible(DAT_006152ec);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006152e8,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006152ec,(RECT *)0x0,1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    return local_f0;
  }
  local_1d8 = 0;
  PostMessageA(DAT_00618990,0x401,0,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(local_1d8);
}


