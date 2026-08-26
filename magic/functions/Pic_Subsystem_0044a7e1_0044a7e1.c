/*
 * Decompiled function: Pic_Subsystem_0044a7e1
 * Entry Point: 0044a7e1
 * Size: 83 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0044a7e1(int arg_1)

{
  undefined4 uVar1;
  int local_7d8;
  undefined1 local_7d4 [2000];
  
  local_7d8 = Ai_Subsystem_004b718a(local_7d4,arg_1);
  if (local_7d8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(local_7d4 + local_7d8 * 4 + -4);
  }
  return uVar1;
}


