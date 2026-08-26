/*
 * Decompiled function: Card_GenericCreature_TriggerRegen
 * Entry Point: 004d80d3
 * Size: 168 bytes
 */
#include "magic.h"


undefined4 Card_GenericCreature_TriggerRegen(int arg_1,int arg_2,int arg_3)

{
  uint arg_4;
  undefined4 uVar1;
  
  arg_4 = FUN_00473cc5((&DAT_0051aebe)
                       [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34]);
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff690 + arg_4 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_006ff690 + arg_4 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = Card_GenericCreature_Regenerate(arg_1,arg_2,arg_3,arg_4,1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


