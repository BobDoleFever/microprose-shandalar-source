/*
 * Decompiled function: FUN_0042024f
 * Entry Point: 0042024f
 * Size: 296 bytes
 */
#include "magic.h"


undefined4 FUN_0042024f(int arg1,int arg2)

{
  int arg_5;
  int arg_4;
  int *arg_6;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  int *local_8;
  
  switch(arg2) {
  case 0:
    local_8 = (int *)&DAT_00538818;
    break;
  case 1:
    local_8 = (int *)&DAT_00538818;
    break;
  case 2:
    local_8 = (int *)&DAT_00538824;
    break;
  case 3:
    local_8 = (int *)&DAT_00538818;
  }
  arg_7 = (&DAT_0051a090)[arg1 * 0x15];
  arg_8 = *(int *)(&DAT_0051a094 + arg1 * 0x54);
  arg_9 = *(int *)(&DAT_0051a098 + arg1 * 0x54);
  arg_10 = *(int *)(&DAT_0051a09c + arg1 * 0x54);
  FUN_0041fffc((int)g_DisplaySurfaceBackBuffer,local_8,0x168,0x1b,&DAT_0067f450 + arg1 * 0x40,4,arg2
              );
  arg_6 = (int *)g_DisplaySurfaceScreen;
  arg_5 = Ai_Util_004c3bc4(0x1a);
  arg_4 = Ai_Util_004c3bc4(0x168);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,
                     arg_10);
  return 0;
}


