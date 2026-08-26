/*
 * Decompiled function: FUN_00467eef
 * Entry Point: 00467eef
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_00467eef(int arg1,int arg2)

{
  *(uint *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) - 1U & 0xff |
       *(uint *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00;
  return;
}


