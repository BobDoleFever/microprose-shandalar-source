/*
 * Decompiled function: SpellChain_RegisterClass
 * Entry Point: 004cd760
 * Size: 673 bytes
 */
#include "magic.h"


undefined4 SpellChain_RegisterClass(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = SpellChain_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = SpellChain_MinimizedWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_SpellMinimized_0052e6e8;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_0056594c = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellChain_pic_0052e6f8);
  DAT_00565984 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellMushrooms_pic_0052e710);
  DAT_0056597c = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellSnails_pic_0052e72c);
  DAT_00565978 = Pic_Load_00423833(local_138);
  DAT_0052e6e4 = 3;
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellMin_pic_0052e744);
  DAT_00565980 = Pic_Load_00423833(local_138);
  SetRect((LPRECT)&DAT_00565968,0,0,0,0);
  DAT_00565948 = CreatePen(0,0,0x1000040);
  DAT_0056598c = CreatePen(0,0,0x1000037);
  DAT_00565950 = CreatePen(0,0,0x1000016);
  DAT_00565988 = CreateSolidBrush(0x1000037);
  DAT_00565944 = 0x1000048;
  if ((((DAT_00565948 == (HPEN)0x0) || (DAT_0056598c == (HPEN)0x0)) || (DAT_00565950 == (HPEN)0x0))
     || (DAT_00565988 == (HBRUSH)0x0)) {
    local_30 = 0;
  }
  return local_30;
}


