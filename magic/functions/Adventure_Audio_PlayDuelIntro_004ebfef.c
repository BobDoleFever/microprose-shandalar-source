/*
 * Decompiled function: Adventure_Audio_PlayDuelIntro
 * Entry Point: 004ebfef
 * Size: 102 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayDuelIntro(int arg_1)

{
  if (DAT_0052f018 != -1) {
    Pic_Subsystem_00423b93(0x10);
  }
  DAT_0052f018 = 0x15;
  DAT_0052f064 = 0xffffffff;
  Adventure_Audio_SetPlaybackPosition((&PTR_s_x_sound_dueltune_wav_0052f070)[arg_1],0x10);
  Adventure_Audio_StopEffectChannel(0x10,0x80,0);
  DAT_0052f014 = 1;
  return;
}


