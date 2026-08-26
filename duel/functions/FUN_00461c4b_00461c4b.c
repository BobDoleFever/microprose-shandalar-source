/*
 * Decompiled function: FUN_00461c4b
 * Entry Point: 00461c4b
 * Size: 194 bytes
 */
#include "duel.h"


undefined4 FUN_00461c4b(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x79) {
    iVar1 = FUN_004af74c(arg_1,arg_2,4);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + (1 - arg_1) * 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  if ((arg_3 == 0x1a) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    FUN_004a2b00(arg_1,arg_2,DAT_006664e8,arg_1,arg_2);
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  return 0;
}


