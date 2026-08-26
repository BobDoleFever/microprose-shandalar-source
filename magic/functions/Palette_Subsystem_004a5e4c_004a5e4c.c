/*
 * Decompiled function: Palette_Subsystem_004a5e4c
 * Entry Point: 004a5e4c
 * Size: 304 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a5e4c(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Minit_Subsystem_00452827();
  if (DAT_00522454 == 5) {
    DAT_00522454 = -1;
  }
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    strcat(&g_OverworldWorldState,&DAT_0052c5fc);
    pcVar2 = _itoa(DAT_00522454,&DAT_0054bd58,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,&DAT_0052c600);
    pcVar2 = _itoa(iVar1 + DAT_00627a7c + DAT_006498fc,&DAT_0054bd58,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s___Lives_0052c604);
  }
  if (DAT_00522454 == 0) {
    strcat(&g_OverworldWorldState,s_First_Move_0052c610);
  }
  if (5 < DAT_00522454) {
    strcat(&g_OverworldWorldState,&DAT_0052c61c);
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_00522454 * 0x34);
  }
  return;
}


