/*
 * Decompiled function: FUN_0046f240
 * Entry Point: 0046f240
 * Size: 181 bytes
 */
#include "duel.h"


byte FUN_0046f240(LPCSTR param_1)

{
  byte bVar1;
  ATOM AVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = FUN_0046f328;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar2 = RegisterClassA(&local_2c);
  uVar8 = 0;
  uVar7 = 0;
  puVar6 = &DAT_00522458;
  uVar5 = 0;
  puVar4 = &DAT_00522448;
  iVar3 = GetSystemMetrics(3);
  bVar1 = FUN_004707f3(1000,iVar3 * 5,puVar4,uVar5,puVar6,uVar7,uVar8);
  return AVar2 != 0 & bVar1;
}


