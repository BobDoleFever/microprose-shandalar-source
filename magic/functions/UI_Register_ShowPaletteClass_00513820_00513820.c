/*
 * Decompiled function: UI_Register_ShowPaletteClass_00513820
 * Entry Point: 00513820
 * Size: 131 bytes
 */
#include "magic.h"


ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance)

{
  ATOM AVar1;
  WNDCLASSA local_28;
  
  local_28.style = 0x20;
  local_28.hInstance = hInstance;
  local_28.lpfnWndProc = (WNDPROC)&LAB_00513690;
  local_28.cbClsExtra = 0;
  local_28.cbWndExtra = 0;
  local_28.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hbrBackground = CreateSolidBrush(0);
  local_28.lpszMenuName = (LPCSTR)0x0;
  local_28.lpszClassName = s_ShowPaletteClass_005326ac;
  AVar1 = RegisterClassA(&local_28);
  return AVar1;
}


