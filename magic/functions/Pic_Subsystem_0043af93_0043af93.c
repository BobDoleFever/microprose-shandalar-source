/*
 * Decompiled function: Pic_Subsystem_0043af93
 * Entry Point: 0043af93
 * Size: 212 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043af93(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    if ((g_ActivePlayerPriority == arg_1) && ((&g_PlayerCreatureCount)[arg_1] == 2)) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0040dcca(arg_1,arg_2,1,1);
      if ((iVar2 == 0) || ((int)(&g_PlayerCreatureCount)[arg_1] < 2)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (arg_3 == 0x6d) {
      Ai_Subsystem_004be192(arg_1,arg_2,1,1);
    }
    if (arg_3 == 0x72) {
      FUN_0046f5d1(arg_1);
      (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + -2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


