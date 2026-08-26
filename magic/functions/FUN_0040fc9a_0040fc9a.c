/*
 * Decompiled function: FUN_0040fc9a
 * Entry Point: 0040fc9a
 * Size: 88 bytes
 */
#include "magic.h"


void FUN_0040fc9a(int arg_1,char *str_2,char *str_3)

{
  uint arg_1_00;
  
  arg_1_00 = *(uint *)(&DAT_005224e8 + arg_1 * 0x10);
  strcpy(str_2,(&PTR_s_Sleight_of_hand_005225d0)[arg_1]);
  g_OverworldWorldState = 0;
  Ai_TownEncounter_004c3b19(arg_1_00);
  strcpy(str_3,&g_OverworldWorldState);
  return;
}


