/*
 * Decompiled function: FUN_00459143
 * Entry Point: 00459143
 * Size: 117 bytes
 */
#include "duel.h"


undefined4 FUN_00459143(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_004af74c(arg_1,arg_2,3);
    if (0 < *(int *)(&DAT_0068ef50 + iVar1 * 4 + arg_1 * 0x20)) {
      if (arg_3 == 0x32) {
        DAT_0066642c = DAT_0066642c + 1;
      }
      if (arg_3 == 0x33) {
        DAT_0066642c = DAT_0066642c + 2;
      }
    }
  }
  return 0;
}


