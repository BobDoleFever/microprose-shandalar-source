/*
 * Decompiled function: FUN_004ccb93
 * Entry Point: 004ccb93
 * Size: 123 bytes
 */
#include "duel.h"


void FUN_004ccb93(int param_1,int param_2,int param_3)

{
  char cVar1;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    FUN_00434660(s_prompts_txt_00508d04,s_BURROWING_00508cf8);
  }
  cVar1 = FUN_004af74c(param_1,param_2,4);
  FUN_004ce5ce(param_1,param_2,param_3,1 << (cVar1 - 1U & 0x1f));
  return;
}


