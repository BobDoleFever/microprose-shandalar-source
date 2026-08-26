/*
 * Decompiled function: Adventure_Audio_InitSoundTrack
 * Entry Point: 004ec5be
 * Size: 156 bytes
 */
#include "magic.h"


undefined4 Adventure_Audio_InitSoundTrack(char *str_1,undefined4 arg_2,undefined4 arg_3)

{
  char cVar1;
  int iVar2;
  
  if (DAT_005659c0 == 0) {
    _getcwd(&DAT_00640f10,0x100);
    DAT_005659c0 = 1;
  }
  if (*str_1 == 'x') {
    *str_1 = DAT_00640f10;
    iVar2 = FUN_00406b01(str_1);
    if (iVar2 == 0) {
      cVar1 = Adventure_Audio_GetMusicDrivePath();
      *str_1 = cVar1;
    }
  }
  do {
  } while (DAT_0062681c != 0);
  Pic_Subsystem_00423b57(str_1,arg_2,arg_3);
  return 0;
}


