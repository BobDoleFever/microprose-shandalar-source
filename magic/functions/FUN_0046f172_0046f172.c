/*
 * Decompiled function: FUN_0046f172
 * Entry Point: 0046f172
 * Size: 167 bytes
 */
#include "magic.h"


undefined1 * FUN_0046f172(char *str_1)

{
  if (DAT_00522458 == 0x280) {
    strcpy(&g_OverworldWorldState,&DAT_00525744);
  }
  else if (DAT_00522458 == 800) {
    strcpy(&g_OverworldWorldState,s_spr800__0052574c);
  }
  else if (DAT_00522458 == 0x400) {
    strcpy(&g_OverworldWorldState,s_spr1024__00525754);
  }
  strcat(&g_OverworldWorldState,str_1);
  return &g_OverworldWorldState;
}


