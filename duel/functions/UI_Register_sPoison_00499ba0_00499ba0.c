/*
 * Decompiled function: UI_Register_sPoison_00499ba0
 * Entry Point: 00499ba0
 * Size: 243 bytes
 */
#include "duel.h"


undefined4 UI_Register_sPoison_00499ba0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_004b9284;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
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
  DAT_005dcaf8 = CreatePopupMenu();
  _sprintf(local_138,s__s_Poison_pic_00505888,&DAT_005f7800);
  DAT_005dcaf4 = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_00472731(&DAT_00505898,0);
  DAT_005dcaf0 = CreateFontIndirectA(lplf);
  DAT_005dcae8 = 0x100004a;
  DAT_005dcaec = 0x10000c9;
  return local_30;
}


