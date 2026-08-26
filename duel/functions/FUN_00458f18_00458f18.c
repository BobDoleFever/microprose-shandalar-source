/*
 * Decompiled function: FUN_00458f18
 * Entry Point: 00458f18
 * Size: 274 bytes
 */
#include "duel.h"


undefined4 FUN_00458f18(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x71) {
    iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (iVar1 != -1) {
      *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(undefined4 *)(&DAT_006826f0 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x20f;
      *(undefined4 *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar1;
    }
  }
  return 0;
}


