/*
 * Decompiled function: Card_HurkylsRecall_ReturnAllArtifacts
 * Entry Point: 004e474e
 * Size: 185 bytes
 */
#include "magic.h"


void Card_HurkylsRecall_ReturnAllArtifacts(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    iVar1 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
    if (iVar1 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      FUN_0046f5d1(arg_1);
    }
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  return;
}


