/*
 * Decompiled function: CardTarget_HasValidPermanentTarget
 * Entry Point: 004e701f
 * Size: 142 bytes
 */
#include "magic.h"


undefined4 CardTarget_HasValidPermanentTarget(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  iVar1 = Action_ValidateTarget_00405802
                    (arg_1,arg_1,arg_1,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,0,&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      Magic_UpkeepPhase(0xf);
    }
    Pic_Subsystem_0044867e(local_c,local_8,3);
    uVar2 = 1;
  }
  return uVar2;
}


