/*
 * Decompiled function: UI_Register_FACE_BLACK_00408e20
 * Entry Point: 00408e20
 * Size: 562 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 UI_Register_FACE_BLACK_00408e20(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_004090f6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00538308 = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_MULTI_pic_00516bf8);
  _DAT_00538310 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_BLACK_pic_00516c08);
  _DAT_00538314 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_BLUE_pic_00516c18);
  _DAT_00538318 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_GREEN_pic_00516c28);
  _DAT_0053831c = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_RED_pic_00516c38);
  _DAT_00538320 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__FACE_WHITE_pic_00516c48);
  _DAT_00538324 = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00516c58,0);
  DAT_0053830c = CreateFontIndirectA(lplf);
  DAT_005382f0 = 0x2f6f7f7;
  DAT_005382f4 = 0x2565656;
  return local_30;
}


