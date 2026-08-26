/*
 * Decompiled function: FUN_0050b1a0
 * Entry Point: 0050b1a0
 * Size: 102 bytes
 */
#include "magic.h"


void FUN_0050b1a0(void)

{
  char *str_2;
  
  str_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_005324e0);
  FUN_00484c45(1 << ((byte)DAT_00522450 & 3));
  strcat(&g_OverworldWorldState,s_spell_005324e4);
  return;
}


