/*
 * Decompiled function: UI_Register_WINBK_SpellChain_0049f820
 * Entry Point: 0049f820
 * Size: 673 bytes
 */
#include "duel.h"


undefined4 UI_Register_WINBK_SpellChain_0049f820(LPCSTR str_1)

{
  ATOM AVar1;
  uint local_138 [66];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_Register_MAGICGAME_ScrollbarClass_0049fc0f;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
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
  local_2c.lpfnWndProc = UI_WndProc_004a26c6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_SpellMinimized_00505e94;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_005dcd1c = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_SpellChain_pic_00505ea4);
  DAT_005dcd54 = FUN_0043d713((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_SpellMushrooms_pic_00505ebc);
  DAT_005dcd4c = FUN_0043d713((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_SpellSnails_pic_00505ed8);
  DAT_005dcd48 = FUN_0043d713((char *)local_138);
  DAT_00505e90 = 3;
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_SpellMin_pic_00505ef0);
  DAT_005dcd50 = FUN_0043d713((char *)local_138);
  SetRect((LPRECT)&DAT_005dcd38,0,0,0,0);
  DAT_005dcd18 = CreatePen(0,0,0x1000040);
  DAT_005dcd5c = CreatePen(0,0,0x1000037);
  DAT_005dcd20 = CreatePen(0,0,0x1000016);
  DAT_005dcd58 = CreateSolidBrush(0x1000037);
  DAT_005dcd14 = 0x1000048;
  if ((((DAT_005dcd18 == (HPEN)0x0) || (DAT_005dcd5c == (HPEN)0x0)) || (DAT_005dcd20 == (HPEN)0x0))
     || (DAT_005dcd58 == (HBRUSH)0x0)) {
    local_30 = 0;
  }
  return local_30;
}


