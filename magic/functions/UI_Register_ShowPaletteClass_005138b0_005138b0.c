/*
 * Decompiled function: UI_Register_ShowPaletteClass_005138b0
 * Entry Point: 005138b0
 * Size: 121 bytes
 */
#include "magic.h"


void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd)

{
  tagRECT local_10;
  
  local_10.right = 0x100;
  local_10.bottom = 0x100;
  local_10.left = 0;
  local_10.top = 0;
  AdjustWindowRect(&local_10,0xcc0000,0);
  CreateWindowExA(0,s_ShowPaletteClass_005326ac,s_Current_Palette_005326c0,0x80c80000,100,0x32,
                  local_10.right - local_10.left,local_10.bottom - local_10.top,hwnd,(HMENU)0x0,
                  hInstance,(LPVOID)0x0);
  return;
}


