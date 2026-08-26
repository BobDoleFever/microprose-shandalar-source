/*
 * Decompiled function: Ai_Subsystem_004ae8a3
 * Entry Point: 004ae8a3
 * Size: 242 bytes
 */
#include "magic.h"


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
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  iVar1 = Ai_Subsystem_004b72d0(local_7e0,0);
  if (iVar1 == 0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = local_7e0[0];
  }
  iVar1 = Ai_Subsystem_004b72d0(local_7e0,1);
  if (iVar1 == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_7e0[0];
  }
  sprintf(local_918,s__s_That_was_round__d_Your_record_0052d158,arg_1,arg_2,arg_3,arg_4,arg_5);
  local_7ec = 1;
  local_7e8 = local_c;
  local_7e4 = local_10;
  IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf6,g_MainAppHwnd,Ai_DuelMainWndProc,
                          (LPARAM)local_918);
  return IVar2;
}


