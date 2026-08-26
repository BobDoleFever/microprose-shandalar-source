/*
 * Decompiled function: FUN_00418795
 * Entry Point: 00418795
 * Size: 92 bytes
 */
#include "duel.h"


uint FUN_00418795(int arg1,int arg2)

{
  DAT_0068eef0 = (*(int *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20) >> 8) + -1;
  return *(uint *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}


