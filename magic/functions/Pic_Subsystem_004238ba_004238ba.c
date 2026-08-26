/*
 * Decompiled function: Pic_Subsystem_004238ba
 * Entry Point: 004238ba
 * Size: 52 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_Subsystem_004238ba(char *str_1,int arg2)

{
  int iVar1;
  
  iVar1 = _open(str_1,arg2);
  _DAT_00538ae8 = 0xffffffff;
  return iVar1;
}


