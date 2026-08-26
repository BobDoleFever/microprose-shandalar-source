/*
 * Decompiled function: FUN_00467e37
 * Entry Point: 00467e37
 * Size: 184 bytes
 */
#include "duel.h"


void FUN_00467e37(int arg1,int arg2)

{
  if (((&DAT_0068270c)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (*(uint *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) =
           *(int *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) + 1U & 0xff |
           *(uint *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00, DAT_0066aaf4 != 1))
  {
    FUN_0048d00c(0x1b);
  }
  return;
}


