/*
 * Decompiled function: StatWin_PlayVictorySound
 * Entry Point: 100024fd
 * Size: 397 bytes
 */
#include "statwin.h"


void __cdecl StatWin_PlayVictorySound(int arg_1)

{
  int val_1;
  char local_114 [256];
  uint32_t local_14;
  short local_10;
  short local_e;
  int32_t local_c;
  int32_t local_8;
  
  local_14 = (uint32_t)*(uint8_t *)(arg_1 + 0x2d);
  local_8 = 5;
  thunk_FUN_1000432f(local_114,PTR_s___statwin__10011540,
                     (&PTR_s_cball00_avi_100115a8)[*(uint8_t *)(arg_1 + 0x2e)]);
  val_1 = thunk_FUN_100097b0(local_114,&local_c,&local_10,3);
  if (val_1 == 0) {
    thunk_FUN_1000432f(local_114,PTR_DAT_10011544,s_statscrn_wav_10011bb4);
    thunk_FUN_100099ff(*(int32_t *)(DAT_100117a4 + 0xc),local_c);
    thunk_FUN_10009a89(local_c,1);
    local_10 = (short)*(int32_t *)(DAT_100117a4 + 0x14) + DAT_10011554;
    local_e = DAT_10011556 + (short)*(int32_t *)(DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(DAT_10013174,&local_10);
    *DAT_1001e878 = 1;
    thunk_FUN_1000432f(local_114,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
    thunk_FUN_1000308a(local_114);
    thunk_FUN_10009ace(local_c);
    thunk_FUN_10009824(local_c);
    do {
      val_1 = thunk_FUN_10009b0f(local_c);
    } while (val_1 != 0);
    thunk_FUN_10009ace(local_c);
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    thunk_FUN_100097f0(local_c);
    thunk_FUN_100016c1(0xff);
  }
  return;
}


