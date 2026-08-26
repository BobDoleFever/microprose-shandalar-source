/*
 * Decompiled function: FUN_0041ec8d
 * Entry Point: 0041ec8d
 * Size: 87 bytes
 */
#include "magic.h"


undefined4 FUN_0041ec8d(int arg_1)

{
  FUN_0040a3e1();
  if (DAT_00640f08 == 0) {
    DAT_00640f08 = *(int *)(arg_1 + 0x2c);
  }
  DAT_007039c4 = 0;
  Adventure_Audio_PlayEffect
            (*(undefined4 *)(&DAT_00519f1c + *(int *)(arg_1 + 0x2c) * 4),0xf,100,100,0);
  return 0;
}


