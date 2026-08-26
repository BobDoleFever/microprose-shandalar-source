/*
 * Decompiled function: Adventure_Audio_StopAllTracks
 * Entry Point: 004ebebf
 * Size: 44 bytes
 */
#include "magic.h"


void Adventure_Audio_StopAllTracks(void)

{
  if (DAT_0052f014 != 0) {
    Pic_Subsystem_00423c82(0x10);
  }
  DAT_0052f014 = 0;
  return;
}


