/*
 * Decompiled function: Ai_Subsystem_004b832d
 * Entry Point: 004b832d
 * Size: 234 bytes
 */
#include "magic.h"


undefined4
Ai_Subsystem_004b832d
          (int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 *arg_5,undefined4 *arg_6
          ,undefined4 *arg_7)

{
  undefined4 uVar1;
  INT_PTR IVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (arg_1 == 1) {
    uVar1 = 0;
  }
  else if ((((arg_1 == -1) || (arg_2 == -1)) || (arg_5 == (undefined4 *)0x0)) ||
          ((arg_6 == (undefined4 *)0x0 || (arg_7 == (undefined4 *)0x0)))) {
    uVar1 = 0;
  }
  else {
    local_20 = arg_3;
    local_1c = arg_4;
    local_18 = *arg_5;
    local_14 = *arg_6;
    local_c = Ai_Subsystem_004cbd67(arg_2);
    IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xef,g_MainAppHwnd,Ai_Subsystem_004b8421,
                            (LPARAM)&local_20);
    if (IVar2 == -1) {
      uVar1 = 0;
    }
    else if (IVar2 == -2) {
      uVar1 = 0;
    }
    else {
      *arg_5 = local_18;
      *arg_6 = local_14;
      *arg_7 = local_10;
      uVar1 = 1;
    }
  }
  return uVar1;
}


