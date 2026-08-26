/*
 * Decompiled function: Adventure_Audio_PlayEffectAtVolume
 * Entry Point: 004ebd62
 * Size: 104 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayEffectAtVolume(undefined4 arg_1,int y,int width,int height)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_8;
  
  memset(&local_24,0,0x20);
  local_24 = y << 2;
  local_20 = (width * 0x5622) / 100;
  local_1c = height << 2;
  local_8 = local_8 & 0xffffffee;
  Pic_Subsystem_00423bf4(arg_1,&local_24);
  return;
}


