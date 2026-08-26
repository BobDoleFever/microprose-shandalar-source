/*
 * Decompiled function: Adventure_Audio_PlayCastleVictory
 * Entry Point: 004ebeeb
 * Size: 231 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayCastleVictory(int arg_1)

{
  Adventure_Audio_StopAllTracks();
  if (DAT_0052f018 != -1) {
    Pic_Subsystem_00423b93(0x10);
  }
  DAT_0052f018 = arg_1 + 0x15;
  switch(arg_1) {
  case 1:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_bcastle_wav_0052f860,0x10);
    break;
  case 2:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_ucastle_wav_0052f874,0x10);
    break;
  case 3:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_gcastle_wav_0052f888,0x10);
    break;
  case 4:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_rcastle_wav_0052f89c,0x10);
    break;
  case 5:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_wcastle_wav_0052f8b0,0x10);
    break;
  case 6:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_wingame_wav_0052f8c4,0x10);
  }
  Adventure_Audio_PlayEffectLooped(0x10,100,0);
  DAT_0052f014 = 1;
  return;
}


