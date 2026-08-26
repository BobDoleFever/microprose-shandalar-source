/*
 * Decompiled function: Palette_Subsystem_004989a9
 * Entry Point: 004989a9
 * Size: 111 bytes
 */
#include "magic.h"


void Palette_Subsystem_004989a9(int x,int y,int width,undefined4 arg_4)

{
  char *str_2;
  
  g_OverworldWorldState = 0;
  str_2 = _itoa((x * 100) / DAT_0054b348,&DAT_0054b350,10);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_0052b940);
  FUN_0040c2e9(&g_OverworldWorldState,y,width,arg_4);
  return;
}


