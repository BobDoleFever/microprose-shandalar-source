/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004b6c50
 * Size: 604 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(LPCSTR filepath)

{
  ATOM AVar1;
  LOGFONTA *pLVar2;
  uint local_138 [66];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  DAT_0060cc78 = 2;
  DAT_00601614 = 1;
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_Register_WINBK_TellUser_004b6fea;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(2);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = filepath;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  Mem_AllocOrFree_004d9630(local_138,(uint *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint *)s__WINBK_TellUser_pic_00507048);
  DAT_005dcdf0 = Pic_Load_00423833((char *)local_138);
  FUN_00434660(s_prompts_txt_0050706c,s_BUTTONLABELS_0050705c);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00618960,(uint *)&DAT_006679f0);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00601590,(uint *)&DAT_00667aea);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_TellUser_00507078,0);
  DAT_005dcdc4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_TellUser_00507084,0);
  DAT_005dcdb8 = CreateFontIndirectA(pLVar2);
  DAT_005dcdc8 = CreatePen(0,0,0x10000cb);
  DAT_005dcdf4 = CreatePen(0,0,0x10000cd);
  DAT_005dcdd0 = CreatePen(0,0,0x10000cf);
  DAT_005dcdbc = 0x10000b6;
  DAT_005dcdc0 = 0x10000c9;
  DAT_005dcddc = CreateSolidBrush(0x10000cd);
  DAT_005dcdd4 = CreatePen(0,0,0x10000cb);
  DAT_005dcdcc = CreatePen(0,0,0x10000cf);
  DAT_005dcdd8 = DAT_005dcdbc;
  if (((((DAT_005dcdc4 == (HFONT)0x0) || (DAT_005dcdb8 == (HFONT)0x0)) ||
       (DAT_005dcdc8 == (HPEN)0x0)) || ((DAT_005dcdf4 == (HPEN)0x0 || (DAT_005dcdd0 == (HPEN)0x0))))
     || ((DAT_005dcddc == (HBRUSH)0x0 ||
         ((DAT_005dcdd4 == (HPEN)0x0 || (DAT_005dcdcc == (HPEN)0x0)))))) {
    local_30 = 0;
  }
  return local_30;
}


