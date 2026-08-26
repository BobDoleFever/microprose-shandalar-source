/*
 * Decompiled function: Ai_Subsystem_004cc814
 * Entry Point: 004cc814
 * Size: 107 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004cc814
                  (int arg_1,char *str_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      arg_3 = FUN_004854a4(arg_1,str_2,arg_3);
    }
    else {
      arg_3 = Ai_Subsystem_004b1416(arg_1,str_2,arg_3,str_4,str_5,str_6);
    }
  }
  return arg_3;
}


