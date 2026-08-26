/*
 * Decompiled function: FUN_00465ed2
 * Entry Point: 00465ed2
 * Size: 185 bytes
 */
#include "duel.h"


void FUN_00465ed2(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    iVar1 = FUN_00468a84(arg_1);
    if (iVar1 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      FUN_00487ce1(arg_1);
    }
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  return;
}


