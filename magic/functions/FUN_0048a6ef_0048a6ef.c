/*
 * Decompiled function: FUN_0048a6ef
 * Entry Point: 0048a6ef
 * Size: 1344 bytes
 */
#include "magic.h"


void FUN_0048a6ef(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 *arg_5)

{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined4 uStack_a8;
  short local_a4 [2];
  undefined4 auStack_a0 [3];
  short local_94;
  short local_92;
  short local_84;
  short local_82;
  short local_74;
  short local_72;
  short local_64;
  short local_62;
  short local_54;
  short local_52;
  short local_44;
  short local_42;
  short local_34;
  short local_32;
  short local_24;
  short local_22;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  
  local_c = arg_5;
  for (local_b0 = 0; local_b0 < 9; local_b0 = local_b0 + 1) {
    if (local_c[local_b0] != 0) {
      puVar1 = (undefined4 *)local_c[local_b0];
      (&uStack_a8)[local_b0 * 4] = *puVar1;
      *(undefined4 *)(local_a4 + local_b0 * 8) = puVar1[1];
      auStack_a0[local_b0 * 4] = puVar1[2];
      auStack_a0[local_b0 * 4 + 1] = puVar1[3];
      sVar2 = Ai_Util_004c3bc4((int)local_a4[local_b0 * 8]);
      local_a4[local_b0 * 8] = sVar2;
      uVar3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_a0 + local_b0 * 0x10 + -2));
      *(undefined2 *)((int)auStack_a0 + local_b0 * 0x10 + -2) = uVar3;
    }
  }
  if (local_c[8] == 0) {
    local_14 = arg_4;
    local_10 = arg_3;
  }
  else {
    if (arg_4 % (int)local_22 != 0) {
      local_14 = (arg_4 / (int)local_22 + 1) * (int)local_22;
    }
    if (arg_3 % (int)local_24 != 0) {
      local_10 = (arg_3 / (int)local_24 + 1) * (int)local_24;
    }
    arg_1 = (arg_1 + 4) - (local_10 - arg_3) / 2;
    arg_2 = (arg_2 + 4) - (local_14 - arg_4) / 2;
    for (local_b4 = 0; local_b4 < local_14 / (int)local_22; local_b4 = local_b4 + 1) {
      for (local_b0 = 0; local_b0 < local_10 / (int)local_24; local_b0 = local_b0 + 1) {
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_24 * local_b0 + arg_1,
                          local_22 * local_b4 + arg_2,(int)local_24,(int)local_22,local_c[8]);
      }
    }
  }
  local_ac = (local_94 + local_10 + arg_1) - (int)local_94;
  for (local_18 = (arg_1 - local_44) + (int)local_a4[0]; local_18 < arg_1 + local_10 / 2;
      local_18 = local_18 + local_64) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,arg_2,(int)local_64,(int)local_62,
                      local_c[4]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,arg_2,(int)local_64,(int)local_62,
                      local_c[4]);
    local_ac = local_ac - local_64;
  }
  local_18 = arg_1 - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,arg_2,(int)local_a4[0],(int)local_a4[1],
                    *local_c);
  local_18 = (local_34 + arg_3 + arg_1) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,arg_2,(int)local_94,(int)local_92,
                    local_c[1]);
  local_18 = arg_1 - local_44;
  iVar4 = local_10 + arg_1;
  for (local_b8 = local_a4[1] + arg_2; local_b8 < (arg_2 + local_14) - (int)local_82;
      local_b8 = local_b8 + local_42) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,local_b8,(int)local_44,(int)local_42,
                      local_c[6]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4,local_b8,(int)local_34,(int)local_32,
                      local_c[7]);
  }
  iVar4 = (arg_2 + local_14) - (int)local_82;
  local_18 = arg_1 - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_84,(int)local_82,
                    local_c[2]);
  local_18 = (local_34 + local_10 + arg_1) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_74,(int)local_72,
                    local_c[3]);
  local_ac = (local_94 + local_10 + arg_1) - (int)local_94;
  iVar4 = arg_2 + local_14;
  for (local_18 = (arg_1 - local_44) + (int)local_a4[0]; local_18 < arg_1 + local_10 / 2;
      local_18 = local_18 + local_54) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_54,(int)local_52,
                      local_c[5]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,iVar4,(int)local_54,(int)local_52,
                      local_c[5]);
    local_ac = local_ac - local_54;
  }
  return;
}


