/*
 * Decompiled function: Minit_Subsystem_0045d842
 * Entry Point: 0045d842
 * Size: 77 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045d842(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = Card_GenericCreature_Regenerate(arg_1,arg_2,arg_3,0,2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


