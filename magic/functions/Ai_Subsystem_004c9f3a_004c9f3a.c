/*
 * Decompiled function: Ai_Subsystem_004c9f3a
 * Entry Point: 004c9f3a
 * Size: 78 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004c9f3a(int arg1,uint arg2)

{
  undefined4 uVar1;
  
  if ((arg1 == 0) && ((arg2 & 0x100) != 0)) {
    uVar1 = 1;
  }
  else if ((arg1 == 0) || ((arg2 & 0x100) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


