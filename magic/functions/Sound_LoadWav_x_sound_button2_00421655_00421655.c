/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_00421655
 * Entry Point: 00421655
 * Size: 144 bytes
 */
#include "magic.h"


undefined4 Sound_LoadWav_x_sound_button2_00421655(int arg_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(arg_1 + 0x2c) - 0xf;
  if (((*(int *)(arg_1 + 0x2c) < 0xf) || ((int)uVar1 < 2)) || ((uVar1 & 1) != 0)) {
    Adventure_Audio_PlayEffect(s_x_sound_button2_wav_0051ac88,0xf,100,100,0);
  }
  else {
    Adventure_Audio_PlayEffect
              ((&PTR_s_x_sound_blackwm_wav_00519fe0)[(*(int *)(arg_1 + 0x2c) + -0x11) / 2],0xf,100,
               100,0);
  }
  DAT_00538a28 = *(undefined4 *)(arg_1 + 0x2c);
  return *(undefined4 *)(arg_1 + 0x2c);
}


