/*
 * Decompiled function: FUN_0045f68c
 * Entry Point: 0045f68c
 * Size: 81 bytes
 */
#include "duel.h"


undefined4 FUN_0045f68c(int arg1,int arg2)

{
  if ((arg2 == DAT_00690c48) && (arg1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 0x2000;
  }
  return 0;
}


