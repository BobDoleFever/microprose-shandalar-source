/*
 * Decompiled function: FUN_00479ff9
 * Entry Point: 00479ff9
 * Size: 707 bytes
 */
#include "magic.h"


undefined4 FUN_00479ff9(int arg1,int arg2)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int arg_2;
  int arg_3;
  int *piVar5;
  int arg_5;
  int local_18;
  int local_14;
  undefined4 *local_8;
  
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  iVar2 = *(int *)(&DAT_00525f34 + arg1 * 0x10);
  iVar3 = *(int *)(&DAT_00525f30 + arg1 * 0x10);
  piVar5 = (int *)g_DisplaySurfaceBackBuffer;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  FUN_0050dce0((int *)g_DisplaySurfaceWork,*(uint *)(&DAT_00525f30 + arg1 * 0x10),
               *(int *)(&DAT_00525f34 + arg1 * 0x10),
               DAT_00522458 - *(int *)(&DAT_00525f30 + arg1 * 0x10),DVar1,piVar5,iVar3,iVar2);
  switch(arg1) {
  case 0:
    local_8 = &DAT_005394d8;
    break;
  case 1:
    local_8 = (undefined4 *)&DAT_005394b0;
    break;
  case 2:
    local_8 = (undefined4 *)&DAT_005394f8;
    break;
  case 3:
    local_8 = (undefined4 *)&DAT_00539188;
  }
  switch(arg2) {
  case 0:
    local_18 = 0;
    local_14 = 0;
    break;
  case 1:
    local_18 = 1;
    local_14 = 1;
    break;
  case 2:
    local_18 = 1;
    local_14 = 2;
    break;
  case 3:
    local_18 = 2;
    local_14 = 3;
  }
  arg_2 = *(int *)(&DAT_00525f30 + arg1 * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  arg_3 = *(int *)(&DAT_00525f34 + arg1 * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  iVar2 = Ai_Util_004c3bc4(2);
  iVar3 = Ai_Util_004c3bc4(2);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar2 / 2 + arg_2,iVar3 / 2 + arg_3,DAT_00525f80
                      ,DAT_00525f80,*(int *)(&DAT_005394e8 + local_14 * 4));
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,DAT_00525f80,DAT_00525f80,
                      *(int *)(&DAT_005394e8 + local_14 * 4));
  }
  iVar2 = local_8[local_18];
  iVar3 = *(int *)(&DAT_00525f38 + arg1 * 0x10);
  arg_5 = DAT_00525f80;
  iVar4 = Ai_Util_004c3bc4(0x24);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2 + iVar4,arg_3,iVar3,arg_5,iVar2);
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  iVar2 = *(int *)(&DAT_00525f34 + arg1 * 0x10);
  iVar3 = *(int *)(&DAT_00525f30 + arg1 * 0x10);
  piVar5 = (int *)g_DisplaySurfaceScreen;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint *)(&DAT_00525f30 + arg1 * 0x10),
               *(int *)(&DAT_00525f34 + arg1 * 0x10),
               DAT_00522458 - *(int *)(&DAT_00525f30 + arg1 * 0x10),DVar1,piVar5,iVar3,iVar2);
  return 0;
}


