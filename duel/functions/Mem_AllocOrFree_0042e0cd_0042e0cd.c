/*
 * Decompiled function: Mem_AllocOrFree_0042e0cd
 * Entry Point: 0042e0cd
 * Size: 47 bytes
 */
#include "duel.h"


bool Mem_AllocOrFree_0042e0cd(void)

{
  int iVar1;
  
  iVar1 = DAT_004f3b2c;
  if (0 < DAT_004f3b2c) {
    DAT_004f3b2c = DAT_004f3b2c + -1;
  }
  return 0 < iVar1;
}


