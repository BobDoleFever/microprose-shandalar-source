/*
 * Decompiled function: FUN_00448d16
 * Entry Point: 00448d16
 * Size: 74 bytes
 */
#include "duel.h"


void FUN_00448d16(undefined4 arg1,undefined4 arg2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_0066aaf4 != 1) {
    local_10 = arg1;
    local_c = arg2;
    DialogBoxParamA(DAT_00664680,(LPCSTR)0xf3,DAT_00618990,Ai_CalcManaRequirement_004b7897,
                    (LPARAM)&local_10);
  }
  return;
}


