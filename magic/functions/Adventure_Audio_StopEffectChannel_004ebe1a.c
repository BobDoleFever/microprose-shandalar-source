/*
 * Decompiled function: Adventure_Audio_StopEffectChannel
 * Entry Point: 004ebe1a
 * Size: 71 bytes
 */
#include "magic.h"


void Adventure_Audio_StopEffectChannel(undefined4 arg_1,int arg_2,int arg_3)

{
  int local_24 [8];
  
  memset(local_24,0,0x20);
  local_24[0] = arg_2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg_3 << 2;
  Pic_Subsystem_00423bf4(arg_1,local_24);
  return;
}


