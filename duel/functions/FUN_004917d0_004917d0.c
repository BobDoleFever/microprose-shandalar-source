/*
 * Decompiled function: FUN_004917d0
 * Entry Point: 004917d0
 * Size: 289 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004917d0(LPCSTR param_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  bool bVar2;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = FUN_0049198a;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  bVar2 = AVar1 != 0;
  DAT_00618974 = 0;
  DAT_006152f0 = 500;
  _DAT_00664d98 = 10;
  _DAT_0061746c = 0x12;
  DAT_0060ccb8 = 0x14;
  lplf = (LOGFONTA *)FUN_00472731(s_CueCard_005053a0,0);
  DAT_005daf04 = CreateFontIndirectA(lplf);
  DAT_005daf10 = CreateSolidBrush(0x296bed2);
  DAT_005daf0c = CreateSolidBrush(0x27f7f7f);
  DAT_005daf08 = 0x2505050;
  if ((DAT_005daf10 == (HBRUSH)0x0) || (DAT_005daf0c == (HBRUSH)0x0)) {
    bVar2 = false;
  }
  return bVar2;
}


