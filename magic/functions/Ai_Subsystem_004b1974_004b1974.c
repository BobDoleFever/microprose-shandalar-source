/*
 * Decompiled function: Ai_Subsystem_004b1974
 * Entry Point: 004b1974
 * Size: 87 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004b1974(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  undefined4 local_10;
  INT_PTR local_c;
  
  if (arg_1 == 0) {
    local_10 = arg_2;
    local_c = arg_3;
    arg_3 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe5,g_MainAppHwnd,Ai_Subsystem_004b19d0,
                            (LPARAM)&local_10);
  }
  return arg_3;
}


