/*
 * Decompiled function: Prompts_Load_00476e60
 * Entry Point: 00476e60
 * Size: 604 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00476e60(LPCSTR filepath)

{
  ATOM AVar1;
  LOGFONTA *pLVar2;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  DAT_00695ecc = 2;
  DAT_0068a710 = 1;
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_Register_WINBK_TellUser_004771fa;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(2);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = filepath;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_TellUser_pic_00525d2c);
  DAT_00538e40 = Pic_Load_00423833(local_138);
  Pic_Subsystem_00424500(s_prompts_txt_00525d50,s_BUTTONLABELS_00525d40);
  strcpy(&DAT_006b2d70,&g_OverworldGoldAmount);
  strcpy(&DAT_0068a680,&DAT_0069f84a);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d5c,0);
  DAT_00538e14 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d68,0);
  DAT_00538e08 = CreateFontIndirectA(pLVar2);
  DAT_00538e18 = CreatePen(0,0,0x10000cb);
  DAT_00538e44 = CreatePen(0,0,0x10000cd);
  DAT_00538e20 = CreatePen(0,0,0x10000cf);
  DAT_00538e0c = 0x10000b6;
  DAT_00538e10 = 0x10000c9;
  DAT_00538e2c = CreateSolidBrush(0x10000cd);
  DAT_00538e24 = CreatePen(0,0,0x10000cb);
  DAT_00538e1c = CreatePen(0,0,0x10000cf);
  DAT_00538e28 = DAT_00538e0c;
  if (((((DAT_00538e14 == (HFONT)0x0) || (DAT_00538e08 == (HFONT)0x0)) ||
       (DAT_00538e18 == (HPEN)0x0)) || ((DAT_00538e44 == (HPEN)0x0 || (DAT_00538e20 == (HPEN)0x0))))
     || ((DAT_00538e2c == (HBRUSH)0x0 ||
         ((DAT_00538e24 == (HPEN)0x0 || (DAT_00538e1c == (HPEN)0x0)))))) {
    local_30 = 0;
  }
  return local_30;
}


