/*
 * Decompiled function: Ai_Subsystem_004cc455
 * Entry Point: 004cc455
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cc455(int *arg_1,int arg_2,undefined4 arg_3,int arg_4,char *str_5)

{
  undefined4 uVar1;
  
  if (g_IsAiThinking == 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = Ai_ScoreCardPlay_004afa69(arg_1,0,arg_2,arg_3,arg_4,str_5);
  }
  return uVar1;
}


