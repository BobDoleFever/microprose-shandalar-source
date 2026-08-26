/*
 * Decompiled function: Magic_TapCardForMana
 * Entry Point: 004744de
 * Size: 170 bytes
 */
#include "magic.h"


void Magic_TapCardForMana(void)

{
  if (0 < DAT_0052577c) {
    DAT_0052577c = DAT_0052577c + -1;
  }
  g_OverworldPlayerCoordX = *(undefined4 *)(&DAT_00676e40 + DAT_0052577c * 0x28);
  g_OverworldMapGrid = *(undefined4 *)(&DAT_00676e44 + DAT_0052577c * 0x28);
  DAT_006a4f70 = *(undefined4 *)(&DAT_00676e48 + DAT_0052577c * 0x28);
  DAT_006b2fe4 = *(undefined4 *)(&DAT_00676e4c + DAT_0052577c * 0x28);
  DAT_007006c8 = *(undefined4 *)(&DAT_00676e50 + DAT_0052577c * 0x28);
  DAT_006b2d5c = *(undefined4 *)(&DAT_00676e54 + DAT_0052577c * 0x28);
  g_ActivePalette = *(undefined4 *)(&DAT_00676e58 + DAT_0052577c * 0x28);
  return;
}


