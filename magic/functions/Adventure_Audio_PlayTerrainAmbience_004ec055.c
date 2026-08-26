/*
 * Decompiled function: Adventure_Audio_PlayTerrainAmbience
 * Entry Point: 004ec055
 * Size: 680 bytes
 */
#include "magic.h"


void Adventure_Audio_PlayTerrainAmbience(int arg_1)

{
  int arg_1_00;
  int iVar1;
  int iVar2;
  
  arg_1_00 = arg_1 + 9;
  iVar1 = FUN_0040a1d2(200);
  iVar1 = iVar1 + -100;
  iVar2 = FUN_0040a1d2(0x32);
  Adventure_Audio_PlayEffectAtVolume(arg_1_00,100,iVar2 + 0x46,iVar1);
  iVar1 = FUN_0040a1d2(3);
  if (iVar1 == 0) {
    Pic_Subsystem_00423b93(arg_1_00);
    switch(arg_1) {
    case 1:
      iVar1 = FUN_0040a1d2(3);
      if (iVar1 == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kbird1_wav_0052f8d8,arg_1_00,0);
      }
      else if (iVar1 == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kland1_wav_0052f8ec,arg_1_00,0);
      }
      else if (iVar1 == 2) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kland2_wav_0052f900,arg_1_00,0);
      }
      break;
    case 2:
      iVar1 = FUN_0040a1d2(3);
      if (iVar1 == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bbird1_wav_0052f914,arg_1_00,0);
      }
      else if (iVar1 == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bland1_wav_0052f928,arg_1_00,0);
      }
      else if (iVar1 == 2) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bland2_wav_0052f93c,arg_1_00,0);
      }
      break;
    case 3:
      iVar1 = FUN_0040a1d2(2);
      if (iVar1 == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gbird1_wav_0052f950,arg_1_00,0);
      }
      else if (iVar1 == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gland1_wav_0052f964,arg_1_00,0);
      }
      break;
    case 4:
      iVar1 = FUN_0040a1d2(2);
      if (iVar1 == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rbird1_wav_0052f978,arg_1_00,0);
      }
      else if (iVar1 == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rland1_wav_0052f98c,arg_1_00,0);
      }
      break;
    case 5:
      iVar1 = FUN_0040a1d2(2);
      if (iVar1 == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_wbird1_wav_0052f9a0,arg_1_00,0);
      }
      else if (iVar1 == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_wland1_wav_0052f9b4,arg_1_00,0);
      }
    }
  }
  return;
}


