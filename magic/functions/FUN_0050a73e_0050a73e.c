/*
 * Decompiled function: FUN_0050a73e
 * Entry Point: 0050a73e
 * Size: 331 bytes
 */
#include "magic.h"


undefined1 * FUN_0050a73e(int arg_1)

{
  int arg_1_00;
  char *str_2;
  
  if ((&DAT_0067bdfc)[arg_1 * 100] == '\0') {
    strcat(&g_OverworldWorldState,&DAT_00532468);
  }
  else {
    arg_1_00 = FUN_00473cc5((byte)*(undefined4 *)(&DAT_0067bdfc + arg_1 * 100));
    str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_1_00);
    strcat(&g_OverworldWorldState,str_2);
  }
  switch(*(int *)(&DAT_0067bdfc + arg_1 * 100) >> 8) {
  case 0:
    strcat(&g_OverworldWorldState,s_cards_0053246c);
    break;
  case 1:
    strcat(&g_OverworldWorldState,s_land_00532474);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_creatures_0053247c);
    break;
  case 3:
    strcat(&g_OverworldWorldState,s_enchantments_00532488);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_sorceries_00532498);
    break;
  case 5:
    strcat(&g_OverworldWorldState,s_fast_effects_005324a4);
    break;
  case 7:
    strcat(&g_OverworldWorldState,s_artifacts_005324b4);
  }
  return &g_OverworldWorldState;
}


