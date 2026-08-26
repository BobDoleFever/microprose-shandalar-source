/*
 * Decompiled function: FUN_00467f65
 * Entry Point: 00467f65
 * Size: 186 bytes
 */
#include "duel.h"


void FUN_00467f65(int arg_1,int arg_2,int arg_3)

{
  if (((&DAT_0068270c)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) &&
     (*(uint *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) + arg_3 & 0xffU |
           *(uint *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffff00, DAT_0066aaf4 != 1
     )) {
    FUN_0048d00c(0x1b);
  }
  return;
}


