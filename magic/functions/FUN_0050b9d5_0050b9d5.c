/*
 * Decompiled function: FUN_0050b9d5
 * Entry Point: 0050b9d5
 * Size: 442 bytes
 */
#include "magic.h"


void FUN_0050b9d5(int *arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int arg_2;
  int local_3c [4];
  int local_2c [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = DAT_00677e10;
  if (DAT_00522458 == 0x280) {
    local_1c = 0;
  }
  else if (DAT_00522458 == 800) {
    local_1c = 1;
  }
  else if (DAT_00522458 == 0x400) {
    local_1c = 2;
  }
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3bc4(0x30);
  iVar4 = Ai_Util_004c3bc4(0x40);
  piVar5 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceScreen,iVar4,iVar3,iVar2,iVar1);
  local_14 = *piVar5;
  local_10 = piVar5[1];
  local_c = piVar5[2];
  local_8 = piVar5[3];
  iVar1 = DAT_00677e10;
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_18 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_18 + 4));
  iVar4 = Ai_Util_004c3bc4(0x135);
  arg_2 = Ai_Util_004c3bc4(0x181);
  Sprite_DrawScaled(arg_1,arg_2,iVar4,iVar3,iVar2,iVar1);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_005318e8 + local_1c * 4),
                    *(int *)(&DAT_005318f8 + local_1c * 4),DAT_00677fb0);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_00531908 + local_1c * 4),
                    *(int *)(&DAT_00531920 + local_1c * 4),DAT_00677fe4);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_00531914 + local_1c * 4),
                    *(int *)(&DAT_00531920 + local_1c * 4),DAT_00677fe4);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceScreen,local_14,local_10,local_c,local_8);
  return;
}


