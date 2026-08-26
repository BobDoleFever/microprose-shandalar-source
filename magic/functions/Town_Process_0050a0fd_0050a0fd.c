/*
 * Decompiled function: Town_Process_0050a0fd
 * Entry Point: 0050a0fd
 * Size: 126 bytes
 */
#include "magic.h"


void Town_Process_0050a0fd(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Adventure_Audio_PlayEffect(s_x_sound_button2_wav_0053234c,0xf,100,100,0);
  Ai_CastleEncounter_004c24b3(0);
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532360 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}


