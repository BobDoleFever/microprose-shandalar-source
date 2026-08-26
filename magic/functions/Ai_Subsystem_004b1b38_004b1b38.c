/*
 * Decompiled function: Ai_Subsystem_004b1b38
 * Entry Point: 004b1b38
 * Size: 94 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004b1b38(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  undefined4 local_14;
  INT_PTR local_10;
  undefined4 local_c;
  
  if (arg_1 == 0) {
    local_14 = arg_2;
    local_10 = arg_3;
    local_c = 0;
    arg_3 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdc,g_MainAppHwnd,Ai_Subsystem_004b1b9b,
                            (LPARAM)&local_14);
  }
  return arg_3;
}


