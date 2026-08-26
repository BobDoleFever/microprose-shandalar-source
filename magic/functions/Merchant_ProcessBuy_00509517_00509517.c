/*
 * Decompiled function: Merchant_ProcessBuy_00509517
 * Entry Point: 00509517
 * Size: 2749 bytes
 */
#include "magic.h"


void Merchant_ProcessBuy_00509517(void)

{
  undefined4 arg_1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  void *arg_6;
  int local_100;
  void *local_fc;
  int local_f8;
  undefined4 local_f4;
  undefined4 auStack_f0 [6];
  undefined4 auStack_d8 [4];
  int local_c8;
  int local_c4;
  int local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4 [40];
  
  local_a8 = DAT_0062680c;
  local_ac = 0;
  FUN_0040a3e1();
  arg_1 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_a8 * 100),
                       *(int *)(&DAT_0067bdf8 + local_a8 * 100));
  local_bc = Adventure_GetLocationEncounterIndex(arg_1);
  local_ac = *(int *)(&DAT_0067bdf0 + local_a8 * 100) + 3;
  if (DAT_005224f8 == 0) {
    local_ac = *(int *)(&DAT_0067bdf0 + local_a8 * 100) + 4;
  }
  if (local_ac == 0) {
    iVar1 = FUN_00473cc5((byte)local_bc);
    *(int *)(&DAT_0061e060 + local_ac * 4) = iVar1 + -1;
    *(undefined4 *)(&DAT_0061e0a0 + local_ac * 4) = 0x28;
    local_ac = local_ac + 1;
  }
  Sprite_LoadAll(&local_fc,s_BuyButtons_spr_00532274);
  DAT_0061e0d8 = local_fc;
  DAT_0061e114 = local_f8;
  DAT_0061e0c0 = local_f4;
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    (&DAT_0061e108)[local_100] = auStack_f0[local_100];
  }
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    *(undefined4 *)(&DAT_0061e0c8 + local_100 * 4) = auStack_f0[local_100 + 3];
  }
  for (local_100 = 0; local_100 < 3; local_100 = local_100 + 1) {
    *(undefined4 *)(&DAT_0061e0e0 + local_100 * 4) = auStack_f0[local_100 + 6];
  }
  FUN_00510b70(1,0,DAT_0052245c + -0x118,s_buycards_pic_00532284,(short *)0x0);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceScreen,iVar4,iVar3,iVar2,iVar1);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,iVar1);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  if (DAT_006265f8 != -1) {
    Merchant_ProcessBuy_00407b34(DAT_006265f8);
  }
  local_c8 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_c8);
  if (DAT_005318a0 == DAT_00531890) {
    DAT_005318a0 = Ai_Util_004c3bc4(DAT_005318a0);
    DAT_005318a4 = Ai_Util_004c3bc4(DAT_005318a4);
    DAT_005318a8 = Ai_Util_004c3bc4(DAT_005318a8);
    DAT_005318ac = Ai_Util_004c3bc4(DAT_005318ac);
  }
  FUN_0041f17e(0x531890,1,local_c8);
