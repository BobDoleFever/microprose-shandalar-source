/*
 * Decompiled function: FUN_004ce553
 * Entry Point: 004ce553
 * Size: 123 bytes
 */
#include "duel.h"


void FUN_004ce553(int param_1,int param_2,int param_3)

{
  char cVar1;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    FUN_00434660(s_prompts_txt_00508da4,s_FISHLIVEROIL_00508d94);
  }
  cVar1 = FUN_004af74c(param_1,param_2,2);
  FUN_004ce5ce(param_1,param_2,param_3,1 << (cVar1 - 1U & 0x1f));
  return;
}


