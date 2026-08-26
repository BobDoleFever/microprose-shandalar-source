/*
 * Decompiled function: UI_Register_sPoison_0047c640
 * Entry Point: 0047c640
 * Size: 244 bytes
 */
#include "magic.h"


undefined4 UI_Register_sPoison_0047c640(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0047c7aa;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
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
  DAT_00539518 = CreatePopupMenu();
  sprintf(local_138,s__s_Poison_pic_00526b80,&DAT_006808d0);
  DAT_00539514 = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00526b90,0);
  DAT_00539510 = CreateFontIndirectA(lplf);
  DAT_00539508 = 0x100004a;
  DAT_0053950c = 0x10000c9;
  return local_30;
}


