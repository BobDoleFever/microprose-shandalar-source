/*
 * Decompiled function: Minit_Subsystem_0045bc8b
 * Entry Point: 0045bc8b
 * Size: 197 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045bc8b(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int arg_2_00;
  
  if (arg_3 == 0x73) {
    if (((*(byte *)(&DAT_006a2828 + arg_1) & 2) == 0) ||
       (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      arg_2_00 = CardTarget_HasValidCreatureTarget(arg_1);
      if (arg_2_00 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(arg_1,arg_2_00,3);
      }
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(arg_1,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


