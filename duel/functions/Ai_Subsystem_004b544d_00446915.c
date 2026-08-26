/*
 * Decompiled function: Ai_Subsystem_004b544d
 * Entry Point: 00446915
 * Size: 180 bytes
 */
#include "duel.h"


undefined4 Ai_Subsystem_004b544d(void)

{
  LRESULT LVar1;
  int iVar2;
  int local_c [2];
  
  if ((DAT_0068f0b0 == 0) && (LVar1 = SendMessageA(DAT_00618ab0,0x411,0,0), LVar1 != 0)) {
    if (DAT_006152b4 == 0) {
      do {
        iVar2 = Action_ValidateTarget_0041e2a2
                          (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0x10,
                           s_Choose_defenders_004f7edc,2,local_c);
      } while (iVar2 != 0);
    }
    SendMessageA(DAT_00618ab0,0x412,0,0);
  }
  return 0;
}


