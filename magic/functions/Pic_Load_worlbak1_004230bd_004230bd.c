/*
 * Decompiled function: Pic_Load_worlbak1_004230bd
 * Entry Point: 004230bd
 * Size: 560 bytes
 */
#include "magic.h"


void Pic_Load_worlbak1_004230bd(int arg_1)

{
  int arg_5;
  int arg_4;
  int arg_3;
  int arg_2;
  int iVar1;
  int iVar2;
  int arg_1_00;
  int arg_1_01;
  
  Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_0051ae80);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Bazaar_GetCardBaseValue(arg_1);
  iVar2 = *(int *)(&DAT_006782a0 + arg_1 * 4);
  arg_1_00 = (0x4e - *(short *)(iVar2 + 6)) / 2 + 0x4c;
  arg_1_01 = (0x4f - *(short *)(iVar2 + 4)) / 2 + 0x14f;
  iVar1 = *(int *)(&DAT_006782a0 + arg_1 * 4);
  arg_5 = Ai_Util_004c3bc4((int)*(short *)(iVar2 + 6));
  arg_4 = Ai_Util_004c3bc4((int)*(short *)(iVar2 + 4));
  arg_3 = Ai_Util_004c3bc4(arg_1_00);
  arg_2 = Ai_Util_004c3bc4(arg_1_01);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,iVar1);
  iVar1 = (arg_1_00 + *(short *)(iVar2 + 6) + 0x10) / 2;
  iVar2 = (arg_1_01 + (int)*(short *)(iVar2 + 4) / 2) / 2;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  FUN_0040d4d1((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
  g_OverworldWorldState = 0;
  strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[arg_1]);
  FUN_0040c336(&g_OverworldWorldState,iVar2,iVar1 + -5,0x40);
  strcpy(&g_OverworldWorldState,&DAT_0051ae9c);
  strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[arg_1]);
  strcat(&g_OverworldWorldState,&DAT_0051aea0);
  iVar1 = Ai_Util_004c3ba3(iVar1 + 3);
  iVar2 = Ai_Util_004c3ba3(iVar2);
  FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,iVar2,iVar1);
  FUN_0040a3e1();
  Ai_Subsystem_004cd1d1();
  return;
}


