/*
 * Decompiled function: Card_RodOfRuin_EvaluateAi
 * Entry Point: 004e07b5
 * Size: 247 bytes
 */
#include "magic.h"


undefined4 Card_RodOfRuin_EvaluateAi(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       ((*(byte *)(&DAT_006a2828 + arg_1) & 0x40) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0040d875(arg_1,1,(int)(char)(&DAT_0051aec0)[local_8 * 0x34]);
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar1 = 0;
  }
  return uVar1;
}


