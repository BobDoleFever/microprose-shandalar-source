/*
 * Decompiled function: Ai_Subsystem_004b574d
 * Entry Point: 004b574d
 * Size: 252 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b574d(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5,undefined4 arg_6)

{
  int iVar1;
  INT_PTR IVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  if (arg_4 == 0xff) {
    arg_4 = -1;
  }
  if ((arg_1 != -1) && (arg_2 != -1)) {
    iVar1 = Ai_Subsystem_004b5cbb(arg_1,arg_2);
    if (iVar1 == -1) {
      Ai_Subsystem_004b42dc();
    }
  }
  if ((arg_3 != -1) && (arg_4 != -1)) {
    iVar1 = Ai_Subsystem_004b5cbb(arg_3,arg_4);
    if (iVar1 == -1) {
      Ai_Subsystem_004b42dc();
    }
  }
  local_20 = arg_1;
  local_1c = arg_2;
  local_18 = arg_3;
  local_14 = arg_4;
  local_10 = arg_5;
  local_c = arg_6;
  IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdf,g_MainAppHwnd,
                          UI_Register_MAGICGAME_BigCardCardClass_00401000,(LPARAM)&local_20);
  if (IVar2 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = IVar2 + -1;
  }
  return iVar1;
}


