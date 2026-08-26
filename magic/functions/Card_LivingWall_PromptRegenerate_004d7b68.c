/*
 * Decompiled function: Card_LivingWall_PromptRegenerate
 * Entry Point: 004d7b68
 * Size: 77 bytes
 */
#include "magic.h"


undefined4 Card_LivingWall_PromptRegenerate(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = Card_GenericCreature_Regenerate(arg_1,arg_2,arg_3,2,3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


