/*
 * Decompiled function: FUN_0048d320
 * Entry Point: 0048d320
 * Size: 143 bytes
 */
#include "duel.h"


void FUN_0048d320(void)

{
  uint local_130 [66];
  int local_28;
  uint local_8;
  
  local_8 = local_8 & 0xfffffffb;
  StopSndTrack();
  for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
    Mem_AllocOrFree_004d9630(local_130,(uint *)&DAT_0060d4a0);
    FUN_004d9640(local_130,(uint *)&DAT_004fb0f8);
    FUN_004d9640(local_130,(uint *)(&PTR_s_artifact_wav_004fab58)[local_28]);
    InitSndTrack(local_130,local_28,0);
  }
  return;
}


