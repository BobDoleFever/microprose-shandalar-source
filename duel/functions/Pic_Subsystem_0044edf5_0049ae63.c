/*
 * Decompiled function: Pic_Subsystem_0044edf5
 * Entry Point: 0049ae63
 * Size: 98 bytes
 */
#include "duel.h"


void Pic_Subsystem_0044edf5(LPCSTR str_1)

{
  uint local_10c [66];
  
  Mem_AllocOrFree_004d9630(local_10c,(uint *)&DAT_00615350);
  FUN_004d9640(local_10c,(uint *)s__AUTOSAVE_00505978);
  FUN_004d9640(local_10c,(uint *)&DAT_005dcb31);
  CopyFileA((LPCSTR)local_10c,str_1,0);
  return;
}


