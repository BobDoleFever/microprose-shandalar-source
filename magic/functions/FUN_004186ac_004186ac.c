/*
 * Decompiled function: FUN_004186ac
 * Entry Point: 004186ac
 * Size: 126 bytes
 */
#include "magic.h"


bool FUN_004186ac(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == g_CurrentTurnPhase) {
      bVar1 = true;
    }
    else {
      bVar1 = arg_1 != g_DefendingPlayer;
    }
  }
  else {
    if (arg_3 == 0x71) {
      CardQuery_ForEachPermanent(FUN_0041872f,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    bVar1 = false;
  }
  return bVar1;
}


