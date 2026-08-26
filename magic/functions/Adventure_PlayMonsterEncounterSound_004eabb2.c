/*
 * Decompiled function: Adventure_PlayMonsterEncounterSound
 * Entry Point: 004eabb2
 * Size: 340 bytes
 */
#include "magic.h"


void Adventure_PlayMonsterEncounterSound(int x,int arg_2,int arg_3,int height)

{
  if (DAT_0052f068 == 0) {
    Pic_Subsystem_00423b93(0xf);
  }
  DAT_0052f068 = 0;
  switch((&DAT_0052262a)[x * 0x44]) {
  case 1:
    Adventure_Audio_InitSoundTrack(s_x_sound_malewiz_wav_0052f434,0xf,0);
    break;
  case 2:
    Adventure_Audio_InitSoundTrack(s_x_sound_fewiz_wav_0052f448,0xf,0);
    break;
  case 3:
    Adventure_Audio_InitSoundTrack(s_x_sound_knight_wav_0052f45c,0xf,0);
    break;
  case 4:
    Adventure_Audio_InitSoundTrack(s_x_sound_lord_wav_0052f470,0xf,0);
    break;
  case 5:
    Adventure_Audio_InitSoundTrack(s_x_sound_djinn_wav_0052f484,0xf,0);
    break;
  case 6:
    Adventure_Audio_InitSoundTrack(s_x_sound_troll_wav_0052f498,0xf,0);
    break;
  case 7:
    Adventure_Audio_InitSoundTrack(s_x_sound_wyrm_wav_0052f4ac,0xf,0);
    break;
  case 8:
    Adventure_Audio_InitSoundTrack(s_x_sound_dragon_wav_0052f4c0,0xf,0);
    break;
  case 9:
    Adventure_Audio_InitSoundTrack(s_x_sound_flyer_wav_0052f4d4,0xf,0);
    break;
  case 10:
    Adventure_Audio_InitSoundTrack(s_x_sound_archmage_wav_0052f4e8,0xf,0);
  }
  Adventure_Audio_PlayEffectAtVolume(0xf,arg_2,arg_3,-height);
  return;
}


