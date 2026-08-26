/*
 * Decompiled function: Adventure_Audio_PlayEffect
 * Entry Point: 004ebcdc
 * Size: 134 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayEffect(char *arg_1,undefined4 arg_2,int arg_3,int arg_4,int arg_5)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_8;
  
  Pic_Subsystem_00423b93(arg_2);
  Adventure_Audio_InitSoundTrack(arg_1,arg_2,0);
  memset(&local_24,0,0x20);
  local_24 = arg_3 << 2;
  local_20 = (arg_4 * 0x5622) / 100;
  local_1c = arg_5 << 2;
  local_8 = local_8 & 0xffffffee;
  Pic_Subsystem_00423bf4(arg_2,&local_24);
  return;
}


