/*
 * Decompiled function: FUN_0045906f
 * Entry Point: 0045906f
 * Size: 212 bytes
 */
#include "duel.h"


undefined4 FUN_0045906f(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x71) {
    iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (iVar1 != -1) {
      *(undefined4 *)(&DAT_006826f0 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x80d;
      *(undefined4 *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar1;
    }
  }
  return 0;
}


