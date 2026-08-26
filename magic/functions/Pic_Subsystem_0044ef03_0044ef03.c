/*
 * Decompiled function: Pic_Subsystem_0044ef03
 * Entry Point: 0044ef03
 * Size: 98 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044ef03(LPCSTR str_1)

{
  char local_10c [264];
  
  strcpy(local_10c,&DAT_006a28c0);
  strcat(local_10c,s__AUTOSAVE_00523bb8);
  strcat(local_10c,&DAT_00538c21);
  CopyFileA(local_10c,str_1,0);
  return;
}


