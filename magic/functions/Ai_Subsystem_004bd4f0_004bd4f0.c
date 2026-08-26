/*
 * Decompiled function: Ai_Subsystem_004bd4f0
 * Entry Point: 004bd4f0
 * Size: 110 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bd4f0(void)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_0052d5cc < 10) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_00556b28 + local_8 * 4 + DAT_0052d5cc * 0x1c) = 0;
    }
    DAT_0052d5cc = DAT_0052d5cc + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


