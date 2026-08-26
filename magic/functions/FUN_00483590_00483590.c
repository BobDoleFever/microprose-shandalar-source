/*
 * Decompiled function: FUN_00483590
 * Entry Point: 00483590
 * Size: 204 bytes
 */
#include "magic.h"


void FUN_00483590(char *str_1,int arg_2,int arg_3)

{
  int y;
  int width;
  int iVar1;
  int arg_4;
  
  y = arg_2 * 2;
  width = arg_3 * 2;
  iVar1 = FUN_0040c465(str_1);
  arg_4 = iVar1 + 0x10;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,(y - arg_4 / 2) + -1,width + -5,iVar1 + 0x11,0x13,
                   0xff);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - arg_4 / 2,width + -4,iVar1 + 0x11,0x12,0xf4);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - arg_4 / 2,width + -4,arg_4,0x11,0xf6);
  FUN_0040c3cc(str_1,y,width,0xe3);
  return;
}


