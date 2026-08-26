/*
 * Decompiled function: FUN_00418755
 * Entry Point: 00418755
 * Size: 64 bytes
 */
#include "duel.h"


void FUN_00418755(int arg_1,int arg_2,uint arg_3)

{
  *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
       (-(uint)(DAT_0068eef0 == 0) & 0xffffff00) + 0x200 | arg_3;
  return;
}


