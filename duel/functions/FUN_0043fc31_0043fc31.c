/*
 * Decompiled function: FUN_0043fc31
 * Entry Point: 0043fc31
 * Size: 298 bytes
 */
#include "duel.h"


void FUN_0043fc31(int arg_1)

{
  int iVar1;
  uint local_918 [75];
  undefined4 local_7ec;
  undefined4 local_7e8;
  undefined4 local_7e4;
  undefined4 local_7e0 [500];
  undefined4 local_10;
  undefined4 local_c;
  
  KillTimer(DAT_00618990,DAT_00663610);
  iVar1 = FUN_00448799(local_7e0,0);
  if (iVar1 == 0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = local_7e0[0];
  }
  iVar1 = FUN_00448799(local_7e0,1);
  if (iVar1 == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_7e0[0];
  }
  if (arg_1 == 0) {
    FUN_00448412((char *)local_918);
    FUN_004d9640(local_918,(uint *)&DAT_004f7c50);
  }
  else if (arg_1 == 1) {
    Mem_AllocOrFree_004d9630(local_918,(uint *)s_You_won__004f7c58);
  }
  else {
    Mem_AllocOrFree_004d9630(local_918,(uint *)s_The_duel_is_a_draw_004f7c64);
  }
  local_7ec = 0;
  local_7e8 = local_c;
  local_7e4 = local_10;
  DialogBoxParamA(DAT_00664680,(LPCSTR)0xf6,DAT_00618990,UI_WndProc_0043fe4c,(LPARAM)local_918);
  return;
}


