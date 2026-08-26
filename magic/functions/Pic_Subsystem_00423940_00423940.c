/*
 * Decompiled function: Pic_Subsystem_00423940
 * Entry Point: 00423940
 * Size: 60 bytes
 */
#include "magic.h"


int Pic_Subsystem_00423940(void)

{
  int iVar1;
  
  iVar1 = _read(DAT_00538ae4,&DAT_00706510,0x200);
  DAT_00706500 = &DAT_00706510;
  return iVar1;
}


