/*
 * Decompiled function: FUN_0048efc7
 * Entry Point: 0048efc7
 * Size: 231 bytes
 */
#include "magic.h"


undefined4 FUN_0048efc7(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int iVar1;
  
  if (arg_6 != 0) {
    if ((arg_5 << 8) / (int)*(short *)(arg_6 + 6) < (arg_4 << 8) / (int)*(short *)(arg_6 + 4)) {
      iVar1 = (*(short *)(arg_6 + 4) * arg_5) / (int)*(short *)(arg_6 + 6);
      Sprite_DrawScaled(arg_1,arg_2 + (arg_4 - iVar1) / 2,arg_3,iVar1,arg_5,arg_6);
    }
    else {
      iVar1 = (*(short *)(arg_6 + 6) * arg_4) / (int)*(short *)(arg_6 + 4);
      Sprite_DrawScaled(arg_1,arg_2,arg_3 + (arg_5 - iVar1) / 2,arg_4,iVar1,arg_6);
    }
  }
  return 0;
}


