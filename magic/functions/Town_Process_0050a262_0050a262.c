/*
 * Decompiled function: Town_Process_0050a262
 * Entry Point: 0050a262
 * Size: 126 bytes
 */
#include "magic.h"


void Town_Process_0050a262(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Adventure_Audio_PlayEffect(s_x_sound_button2_wav_005323bc,0xf,100,100,0);
  FUN_0040a3e1();
  Castle_Process_00421b32();
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323d0 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}


