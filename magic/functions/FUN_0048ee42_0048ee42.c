/*
 * Decompiled function: FUN_0048ee42
 * Entry Point: 0048ee42
 * Size: 389 bytes
 */
#include "magic.h"


undefined4 FUN_0048ee42(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *in_stack_00000018;
  int local_30;
  int local_2c;
  uint local_24;
  int local_20;
  uint local_1c [4];
  int local_c;
  int local_8;
  
  local_c = *in_stack_00000018;
  local_2c = in_stack_00000018[1];
  if (local_c == 0) {
    uVar1 = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,*(short *)(local_c + 4) + 1,
                     *(short *)(local_c + 6) + 1,0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,*in_stack_00000018);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,in_stack_00000018[1]);
    FUN_0048ed04(*in_stack_00000018,local_1c,&local_30);
    FUN_0048ed04(in_stack_00000018[1],&local_24,&local_8);
    if ((int)local_1c[0] <= (int)local_24) {
      local_24 = local_1c[0];
    }
    if (local_8 <= local_30) {
      local_8 = local_30;
    }
    local_30 = local_8;
    if (0xfa < (int)(local_8 - local_24)) {
      local_30 = local_24 + 0xfa;
    }
    local_20 = (int)*(short *)(local_2c + 0xc);
    if ((int)*(short *)(local_c + 0xc) <= (int)*(short *)(local_2c + 0xc)) {
      local_20 = (int)*(short *)(local_c + 0xc);
    }
    iVar2 = (int)*(short *)(local_2c + 0xc) + (int)*(short *)(local_2c + 0xe);
    iVar3 = (int)*(short *)(local_c + 0xc) + (int)*(short *)(local_c + 0xe);
    if (iVar2 <= iVar3) {
      iVar2 = iVar3;
    }
    uVar1 = Sprite_EncodeFromSurface
                      (*(int *)g_DisplaySurfaceWork,local_24,local_20 + 0x80,
                       (local_30 - local_24) + 1,(iVar2 - local_20) + 1);
  }
  return uVar1;
}


