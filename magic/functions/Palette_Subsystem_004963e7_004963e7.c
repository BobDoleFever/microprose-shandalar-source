/*
 * Decompiled function: Palette_Subsystem_004963e7
 * Entry Point: 004963e7
 * Size: 176 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004963e7(void)

{
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = Palette_Subsystem_00496497;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(1);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_KimDebug_0052b708;
  RegisterClassA(&local_2c);
  DAT_0064a0bc = CreateWindowExA(0,s_KimDebug_0052b718,&DAT_0052b714,0x80cc0000,10,10,0xfa,0x113,
                                 g_MainAppHwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  return 1;
}


