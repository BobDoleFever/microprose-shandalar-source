/*
 * Decompiled function: Pic_Subsystem_0044eca0
 * Entry Point: 0044eca0
 * Size: 341 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Subsystem_0044eca0(void)

{
  size_t sVar1;
  char *pcVar2;
  
  DAT_00695e98 = 0xd;
  strcpy(&DAT_00538c20,s___SVG_00523b70);
  strcpy(&DAT_00538c30,s_MTG_Gauntlet_Save_Game_00523b78);
  pcVar2 = &DAT_00538c20;
  sVar1 = strlen(&DAT_00538c30);
  strcat((char *)(sVar1 + 0x538c31),pcVar2);
  pcVar2 = &DAT_00523b90;
  sVar1 = strlen(&DAT_00538c30);
  strcat((char *)(sVar1 + 0x538c31),pcVar2);
  strcpy(&DAT_00538ca8,&DAT_00538c20);
  _DAT_006a2860 = 0x4c;
  _DAT_006a2864 = g_MainAppHwnd;
  _DAT_006a2868 = 0;
  _DAT_006a286c = &DAT_00538c30;
  _DAT_006a2870 = 0;
  _DAT_006a2874 = 0;
  _DAT_006a2878 = 0;
  DAT_006a287c = &DAT_00538ca8;
  _DAT_006a2880 = 0x104;
  _DAT_006a2884 = &DAT_00538c00;
  _DAT_006a2888 = 0x1e;
  _DAT_006a288c = &DAT_006a28c0;
  _DAT_006a2890 = s_Save_Game_00523b94;
  _DAT_006a2894 = 0x2a000c;
  _DAT_006a2898 = 0;
  _DAT_006a289a = 0;
  _DAT_006a289c = &DAT_00538c20;
  _DAT_006a28a0 = 0;
  _DAT_006a28a4 = 0;
  _DAT_006a28a8 = 0;
  return;
}


