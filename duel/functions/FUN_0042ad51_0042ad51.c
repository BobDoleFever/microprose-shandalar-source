/*
 * Decompiled function: FUN_0042ad51
 * Entry Point: 0042ad51
 * Size: 207 bytes
 */
#include "duel.h"


void FUN_0042ad51(int arg_1)

{
  bool bVar1;
  int arg2;
  int iVar2;
  
  bVar1 = false;
  while (!bVar1) {
    arg2 = Ai_Subsystem_004bc029(DAT_00676510,DAT_00676510,DAT_00676510,0xff,0,arg_1,2);
    if (DAT_0068f2cc != -3) {
      if (DAT_0068f2cc == -2) {
        bVar1 = true;
      }
      else if (((DAT_0068f2cc == 0) && (arg2 != -1)) &&
              (iVar2 = FUN_0042b120(DAT_0068eef0,arg2), iVar2 != 0)) {
        FUN_0042b213(DAT_0068eef0,arg2);
      }
    }
  }
  return;
}


