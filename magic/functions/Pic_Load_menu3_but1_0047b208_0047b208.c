/*
 * Decompiled function: Pic_Load_menu3_but1_0047b208
 * Entry Point: 0047b208
 * Size: 1033 bytes
 */
#include "magic.h"


undefined4 Pic_Load_menu3_but1_0047b208(void)

{
  int *piVar1;
  undefined4 uVar2;
  int local_3c [4];
  int local_2c [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menu3_pic_00526a78,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,DAT_00522458,DAT_0052245c);
  FUN_005115a0(0,(short)DAT_00530d9c);
  piVar1 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceWork,0,0,DAT_00522458,DAT_0052245c);
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510de0(1,s_menu3_but1_pic_00526a84);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,0,local_18 * 0x4b,0x46,0x4b);
    (&DAT_00676d60)[local_18] = (void *)uVar2;
  }
  Mem_AllocOrFree_00510de0(1,s_menu3but_pic_00526a94);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,0,local_18 * 0x4b,0x46,0x4b);
    *(undefined4 *)(&DAT_00676e20 + local_18 * 4) = uVar2;
  }
  FUN_0050fc20();
  if (DAT_005261a0 == DAT_00526190) {
    for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526388 + local_18 * 0x10));
      *(undefined4 *)(&DAT_00526388 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052638c + local_18 * 0x10));
      *(undefined4 *)(&DAT_0052638c + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526390 + local_18 * 0x10));
      *(undefined4 *)(&DAT_00526390 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526394 + local_18 * 0x10));
      *(undefined4 *)(&DAT_00526394 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4((&DAT_005261a0)[local_18 * 0x15]);
      (&DAT_005261a0)[local_18 * 0x15] = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a4 + local_18 * 0x54));
      *(undefined4 *)(&DAT_005261a4 + local_18 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a8 + local_18 * 0x54));
      *(undefined4 *)(&DAT_005261a8 + local_18 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261ac + local_18 * 0x54));
      *(undefined4 *)(&DAT_005261ac + local_18 * 0x54) = uVar2;
    }
  }
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x526190,6,local_1c);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    FUN_0047b0c9(local_18,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(local_1c);
  Mem_AllocOrFree_0050fc50(DAT_00676d60);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceWork,local_14,local_10,local_c,local_8);
  if (DAT_00525f28 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_00525f28 * 4 + 0x5263d4);
  }
  return uVar2;
}


