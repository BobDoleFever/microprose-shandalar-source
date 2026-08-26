/*
 * Decompiled function: Ai_Subsystem_004ae8a3
 * Entry Point: 0043fd5b
 * Size: 241 bytes
 */
#include "duel.h"


INT_PTR Ai_Subsystem_004ae8a3
                  (undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,
                  undefined4 arg_5)

{
  int iVar1;
  INT_PTR IVar2;
  char local_918 [300];
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
  _sprintf(local_918,s__s_That_was_round__d_Your_record_004f7c78,arg_1,arg_2,arg_3,arg_4,arg_5);
  local_7ec = 1;
  local_7e8 = local_c;
  local_7e4 = local_10;
  IVar2 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf6,DAT_00618990,Ai_DuelMainWndProc,
                          (LPARAM)local_918);
  return IVar2;
}


