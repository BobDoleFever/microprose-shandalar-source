/*
 * Decompiled function: FUN_0047b0c9
 * Entry Point: 0047b0c9
 * Size: 314 bytes
 */
#include "magic.h"


undefined4 FUN_0047b0c9(int arg1,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  undefined4 *local_8;
  
  if (arg2 == 0) {
    local_8 = &DAT_00676d60;
  }
  else if (arg2 == 1) {
    local_8 = (undefined4 *)&DAT_00676e20;
  }
  else if (arg2 == 2) {
    local_8 = (undefined4 *)&DAT_00676e20;
  }
  arg_2 = *(uint *)(&DAT_00526388 + arg1 * 0x10);
  arg_3 = *(int *)(&DAT_0052638c + arg1 * 0x10);
  arg_4 = *(uint *)(&DAT_00526390 + arg1 * 0x10);
  arg_5 = *(DWORD *)(&DAT_00526394 + arg1 * 0x10);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 2,arg_3 + 2,arg_4 - 4,arg_5 - 4,
                      local_8[arg1]);
    FUN_0050dce0((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,local_8[arg1]);
  }
  return 0;
}


