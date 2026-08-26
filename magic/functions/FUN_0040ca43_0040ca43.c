/*
 * Decompiled function: FUN_0040ca43
 * Entry Point: 0040ca43
 * Size: 268 bytes
 */
#include "magic.h"


void FUN_0040ca43(int arg_1,int arg_2,int arg_3)

{
  int arg_2_00;
  int arg_3_00;
  uint uVar1;
  
  if ((((arg_1 < 0x40) && (-1 < arg_1)) && (arg_2 < 0x40)) && (-1 < arg_2)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40,
                     uVar1 | 1 << ((char)arg_3 - 1U & 0x1f));
    FUN_0040c81c(0x20,arg_1,arg_2);
    arg_2_00 = arg_1 + *(int *)(&DAT_00522378 + arg_3 * 4);
    arg_3_00 = arg_2 + *(int *)(&DAT_005223e0 + arg_3 * 4);
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40,
                     uVar1 | 1 << ((char)arg_3 + 3U & 7));
    FUN_0040c81c(0x20,arg_2_00,arg_3_00);
  }
  return;
}


