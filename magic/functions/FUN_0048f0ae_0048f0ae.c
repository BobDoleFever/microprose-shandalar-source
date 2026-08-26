/*
 * Decompiled function: FUN_0048f0ae
 * Entry Point: 0048f0ae
 * Size: 374 bytes
 */
#include "magic.h"


int FUN_0048f0ae(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = arg_6;
  if (arg_6 == 0) {
    local_1c = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,(int)*(short *)(arg_6 + 4),
                     (int)*(short *)(arg_6 + 6),0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,arg_6);
    FUN_0048ed04(arg_6,&local_18,&local_20);
    local_1c = Sprite_EncodeFromSurface
                         (*(int *)g_DisplaySurfaceWork,local_18,*(short *)(local_8 + 0xc) + 0x80,
                          (local_20 - local_18) + 1,(int)*(short *)(local_8 + 0xe));
    local_14 = local_1c;
    if ((arg_5 << 8) / (int)*(short *)(local_1c + 6) < (arg_4 << 8) / (int)*(short *)(local_1c + 4))
    {
      local_c = (*(short *)(local_1c + 4) * arg_5) / (int)*(short *)(local_1c + 6);
      Sprite_DrawScaled(arg_1,arg_2 + (arg_4 - local_c) / 2,arg_3,local_c,arg_5,local_1c);
    }
    else {
      local_10 = (*(short *)(local_1c + 6) * arg_4) / (int)*(short *)(local_1c + 4);
      Sprite_DrawScaled(arg_1,arg_2,arg_3 + (arg_5 - local_10) / 2,arg_4,local_10,local_1c);
    }
  }
  return local_1c;
}


