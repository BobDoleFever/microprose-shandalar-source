/*
 * Decompiled function: Ai_CalcManaRequirement_004b9120
 * Entry Point: 0044a5e0
 * Size: 238 bytes
 */
#include "duel.h"


undefined4 Ai_CalcManaRequirement_004b9120(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  uint local_138 [66];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_004b9284;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
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
  DAT_00516b48 = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_ManaPool_pic_004f7ff4);
  DAT_00516b50 = Pic_Load_00423833((char *)local_138);
  lplf = (LOGFONTA *)FUN_00472731(s_ManaPool_004f8008,0);
  DAT_00516b4c = CreateFontIndirectA(lplf);
  return local_30;
}


