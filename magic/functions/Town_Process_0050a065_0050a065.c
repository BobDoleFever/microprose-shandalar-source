/*
 * Decompiled function: Town_Process_0050a065
 * Entry Point: 0050a065
 * Size: 152 bytes
 */
#include "magic.h"


void Town_Process_0050a065(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Adventure_Audio_PlayEffect(s_x_sound_button2_wav_00532320,0xf,100,100,0);
  FUN_005112b0(0,(short)DAT_00530d9c);
  DeckBuilderMain(_hwndScreen,1,3);
  Pic_Load_advfac64_0040a4fc();
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532334 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}


