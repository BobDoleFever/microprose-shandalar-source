/*
 * Decompiled function: FUN_0047aa7c
 * Entry Point: 0047aa7c
 * Size: 368 bytes
 */
#include "magic.h"


undefined4 FUN_0047aa7c(int arg1,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  int iVar1;
  uint arg_4_00;
  DWORD arg_5_00;
  int *arg_6;
  int arg_7;
  int arg_8;
  int *local_18;
  
  if (arg2 == 0) {
    local_18 = (int *)g_DisplaySurfaceBackBuffer;
  }
  else if (arg2 == 1) {
    local_18 = (int *)g_DisplaySurfaceWork;
  }
  else if (arg2 == 2) {
    local_18 = (int *)g_DisplaySurfaceWork;
  }
  arg_2 = *(uint *)(&DAT_00526150 + arg1 * 0x10);
  arg_3 = *(int *)(&DAT_00526154 + arg1 * 0x10);
  arg_4 = *(uint *)(&DAT_00526158 + arg1 * 0x10);
  arg_5 = *(DWORD *)(&DAT_0052615c + arg1 * 0x10);
  if (arg2 == 2) {
    arg_8 = 0;
    arg_7 = 0;
    arg_4_00 = arg_4;
    arg_5_00 = arg_5;
    arg_6 = (int *)g_DisplaySurfaceBackBuffer;
    iVar1 = Ai_Util_004c3bc4(0x43);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,200,arg_3 - iVar1,arg_4_00,arg_5_00,arg_6,arg_7,
                 arg_8);
    Surface_StretchBlt(local_18,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,4,4,
                       arg_4 - 4,arg_5 - 4);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    FUN_0050e040(local_18,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,arg_2,arg_3);
  }
  return 0;
}


