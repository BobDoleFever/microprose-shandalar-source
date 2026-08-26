/*
 * Decompiled function: Ai_Subsystem_004cc8de
 * Entry Point: 004cc8de
 * Size: 95 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004cc8de(int arg_1,char *str_2,INT_PTR arg_3)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      arg_3 = FUN_00485605(arg_1,str_2,arg_3);
    }
    else {
      arg_3 = Ai_Subsystem_004b1b38(arg_1,str_2,arg_3);
    }
  }
  return arg_3;
}


