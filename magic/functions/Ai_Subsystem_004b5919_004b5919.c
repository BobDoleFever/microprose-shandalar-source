/*
 * Decompiled function: Ai_Subsystem_004b5919
 * Entry Point: 004b5919
 * Size: 78 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b5919(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if ((arg1 == 0) || (arg1 == 1)) {
    if ((arg2 < 0) || (0x50 < arg2)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


