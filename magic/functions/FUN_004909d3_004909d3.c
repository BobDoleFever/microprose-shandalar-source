/*
 * Decompiled function: FUN_004909d3
 * Entry Point: 004909d3
 * Size: 271 bytes
 */
#include "magic.h"


void FUN_004909d3(int x,undefined4 arg_2,uint width,int height)

{
  char *str_2;
  int iVar1;
  
  strcpy(&g_OverworldWorldState,s_decks_0_00528600);
  if (*(int *)(&DAT_0052262c + x * 0x44) < 100) {
    strcat(&g_OverworldWorldState,&DAT_00528608);
    if (*(int *)(&DAT_0052262c + x * 0x44) < 10) {
      strcat(&g_OverworldWorldState,&DAT_0052860c);
    }
  }
  str_2 = _itoa(*(int *)(&DAT_0052262c + x * 0x44),&DAT_0054aae8,10);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_00528610);
  iVar1 = FUN_00406b01(&g_OverworldWorldState);
  if (iVar1 == 0) {
    FUN_00409f99(s_decks_0179_dck_00528618,1,width,height);
  }
  else {
    FUN_00409f99(&g_OverworldWorldState,1,width,height);
  }
  DAT_0052eff8 = 1;
  return;
}


