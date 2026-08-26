/*
 * Decompiled function: Sprite_Load_begin_0047a2e6
 * Entry Point: 0047a2e6
 * Size: 1633 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Sprite_Load_begin_0047a2e6(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_1ac;
  int local_1a8;
  undefined4 local_1a0 [100];
  int local_10;
  char *local_c;
  int local_8;
  
  local_c = s_magic3_map_005269f4;
  do {
    strcpy(local_c,s_magic3_map_00526a00);
    DAT_00525f28 = -1;
    FUN_005112b0(0,(short)DAT_00530d9c);
    FUN_00510b70(1,0,0,s_menubak_pic_00526a0c,
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork
                       ,0,0,DAT_00522458,DAT_0052245c);
    FUN_005115a0(0,(short)DAT_00530d9c);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    _DAT_00525f98 = FUN_00406b01(local_c);
    for (local_8 = 4; local_8 < 0xe; local_8 = local_8 + 1) {
      if (local_8 < 10) {
        local_c[5] = (char)local_8 + '0';
      }
      else {
        local_c[5] = (char)local_8 + 'W';
      }
      iVar1 = FUN_00406b01(local_c);
      if (iVar1 != 0) break;
    }
    if (local_8 == 0xe) {
      _DAT_00525f94 = 0;
    }
    local_1ac = 0;
    Sprite_LoadAll(local_1a0,s_begin_spr_00526a18);
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      (&DAT_005394d8)[local_1a8] = (void *)local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_005394b0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_005394f8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_005394c0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_00539188 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_00538e60 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 4; local_1a8 = local_1a8 + 1) {
      *(undefined4 *)(&DAT_005394e8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    if (DAT_00525de8 == DAT_00525dd8) {
      for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f30 + local_8 * 0x10));
        *(undefined4 *)(&DAT_00525f30 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f34 + local_8 * 0x10));
        *(undefined4 *)(&DAT_00525f34 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f38 + local_8 * 0x10));
        *(undefined4 *)(&DAT_00525f38 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f3c + local_8 * 0x10));
        *(undefined4 *)(&DAT_00525f3c + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4((&DAT_00525de8)[local_8 * 0x15]);
        (&DAT_00525de8)[local_8 * 0x15] = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525dec + local_8 * 0x54));
        *(undefined4 *)(&DAT_00525dec + local_8 * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df0 + local_8 * 0x54));
        *(undefined4 *)(&DAT_00525df0 + local_8 * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df4 + local_8 * 0x54));
        *(undefined4 *)(&DAT_00525df4 + local_8 * 0x54) = uVar2;
      }
      DAT_00525f80 = Ai_Util_004c3bc4(DAT_00525f80);
      DAT_00525f84 = Ai_Util_004c3bc4(DAT_00525f84);
      DAT_00525f88 = Ai_Util_004c3bc4(DAT_00525f88);
    }
    local_10 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(local_10);
    FUN_0041f17e(0x525dd8,4,local_10);
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      FUN_00479ff9(local_8,-(uint)(*(int *)(&DAT_00525f90 + local_8 * 4) == 0) & 3);
      if (*(int *)(&DAT_00525f90 + local_8 * 4) == 0) {
        FUN_0041ece4((int)(&DAT_00525dd8 + local_8 * 0x15));
      }
    }
    while (DAT_00525f28 == -1) {
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
    }
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_10);
    Mem_AllocOrFree_0050fc50(DAT_005394d8);
    if (DAT_00525f28 != 4) {
      return DAT_00525f28 + -1;
    }
    Pic_Load_004244a0();
  } while( true );
}


