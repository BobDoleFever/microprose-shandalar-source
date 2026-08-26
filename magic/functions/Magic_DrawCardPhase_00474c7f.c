/*
 * Decompiled function: Magic_DrawCardPhase
 * Entry Point: 00474c7f
 * Size: 143 bytes
 */
#include "magic.h"


void Magic_DrawCardPhase(void)

{
  char local_130 [264];
  int local_28;
  uint local_8;
  
  local_8 = local_8 & 0xfffffffb;
  Pic_Subsystem_00423bc7();
  for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
    strcpy(local_130,&DAT_00696910);
    strcat(local_130,&DAT_00525d28);
    strcat(local_130,(&PTR_s_artifact_wav_00525788)[local_28]);
    Pic_Subsystem_00423b57(local_130,local_28,0);
  }
  return;
}


