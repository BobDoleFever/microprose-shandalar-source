/*
 * Decompiled function: Adventure_Audio_GetMusicDrivePath
 * Entry Point: 004ec4fc
 * Size: 113 bytes
 */
#include "magic.h"


char Adventure_Audio_GetMusicDrivePath(void)

{
  char cVar1;
  char local_104 [256];
  
  if (DAT_005659d8 == 0) {
    DAT_00641018 = Adventure_Audio_FindSoundOnDrives(s_sound_locmus1_wav_0052fafc);
    DAT_005659d8 = 1;
  }
  cVar1 = DAT_00641018;
  if (DAT_00626828 == 0) {
    _getcwd(local_104,0x100);
    cVar1 = local_104[0];
  }
  return cVar1;
}


