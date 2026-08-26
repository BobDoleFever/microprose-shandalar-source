/*
 * Decompiled function: Adventure_Audio_SetPlaybackPosition
 * Entry Point: 004ebe61
 * Size: 94 bytes
 */
#include "magic.h"


void Adventure_Audio_SetPlaybackPosition(char *arg1,undefined4 arg2)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  
  memset(&local_24,0,0x20);
  local_8 = local_8 | 4;
  local_24 = 400;
  local_20 = 0;
  local_1c = 0;
  Adventure_Audio_InitSoundTrack(arg1,arg2,&local_24);
  Pic_Subsystem_00423f10(arg2,1);
  return;
}


