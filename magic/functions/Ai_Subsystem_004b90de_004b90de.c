/*
 * Decompiled function: Ai_Subsystem_004b90de
 * Entry Point: 004b90de
 * Size: 60 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b90de(int arg1,int arg2)

{
  char *str_2;
  
  str_2 = (char *)Ai_Subsystem_004b8e4d(arg1,arg2);
  if (str_2 != (char *)0x0) {
    strcat(&g_OverworldWorldState,str_2);
  }
  return;
}


