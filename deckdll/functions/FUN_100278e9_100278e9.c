/*
 * Decompiled function: FUN_100278e9
 * Entry Point: 100278e9
 * Size: 279 bytes
 */
#include "deckdll.h"


void FUN_100278e9(void)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  char local_58 [80];
  int local_8;
  
  if ((DAT_1017646c & 1) == 0) {
    local_8 = 0;
    while( true ) {
      uval_1 = clock();
      uval_3 = (int)uval_1 >> 0x1f;
      if ((int)(((uval_1 ^ uval_3) - uval_3 & 0x3ff ^ uval_3) - uval_3) <= local_8) break;
      rand();
      local_8 = local_8 + 1;
    }
    val_2 = rand();
    local_8 = val_2 % 0x13 + 1;
    sprintf(local_58,s_sound_locmus_d_wav_10045e1c,local_8);
    thunk_FUN_10027b96(local_58,1);
    sprintf(local_58,s_DuelSounds_discard_wav_10045e30);
    thunk_FUN_1003b487(local_58,3,0);
    sprintf(local_58,s_DuelSounds_draw_wav_10045e48);
    thunk_FUN_1003b487(local_58,2,0);
    sprintf(local_58,s_DuelSounds_button_wav_10045e5c);
    thunk_FUN_1003b487(local_58,4,0);
    sprintf(local_58,s_DuelSounds_cancel_wav_10045e74);
    thunk_FUN_1003b487(local_58,5,0);
  }
  return;
}


