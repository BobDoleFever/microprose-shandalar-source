/*
 * Decompiled function: Ai_Subsystem_004b3777
 * Entry Point: 004b3777
 * Size: 193 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004b3777(int arg_1,undefined4 *arg_2,undefined4 arg_3,int arg_4,uint arg_5)

{
  INT_PTR IVar1;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (arg_1 == 0) {
    local_1c = arg_3;
    local_18 = arg_4;
    local_14 = arg_5;
    local_10 = *arg_2;
    local_c = arg_2[1];
    IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xea,g_MainAppHwnd,Ai_Subsystem_004b3847,
                            (LPARAM)&local_1c);
    if (IVar1 == -1) {
      IVar1 = -1;
    }
    else if (IVar1 == -2) {
      IVar1 = -1;
    }
  }
  else if (((arg_5 & 0xffff) == 0) && (arg_4 == 0)) {
    IVar1 = 0;
  }
  else {
    IVar1 = 1;
  }
  return IVar1;
}


