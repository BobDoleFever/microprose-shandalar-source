/*
 * Decompiled function: Ai_Subsystem_004b544d
 * Entry Point: 004b544d
 * Size: 180 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b544d(void)

{
  LRESULT LVar1;
  int iVar2;
  int local_c [2];
  
  if ((DAT_006fedc0 == 0) && (LVar1 = SendMessageA(DAT_006b3064,0x411,0,0), LVar1 != 0)) {
    if (DAT_0069f6d0 == 0) {
      do {
        iVar2 = Action_ValidateTarget_00405802
                          (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0x10,
                           s_Choose_defenders_0052d3bc,2,local_c);
      } while (iVar2 != 0);
    }
    SendMessageA(DAT_006b3064,0x412,0,0);
  }
  return 0;
}


