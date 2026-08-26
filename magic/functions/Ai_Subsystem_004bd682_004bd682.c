/*
 * Decompiled function: Ai_Subsystem_004bd682
 * Entry Point: 004bd682
 * Size: 114 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bd682(int arg_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_0052d5cc < 1) {
    uVar1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(int *)(&DAT_00556b28 + (DAT_0052d5cc + -1) * 0x1c + local_8 * 4) =
           *(int *)(&DAT_00556b28 + (DAT_0052d5cc + -1) * 0x1c + local_8 * 4) -
           *(int *)(arg_1 + local_8 * 4);
    }
    uVar1 = 1;
  }
  return uVar1;
}


