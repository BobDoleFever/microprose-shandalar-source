/*
 * Decompiled function: Ai_Subsystem_004cc50a
 * Entry Point: 004cc50a
 * Size: 99 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cc50a(undefined4 arg_1,undefined4 arg_2,char *str_3)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      Sprite_Load_dungbutt_00484738(arg_1,arg_2,str_3);
    }
    else {
      Ai_Subsystem_004b137d(arg_1,-1,-1);
    }
  }
  return;
}


