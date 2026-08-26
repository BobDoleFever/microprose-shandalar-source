/*
 * Decompiled function: UI_Register_WINBK_Attack_0047d460
 * Entry Point: 0047d460
 * Size: 1020 bytes
 */
#include "magic.h"


undefined4 UI_Register_WINBK_Attack_0047d460(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_Register_MAGICGAME_CardClass_0047da80;
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
  local_2c.style = 0x801;
  local_2c.lpfnWndProc = UI_WndProc_004822b7;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackSwordShield_00526c2c;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_WndProc_00482dd6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackMinimized_00526c40;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_0053955c = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_Attack_pic_00526c50);
  DAT_00539590 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackSword_pic_00526c64);
  DAT_00539534 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackShield_pic_00526c7c);
  DAT_00539564 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackBones_pic_00526c94);
  DAT_00539544 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackRats_pic_00526cac);
  DAT_00539530 = Pic_Load_00423833(local_138);
  DAT_00526c28 = 6;
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackMin_pic_00526cc4);
  DAT_0053957c = Pic_Load_00423833(local_138);
  DAT_00539550 = CreatePen(0,0,0x10000b4);
  DAT_00539580 = CreatePen(0,0,0x100007c);
  DAT_0053953c = CreatePen(0,0,0x1000050);
  DAT_00539558 = CreateSolidBrush(0x1000076);
  DAT_00539568 = CreatePen(0,0,0x10000d3);
  DAT_0053956c = CreatePen(0,0,0x100002f);
  DAT_00539548 = CreatePen(0,0,0x10000d7);
  DAT_00539578 = CreateSolidBrush(0x100003a);
  DAT_0053954c = 0x10000bf;
  DAT_0053958c = 0x10000c9;
  if (((((DAT_00539550 == (HPEN)0x0) || (DAT_00539580 == (HPEN)0x0)) || (DAT_0053953c == (HPEN)0x0))
      || ((DAT_00539558 == (HBRUSH)0x0 || (DAT_00539568 == (HPEN)0x0)))) ||
     ((DAT_0053956c == (HPEN)0x0 || ((DAT_00539548 == (HPEN)0x0 || (DAT_00539578 == (HBRUSH)0x0)))))
     ) {
    local_30 = 0;
  }
  return local_30;
}


