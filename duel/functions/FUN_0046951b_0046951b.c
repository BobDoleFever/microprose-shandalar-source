/*
 * Decompiled function: FUN_0046951b
 * Entry Point: 0046951b
 * Size: 249 bytes
 */
#include "duel.h"


int FUN_0046951b(int arg_1,int arg_2,undefined4 arg_3)

{
  int iVar1;
  
  iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_0068f0c4,arg_1,arg_2);
  if (iVar1 != -1) {
    *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x20;
    *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) = arg_3;
    if (arg_1 != 0) {
      *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x1000;
    }
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar1;
  }
  return iVar1;
}


