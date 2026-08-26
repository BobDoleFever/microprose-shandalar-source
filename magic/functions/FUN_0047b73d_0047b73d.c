/*
 * Decompiled function: FUN_0047b73d
 * Entry Point: 0047b73d
 * Size: 343 bytes
 */
#include "magic.h"


undefined4 FUN_0047b73d(int arg1,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  undefined4 *local_8;
  
  if (arg2 == 0) {
    local_8 = &DAT_00676dd0;
  }
  else if (arg2 == 1) {
    local_8 = &DAT_00676d80;
  }
  else if (arg2 == 2) {
    local_8 = &DAT_00676d80;
  }
  arg_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f0 + arg1 * 0x54) + 0x1d);
  arg_3 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f4 + arg1 * 0x54));
  arg_4 = Ai_Util_004c3bc4(0x4d);
  arg_5 = Ai_Util_004c3bc4(0x5f);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 4,arg_3 + 4,arg_4 - 4,arg_5 - 4,
                      local_8[arg1]);
    FUN_0050dce0((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,local_8[arg1]);
  }
  return 0;
}


