/*
 * Decompiled function: Pic_Load_advfac64_0047c1fe
 * Entry Point: 0047c1fe
 * Size: 255 bytes
 */
#include "magic.h"


undefined4 Pic_Load_advfac64_0047c1fe(undefined4 *arg_1,int y,int width,int height)

{
  undefined4 uVar1;
  int local_20 [2];
  int local_18;
  uint local_14 [3];
  int local_8;
  
  local_8 = height;
  if (height == 0) {
    uVar1 = 0;
  }
  else {
    Surface_FillRect(arg_1,y,width,*(short *)(height + 4) + 2,*(short *)(height + 6) + 2,0);
    Sprite_DrawDirect(arg_1,y,width,height);
    FUN_00488fdb(arg_1,y,width,(int)*(short *)(local_8 + 4),(int)*(short *)(local_8 + 6),
                 s_pedstls_pic_00526b70,s_advfac64_pic_00526b60);
    FUN_0048ed04(height,local_14,local_20);
    local_18 = (int)*(short *)(local_8 + 0xc);
    uVar1 = Sprite_EncodeFromSurface
                      (*arg_1,y + local_14[0],width + local_18,(local_20[0] - local_14[0]) + 1,
                       (((int)*(short *)(local_8 + 0xc) + (int)*(short *)(local_8 + 0xe)) - local_18
                       ) + 1);
  }
  return uVar1;
}