LAB_00509872:
  Mem_AllocOrFree_00510e20(1,s_buycards_pic_00532294);
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3ba3(0x18);
  iVar4 = Ai_Util_004c3ba3(0x20);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x200,0x118,(int *)g_DisplaySurfaceScreen
                     ,iVar4,iVar3,iVar2,iVar1);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  FUN_0041f213();
  FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  iVar2 = FUN_0040c465(s_Cards_for_Sale_005322a4);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(DAT_00522458 / 2 - iVar2 / 2) + -0x14,
                    (DAT_0052245c * 0x1f) / 0xf0 - iVar1,iVar2 + 0x28,iVar1 * 3,DAT_0061e114);
  FUN_0040c336(s_Cards_for_Sale_005322b4,0xa0,0x1f,0x1b);
  local_b0 = 0x40;
  local_c4 = (int)(0xf4 / (longlong)local_ac);
  memset(local_a4,0xff,0xa0);
  local_b4 = local_ac;
  while (local_b4 = local_b4 + -1, -1 < local_b4) {
    if (*(int *)(&DAT_0061e060 + local_b4 * 4) != -1) {
      FUN_0040c6c7(g_DisplaySurfaceScreen,local_c4 * local_b4 + 0x2c,
                   (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -0xc,local_c4 + -4,0xc
                   ,DAT_0061e0c0);
      g_OverworldWorldState = 0;
      pcVar5 = _itoa(*(int *)(&DAT_0061e0a0 + local_b4 * 4),&DAT_0061e0f0,10);
      strcat(&g_OverworldWorldState,pcVar5);
      strcat(&g_OverworldWorldState,s_gold_005322c4);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040c336(&g_OverworldWorldState,local_c4 * local_b4 + local_c4 / 2 + 0x29,
                   (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + -8,0x1b);
      pcVar5 = &DAT_005322cc;
      iVar3 = 0;
      iVar1 = (*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4;
      iVar2 = FUN_0040a305(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,DAT_00522458 + -0x62);
      FUN_0050b206(*(int *)(&DAT_0061e060 + local_b4 * 4),iVar2,iVar1,iVar3,pcVar5);
      iVar1 = FUN_0040a305(local_c4 * local_b4 + local_c4 / 2 + 0x12,0,DAT_00522458 + -0x62);
      iVar1 = Ai_Util_004c3ba3(iVar1);
      local_a4[local_b4 * 4] = iVar1;
      iVar1 = Ai_Util_004c3ba3((*(uint *)(&DAT_0061e060 + local_b4 * 4) & 7) + local_b0 + 4);
      local_a4[local_b4 * 4 + 1] = iVar1;
      iVar1 = local_a4[local_b4 * 4];
      iVar2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 2] = iVar1 + iVar2;
      iVar1 = local_a4[local_b4 * 4 + 1];
      iVar2 = Ai_Util_004c3ba3(0x30);
      local_a4[local_b4 * 4 + 3] = iVar1 + iVar2;
    }
  }
  DAT_00626600 = 0;
  do {
    while( true ) {
      if (DAT_00626600 != 0) {
        FUN_0041f391();
        Ai_Subsystem_004c05ba();
        Ai_Subsystem_004c3c5c(1);
        FUN_0040a95d(s_village_pic_005322f0 +
                     ((*(int *)(&DAT_0067bdf0 + local_a8 * 100) == 1) - 1 & 0xc));
        DAT_006265fc = 0xfffffffe;
        Mem_AllocOrFree_0050fc50(DAT_0061e0d8);
        return;
      }
      local_c0 = -1;
      Pic_Subsystem_0044b84b();
      if (DAT_007039c4 != 0) break;
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
    }
    for (local_b4 = 0; local_b4 < local_ac; local_b4 = local_b4 + 1) {
      if ((((local_a4[local_b4 * 4] <= DAT_0067bda4) && (DAT_0067bda4 <= local_a4[local_b4 * 4 + 2])
           ) && (local_a4[local_b4 * 4 + 1] <= DAT_0067bda8)) &&
         (DAT_0067bda8 <= local_a4[local_b4 * 4 + 3])) {
        local_c0 = local_b4;
        break;
      }
    }
    if (local_c0 != -1) break;
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  } while( true );
  sprintf(&g_OverworldWorldState,s_Buy_for__d_gold___Y_N__005322d0,
          *(undefined4 *)(&DAT_0061e0a0 + local_b4 * 4));
  arg_6 = DAT_0061e0d8;
  iVar1 = Ai_Util_004c3ba3(0x10f);
  iVar1 = iVar1 / 2;
  iVar2 = Ai_Util_004c3ba3(0xc5);
  iVar2 = iVar2 / 2;
  iVar3 = Ai_Util_004c3ba3(0x34);
  iVar3 = iVar3 / 2;
  iVar4 = Ai_Util_004c3ba3(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4 / 2,iVar3,iVar2,iVar1,(int)arg_6);
  FUN_0050b3de(*(int *)(&DAT_0061e060 + local_b4 * 4),0x7a,0x29,0x4b,0x70,1,&DAT_005322ec);
  FUN_0040d339((int)g_DisplaySurfaceScreen,0x1b,0x140,0x47);
  FUN_0040a3e1();
  local_b8 = FUN_0048ac2f();
  if (((local_b8 == 0x79) || (local_b8 == 0x59)) && (*(int *)(&DAT_0061e0a0 + local_b4 * 4) <= Gold)
     ) {
    Gold = Gold - *(int *)(&DAT_0061e0a0 + local_b4 * 4);
    iVar1 = Pic_Subsystem_00451e40(*(uint *)(&DAT_0061e060 + local_b4 * 4));
    *(uint *)(&deck + iVar1 * 4) = *(uint *)(&deck + iVar1 * 4) | 0x4000;
    *(undefined4 *)(&DAT_0061e060 + local_b4 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_0061e0a0 + local_b4 * 4) = 0;
    if (DAT_00626808 == local_b4) {
      DAT_006265f8 = -1;
    }
    iVar1 = FUN_0040a1d2(5);
    *(int *)(&DAT_0067be24 + local_b4 * 4 + local_a8 * 100) =
         iVar1 * (DAT_0067f380 + 2) + DAT_00641020;
    FUN_0040a566();
    Ai_Subsystem_004c3c5c(1);
  }
  goto LAB_00509872;
}


