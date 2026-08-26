/*
 * Decompiled function: Ai_Subsystem_004cc49a
 * Entry Point: 004cc49a
 * Size: 71 bytes
 */
#include "magic.h"


undefined4
Ai_Subsystem_004cc49a(int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,char *str_6)

{
  undefined4 uVar1;
  
  if (g_IsAiThinking == 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = Ai_ScoreCardPlay_004afa69(arg_1,arg_2,arg_3,arg_4,arg_5,str_6);
  }
  return uVar1;
}


