/*
 * Decompiled function: Ai_Subsystem_004af765
 * Entry Point: 004af765
 * Size: 737 bytes
 */
#include "magic.h"


LRESULT Ai_Subsystem_004af765
                  (undefined4 arg_1,char *str_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,
                  undefined4 arg_6,undefined4 arg_7,int *arg_8,undefined4 *arg_9,undefined4 arg_10,
                  undefined4 arg_11)

{
  POINT Point;
  POINT Point_00;
  BOOL BVar1;
  tagPOINT local_1e4;
  HWND local_1dc;
  DWORD local_1d8;
  tagPOINT local_1d4;
  HWND local_1cc;
  char local_1c8 [200];
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
  char local_d4 [200];
  undefined4 local_c;
  undefined4 local_8;
  
  if (str_2 == (char *)0x0) {
    strcpy(local_1c8,&DAT_0052d1dc);
  }
  else {
    strcpy(local_1c8,str_2);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (DAT_00696730 != -1) {
    DAT_00696730 = -1;
    BVar1 = IsWindowVisible(DAT_006a284c);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006a283c,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006a284c,(RECT *)0x0,1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  Ai_Subsystem_004cc9c5(0,0xff);
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
  strcpy(local_d4,local_1c8);
  local_d8 = arg_3;
  local_f0 = SendMessageA(g_MainAppHwnd,0x403,(WPARAM)&local_ec,(LPARAM)&local_100);
  *arg_8 = local_100;
  *arg_9 = local_fc;
  arg_9[1] = local_f8;
  Ai_Subsystem_004b553f((char *)0x0);
  if (local_100 != -5) {
    GetCursorPos(&local_1e4);
    Point_00.y = local_1e4.y;
    Point_00.x = local_1e4.x;
    local_1dc = WindowFromPoint(Point_00);
    SendMessageA(local_1dc,0x20,(WPARAM)local_1dc,0x2000001);
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (DAT_0063ee8c == -2) {
      if (DAT_00627a88 == -1) {
        DAT_00696730 = -1;
        DAT_00695ec0 = 0xffffffff;
      }
      else {
        DAT_00695ec0 = DAT_00627a84;
        DAT_00696730 = DAT_00627a88;
      }
    }
    else {
      DAT_00696730 = -1;
      DAT_00695ec0 = 0xffffffff;
    }
    BVar1 = IsWindowVisible(DAT_006a284c);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006a283c,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006a284c,(RECT *)0x0,1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    return local_f0;
  }
  local_1d8 = 0;
  PostMessageA(g_MainAppHwnd,0x401,0,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(local_1d8);
}


