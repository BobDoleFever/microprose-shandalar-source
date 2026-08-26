/*
 * Decompiled function: UI_CreateWindow_004386c1
 * Entry Point: 004386c1
 * Size: 176 bytes
 */
#include "duel.h"


undefined4 UI_CreateWindow_004386c1(void)

{
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_CreateWindow_00438771;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(1);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_KimDebug_004f7170;
  RegisterClassA(&local_2c);
  DAT_00694744 = CreateWindowExA(0,s_KimDebug_004f7180,&DAT_004f717c,0x80cc0000,10,10,0xfa,0x113,
                                 DAT_00618990,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  return 1;
}


