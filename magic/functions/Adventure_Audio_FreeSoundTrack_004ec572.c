/*
 * Decompiled function: Adventure_Audio_FreeSoundTrack
 * Entry Point: 004ec572
 * Size: 76 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Adventure_Audio_FreeSoundTrack(void *arg_1)

{
  _DAT_00640f0c = _DAT_00640f0c + 1;
  Pic_Subsystem_00423b57(arg_1,*(undefined4 *)((int)arg_1 + 0x100),(int)arg_1 + 0x104);
  free(arg_1);
  _DAT_00640f0c = _DAT_00640f0c + -1;
  return;
}


