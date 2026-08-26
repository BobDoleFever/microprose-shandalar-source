/*
 * Decompiled function: Adventure_Audio_PlayEffectLooped
 * Entry Point: 004ebdca
 * Size: 80 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayEffectLooped(undefined4 arg_1,int arg_2,int arg_3)

{
  int local_24 [7];
  uint local_8;
  
  memset(local_24,0,0x20);
  local_24[0] = arg_2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg_3 << 2;
  local_8 = local_8 | 1;
  Pic_Subsystem_00423bf4(arg_1,local_24);
  return;
}


