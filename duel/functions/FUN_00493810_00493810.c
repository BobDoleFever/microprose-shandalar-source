/*
 * Decompiled function: FUN_00493810
 * Entry Point: 00493810
 * Size: 1020 bytes
 */
#include "duel.h"


undefined4 FUN_00493810(LPCSTR param_1)

{
  ATOM AVar1;
  undefined1 local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = FUN_00493e30;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 0x801;
  local_2c.lpfnWndProc = FUN_0049866e;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackSwordShield_00505554;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = FUN_0049918f;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackMinimized_00505568;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_005dc2d8 = CreatePopupMenu();
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_Attack_pic_00505578);
  DAT_005dc30c = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_AttackSword_pic_0050558c);
  DAT_005dc2b0 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_AttackShield_pic_005055a4);
  DAT_005dc2e0 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_AttackBones_pic_005055bc);
  DAT_005dc2c0 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_AttackRats_pic_005055d4);
  DAT_005dc2ac = FUN_0043d713(local_138);
  DAT_00505550 = 6;
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_AttackMin_pic_005055ec);
  DAT_005dc2f8 = FUN_0043d713(local_138);
  DAT_005dc2cc = CreatePen(0,0,0x10000b4);
  DAT_005dc2fc = CreatePen(0,0,0x100007c);
  DAT_005dc2b8 = CreatePen(0,0,0x1000050);
  DAT_005dc2d4 = CreateSolidBrush(0x1000076);
  DAT_005dc2e4 = CreatePen(0,0,0x10000d3);
  DAT_005dc2e8 = CreatePen(0,0,0x100002f);
  DAT_005dc2c4 = CreatePen(0,0,0x10000d7);
  DAT_005dc2f4 = CreateSolidBrush(0x100003a);
  DAT_005dc2c8 = 0x10000bf;
  DAT_005dc308 = 0x10000c9;
  if (((((DAT_005dc2cc == (HPEN)0x0) || (DAT_005dc2fc == (HPEN)0x0)) || (DAT_005dc2b8 == (HPEN)0x0))
      || ((DAT_005dc2d4 == (HBRUSH)0x0 || (DAT_005dc2e4 == (HPEN)0x0)))) ||
     ((DAT_005dc2e8 == (HPEN)0x0 || ((DAT_005dc2c4 == (HPEN)0x0 || (DAT_005dc2f4 == (HBRUSH)0x0)))))
     ) {
    local_30 = 0;
  }
  return local_30;
}


